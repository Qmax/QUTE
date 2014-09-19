#include "ptapplicationcardplugin.h"


static const char *device = "/dev/emiapp";



//PTApplicationCardPlugin::PTApplicationCardPlugin()
//{
//    //enumerateAPPCard();
//    qDebug() << "Application Card Constructor";
//
//}
////
//PTApplicationCardPlugin::~PTApplicationCardPlugin()
//{
//    m_ptrReadValues = m_ptrWriteValues = NULL;
//    free(m_ptrReadValues);
//    free(m_ptrWriteValues);
//    close(m_nAppFD);
//}

unsigned int PTApplicationCardPlugin::readScratchPad()
{
	return readRegister(PT_APPCARD_MODULES::PT_SYSTEM_APPCARD_SPR);
}

void PTApplicationCardPlugin::setDeviceName(APP_SLOTS pSlotNo)
{

	mapDeviceString.insert(0,"/dev/emiapp");
	mapDeviceString.insert(1,"/dev/emics3");
	mapDeviceString.insert(2,"/dev/emics4");
	mapDeviceString.insert(3,"/dev/emics5");
	m_strdevice = mapDeviceString.value(0);
	//qDebug() <<"Selected Device:" << m_strdevice;
}

void PTApplicationCardPlugin::enumerateAPPCard()
{
    tempAddr=0;
    baseAddr = 0x0000000;
//    qDebug() <<"Selected Device:" << m_strdevice;
//    m_nAppFD = open(m_strdevice,O_RDWR);
//    if (m_nAppFD < 0)
//    {
//        printf("Can't open device for Application card communication.\n");
//        close(m_nAppFD);
//        //return 0;
//    }
//    m_ptrWriteValues = (unsigned int*)malloc(2*sizeof(unsigned int));
//    m_ptrReadValues = (unsigned int*)malloc(1*sizeof(unsigned int));
    //qDebug()<<hex<<readAppCardCodeId();
    for(int l_nAppcardIndex=0;l_nAppcardIndex<4;l_nAppcardIndex++)
    {
//    	qDebug()<<mapDeviceString.value(l_nAppcardIndex);
    	int l_nAppFD = open(mapDeviceString.value(l_nAppcardIndex),O_RDWR);
    	if (l_nAppFD < 0)
		{
            printf("Can't open device for Application card communication.\n");
            close(l_nAppFD);
		}
		m_nAppFD = l_nAppFD;
    	if( readAppCardCodeId() == 0x1982)
    	{
    		if(l_nAppcardIndex == 0)
    		{
    			writeScratchpad(0x40);
    		}
    		else if(l_nAppcardIndex == 1)
    		{
    			writeScratchpad(0x10);
    		}
    		else if(l_nAppcardIndex == 2)
    		{
    			writeScratchpad(0x04);
    		}
    		else if(l_nAppcardIndex == 4)
    		{
    			writeScratchpad(0x01);
    		}
    		qDebug()<</*l_nAppFD*/"APPCARD CODE ID:"<<hex<<readAppCardCodeId();
//        	qDebug()<<"Selected Device:"<<mapDeviceString.value(l_nAppcardIndex);
        	break;
    	}
    }

}

//[[-------------------------------------- DSO Drive Registers---------------------------------------
void PTApplicationCardPlugin::setDSOBTUR(unsigned int pData)
{
   writeRegister(pData,PT_APPCARD_MODULES::PT_DSO_BTUR);
}

void PTApplicationCardPlugin::setDSOBDR(unsigned int pData)
{
	writeRegister(pData,PT_APPCARD_MODULES::PT_DSO_BDR);
}

void PTApplicationCardPlugin::setDSOCR(bool pStartDrive)
{
	if(pStartDrive)
		writeRegister(0x01,PT_APPCARD_MODULES::PT_DSO_CR);
	else
		writeRegister(0x02,PT_APPCARD_MODULES::PT_DSO_CR);
}

void PTApplicationCardPlugin::setDSOMR()
{
	// Address Not defined
	// SINGLE,NORMAL,AUTO, RESERVED
}

void PTApplicationCardPlugin::setDSOTrigger(unsigned short int pValue)
{

	writeRegister(pValue,PT_APPCARD_MODULES::PT_DSO_TR);
}

