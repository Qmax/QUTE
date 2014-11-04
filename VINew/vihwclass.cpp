#include "vihwclass.h"

VIHWClass::VIHWClass()
{
    m_nDriveCount=0;
    m_nReceiveData = new unsigned short int[300];
}



void VIHWClass::initializeHWLibraries()
{
    //ApplicationInterfacePlugin
    QPluginLoader loader1("libPTApplicationcardInterface.so");
    IAppCard = qobject_cast<IApplicationCardInterface*>(loader1.instance());
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();
    qDebug() << "APPCard Code ID:" <<IAppCard->readAppCardCodeId();

    m_nInterruptValue = IAppCard->readScratchPad();
    qDebug()<<"Scratch:"<<m_nInterruptValue;
        //BackPanel Interface Plugin
    QPluginLoader loader2("libBackPlaneInterface.so");
    IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
    IBackPlane->InitializeBpObject();
    qDebug() << "BACKPlane Code ID:" <<IBackPlane->readBackPlaneCodeID();
	IBackPlane->writeBackPlaneRegister(0x01, 0x48);
        //PSOC Interface Plugin
    QPluginLoader loader3("libPTPsocInterface2.so");
    IPsoc = qobject_cast<IPSOCCOMMUNICATION*>(loader3.instance());
    IPsoc->openSerial();
	QPluginLoader loaderSPIMemory("libSPIMemoryInterface.so");
	ISPIMemory = qobject_cast<ISPIMemoryInterface*> (loaderSPIMemory.instance());
	ISPIMemory->setHardwarwObject(IAppCard);
	ISPIMemory->accessSPIMemory(BACKPLANE);
	m_objAD5318Component = new AD5318Components(IAppCard);
	m_objAD5293Component = new AD5293(IAppCard);
	resetDAC();
	//IPsoc->closeSerial();
	//IPsoc->changeBaudRate(1);

	//IPsoc->writeSerial(0x50);
	//IPsoc->writeSerial(0x01);
	peformDriveConfiguration();

        //Added by RRV,DI 16/10/2014~~~~Making the phaseshift zero by init~~
        double m_nPTWPhase=(((pow(2,32))-1)*0)/360;
        unsigned short m_nPTW_LSW=((unsigned int)m_nPTWPhase<<16)>>16;
        unsigned short m_nPTW_MSW=(unsigned int)m_nPTWPhase>>16;
        IAppCard->setDDSPTW_LSW(m_nPTW_LSW);
        IAppCard->setDDSPTW_MSW(m_nPTW_MSW);
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}

void VIHWClass::resetDAC()
{
	IAppCard->setSPIAppendBit(0xC000);
	m_objAD5318Component->resetDAC5318(true);
	m_eSelect = DACF;
	m_objAD5318Component->configureADC5318CW();
	updateDAC(0.0);
	m_eSelect = DACG;
	m_objAD5318Component->configureADC5318CW();
	updateDAC(0.0);
}

void VIHWClass::updateDAC(double pVolt)
{
	 AD5318_dataTemplate l_nAD5318DW;
	    l_nAD5318DW.m_eDACSelect = m_eSelect;
	    l_nAD5318DW.m_bCtrlBit = 0;
	    l_nAD5318DW.m_nVout = pVolt;
	    l_nAD5318DW.m_nVRef = 2.5;
	    l_nAD5318DW.m_bUniPolor = true;
	    if(m_eSelect == DACE || m_eSelect ==DACH)
	    	l_nAD5318DW.m_nVRef = 5.0;
	    if(m_eSelect == DACF || m_eSelect == DACG)
	    	l_nAD5318DW.m_bUniPolor = false;
	    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);
}


void VIHWClass::switchPROBE(PROBESELECTION m_eSelection)
{

    if(m_eSelection == PROBE1)
    {
    	qDebug()<<"Switch probe1";
         IPsoc->viTrace(1);
    }
    else if(m_eSelection == PROBE2)
    {
    	qDebug()<<"Switch probe2";
        IPsoc->viTrace(2);
    }
    else if(m_eSelection == EXT_PROBE)
    {
    	qDebug()<<"Switch External probe";
//    	IPsoc->resetRelays();
//    	IPsoc->writeSerial(0x42);
//    	IPsoc->writeSerial(0x09);
        IPsoc->viTrace(1);
    }
    else if(m_eSelection == EXT_FLY){
        qDebug()<<"EXT-FLY Channel probe";
        IPsoc->switchFly();
    }
}

