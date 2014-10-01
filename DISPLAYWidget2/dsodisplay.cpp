#include "dsodisplay.h"
#include "ui_dsodisplay.h"

DSODisplay::DSODisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DSODisplay)
{
    ui->setupUi(this);
//    this->setAttribute(Qt::WA_NoMousePropagation);
    setBackgroundRole(QPalette::Shadow);
    setAutoFillBackground(true);
    //this->installEventFilter(this);
    //this->setGeometry(10,10,800,600);
}

bool DSODisplay::evenFilter(QObject *target,QEvent *e)
{
	if(e->type() == QEvent::MouseMove)
	{
		//qDebug()<<"Mouse Filter in DSODisplay APP";
		return evenFilter(target,e);
	}
}

void DSODisplay::initializeWaveDisplay(int pX,int pY,int pW,int pH)
{
	this->setGeometry(pX,pY,pW,pH);
    m_objXYModel = new DSOXYGridModel(this);
    m_objXYModel->setXYGridRect(new DSOGridRect(pX,pY,pW,pH));
    m_objXYModel->setPlotSettings(new PlotXYSettings(0.0,0.0000001,10.0,8.0,0.0,-0.5,0.5),CHANNEL1);
    m_objXYModel->setPlotSettings(new PlotXYSettings(0.0,0.0000001,10.0,8.0,0.0,-0.5,0.5),CHANNEL3);
    m_objXYView = new DSOXYGridView(this);
    m_objXYView->initialiseGridScene();
    m_objXYView->constructDSOPlane(m_objXYModel->getXYGridRect(),m_objXYModel->getPlotSettings(CHANNEL1));
    m_objXYView->constructOffsetPointer();
    m_objXYView->constructTriggerPointers();
    m_objXYView->constructVCursor();
    m_objXYView->constructHCursor();
    m_objXYView->contructChannelData(m_objXYModel->getPlotSettings(CHANNEL1),m_objXYModel->getPlotSettings(CHANNEL3));
    setStyleSheet("background-color:black");
    qDebug()<<"display constr";

}

void DSODisplay::mouseMoveEvent(QMouseEvent *event)
{
	//qDebug()<<"Inside Mouse Move";
	event->ignore();
}

void DSODisplay::mousePressEvent(QMouseEvent *event)
 {
     if (event->button() == Qt::LeftButton) {
         // handle left mouse button here
    	// qDebug()<<"Left Button Handled";
     } else {
         // pass on other buttons to base class
    	 QWidget::mousePressEvent(event);
     }
 }
DSODisplay::~DSODisplay()
{
    delete ui;
}

void DSODisplay::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

//Interface

void DSODisplayInterface::initializeWaveDisplay(QRect pRect)
{
	m_objDSODisplay->initializeWaveDisplay(pRect.x(),pRect.y(),pRect.width(),pRect.height());
}
void DSODisplayInterface::initialiseWaveSettings()
{
    m_nAcquisitionTime=m_nAcutalRecordLength=m_nCH1TimePerDivision=m_nCH2TimePerDivision=m_nCH1VoltPerDivision=m_nCH2VoltPerDivsion=0.0;
    m_nCH1FPAtteunationFactor=m_nCH2FPAtteunationFactor=1.0;
    m_nCH1FSSettings=m_nCH2FSSettings = 0.733347;
}