void PTApplicationCardPlugin::setDSOTriggerSource(RECEIVER_CONF pReceInfo,DSO_TRIGGER pTriggerSource)
{
	unsigned short l_nRegValue=0;
	//l_nRegValue = readRegister(PT_APPCARD_MODULES::PT_DSO_TR);
	if(pReceInfo == RECEIVER2)
		l_nRegValue |= 0x10;
	if(pReceInfo == EXTERNAL)
		l_nRegValue |= 0x20;
	if(pTriggerSource == EDGE_RISING)
		l_nRegValue |= 0x02;
	if(pTriggerSource == PULSE_POSITIVE)
		l_nRegValue |= 0x04;
	if(pTriggerSource == PULSE_NEGATIVE)
		l_nRegValue |= 0x06;

	qDebug() << "Selected Trigger Source and Trigger:"<<hex<<l_nRegValue;
	writeRegister(l_nRegValue,PT_APPCARD_MODULES::PT_DSO_TR);
}

void PTApplicationCardPlugin::setDSOSampleCount(unsigned int pCount)
{
	//writeRegister(pCount,PT_APPCARD_MODULES::PT_DSO_SCR);
}
bool PTApplicationCardPlugin::checkDSODriveDone()
{
	 while(!(readRegister(PT_APPCARD_MODULES::PT_DSO_CR)& 0x0001));
	    return true;
}

void PTApplicationCardPlugin::setDSOPostCount(unsigned int pCount)
{
	writeRegister(pCount,PT_APPCARD_MODULES::PT_DSO_POSTCR);
}

void PTApplicationCardPlugin::setDSOPreCount(unsigned int pCount)
{
	writeRegister(pCount,PT_APPCARD_MODULES::PT_DSO_PRETCR);
}
//--------------------------------------------------------------------------------------------------]]

//[[-------------------------------------- DSO Receiver Configuration----------------------------------

void PTApplicationCardPlugin::setDSOReceiveFIFOConfiguration(DSO_RECEIVE_FIFO pSelFIFO,bool pADC1Rst,bool pADC1ClkDivRst,bool pFIFORst)
{
	unsigned short l_nReceFIFO[2]= {PT_APPCARD_MODULES::PT_DSOR1FIFO_CFG,
	                                PT_APPCARD_MODULES::PT_DSOR2FIFO_CFG};
	unsigned short l_nData=0;
	if(pADC1Rst == true)
		l_nData = 1;
	if(pADC1ClkDivRst==true)
		l_nData |= 2;
	if(pFIFORst == true)
		l_nData |=4;
	writeRegister(l_nData,l_nReceFIFO[pSelFIFO-1]);
}

void PTApplicationCardPlugin::setDSOReceiveFIFOMode(bool bR1Mode,bool bR2Mode)
{
//	unsigned short l_nReceFIFO[2]= {PT_APPCARD_MODULES::PT_DSOFIFO_MODE,
//	                                PT_APPCARD_MODULES::PT_DSOFIFO_MODE};
	unsigned short l_nData=0;
	if(bR1Mode == true)
	{
		l_nData =1;
	}
	if(bR2Mode == true)
	{
		l_nData |= 2;
	}
	writeRegister(l_nData,PT_APPCARD_MODULES::PT_DSOFIFO_MODE);
}

unsigned short PTApplicationCardPlugin::getDSOReceiveFIFOODD_RD(DSO_RECEIVE_FIFO pSelFIFO)
{
	unsigned short l_nReceFIFO[2]= {PT_APPCARD_MODULES::PT_DSOR1FIFO_ODD_RD,
	                                PT_APPCARD_MODULES::PT_DSOR2FIFO_ODD_RD};

	return readRegister(l_nReceFIFO[pSelFIFO-1]);
}

unsigned short PTApplicationCardPlugin::getDSOReceiveFIFOEVEN_RD(DSO_RECEIVE_FIFO pSelFIFO)
{
	unsigned short l_nReceFIFO[2]= {PT_APPCARD_MODULES::PT_DSOR1FIFO_EVEN_RD,
	                                PT_APPCARD_MODULES::PT_DSOR2FIFO_EVEN_RD};

	return readRegister(l_nReceFIFO[pSelFIFO-1]);
}


