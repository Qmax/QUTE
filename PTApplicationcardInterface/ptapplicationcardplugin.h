#ifndef PTAPPLICATIONCARDPLUGIN_H
#define PTAPPLICATIONCARDPLUGIN_H

#include <ApplicationCardInterface.h>
#include <AppdeviceRegisterDetails.h>
#include <appcardfunctiontemplate.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <qdebug.h>
#include <AppdeviceRegisterDetails.h>
#include <QObject>
#include <QtCore>


//using namespace APPCARD_DETAILS;

class PTApplicationCardPlugin:public QObject,public IApplicationCardInterface
{
    Q_OBJECT
    Q_INTERFACES(IApplicationCardInterface)
public:
    //PTApplicationCardPlugin(QObject *parent = 0);
//            PTApplicationCardPlugin();
//            ~PTApplicationCardPlugin();

            //[----------------- Memory Registers------------------------
    		void setDeviceName(APP_SLOTS pSlotNo);
            void enumerateAPPCard();
            //----------------------------------------------------------]]

            //[[--------------------------System Registers---------------------------
            unsigned int readAppCardCodeId();
            void writeScratchpad(unsigned int);
            unsigned int readScratchPad();
            //------------------------------------------------------------------------

            //[[-------------------------- Drive Register ----------------------------
            unsigned int basicTimeUnit(unsigned int);
            unsigned int basicDuration(unsigned int);
            void startDrive(unsigned int);
            void stopDrive();
            void setDrivePeriod(unsigned short);
            void setStartStop(unsigned short ,unsigned short);
            void setDrivePatternCount(bool,unsigned short) ;
            //-----------------------------------------------------------------------]]
            //[[-------------------------- DDS Register-------------------------------
            void setDDSCommandWord(bool);
            void setDDSFTW_MSW(unsigned short);
            void setDDSFTW_LSW(unsigned short);
            void setDDSPTW_MSW(unsigned short);
            void setDDSPTW_LSW(unsigned short);
            void setDDSWaveSelect(DDS_WAVESELECT pWaveSelect);
            void setDDSSawtooth(DDS_SAWTOOTH_REG pSawtooth);
            void setDDSDACDCdrive(unsigned short);
            void setDDSConfiguration1(DDSR1CONFIG pObjR1Configuration);
            void setDDSTWRAM();
            //-----------------------------------------------------------------------]]
            //[[---------------------------------- SRAM Registers --------------------------------------------------
            void setRAMADDR(unsigned short);
            void setDriveRAMData(unsigned short);
            void setReceiveRAMData(unsigned short);
            void setDriveRAMStarAddress(unsigned short);
            void setDriveRAMEndAddress(unsigned short);
            void setRAMModeAccess(RAMACCESS pbRamAccess);
            unsigned short int readDriveRAMData();
            unsigned short int readReceiveRAMData();
            //----------------------------------------------------------------------------------------------------]]

            //[[------------------------------------ SPI Controllers -----------------------------------------------
            // SPI1 Controller
            void setSPI1CommandWord(SPI1_CONFIGURATION m_stSPI1);
            // SPI2 Constroller
            void setSPI2CommandWord(SPI2_CONFIGURATION m_stSPI2);
            // SPI3 Constroller
            void setSPI3CommandWord(SPI3_CONFIGURATION m_stSPI3);
            // SPI4 Constroller
            void setSPI4CommandWord(SPI4_CONFIGURATION m_stSPI4);
            // SPI5 Constroller
            void setSPI5CommandWord(SPI5_CONFIGURATION m_stSPI5);
            // SPI6 Constroller
            void setSPI6CommandWord(SPI6_CONFIGURATION m_stSPI6);

            void setSPITXLSW(unsigned short pLSWData,SPI_SELECT peSPISelect);
            void setSPITXMSW(unsigned short pLSWData,SPI_SELECT peSPISelect);
            unsigned short getSPIRXLSW(SPI_SELECT peSPISelect);
            unsigned short getSPIRXMSW(SPI_SELECT peSPISelect);

            void setSPICW(unsigned short pCWData,SPI_SELECT peSPISelect);
            void setSPIClock(unsigned short pCLKData,SPI_SELECT peSPISelect);
            void setSPIAppendBit(unsigned short int);

            bool readSPIDriveDoneBit(SPI_SELECT peSPISelect);
            //-----------------------------------------------------------------------------------------------------]]

            //[[-------------------------------------- Drive Relay Registers -----------------------------------------
            void setDriveReceiveSourceSelect(DRSER  pstDRSER);
            void setDriveSourceAmplitudeRegister(DSAR pstDSAR);
            void setDriveReceiveGainRegister(DRGSR pstDRGRs);
            unsigned short int getDriveReceiveSourceSelect();
            unsigned short int getDriveSourceAmplitudeRegister();
            unsigned short int getDriveReceiveGainRegister();

            //------------------------------------------------------------------------------------------------------]]

            //[[-------------------------------------- Receive Relay Registers ---------------------------------------
            void setReceiversConfiguration(RECEIVER_CONF peReceConf,R1CR pSTReceiver1);
            void setICMRangeGain(ICMMGR pstICMConf);

            unsigned short int getReceiversConfiguration(RECEIVER_CONF peReceConf);
            unsigned short int getICMRangeGain();


            //------------------------------------------------------------------------------------------------------]]
            unsigned int readRegister(unsigned int);
            void writeRegister(unsigned int,unsigned int);
            //[[-------------------------------------- DSO Drive Registers--------------------------------------------
            void setDSOBTUR(unsigned int);
            void setDSOBDR(unsigned int);
            void setDSOCR(bool);
            void setDSOMR();
            void setDSOTrigger(unsigned short int);
            void setDSOTriggerSource(RECEIVER_CONF,DSO_TRIGGER);
            void setDSOSampleCount(unsigned int);
            bool checkDSODriveDone();
            void setDSOPreCount(unsigned int);
            void setDSOPostCount(unsigned int);
            //--------------------------------------------------------------------------------------------------------]]
            //[[-------------------------------------- DSO Receive FIFO Registers --------------------------------------
            void setDSOReceiveFIFOConfiguration(DSO_RECEIVE_FIFO pselFIFO,bool,bool,bool);
            void setDSOReceiveFIFOMode(bool,bool);
            void setDSOReceiveFIFOODD_WR(unsigned short pOddData,DSO_RECEIVE_FIFO pselFIFO);
            unsigned short getDSOReceiveFIFOODD_RD(DSO_RECEIVE_FIFO pselFIFO);
            void setDSOReceiveFIFOEVEN_WR(unsigned short pEvenData,DSO_RECEIVE_FIFO pselFIFO);
            unsigned short getDSOReceiveFIFOEVEN_RD(DSO_RECEIVE_FIFO pselFIFO);

            //--------------------------------------------------------------------------------------------------------]]
        protected:
//            unsigned int *m_ptrWriteValues;
//            unsigned int *m_ptrReadValues;
            unsigned int tempAddr;
            unsigned int baseAddr;
            unsigned short m_nBasicTime,m_nBasicDuration,m_nSPIAppend;
            int m_nAppFD;
            const char *m_strdevice;
            QMap<int,const char*> mapDeviceString;


};

#endif // PTAPPLICATIONCARDPLUGIN_H
