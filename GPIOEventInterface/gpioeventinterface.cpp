#include "gpioeventinterface.h"
#if 1
#define qLog(x) qDebug()
#else
#define qLog(x) while (0) qDebug()
#endif

#define DEV_NAME  "gpioevent"
#define DEV_NAME1  "gpioshutdown"
#define DEV_MOUSE   "Logitech Optical USB Mouse"



void  GpioEventInterface::InvokeGPIOEvent(QWidget *parent,QString driver, QString device,int *pKeyCode){
    //qDebug()<<"GPIO event invoked";
    g_objGPIOevent = new GPIOEvent(parent,pKeyCode);
    g_objGPIOevent->create(driver,device);
}
void GpioEventInterface::setApplicationID(APPID pAPPID)
{
	g_objGPIOevent->setAPPID(pAPPID);
}


void GpioEventInterface::driveDSO(bool iSNormal = false)
{
	g_objGPIOevent->driveDSO(iSNormal);
}
void GpioEventInterface::setStopFlag(bool pFlag)
{
	g_objGPIOevent->setStopEvent(pFlag);
}

void GpioEventInterface::setProbeFlag(short int pProbeFlag)
{
	g_objGPIOevent->setProbeFlag(pProbeFlag);
}

void GpioEventInterface::closefd(){
        g_objGPIOevent->callclosefd();
}
bool GpioEventInterface::BlockSig(bool get){
        if(get==true){
            g_objGPIOevent->blockSignals(true);
           // //qDebug()<<"Signal Blocked";
        }
        else if(get==false){
       g_objGPIOevent->blockSignals(false);
      // qDebug()<<"Signal UnBlocked";
        }
        return true;
}

void GpioEventInterface::setFSSettings(double pVoltage,double pFSSettings,int pSamples,int pRectWidth,int pReceFIFO)
{
	g_objGPIOevent->setFSSettings(pVoltage,pFSSettings,pSamples,pRectWidth,pReceFIFO);
}

void GpioEventInterface::setFIFOMode(int pReceFIFO)
{
	g_objGPIOevent->setFIFOMode(pReceFIFO);
}

void GpioEventInterface::setSamplingType(SAMPLING_TYPE pType)
{
	g_objGPIOevent->setSamplingType(pType);
}

Q_EXPORT_PLUGIN2(GpioEventInterface, GpioEventInterface)

GPIOEvent::GPIOEvent(QWidget *parent,int *pKeyCode):QWidget(parent){
    //qDebug()<<"----------------------------GPIO LIBRARY STARTS----------------------------";

        m_TW = parent;
        m_nKey = pKeyCode;
    //Backpanel Interface Plugin
    QPluginLoader loader2("libBackPlaneInterface.so",this);
    IBackPlane = qobject_cast<IntefaceBackPlane*>(loader2.instance());
    IBackPlane->InitializeBpObject();
    QPluginLoader loader1("libPTApplicationcardInterface.so");
    IAppCard = qobject_cast<IApplicationCardInterface*>(loader1.instance());
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();
    m_nInterruptValue = IAppCard->readScratchPad();
	QPluginLoader loaderSPIMemory("libSPIMemoryInterface.so");
	ISPIMemory = qobject_cast<ISPIMemoryInterface*> (loaderSPIMemory.instance());
	IAppCard->setSPIAppendBit(0xC000);
    QPluginLoader loader3("libPTPsocInterface2.so");
    IPsoc = qobject_cast<IPSOCCOMMUNICATION*>(loader3.instance());
    IPsoc->openSerial();
	m_nReceiveData = new unsigned short int[300];
	m_stopFlag = false;
	m_strReceiveName =".\ActualData.bin";
	//m_objEvent = new QEvent(APPCARDDRIVEEVENT);
}

GPIOEvent::~GPIOEvent(){
        IBackPlane->closeObject();
        //qDebug()<<"----------------------------GPIO LIBRARY ENDS----------------------------";
}