void PTApplicationCardPlugin::setDSOReceiveFIFOODD_WR(unsigned short pOddData,DSO_RECEIVE_FIFO pSelFIFO)
{
	unsigned short l_nReceFIFO[2]= {PT_APPCARD_MODULES::PT_DSOR1FIFO_ODD_WR,
	                                PT_APPCARD_MODULES::PT_DSOR2FIFO_ODD_WR};

	writeRegister(pOddData,l_nReceFIFO[pSelFIFO-1]);
}

void PTApplicationCardPlugin::setDSOReceiveFIFOEVEN_WR(unsigned short pEvenData,DSO_RECEIVE_FIFO pSelFIFO)
{
	unsigned short l_nReceFIFO[2]= {PT_APPCARD_MODULES::PT_DSOR1FIFO_EVEN_WR,
	                                PT_APPCARD_MODULES::PT_DSOR2FIFO_EVEN_WR};

	writeRegister(pEvenData,l_nReceFIFO[pSelFIFO-1]);
}

//---------------------------------------------------------------------------------------------------]]



//[[-------------------------------------- Drive Registers -------------------------------------------

unsigned int PTApplicationCardPlugin::basicDuration(unsigned int pData)
{
  //  unsigned int l_nreadValue;
    m_nBasicDuration = m_nBasicTime *(pData+1);
    writeRegister(pData,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_BDR);
   // l_nreadValue=readRegister(PT_APPCARD_MODULES::PT_DRIVE_APPCARD_BDR);
    return 1;
}

unsigned int PTApplicationCardPlugin::basicTimeUnit(unsigned int pData)
{
     m_nBasicTime = (pData + 1)*10;
    writeRegister(pData,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_BTUR);
    return 1;
}

void PTApplicationCardPlugin::startDrive(unsigned int)
{
    writeRegister(START_DRIVE,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DCR);
}

void PTApplicationCardPlugin::stopDrive()
{
    writeRegister(STOP_DRIVE,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DCR);
}

void PTApplicationCardPlugin::setDrivePeriod(unsigned short pDPR)
{
    writeRegister((pDPR),PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DPR);
}

void PTApplicationCardPlugin::setStartStop(unsigned short pStartSSDR, unsigned short pStopSSDR)
{
    unsigned short l_nSSDRMSW_MSW = (pStartSSDR<<8) | pStopSSDR;
    writeRegister(l_nSSDRMSW_MSW,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_SSDR);
}

void PTApplicationCardPlugin::setDrivePatternCount(bool pLOOPEN,unsigned short pDPC)
{
    unsigned short l_nDPCReg = 0x0000;
    if(pLOOPEN == true)
        l_nDPCReg = (1<<8)| pDPC;
    else
        l_nDPCReg = pDPC;
    writeRegister(l_nDPCReg,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DPC);
}
//---------------------------------------------------------------------------------------------------]]
//[[----------------------------------- DDS Module ----------------------------------------------------
void PTApplicationCardPlugin::setDDSCommandWord(bool pSetDDS)
{
    unsigned short l_nDDS=0;
    if(pSetDDS == true)
    {
        l_nDDS = 1;
    }
    writeRegister(l_nDDS,PT_APPCARD_MODULES::PT_DDS_APPCARD_CR);
}

void PTApplicationCardPlugin::setDDSFTW_LSW(unsigned short pLSW)
{
    writeRegister(pLSW,PT_APPCARD_MODULES::PT_DDS_APPCARD_FTWR_LSW);
}

void PTApplicationCardPlugin::setDDSFTW_MSW(unsigned short pMSW)
{
    writeRegister(pMSW,PT_APPCARD_MODULES::PT_DDS_APPCARD_FTWR_MSW);
}

void PTApplicationCardPlugin::setDDSPTW_LSW(unsigned short pLSW)
{
    writeRegister(pLSW,PT_APPCARD_MODULES::PT_DDS_APPCARD_PTWR_LSW);

}

void PTApplicationCardPlugin::setDDSPTW_MSW(unsigned short pMSW)
{
    writeRegister(pMSW,PT_APPCARD_MODULES::PT_DDS_APPCARD_PTWR_MSW);
}

void PTApplicationCardPlugin::setDDSWaveSelect(DDS_WAVESELECT pWaveSelect)
{
    writeRegister(pWaveSelect,PT_APPCARD_MODULES::PT_DDS_APPCARD_DDSWSELR);
}

