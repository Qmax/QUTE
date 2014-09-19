#ifndef WAVEFORMCLASS_H
#define WAVEFORMCLASS_H
#include "plotter.h"

class IWaveProduct:public Plotter
{
public:
    IWaveProduct(QWidget *parent=0):Plotter(parent){}
    void LoadPlotterData(QString pStrFileName,stWaveData *pObjWaveData)
    {
        QFile *l_objDataFile = new QFile(pStrFileName);
        char *data = new char[20];
        qint64 l_nLineLength=0;
        QString l_strWaveData;
        m_strWaveData.clear();
        if(l_objDataFile->open(QFile::ReadOnly))
        {
            while(l_nLineLength !=-1)
            {
                l_nLineLength = l_objDataFile->readLine(data,20);
                l_strWaveData.append(data);l_strWaveData.remove("\n");l_strWaveData.remove("\r");
                if(!l_strWaveData.isEmpty())
                    m_strWaveData.append(l_strWaveData);
                l_strWaveData ="";
            }
        }
        l_objDataFile->close();
        m_objWaveData = pObjWaveData;
        //printf("steps:%f\n",m_objWaveData->m_nSteps);
    }

    virtual void GeneratePlotterPoints(short pChannelValue)=0;
    virtual void GenerateOscillatorPattern(QString pStrPatternselected,short int) =0;
    virtual void calculateSampleTimePeriod()=0;
    virtual void WaveSettings() =0;
    virtual void setDimensions(int pXPos,int pYPos,int pWidth,int pHeight) =0;
    virtual void setWaveParams(bool pGrid,bool pShowData,bool pZoomFlag,bool pVILabels,bool pVIMode,double)=0;
    virtual void LoadVITrace(short,int)=0;
    virtual void LoadVIData (QString pStrRefereceFileName,QString pStrActualFileName,int pIndex,int pWaveTrace,stWaveData *pObjWaveData) =0;
    virtual void setGainFactor(double)=0;
    virtual void setAutoScale(bool)=0;
    QStringList getData(){ return m_strWaveData;}

protected:
    bool m_bZoomFlag;
    bool m_bVIFlag;
    stWaveData* m_objWaveData;
    QStringList m_strWaveData;

};

class OscillaScope:public IWaveProduct
{
public:
    OscillaScope(QWidget* parent):IWaveProduct(parent)
    {
        printf("DSO Product\n");
        m_objWaveData = new stWaveData();
    }
    virtual void setDimensions(int pXPos,int pYPos,int pWidth,int pHeight)
    {
        setGeometry(pXPos,pYPos,pWidth,pHeight);
    }
    virtual void setGainFactor(double){}
    virtual void setAutoScale(bool){}

    virtual void setWaveParams(bool pGrid,bool pShowData,bool pZoomFlag,bool pVILabels,bool pVIMode,double)
    {
    	Q_UNUSED(pGrid);
    	Q_UNUSED(pShowData);
    	Q_UNUSED(pZoomFlag);
    	Q_UNUSED(pVILabels);
    	Q_UNUSED(pVIMode);
    }
    virtual void GenerateOscillatorPattern(QString pStrPatternselected,short int)
    {
        Q_UNUSED(pStrPatternselected);
    }

    virtual void GeneratePlotterPoints(short pChannelValue)
    {
        double l_nXPoint =0.0,l_nYPoint =0.0;

        QVector<QPointF> l_nData;
        for(int l_nIndex=0;l_nIndex<m_strWaveData.count();l_nIndex++)
        {
            l_nYPoint = convertToYPoint(m_strWaveData[l_nIndex]);
            l_nData.append(QPointF(l_nXPoint,l_nYPoint));
            l_nXPoint += m_objWaveData->m_nTimeperSample;
        }
        setCurveData(pChannelValue,l_nData);

    }
    virtual void calculateSampleTimePeriod()
    {
        m_objWaveData->m_nOffset = (1.0/m_objWaveData->m_nYunits)/10.0;

    }

    virtual void WaveSettings()
    {

        if(m_bZoomFlag == false)
            setPlotSettings(PlotSettings(m_objWaveData->m_nScreenTime, m_objWaveData->m_nScreenAmplitude,m_objWaveData->m_nXunits,m_objWaveData->m_nYunits,m_objWaveData->m_nSteps*m_objWaveData->m_nOffset,m_objWaveData->m_nMinX,m_objWaveData->m_nMinY));
        else
            setPlotSettings(PlotSettings(m_objWaveData->m_nScreenTime, m_objWaveData->m_nScreenAmplitude,m_objWaveData->m_nXunits,m_objWaveData->m_nYunits,m_objWaveData->m_nSteps*m_objWaveData->m_nOffset,m_objWaveData->m_nMinX,m_objWaveData->m_nMinY));
    }