void GPIOEvent::setAPPID(APPID pAPPID)
{
	m_eAPPID = pAPPID;
}
void GPIOEvent::create(QString driver, QString device)
{
    QMessageBox msgbox;
    qLog(Input) << "Loaded GPIOEvent plugin!";
    qLog(Input) << driver;
    qLog(Input) << device;
    char *device1 = new char[50];
    char *mousedevice = new char[50];
    char name[50] = "Unknown";
    setObjectName( "GPIOEVENT Handler" );



    for(int l_nDeviceIndex=0;l_nDeviceIndex < 32; l_nDeviceIndex++){
            strcpy(device1,"/dev/input/event");
            char str[2];
            sprintf(str,"%d", l_nDeviceIndex);
            strcat(device1,str);
            printf("Inside GPIOEVENT %s\n",device1);
            if((kbdFD = ::open(device1,O_RDONLY)) == -1){
                 printf ("%s is not a vaild device.\n", device1);
            }
            // Get Device Name
            ioctl (kbdFD, EVIOCGNAME (sizeof (name)), name);
            printf("GPIO Event Name :%s\n",name);
            if(strcmp(name,DEV_NAME) == 0)
            {

                ::close(kbdFD);
                break;
            }
/*            if(strcmp(name,DEV_NAME1) == 0)
            {

                ::close(kbdFD);
                break;
            }*/
            if(strcmp(name,DEV_MOUSE) == 0)
            {
            	mouseFD = kbdFD;
                ::close(kbdFD);
                strcpy(mousedevice,device1);
                //break;
            }

        }


    //kbdFD = ::open(driver.toLocal8Bit().constData(), O_RDONLY);
    kbdFD = ::open(device1, O_RDONLY);
    if (kbdFD >= 0) {
        qLog(Input) << "Opened" << device1 << "as GPIO input";
        m_notify = new QSocketNotifier( kbdFD, QSocketNotifier::Read, this );
        ioctl (kbdFD, EVIOCGNAME (sizeof (name)), name);
        printf("Event Name:\n",name);
        if(strcmp(name,DEV_NAME) == 0)
                connect( m_notify, SIGNAL(activated(int)), this, SLOT(readKbdData()));
/*        else if(strcmp(name,DEV_NAME1) == 0)
                connect( m_notify, SIGNAL(activated(int)), this, SLOT(readKbdData()));*/
    } else {
        qWarning("Cannot open '%s' for keypad (%s)",device.toLocal8Bit().constData(), strerror(errno));
        return;
    }

    mouseFD = ::open(mousedevice, O_RDONLY);
    if (mouseFD >= 0) {
        qLog(Input) << "Opened" << mousedevice << "as Mouse input";
        m_notify = new QSocketNotifier( mouseFD, QSocketNotifier::Read, this );
        ioctl (mouseFD, EVIOCGNAME (sizeof (name)), name);
        if(strcmp(name,DEV_MOUSE) == 0)
            connect( m_notify, SIGNAL(activated(int)), this, SLOT(readMouseData()));
/*        else if(strcmp(name,DEV_NAME1) == 0)
                connect( m_notify, SIGNAL(activated(int)), this, SLOT(readKbdData()));*/
    } else {
        qWarning("Cannot open '%s' for mouse (%s)",device.toLocal8Bit().constData(), strerror(errno));
        return;
    }


    shift = false;
}
void GPIOEvent::startKnobDrive()
{

    //qDebug()<<"Starting knob drive.....";
    IBackPlane->writeOtpLsb(0x00);
    IBackPlane->setTimer(0xf9);
    IBackPlane->setKnobCommandRegsiter(0x03);
}
int GPIOEvent::callclosefd()
{
        int cl;
        cl=::close(kbdFD);
        return cl;
}