unsigned short VIHWClass::checkProbeStatus()
{
    // this checks if probes are not connected.
    unsigned short l_nPrStatus = IPsoc->embeddedProbeStatus();
    qDebug()<< "VIHWClass::Probe Status:"<<hex<<l_nPrStatus;
    return l_nPrStatus;
    /*if( (l_nPrStatus & 0x01) == 0x01)
    {
        return PROBE1;
    }
    else if((l_nPrStatus & 0x10) == 0x10)
    {
        return PROBE2;
    }
    else if((l_nPrStatus & 0x11) == 0x11)
    {
        return DUALPROBE;
    }
    else
    	return NOPROBE;*/
}

void VIHWClass::readTestandRefChannel()
{
//	QByteArray l_narr = IPsoc->readSerByte();
//	qDebug()<<"Values:"<<l_narr;

}

bool VIHWClass::readMUXStatus()
{
	return IPsoc->readMuxStatus();
}

unsigned int VIHWClass::readPSOCID()
{
	return IPsoc->readPsocCodeID();
}

unsigned int VIHWClass::switchTestMuxChannel(short int pTestPinChannel)
{
	return IPsoc->switchTest(pTestPinChannel);
}

unsigned int VIHWClass::switchRefMuxChannel(short int pRefPinChannel)
{
	return IPsoc->switchRef(pRefPinChannel);
}

void VIHWClass::switchExternalMux(short int pTestPinChannel,short int pRefPinChannel)
{
	IPsoc->externalMuxMeasurement(pTestPinChannel,pRefPinChannel);
}

void VIHWClass::setDriveCount(unsigned short pSamples,unsigned short pPrePostCount)
{
    /*/
     * 200 count Sampled Drive
     */

    short int l_nExtraDriveSamp1e = 100;
    m_nDriveCount = ((pSamples+ l_nExtraDriveSamp1e) + pPrePostCount) - 1;
}

void VIHWClass::setPSOCDelay()
{
	// Switching Delay
//	IPsoc->writeSerial(0xDF);
//	usleep(1000);
//	IPsoc->writeSerial(0x00);
//	usleep(1000);
//	IPsoc->writeSerial(0x00);
//	usleep(1000);
	// External Mux Delay
	IPsoc->writeSerial(0xDE);
	usleep(1000);
	IPsoc->writeSerial(0x00);
	usleep(1000);
	IPsoc->writeSerial(0x32);
	usleep(1000);
	/*IPsoc->writeSerial(0xDD);
	usleep(1000);
	if(!IPsoc->getAck())
	{
		qDebug()<<"Psoc Communicatin Failure";
	}

	unsigned short l_nMSW = IPsoc->readSerial();
	unsigned short l_nLSW = IPsoc->readSerial();*/

	//qDebug()<<"MSW:"<<l_nMSW<<"LSW:"<<l_nLSW;

}

unsigned int VIHWClass::getDriveCount()
{
    return m_nDriveCount;
}

void VIHWClass::driveRAM(unsigned short int *pData)
{
	//qDebug() << "Drive Ram Loaded" << m_nDriveCount;
	ISPIMemory->accessSPIRAM(DRIVERAM);
	IAppCard->writeRegister(0x0,0x86);

	//ISPIMemory->setAutoIncrement();
	ISPIMemory->writeAppCardSRAM(0,m_nDriveCount,&pData[0]);
	usleep(1000);

	IAppCard->setDDSWaveSelect(RAM_DATA);
	IAppCard->setDriveRAMStarAddress(0);
	IAppCard->setDriveRAMEndAddress(m_nDriveCount);
	/*RAMACCESS pRAMSelect;
	pRAMSelect.m_bDRAMMODE=true;
	pRAMSelect.m_bRRAM1MODE=true;
	IAppCard->setRAMModeAccess(pRAMSelect);*/

    /*IAppCard->registerSelect(0);
    IAppCard->resetDriveFIFO();
    IAppCard->driveFIFO(getDriveCount() + 1, 0);*/

}