    double convertToYPoint(QString pStrData)
    {
        bool ok = true;
        return ((pStrData.toInt(&ok,16) * ((m_objWaveData->m_nAmplitude*2) / pow(2,m_objWaveData->m_nResolution)-1)) - (m_objWaveData->m_nAmplitude*2)/2.0)*(1/m_objWaveData->m_nScreenAmplitude);
    }

    virtual void LoadVIData (QString pStrRefereceFileName,QString pStrActualFileName,int pIndex,int pWaveTrace,stWaveData *pObjWaveData)
    {
        Q_UNUSED(pStrRefereceFileName);
        Q_UNUSED(pStrActualFileName);
        Q_UNUSED(pIndex);
        Q_UNUSED(pWaveTrace);
        Q_UNUSED(pObjWaveData);

    }
    virtual void LoadVITrace(short,int)
    {
    }


};

class Oscillator:public IWaveProduct
{
public:
    Oscillator(QWidget* parent):IWaveProduct(parent)
    {
        printf("FG Product\n");
        //this->move(25,50);
        this->m_bGrid = true;
        this->m_showData = true;
        this->m_ZoomFlag = false;
        this->m_bVILabels = false;
        this->m_bVIMode = false;
        this->m_bAutoScale = false;
        m_nADCGainFactor=1.0;
        //this->resize(620,200);
        m_objWaveData = new stWaveData();
         //WaveSettings();

    }
    virtual void setGainFactor(double pGain)
    {
    	m_nADCGainFactor = pGain;
    }
    virtual void setAutoScale(bool pFlag)
    {
    	this->m_bAutoScale = pFlag;
    }
    virtual void setWaveParams(bool pGrid,bool pShowData,bool pZoomFlag,bool pVILabels,bool pVIMode,double pGain)
    {
        this->m_bGrid = pGrid;
        this->m_showData = pShowData;
        this->m_ZoomFlag = pZoomFlag;
        this->m_bVILabels = pVILabels;
        this->m_bVIMode = pVIMode;
        this->m_bAutoScale = false;
        m_nADCGainFactor = pGain;
    }
    virtual void setDimensions(int pXPos,int pYPos,int pWidth,int pHeight)
    {
        setGeometry(pXPos,pYPos,pWidth,pHeight);
    }

    double convertToYPoint(QString pStrData)
      {
          bool ok = true;
          double l_nVref = 0.725;
          //qDebug()<<"ADC Point Data:" <<((2*(pStrData.toInt(&ok,16)*l_nVref))/ (pow(2,8)-1)) - l_nVref;
          return ((2*(pStrData.toInt(&ok,16)*l_nVref))/ (pow(2,8)-1)) - l_nVref;
          //return ((pStrData.toInt(&ok,16) * ((m_objWaveData->m_nAmplitude*2) / pow(2,8))) - (m_objWaveData->m_nAmplitude*2)/2.0)*(1/m_objWaveData->m_nScreenAmplitude);
     }
    double convertToADCPoint(QString pStrData)
    {
    	bool ok = true;
    	double l_nVref = 2.048;
		double l_nFactor1 = (pStrData.toUInt(&ok,16)/pow(2,23))-1;
		double l_nFactor2 = (m_nADCGainFactor / l_nVref);
		double l_nAIN = l_nFactor1 / l_nFactor2;
		return l_nAIN;

    }
    void GenerateADCPlotterPoints(int pGain)
    {
    	//m_nADCGainFactor = pGain;
    	//qDebug() << "Timer Per Sample" << m_objWaveData->m_nTimeperSample;
    	Q_UNUSED(pGain);
		double l_nXPoint =0.0,l_nYPoint =0.0;
		m_nData.clear();
		QVector<QPointF> l_nData;
		l_nData.clear();
		for(int l_nIndex=0;l_nIndex<m_strWaveData.count();l_nIndex++)
		{
			l_nYPoint = convertToADCPoint(m_strWaveData[l_nIndex]);
			l_nData.append(QPointF(l_nXPoint,l_nYPoint));
			//qDebug() <<"Data:"<< m_strWaveData[l_nIndex]<<"XPoint:"<<l_nXPoint<<"YPoint:"<<l_nYPoint;
			l_nXPoint += 0.01;
		}
		// for testing to check Maximum and Minimum Ypoint
//		double l_nMaxY=0.0,l_nMinY=0.0;
//		for(int l_nIndex=0;l_nIndex<l_nData.count();l_nIndex++)
//		{
//			double l_nY1Point = l_nData.at(l_nIndex).y();
//			//qDebug()<<"YPoint:"<<l_nY1Point;
//			if( l_nY1Point > l_nMaxY)
//				l_nMaxY = l_nY1Point;
//			else if(l_nY1Point < l_nMinY)
//				l_nMinY = l_nY1Point;
//		}
//		if(this->m_bAutoScale == true)
//		{
//
//		}
		//qDebug() << "MaxY Point:" << l_nMaxY << "MinY Point:"<< l_nMinY;
    	setCurveData(0,l_nData);
    }