void GPIOEvent::readMouseData()
{
	struct input_event *ie;
	struct input_event iebuf[32];
    uint n = ::read(mouseFD, iebuf, sizeof(iebuf));
    n /= sizeof(struct input_event);
    ie = iebuf;
    bool pressed;
    bool autorepeat;

    for (uint i = 0; i < 1; i++) {

        pressed = ie->value != 0;
        autorepeat = ie->value == 2;
        *m_nKey = ie->code;
        //qDebug()<<"GPIOEventInterfcae - mouse:"<<ie->code<<"type:"<<ie->type<<"value:"<<ie->value<<*m_nKey;
        QApplication::postEvent(m_TW,new QEvent(MouseEvent));
    }
}

void GPIOEvent::readKbdData()
{
    struct input_event *ie;
    struct input_event iebuf[32];
    m_strReceiveName = "./ActualData.bin";
    uint n = ::read(kbdFD, iebuf, sizeof(iebuf));
    bool probeSwitch=false;
    bool pressed;
    bool autorepeat;

    n /= sizeof(struct input_event);
    ie = iebuf;
    for (uint i = 0; i < 1; i++) {

        pressed = ie->value != 0;
        autorepeat = ie->value == 2;
        *m_nKey = ie->code;
       qDebug()<<"GPIOEventInterfcae - code:"<<ie->code<<"type:"<<ie->type<<"value:"<<ie->value<<*m_nKey;


        l_nRegisterValue=IBackPlane->readBackPlaneRegister(0x001E);
       qDebug()<<"GPIO Event Interface (0x1E) Status:"<<hex<<l_nRegisterValue;


        if(ie->type==0x9)
        	QApplication::postEvent(m_TW,new QEvent(ShutDownEvent));

        if(l_nRegisterValue==0x900){
                //qDebug()<<"Probe&Knob";
                QApplication::postEvent(m_TW,new QEvent(GpioEvent));
                QApplication::postEvent(m_TW,new QEvent(KnobEvent));
        }
        else if(l_nRegisterValue==0x800){
                QApplication::postEvent(m_TW,new QEvent(KnobEvent));
        }
       // qDebug()<<"Inside Interrupt Handle.";
        unsigned int l_nIntPadValue = 0x00100 | m_nInterruptValue;
       // qDebug()<<"Interrupt Value Outside:"<<hex<<l_nIntPadValue;
        if(m_eAPPID == DSO)
        {
        	if(IBackPlane->readBackPlaneRegister(0x20) == 0x80)
        	{
            //	qDebug()<<"Interrupt Value Inside:"<<hex<<IBackPlane->readBackPlaneRegister(0x20);
        		IBackPlane->writeBackPlaneRegister(0x80,0x1E);
        		IBackPlane->writeBackPlaneRegister(0x0,0x20);
//        		IAppCard->readAppCardCodeId();
//        		IAppCard->readAppCardCodeId();
//        		IAppCard->readAppCardCodeId();
        		//qDebug()<<"Window ID:"<<m_TW;
//            	QApplication::postEvent(m_TW,new QEvent(APPCARDDRIVEEVENT),Qt::NormalEventPriority);
        		readFIFORegister();
        		//driveDSO(false);
            	emit postAPP(m_lstOddPoints,m_lstEvenPoints);
            	//IAppCard->readAppCardCodeId();

            //	qDebug()<<"Interrupt Posted";
        	}
        	//return;
        }
        else if((l_nRegisterValue&0x100)==0x100)
        {
        	IBackPlane->writeBackPlaneRegister(0x100,0x1E);//clear PSoc
        	IBackPlane->writeBackPlaneRegister(0x0,0x20); // clear PSoc Int source
            QApplication::postEvent(m_TW,new QEvent(GpioEvent),Qt::NormalEventPriority);
			usleep(10000);
            IBackPlane->writeBackPlaneRegister(l_nIntPadValue,0x20);// Enable Psoc
            //break;
        }
        else if((l_nRegisterValue&m_nInterruptValue) == m_nInterruptValue)
        {

        	IBackPlane->writeBackPlaneRegister(m_nInterruptValue,0x1E);
        	IBackPlane->writeBackPlaneRegister(0x0,0x20);
        	//if(m_nProbeValue!=-1)
        	performReceive(m_strReceiveName);
        	QApplication::postEvent(m_TW,new QEvent(APPCARDDRIVEEVENT),Qt::NormalEventPriority);
        	if(m_stopFlag == true){
        		IAppCard->stopDrive();
        		IBackPlane->writeBackPlaneRegister(l_nIntPadValue,0x20);
        	}
        	else{

        		if(m_nProbeValue==1)
        		{
        			//m_strReceiveName = "Probe2.bin";
        			IPsoc->viTrace(2);
        		//	IPsoc->onTopRelay(0x24);
        			usleep(10000);
        		}
        		else if(m_nProbeValue==2)
        		{
        			IPsoc->viTrace(1);
        			//->onTopRelay(0x24);
        			usleep(10000);
        			//m_strReceiveName = "Probe1.bin";
        		}

        		//qDebug()<<"Before Drive:"<<hex<<l_nRegisterValue<<m_stopFlag;
        		IBackPlane->writeBackPlaneRegister(l_nIntPadValue,0x20);
            	IAppCard->writeRegister(0x3,0x86);
            	IAppCard->startDrive(1);
            	//break;
        	}
        }
        else
        {
       		qDebug()<<"No Services";
        }
        ie++;
    }
}
void GPIOEvent::setForceTrigger(bool pTrigger)
{
	//Q_UNUSED(pTrigger)
	IAppCard->setDSOTrigger(1);
	if(pTrigger== true)
		IAppCard->checkDSODriveDone();

}