void DSODisplayInterface::LoadChannel1Data(double pVoltTrigger,double pHorizontalTrigger)
{
    PlotXYSettings *settings = m_objDSODisplay->m_objXYModel->getPlotSettings(CHANNEL1);
    settings->setMaxTimeDivision(m_nAcquisitionTime);
    settings->setMaxVoltageDivision(m_nCH1VoltPerDivision);
    settings->setMinVoltageDivision(-m_nCH1VoltPerDivision);
	m_objCH1Data.clear();
    bool isTriggerFound=false;
	QFile l_objDataFile("R1FIFO.txt");
    char data[10];
    qint64 l_nLineLength=0;
    QString l_strWaveData;
    double m_nXData=0.0;
    unsigned short l_nCounter=0;
  //  qDebug()<<"Reading file";
    if(l_objDataFile.open(QFile::ReadOnly))
    {
		   while(l_nLineLength !=-1)
		   {
			   l_nLineLength = l_objDataFile.readLine(data,10);
			   l_strWaveData.append(data);l_strWaveData.remove("\n");l_strWaveData.remove("\r");
			   if(l_nCounter == (m_nSamplesCount*2))
				   break;
			   isTriggerFound=true;
				if(isTriggerFound)
				{
					m_objCH1Data.insert(l_nCounter,QPointF(m_nXData,convertFIFOData(l_strWaveData)));
					l_nCounter++;
				}
			   m_nXData = l_nCounter;//m_nXData + l_nSamplingRate;
			   l_strWaveData ="";
		   }
   }
  //  qDebug()<<"CH1 Vector Data loaded";
  // convertToInterPolatePoints();

   l_objDataFile.close();
}



void DSODisplayInterface::convertToInterPolatePoints()
{
	/* Implementing using Linear Interpolation Technique
	 * Linear interpolation is most reliable if the x you stick in is between the values x0 and x1. If x is not between these two values, technically you are extrapolating rather than interpolating. This still works as long as the new value of x isn't too far from x0 and x1.
	  The further the new x value is from the input values used to specify the line, the more suspicious you should be of your output.
		Now suppose you have the data points (x0, y0) and (x1, y1), but instead of trying to predict a new y value you want to predict a new x value. That is, you have a y value you're trying to get out and you want to guess what input x would give you that output. Then you can reverse the roles of x and y in the equation above and get the following:
		If you have two inputs, x0 and x1, and two corresponding outputs y0 and y1, the equation of the line connecting (x0, y0) and (x1, y1) is the following:
		if (x[0] == x[1] || x[0] == x[2] || x[1] == x[2])
	// report error
		else
    		y[2] = y[0]*(x[2] - x[1])/(x[0] - x[1]) + y[1]*(x[2] - x[0])/(x[1] - x[0]);

    if (y[0] == y[1] || y[0] == y[2] || y[1] == y[2])
    // report error
		else
    x[2] = x[0]*(y[2] - y[1])/(y[0] - y[1]) + x[1]*(y[2] - y[0])/(y[1] - y[0]);
	*/
	QPointF l_nXYValues1,l_nXYValues2;
/*	double l_nNewYValue=0.0,l_nNewXValue;
	for(int l_nIndex=0;l_nIndex<m_objCH1Data.count()/2;l_nIndex++)
	{
		l_nXYValues1 = m_objCH1Data.value(l_nIndex);
		l_nXYValues2 = m_objCH1Data.value(l_nIndex+1);

	//	l_nNewXValue = l_nXYValues1.x()*();
		l_nNewYValue = l_nXYValues1.y() *((l_nXYValues2.x()-l_nXYValues1.x()));
	}*/
}