    virtual void GeneratePlotterPoints(short pChannelValue)
    {

		double l_nXPoint =0.0,l_nYPoint =0.0;
		m_nData.clear();
		QVector<QPointF> l_nData;
		l_nData.clear();
		for(int l_nIndex=0;l_nIndex<m_strWaveData.count();l_nIndex++)
		{
			l_nYPoint = convertToYPoint(m_strWaveData[l_nIndex]);
			if(m_objWaveData->m_bCalibChecked)
			{
				// y = (x-b) / m
				double l_nTempPoint = (l_nYPoint - m_objWaveData->m_nCalibrationConstant) / m_objWaveData->m_nCalibrationGain;
				l_nYPoint = l_nTempPoint;
				//printf("XPoint %f YPoint %f Calibration Constants %f %f\n",l_nXPoint,l_nYPoint,m_objWaveData->m_nCalibrationConstant,m_objWaveData->m_nCalibrationGain);
			}
			//printf("XPoint %f YPoint %f Calibration Constants %f %f\n",l_nXPoint,l_nYPoint,m_objWaveData->m_nCalibrationConstant,m_objWaveData->m_nCalibrationGain);
			l_nData.append(QPointF(l_nXPoint,l_nYPoint));
			//printf("XPoint %f YPoint %f\n",l_nXPoint,l_nYPoint);

			l_nXPoint += m_objWaveData->m_nTimeperSample;
		}
		setCurveData(pChannelValue,l_nData);
    }
    virtual void GenerateOscillatorPattern(QString pstrSelectedPattern,short int pChannel)
    {
        //clearCurve(0);
        if(m_objWaveData->m_bUniPolar == true)
            this->m_bUniPolar = true;
        else
            this->m_bUniPolar = false;
        if( pstrSelectedPattern == "SINE")
            GenerateSinPattern();
        else if(pstrSelectedPattern == "SQUARE")
            GenerateSquarePattern();
        else if(pstrSelectedPattern == "TRIANGLE")
            GenerateTrianglePattern();
        else if(pstrSelectedPattern == "SAWTOOTH")
            GenerateSawtoothPattern();
        else if(pstrSelectedPattern == "FILE")
        {
        	//GenerateFilePattern();
        }
        else if(pstrSelectedPattern == "RECEIVE"){
        	GeneratePlotterPoints(pChannel);
        	return;
        	}
        else if(pstrSelectedPattern == "HAADC")
        {
        	GenerateADCPlotterPoints(0);
        	return;
        }
        else
            return;
        setCurveData(0,m_nData);

    }

    virtual void calculateSampleTimePeriod()
    {
        m_objWaveData->m_nTimeperSample = (1.0 / m_objWaveData->m_nFrequency) / (double)(m_objWaveData->m_nSamples/m_objWaveData->m_nCycles);
    }

