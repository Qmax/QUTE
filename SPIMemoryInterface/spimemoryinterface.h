#ifndef SPIMEMORYINTERFACE_H
#define SPIMEMORYINTERFACE_H

#include <QtCore>
#include <unistd.h>

#include "BackPlaneInterface.h"
#include "ApplicationCardInterface.h"
#include "PTSPIMemoryInterface.h"
#include "macros.h"



class SPIMemoryInterface : public QObject,public ISPIMemoryInterface {
    Q_OBJECT
    Q_INTERFACES(ISPIMemoryInterface)
public:
    SPIMemoryInterface(QObject *parent = 0);

    void accessSPIMemory(SPIMEMORY_ACCESS pSPISelect);
    void accessSPIRAM(RAM_MODE pSPIRAMSelect);
    unsigned int getSPICodeID();
    unsigned int checkMemoryBusy();
    unsigned int stopDrive();
    unsigned int writeEnable();
    unsigned int writeDisable();
    unsigned int bulkErase();
    void pageErase(unsigned int);
    unsigned int spiTxLsw(unsigned int);
    unsigned int spiTxMsw(unsigned int);
    unsigned int spiRxLsw();
    unsigned int spiRxMsw();
    unsigned int startTransmit();
    unsigned int startTransmit2();
    unsigned int startTx8Bit();
    unsigned int readSPIFile(unsigned int,unsigned int);
    unsigned int WriteSPI(unsigned int,unsigned int,unsigned short int *);
    void writeSPIMemory(unsigned int,unsigned int,unsigned short int *);
    unsigned short int* ReadSPI(unsigned int,unsigned int);

    // App Card System Memory
    unsigned short int* readAppCardSystemMemory(unsigned int pStartAddr, unsigned short pCount);
    void writeAppCardSystemMemory(unsigned int,unsigned int,unsigned short int *);
    void setHardwarwObject(IApplicationCardInterface* pobj);
    void SingleWriteAPPCardSRAM(unsigned int pgWraddr,unsigned short pData);
    unsigned short int SingleReadAPPCardSRAM(unsigned int pgRdAddr);
    void checkSPIMemoryWrite();
    void checkSPIMemoryRead();

    // Back Panel Systeme Memory
    unsigned short int* readBackPanelCardSystemMemory(unsigned int pStartAddr, unsigned short pCount);
    void writeBackPanelSystemMemory(unsigned int,unsigned int,unsigned short int *);

    // App Card Ram Memory

    void setAutoIncrement();
    void writeAppCardSRAM(unsigned int,unsigned int,unsigned short int *);
    unsigned short int* readAppCardSRAM(unsigned int pStartAddr, unsigned short pCount);
    void readAppCardSRAM(unsigned int pStartAddr, unsigned short pCount,bool pValue);
    void setSRAMPageSize(short int);
    void setReadCount(short int);


protected:
    IntefaceBackPlane *IBackPlane; ////BackPlaneInterfacePlugin
    IApplicationCardInterface *IAppCard; // AppcardPlugin
    SPIMEMORY_ACCESS m_MemorySelect;
    RAM_MODE m_RAMModeSelect;
    unsigned short int *m_npageRetlsw;


};

#endif // SPIMEMORYINTERFACE_H
