#ifndef PTSPIMEMORYINTERFACE_H
#define PTSPIMEMORYINTERFACE_H
#include <QObject>
#include "ApplicationCardInterface.h"
enum SPIMEMORY_ACCESS
	{
		BACKPLANE,
		APPLICATIONCARD
	};
enum RAM_MODE
{
	DRIVERAM,
	RECEIVERAM
};
class ISPIMemoryInterface{
public:
    virtual unsigned int getSPICodeID()=0;
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
    virtual unsigned int WriteSPI(unsigned int,unsigned int,unsigned short int *)=0;
    virtual void writeSPIMemory(unsigned int,unsigned int,unsigned short int *)=0;
    virtual unsigned short int* ReadSPI(unsigned int,unsigned int)=0;
    virtual void accessSPIMemory(SPIMEMORY_ACCESS pSPISelect)=0;
    virtual void accessSPIRAM(RAM_MODE)=0;

    // Reading Appcard Systme Memory Sequency
    virtual void setHardwarwObject(IApplicationCardInterface*)=0;
    virtual unsigned short int* readAppCardSystemMemory(unsigned int , unsigned short )=0;
    virtual void writeAppCardSystemMemory(unsigned int,unsigned int,unsigned short int *)=0;
    virtual void SingleWriteAPPCardSRAM(unsigned int,unsigned short)=0;
    virtual unsigned short int SingleReadAPPCardSRAM(unsigned int pgRdAddr)=0;
    // Back Panel Systeme Memory
    virtual unsigned short int* readBackPanelCardSystemMemory(unsigned int, unsigned short)=0;
    virtual void writeBackPanelSystemMemory(unsigned int,unsigned int,unsigned short int *)=0;

    // App Card Ram Memory

    virtual void setAutoIncrement()=0;
    virtual void writeAppCardSRAM(unsigned int,unsigned int,unsigned short int *)=0;
    virtual unsigned short int* readAppCardSRAM(unsigned int pStartAddr, unsigned short pCount)=0;
    virtual void readAppCardSRAM(unsigned int pStartAddr, unsigned short pCount,bool pValue)=0;
    virtual void checkSPIMemoryWrite()=0;
    virtual void checkSPIMemoryRead()=0;
};
Q_DECLARE_INTERFACE(ISPIMemoryInterface,"pt.spimemoryInterface/1.0.0.1");
#endif // PTSPIMEMORYINTERFACE_H