void DSODisplayInterface::convertToDecimation()
{
        // Displaying all Points
    //int m_nSamplesCount = m_nSamplesCount;
    int m_nRectWidth=m_objDSODisplay->m_objXYView->getRectWidth();
    QFile l_objDataFile("R1FIFO.txt");
   char data[10];
   qint64 l_nLineLength=0;//,l_nLineLengthR2=0;
   QString l_strWaveData,l_strWaveDataR2;
   double m_nXData=0.0;
   unsigned short l_nCounter=0;
   unsigned int l_nTC=0;
   double l_nSamplesperPixel=0.0;
   bool l_nNormalMode=true;
   bool l_bPeakDetectMode=false;

   bool l_bAverageMode=false;
   l_nSamplesperPixel = (double)ceil((double)m_nSamplesCount/(double)m_nRectWidth);
   //qDebug()<<"samples Per Pixel:"<<l_nSamplesperPixel<<m_nSamplesCount;
   if(l_nSamplesperPixel <= 1.0){
           l_nTC = m_nSamplesCount;
           l_nSamplesperPixel=1.0;
   }
   else
           l_nTC = m_nRectWidth;
   //qDebug()<<"samples Per Pixel:"<<l_nSamplesperPixel<<l_nTC;
   m_objDSODisplay->m_objXYView->setDSOChannelCount(l_nSamplesperPixel);

   m_objChannel1Data.clear();
   QList<double> l_nlstYPoints;
   if(l_objDataFile.open(QFile::ReadOnly))
   {
           while(l_nLineLength !=-1)
           {
                   l_nlstYPoints.clear();
                   for(int l_nFileCount=0;l_nFileCount<l_nSamplesperPixel;l_nFileCount++)
                   {
                             l_nLineLength = l_objDataFile.readLine(data,10);
                             l_strWaveData.append(data);l_strWaveData.remove("\n");l_strWaveData.remove("\r");
                            // qDebug()<<"Data:"<<l_strWaveData;
                             l_nlstYPoints.insert(l_nFileCount,convertFIFOData(l_strWaveData));
                             l_strWaveData="";
                   }
                   if(l_nCounter == (l_nTC))
                           break;
                        //m_objCH1Data.insert(l_nCounter,QPointF(m_nXData,convertFIFOData(l_strWaveData)));
                   if(l_bAverageMode == true && l_nSamplesperPixel >1)
                   {
                	   calculateAveragePoints(l_nlstYPoints);
                	   l_nlstYPoints.clear();
                	   l_nlstYPoints.insert(0,m_nAveragePoint);

                   }
                   else if(l_bPeakDetectMode==true && l_nSamplesperPixel >1)
                   {
                	   // Find Min Max points
                	   findMinMax(l_nlstYPoints);
                	   l_nlstYPoints.clear();
                	   l_nlstYPoints.insert(0,m_nMinPoint);
                	   l_nlstYPoints.insert(1,m_nMaxPoint);
                   }
                   m_objChannel1Data.insert(m_nXData,l_nlstYPoints);
                   l_nCounter++;
                   m_nXData = l_nCounter;//m_nXData + l_nSamplingRate;
                   l_strWaveData ="";
           }
   }
   if(l_bPeakDetectMode==true && l_nSamplesperPixel >1)
   {
	   l_nSamplesperPixel=2.0;
	   m_objDSODisplay->m_objXYView->setDSOChannelCount(l_nSamplesperPixel);
   }
   else if (l_bAverageMode==true && l_nSamplesperPixel >1)
   {
	   l_nSamplesperPixel=1.0;
	   m_objDSODisplay->m_objXYView->setDSOChannelCount(l_nSamplesperPixel);
   }
  // qDebug()<<"End Decimation";
}


void DSODisplayInterface::calculateAveragePoints(QList<double> plstPoints)
{
	m_nAveragePoint=0.0;
	for(int l_nMinMaxIndex=0;l_nMinMaxIndex<plstPoints.count();l_nMinMaxIndex++)
	{
		m_nAveragePoint +=plstPoints.value(l_nMinMaxIndex);
	}
	m_nAveragePoint= m_nAveragePoint / plstPoints.count();

}

void DSODisplayInterface::findMinMax(QList<double> plstPoints)
{
	//m_nMinPoint=m_nMaxPoint=0.0;
	m_nMinPoint = plstPoints.value(0);
	m_nMaxPoint= plstPoints.value(0);
	for(int l_nMinMaxIndex=0;l_nMinMaxIndex<plstPoints.count();l_nMinMaxIndex++)
	{
		if(m_nMinPoint > plstPoints.value(l_nMinMaxIndex) )
			m_nMinPoint = plstPoints.value(l_nMinMaxIndex);
		if(m_nMaxPoint< plstPoints.value(l_nMinMaxIndex))
			m_nMaxPoint=plstPoints.value(l_nMinMaxIndex);
	}
	//qDebug()<<"Min Point:"<<m_nMinPoint<<"Max Point:"<<m_nMaxPoint;
}