void GPIOEvent::driveDSO(bool isNormal = false)
{
	IAppCard->setDSOReceiveFIFOMode(true,true);
	usleep(1000);
	IAppCard->setDSOReceiveFIFOConfiguration(R1FIFO,false,false,true);
	IAppCard->setDSOReceiveFIFOConfiguration(R2FIFO,false,false,true);
	IAppCard->setDSOCR(true);
	if(isNormal == false){
		usleep(5000);
		while(!(IAppCard->readRegister(PT_APPCARD_MODULES::PT_DSO_CR)&0x04)==0x04);
		//usleep(20000);
		setForceTrigger(false);
	}

	enableInterrupt();
}

void GPIOEvent::setProbeFlag(short int pProbeFlag)
{
	m_nProbeValue = pProbeFlag;
}

void GPIOEvent::enableInterrupt()
	{
		unsigned int l_nIntPadValue = 0x0080;
		l_nIntPadValue = 0x0000 | l_nIntPadValue;
		//qDebug()<<"Enable Interrupt Value:"<<hex<<l_nIntPadValue;
		IBackPlane->writeBackPlaneRegister(l_nIntPadValue, 0x0020);//enabling psoc INT0 embedded key interrupt / App Card SLOT 0 Interrupt
		IBackPlane->writeBackPlaneRegister(0x80, 0x001E);//clear all interrupts
		IBackPlane->writeBackPlaneRegister(0x1, 0x0024); //enabling global interrupt
	}