    virtual void WaveSettings()
    {
         //printf("Offset1 %f Samples %d Steps %f\n",m_objWaveData->m_nOffset,m_objWaveData->m_nSamples,m_objWaveData->m_nSteps);
    	qDebug() << "Offset:"<< m_objWaveData->m_nOffset;
        float l_nAmp =1.0;
        if( m_objWaveData->m_bUniPolar == true)
        {
            l_nAmp =2.0;
        }
        setPlotSettings(PlotSettings(m_objWaveData->m_nScreenTime, m_objWaveData->m_nScreenAmplitude*l_nAmp,m_objWaveData->m_nXunits,m_objWaveData->m_nYunits,m_objWaveData->m_nSteps*m_objWaveData->m_nOffset,m_objWaveData->m_nMinX,m_objWaveData->m_nMinY));

    }
    virtual void LoadVIData (QString pStrRefereceFileName,QString pStrActualFileName,int pIndex,int pWaveTrace,stWaveData *pObjWaveData)
    {
        Q_UNUSED(pStrRefereceFileName);
        Q_UNUSED(pStrActualFileName);
        Q_UNUSED(pIndex);
        Q_UNUSED(pWaveTrace);
        Q_UNUSED(pObjWaveData);

    }
    virtual void LoadVITrace(short,int)
    {
    }

protected:
    double m_nADCGainFactor;
    void GenerateSinPattern()
    {
        double l_nYPoint =0.0,l_nDegree =m_objWaveData->m_nPhase,l_nXPoint =0.0;
        m_nData.clear();
        //printf("Value:%d\n",m_objWaveData->m_bUniPolar);
        unsigned int l_nSampleIndex=0;
        unsigned int l_nIndex =0;
        unsigned int l_nSamples=0;
        unsigned int l_nRemainder =0;
        unsigned int l_nTemp=0;

//        if( m_objWaveData->m_nCycles != 1)
//            m_objWaveData->m_nSamples+=1;
        //printf("Local Sample: %d\n",l_nSamples);
        l_nSamples = m_objWaveData->m_nSamples / m_objWaveData->m_nCycles;
        //printf("Local Sample: %d\n",l_nSamples);
        l_nRemainder = (m_objWaveData->m_nSamples%(int)m_objWaveData->m_nCycles)/l_nSamples;
         //printf("Remainter : %d\n",l_nRemainder);
//        unsigned int l_nTotalSamples = (l_nSamples*m_objWaveData->m_nCycles) + (l_nSamples*l_nRemainder);
        l_nTemp = l_nSamples;
        //printf("Local Sample: %d\n",l_nSamples);
        double l_nPhaseAngle=0.0;
        l_nPhaseAngle = (l_nDegree*PI) / 180.0;
        //printf("l_nPhaseAnlge : %f\n",l_nPhaseAngle);
        //printf("Total Samples %d",l_nTotalSamples);
        //printf("V Reference & Amplitude %f %f\n",m_objWaveData->m_nVRef,m_objWaveData->m_nAmplitude);
        //double l_nAmplitude = (m_objWaveData->m_nAmplitude/m_objWaveData->m_nVRef);
        double l_nAmplitude = (m_objWaveData->m_nAmplitude)*m_objWaveData->m_nVRef;
        double l_nTempYPoint=0.0;
        while(l_nSampleIndex < (m_objWaveData->m_nCycles+l_nRemainder))
        {
            for(;l_nIndex<l_nSamples;l_nIndex++)
            {
            	l_nTempYPoint = l_nAmplitude*sin(l_nPhaseAngle);
                l_nYPoint = l_nTempYPoint * m_objWaveData->m_nVRef;
            	l_nYPoint = l_nTempYPoint;
                //printf("XPoint :%f TempYPoint : %f\n",l_nXPoint,l_nTempYPoint);
                //printf("XPoint :%f YPoint : %f\n",l_nXPoint,l_nYPoint);
                if( m_objWaveData->m_bUniPolar == true)
                    l_nYPoint = l_nYPoint + 1.0;
                m_nData.append(QPointF(l_nXPoint,l_nYPoint));
                l_nPhaseAngle = (l_nPhaseAngle +(2*PI) / (m_objWaveData->m_nSamples/m_objWaveData->m_nCycles));
                l_nXPoint += m_objWaveData->m_nTimeperSample;
                if(l_nPhaseAngle > (2*PI))
                    l_nPhaseAngle = l_nPhaseAngle - (2*PI);

            }
            l_nSamples += l_nTemp;
            l_nSampleIndex++;
        }
        //printf("generated\n");
        GenerateHexPattern();
    }

    void GenerateSquarePattern()
    {
        double l_nYPoint =0.0,l_nDegree =m_objWaveData->m_nPhase,l_nXPoint =0.0;

        m_nData.clear();
        double l_nConstValue = (2.0*PI) *(float)(m_objWaveData->m_nDutyCycles);
        printf(" PI Value %f\n",l_nConstValue);
        unsigned int l_nSampleIndex=0;
        unsigned int l_nIndex =0;
        unsigned int l_nSamples=0;

        unsigned int l_nRemainder =0;
        unsigned int l_nTemp=0;

//        if( m_objWaveData->m_nCycles != 1)
//            m_objWaveData->m_nSamples+=1;
        l_nSamples = m_objWaveData->m_nSamples / m_objWaveData->m_nCycles;
        l_nRemainder = (m_objWaveData->m_nSamples%(int)m_objWaveData->m_nCycles)/l_nSamples;
         //printf("Remainter : %d\n",l_nRemainder);
        l_nTemp = l_nSamples;
        double l_nPhaseAngle=0.0;
        l_nPhaseAngle = (l_nDegree*PI) / 180.0;
        double l_nAmplitude = (m_objWaveData->m_nAmplitude)*m_objWaveData->m_nVRef;
        //printf("Local Sample: %d\n",l_nSamples);
        double l_nTempYPoint=0.0;
        while(l_nSampleIndex < (m_objWaveData->m_nCycles+l_nRemainder))
        {
            for(;l_nIndex<m_objWaveData->m_nSamples;l_nIndex++)
            {

                if(l_nPhaseAngle < l_nConstValue){
                	l_nTempYPoint = l_nAmplitude;
                    l_nYPoint = l_nTempYPoint * m_objWaveData->m_nVRef;

                }
                else{
                	l_nTempYPoint = -(l_nAmplitude);
                	l_nYPoint = l_nTempYPoint * m_objWaveData->m_nVRef;
                }
                if( m_objWaveData->m_bUniPolar == true)
                    l_nYPoint = l_nYPoint + 1.0;

                m_nData.append(QPointF(l_nXPoint,l_nYPoint));
                l_nPhaseAngle = (l_nPhaseAngle +(2*PI) / (m_objWaveData->m_nSamples/m_objWaveData->m_nCycles));
                l_nXPoint += m_objWaveData->m_nTimeperSample;
                //printf("Phase Angle : %f XPoint :%f YPoint : %f\n",l_nPhaseAngle,l_nXPoint,l_nYPoint);
                if(l_nPhaseAngle > (2*PI) )
                    l_nPhaseAngle = l_nPhaseAngle - (2*PI);
            }
            l_nSamples += l_nTemp;
            l_nSampleIndex++;
        }
        GenerateHexPattern();
    }