void PTApplicationCardPlugin::setDDSSawtooth(DDS_SAWTOOTH_REG pSawtooth)
{
    writeRegister(pSawtooth,PT_APPCARD_MODULES::PT_DDS_APPCARD_DDSSSTR);
}

void PTApplicationCardPlugin::setDDSDACDCdrive(unsigned short pDACDC)
{
    writeRegister(pDACDC,PT_APPCARD_MODULES::PT_DDS_APPCARD_DCDR);
}

void PTApplicationCardPlugin::setDDSConfiguration1(DDSR1CONFIG pObjR1Configuration)
{
    unsigned short l_nDDRR1Configuration=0;
    if(pObjR1Configuration.m_bSINEorCOSINE == false)
        l_nDDRR1Configuration |= (1<<3);
    if(pObjR1Configuration.m_bBaseClockorMSBRAM == false)
        l_nDDRR1Configuration |= (1<<2);
    if(pObjR1Configuration.m_bPTWRAMorREG == false)
        l_nDDRR1Configuration |= (1<<1);
    if(pObjR1Configuration.m_bFTWRAMorREG== false)
        l_nDDRR1Configuration |= 1;

    writeRegister(l_nDDRR1Configuration,PT_APPCARD_MODULES::PT_DDS_APPCARD_CFG1R);
}

void PTApplicationCardPlugin::setDDSTWRAM()
{
    // functionality to be defined
}
//----------------------------------------------------------------------------------------------------]]

//[[---------------------------------- SRAM Registers --------------------------------------------------

void PTApplicationCardPlugin::setRAMADDR(unsigned short pRAMAddress)
{
    writeRegister(pRAMAddress,PT_APPCARD_MODULES::PT_SRAM_APPCARD_RAMADDRR);
}

void PTApplicationCardPlugin::setDriveRAMData(unsigned short pRAMData)
{
    writeRegister(pRAMData,PT_APPCARD_MODULES::PT_SRAM_APPCARD_DRAMDATAR);
}

unsigned short PTApplicationCardPlugin::readDriveRAMData()
{
	return readRegister(PT_APPCARD_MODULES::PT_SRAM_APPCARD_DRAMDATAR);
}

void PTApplicationCardPlugin::setReceiveRAMData(unsigned short pRAMData)
{
    writeRegister(pRAMData,PT_APPCARD_MODULES::PT_SRAM_APPCARD_RRAMDATAR);
}

unsigned short PTApplicationCardPlugin::readReceiveRAMData()
{
	return readRegister(PT_APPCARD_MODULES::PT_SRAM_APPCARD_RRAMDATAR);
}

void PTApplicationCardPlugin::setDriveRAMStarAddress(unsigned short pStartAddress)
{
	qDebug()<<"RAM Start Address:"<<pStartAddress;
    writeRegister(pStartAddress,PT_APPCARD_MODULES::PT_SRAM_APPCARD_DRSAR);
}

void PTApplicationCardPlugin::setDriveRAMEndAddress(unsigned short pEndAddress)
{
	qDebug()<<"RAM End Address:"<<pEndAddress;
    writeRegister(pEndAddress,PT_APPCARD_MODULES::PT_SRAM_APPCARD_DREAR);
}

void PTApplicationCardPlugin::setRAMModeAccess(RAMACCESS pbRamAccess)
{
    unsigned short l_nRAMMode=0;
    if(pbRamAccess.m_bRRAM1MODE == true)
        l_nRAMMode |= (1<<1);
    if(pbRamAccess.m_bDRAMMODE==true)
        l_nRAMMode |= 1;
    writeRegister(l_nRAMMode,PT_APPCARD_MODULES::PT_SRAM_APPCARD_RAMR);
}

//----------------------------------------------------------------------------------------------------]]

//[[-------------------------------------- SPI Controller-----------------------------------------------

// SPI1