void DSODisplayInterface::LoadOddEvenData(double pVoltageTrigger,double pHorizontalTrigger,bool bODDData,bool bEvenData,DSO_CHANNEL pChannel,unsigned int pPostCount,unsigned int pPreCount )
{
	Q_UNUSED(bODDData);
	Q_UNUSED(bEvenData);
	Q_UNUSED(pChannel);
	//qDebug()<<"OddEven";
    //qDebug()<<"Load FIFO Data:"<<"Voltage Trigger:"<<pVoltageTrigger<<"Timebase Trigger:"<<pHorizontalTrigger;
    //qDebug()<<"Actual Record Length"<<m_nAcutalRecordLength<<"Sample Rate:"<<m_nSampleRate;
    //double l_nSamplingRate = (1.0/m_nAcutalRecordLength);
    PlotXYSettings *settings;

    //qDebug()<<"Voltage Per Divison:"<<m_nVoltPerDivision;
    if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
    {
    	//qDebug()<<"CH1:"<<m_nCH1VoltPerDivision;
    	settings = m_objDSODisplay->m_objXYModel->getPlotSettings(pChannel);
    	settings->setMaxTimeDivision(m_nAcquisitionTime);
		settings->setMaxVoltageDivision(m_nCH1VoltPerDivision);
		settings->setMinVoltageDivision(-m_nCH1VoltPerDivision);
//		m_objDSODisplay->m_objXYView->changePlotSettings(CHANNEL1,settings,m_nCH1VoltPerDivision);
		m_objDSODisplay->m_objXYView->setSpanData(settings->spanY(),CHANNEL1);
		m_objDSODisplay->m_objXYView->setPrePostCount(pPostCount,pPreCount,CHANNEL1);
    }
    else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
    {
    	//qDebug()<<"CH2:"<<m_nCH2VoltPerDivsion;
    	settings = m_objDSODisplay->m_objXYModel->getPlotSettings(pChannel);
    	settings->setMaxTimeDivision(m_nAcquisitionTime);
		settings->setMaxVoltageDivision(m_nCH2VoltPerDivsion);
		settings->setMinVoltageDivision(-m_nCH2VoltPerDivsion);
		m_objDSODisplay->m_objXYView->setSpanData(settings->spanY(),CHANNEL3);
		m_objDSODisplay->m_objXYView->setPrePostCount(pPostCount,pPreCount,CHANNEL3);

    }
	m_objChannel1Data.clear();
	m_objChannel2Data.clear();
	m_objChannel3Data.clear();
	m_objChannel4Data.clear();

    clearVectorData();
    bool isTriggerFound=false;

   int  l_nSamplesperPixel = (double)ceil((double)m_nSamplesCount/(double) m_objDSODisplay->m_objXYView->getRectWidth());
    if(l_nSamplesperPixel <= 1.0){
            l_nSamplesperPixel=1.0;
    }
    m_objDSODisplay->m_objXYView->setDSOChannelCount(l_nSamplesperPixel);

   // FILE *l_nOddFP,*l_nEvenFP;
  //  l_nOddFP = fopen("Odd.txt","w");
   // l_nEvenFP = fopen("Even.txt","w");
//		QFile l_objDataFile("R1FIFO.txt");
//		QFile l_objDataFileR2 ("R2FIFO.txt");
//       char data[10];
//       char data1[10];
//       qint64 l_nLineLength=0,l_nLineLengthR2=0;
//       QString l_strWaveData,l_strWaveDataR2;
//       double m_nXData=0.0;
//       unsigned short l_nCounter=0;
//       unsigned short l_nOdd=0,l_nEven=0;
//       if(l_objDataFile.open(QFile::ReadOnly) && l_objDataFileR2.open(QFile::ReadOnly))
//       {
//           while(l_nLineLength !=-1)
//           {
//               l_nLineLength = l_objDataFile.readLine(data,10);
//               l_strWaveData.append(data);l_strWaveData.remove("\n");l_strWaveData.remove("\r");
//               l_nLineLengthR2 = l_objDataFileR2.readLine(data1,10);
//               l_strWaveDataR2.append(data1);l_strWaveDataR2.remove("\n");l_strWaveDataR2.remove("\r");
//               if(l_nCounter == (m_nSamplesCount*2))
//                   break;
//               isTriggerFound=true;
//                if(isTriggerFound)
//                {
//                	if(l_nCounter%2==0)
//                	{
//						m_objCH1Data.insert(l_nEven,QPointF(m_nXData,convertFIFOData(l_strWaveData)));
//						m_objCH3Data.insert(l_nEven,QPointF(m_nXData,convertFIFOData(l_strWaveDataR2)));
//                		l_nEven++;
//                		//fprintf(l_nOddFP,"%X\n",l_strWaveData.toShort(&ok,16));
//                	}
//                	else{
//						m_objCH2Data.insert(l_nOdd,QPointF(m_nXData,convertFIFOData(l_strWaveData)));
//						m_objCH4Data.insert(l_nOdd,QPointF(m_nXData,convertFIFOData(l_strWaveDataR2)));
//                		l_nOdd++;
//                		//fprintf(l_nEvenFP,"%X\n",l_strWaveData.toShort(&ok,16));
//                	}
//                	l_nCounter++;
//                }
//               m_nXData = l_nCounter;//m_nXData + l_nSamplingRate;
//               l_strWaveData ="";l_strWaveDataR2="";
//
//           }
//       }
//    //   qDebug()<<"Count:"<<m_nAcutalRecordLength;
//       //qDebug()<<"Odd Counter:"<<l_nOdd++<<"Even Counter:"<<l_nEven;
//       l_objDataFile.close();
//       l_objDataFileR2.close();
//       convertToDecimation();
       //fclose(l_nEvenFP);fclose(l_nOddFP);

}

