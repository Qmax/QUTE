#ifndef IBACKPLANE_H
#define IBACKPLANE_H
#include "BackPlaneInterface.h"
#include <QObject>
#include <QtCore>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <emidevice.h>

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef struct {
    uint16_t address;
    uint8_t data[256];
    int dataLen;
    int type;
    uint8_t checksum;
} IHexRecord;
typedef struct {
    uint8_t data[256];
}row_struct;
typedef struct{
    row_struct data[128];
}row_data;

uint32_t getHexFileJtagID();
uint32_t getHexFileChecksum();
uint32_t getHexFileECC();
uint32_t getHexFileFlashData();

unsigned char GetDieTemperature(unsigned char*,unsigned char*);
unsigned char IsSpcIdle();

class IBackPlane:public QObject,public IntefaceBackPlane
{
	Q_OBJECT
	Q_INTERFACES(IntefaceBackPlane)
public:
	void InitializeBpObject();
	void writeBackPlaneRegister(unsigned int,unsigned int);
	unsigned int readBackPlaneRegister(unsigned int);
	void closeObject();
	unsigned int readBackPlaneCodeID();
	unsigned int writeScracthPAD(unsigned int);
	unsigned int readScratchPAD();
	unsigned short setBuzzerVolume(unsigned int,unsigned short,unsigned int);
	unsigned short setBuzzerTone(unsigned int,unsigned short,unsigned int);
	unsigned short setLCDControl(unsigned int,unsigned short,unsigned int);

	unsigned int initInterruptServiceRoutine();
	unsigned int setKnobCommandRegsiter(unsigned short);
	unsigned int readAngle();
	unsigned int readOtpLsb();
	unsigned int readOtpMsb();
	unsigned int getSPICodeID();
	unsigned int writeOtpLsb(unsigned short);
	unsigned int writeOtpMsb(unsigned short);
	unsigned int setTimer(unsigned short);
	unsigned int readInterruptStatus();
	unsigned int clearInterruptStatus(unsigned short);
	unsigned int enableInterruptRegister(unsigned short);
	unsigned int readInterruptSource();

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
	unsigned int WriteSPI(unsigned int,unsigned int,short int *);
	void writeSPIMemory(unsigned int,unsigned int,short int *);
	short int* ReadSPI(unsigned int,unsigned int);

     unsigned char enterPsocProgMode();
	 unsigned char configTargetDevice();
	 unsigned char verifyJtagID();
	 unsigned char eraseAll();
	 unsigned char prgDevConfigNVLatch();
	 unsigned char programFlash();
	 unsigned char verifyFlash();
	 unsigned char prgWrtOnceNVLatch();
	 unsigned char prgFlashProtectData();
	 unsigned char verifyFlashProtectData();
	 unsigned char validateChecksum();
	 unsigned char DPACC(unsigned int,unsigned int,unsigned int);
	 unsigned char APACC(unsigned int,unsigned int,unsigned int);
	 unsigned int  SWDREAD(unsigned int);
};
#endif // IBACKPLANE_H