void GPIOEvent::setStopEvent(bool pFlag)
{
	m_stopFlag = pFlag;
}
void GPIOEvent::performReceive(QString pStrFileName)
{
	ISPIMemory->accessSPIRAM(RECEIVERAM);
	IAppCard->writeRegister(0x0,0x86);
	ISPIMemory->readAppCardSRAM(0,300,false);
	//writeReceiveRAM();
	QString l_strOldName = "./RWaveData.txt";
	QFile l_objFile;
	if (l_objFile.exists(pStrFileName))
		l_objFile.remove(pStrFileName);
	l_objFile.rename(l_strOldName,pStrFileName );
	l_objFile.close();

}
void GPIOEvent::writeReceiveRAM()
{
	  FILE *l_nFD;

	  unsigned int l_nFileData=0;
	  //printf("receiveFIFO\n");
	  l_nFD = fopen("./DFIFOReceive.txt","w");
	  if(l_nFD == 0)
		  printf("File I/O error\n");
	  unsigned int l_nIndex=0;
	  while(l_nIndex < 300)
	  {
		  l_nFileData = m_nReceiveData[l_nIndex]&0x3FFF;
		  fprintf(l_nFD,"%X\n",l_nFileData);
		  l_nIndex++;
	  }
	  fclose(l_nFD);
}


void GPIOEvent::readFIFORegister()
{
   unsigned int l_nTC=0;
   double l_nSamplesperPixel=0.0;
   l_nSamplesperPixel = (double)floor((double)m_nSamples/(double)m_nRectWidth);
   if(l_nSamplesperPixel <= 1.0){
	   	   l_nTC = m_nSamples;
           l_nSamplesperPixel=1.0;
   }
   else
   {
           l_nTC = m_nRectWidth*2;
   }
//   qDebug()<<"GPIO samples Per Pixel:"<<l_nSamplesperPixel<<m_nSamples<<m_eSamplesType;
	IAppCard->setDSOReceiveFIFOMode(false,false);
	m_lstOddPoints.clear();m_lstEvenPoints.clear();
	bool isMax=false;
	unsigned char l_nOddSample=0,l_nEvenSample=0;
	unsigned char l_nCh2EvenSample=0;
	unsigned short int l_nGCounter=0;
	QList<unsigned char> l_lstSamplePoints1,l_lstSamplePoints2;
	int l_nIndex=0;
   for(unsigned short int l_nAddrIndex=0;l_nAddrIndex<m_nRectWidth;l_nAddrIndex++)
   {
	   l_nIndex=0;
	   l_lstSamplePoints1.clear();l_lstSamplePoints2.clear();
	   for(int l_nFileCount=0;l_nFileCount<l_nSamplesperPixel;l_nFileCount++)
	   {
		   //if(m_eReceFIFO == 0)
		   //{
			 //  l_nOddSample= ~(IAppCard->getDSOReceiveFIFOODD_RD(R1FIFO))&0x0FF;
			   l_nEvenSample = ~(IAppCard->getDSOReceiveFIFOEVEN_RD(R1FIFO))&0x0FF;
			   l_nCh2EvenSample = ~(IAppCard->getDSOReceiveFIFOEVEN_RD(R2FIFO))&0x0FF;
		   //}
		//   else
		  // {
			 //  l_nOddSample= ~(IAppCard->getDSOReceiveFIFOODD_RD(R2FIFO))&0x0FF;
			 //  l_nEvenSample = ~(IAppCard->getDSOReceiveFIFOEVEN_RD(R2FIFO))&0x0FF;
		//   }
		   if(m_eSamplesType == NORMAL && l_nFileCount <1)
		   {
			   m_lstOddPoints.insert(l_nGCounter,l_nEvenSample);
			   m_lstEvenPoints.insert(l_nGCounter,l_nCh2EvenSample);
			   l_nGCounter++;
		   }
		   else if(m_eSamplesType == MIN_MAX || m_eSamplesType == AVERAGE)
		   {
			   l_lstSamplePoints1.insert(l_nIndex,l_nEvenSample);
			   l_lstSamplePoints2.insert(l_nIndex,l_nCh2EvenSample);
			   l_nIndex++;
		   }

		   else if(m_eSamplesType !=NORMAL && m_eSamplesType !=MIN_MAX && m_eSamplesType !=AVERAGE)
		   {
			   m_lstOddPoints.insert(l_nGCounter,l_nEvenSample);
			   m_lstEvenPoints.insert(l_nGCounter,l_nCh2EvenSample);
			   l_nGCounter++;
		   }
	   }
	   if(m_eSamplesType == MIN_MAX)
	   {
		   if(isMax == false)
		   {
			   m_lstOddPoints.insert(l_nGCounter,findMinPoint(l_lstSamplePoints1));
			   m_lstEvenPoints.insert(l_nGCounter,findMinPoint(l_lstSamplePoints2));
			   isMax = true;
		   }
		   else if(isMax == true)
		   {
			   m_lstOddPoints.insert(l_nGCounter,findMaxPoint(l_lstSamplePoints1));
			   m_lstEvenPoints.insert(l_nGCounter,findMaxPoint(l_lstSamplePoints2));
			   isMax = false;
		   }
		   l_nGCounter++;
	   }
	   if(m_eSamplesType == AVERAGE)
	   {

		   m_lstOddPoints.insert(l_nGCounter,calculateAveragePoints(l_lstSamplePoints1));
		   m_lstEvenPoints.insert(l_nGCounter,calculateAveragePoints(l_lstSamplePoints2));
		   l_nGCounter++;
	   }
   }
   if(m_eSamplesType == MOVING_AVERAGE){
	   m_lstOddPoints = calcuateMovingAverage(m_lstOddPoints);
	   m_lstEvenPoints = calcuateMovingAverage(m_lstEvenPoints);
   }
  // qDebug()<<"FIFO Read end.";
}


