#ifndef APPLICATIONCARDINTERFACE_H
#define APPLICATIONCARDINTERFACE_H


#include <QObject>
#include <appcardfunctiontemplate.h>
using namespace APPCARD_DETAILS;

class IApplicationCardInterface
{
    public:
    //[----------------- Memory Registers------------------------
	virtual void setDeviceName(APP_SLOTS)=0;
    virtual void enumerateAPPCard()=0;
    //----------------------------------------------------------]]

    //[[--------------------------System Registers---------------------------
    virtual unsigned int readAppCardCodeId()=0;
    virtual void writeScratchpad(unsigned int)=0;
    virtual unsigned int readScratchPad()=0;
    //------------------------------------------------------------------------

    //[[-------------------------- Drive Register ----------------------------
    virtual unsigned int basicTimeUnit(unsigned int)=0;
    virtual unsigned int basicDuration(unsigned int)=0;
    virtual void startDrive(unsigned int)=0;
    virtual void stopDrive()=0;
    virtual void setDrivePeriod(unsigned short)=0;
    virtual void setStartStop(unsigned short ,unsigned short)=0;
    virtual void setDrivePatternCount(bool,unsigned short)=0;
    //-----------------------------------------------------------------------]]
    //[[-------------------------- DDS Register-------------------------------
    virtual void setDDSCommandWord(bool)=0;
    virtual void setDDSFTW_MSW(unsigned short)=0;
    virtual void setDDSFTW_LSW(unsigned short)=0;
    virtual void setDDSPTW_MSW(unsigned short)=0;
    virtual void setDDSPTW_LSW(unsigned short)=0;
    virtual void setDDSWaveSelect(DDS_WAVESELECT pWaveSelect)=0;
    virtual void setDDSSawtooth(DDS_SAWTOOTH_REG pSawtooth)=0;
    virtual void setDDSDACDCdrive(unsigned short)=0;
    virtual void setDDSConfiguration1(DDSR1CONFIG pObjR1Configuration)=0;
    virtual void setDDSTWRAM()=0;
    //-----------------------------------------------------------------------]]
    //[[---------------------------------- SRAM Registers --------------------------------------------------
    virtual void setRAMADDR(unsigned short)=0;
    virtual void setDriveRAMData(unsigned short)=0;
    virtual void setReceiveRAMData(unsigned short)=0;
    virtual void setDriveRAMStarAddress(unsigned short)=0;
    virtual void setDriveRAMEndAddress(unsigned short)=0;
    virtual void setRAMModeAccess(RAMACCESS pbRamAccess)=0;

    virtual unsigned short int readDriveRAMData()=0;
    virtual unsigned short int readReceiveRAMData()=0;
    //----------------------------------------------------------------------------------------------------]]

    //[[------------------------------------ SPI Controllers -----------------------------------------------
    // SPI1 Controller
    virtual void setSPI1CommandWord(SPI1_CONFIGURATION m_stSPI1)=0;
    // SPI2 Constroller
    virtual void setSPI2CommandWord(SPI2_CONFIGURATION m_stSPI2)=0;
    // SPI3 Constroller
    virtual void setSPI3CommandWord(SPI3_CONFIGURATION m_stSPI3)=0;
    // SPI4 Constroller
    virtual void setSPI4CommandWord(SPI4_CONFIGURATION m_stSPI4)=0;
    // SPI5 Constroller
    virtual void setSPI5CommandWord(SPI5_CONFIGURATION m_stSPI5)=0;
    // SPI6 Constroller
    virtual void setSPI6CommandWord(SPI6_CONFIGURATION m_stSPI6)=0;

    virtual void setSPITXLSW(unsigned short pLSWData,SPI_SELECT peSPISelect)=0;
    virtual void setSPITXMSW(unsigned short pLSWData,SPI_SELECT peSPISelect)=0;
    virtual unsigned short getSPIRXLSW(SPI_SELECT peSPISelect)=0;
    virtual unsigned short getSPIRXMSW(SPI_SELECT peSPISelect)=0;


    virtual void setSPICW(unsigned short pCWData,SPI_SELECT peSPISelect)=0;
    virtual void setSPIClock(unsigned short pCLKData,SPI_SELECT peSPISelect)=0;
    virtual void setSPIAppendBit(unsigned short int)=0;

    virtual bool readSPIDriveDoneBit(SPI_SELECT peSPISelect)=0;
    //-----------------------------------------------------------------------------------------------------]]

    //[[-------------------------------------- Drive Relay Registers -----------------------------------------
    virtual void setDriveReceiveSourceSelect(DRSER  pstDRSER)=0;
    virtual void setDriveSourceAmplitudeRegister(DSAR pstDSAR)=0;
    virtual void setDriveReceiveGainRegister(DRGSR pstDRGRs)=0;
    virtual unsigned short int getDriveReceiveSourceSelect()=0;
    virtual unsigned short int getDriveSourceAmplitudeRegister()=0;
    virtual unsigned short int getDriveReceiveGainRegister()=0;
    //------------------------------------------------------------------------------------------------------]]

    //[[-------------------------------------- Receive Relay Registers ---------------------------------------
    virtual void setReceiversConfiguration(RECEIVER_CONF peReceConf,R1CR pSTReceiver1)=0;
    virtual void setICMRangeGain(ICMMGR pstICMConf)=0;
    virtual unsigned short int getReceiversConfiguration(RECEIVER_CONF peReceConf)=0;
    virtual unsigned short int getICMRangeGain()=0;
    //[[-------------------------------------- DSO Drive Registers--------------------------------------------
    virtual void setDSOBTUR(unsigned int)=0;
    virtual void setDSOBDR(unsigned int)=0;
    virtual void setDSOCR(bool)=0;
    virtual void setDSOMR()=0;
    virtual void setDSOTrigger(unsigned short int)=0;
    virtual void setDSOSampleCount(unsigned int)=0;
    virtual bool checkDSODriveDone()=0;
    virtual void setDSOPreCount(unsigned int)=0;
    virtual void setDSOPostCount(unsigned int)=0;

    //--------------------------------------------------------------------------------------------------------]]


    //[[-------------------------------------- DSO Receive FIFO Registers --------------------------------------
		virtual void setDSOReceiveFIFOConfiguration(DSO_RECEIVE_FIFO pselFIFO,bool,bool,bool)=0;
		virtual void setDSOReceiveFIFOMode(bool,bool)=0;
		virtual void setDSOReceiveFIFOODD_WR(unsigned short pOddData,DSO_RECEIVE_FIFO pselFIFO)=0;
		virtual unsigned short getDSOReceiveFIFOODD_RD(DSO_RECEIVE_FIFO pselFIFO)=0;
		virtual void setDSOReceiveFIFOEVEN_WR(unsigned short pEvenData,DSO_RECEIVE_FIFO pselFIFO)=0;
		virtual unsigned short getDSOReceiveFIFOEVEN_RD(DSO_RECEIVE_FIFO pselFIFO)=0;
      //--------------------------------------------------------------------------------------------------------]]



    //------------------------------------------------------------------------------------------------------]]
    virtual unsigned int readRegister(unsigned int)=0;
    virtual void writeRegister(unsigned int,unsigned int)=0;
};
Q_DECLARE_INTERFACE(IApplicationCardInterface,"pt.ApplicationCardInterface/1.0.0.1");

#endif // APPLICATIONCARDINTERFACE_H