void VIHWClass::driveDDS()
{

	unsigned int l_nRegisterAddress = 0x94, l_nRegisterData = 0x01;
	IAppCard->writeRegister(l_nRegisterData,l_nRegisterAddress); // Register ADDed 30.07.2013
	IAppCard->setDDSWaveSelect(DDS);
	//IAppCard->writeRegister(0x3,0x74);// testing of Assymetric
	//IAppCard->writeRegister(0x5,0x72);

	IAppCard->setDrivePatternCount(false,0);
	IAppCard->setDrivePeriod(m_nDriveCount);
	IAppCard->writeRegister(0x201,0x68);
}



void VIHWClass::calculateDDSFrequency(unsigned int pFreq)
{
	double l_nFrequenceArray[13] = {10.0,20.0,50.0,100.0,200.0,500.0,1000.0,2000.0,5000.0,10000.0,20000.0,50000.0,100000.0};
	double l_nFTWOutputFrequency, l_nOutputTime;
	l_nFTWOutputFrequency = (l_nFrequenceArray[pFreq] / 50000000);
	l_nFTWOutputFrequency = l_nFTWOutputFrequency * pow(2, 32);
	l_nOutputTime = 1 / l_nFTWOutputFrequency;
	//qDebug() << "FTW Output Frequency:" << l_nFTWOutputFrequency;
	//qDebug() << "FTW Output Time:" << l_nOutputTime;
	unsigned int l_nFTW_LSW = ((unsigned int) l_nFTWOutputFrequency << 16) >> 16;
	unsigned int l_nFTW_MSW = (unsigned int) l_nFTWOutputFrequency >> 16;
	//qDebug() << "FTW_LSW" << hex << l_nFTW_LSW;
	//qDebug() << "FTW_MSW" << hex << l_nFTW_MSW;
	IAppCard->setDDSFTW_LSW(l_nFTW_LSW);
	IAppCard->setDDSFTW_MSW(l_nFTW_MSW);
}

void VIHWClass::performReceive()
{
	ISPIMemory->accessSPIRAM(RECEIVERAM);
	//qDebug()<<"Receive Mode";
	usleep(1000);
	IAppCard->writeRegister(0x0,0x86);
	ISPIMemory->readAppCardSRAM(0,m_nDriveCount);
	//writeReceiveRAM();
    /*IAppCard->registerSelect(0x0);
    IAppCard->receiveFIFO(getDriveCount() + 1, 0);*/
}

void VIHWClass::writeReceiveRAM()
{
	  FILE *l_nFD;
	  unsigned int l_nFileData=0;
	  //printf("receiveFIFO\n");
	  l_nFD = fopen("./DFIFOReceive.txt","w");
	  if(l_nFD == 0)
		  printf("File I/O error\n");
	  unsigned int l_nIndex=0;
	  while(l_nIndex < m_nDriveCount)
	  {
		  l_nFileData = m_nReceiveData[l_nIndex]&0x3FFF;
		  fprintf(l_nFD,"%X\n",l_nFileData);
		  l_nIndex++;
	  }
	  fclose(l_nFD);
}

void VIHWClass::checkforDriveDoneBit()
{
	while(!(IAppCard->readRegister(0x12)& 0x0001));

}

void VIHWClass::changePSOCBaudRate(unsigned int pBaudRate)
{
	IPsoc->changeBaudRate(pBaudRate);
}

void VIHWClass::performDrive( )
{
	IAppCard->writeRegister(0x3,0x86);
	//IAppCard->setDrivePatternCount(false,0);
	IAppCard->startDrive(1);
	usleep(20000);
	while(!(IAppCard->readRegister(0x12)& 0x0001));
//    qDebug() << "Drive Relay Register Value:"<<hex<<IAppCard->getDriveSourceAmplitudeRegister();
//    qDebug()<<  "Receive Source Select:"<<hex<<IAppCard->getDriveReceiveSourceSelect();
//    qDebug() << "Receive Relay1 Register Value:"<<hex<<IAppCard->getReceiversConfiguration(RECEIVER1);

	//while(IAppCard->readRegister(PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DCR)) & 0x0001);
	//usleep(10000);
//	IAppCard->setDrivePatternCount(false,1);
//	IAppCard->startDrive(1);
    /*IAppCard->registerSelect(0x07);
    IAppCard->startDrive(1);
    while (!IAppCard->checkDriveDone());*/
}

void VIHWClass::stopDrive()
{
	IAppCard->stopDrive();
}

void VIHWClass::setVoltageConstant(double pVoltConst)
{

	m_nVConst = pVoltConst;
}