void DSODisplayInterface::LoadFIFOData(double pVoltageTrigger,double pHorizontalTrigger,bool bCH1,bool bCH2)
{
	Q_UNUSED(bCH1);
	Q_UNUSED(bCH2);
  //  qDebug()<<"Load FIFO Data1:"<<"Voltage Trigger:"<<pVoltageTrigger<<"Timebase Trigger:"<<pHorizontalTrigger;
  //  qDebug()<<"Actual Record Length"<<m_nAcutalRecordLength<<"Sample Rate:"<<m_nSampleRate;
    double l_nSamplingRate = (1.0/m_nSampleRate);
    PlotXYSettings *settings = m_objDSODisplay->m_objXYModel->getPlotSettings(CHANNEL1);
    settings->setMaxTimeDivision(m_nAcquisitionTime);
    settings->setMaxVoltageDivision(m_nCH1VoltPerDivision);
    settings->setMinVoltageDivision(-m_nCH1VoltPerDivision);
    m_objCH1Data.clear();
    m_objCH2Data.clear();
    clearVectorData();
    bool isTriggerFound=false;
    QFile *l_objDataFile = new QFile("R1FIFO.txt");
       char *data = new char[10];
       qint64 l_nLineLength=0;
       QString l_strWaveData;
       double m_nXData=0.0;
       unsigned short l_nCounter=0;
       if(l_objDataFile->open(QFile::ReadOnly))
       {
           while(l_nLineLength !=-1)
           {
               l_nLineLength = l_objDataFile->readLine(data,10);
               l_strWaveData.append(data);l_strWaveData.remove("\n");l_strWaveData.remove("\r");
               if(l_nCounter == (m_nAcutalRecordLength))
                   break;
               //qDebug()<<"Data:"<<convertFIFOData(l_strWaveData);
               if(pVoltageTrigger>=0 )
               {
                   if(( convertFIFOData(l_strWaveData) >= pVoltageTrigger) && isTriggerFound == false)
                   {
                       qDebug()<<"Positve Triggered.......................";
                       qDebug()<<"PXData:"<<m_nXData<<"PYData:"<<convertFIFOData(l_strWaveData);
                       qDebug()<<".........................................";
                       isTriggerFound = true;
                       m_nXData = pHorizontalTrigger;
                   }
               }
               else if(pVoltageTrigger<=0 )
               {
                   if(( convertFIFOData(l_strWaveData) <= pVoltageTrigger) && isTriggerFound == false)
                   //if( convertFIFOData(l_strWaveData) <= l_nVoltageTriggerPoint && isTriggerFound == false )
                   {
                       qDebug()<<"Negative Triggered.......................";
                       qDebug()<<"NXData:"<<m_nXData<<"NYData:"<<convertFIFOData(l_strWaveData);
                       qDebug()<<".........................................";
                       isTriggerFound = true;
                       m_nXData = pHorizontalTrigger;
                   }
               }
                if(isTriggerFound)
                {
                    m_objCH1Data.insert(l_nCounter++,QPointF(m_nXData,convertFIFOData(l_strWaveData)));
                }
               m_nXData = m_nXData + l_nSamplingRate;
               l_strWaveData ="";
           }
       }
       l_objDataFile->close();
       delete data;
}

