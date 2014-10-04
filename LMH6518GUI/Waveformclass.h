#ifndef WAVEFORMCLASS_H
#define WAVEFORMCLASS_H
#include "plotter.h"
#include <qdebug.h>
class IWaveProduct:public Plotter
{
public:
    IWaveProduct(QWidget *parent=0):Plotter(parent){}
    void LoadPlotterData(QString pStrFileName,stWaveData *pObjWaveData)
    {
        QFile *l_objDataFile = new QFile(pStrFileName);
        char *data = new char[10];
        qint64 l_nLineLength=0;
        QString l_strWaveData;
        m_strWaveData.clear();
        if(l_objDataFile->open(QFile::ReadOnly))
        {
            while(l_nLineLength !=-1)
            {
                l_nLineLength = l_objDataFile->readLine(data,10);
                l_strWaveData.append(data);l_strWaveData.remove("\n");l_strWaveData.remove("\r");
                if(!l_strWaveData.isEmpty())
                    m_strWaveData.append(l_strWaveData);
                l_strWaveData ="";
            }
        }
        l_objDataFile->close();
        m_objWaveData = pObjWaveData;
        delete data;
        qDebug() << "LoadPlot "<< m_objWaveData->m_nSteps << m_objWaveData->m_nOffset;
    }

    virtual void GeneratePlotterPoints(short pChannelValue)=0;
    virtual void GenerateOscillatorPattern(QString pStrPatternselected,short int,bool) =0;
    virtual void calculateSampleTimePeriod()=0;
    virtual void WaveSettings() =0;
    virtual void setDimensions(int pXPos,int pYPos,int pWidth,int pHeight) =0;
    virtual void setWaveParams(bool pGrid,bool pShowData,bool pZoomFlag,bool pVILabels,bool pVIMode)=0;
    virtual void LoadVITrace(short,int)=0;
    virtual void LoadVIData (QString pStrRefereceFileName,QString pStrActualFileName,int pIndex,int pWaveTrace,stWaveData *pObjWaveData) =0;
    virtual void LoadVIData (QStringList pRefereceList,QStringList pActualList,int pIndex,int pWaveTrace,stWaveData *pObjWaveData)=0;
    virtual QStringList getReferenceData(QString)=0;
    virtual QStringList getActualData(bool)=0;
    virtual void clearCurves(short int)=0;
    virtual void setLabels(QString pStrX1Label,QString pStrY1Label,QString pStrX2Label,QString pStrY2Label)=0;
    virtual void isContinuous(bool pValue)=0;


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
        m_eWaveType = NONETYPE;
    }
    virtual void setDimensions(int pXPos,int pYPos,int pWidth,int pHeight)
    {
        setGeometry(pXPos,pYPos,pWidth,pHeight);
    }
    virtual void isContinuous(bool pValue)
    {
    Q_UNUSED(pValue)
    }
    virtual void setWaveParams(bool pGrid,bool pShowData,bool pZoomFlag,bool pVILabels,bool pVIMode)
    {
    	Q_UNUSED(pGrid);
    	Q_UNUSED(pShowData);
    	Q_UNUSED(pZoomFlag);
    	Q_UNUSED(pVILabels);
    	Q_UNUSED(pVIMode);
    }
    virtual void GenerateOscillatorPattern(QString pStrPatternselected,short int,bool)
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
    virtual void LoadVIData (QStringList pRefereceList,QStringList pActualList,int pIndex,int pWaveTrace,stWaveData *pObjWaveData)
    {
        Q_UNUSED(pRefereceList);
        Q_UNUSED(pActualList);
        Q_UNUSED(pIndex);
        Q_UNUSED(pWaveTrace);
        Q_UNUSED(pObjWaveData);

    }
    virtual void LoadVITrace(short,int)
    {
    }

    virtual QStringList getReferenceData(QString)
    {
    	QStringList lst;
    	return lst;

    }
    virtual QStringList getActualData(bool)
    {
    	QStringList lst;
    	return lst;

    }
    virtual void clearCurves(short int){}
    virtual void setLabels(QString pStrXLabel,QString pStrYLabel,QString pStrX2Label,QString pStrY2Label)
    {
        Q_UNUSED(pStrXLabel);
        Q_UNUSED(pStrYLabel);
        Q_UNUSED(pStrY2Label);
        Q_UNUSED(pStrX2Label);
    }
};