void VIHWClass::setVoltageGain(double pGain)
{
	m_nVGain = pGain;
}
void VIHWClass::switchVoltageRegister(unsigned int pIndex)
{

//    unsigned int l_nAmpValue = pow(2, pIndex);
   // qDebug()<<"Vindex"<<pIndex;
//    unsigned int l_nRegisterData = l_nAmpValue;
    double m_nVoltRangeArray[5]={	0.6,	2.0,	4.0,	8.0,	14.0	};
    //double m_nVoltRangeArray1[4]={	0.2,	2.5,	7.75,	12.75	};
    double m_nVoltRangeArray1[4]={	0.2,	2.5,	8,	13	};  // Anbu

    // qDebug()<< "Voltage Index:" << pIndex<<" "<<m_nVoltRangeArray1[pIndex];
   // double m_nVoltRangeArray[6]={0.6,0.6,1.5,3.5,7.0,13.0}; // for testing
    int index=0;
	if(m_nVoltRangeArray1[pIndex]>0.5&&m_nVoltRangeArray1[pIndex]<=1.5)
	{
		index=1;
	}
	else if(m_nVoltRangeArray1[pIndex]>1.5&&m_nVoltRangeArray1[pIndex]<=3.5)
	{
		index=2;
	}
	else if(m_nVoltRangeArray1[pIndex]>3.5&&m_nVoltRangeArray1[pIndex]<=8)  // Anbu  7(8)
	{
		index=3;
	}
	else if(m_nVoltRangeArray1[pIndex]>8 &&m_nVoltRangeArray1[pIndex]<=13) // Anbu 7.1(8.1)
	{
		index=4;
	}
	else if(m_nVoltRangeArray1[pIndex]<=0.6)
	{
		index=0;
	}


	double m_nDDSVoltage;
	//temp=(m_nTestVoltage-(m_nRangeConstant[ui.comboBox->currentIndex()]))/(m_nRangeSlope[ui.comboBox->currentIndex()]);
	//qDebug()<<"Gain:"<<m_nVGain<<"Constant:"<<m_nVConst;
	m_nDDSVoltage = (m_nVoltRangeArray1[pIndex]-m_nVConst)/m_nVGain;
	m_nDDSVoltage = 1600/(m_nDDSVoltage/m_nVoltRangeArray[index]);
//	qDebug() << "DDS Voltage:"<<m_nDDSVoltage<<"Gain:"<<m_nVGain<<"Const:"<<m_nVConst;
	IAppCard->setSPIAppendBit(0x8000);
	m_objAD5293Component->setAD5293Voltage(m_nDDSVoltage);
    m_objAD5293Component->writeAD5293(SPI1);
    usleep(100000);
	short int l_nAmpValue = pow(2, index);
    unsigned int l_nRegisterAddress = 0x48;
	 if (index > 0){
        l_nAmpValue = pow(2, index - 1);
        IAppCard->writeRegister(l_nAmpValue,l_nRegisterAddress);
	 } else {
	    IAppCard->writeRegister(0x00, l_nRegisterAddress);
	 }

//    qDebug()<<"switchVoltageRegister Done";

	    //~~~~~~~~~~~~~Reading Short Values from File~~~~~~~~~~~~~~~~~~~~~~
	    QStringList stringList;    bool ok = true;    QFile textFile;	double offsetValue[5];
	    textFile.setFileName("OffsetValues.txt");

	    if (textFile.open(QIODevice::ReadOnly)) {
	            QTextStream textStream(&textFile);
	            while (!textStream.atEnd()) {
	                    stringList.append(textStream.readLine());
	            }
	            for(int i=0;i<5;i++){
	                offsetValue[i]=stringList.value(i).toDouble(&ok);
	                qDebug()<<"Range:"<<m_nVoltRangeArray[index]<<offsetValue[i];
	            }
	    }
	    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		IAppCard->setSPIAppendBit(0xC000);
		m_objAD5318Component->resetDAC5318(true);
		m_eSelect = DACF;
		m_objAD5318Component->configureADC5318CW();
	    updateDAC(offsetValue[index]);
}