void PTApplicationCardPlugin::setSPITXLSW(unsigned short pLSWData, SPI_SELECT peSPISelect)
{
    unsigned short l_nTXARRAY[6]= {PT_APPCARD_MODULES::PT_SPI1_APPCARD_TXR_LSW,
                                   PT_APPCARD_MODULES::PT_SPI2_APPCARD_TXR_LSW,
                                   PT_APPCARD_MODULES::PT_SPI3_APPCARD_TXR_LSW,
                                   PT_APPCARD_MODULES::PT_SPI4_APPCARD_TXR_LSW,
                                   PT_APPCARD_MODULES::PT_SPI5_APPCARD_TXR_LSW,
                                   PT_APPCARD_MODULES::PT_SPI6_APPCARD_TXR_LSW,
                               };
//    qDebug()<<"SPITXLSW"<<"\tData:"<<hex<<pLSWData<<"\tAddress:"<<hex<<l_nTXARRAY[peSPISelect-1];
    writeRegister(pLSWData,l_nTXARRAY[peSPISelect-1]);
}

void PTApplicationCardPlugin::setSPITXMSW(unsigned short pMSWData, SPI_SELECT peSPISelect)
{
    unsigned short l_nTXARRAY[6]= {PT_APPCARD_MODULES::PT_SPI1_APPCARD_TXR_MSW,
                                   PT_APPCARD_MODULES::PT_SPI2_APPCARD_TXR_MSW,
                                   PT_APPCARD_MODULES::PT_SPI3_APPCARD_TXR_MSW,
                                   PT_APPCARD_MODULES::PT_SPI4_APPCARD_TXR_MSW,
                                   PT_APPCARD_MODULES::PT_SPI5_APPCARD_TXR_MSW,
                                   PT_APPCARD_MODULES::PT_SPI6_APPCARD_TXR_MSW,
                               };
//    qDebug()<<"SPITXMSW"<<"\tData:"<<hex<<pMSWData<<"\tAddress:"<<hex<<l_nTXARRAY[peSPISelect-1];
    writeRegister(pMSWData,l_nTXARRAY[peSPISelect-1]);

}

unsigned short PTApplicationCardPlugin::getSPIRXLSW(SPI_SELECT peSPISelect)
{
    unsigned short l_nRXARRAY[6]= {PT_APPCARD_MODULES::PT_SPI1_APPCARD_RXR_LSW,
                                   PT_APPCARD_MODULES::PT_SPI2_APPCARD_RXR_LSW,
                                   PT_APPCARD_MODULES::PT_SPI3_APPCARD_RXR_LSW,
                                   PT_APPCARD_MODULES::PT_SPI4_APPCARD_RXR_LSW,
                                   PT_APPCARD_MODULES::PT_SPI5_APPCARD_RXR_LSW,
                                   PT_APPCARD_MODULES::PT_SPI6_APPCARD_RXR_LSW,
                               };
    return readRegister(l_nRXARRAY[peSPISelect-1]);
}

unsigned short PTApplicationCardPlugin::getSPIRXMSW(SPI_SELECT peSPISelect)
{
    unsigned short l_nRXARRAY[6]= {PT_APPCARD_MODULES::PT_SPI1_APPCARD_RXR_MSW,
                                   PT_APPCARD_MODULES::PT_SPI2_APPCARD_RXR_MSW,
                                   PT_APPCARD_MODULES::PT_SPI3_APPCARD_RXR_MSW,
                                   PT_APPCARD_MODULES::PT_SPI4_APPCARD_RXR_MSW,
                                   PT_APPCARD_MODULES::PT_SPI5_APPCARD_RXR_MSW,
                                   PT_APPCARD_MODULES::PT_SPI6_APPCARD_RXR_MSW,
                               };
    return readRegister(l_nRXARRAY[peSPISelect-1]);
}

bool PTApplicationCardPlugin::readSPIDriveDoneBit(SPI_SELECT peSPISelect)
{
    unsigned short l_nSPICRARRAY[6]=
                                  {PT_APPCARD_MODULES::PT_SPI1_APPCARD_CR,
                                   PT_APPCARD_MODULES::PT_SPI2_APPCARD_CR,
                                   PT_APPCARD_MODULES::PT_SPI3_APPCARD_CR,
                                   PT_APPCARD_MODULES::PT_SPI4_APPCARD_CR,
                                   PT_APPCARD_MODULES::PT_SPI5_APPCARD_CR,
                                   PT_APPCARD_MODULES::PT_SPI6_APPCARD_CR};
    usleep(10000);
    while((readRegister(l_nSPICRARRAY[peSPISelect-1])& 0x0001));
    return true;
}