QList<unsigned char> GPIOEvent::calcuateMovingAverage(QList<unsigned char> plstPoints)
{
	//qDebug()<<"Inside Moving Average.";
	unsigned short l_nWindowSize = 5,l_nAverageCounter=0;
	unsigned short l_nSum=0;
	QList<unsigned char> l_objMovingAverage;
	l_objMovingAverage.clear();
	for(unsigned short l_nWaveCounter=0;l_nWaveCounter<(plstPoints.count());l_nWaveCounter++)
	{
		l_nSum=0.0;
		for(unsigned short l_nIndex=l_nWaveCounter;l_nIndex<l_nWaveCounter+l_nWindowSize;l_nIndex++)
		{
			l_nSum +=plstPoints.value(l_nIndex);
		}
		l_objMovingAverage.insert(l_nAverageCounter++,(l_nSum/(unsigned short)l_nWindowSize));
	}
	return l_objMovingAverage;
}



unsigned char GPIOEvent::calculateAveragePoints(QList<unsigned char> plstPoints)
{
	unsigned short l_nAveragePoint=0;

	for(int l_nMinMaxIndex=0;l_nMinMaxIndex<plstPoints.count();l_nMinMaxIndex++)
	{
		//qDebug()<<"Value:"<<plstPoints.value(l_nMinMaxIndex);
		l_nAveragePoint +=plstPoints.value(l_nMinMaxIndex);
	}
	l_nAveragePoint= l_nAveragePoint / plstPoints.count();
	//qDebug()<<"Aver:"<<l_nAveragePoint;
	return (unsigned char)l_nAveragePoint;

}

unsigned char GPIOEvent::findMinPoint(QList<unsigned char> plstPoints)
{
	unsigned char l_nMinpoint = plstPoints.value(0);
	for(int l_nIndex=0;l_nIndex<plstPoints.count();l_nIndex++)
	{
		if(l_nMinpoint > plstPoints.value(l_nIndex) )
			l_nMinpoint = plstPoints.value(l_nIndex);

	}
	return l_nMinpoint;
}


unsigned char GPIOEvent::findMaxPoint(QList<unsigned char> plstPoints)
{
	unsigned char l_nMaxpoint = plstPoints.value(0);
	for(int l_nIndex=0;l_nIndex<plstPoints.count();l_nIndex++)
	{
		if(l_nMaxpoint < plstPoints.value(l_nIndex) )
			l_nMaxpoint = plstPoints.value(l_nIndex);

	}
	return l_nMaxpoint;
}