    void GenerateTrianglePattern()
    {
        double l_nYPoint =0.0,l_nDegree =m_objWaveData->m_nPhase,l_nXPoint =0.0;

        m_nData.clear();
        unsigned int l_nSampleIndex=0;
        unsigned int l_nIndex =0;
        unsigned int l_nSamples=0;
        unsigned int l_nRemainder =0;
        unsigned int l_nTemp=0;

//        if( m_objWaveData->m_nCycles != 1)
//            m_objWaveData->m_nSamples+=1;
        l_nSamples = m_objWaveData->m_nSamples / m_objWaveData->m_nCycles;
        l_nRemainder = (m_objWaveData->m_nSamples%(int)m_objWaveData->m_nCycles)/l_nSamples;
         //printf("Remainter : %d\n",l_nRemainder);
        //printf("Local Sample: %d\n",l_nSamples);
        double l_nPhaseAngle=0.0;
        l_nPhaseAngle = (l_nDegree*PI) / 180.0;
        double l_nAmplitude = (m_objWaveData->m_nAmplitude)*m_objWaveData->m_nVRef;
        double l_nTempYPoint=0.0;
        while(l_nSampleIndex < (m_objWaveData->m_nCycles+l_nRemainder))
        {

            for(;l_nIndex<m_objWaveData->m_nSamples;l_nIndex++)
            {
                if(l_nPhaseAngle < PI)
                {
                	l_nTempYPoint = -(l_nAmplitude) + (2*l_nAmplitude/PI) * l_nPhaseAngle;
                	 l_nYPoint = l_nTempYPoint * m_objWaveData->m_nVRef;
                }
                else
                {
                	l_nTempYPoint = 3*(l_nAmplitude) - (2*l_nAmplitude/PI) * l_nPhaseAngle;
                	 l_nYPoint = l_nTempYPoint * m_objWaveData->m_nVRef;
                }
                if( m_objWaveData->m_bUniPolar == true)
                    l_nYPoint = l_nYPoint + 1.0;

                m_nData.append(QPointF(l_nXPoint,l_nYPoint));
                l_nPhaseAngle = (l_nPhaseAngle +(2*PI) / (m_objWaveData->m_nSamples/m_objWaveData->m_nCycles));
                l_nXPoint += m_objWaveData->m_nTimeperSample;
                if(l_nPhaseAngle > (2*PI))
                    l_nPhaseAngle = l_nPhaseAngle - (2*PI);
            }
            l_nSamples += l_nTemp;
            l_nSampleIndex++;
        }
        GenerateHexPattern();
    }

    void GenerateSawtoothPattern()
    {
        double l_nYPoint =0.0,l_nDegree =m_objWaveData->m_nPhase,l_nXPoint =0.0;
        m_nData.clear();
        unsigned int l_nSampleIndex=0;
        unsigned int l_nIndex =0;
        unsigned int l_nSamples=0;
        unsigned int l_nTemp=0;
        unsigned int l_nRemainder =0;

		 l_nSamples = m_objWaveData->m_nSamples / m_objWaveData->m_nCycles;
		 l_nRemainder = (m_objWaveData->m_nSamples%(int)m_objWaveData->m_nCycles)/l_nSamples;
		  //printf("Remainter : %d\n",l_nRemainder);
        double l_nPhaseAngle=0.0;
        l_nPhaseAngle = (l_nDegree*PI) / 180.0;
        double l_nAmplitude = (m_objWaveData->m_nAmplitude)*m_objWaveData->m_nVRef;
        double l_nTempYPoint=0.0;
        while(l_nSampleIndex < (m_objWaveData->m_nCycles+l_nRemainder))
        {

            for(;l_nIndex<m_objWaveData->m_nSamples;l_nIndex++)
            {
            	l_nTempYPoint =l_nAmplitude - (l_nAmplitude/PI) * l_nPhaseAngle;
            	l_nYPoint = l_nTempYPoint * m_objWaveData->m_nVRef;
				if( m_objWaveData->m_bUniPolar == true)
					l_nYPoint = l_nYPoint + 1.0;

				m_nData.append(QPointF(l_nXPoint,l_nYPoint));
				l_nPhaseAngle = (l_nPhaseAngle +(2*PI) / (m_objWaveData->m_nSamples/m_objWaveData->m_nCycles));
				l_nXPoint += m_objWaveData->m_nTimeperSample;
				if(l_nPhaseAngle > (2*PI))
					l_nPhaseAngle = l_nPhaseAngle - (2*PI);
			}
            l_nSamples += l_nTemp;
            l_nSampleIndex++;

        }
    GenerateHexPattern();
    }