void PTApplicationCardPlugin::setSPIAppendBit(unsigned short int pSPIAppend)
{
	m_nSPIAppend = pSPIAppend;
//	qDebug() <<"SPI Append Bit:"<<hex<<m_nSPIAppend;
}
void PTApplicationCardPlugin::setSPICW(unsigned short pCWData, SPI_SELECT peSPISelect)
{
    unsigned short l_nSPICWArray[6] =
    {
        PT_APPCARD_MODULES::PT_SPI1_APPCARD_CR,
        PT_APPCARD_MODULES::PT_SPI2_APPCARD_CR,
        PT_APPCARD_MODULES::PT_SPI3_APPCARD_CR,
        PT_APPCARD_MODULES::PT_SPI4_APPCARD_CR,
        PT_APPCARD_MODULES::PT_SPI5_APPCARD_CR,
        PT_APPCARD_MODULES::PT_SPI6_APPCARD_CR
    };
    // CS_POL 	SCLK_LOW
    //   1			1	 // CS_LOW,CLK LOW
    //   1			0	 // CS_LOW,CLK HIGH
    //   0			1    // CS_HIGH, CLK_LOW
    //   0			0    // CS_HIGH, CLK_HIGH
    pCWData = m_nSPIAppend | pCWData;
//    qDebug() << "SPICTRLW"<<"\tData:"<<hex<<pCWData<<"\tAddress:"<<hex<< l_nSPICWArray[peSPISelect-1];
    writeRegister(pCWData,l_nSPICWArray[peSPISelect-1]);
}

void PTApplicationCardPlugin::setSPIClock(unsigned short pCLKData,SPI_SELECT peSPISelect)
{
    unsigned short l_nSPICLKArray[6] =
    {
        PT_APPCARD_MODULES::PT_SPI1_APPCARD_SCLKDIV,
        PT_APPCARD_MODULES::PT_SPI2_APPCARD_SCLKDIV,
        PT_APPCARD_MODULES::PT_SPI3_APPCARD_SCLKDIV,
        PT_APPCARD_MODULES::PT_SPI4_APPCARD_SCLKDIV,
        PT_APPCARD_MODULES::PT_SPI5_APPCARD_SCLKDIV,
        PT_APPCARD_MODULES::PT_SPI6_APPCARD_SCLKDIV
    };
	writeRegister(pCLKData,l_nSPICLKArray[peSPISelect-1]);
}


void PTApplicationCardPlugin::setSPI1CommandWord(SPI1_CONFIGURATION m_stSPI1)
{
    unsigned short l_nSPI1CW=0;
    l_nSPI1CW = m_stSPI1.m_eCSSEL;
    l_nSPI1CW |= (m_stSPI1.m_eCSEN) << 5;
    if(m_stSPI1.m_bLDAC_AD5318 == true)
        l_nSPI1CW |= (1) << 4;
    if(m_stSPI1.m_bCD == true)
        l_nSPI1CW |= (1) << 3;
    l_nSPI1CW |= m_stSPI1.m_eMode << 1;
    if(m_stSPI1.m_bSD == true)
        l_nSPI1CW |= 1;
    writeRegister(l_nSPI1CW,PT_APPCARD_MODULES::PT_SPI1_APPCARD_CR);
}