void VIHWClass::switchFrequencyRegister(unsigned int pValue)
{
	//qDebug()<< "Freq Index:" << pValue;
	double l_nFrequenceArray[13] = {10.0,20.0,50.0,100.0,200.0,500.0,1000.0,2000.0,5000.0,10000.0,20000.0,50000.0,100000.0};
	unsigned short int l_nBTUARR[13]={1000,1000,1000,1000,1000,1000,100,100,100,100,50,20,10};
	unsigned short int l_nBDARR[13]= {100,50,20,10,5,2,10,5,2,1,1,1,1};
//	qDebug()<<"Frequency:"<<l_nFrequenceArray[pValue];//<<"Frequency Index:"<<pValue;
    double l_nTime = 1.0 / l_nFrequenceArray[pValue];
    double l_nTimeperSample = l_nTime / 100.0;
    unsigned short l_nCount = (unsigned short) (l_nTimeperSample / (1.0/ 100000000.0));
    unsigned short l_nQuotient = 0;
    if (l_nCount > 0xFFFE)
            l_nQuotient = l_nCount / 2;
    unsigned short l_nBDR =0;
    unsigned short l_nBTUR=0;
    if (l_nQuotient == 0) {
            l_nBDR= 0;
            l_nBTUR = l_nCount - 1;
    }
    else {
            l_nBDR = 1;
            l_nBTUR = l_nQuotient - 1;
    }
//    qDebug() << "Drive Count:" <<m_nDriveCount;
//    qDebug() << "BTUR:" <<l_nBTUARR[pValue]-1;
//    qDebug() << "BDR:" <<l_nBDARR[pValue]-1;

    IAppCard->writeRegister(0,0x14);
    IAppCard->basicTimeUnit(l_nBTUARR[pValue]-1);
    IAppCard->basicDuration(l_nBDARR[pValue]-1);
    //if(pValue==11 || pValue == 12)
    //	IAppCard->setStartStop(2,0);
    //else
    	IAppCard->setStartStop(1,0);
    IAppCard->setDrivePatternCount(false,0);

    /*IAppCard->basicTimeUnit(l_nBTUR);
    IAppCard->basicDuration(l_nBDR);
    IAppCard->driveCount(m_nDriveCount);*/

}

void VIHWClass::peformDriveConfiguration()
{
	unsigned int l_nRegisterAddress = 0, l_nRegisterData = 0;
	//qDebug()<<"Drive Configuraion";
	l_nRegisterAddress = 0x36, l_nRegisterData = 0x1;
	IAppCard->writeRegister(l_nRegisterData, l_nRegisterAddress);
	l_nRegisterAddress = 0x16, l_nRegisterData = 0x1;//Changed to 0x1 from 0x0 on 9thJune2014 RRV
	IAppCard->writeRegister(l_nRegisterData, l_nRegisterAddress);
	l_nRegisterAddress = 0x34, l_nRegisterData = 0x7;
	IAppCard->writeRegister(l_nRegisterData, l_nRegisterAddress);
	//qDebug()<<"0x34:"<<IAppCard->readRegister(0x34);
	//qDebug()<<"0x36:"<<IAppCard->readRegister(0x36);
	//qDebug()<<"0x16:"<<IAppCard->readRegister(0x16);
}


void VIHWClass::switchImpedanceRegister(unsigned int pIndex)
{
//added on june9th2014 by RRV
//	qDebug()<<"VIHWClass::switchImpedanceRegister index:"<<pIndex;
	IPsoc->srcImpedanceSelection(pIndex+0x01);

//commented on june9th2014 by RRV
 /*usleep(10000);
   unsigned int l_nRegisterAddress = 0x26, l_nRegisterData = pIndex;
   IBackPlane->writeBackPlaneRegister(l_nRegisterData, l_nRegisterAddress); // Initialize BP Source Impedance Selection*/
}


bool VIHWClass::checkSPIMemoryCodeID()
{
	//qDebug()<< "Code ID:"<<hex<<IBackPlane->getSPICodeID();
    if(ISPIMemory->getSPICodeID() == 0x208014)
        return true;
    else
        return false;
}

short unsigned int* VIHWClass::ReadSPIData(unsigned int pMemIndex,unsigned int pCount)
{
	//return IBackPlane->ReadSPI(pMemIndex,pCount);
	return ISPIMemory->ReadSPI(pMemIndex,pCount);
}

void VIHWClass::initializeInterruptSequeces()
{
    IBackPlane->writeBackPlaneRegister(0x0FFF, 0x001E);//clear all interrupts
    IBackPlane->writeBackPlaneRegister(0x0000, 0x0020);//disable all interrupts
    IBackPlane->writeBackPlaneRegister(0x0000, 0x0024);//disable global interrupt

}