    // Unipolar hex_Value = (Value)*(2^n-1) / Vref
    // Bipolar hex_value = (Value+Vref) *(2^n-1) / 2 * Vref
    void GenerateHexPattern()
    {
    	FILE *fpWaveFile;
    	fpWaveFile = fopen("./DFIFODrive.txt","w");
    	short l_nHexValue = 0;
	    if(fpWaveFile == 0)
	        printf("File I/O error\n");
//         QFile *l_objDataFile = new QFile("./DFIFODrive.txt");
//         l_objDataFile->open(QFile::WriteOnly);
//         QTextStream out(l_objDataFile);
	    for(short int l_nPreIndex=0;l_nPreIndex<m_objWaveData->m_nPreamble;l_nPreIndex++)
	    {
	    	l_nHexValue = (m_objWaveData->m_nVRef) * ((pow(2,m_objWaveData->m_nResolution))-1) / (2 * (m_objWaveData->m_nVRef));
	    	fprintf(fpWaveFile,"%X\n",l_nHexValue);
	    }
        for(int l_nIndex=0;l_nIndex<m_nData.count();l_nIndex++)
        {
            QPointF m_nPointValue = m_nData.at(l_nIndex);

            //unsigned short l_nUniPolar =0;
            if( m_objWaveData->m_bUniPolar == true)
            {
                //printf("Y Point %f\n",m_nPointValue.y());
                l_nHexValue = (m_nPointValue.y()) *((pow(2,m_objWaveData->m_nResolution-1)))/(m_objWaveData->m_nAmplitude*2.0);
                l_nHexValue = l_nHexValue + 8192;
            }
            else
            {
            	//qDebug()<<"VREF:"<<m_objWaveData->m_nVRef;
                //printf("Y Point %f\n",m_nPointValue.y());
            	double l_nRefPoint = 0.0;
            	if(m_objWaveData->m_bCalibChecked)
            	{
            		l_nRefPoint = m_nPointValue.y();
            	//	l_nRefPoint =  (m_nPointValue.y() - m_objWaveData->m_nCalibrationConstant) /m_objWaveData->m_nCalibrationGain;
            	}
            	else
            	{
            		l_nRefPoint = m_nPointValue.y();
            	}
                l_nHexValue = ((l_nRefPoint)+m_objWaveData->m_nVRef) * ((pow(2,m_objWaveData->m_nResolution))-1) / (2 * (m_objWaveData->m_nVRef));
                //printf("VRef %f %d\n",l_nRefPoint,l_nHexValue);
            }
            QString l_strHexValue;

            fprintf(fpWaveFile,"%X\n",l_nHexValue);
            //l_strHexValue.setNum(l_nHexValue & 0x00003FFF,16);
           // std::string hexString = l_strHexValue.toStdString();

            //QString hexQString(l_strHexValue);
            //out << hexQString<<endl;
        }
	    for(short int l_nPostIndex=0;l_nPostIndex<m_objWaveData->m_nPostamble;l_nPostIndex++)
	    {
	    	l_nHexValue = (m_objWaveData->m_nVRef) * ((pow(2,m_objWaveData->m_nResolution))-1) / (2 * (m_objWaveData->m_nVRef));
	    	fprintf(fpWaveFile,"%X\n",l_nHexValue);
	    }

        //l_objDataFile->close();
        fclose(fpWaveFile);
    }

private:
    QVector<QPointF> m_nData;
};

class VI:public IWaveProduct
{
public:
    VI(QWidget* parent):IWaveProduct(parent)
    {
        m_bGrid = false;
        m_showData = true;
        m_ZoomFlag = false;
        m_bRubberbandDrag = false;
        m_bVILabels = false;
        m_bVIMode = true;
        m_bUniPolar = false;
        printf("VI Product\n");
        setMargin(1);
    }
    virtual void setWaveParams(bool pGrid,bool pShowData,bool pZoomFlag,bool pVILabels,bool pVIMode,double)
    {
    	Q_UNUSED(pGrid);
    	Q_UNUSED(pShowData);
    	Q_UNUSED(pZoomFlag);
    	Q_UNUSED(pVILabels);
    	Q_UNUSED(pVIMode);
    }
    virtual void setAutoScale(bool) {}
    virtual void setGainFactor(double)
    {
    }

    virtual void setDimensions(int pXPos,int pYPos,int pWidth,int pHeight)
    {
        setGeometry(pXPos,pYPos,pWidth,pHeight);
    }