double DSODisplayInterface::convertFIFOData(QString pStrData)
{
    bool ok = true;
    double l_nVref = 0.7;
    double l_nYPoint = ((2*(pStrData.toInt(&ok,16)*l_nVref))/ (pow(2,8)-1)) - l_nVref;
    //qDebug()<<"FS Settings:"<<m_nFSSettings<<"Voltage:"<<m_nVoltPerDivision;
    //l_nYPoint = l_nYPoint * (m_nVoltPerDivision * 8.0) / m_nFSSettings;
    return l_nYPoint;

}

void DSODisplayInterface::clearVectorData()
{
    m_objDSODisplay->m_objXYView->clearVectorData();
}


void DSODisplayInterface::setChannelVectData(QMap<int,QList<double> > pData,bool pOdd,bool pEven,DSO_CHANNEL pChannel)
{
//		if(pChannel == CHANNEL1)
//		{
//			m_objChannel1Data = pData;
//			m_objDSODisplay->m_objXYView->setChannelVectorData(m_objChannel1Data,pOdd,pEven,pChannel);
//		}
//		if(pChannel == CHANNEL2)
//		{
//			m_objChannel2Data=pData;
//			m_objDSODisplay->m_objXYView->setChannelVectorData(m_objChannel2Data,pOdd,pEven,pChannel);
//
//		}
//		if(pChannel == CHANNEL3)
//		{
//			m_objChannel3Data=pData;
//			m_objDSODisplay->m_objXYView->setChannelVectorData(m_objChannel3Data,pOdd,pEven,pChannel);
//		}
//		if(pChannel == CHANNEL4)
//		{
//			m_objChannel4Data=pData;
//			m_objDSODisplay->m_objXYView->setChannelVectorData(m_objChannel4Data,pOdd,pEven,pChannel);
//		}
//		m_objDSODisplay->m_objXYView->update();
}




void DSODisplayInterface::setCH1VectorData(QMap<int,QList<double> > pData)

{

	//m_objDSODisplay->m_objXYView->setVectorData(m_objCH1Data,true,false,false,false);
	//qDebug()<<"DSO Display Channel 1 Data:"<<pData.count();
	m_objChannel1Data = pData;
	m_objDSODisplay->m_objXYView->setChannelVectorData(m_objChannel1Data,true,false,CHANNEL1);
	m_objDSODisplay->m_objXYView->setSamplesCount(getSamplesCount(CHANNEL1),getSampleType());
    //m_objDSODisplay->m_objXYView->update();
}


void DSODisplayInterface::moveChannelOffset(DSO_CHANNEL pChannel,double pOffset=0.0)
{

		m_objDSODisplay->m_objXYView->moveChannelOffset(pChannel,pOffset);
		m_objDSODisplay->m_objXYView->update();
}

void DSODisplayInterface::setCH2VectorData(QMap<int,QList<double> > pData)
{
	//m_objDSODisplay->m_objXYView->setVectorData(m_objCH2Data,false,true,false,false);
	//()<<"DSO Display Channel 2 Data:"<<pData.count();
	m_objChannel2Data = pData;
	m_objDSODisplay->m_objXYView->setChannelVectorData(m_objChannel2Data,false,true,CHANNEL2);
	m_objDSODisplay->m_objXYView->setSamplesCount(getSamplesCount(CHANNEL1),getSampleType());

    //m_objDSODisplay->m_objXYView->update();
}