void VIHWClass::writeSPIMemory(unsigned int pMemIndex,unsigned int pCount,short unsigned int *pData)
{
	//IBackPlane->writeSPIMemory(pMemIndex,pCount,pData);
	ISPIMemory->writeSPIMemory(pMemIndex,pCount,pData);
}

bool VIHWClass::checkMUXDetection()
{
	IPsoc->muxDetection();//dummy read for 0
	unsigned int muxStatus=IPsoc->muxDetection();
	if(  muxStatus == 0x15)
	{
		qDebug()<<"mux detected :"<<hex<<muxStatus;
//		IPsoc->externalMuxMeasurement(0xff,0xff);//added by ravivarman 31st july
//	    if(IPsoc->readMuxStatus()==true)
//	    	qDebug()<<"Both Channels Reset Done";
//	    else
//	    	qDebug()<<"Both Channels Reset Not Done";
		IPsoc->switchTest(0xff);
		IPsoc->switchRef(0xff);
		return true;
	}
	else
	{
		qDebug()<<"mux not detected :"<<hex<<muxStatus;
		return false;
	}


}

void VIHWClass::enableInterrupt()
{
	unsigned int l_nIntPadValue = 0x00100 | m_nInterruptValue;
	qDebug()<<"Interrupt Value:"<<hex<<l_nIntPadValue;
	IBackPlane->writeBackPlaneRegister(l_nIntPadValue, 0x0020);//enabling psoc INT0 embedded key interrupt / App Card SLOT 0 Interrupt
	IBackPlane->writeBackPlaneRegister(l_nIntPadValue, 0x001E);//clear all interrupts
	IBackPlane->writeBackPlaneRegister(0x1, 0x0024); //enabling global interrupt
	//qDebug()<<"Interrupt Status Register(0x1E):"<<IBackPlane->readBackPlaneRegister(0x1E);
}

void VIHWClass::clearInterrupt()
{
	unsigned int l_nIntPadValue = 0x00100 | m_nInterruptValue;
	qDebug()<<"Interrupt Value:"<<hex<<l_nIntPadValue;
	IBackPlane->writeBackPlaneRegister(l_nIntPadValue, 0x001E);//clear all interrupts
	//IBackPlane->writeBackPlaneRegister(0x0001, 0x0024); // set Interrupt
}

unsigned int VIHWClass::readAPPCardInterruptValue()
{
	//IBackPlane->writeBackPlaneRegister(0x0000,0x0024);  //global interrupt disabled
	unsigned int l_nRegisterValue = IBackPlane->readBackPlaneRegister(0x001E);
	IBackPlane->writeBackPlaneRegister(m_nInterruptValue, 0x001E);
	return l_nRegisterValue;
}

unsigned int VIHWClass::readEmbKeyValue()
{
	//IBackPlane->writeBackPlaneRegister(0x0000,0x0024);  //global interrupt disabled
	unsigned int l_nRegisterValue = IBackPlane->readBackPlaneRegister(0x001E);
	IBackPlane->writeBackPlaneRegister(0x0100, 0x001E);
	return l_nRegisterValue;
}

void VIHWClass::disableInterrupt()
{
	unsigned int l_nIntPadValue = 0x00100 | m_nInterruptValue;
	qDebug()<<"Interrupt Value:"<<hex<<l_nIntPadValue;
	IBackPlane->writeBackPlaneRegister(l_nIntPadValue, 0x001E);//clear all interrupts
	IBackPlane->writeBackPlaneRegister(0x0000, 0x0020);//disable all interrupts
	IBackPlane->writeBackPlaneRegister(0x0000, 0x0024);//disable global interrupt
}

void VIHWClass::onGNDRelay(bool pFlag)
{
	if(pFlag==true)
	{
//		IPsoc->onTopRelay(0x24);//added june9th2014
	}
	else
	{
//		IPsoc->offTopRelay(0x24);//added june9th2014
	}
}
void VIHWClass::writePSOC(unsigned int pValue)
{
	IPsoc->writeSerial(pValue);
}
void VIHWClass::resetPSOC(){//added by ravivarman 31st july
	IPsoc->resetRelays();
}
unsigned int VIHWClass::readPSOC()
{
	return IPsoc->readSerial();
}