//SPI2
void PTApplicationCardPlugin::setSPI2CommandWord(SPI2_CONFIGURATION m_stSPI2)
{
    unsigned short l_nSPI2CW=0;
    l_nSPI2CW |= (m_stSPI2.m_eCSEN) << 5;
    if(m_stSPI2.m_bCD == true)
        l_nSPI2CW |= (1) << 3;
    l_nSPI2CW |= m_stSPI2.m_eMode << 1;
    if(m_stSPI2.m_bSD == true)
        l_nSPI2CW |= 1;
    writeRegister(l_nSPI2CW,PT_APPCARD_MODULES::PT_SPI2_APPCARD_CR);
}
//SPI3
void PTApplicationCardPlugin::setSPI3CommandWord(SPI3_CONFIGURATION m_stSPI3)
{
    unsigned short l_nSPI3CW=0;
    if(m_stSPI3.m_bCD == true)
        l_nSPI3CW |= (1) << 3;
    l_nSPI3CW |= m_stSPI3.m_eMode << 1;
    if(m_stSPI3.m_bSD == true)
        l_nSPI3CW |= 1;
    writeRegister(l_nSPI3CW,PT_APPCARD_MODULES::PT_SPI3_APPCARD_CR);
}
//SPI4
void PTApplicationCardPlugin::setSPI4CommandWord(SPI4_CONFIGURATION m_stSPI4)
{
    unsigned short l_nSPI4CW=0;
    if(m_stSPI4.m_bCD == true)
        l_nSPI4CW |= (1) << 3;
    l_nSPI4CW |= m_stSPI4.m_eMode << 1;
    if(m_stSPI4.m_bSD == true)
        l_nSPI4CW |= 1;
    writeRegister(l_nSPI4CW,PT_APPCARD_MODULES::PT_SPI4_APPCARD_CR);
}
// SPI5
void PTApplicationCardPlugin::setSPI5CommandWord(SPI5_CONFIGURATION m_stSPI5)
{
    unsigned short l_nSPI5CW=0;
    l_nSPI5CW = m_stSPI5.m_eCSSEL;
    l_nSPI5CW |= (m_stSPI5.m_eCSEN) << 5;
    if(m_stSPI5.m_bCD == true)
        l_nSPI5CW |= (1) << 3;
    l_nSPI5CW |= m_stSPI5.m_eMode << 1;
    if(m_stSPI5.m_bSD == true)
        l_nSPI5CW |= 1;
    writeRegister(l_nSPI5CW,PT_APPCARD_MODULES::PT_SPI5_APPCARD_CR);
}


// SPI6
void PTApplicationCardPlugin::setSPI6CommandWord(SPI6_CONFIGURATION m_stSPI6)
{
    unsigned short l_nSPI6CW=0;
    l_nSPI6CW = m_stSPI6.m_eCSSEL;
    l_nSPI6CW |= (m_stSPI6.m_eCSEN) << 5;
    if(m_stSPI6.m_bCD == true)
        l_nSPI6CW |= (1) << 3;
    l_nSPI6CW |= m_stSPI6.m_eMode << 1;
    if(m_stSPI6.m_bSD == true)
        l_nSPI6CW |= 1;
    writeRegister(l_nSPI6CW,PT_APPCARD_MODULES::PT_SPI6_APPCARD_CR);
}
//-----------------------------------------------------------------------------------------------------]]

//[[ ---------------------------------------- Drive Relay Registers--------------------------------------
void PTApplicationCardPlugin::setDriveReceiveSourceSelect(DRSER pstDRSER)
{
    unsigned short l_nDRSER=0;
    if(pstDRSER.m_bDSE == true)
        l_nDRSER = 1;
    if(pstDRSER.m_bR1SE == true)
        l_nDRSER |= (1) <<1;
    if(pstDRSER.m_bR2SE == true)
        l_nDRSER |= (1) <<2;
    writeRegister(l_nDRSER,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRSER );
}

unsigned short int PTApplicationCardPlugin::getDriveReceiveSourceSelect()
{
	return readRegister(PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRSER);
}

void PTApplicationCardPlugin::setDriveSourceAmplitudeRegister(DSAR pstDSAR)
{
    unsigned short l_nDSAR=0;
    if(pstDSAR.m_bSRCN == true)
        l_nDSAR = 1;
    l_nDSAR |= pstDSAR.m_eIRS << 1;
    if(pstDSAR.m_bSRCN == true)
        l_nDSAR |= 1 << 3;
     writeRegister(l_nDSAR,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DSAR);
}
unsigned short int PTApplicationCardPlugin::getDriveSourceAmplitudeRegister()
{
	return readRegister(PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DSAR);
}


void PTApplicationCardPlugin::setDriveReceiveGainRegister(DRGSR pstDRGR)
{
    unsigned short l_nDRGR=0;
    l_nDRGR = pstDRGR.m_eVRanges;
    if(pstDRGR.m_bSlotFFS == true)
        l_nDRGR |= 1 <<3;
    writeRegister(l_nDRGR,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRGSR);
}
unsigned short int PTApplicationCardPlugin::getDriveReceiveGainRegister()
{
	return readRegister(PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRGSR);
}
//------------------------------------------------------------------------------------------------------]]

