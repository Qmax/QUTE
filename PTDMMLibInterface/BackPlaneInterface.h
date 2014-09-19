#ifndef BACKPLANEINTERFACE_H
#define BACKPLANEINTERFACE_H
#include<QObject>
class IntefaceBackPlane
{
public:
        virtual void InitializeBpObject()=0;
        virtual void writeBackPlaneRegister(unsigned int,unsigned int)=0;
        virtual unsigned int readBackPlaneRegister(unsigned int)=0;
        virtual void closeObject()=0;
        virtual unsigned int readBackPlaneCodeID()=0;
        virtual unsigned int writeScracthPAD(unsigned int)=0;
        virtual unsigned int readScratchPAD()=0;
        virtual unsigned short setBuzzerVolume(unsigned int,unsigned short,unsigned int)=0;
        virtual unsigned short setBuzzerTone(unsigned int,unsigned short,unsigned int)=0;
        virtual unsigned short setLCDControl(unsigned int,unsigned short,unsigned int)=0;

        virtual unsigned int initInterruptServiceRoutine()=0;
        virtual unsigned int setKnobCommandRegsiter(unsigned short)=0;
        virtual unsigned int readAngle()=0;
        virtual unsigned int readOtpLsb()=0;
        virtual unsigned int readOtpMsb()=0;
        virtual unsigned int getSPICodeID()=0;
        virtual unsigned int writeOtpLsb(unsigned short)=0;
        virtual unsigned int writeOtpMsb(unsigned short)=0;
        virtual unsigned int setTimer(unsigned short)=0;
        virtual unsigned int readInterruptStatus()=0;
        virtual unsigned int clearInterruptStatus(unsigned short)=0;
        virtual unsigned int enableInterruptRegister(unsigned short)=0;
        virtual unsigned int readInterruptSource()=0;

        virtual unsigned int checkMemoryBusy()=0;
        virtual unsigned int stopDrive()=0;
        virtual unsigned int writeEnable()=0;
        virtual unsigned int writeDisable()=0;
        virtual unsigned int bulkErase()=0;
        virtual void pageErase(unsigned int)=0;
        virtual unsigned int spiTxLsw(unsigned int)=0;
        virtual unsigned int spiTxMsw(unsigned int)=0;
        virtual unsigned int spiRxLsw()=0;
        virtual unsigned int spiRxMsw()=0;
        virtual unsigned int startTransmit()=0;
        virtual unsigned int startTransmit2()=0;
        virtual unsigned int startTx8Bit()=0;
        virtual unsigned int readSPIFile(unsigned int,unsigned int)=0;
        virtual unsigned int WriteSPI(unsigned int,unsigned int,short int *)=0;
        virtual void writeSPIMemory(unsigned int,unsigned int,short int *)=0;
        virtual short int* ReadSPI(unsigned int,unsigned int)=0;

        virtual unsigned char enterPsocProgMode()=0;
        virtual unsigned char configTargetDevice()=0;
        virtual unsigned char verifyJtagID()=0;
        virtual unsigned char eraseAll()=0;
        virtual unsigned char prgDevConfigNVLatch()=0;
        virtual unsigned char programFlash()=0;
        virtual unsigned char verifyFlash()=0;
        virtual unsigned char prgWrtOnceNVLatch()=0;
        virtual unsigned char prgFlashProtectData()=0;
        virtual unsigned char verifyFlashProtectData()=0;
        virtual unsigned char validateChecksum()=0;
        virtual unsigned char DPACC(unsigned int,unsigned int,unsigned int)=0;
        virtual unsigned char APACC(unsigned int,unsigned int,unsigned int)=0;
        virtual unsigned int  SWDREAD(unsigned int)=0;

};
Q_DECLARE_INTERFACE(IntefaceBackPlane,"pt.backplaneInterface/1.0.0.1");
#endif // BACKPLANEINTERFACE_H