    virtual void LoadVITrace(short pChannel, int pTraceType)
    {
        GenerateIPoints(pChannel,pTraceType);
    }

    virtual void LoadVIData (QString pStrRefereceFileName,QString pStrActualFileName,int pIndex,int pWaveTrace,stWaveData *pObjData)
    {
        QFile *l_objDataFile = new QFile(pStrRefereceFileName);
        char *data = new char[100];
        qint64 l_nLineLength=0;
        QString l_strWaveData;
        m_strReferenceData.clear();
        m_strActualData.clear();
        qDebug()<< pStrRefereceFileName << pStrActualFileName <<pObjData->m_nPostamble;
        short int counter=0;
        if(l_objDataFile->open(QFile::ReadOnly))
        {
            while(l_nLineLength !=-1)
            {
                l_nLineLength = l_objDataFile->readLine(data,100);
                if(counter > pObjData->m_nPreamble && counter <= pObjData->m_nPreamble+100){
                //printf("Data %s\n",data);
					l_strWaveData.append(data);l_strWaveData.remove("\n");l_strWaveData.remove("\r");
					if(!l_strWaveData.isEmpty())
						m_strReferenceData.append(l_strWaveData);
					l_strWaveData ="";
                }
                counter++;
            }
        }
        l_objDataFile->close();
        l_objDataFile = new QFile(pStrActualFileName);
        l_nLineLength=0;
        counter =0;
        if(l_objDataFile->open(QFile::ReadOnly))
        {
            while(l_nLineLength !=-1)
            {
                l_nLineLength = l_objDataFile->readLine(data,100);
                if(counter > pObjData->m_nPreamble && counter <= pObjData->m_nPreamble+100){
					//printf("Data %s\n",data);
					l_strWaveData.append(data);l_strWaveData.remove("\n");l_strWaveData.remove("\r");
					if(!l_strWaveData.isEmpty())
						m_strActualData.append(l_strWaveData);
					l_strWaveData ="";
                }
                counter++;
            }
        }
        l_objDataFile->close();
        m_objWaveData = pObjData;
//        m_objWaveData->m_nAmplitude = pObjData->m_nAmplitude;
//        m_objWaveData->m_nFrequency = pObjData->m_nFrequency;
//        m_objWaveData->m_nSamples = m_strReferenceData.count();
//        m_objWaveData->m_nScreenAmplitude = pObjData->m_nScreenAmplitude;
//        m_objWaveData->m_nScreenTime = pObjData->m_nScreenTime;
//        m_objWaveData->m_nTimeperSample = pObjData->m_nTimeperSample;
//        m_objWaveData->m_nSteps = pObjData->m_nSteps;
//        m_objWaveData->m_nXunits = pObjData->m_nXunits;
//        m_objWaveData->m_nYunits = pObjData->m_nYunits;
//        m_objWaveData->m_nMinX = pObjData->m_nMinX;
//        m_objWaveData->m_nMinY = pObjData->m_nMinY;
//        m_objWaveData->m_nOffset = (1.0/m_objWaveData->m_nYunits)/10.0;
//        printf("----------------------------------------------\n");
//        printf("steps:%f\n",m_objWaveData->m_nSteps);
//        printf("Amplitude %f\n",m_objWaveData->m_nAmplitude);
//        printf("Screen Amplitude %f\n",m_objWaveData->m_nScreenAmplitude);
//        printf("Time %f\n",m_objWaveData->m_nScreenTime);
//        printf("Min X %f\n",m_objWaveData->m_nMinX);
//        printf("Min Y %f\n",m_objWaveData->m_nMinY);
//        printf("Samples %d\n",m_objWaveData->m_nSamples);
//        printf("----------------------------------------------\n");

        setPlotSettings(PlotSettings(m_objWaveData->m_nScreenTime, m_objWaveData->m_nScreenAmplitude,m_objWaveData->m_nXunits,m_objWaveData->m_nYunits,m_objWaveData->m_nSteps*m_objWaveData->m_nOffset,m_objWaveData->m_nMinX,m_objWaveData->m_nMinY));
        if(pWaveTrace == 0)
            m_bVIMode = true;
        if(pWaveTrace == 1)
            m_bVIMode = false;
        if(pWaveTrace == 2)
            m_bVIMode = true;

        qDebug()<< "VIMode"<<m_bVIMode;
        GenerateIPoints(pIndex,pWaveTrace);
        printf("Exit VI Data\n");
    }
    virtual void GenerateOscillatorPattern(QString pStrPatternselected,short int)
    {
        Q_UNUSED(pStrPatternselected);
    }

    virtual void GeneratePlotterPoints(short pChannelValue)
    {

    	Q_UNUSED(pChannelValue);
    }
    virtual void calculateSampleTimePeriod()
    {
        m_objWaveData->m_nOffset = (1.0/m_objWaveData->m_nYunits)/10.0;
    }