void DSODisplayInterface::setCH3VectorData(QMap<int,QList<double> > pData)
{
	//m_objDSODisplay->m_objXYView->setVectorData(m_objCH3Data,false,false,true,false);
	//qDebug()<<"DSO Display Channel 3 Data:"<<pData.count();
	m_objChannel3Data = pData;
	m_objDSODisplay->m_objXYView->setChannelVectorData(m_objChannel3Data,true,false,CHANNEL3);
	m_objDSODisplay->m_objXYView->setSamplesCount(getSamplesCount(CHANNEL3),getSampleType());
    //m_objDSODisplay->m_objXYView->update();
}

void DSODisplayInterface::setCH4VectorData(QMap<int,QList<double> > pData)
{
	//m_objDSODisplay->m_objXYView->setVectorData(m_objCH4Data,false,false,false,true);
	//qDebug()<<"DSO Display Channel 4 Data:"<<pData.count();
	m_objChannel4Data = pData;
	m_objDSODisplay->m_objXYView->setChannelVectorData(m_objChannel4Data,false,true,CHANNEL4);
	m_objDSODisplay->m_objXYView->setSamplesCount(getSamplesCount(CHANNEL3),getSampleType());
    //m_objDSODisplay->m_objXYView->update();
}

void DSODisplayInterface::setVectorData()
{
    m_objDSODisplay->m_objXYView->setVectorData(m_objCH1Data,true,false,false,false);
    m_objDSODisplay->m_objXYView->update();
}

DSODisplayInterface::DSODisplayInterface()
{
        initialiseWaveSettings();
        m_objDSODisplay=new DSODisplay;
}
DSODisplayInterface::~DSODisplayInterface(){
        delete m_objDSODisplay;
}
QWidget* DSODisplayInterface::getDisplayWidget(){
        return m_objDSODisplay;
}

void DSODisplayInterface::moveVertical1Cursors(double v1){
    m_objDSODisplay->m_objXYView->moveV1Cursor(v1);
}
void DSODisplayInterface::moveVertical2Cursor(double v2){
    m_objDSODisplay->m_objXYView->moveV2Cursor(v2);
}
void DSODisplayInterface::moveHorizontal1Cursors(double h1){
    m_objDSODisplay->m_objXYView->moveH1Cursor(h1);
}
void DSODisplayInterface::moveHorizontal2Cursors(double h2){
    m_objDSODisplay->m_objXYView->moveH2Cursor(h2);
}
void DSODisplayInterface::moveVerticalTriggerPointer(double val){
    m_objDSODisplay->m_objXYView->moveVerticalTriggerPointer(val);
}
void DSODisplayInterface::moveHorizontalTriggerPointer(double val){
    m_objDSODisplay->m_objXYView->moveHorizontalTriggerPointer(val);
}
void DSODisplayInterface::moveOffsetPointer(double offset){
    m_objDSODisplay->m_objXYView->moveOffsetPointer(offset);
}
void DSODisplayInterface::setBorderGeometry(int x,int y,int w,int h){
    m_objDSODisplay->m_objXYView->setBorderRect(x,y,w,h);
    m_objDSODisplay->m_objXYView->udpateGridView();
}
void DSODisplayInterface::hideVerticalCursors(short int pValue,bool hide){
    m_objDSODisplay->m_objXYView->HideVerticalCursros(pValue,hide);
    //m_objDSODisplay->m_objXYView->update();
}
void DSODisplayInterface::hideHorizontalCursors(short int pValue,bool hide){
    m_objDSODisplay->m_objXYView->HideHorizontalCursors(pValue,hide);
    //m_objDSODisplay->m_objXYView->update();
}
void DSODisplayInterface::HideDSOChannel(DSO_CHANNEL pChannel,bool pHideFlag)
{
	//qDebug()<<"HideDSOChannel";
	m_objDSODisplay->m_objXYView->HideChannelData(pChannel,pHideFlag);
	m_objDSODisplay->m_objXYView->update();
}
Q_EXPORT_PLUGIN2(DisplayWidgetInterface,DSODisplayInterface);