//[[--------------------------------------- Receive Relays -----------------------------------------------
void PTApplicationCardPlugin::setReceiversConfiguration(RECEIVER_CONF peReceConf, R1CR pSTReceiver1)
{
    unsigned short l_nR1CR =0;
    if(pSTReceiver1.m_bHSHA == true)
        l_nR1CR = 1;
    if(pSTReceiver1.m_bHAAC == true)
        l_nR1CR|= 1 << 1;
    if(pSTReceiver1.m_bRMSIN == true)
        l_nR1CR|= 1 << 2;
    if(pSTReceiver1.m_bRMSGAIN == true)
        l_nR1CR|= 1 << 3;
    if(pSTReceiver1.m_bRMSAVG == true)
        l_nR1CR|= 1 << 4;
    if(pSTReceiver1.m_bHAIPR1_ICMSELR2 == true) // ICM Selection for Receiver 2
        l_nR1CR|= 1 << 5;
    if(pSTReceiver1.m_bHSVI == true)
        l_nR1CR|= 1 << 6;
    l_nR1CR|= pSTReceiver1.m_eCoupling << 7;
    if(peReceConf == RECEIVER1)
        writeRegister(l_nR1CR,PT_APPCARD_MODULES::PT_RECERLY_APPCARD_R1CR);
    if(peReceConf == RECEIVER2)
        writeRegister(l_nR1CR,PT_APPCARD_MODULES::PT_RECERLY_APPCARD_R2CR);
}

unsigned short int PTApplicationCardPlugin::getReceiversConfiguration(RECEIVER_CONF peReceConf)
{
    if(peReceConf == RECEIVER1)
    	return readRegister(PT_APPCARD_MODULES::PT_RECERLY_APPCARD_R1CR);
    else
    	return readRegister(PT_APPCARD_MODULES::PT_RECERLY_APPCARD_R2CR);
}


void PTApplicationCardPlugin::setICMRangeGain(ICMMGR pstICMConf)
{
    unsigned short l_nICMConf =0;
    l_nICMConf = pstICMConf.m_eRange;
    if(pstICMConf.m_bGain == true)
        l_nICMConf|= 1 <<3;
    if(pstICMConf.m_bIASel == true)
        l_nICMConf|= 1 <<4;
    if(pstICMConf.m_bFBCAPSel == true)
        l_nICMConf|= 1 <<5;
    writeRegister(l_nICMConf,PT_APPCARD_MODULES::PT_RECERLY_APPCARD_ICMMGR);
}


unsigned short int PTApplicationCardPlugin::getICMRangeGain()
{
	return readRegister(PT_APPCARD_MODULES::PT_RECERLY_APPCARD_ICMMGR);
}
//------------------------------------------------------------------------------------------------------]]


unsigned  int PTApplicationCardPlugin::readAppCardCodeId()
{
    return readRegister(PT_APPCARD_MODULES::PT_SYSTEM_APPCARD_CR);
}

void PTApplicationCardPlugin::writeScratchpad(unsigned int pData)
{
    writeRegister(pData,PT_APPCARD_MODULES::PT_SYSTEM_APPCARD_SPR);
}

unsigned int PTApplicationCardPlugin::readRegister(unsigned int pAddress)
{
	//qDebug()<<hex<< "Read Register"<<pAddress;
    unsigned int *m_ptrReadValues;
    m_ptrReadValues = (unsigned int*)malloc(1*sizeof(unsigned int));
    unsigned int l_nReceiveData=0;
     tempAddr=pAddress;
     pAddress=baseAddr|tempAddr;
     m_ptrReadValues[0] = pAddress;
     l_nReceiveData = read(m_nAppFD,m_ptrReadValues,sizeof(m_ptrReadValues));
     free(m_ptrReadValues);
     return l_nReceiveData;
}

void PTApplicationCardPlugin::writeRegister(unsigned int pData, unsigned int pAddress)
{
	//qDebug()<<hex<< "Write Register"<<pAddress<<"Data:"<<pData;
    unsigned int *m_ptrWriteValues;
    m_ptrWriteValues = (unsigned int*)malloc(2*sizeof(unsigned int));
    tempAddr=pAddress;
    pAddress=baseAddr|tempAddr;
    m_ptrWriteValues[0] = pData;
    m_ptrWriteValues[1] = pAddress;
    write(m_nAppFD,m_ptrWriteValues,sizeof(m_ptrWriteValues));
    free(m_ptrWriteValues);
}

Q_EXPORT_PLUGIN2(IApplicationCardInterface, PTApplicationCardPlugin)