    virtual void WaveSettings()
    {
        //stWaveData *objWaveData = new stWaveData;
        setPlotSettings(PlotSettings(m_objWaveData->m_nScreenTime, m_objWaveData->m_nScreenAmplitude,m_objWaveData->m_nXunits,m_objWaveData->m_nYunits,m_objWaveData->m_nSteps*m_objWaveData->m_nOffset,m_objWaveData->m_nMinX,m_objWaveData->m_nMinY));
    }
protected:
    double convertToVIPoint(QString pStrData)
    {
        bool ok = true;
        return ((pStrData.toInt(&ok,16) * (m_objWaveData->m_nAmplitude)) / 128) - (m_objWaveData->m_nAmplitude);
    }

    double converttoVZPoint(QString pStrData)
    {

    	bool ok = true;
        return ((pStrData.toInt(&ok,16) * (m_objWaveData->m_nAmplitude)) / 128) - (m_objWaveData->m_nAmplitude);

    }

    double converToVTPoint(QString pStrData)
    {
        bool ok = true;
        double l_nVref = 0.6;
        return ((2*(pStrData.toInt(&ok,16)*l_nVref))/ (pow(2,8)-1)) - l_nVref;

//        bool ok = true;
//        return ((pStrData.toInt(&ok,16) * ((m_objWaveData->m_nAmplitude*2) / pow(2,8))) - (m_objWaveData->m_nAmplitude*2)/2.0)*(1/m_objWaveData->m_nScreenAmplitude);
    }

    void GenerateIPoints(short pChannelValue,int pWaveTrace )
    {
        printf("Acutal Data Count %d\n",m_strActualData.count());
        double l_nXPoint =0.0,l_nYPoint =0.0;

        QVector<QPointF> l_nData;
        for(int l_nIndex=0;l_nIndex<m_strActualData.count();l_nIndex++)
        {
            if(pWaveTrace==0)
            {
                l_nXPoint = convertToVIPoint(m_strActualData[l_nIndex]) ;
                l_nYPoint = convertToVIPoint(m_strReferenceData[l_nIndex]) - convertToVIPoint(m_strActualData[l_nIndex]);
                l_nData.append(QPointF(l_nXPoint,l_nYPoint));
            }
            if(pWaveTrace==1)
            {
                l_nYPoint = converToVTPoint(m_strActualData[l_nIndex]);
                l_nData.append(QPointF(l_nXPoint,l_nYPoint));
                l_nXPoint += m_objWaveData->m_nTimeperSample;
            }
            if(pWaveTrace==2)
            {
                l_nXPoint = converttoVZPoint(m_strActualData[l_nIndex]) ;
                l_nYPoint = l_nXPoint / 1000.0 ;// Impedance Value is hardcoded will be replaced
                l_nData.append(QPointF(l_nXPoint,l_nYPoint));
            }
       // printf("XPoint: %f == YPoint: %f\n",l_nXPoint,l_nYPoint);
        }
        setCurveData(pChannelValue,l_nData);

    }

private:
    QStringList m_strReferenceData;
    QStringList m_strActualData;
    QStringList m_strExpectedData;
    QVector<QPointF> m_nData;

};


class IWaveFormFactory
{
public:
    virtual IWaveProduct* getWaveProduct(QString,QWidget*)=0;
};

class WaveFormFactory//: public IWaveFormFactory
{
public:
    virtual IWaveProduct* getWaveProduct(QString pStrproduct,QWidget *parent)
    {
        if( pStrproduct == "OscillaScope")
        {
            return new OscillaScope(parent);
        }
        else if(pStrproduct == "Oscillator")
        {
            return new Oscillator(parent);
        }
        else if(pStrproduct == "VI")
        {
            return new VI(parent);
        }
        return NULL;
    }

    void sample()
    {

    }
};
class createProduct{
public:
    void CreateWaveProduct(QString function,QWidget* parent){
    	objWaveProduct=objwavefactory.getWaveProduct(function,parent);
        }
    void SetDimensions(int x,int y,int w,int h){
    	objWaveProduct->setDimensions(x,y,w,h);
    }
    void LoadPlotterData(QString pStrFileName,stWaveData* pObjWaveData){
    	objWaveProduct->LoadPlotterData(pStrFileName,pObjWaveData);
    }
    void GenerateOscillatorPattern(QString pStrPatternselected,short int value){
    	objWaveProduct->GenerateOscillatorPattern(pStrPatternselected,value);
    }
    void WaveSettings(){
    	objWaveProduct->WaveSettings();
    }
    void setGainFactor(double value){
    	objWaveProduct->setGainFactor(value);
    }
protected:
    WaveFormFactory objwavefactory;
    IWaveProduct *objWaveProduct;
};
#endif // WAVEFORMCLASS_H