class Oscillator:public IWaveProduct
{
public:
    Oscillator(QWidget* parent):IWaveProduct(parent)
    {
        //printf("FG Product\n");
        //this->move(25,50);
        this->m_bGrid = true;
        this->m_showData = true;
        this->m_ZoomFlag = false;
        this->m_bVILabels = false;
        this->m_bVIMode = false;
        m_bisSingleorContinuous = false;
        //this->resize(620,200);
       // m_objWaveData = new stWaveData();
         //WaveSettings();


    }
    virtual void isContinuous(bool pValue)
    {
    	m_bisSingleorContinuous = pValue;
    }
    virtual void setWaveParams(bool pGrid,bool pShowData,bool pZoomFlag,bool pVILabels,bool pVIMode)
    {
        this->m_bGrid = pGrid;
        this->m_showData = pShowData;
        this->m_ZoomFlag = pZoomFlag;
        this->m_bVILabels = pVILabels;
        this->m_bVIMode = pVIMode;
    }
    virtual void setDimensions(int pXPos,int pYPos,int pWidth,int pHeight)
    {
        setGeometry(pXPos,pYPos,pWidth,pHeight);
    }

    double convertToYPoint(QString pStrData)
      {
          bool ok = true;
          double l_nVref = 0.725;
          return ((2*(pStrData.toInt(&ok,16)*l_nVref))/ (pow(2,8)-1)) - l_nVref;
          //return ((pStrData.toInt(&ok,16) * ((m_objWaveData->m_nAmplitude*2) / pow(2,8))) - (m_objWaveData->m_nAmplitude*2)/2.0)*(1/m_objWaveData->m_nScreenAmplitude);
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
			//qDebug() <<"Data "<< m_strWaveData[l_nIndex];

			l_nXPoint += m_objWaveData->m_nTimeperSample;
		}
		setCurveData(pChannelValue,l_nData);
    }
    virtual void GenerateOscillatorPattern(QString pstrSelectedPattern,short int pChannel,bool isVI)
    {
        //clearCurve(0);
        if(m_objWaveData->m_bUniPolar == true)
            this->m_bUniPolar = true;
        else
            this->m_bUniPolar = false;
        if( pstrSelectedPattern == "SINE"){
            GenerateSinPattern();
            m_eWaveType = SINE;
        }
        else if(pstrSelectedPattern == "SQUARE"){
            GenerateSquarePattern();
            m_eWaveType = SQUARE;
        }
        else if(pstrSelectedPattern == "DC"){
            GenerateDCPattern();
            m_eWaveType = DC;
        }
        else if(pstrSelectedPattern == "TRIANGLE"){
            GenerateTrianglePattern();
            m_eWaveType = TRIANGLE;
        }
        else if(pstrSelectedPattern == "RAMP"){
            GenerateSawtoothPattern();
            m_eWaveType = RAMP;
        }
        else if(pstrSelectedPattern == "PULSE"){
                    GeneratePulsePattern();
                    m_eWaveType = PULSE;
                }
        else if(pstrSelectedPattern == "RECEIVE"){
        	GeneratePlotterPoints(pChannel);
                m_eWaveType = NONETYPE;
        	return;
        	}
        else
            return;
        if(isVI==false)
                setCurveData(0,m_nData1);

    }

    virtual void calculateSampleTimePeriod()
    {
        m_objWaveData->m_nTimeperSample = (1.0 / m_objWaveData->m_nFrequency) / (double)(m_objWaveData->m_nSamples/m_objWaveData->m_nCycles);
    }

    virtual void WaveSettings()
    {
         //printf("Offset1 %f Samples %d Steps %f\n",m_objWaveData->m_nOffset,m_objWaveData->m_nSamples,m_objWaveData->m_nSteps);
        float l_nAmp =1.0;
        if( m_objWaveData->m_bUniPolar == true)
        {
            l_nAmp =2.0;
        }

          if(m_objWaveData->m_nAmplitude >0.0)
             setAmplitude(m_objWaveData->m_nAmplitude,m_objWaveData->m_nDutyCycles);
          else
              setAmplitude(0.0,m_objWaveData->m_nDutyCycles);

        qDebug()<< "Wave Offset" << m_objWaveData->m_nOffset;
        qDebug()<< "Wave Offset" << m_objWaveData->m_nSteps;
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
    virtual QStringList getReferenceData(QString)
    {
    	QStringList lst;
    	return lst;

    }
    virtual QStringList getActualData(bool)
    {
    	QStringList lst;
    	return lst;
    }
    virtual void LoadVIData (QStringList pRefereceList,QStringList pActualList,int pIndex,int pWaveTrace,stWaveData *pObjWaveData)
    {
        Q_UNUSED(pRefereceList);
        Q_UNUSED(pActualList);
        Q_UNUSED(pIndex);
        Q_UNUSED(pWaveTrace);
        Q_UNUSED(pObjWaveData);

    }
    virtual void clearCurves(short int){}
    virtual void setLabels(QString pStrXLabel,QString pStrYLabel,QString pStrX2Label,QString pStrY2Label)
    {
        Q_UNUSED(pStrXLabel);
        Q_UNUSED(pStrYLabel);
        Q_UNUSED(pStrY2Label);
        Q_UNUSED(pStrX2Label);
    }
protected:

    void GenerateSinPattern()
    {
        double l_nYPoint =0.0,l_nDegree =m_objWaveData->m_nPhase,l_nXPoint =0.0;
        m_nData.clear();
        m_nData1.clear();
        //printf("Value:%d\n",m_objWaveData->m_bUniPolar);
        unsigned int l_nSampleIndex=0;
        unsigned int l_nIndex =0;
        unsigned int l_nSamples=0;
        unsigned int l_nRemainder =0;
        unsigned int l_nTemp=0;
        l_nSamples = m_objWaveData->m_nSamples / m_objWaveData->m_nCycles;
        l_nRemainder = (m_objWaveData->m_nSamples%(int)m_objWaveData->m_nCycles)/l_nSamples;
        l_nTemp = l_nSamples;
        double l_nPhaseAngle=0.0;
        l_nPhaseAngle = (l_nDegree*PI) / 180.0;
        qDebug() << "Amplitude:" << m_objWaveData->m_nAmplitude;
        qDebug() << "VRef:" << m_objWaveData->m_nVRef;
        qDebug() << "Samples:" << m_objWaveData->m_nSamples;
        qDebug() <<  "Cycles:" << m_objWaveData->m_nCycles;
        qDebug() << "TimeperSample" << m_objWaveData->m_nTimeperSample;
        //double l_nAmplitude = ((m_objWaveData->m_nAmplitude/2.0)/m_objWaveData->m_nVRef);
          double l_nAmplitude = (m_objWaveData->m_nAmplitude)*m_objWaveData->m_nVRef;
        //double l_nAmplitude = (m_objWaveData->m_nAmplitude);
        qDebug() <<  "Converted Amplitude:" << l_nAmplitude;
        double l_nTempYPoint=0.0;
        double l_nYPoint1 =0.0;
        double l_nTempAmp =0.0;
        if(m_objWaveData->m_nAmplitude >0.0)
            l_nTempAmp =1.0;
        while(l_nSampleIndex < (m_objWaveData->m_nCycles+l_nRemainder))
        {
            for(;l_nIndex<l_nSamples;l_nIndex++)
            {
            	l_nTempYPoint = l_nAmplitude*sin(l_nPhaseAngle);
                //l_nYPoint = l_nTempYPoint * m_objWaveData->m_nVRef;
                l_nYPoint = l_nTempYPoint;
                l_nYPoint1 = l_nTempAmp*sin(l_nPhaseAngle);
                //printf("XPoint :%f TempYPoint : %f\n",l_nXPoint,l_nTempYPoint);
                //printf("XPoint :%f YPoint : %f\n",l_nXPoint,l_nYPoint);
                if( m_objWaveData->m_bUniPolar == true)
                    l_nYPoint = l_nYPoint + 1.0;
                m_nData.append(QPointF(l_nXPoint,l_nYPoint));
                m_nData1.append(QPointF(l_nXPoint,l_nYPoint1));
                l_nPhaseAngle = (l_nPhaseAngle +(2*PI) / (m_objWaveData->m_nSamples/m_objWaveData->m_nCycles));
                l_nXPoint += m_objWaveData->m_nTimeperSample;
                if(l_nPhaseAngle > (2*PI))
                    l_nPhaseAngle = l_nPhaseAngle - (2*PI);
                //qDebug()<<l_nYPoint;
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
            m_nData1.clear();
            double l_nConstValue = (2.0*PI) *(float)(m_objWaveData->m_nDutyCycles);
            qDebug() << "Square Wave " << m_objWaveData->m_nDutyCycles <<"Cycles"<< m_objWaveData->m_nCycles << "Constant Value" <<l_nConstValue;
            //printf(" DutyCycles %f\n",m_objWaveData->m_nDutyCycles);
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
            qDebug() << "Phase Angle " << l_nPhaseAngle;
            //double l_nAmplitude = ((m_objWaveData->m_nAmplitude/2.0)/m_objWaveData->m_nVRef);
            //double l_nAmplitude = (m_objWaveData->m_nAmplitude);
            double l_nAmplitude = (m_objWaveData->m_nAmplitude)*m_objWaveData->m_nVRef;

            //printf("Local Sample: %d\n",l_nSamples);
            double l_nTempYPoint=0.0;
            double l_nTempAmp =0.0;
             double l_nYPoint1 =0.0;
            if(m_objWaveData->m_nAmplitude >0.0)
                l_nTempAmp =1.0;

            while(l_nSampleIndex < (m_objWaveData->m_nCycles+l_nRemainder))
            {
                for(;l_nIndex<m_objWaveData->m_nSamples;l_nIndex++)
                {

                    if(l_nPhaseAngle < l_nConstValue){
                    	l_nTempYPoint = l_nAmplitude;
                        l_nYPoint = l_nTempYPoint;// * m_objWaveData->m_nVRef;
                        l_nYPoint1 = l_nTempAmp;

                    }
                    else{
                    	l_nTempYPoint = -(l_nAmplitude);
                    	l_nYPoint = l_nTempYPoint ;//* m_objWaveData->m_nVRef;
                            l_nYPoint1 = -l_nTempAmp;
                    }
                    if( m_objWaveData->m_bUniPolar == true)
                        l_nYPoint = l_nYPoint + 1.0;

                    m_nData.append(QPointF(l_nXPoint,l_nYPoint));
                    m_nData1.append(QPointF(l_nXPoint,l_nYPoint1));
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
    void GenerateDCPattern()
        {
            double l_nYPoint =0.0,l_nDegree =m_objWaveData->m_nPhase,l_nXPoint =0.0;

            m_nData.clear();
            m_nData1.clear();
            double l_nConstValue = (2.0*PI) *(float)(m_objWaveData->m_nDutyCycles);
            qDebug() << "Square Wave " << m_objWaveData->m_nDutyCycles <<"Cycles"<< m_objWaveData->m_nCycles << "Constant Value" <<l_nConstValue;
            //printf(" DutyCycles %f\n",m_objWaveData->m_nDutyCycles);
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
            qDebug() << "Phase Angle " << l_nPhaseAngle;
            //double l_nAmplitude = ((m_objWaveData->m_nAmplitude/2.0)/m_objWaveData->m_nVRef);
            //double l_nAmplitude = (m_objWaveData->m_nAmplitude);
            double l_nAmplitude = (m_objWaveData->m_nAmplitude)*m_objWaveData->m_nVRef;
            Q_UNUSED(l_nAmplitude)
            //printf("Local Sample: %d\n",l_nSamples);
            double l_nTempYPoint=0.0;
            double l_nTempAmp =0.0;
             double l_nYPoint1 =0.0;
            if(m_objWaveData->m_nAmplitude >0.0)
                l_nTempAmp =1.0;

            while(l_nSampleIndex < (m_objWaveData->m_nCycles+l_nRemainder))
            {
                for(;l_nIndex<m_objWaveData->m_nSamples;l_nIndex++)
                {

                    if(l_nPhaseAngle < l_nConstValue){
                    	l_nTempYPoint = 0;//l_nAmplitude;
                        l_nYPoint = l_nTempYPoint;// * m_objWaveData->m_nVRef;
                        l_nYPoint1 = 0;//l_nTempAmp;

                    }
                    else{
                    	l_nTempYPoint = 0;//-(l_nAmplitude);
                    	l_nYPoint = l_nTempYPoint ;//* m_objWaveData->m_nVRef;
                            l_nYPoint1 = 0;//-l_nTempAmp;
                    }
                    if( m_objWaveData->m_bUniPolar == true)
                        l_nYPoint = l_nYPoint + 1.0;

                    m_nData.append(QPointF(l_nXPoint,l_nYPoint));
                    m_nData1.append(QPointF(l_nXPoint,l_nYPoint1));
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

    void GeneratePulsePattern()
    {
        double l_nYPoint =0.0,l_nDegree =m_objWaveData->m_nPhase,l_nXPoint =0.0;

        qDebug()<<"Inside Generate Pulse Pattern";

        m_nData.clear();
        m_nData1.clear();
        double l_nConstValue = (2.0*PI) *(float)(m_objWaveData->m_nDutyCycles);
        qDebug() << "Pulse Wave " << m_objWaveData->m_nDutyCycles <<"Cycles"<< m_objWaveData->m_nCycles << "Constant Value" <<l_nConstValue;
        //printf(" DutyCycles %f\n",m_objWaveData->m_nDutyCycles);
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
        qDebug() << "Phase Angle " << l_nPhaseAngle;
        //double l_nAmplitude = ((m_objWaveData->m_nAmplitude/2.0)/m_objWaveData->m_nVRef);
        double l_nAmplitude = (m_objWaveData->m_nAmplitude);
        //printf("Local Sample: %d\n",l_nSamples);
        double l_nTempYPoint=0.0;
        double l_nTempAmp =0.0;
         double l_nYPoint1 =0.0;
        if(m_objWaveData->m_nAmplitude >0.0)
            l_nTempAmp =1.0;

        while(l_nSampleIndex < (m_objWaveData->m_nCycles+l_nRemainder))
        {
            for(;l_nIndex<m_objWaveData->m_nSamples;l_nIndex++)
            {

                if(l_nPhaseAngle < l_nConstValue){
                	l_nTempYPoint = -l_nAmplitude;
                    l_nYPoint = l_nTempYPoint ;//* m_objWaveData->m_nVRef;
                    l_nYPoint1 = l_nTempAmp;

                }
                else{
                	l_nTempYPoint = (l_nAmplitude);
                	l_nYPoint = l_nTempYPoint ;//* m_objWaveData->m_nVRef;
                        l_nYPoint1 = -l_nTempAmp;
                }
                if( m_objWaveData->m_bUniPolar == true)
                    l_nYPoint = l_nYPoint + 1.0;

                m_nData.append(QPointF(l_nXPoint,l_nYPoint));
                m_nData1.append(QPointF(l_nXPoint,l_nYPoint1));
                l_nPhaseAngle = (l_nPhaseAngle +(2*PI) / (m_objWaveData->m_nSamples/m_objWaveData->m_nCycles));
                l_nXPoint += m_objWaveData->m_nTimeperSample;
               // printf("Phase Angle : %f XPoint :%f YPoint : %f\n",l_nPhaseAngle,l_nXPoint,l_nYPoint);
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
        m_nData1.clear();
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
        //double l_nAmplitude = ((m_objWaveData->m_nAmplitude/2.0)/m_objWaveData->m_nVRef);
        double l_nAmplitude = (m_objWaveData->m_nAmplitude)*m_objWaveData->m_nVRef;
        //double l_nAmplitude = (m_objWaveData->m_nAmplitude);
        double l_nTempYPoint=0.0;
        double l_nTempAmp =0.0;
         double l_nYPoint1 =0.0;
        if(m_objWaveData->m_nAmplitude >0.0)
            l_nTempAmp =1.0;

        while(l_nSampleIndex < (m_objWaveData->m_nCycles+l_nRemainder))
        {

            for(;l_nIndex<m_objWaveData->m_nSamples;l_nIndex++)
            {
                if(l_nPhaseAngle < PI)
                {
                	l_nTempYPoint = -(l_nAmplitude) + (2*l_nAmplitude/PI) * l_nPhaseAngle;
                	 l_nYPoint = l_nTempYPoint ;//* m_objWaveData->m_nVRef;
                         l_nYPoint1 = -(l_nTempAmp) + (2*l_nTempAmp/PI) * l_nPhaseAngle;
                }
                else
                {
                	l_nTempYPoint = 3*(l_nAmplitude) - (2*l_nAmplitude/PI) * l_nPhaseAngle;
                	 l_nYPoint = l_nTempYPoint ;//* m_objWaveData->m_nVRef;
                         l_nYPoint1 = 3*(l_nTempAmp) - (2*l_nTempAmp/PI) * l_nPhaseAngle;
                }
                if( m_objWaveData->m_bUniPolar == true)
                    l_nYPoint = l_nYPoint + 1.0;

                m_nData.append(QPointF(l_nXPoint,l_nYPoint));
                m_nData1.append(QPointF(l_nXPoint,l_nYPoint1));
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
        m_nData1.clear();
        unsigned int l_nSampleIndex=0;
        unsigned int l_nIndex =0;
        unsigned int l_nSamples=0;
        unsigned int l_nTemp=0;
        unsigned int l_nRemainder =0;
        double l_nConstValue = (2.0*PI) *(float)(m_objWaveData->m_nDutyCycles);
        Q_UNUSED(l_nConstValue)
        qDebug()<<"Cycles :"<<m_objWaveData->m_nCycles<<"Duty Cycles"<<m_objWaveData->m_nDutyCycles;
		 l_nSamples = m_objWaveData->m_nSamples / m_objWaveData->m_nCycles;
		 l_nRemainder = (m_objWaveData->m_nSamples%(int)m_objWaveData->m_nCycles)/l_nSamples;
		  //printf("Remainter : %d\n",l_nRemainder);
        double l_nPhaseAngle=0.0;
        l_nPhaseAngle = (l_nDegree*PI) / 180.0;
        //double l_nAmplitude = ((m_objWaveData->m_nAmplitude/2.0)/m_objWaveData->m_nVRef);
        //double l_nAmplitude = (m_objWaveData->m_nAmplitude);
        double l_nAmplitude = (m_objWaveData->m_nAmplitude)*m_objWaveData->m_nVRef;
        double l_nTempYPoint=0.0;
        double l_nTempAmp =0.0;
         double l_nYPoint1 =0.0;
        if(m_objWaveData->m_nAmplitude >0.0)
            l_nTempAmp =1.0;
        while(l_nSampleIndex < (m_objWaveData->m_nCycles+l_nRemainder))
        {

            for(;l_nIndex<m_objWaveData->m_nSamples;l_nIndex++)
            {
            	l_nTempYPoint =l_nAmplitude - (l_nAmplitude/PI) * l_nPhaseAngle;
//                if(l_nPhaseAngle < l_nConstValue){
                    l_nYPoint = l_nTempYPoint;// * m_objWaveData->m_nVRef;
                    l_nYPoint1 = l_nTempAmp - (l_nTempAmp/PI) * l_nPhaseAngle;
//                }
//                else{
//                    l_nYPoint = -(l_nTempYPoint * m_objWaveData->m_nVRef);
//                    l_nYPoint1 = -l_nTempAmp;
//                }
                if( m_objWaveData->m_bUniPolar == true)
                        l_nYPoint = l_nYPoint + 1.0;
                m_nData.append(QPointF(l_nXPoint,l_nYPoint));
                 m_nData1.append(QPointF(l_nXPoint,l_nYPoint1));
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
                //printf("Y Point %f\n",m_nPointValue.y());
            	double l_nRefPoint = 0.0;
            	if(m_objWaveData->m_bCalibChecked)
            	{
            		l_nRefPoint =  (m_nPointValue.y() - m_objWaveData->m_nCalibrationConstant) /m_objWaveData->m_nCalibrationGain;
//            		qDebug()<<"Constant :"<<m_objWaveData->m_nCalibrationConstant<<"Gain :"<<m_objWaveData->m_nCalibrationGain;
            	}
            	else
            	{
            		l_nRefPoint = m_nPointValue.y();
            	}
                l_nHexValue = ((l_nRefPoint)+m_objWaveData->m_nVRef) * ((pow(2,m_objWaveData->m_nResolution))-1) / (2 * (m_objWaveData->m_nVRef));
                //qDebug()<<l_nHexValue;
               // printf("VRef %f %d\n",l_nRefPoint,l_nHexValue);
            }
            QString l_strHexValue;

            fprintf(fpWaveFile,"%X\n",l_nHexValue & 0x00003FFF);
        }
        if(m_objWaveData->m_nCycles==1)
        	fprintf(fpWaveFile,"%X\n",0x1FFF);
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
    QVector<QPointF> m_nData1;
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
        m_bVILabels = true;
        m_bVIMode = true;
        m_bUniPolar = false;
        m_bClearTrace = false;
        //printf("VI Product\n");
        setMargin(0);
    }
    virtual void setWaveParams(bool pGrid,bool pShowData,bool pZoomFlag,bool pVILabels,bool pVIMode)
    {
    	Q_UNUSED(pGrid);
    	Q_UNUSED(pShowData);
    	Q_UNUSED(pZoomFlag);
    	Q_UNUSED(pVILabels);
    	Q_UNUSED(pVIMode);
    }
    virtual void setDimensions(int pXPos,int pYPos,int pWidth,int pHeight)
    {
        setGeometry(pXPos,pYPos,pWidth,pHeight);
    }

    virtual void LoadVITrace(short pChannel, int pTraceType)
    {

        GenerateIPoints(pChannel,pTraceType);
    }

    virtual void LoadVIData (QStringList pRefereceList,QStringList pActualList,int pIndex,int pWaveTrace,stWaveData *pObjWaveData)
    {
    	//clearCurveData();
    	m_bVILabels = true;
    	m_bClearTrace = false;
    	m_strReferenceData.clear();
    	m_strActualData.clear();
    	m_strReferenceData = pRefereceList;
    	m_strActualData = pActualList;
        m_objWaveData = pObjWaveData;
        setPlotSettings(PlotSettings(m_objWaveData->m_nScreenTime, m_objWaveData->m_nScreenAmplitude,m_objWaveData->m_nXunits,m_objWaveData->m_nYunits,m_objWaveData->m_nSteps*m_objWaveData->m_nOffset,m_objWaveData->m_nMinX,m_objWaveData->m_nMinY));
        if(pWaveTrace == 0)
            m_bVIMode = true;
        if(pWaveTrace == 1)
            m_bVIMode = false;
        if(pWaveTrace == 2)
            m_bVIMode = true;
        //qDebug()<< "VIMode"<<m_bVIMode;
        GenerateIPoints(pIndex,pWaveTrace);
    }


    virtual void LoadVIData (QString pStrRefereceFileName,QString pStrActualFileName,int pIndex,int pWaveTrace,stWaveData *pObjData)
    {
    	m_bClearTrace = false;
    	m_bVILabels = true;
        QFile l_objDataFile(pStrRefereceFileName);
        char *data = new char[10];
        int l_nLineLength=0;
        QString l_strWaveData;
        m_strReferenceData.clear();
        m_strActualData.clear();
        //qDebug()<< pStrRefereceFileName << pStrActualFileName <<pObjData->m_nPostamble;
        short int counter=0;
        if(l_objDataFile.open(QFile::ReadOnly))
        {
            while(l_nLineLength !=-1)
            {
                l_nLineLength = l_objDataFile.readLine(data,10);
                if(counter > pObjData->m_nPreamble && counter <= pObjData->m_nPreamble+100){
                //printf("Data %s\n",data);
					l_strWaveData.append(data);
					l_strWaveData.remove("\n");
					l_strWaveData.remove("\r");
					if(!l_strWaveData.isEmpty())
						m_strReferenceData.append(l_strWaveData);
					l_strWaveData ="";
                }
                counter++;
            }
        }
        l_objDataFile.close();
        QFile l_objDataFile1(pStrActualFileName);
        l_nLineLength=0;
        counter =0;
        if(l_objDataFile1.open(QFile::ReadOnly))
        {
            while(l_nLineLength !=-1)
            {
                l_nLineLength = l_objDataFile1.readLine(data,10);
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
        l_objDataFile1.close();
        m_objWaveData = pObjData;

        setPlotSettings(PlotSettings(m_objWaveData->m_nScreenTime, m_objWaveData->m_nScreenAmplitude,m_objWaveData->m_nXunits,m_objWaveData->m_nYunits,m_objWaveData->m_nSteps*m_objWaveData->m_nOffset,m_objWaveData->m_nMinX,m_objWaveData->m_nMinY));
        if(pWaveTrace == 0)
            m_bVIMode = true;
        if(pWaveTrace == 1)
            m_bVIMode = false;
        if(pWaveTrace == 2)
            m_bVIMode = true;

        //qDebug()<< "VIMode"<<m_bVIMode;
        GenerateIPoints(pIndex,pWaveTrace);
        delete data;
        //printf("Exit VI Data\n");
    }
    virtual void GenerateOscillatorPattern(QString pStrPatternselected,short int,bool)
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

    virtual QStringList getReferenceData(QString l_strRefName)
    {
    	if(l_strRefName.count() ==0 )
    		l_strRefName = "./ReferenceData.bin";
        QFile l_objDataFile(l_strRefName);
        char *data = new char[10];
        qint64 l_nLineLength=0;
        QString l_strWaveData;
        m_strReferenceData.clear();
        short int counter=0;
        if(l_objDataFile.open(QFile::ReadOnly))
        {
            while(l_nLineLength !=-1)
            {
                l_nLineLength = l_objDataFile.readLine(data,10);
                if(counter >= 50 && counter < 50+100){
					l_strWaveData.append(data);
					l_strWaveData.remove("\n");
					l_strWaveData.remove("\r");
					if(!l_strWaveData.isEmpty())
						m_strReferenceData.append(l_strWaveData);
					l_strWaveData ="";
                }
                counter++;
            }
        }
        l_objDataFile.close();
    	//qDebug()<<"Reference Data"<<m_strReferenceData.count();
        delete data;
    	return m_strReferenceData;
    }
    virtual QStringList getActualData(bool compare)
    {
        QFile l_objDataFile("./AcutalData.bin");
        char *data = new char[10];
        qint64 l_nLineLength=0;
        QString l_strWaveData;
        m_strActualData.clear();
        short int counter=0;
        if(l_objDataFile.open(QFile::ReadOnly))
        {
            while(l_nLineLength !=-1)
            {
                l_nLineLength = l_objDataFile.readLine(data,10);
                if(counter>=0 && counter <50  && compare == true)
                {
					l_strWaveData.append(data);
					l_strWaveData.remove("\n");
					l_strWaveData.remove("\r");
					if(!l_strWaveData.isEmpty())
						m_strActualData.append(l_strWaveData);
					l_strWaveData ="";
                }
                if(counter >=50 && counter < 50+100){
					l_strWaveData.append(data);
					l_strWaveData.remove("\n");
					l_strWaveData.remove("\r");
					if(!l_strWaveData.isEmpty())
						m_strActualData.append(l_strWaveData);
					l_strWaveData ="";
                }
                if(counter>=150 && counter <200  && compare == true)
                {
					l_strWaveData.append(data);
					l_strWaveData.remove("\n");
					l_strWaveData.remove("\r");
					if(!l_strWaveData.isEmpty())
						m_strActualData.append(l_strWaveData);
					l_strWaveData ="";
                }

                counter++;
            }
        }
        l_objDataFile.close();
    	//qDebug()<<"Actual Data"<<m_strActualData.count();
        delete data;
    	return m_strActualData;
    }
    virtual void clearCurves(short int pIndex)
    {
    	this->clearCurve(pIndex);
    }
    virtual void setLabels(QString pStrX1Label,QString pStrY1Label,QString pStrX2Label,QString pStrY2Label)
    {
    	this->m_strX1Label = pStrX1Label;
    	this->m_strY1Label = pStrY1Label;
    	this->m_strX2Label = pStrX2Label;
    	this->m_strY2Label = pStrY2Label;

    }
    virtual void isContinuous(bool pValue)
    {
        Q_UNUSED(pValue)
    }
protected:
    double convertToVIPoint(QString pStrData)
    {
        bool ok = true;
        //double l_nVref = 0.6;
        return ((pStrData.toInt(&ok,16) * (m_objWaveData->m_nAmplitude*2.0)) /(pow(2,8)-1)) - m_objWaveData->m_nAmplitude;
    }

    double converttoVZPoint(QString pStrData)
    {

    	bool ok = true;
    	//double l_nVref = 0.6;
        return ((pStrData.toInt(&ok,16) * (m_objWaveData->m_nAmplitude*2.0)) / (pow(2,8)-1)) - (m_objWaveData->m_nAmplitude);

    }

    double converToVTPoint(QString pStrData)
    {
        bool ok = true;
        double l_nVref = 1.0;
        //return ((((pStrData.toInt(&ok,16))*(l_nVref*2.0)))/ (pow(2,8)-1)- l_nVref);
        return (((pStrData.toInt(&ok,16)*l_nVref*2.0))/ (pow(2,8)-1)) - l_nVref;

//        bool ok = true;
     //   return ((pStrData.toInt(&ok,16) * ((m_objWaveData->m_nAmplitude*2) / pow(2,8))) - (m_objWaveData->m_nAmplitude*2)/2.0)*(1/m_objWaveData->m_nScreenAmplitude);
    }

    void GenerateIPoints(short pChannelValue,int pWaveTrace )
    {
       // printf("Acutal Data Count %d\n",m_strActualData.count());
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
        //printf("XPoint: %f == YPoint: %f\n",l_nXPoint,l_nYPoint);
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
    virtual IWaveProduct* getWaveProduct(QString,QWidget*);
};

class WaveFormFactory
{
public:
    IWaveProduct* getWaveProduct(QString pStrproduct,QWidget *parent)
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

};

#endif // WAVEFORMCLASS_H