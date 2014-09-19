#include "ibackplane.h"

char *whoami = "default";
static const char *device = "/dev/emibckp";
int g_nBackplaneFD;
IBackPlane	obj_IBackPlane;
row_struct row_no[128];

void IBackPlane::InitializeBpObject() {
	g_nBackplaneFD = open(device, O_RDWR);
	if (g_nBackplaneFD < 0) {
		printf("Can't open device for backplane communication.\n");
		close(g_nBackplaneFD);
		//return 0;
	}
	//qDebug() << "~~~~~~~~~~Backplane Interface Opened~~~~~~~~~~~";
	//return 1;
}

void IBackPlane::closeObject() {
	close(g_nBackplaneFD);
	qDebug() << "~~~~~~~~~~Back Panel Interface Closed~~~~~~~~~~~";
}
void IBackPlane::writeBackPlaneRegister(unsigned int pData,
		unsigned int pAddress) {
	unsigned int *ptrWriteValues;
	ptrWriteValues = (unsigned int*) malloc(2 * sizeof(unsigned int));
	ptrWriteValues[0] = pData;
	ptrWriteValues[1] = pAddress;
	write(g_nBackplaneFD, ptrWriteValues, sizeof(ptrWriteValues));
	free(ptrWriteValues);
}

unsigned int IBackPlane::readBackPlaneRegister(unsigned int pAddress) {
	unsigned int *ptrReadValues;
	unsigned int l_nReceiveData = 0;
	ptrReadValues = (unsigned int*) malloc(1 * sizeof(unsigned int));
	ptrReadValues[0] = pAddress;
	l_nReceiveData = read(g_nBackplaneFD, ptrReadValues, sizeof(ptrReadValues));
	free(ptrReadValues);
	return l_nReceiveData;
}

unsigned int IBackPlane::readBackPlaneCodeID() {
	return readBackPlaneRegister(BP_CR);
}

unsigned int IBackPlane::writeScracthPAD(unsigned int pData) {
	writeBackPlaneRegister(pData, BP_SPR);
	return 1;
}

unsigned int IBackPlane::readScratchPAD() {
	return readBackPlaneRegister(BP_SPR);
}

unsigned short IBackPlane::setBuzzerVolume(unsigned int pFrequency,	unsigned short pPWMFlag, unsigned int pPercentage) {
	/* The value in this register can be used to specify the duty cycle of PWM Signal. the count value can be calculated by below sequence.*/

	double l_nTime = 0.0;
	unsigned int l_nPeriodCounts = 0, l_nPercentage = pPercentage,
			l_nDutycyclecount = 0, l_nPWMValue = BP_BVCER_ENABLE_PERIOD;

	l_nTime = (double) (1.0 / pFrequency);
	printf("Time %f\n", l_nTime);
	l_nPeriodCounts = l_nTime * 50000; /* Period Count Value 50ms*/
	l_nDutycyclecount = (l_nPeriodCounts / 100) * l_nPercentage; /*Duty Cycle Count */
	printf("setBuzzerVolume DutyCycle Count... %x\n", l_nDutycyclecount);
	writeBackPlaneRegister(l_nPeriodCounts, BP_BVCPR); /* Buzzer volume control period register*/
	writeBackPlaneRegister(l_nDutycyclecount, BP_BVCDCR); /* Buzzer volume control duty cycle register*/

	if (pPWMFlag == 1) {
		l_nPWMValue |= BP_BVCER_ENABLE_PWM;
	}
	writeBackPlaneRegister(l_nPWMValue, BP_BVCER); /* Buzzer volume control Enable Register */

	return 1;
}

unsigned short IBackPlane::setBuzzerTone(unsigned int pFrequency,unsigned short pPWMFlag, unsigned int pPercentage) {
	/* The value in this register can be used to specify the duty cycle of PWM Signal. the count value can be calculated by below sequence.*/

	double l_nTime = 0.0;
	unsigned int l_nPeriodCounts = 0, l_nPercentage = pPercentage,
			l_nDutycyclecount = 0, l_nPWMValue = BP_BTCER_ENABLE_PERIOD;
	l_nTime = (double) (1.0 / pFrequency);
	printf("Time %f\n", l_nTime);
	l_nPeriodCounts = l_nTime * 50000; /* Period Count Value 50ms*/
	l_nDutycyclecount = ((double) l_nPeriodCounts / 100) * l_nPercentage; /*Duty Cycle Count */
	printf("setBuzzerTone DutyCycle Count... %x\n", l_nDutycyclecount);
	writeBackPlaneRegister(l_nPeriodCounts, BP_BTCPR); /* Buzzer tone control period register*/
	writeBackPlaneRegister(l_nDutycyclecount, BP_BTCDCR); /* Buzzer tone control duty cycle register*/

	if (pPWMFlag == 1) {
		l_nPWMValue |= BP_BTCER_ENABLE_PWM;
	}
	printf("PWM value %d\n", l_nPWMValue);
	writeBackPlaneRegister(l_nPWMValue, BP_BTCER); /* Buzzer tone control Enable Register */

	return 1;
}

unsigned short IBackPlane::setLCDControl(unsigned int pFrequency,
		unsigned short pPWMFlag, unsigned int pPercentage) {
	/* The value in this register can be used to specify the duty cycle of PWM Signal. the count value can be calculated by below sequence.*/

	double l_nTime = 0.0;
	unsigned int l_nPeriodCounts = 0, l_nPercentage = pPercentage,
			l_nDutycyclecount = 0, l_nPWMValue = BP_LBER_ENABLE_PERIOD;

	l_nTime = (double) (1.0 / pFrequency);

	l_nPeriodCounts = (l_nTime * 50000) - 1; /* Period Count Value */
	printf("l_nPeriodCounts value %d\n", l_nPeriodCounts);
	l_nDutycyclecount = (((double) l_nPeriodCounts / 100) * l_nPercentage) - 1; /*Duty Cycle Count */
	printf("l_nDutycyclecount value %d\n", l_nDutycyclecount);

	writeBackPlaneRegister(l_nPeriodCounts, BP_LBCPR); /* LCD Backlight control period register*/
	writeBackPlaneRegister(l_nDutycyclecount, BP_LBCDCR); /* LCD Backlight control duty cycle register*/

	if (pPWMFlag == 1) {
		l_nPWMValue |= BP_LBER_ENABLE_PWM;
		printf("PWM value %d\n", l_nPWMValue);
	}
	writeBackPlaneRegister(l_nPWMValue, BP_LBER); /* LCD Backlight control Enable Register */

	return 1;
}

unsigned int IBackPlane::initInterruptServiceRoutine() {
	writeBackPlaneRegister(0xFFF, BP_ISCR); /*Clear all Interrupts*/
	writeBackPlaneRegister(0x800, BP_IER); /*Enable int0 Interrupt*/
	writeBackPlaneRegister(0x01, BP_IGER); /*Enable Interrupt Source*/
	writeBackPlaneRegister(0x3FF, BP_KLTR); /*Interval Value*/
	return 1;
}

unsigned int IBackPlane::setKnobCommandRegsiter(unsigned short pData) {
	writeBackPlaneRegister(pData, BP_KCR);
	return 1;
}

unsigned int IBackPlane::writeOtpLsb(unsigned short pData) {
	writeBackPlaneRegister(pData, BP_KLSWR);
	return 1;
}
unsigned int IBackPlane::writeOtpMsb(unsigned short pData) {
	writeBackPlaneRegister(pData, BP_KMSWR);
	return 1;
}

unsigned int IBackPlane::readOtpLsb() {
	return readBackPlaneRegister(BP_KLSWR);
}

unsigned int IBackPlane::readOtpMsb() {
	return readBackPlaneRegister(BP_KMSWR);
}

unsigned int IBackPlane::setTimer(unsigned short pData) {
	writeBackPlaneRegister(pData, BP_KLTR);
	return 1;
}

unsigned int IBackPlane::readAngle() {
	return readBackPlaneRegister(BP_KLSWR);
}

unsigned int IBackPlane::readInterruptStatus() {
	return readBackPlaneRegister(BP_ISCR);
}

unsigned int IBackPlane::clearInterruptStatus(unsigned short pData) {
	writeBackPlaneRegister(pData, BP_ISCR);
	return 1;
}

unsigned int IBackPlane::enableInterruptRegister(unsigned short pData) {
	writeBackPlaneRegister(pData, BP_IER);
	return 1;
}

unsigned int IBackPlane::readInterruptSource() {
	return readBackPlaneRegister(BP_ISDR);
}
///////////////////////////////////////////

/*
 * SPI Memory Sequence....................
 */

unsigned int IBackPlane::getSPICodeID() {
	writeBackPlaneRegister(0x9F00, BP_SPIFLASH_TXMSW);
	writeBackPlaneRegister(0x0000, BP_SPIFLASH_TXLSW);
	writeBackPlaneRegister(0x0007, BP_SPIFLASH_CMD);

	checkMemoryBusy();
	unsigned int l_nData = 0x00FFFFFF&readBackPlaneRegister(BP_SPIFLASH_RXMSW);
//	printf("MSW DATA:%X\n", l_nData);
	l_nData = l_nData << 16;
	l_nData |= readBackPlaneRegister(BP_SPIFLASH_RXLSW);
//	printf("LSW DATA:%X\n", l_nData);
	return l_nData;
}
unsigned int IBackPlane::checkMemoryBusy() {
	while (readBackPlaneRegister(BP_SPIFLASH_CMD) & 0x0001);
	return 1;
}

unsigned int IBackPlane::stopDrive() {
	writeBackPlaneRegister(0x60, BP_SPIFLASH_CMD);
	return 1;
}
unsigned int IBackPlane::writeEnable() {
	writeBackPlaneRegister(0x06, BP_SPIFLASH_TXLSW);
	writeBackPlaneRegister(0x01, BP_SPIFLASH_CMD);
	checkMemoryBusy();
	return 1;
}
unsigned int IBackPlane::writeDisable() {
	writeBackPlaneRegister(0x04, BP_SPIFLASH_TXLSW);
	writeBackPlaneRegister(0x01, BP_SPIFLASH_CMD);
	checkMemoryBusy();
	return 1;
}
unsigned int IBackPlane::bulkErase() {
	writeEnable();
	writeBackPlaneRegister(0xC7, BP_SPIFLASH_TXLSW);
	writeBackPlaneRegister(0x01, BP_SPIFLASH_CMD);
	checkMemoryBusy();
	usleep(100000);
	writeDisable();
	sleep(10); // sleep(25);
	return 1;
}
unsigned int IBackPlane::spiTxLsw(unsigned int pData) {
	writeBackPlaneRegister(pData, BP_SPIFLASH_TXLSW);
	return 1;
}
unsigned int IBackPlane::spiTxMsw(unsigned int pData) {
	writeBackPlaneRegister(pData, BP_SPIFLASH_TXMSW);
	return 1;
}
unsigned int IBackPlane::spiRxLsw() {
	readBackPlaneRegister(BP_SPIFLASH_RXLSW);
	return 1;
}
unsigned int IBackPlane::spiRxMsw() {
	readBackPlaneRegister(BP_SPIFLASH_RXMSW);
	return 1;
}
unsigned int IBackPlane::startTransmit() {
	writeBackPlaneRegister(0x47, BP_SPIFLASH_CMD);
	return 1;
}
unsigned int IBackPlane::startTransmit2() {
	writeBackPlaneRegister(0x41, BP_SPIFLASH_CMD);
	return 1;
}
unsigned int IBackPlane::readSPIFile(unsigned int pAddress, unsigned int pBytes) {
	//        FILE *l_nFD;
	//    unsigned int l_nFileData=0;
	//    l_nFD = fopen(DFIFORECEIVE,"w");
	//    if(l_nFD == 0)
	//        printf("File I/O error\n");
	//    unsigned int l_nIndex=0;
	//    while(l_nIndex < pCount)
	//    {
	//        if(pValue == 0)
	//                l_nFileData = g_nobjBackplaneqt->readBackPlane(APPCARD_RECV_RFIFOR1)&0xFF;
	//        if(pValue == 1)
	//                l_nFileData =g_nobjBackplaneqt->readBackPlane(APPCARD_RECV_RFIFOR2)&0xFF;
	//        fprintf(l_nFD,"%X\n",l_nFileData);
	//        l_nIndex++;
	//    }
	//    fclose(l_nFD);

	//    int pFlag =0;
	//                pCount=3;
	FILE *l_nFD;
	unsigned int l_nFileData[128], pFlag = 0;
	l_nFD = fopen("./data.txt", "r");
	if (l_nFD == 0)
		printf("File I/O error\n");
	//                unsigned int l_nIndex=0;
	//                       for (; !feof(l_nFD);)
	unsigned int i;
	for (i = pAddress; i <= pBytes; i++) {
		printf("Drive Started...\n");
		fscanf(l_nFD, "%x", &l_nFileData[i]);
		printf("file data %x\n", l_nFileData[i]);
		printf("Drive Started...\n");
	}
	//                   l_nIndex = l_nIndex + 1;
	//                }
	fclose(l_nFD);
	printf("Drive Completed.\n");
	//return
}
unsigned int IBackPlane::startTx8Bit() {
	writeBackPlaneRegister(0x49, BP_SPIFLASH_CMD);
	return 1;
}

void IBackPlane::writeSPIMemory(unsigned int pnWraddr, unsigned int pnBytes,
		short int *pnData) {
	unsigned int l_npageWrLsw, l_npageWrMsw, l_npageWrite, l_nLoopIndex;
	short int *l_nWriteData = pnData;
	unsigned int l_nTemp, l_nSpiBusy;

	// Taking Starting address of the page.
	unsigned int l_nDiffBytes;
	l_nDiffBytes = pnWraddr & 0xFF;
	l_nDiffBytes = 0xFF - l_nDiffBytes;
//	qDebug() << "Difference Bytes:" << hex<<l_nDiffBytes;
//	qDebug() << "Starting Address:" << hex<<pnWraddr;
	if (l_nDiffBytes >= pnBytes) {
		writeEnable();
		l_npageWrite = 0x0A000000 | pnWraddr;
		l_npageWrLsw = l_npageWrite & 0x0000FFFF;
		l_npageWrMsw = (l_npageWrite & 0xFFFF0000) >> 16;
		writeBackPlaneRegister(l_npageWrLsw, BP_SPIFLASH_TXLSW);
		writeBackPlaneRegister(l_npageWrMsw, BP_SPIFLASH_TXMSW);
		writeBackPlaneRegister(0x47, BP_SPIFLASH_CMD); //start transmission,32bit drive
		usleep(1000);
		l_nSpiBusy = checkMemoryBusy();
		for (l_nLoopIndex = 0; l_nLoopIndex < pnBytes; l_nLoopIndex++) {
			//qDebug() <<"Index:"<<l_nLoopIndex<<"Write Data 0:" << l_nWriteData[l_nLoopIndex];
			writeBackPlaneRegister(l_nWriteData[l_nLoopIndex],
					BP_SPIFLASH_TXLSW);
			writeBackPlaneRegister(0x41, BP_SPIFLASH_CMD); //start transmission
			l_nSpiBusy = checkMemoryBusy();
		}
		stopDrive();
		writeDisable();
		usleep(50000);
	} else {
		l_nTemp = pnBytes;
		pnBytes = l_nDiffBytes; // Write the Left out Bytes
		writeEnable();
		l_npageWrite = 0x0A000000 | pnWraddr;
		l_npageWrLsw = l_npageWrite & 0x0000FFFF;
		l_npageWrMsw = (l_npageWrite & 0xFFFF0000) >> 16;
		writeBackPlaneRegister(l_npageWrLsw, BP_SPIFLASH_TXLSW);
		writeBackPlaneRegister(l_npageWrMsw, BP_SPIFLASH_TXMSW);
		writeBackPlaneRegister(0x47, BP_SPIFLASH_CMD); //start transmission,32bit drive
		usleep(1000);
		l_nSpiBusy = checkMemoryBusy();
		for (l_nLoopIndex = 0; l_nLoopIndex <= pnBytes; l_nLoopIndex++) {
			//qDebug() <<"Index:"<<l_nLoopIndex<<"Write Data 1:" << l_nWriteData[l_nLoopIndex];
			writeBackPlaneRegister(l_nWriteData[l_nLoopIndex],
					BP_SPIFLASH_TXLSW);
			writeBackPlaneRegister(0x41, BP_SPIFLASH_CMD); //start transmission
			l_nSpiBusy = checkMemoryBusy();
		}
		stopDrive();
		writeDisable();
		usleep(50000);
		l_npageWrite = l_npageWrite + l_nDiffBytes;
		l_npageWrite++;
		//qDebug() << "Starting Address:" << l_npageWrite;
		writeEnable();
		pnBytes = l_nTemp;
		l_npageWrLsw = l_npageWrite & 0x0000FFFF;
		l_npageWrMsw = (l_npageWrite & 0xFFFF0000) >> 16;
		writeBackPlaneRegister(l_npageWrLsw, BP_SPIFLASH_TXLSW);
		writeBackPlaneRegister(l_npageWrMsw, BP_SPIFLASH_TXMSW);
		writeBackPlaneRegister(0x47, BP_SPIFLASH_CMD); //start transmission,32bit drive
		usleep(1000);
		l_nSpiBusy = checkMemoryBusy();
		for (l_nLoopIndex = l_nDiffBytes + 1; l_nLoopIndex < pnBytes; l_nLoopIndex++) {
			//qDebug() <<"Index:"<<l_nLoopIndex<<"Write Data 2:" << l_nWriteData[l_nLoopIndex];
			writeBackPlaneRegister(l_nWriteData[l_nLoopIndex],
					BP_SPIFLASH_TXLSW);
			writeBackPlaneRegister(0x41, BP_SPIFLASH_CMD); //start transmission
			l_nSpiBusy = checkMemoryBusy();
		}
		stopDrive();
		writeDisable();
		usleep(50000);
	}
	stopDrive();
}

unsigned int IBackPlane::WriteSPI(unsigned int pgWraddr, unsigned int l_nBytes,
		short int *l_nWriteData) {
	unsigned int l_npageWrLsw, l_npageWrMsw, l_npageWrite, l_nSpiBusy, a;
	short int *l_ndataWr;
	l_ndataWr = l_nWriteData;
	l_npageWrite = 0x0A000000 | pgWraddr;
	printf("page write %x\n", l_npageWrite);
	l_npageWrLsw = l_npageWrite & 0x0000FFFF;
	printf("page writelsw %x\n", l_npageWrLsw);
	l_npageWrMsw = (l_npageWrite & 0xFFFF0000) >> 16;
	printf("page writemsw %x\n", l_npageWrMsw);
	writeBackPlaneRegister(l_npageWrLsw, BP_SPIFLASH_TXLSW);
	writeBackPlaneRegister(l_npageWrMsw, BP_SPIFLASH_TXMSW);
	writeBackPlaneRegister(0x47, BP_SPIFLASH_CMD); //start transmission,32bit drive
	usleep(1000);
	l_nSpiBusy = checkMemoryBusy();
	//printf("Check busy  %x\n",l_nSpiBusy);
	for (a = 0; a < l_nBytes; a++) {
		//printf("data value %x\n",l_ndataWr[a]);
		writeBackPlaneRegister(l_ndataWr[a], BP_SPIFLASH_TXLSW);
		writeBackPlaneRegister(0x41, BP_SPIFLASH_CMD); //start transmission
		//l_ndataWr++;
		l_nSpiBusy = checkMemoryBusy();
		//printf("Check busy  %x\n",l_nSpiBusy);
	}
	stopDrive();
	writeDisable();
	usleep(500000);
	return 1;
}
void IBackPlane::pageErase(unsigned int pgErAddr) {
	unsigned int l_npageErase = 0, l_npageErLsw = 0, l_npageErMsw = 0;
	l_npageErase = 0xDB000000 | pgErAddr;
	l_npageErLsw = l_npageErase & 0x0000FFFF;
	l_npageErMsw = (l_npageErase & 0xFFFF0000) >> 16;
	writeEnable();
	writeBackPlaneRegister(l_npageErMsw, BP_SPIFLASH_TXMSW);
	writeBackPlaneRegister(l_npageErLsw, BP_SPIFLASH_TXLSW);
	writeBackPlaneRegister(0x07, BP_SPIFLASH_CMD);
	checkMemoryBusy();
	usleep(50000);
	writeDisable();
	printf("Page Erased\n");
}
short int* IBackPlane::ReadSPI(unsigned int pgRdaddr, unsigned int bytes) {

	unsigned int l_npageRead, l_npageRdLsw, l_npageRdMsw, l_nSpi1Busy;
	short int *l_npageRetlsw;
	int b;
	//scanf("%d",&bytes);
	l_npageRetlsw = new short int[bytes];
	l_npageRead = 0x03000000 | pgRdaddr;
//	printf("page Read %x\n", l_npageRead);
	l_npageRdLsw = l_npageRead & 0x0000FFFF;
//	printf("page Read LSW%x\n", l_npageRdLsw);
	l_npageRdMsw = (l_npageRead & 0xFFFF0000) >> 16;
//	printf("page Read MSW%x\n", l_npageRdMsw);
	writeBackPlaneRegister(l_npageRdLsw, BP_SPIFLASH_TXLSW);
	writeBackPlaneRegister(l_npageRdMsw, BP_SPIFLASH_TXMSW);
	writeBackPlaneRegister(0x47, BP_SPIFLASH_CMD);
	usleep(10000);
	l_nSpi1Busy = checkMemoryBusy();
	//printf("Check busy  %x\n",l_nSpi1Busy);
	for (b = 0; b < bytes; b++) {
		writeBackPlaneRegister(0x49, BP_SPIFLASH_CMD);
		usleep(1000);
		l_nSpi1Busy = checkMemoryBusy();
		//printf("Check busy  %x\n",l_nSpi1Busy);
		l_npageRetlsw[b] = readBackPlaneRegister(BP_SPIFLASH_RXLSW) & 0x00FF;
		//printf("page readlsw  %x\n",l_npageRetlsw[b]);
	}
	stopDrive();
	return &l_npageRetlsw[0];
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PSOC Programming~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

uint32_t getHexFileJtagID(){
    QString readData;
    bool ok=true;
    bool DeviceIdDetected = false;
    IHexRecord MetaData;
    uint32_t JtagId;

    QFile file("flash2.hex");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"Error";
    QTextStream in(&file);

    while (!((readData =in.readLine()).isNull()))
    {
        if (DeviceIdDetected == true)          {
            MetaData.dataLen=readData.mid(1,2).toUInt(&ok,16);
            for(int loop=0,start=9;loop<MetaData.dataLen;loop++,start++)
                MetaData.data[loop]=readData.mid(start+loop,2).toUInt(&ok,16);
            JtagId=(MetaData.data[2]<<24)|(MetaData.data[3]<<16)|(MetaData.data[4]<<8)|(MetaData.data[5]);
            DeviceIdDetected = false;
            break;
        }
        if (readData == ":0200000490501A")
            DeviceIdDetected = true;
    }
    return JtagId;
}

uint32_t getHexFileChecksum(){
    QString readData;
    bool ok=true;
    bool DeviceIdDetected = false;
    IHexRecord HexData;
    uint32_t checkSum;

    QFile file("flash2.hex");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"Error";
    QTextStream in(&file);

    while (!((readData =in.readLine()).isNull()))
    {
        if (DeviceIdDetected == true)          {
            HexData.dataLen=readData.mid(1,2).toUInt(&ok,16);
            for(int loop=0,start=9;loop<HexData.dataLen;loop++,start++)
                HexData.data[loop]=readData.mid(start+loop,2).toUInt(&ok,16);
            checkSum=(HexData.data[0]<<8)|(HexData.data[1]);
            DeviceIdDetected = false;
            break;
        }
        if (readData == ":0200000490303A")
            DeviceIdDetected = true;
    }
    return checkSum;
}
uint32_t getHexFileECC(){
    QString readData;
    bool ok=true;
    bool DeviceIdDetected = false;
    IHexRecord HexData;
    uint32_t ErrorCC;

    QFile file("flash2.hex");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"Error";
    QTextStream in(&file);

    while (!((readData =in.readLine()).isNull()))
    {
        if (DeviceIdDetected == true)          {
            HexData.dataLen=readData.mid(1,2).toUInt(&ok,16);
            for(int loop=0,start=9;loop<HexData.dataLen;loop++,start++)
                HexData.data[loop]=readData.mid(start+loop,2).toUInt(&ok,16);
            ErrorCC=(HexData.data[3]);
            DeviceIdDetected = false;
            break;
        }
        if (readData == ":0200000490006A")
            DeviceIdDetected = true;
    }
    return ErrorCC;
}
uint32_t getHexFileFlashData(){
    QString readData;
    bool ok=true;
    bool DeviceIdDetected = false;
    IHexRecord MetaData;
    uint32_t  JtagId;
//    row_struct row_no[128];

    QFile file("flash2.hex");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"Error";
    QTextStream in(&file);

    int serial=0,row=0;

    while (!((readData =in.readLine()).isNull()))
    {

         MetaData.dataLen=readData.mid(1,2).toUInt(&ok,16);
         MetaData.address=readData.mid(3,4).toUInt(&ok,16);
         MetaData.type=readData.mid(7,2).toUInt(&ok,16);
         MetaData.checksum=readData.right(2).toUInt(&ok,16);

         if(MetaData.type==0x04) break;

        if (MetaData.address>=0x0000&&MetaData.address<=0x7FFF) {
//            qDebug("Data Length :%0.2X",MetaData.dataLen);
//            qDebug("Data Type:%0.2X",MetaData.type);
//            qDebug("Data Address:%0.4X",MetaData.address);
//            qDebug("Checksum:%0.2X",MetaData.checksum);
//             qDebug()<<"Data:";

             for(int loop=0,start=9;loop<MetaData.dataLen;loop++,start++)
               MetaData.data[loop]=readData.mid(start+loop,2).toUInt(&ok,16);

             for(int i=0;i<MetaData.dataLen;i++ ){
              //qDebug("row-%d,byte-%d. %0.2X ",row,serial,MetaData.data[i]);
               row_no[row].data[serial]=MetaData.data[i];

               if(serial==255) {
                   serial=0;
                   row++;
               }
                else
                    serial++;

           }
         }
    }
/*
    for(int j=0;j<128;j++){
        qDebug()<<"row :"<<j;
        for(int i=0;i<256;i++)
            qDebug(" %0.2X ",row_no[j].data[i]);
    }
*/

    return 0;
}
unsigned int IBackPlane::SWDREAD(unsigned int _CMD) {
	unsigned int readCMD, chkBusy, chkAck, ackLoop;
	unsigned int readLSB, readMSB;

	readCMD = chkBusy = chkAck = ackLoop = 0;
	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nSWD read Command failed %d times!!!!\n", ackLoop- 1);
			return 0;
		}
		writeBackPlaneRegister(_CMD, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
		} while (chkBusy == 0x0000);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	readLSB = readBackPlaneRegister(PSOC_RLSW);
	readMSB = readBackPlaneRegister(PSOC_RMSW);

	unsigned int temp = (((readMSB | 0x00000000) << 16) | readLSB);

//	qDebug() << "readData:" << hex << temp << "readLSB:" << hex << readLSB
//			<< "readMSB:" << hex << readMSB;

	return temp;
}
unsigned char IBackPlane::DPACC(unsigned int _CMD, unsigned int _MSB,
		unsigned int _LSB) {
	if (APACC(_CMD, _MSB, _LSB) == 1)
		return 1;
	else
		return 0;
}
unsigned char IBackPlane::APACC(unsigned int _CMD, unsigned int _MSB,
		unsigned int _LSB) {

	unsigned int readCMD, chkBusy, chkAck, ackLoop;

	readCMD = chkBusy = chkAck = ackLoop = 0;
	writeBackPlaneRegister(_MSB, PSOC_WMSW);
	writeBackPlaneRegister(_LSB, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nAPACC/DPACC Command failed %d times at %s !!!!\n",
					ackLoop - 1, whoami);
			return 0;
		}
		writeBackPlaneRegister(_CMD, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
		} while (chkBusy == 0);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);
	return 1;

}

unsigned char IBackPlane::enterPsocProgMode() {
	/*
	 //Write Port Acquire key, Use SWD ADDR = 2’b11
	 writeBackPlaneRegister(0x0000,0x0034);	//XRES
	 if(DPACC(READBUFF,0x7B0C,0x06DB)==1){

	 // Address of the Test mode key register
	 if(APACC(TRNS_ADDR,0x0005,0x0210)==1){

	 // Write 32-bit test mode key
	 if(APACC(DATA_WR,0xEA7E,0x30A9)==1){
	 return 1;
	 }
	 }
	 }
	 else
	 return 0;*/

	unsigned int readCMD, chkBusy, chkAck, ackLoop;
	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0x8002, 0x003E);//clock selection(8002->1.666MHz)

	writeBackPlaneRegister(0X7B0C, PSOC_WMSW);	//SWD TXMSW Register
	writeBackPlaneRegister(0X06DB, PSOC_WLSW);  //SWD TXLSW Register
	writeBackPlaneRegister(0X0000, PSOC_CMD); //XReset
	usleep(1);
	writeBackPlaneRegister(0X0001, PSOC_CMD); //Bus Reset

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nAcquire Port failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(READBUFF, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0X0005, PSOC_WMSW);
	writeBackPlaneRegister(0X0210, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nTest Address Drive failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(0X0011, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
		} while (chkBusy == 0);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0XEA7E, PSOC_WMSW);
	writeBackPlaneRegister(0X30A9, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nTest Data Drive failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(0X0015, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/* Setting DP configuration register for one-byte access. */
	//	DPACC(DPGPRT_CFG,0x0000,0x0000);

	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0x0000, PSOC_WMSW);
	writeBackPlaneRegister(0X0000, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf(
					"\nSetting DP configuration register for one-byte access failed %d times!!!!\n",
					ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(DPGPRT_CFG, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	// Halt CPU, Enable Debug-on-chip (DoC) access
	//	APACC(TRNS_ADDR,0x0005,0x0220);
	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0x0005, PSOC_WMSW);
	writeBackPlaneRegister(0X0220, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf(
					"\nHalt CPU, Enable Debug-on-chip (DoC) access Address Drive failed %d times!!!!\n",
					ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(TRNS_ADDR, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	//	APACC(DATA_WR,0x0000,0x00b3);
	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0x0000, PSOC_WMSW);
	writeBackPlaneRegister(0X00b3, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf(
					"\nHalt CPU, Enable Debug-on-chip (DoC) access Data  Drive failed %d times!!!!\n",
					ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(DATA_WR, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	// Halt CPU
	//	APACC(TRNS_ADDR,0x0000,0x46EA);
	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0x0000, PSOC_WMSW);
	writeBackPlaneRegister(0X046EA, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nHalt CPU Address Drive failed %d times!!!!\n", ackLoop
					- 1);
			return 0;
		}
		writeBackPlaneRegister(TRNS_ADDR, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	//	APACC(DATA_WR,0x0000,0x0001);
	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0x0000, PSOC_WMSW);
	writeBackPlaneRegister(0X0001, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nHalt CPU Data Drive failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(DATA_WR, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	// Enable individual sub-system of chip
	//	APACC(TRNS_ADDR,0x0000,0x43A0);
	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0x0000, PSOC_WMSW);
	writeBackPlaneRegister(0X43A0, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf(
					"\nEnable individual sub-system of chip Address Drive failed %d times!!!!\n",
					ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(TRNS_ADDR, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	//	APACC(DATA_WR,0x0000,0x00BF);
	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0x0000, PSOC_WMSW);
	writeBackPlaneRegister(0X00BF, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf(
					"\nEnable individual sub-system of chip Data Drive failed %d times!!!!\n",
					ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(DATA_WR, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	// IMO set to 24 MHz
	//	APACC(TRNS_ADDR,0x0000,0x4200);
	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0x0000, PSOC_WMSW);
	writeBackPlaneRegister(0X4200, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nIMO set to 24 MHz Data Address failed %d times!!!!\n",
					ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(TRNS_ADDR, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	//	APACC(DATA_WR,0x0000,0x0002);

	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0X0000, PSOC_WMSW);
	writeBackPlaneRegister(0X0002, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nIMO set to 24 MHz Data Drive failed %d times!!!!\n",
					ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(DATA_WR, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	return 1;
}
unsigned char IBackPlane::configTargetDevice() {
	/* Setting DP configuration register for one-byte access. */
	DPACC(DPGPRT_CFG, 0x0000, 0x0000);

	// Halt CPU, Enable Debug-on-chip (DoC) access
	APACC(TRNS_ADDR, 0x0005, 0x0220);
	APACC(DATA_WR, 0x0000, 0x00b3);

	// Halt CPU
	APACC(TRNS_ADDR, 0x0000, 0x46EA);
	APACC(DATA_WR, 0x0000, 0x0001);

	// Enable individual sub-system of chip
	APACC(TRNS_ADDR, 0x0000, 0x43A0);
	APACC(DATA_WR, 0x0000, 0x00BF);

	// IMO set to 24 MHz
	APACC(TRNS_ADDR, 0x0000, 0x4200);
	APACC(DATA_WR, 0x0000, 0x0002);
	return 1;
}
unsigned char IBackPlane::verifyJtagID() {
	unsigned int readCMD, chkBusy, chkAck, ackLoop;
	unsigned int readLSB, readMSB;

	readCMD = chkBusy = chkAck = ackLoop = 0;
	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nJTAG Command failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(JTAG_IDCODE, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
		} while (chkBusy == 0x0000);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	readLSB = readBackPlaneRegister(PSOC_RLSW);
	readMSB = readBackPlaneRegister(PSOC_RMSW);
	//qDebugqDebug()<<"readLSB:"<<hex<<readLSB<<"readMSB:"<<hex<<readMSB;
	unsigned int temp = (((readMSB | 0x00000000) << 16) | readLSB);
	//qDebug() << "JTAG Code ID:" << hex << temp << hex << "Parity:" << hex
			//<< ((readCMD & 0x0200) >> 9);
	if (temp == getHexFileJtagID())
		return 1;
	else
		return 0;
}
unsigned char IBackPlane::eraseAll(){
	unsigned int readCMD, chkBusy, chkAck, ackLoop;
	unsigned int readLSB, readMSB;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	readCMD = chkBusy = chkAck = ackLoop = 0;
	writeBackPlaneRegister(0X0000, PSOC_WMSW);
	writeBackPlaneRegister(0X4720, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nSPC Data Register Address Drive failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(0X0011, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
		} while (chkBusy == 0);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0X0000, PSOC_WMSW);
	writeBackPlaneRegister(0X00B6, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nTest Data Drive failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(0X0015, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0X0000, PSOC_WMSW);
	writeBackPlaneRegister(0X4720, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nAddress Drive failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(0X0011, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
		} while (chkBusy == 0);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);*/

	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0X0000, PSOC_WMSW);
	writeBackPlaneRegister(0X00DC, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nTest Data Drive failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(0X0015, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0X0000, PSOC_WMSW);
	writeBackPlaneRegister(0X4720, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nTest Address Drive failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(0X0011, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
		} while (chkBusy == 0);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);*/

	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0X0000, PSOC_WMSW);
	writeBackPlaneRegister(0X0009, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nErase All Opcode Data Drive failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(0X0015, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0003; //masking D1&D0 of data read at0x0034
		} while (chkBusy != DONE);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	readCMD = chkBusy = chkAck = ackLoop = 0;

	writeBackPlaneRegister(0X0000, PSOC_WMSW);
	writeBackPlaneRegister(0X4722, PSOC_WLSW);

	do {
		ackLoop++;
		if (ackLoop > 4) {
			printf("\nTest Address Drive failed %d times!!!!\n", ackLoop - 1);
			return 0;
		}
		writeBackPlaneRegister(TRNS_ADDR, PSOC_CMD);
		do {
			readCMD = readBackPlaneRegister(PSOC_CMD);
			chkBusy = chkAck = readCMD;
			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
		} while (chkBusy == 0);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);
	//--------------------------------------------------------------------------------
	 readLSB = readBackPlaneRegister(PSOC_RLSW);
	 readMSB = readBackPlaneRegister(PSOC_RMSW);

	 //qDebug()<<"readLSB:"<<hex<<readLSB<<"readMSB:"<<hex<<readMSB;
 //dummy read
	readCMD = chkBusy = chkAck = ackLoop = 0;
	 do {
	 		ackLoop++;
	 		if (ackLoop > 4) {
	 			printf("\nDummy Read Command failed %d times!!!!\n", ackLoop - 1);
	 			return 0;
	 		}
	 		writeBackPlaneRegister(0x19, PSOC_CMD);
	 		do {
	 			readCMD = readBackPlaneRegister(PSOC_CMD);
	 			chkBusy = chkAck = readCMD;
	 			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
	 		} while (chkBusy == 0x0000);
	 		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	 	} while ((chkAck >> 6) != OK);

	 readLSB = readBackPlaneRegister(PSOC_RLSW);
	 readMSB = readBackPlaneRegister(PSOC_RMSW);

	 //qDebug()<<"readLSB:"<<hex<<readLSB<<"readMSB:"<<hex<<readMSB;

//dummy read-2
		readCMD = chkBusy = chkAck = ackLoop = 0;
		 do {
		 		ackLoop++;
		 		if (ackLoop > 4) {
		 			printf("\nDummy Read Command failed %d times!!!!\n", ackLoop - 1);
		 			return 0;
		 		}
		 		writeBackPlaneRegister(0x19, PSOC_CMD);
			 		do {
		 			readCMD = readBackPlaneRegister(PSOC_CMD);
		 			chkBusy = chkAck = readCMD;
		 			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
		 		} while (chkBusy == 0x0000);
		 		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
		 	} while ((chkAck >> 6) != OK);

		 readLSB = readBackPlaneRegister(PSOC_RLSW);
		 readMSB = readBackPlaneRegister(PSOC_RMSW);

		 //qDebug()<<"readLSB:"<<hex<<readLSB<<"readMSB:"<<hex<<readMSB;

//dummy read-3
			readCMD = chkBusy = chkAck = ackLoop = 0;
			 do {
			 		ackLoop++;
			 		if (ackLoop > 4) {
			 			printf("\nDummy Read Command failed %d times!!!!\n", ackLoop - 1);
			 			return 0;
			 		}
			 		writeBackPlaneRegister(0x19, PSOC_CMD);
				 		do {
			 			readCMD = readBackPlaneRegister(PSOC_CMD);
			 			chkBusy = chkAck = readCMD;
			 			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
			 		} while (chkBusy == 0x0000);
			 		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
			 	} while ((chkAck >> 6) != OK);

			 readLSB = readBackPlaneRegister(PSOC_RLSW);
			 readMSB = readBackPlaneRegister(PSOC_RMSW);

			 //qDebug()<<"readLSB:"<<hex<<readLSB<<"readMSB:"<<hex<<readMSB;

//dummy read-4
				readCMD = chkBusy = chkAck = ackLoop = 0;
				 do {
				 		ackLoop++;
				 		if (ackLoop > 4) {
				 			printf("\nDummy Read Command failed %d times!!!!\n", ackLoop - 1);
				 			return 0;
				 		}
				 		writeBackPlaneRegister(0x19, PSOC_CMD);
					 		do {
				 			readCMD = readBackPlaneRegister(PSOC_CMD);
				 			chkBusy = chkAck = readCMD;
				 			chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
				 		} while (chkBusy == 0x0000);
				 		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
				 	} while ((chkAck >> 6) != OK);

					readLSB = readBackPlaneRegister(PSOC_RLSW);
					readMSB = readBackPlaneRegister(PSOC_RMSW);

					//qDebug()<<"readLSB:"<<hex<<readLSB<<"readMSB:"<<hex<<readMSB;

/*//actual read
	 float time_elapsed=0;
	 unsigned int status;
	 clock_t this_time=clock();
//	 qDebug()<<"time"<<this_time;

	do{
		readCMD = chkBusy = chkAck = ackLoop = 0;
	  do{
		  ackLoop++;
		  if (ackLoop > 4) {
			  printf("\nActual Read Command failed %d times!!!!\n", ackLoop - 1);
			  return 0;
		  }
		  writeBackPlaneRegister(DATA_RD, PSOC_CMD);
		  do {
			  readCMD = readBackPlaneRegister(PSOC_CMD);
			  chkBusy = chkAck = readCMD;
			  chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
		  } while (chkBusy == 0x0000);
		chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
	} while ((chkAck >> 6) != OK);

	readLSB = readBackPlaneRegister(PSOC_RLSW);
	readMSB = readBackPlaneRegister(PSOC_RMSW);

	qDebug()<<"readLSB:"<<hex<<readLSB<<"readMSB:"<<hex<<readMSB;
	status = (((readMSB | 0x00000000) << 16) | readLSB);
	this_time=clock()-this_time;
	time_elapsed=((float)this_time)/CLOCKS_PER_SEC;
	qDebug()<<"in loop"<<hex<<"status:"<<status<<"time elapsed:"<<time_elapsed;
	}while(status!=0x02&&time_elapsed<0.15);

	if(time_elapsed>0.15){
		qDebug()<<"Time elapsed FAIL_EXIT";
		return 0;
	}*/
   //-----------------------------------------------------------------------------------
	return 1;
}
/*unsigned char IBackPlane::eraseAll() {
	unsigned int readCMD, chkBusy, chkAck, ackLoop;
	unsigned int readLSB, readMSB;

	writeBackPlaneRegister(0X0001, PSOC_CMD); //Bus Reset

	// SPC data register address
	whoami = "spc_data_reg_addr";
	if (APACC(TRNS_ADDR, 0x0000, 0x4720) == 1) {
		// First initiation key
		whoami = "First initiation key";
		if (APACC(DATA_WR, 0x0000, 0x00B6) == 1) {
			// Second key:00DC(0xD3 + 0x09); 0x09 is Erase All opcode
			whoami = "second key";
			//		if(APACC(TRNS_ADDR,0x0000,0x4720)==1){
			if (APACC(DATA_WR, 0x0000, 0x00DC) == 1) {
				// ERASE_ALL opcode
				whoami = "erase all opcode";
				//	if(APACC(TRNS_ADDR,0x0000,0x4720)==1){
				if (APACC(DATA_WR, 0x0000, 0x0009) == 1) {

					 Read SPC status register to check the status of SPC command. If “Command Success” status
					 is not received within 1 second, then exit the programming operation

					// SPC status register address
				 // if (APACC(TRNS_ADDR, 0x0000, 0x4722) == 1) {


						readCMD = chkBusy = chkAck = ackLoop = 0;
						do {
							ackLoop++;
							if (ackLoop > 4) {
								printf(
										"\nRead SPC status register failed %d times!!!!\n",
										ackLoop - 1);
								return 0;
							}
							APACC(TRNS_ADDR, 0x0000, 0x4722);
							writeBackPlaneRegister(DATA_RD, PSOC_CMD);
							do {
								unsigned int dummy=readBackPlaneRegister(PSOC_CMD);
								readCMD = readBackPlaneRegister(PSOC_CMD);
								chkBusy = chkAck = readCMD;
								chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
							} while (chkBusy == 0x0000);
							chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
						} while ((chkAck >> 6) != OK);

						if(IsSpcIdle()==1)
							return 1;
						else
							return 0;
						readCMD = chkBusy = chkAck = ackLoop = 0;
						do {
							ackLoop++;
							if (ackLoop > 4) {
								printf(
										"\nactual read Command failed %d times!!!!\n",
										ackLoop - 1);
								return 0;
							}
							writeBackPlaneRegister(DATA_RD, PSOC_CMD);
							do {
								readCMD = readBackPlaneRegister(PSOC_CMD);
								chkBusy = chkAck = readCMD;
								chkBusy &= 0x0002; //masking D1&D0 of data read at0x0034
							} while (chkBusy == 0x0000);
							chkAck &= 0x01C0; //masking D8,D7&D6 of data read at0x0034
						} while ((chkAck >> 6) != OK);

						readLSB = readBackPlaneRegister(PSOC_RLSW);
						readMSB = readBackPlaneRegister(PSOC_RMSW);
						//
						unsigned int temp = (((readMSB | 0x00000000) << 16)
								| readLSB);

						qDebug() << "readData:" << hex << temp << "readLSB:"
								<< hex << readLSB << "readMSB:" << hex
								<< readMSB;
					//SWDREAD(DATA_RD);
					//qDebug()<<"Data :"<<SWDREAD(DATA_RD);

					} else
						return 0;

				} else
					return 0;

			} else
				return 0;

		} else
			return 0;

	} else
		return 0;
	return 1;
}*/
unsigned char GetDieTemperature(unsigned char * Temperature_Sign, unsigned char * Temperature_Magnitude)
{
	unsigned int readData;

    /* APACC ADDR Write [0x0000 4720] */
	obj_IBackPlane.APACC(TRNS_ADDR,0x0000,0x4720);

    /* APACC DATA Write [0x0000 00B6] */
	obj_IBackPlane.APACC(DATA_WR,0x0000,0x00B6);

    /* APACC DATA Write [0x0000 00E1] */
	obj_IBackPlane.APACC(DATA_WR,0x0000,0x00E1);

    /* APACC DATA Write [0x0000 000E] */
	obj_IBackPlane.APACC(DATA_WR,0x0000,0x000E);

    /* APACC DATA Write [0x0000 0003] */
	obj_IBackPlane.APACC(DATA_WR,0x0000,0x0003);

    /* APACC ADDR Write [0x0000 4720] */
	obj_IBackPlane.APACC(TRNS_ADDR,0x0000,0x4720);

    /* APACC DATA Read - This is dummy read, next read gets temperature value */
	obj_IBackPlane.SWDREAD(DATA_RD);

    /* APACC DATA Read */
	readData=obj_IBackPlane.SWDREAD(DATA_RD);

    *Temperature_Sign = readData&0x00001111; /* Store the Sign byte of temperature */

    /* APACC DATA Read */
    readData=obj_IBackPlane.SWDREAD(DATA_RD);

    *Temperature_Magnitude = readData&0x00001111; /* Store the Magnitude byte of temperature */

    if(IsSpcIdle() == 1)
        return 1;
    else
        return 0;
}
unsigned char IsSpcIdle()
{
    unsigned short loop,readData=0;

    /* APACC ADDR Write [0x0000 4722] */
    obj_IBackPlane.APACC(TRNS_ADDR,0x0000,0x4722);

    /* APACC DATA Read. This is Dummy read as this is first read packet */
    obj_IBackPlane.SWDREAD(DATA_RD);

    loop = 0;

    /* Loop till SPC is not idle and timeout has not happened */
    do
    {
        /* APACC DATA Read */
    	obj_IBackPlane.SWDREAD(DATA_RD);

        loop++;
    }while(((readData&0x00FF)!=0x02) && (loop < 10));

    if((readData&0x00001111) == 0x02) /*Return success if Idle */
    {
        return 1;
    }
    else /* Set the SPC Timeout error bit and return failure */
    {
        return 0;
    }
}

unsigned char IBackPlane::prgDevConfigNVLatch() {
	/* The NV Latches have a lesser endurance, and hence should be written only when the data has
	 changed. First read the Device Configuration NVL bytes from target device and dump in to an
	 array, Data_Array. Compare the bytes read from the silicon to the NVL bytes in hex file at
	 address 0x90000000. Perform write operation only if there is a byte mismatch */
		unsigned int dummy;
		unsigned int ByteRead = 0; //Variable to track number of bytes that have been read
		unsigned int Data_Array[4]; //4-byte array to store the NVL data read from device
		unsigned int StatusReg; //To store SPC_SR status register value
	while (ByteRead < 0x0004)
	{
		APACC(TRNS_ADDR, 0x0000, 0x4720);
		APACC(DATA_WR, 0x0000, 0x00B6);// First initiation key
		APACC(TRNS_ADDR, 0x0000, 0x4720);
		APACC(DATA_WR, 0x0000, 0x00D6);// Second key:00D6(0xD3 + 0x03); 0x03 is Read Byte opcode
		APACC(TRNS_ADDR, 0x0000, 0x4720);
		APACC(DATA_WR, 0x0000, 0x0003);//0x03 is Read Byte opcode
		APACC(TRNS_ADDR, 0x0000, 0x4720);
		APACC(DATA_WR, 0x0000, 0x0080);// Device Configuration NVL array ID
		APACC(TRNS_ADDR, 0x0000, 0x4720);

		//	APACC DATA Write [ByteRead]
		//Byte number of User NVL to be read
		// Poll status register bit till data is ready

		APACC(TRNS_ADDR, 0x0000, 0x4722);

		dummy = SWDREAD(DATA_RD);
		//Dummy SWD Read, Next read gives correct status


		do{
			StatusReg = SWDREAD(DATA_RD); // Save status register value
			} while (StatusReg != 0x01);

		APACC(TRNS_ADDR, 0x0000, 0x4720);
		dummy = SWDREAD(DATA_RD);
		//Dummy SWD read, first byte read is garbage
		Data_Array[ByteRead] = SWDREAD(DATA_RD); // Store the data read from device
			ByteRead = ByteRead + 1;
		//Check if SPC Idle bit is high

		APACC(TRNS_ADDR, 0x0000, 0x4722);// SPC status register address

		dummy = SWDREAD(DATA_RD);
		do{
			StatusReg = SWDREAD(DATA_RD);// Save status register value
			} while ((StatusReg != 0x02));
	}
		/*Compare the NVL bytes read from target device with those in hex file. Set “WriteFlag” if
		 there is change in NVL data even in one bit position. If “ECC Enable” bit in NVL (bit 3 of
		 byte 4 (last NVL byte)) has been changed from its previous value, “eccEnableChanged” flag is
		 set. If this flag has been set, a port acquire sequence (repeat of Step 1, Step 2) is done
		 again after completing NVL write operation. This is required for the new ECC settings to take
		 effect during subsequent Flash Programming, Read operations.*/

			ByteRead = 0; /* Count of number of bytes read for comparison */
		/*This flag determines whether the NV latch will be programmed or not. Flag is set when new
		 data needs to be written; otherwise reset */
			unsigned int WriteFlag=0;
		/* This flag, if set, indicates “ECC Enable” bit in User NVL in hex file
		 is different from what is already programmed in target device */
			unsigned int eccEnableChanged = 0;
			while (ByteRead < 0x04)
			{
		// Replace XX in below line with data at address (0x90000000 + ByteRead) of .hex file
			if(Data_Array[ByteRead] != 0x0000+ByteRead)
			{
			WriteFlag=1; //Set the flag if NV latch needs to be programmed
		/* Set the “eccEnableChanged” flag if “ECC_Enable” bit(bit 3 of NVL
		 byte-4 is ECC_Enable bit) in User NVL is different between hex file and the
		 target device. */
			if (ByteRead == 0x03)
			{
		/* Replace XX in below line with data at address (0x90000000 + ByteRead) of .hex file */
		eccEnableChanged = ((( 0x0000+ByteRead ^ Data_Array [3]) & 0x08) == 0x08);
		}
		}
		ByteRead = ByteRead + 1;
		}
		//Check if the WriteFlag is set before programming User NVL
		if (WriteFlag == 1)
		{
		unsigned int pullupEnable = ((0x0000 & 0x80) == 0x80) && ((Data_Array[0] & 0x0C) != 0x08);
		/* Pull-up is disabled on P1[2] now. Configure P1[2] for resistive pull-up drive mode,
		 output high state */
		if (pullupEnable == 1)
		{
		unsigned int PinState;

		APACC(TRNS_ADDR, 0x0000, 0x500A);
		dummy = SWDREAD(DATA_RD);//Dummy SWD Read
		PinState = SWDREAD(DATA_RD);// Store the current pin configuration
		/* Configure the pin for resistive pull up mode, data high */
		PinState = (PinState & 0xF0) | (0x05);
		/* Write the modified value to the register */
		//APACC DATA WRITE [PinState]
		}
		unsigned int AddrCount = 0;
		while (AddrCount < 4)
		{
		APACC(TRNS_ADDR, 0x0000, 0x4720);// Write to command data register

		APACC(DATA_WR, 0x0000, 0x00B6);// First initiation key

		APACC(TRNS_ADDR, 0x0000, 0x4720);
		APACC(DATA_WR, 0x0000, 0x00D3); // Second initiation key: 0xD3 + 0x00

		APACC(TRNS_ADDR, 0X0000, 0X4720);

		APACC(DATA_WR, 0X0000, 0X0000);// LOAD_BYTE opcode

		APACC(TRNS_ADDR, 0X0000, 0X4720);

		APACC(DATA_WR, 0X0000, 0X0080);// Array ID of “Device Config NVL”

		APACC(TRNS_ADDR, 0X0000, 0X4720);

		APACC(DATA_WR, 0X0000, 0X0003); //?????????????
		//APACC DATA Write [AddrCount]// Current address: 0 – 3

		APACC(TRNS_ADDR, 0X0000, 0X4720);

		APACC(DATA_WR, 0X0000, 0X0000);

		APACC(TRNS_ADDR,0x0000,0x4722);
		dummy = SWDREAD(DATA_RD);// Dummy SWD Read, Next Read gives correct status
		 do	{
		     StatusReg = SWDREAD(DATA_RD);// Save status register value
		    } while (StatusReg != 0x02);
		 	 AddrCount = AddrCount + 1 ;//Increment to load the next NVL byte
		   }
		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00B6);// Call WRITE_USER_NVL command

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00D9);//Second initiation key: 0xD3 + 0x06

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X0006);// WRITE_USER_NVL opcode

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X0080);// Array ID: Device Config NVL

        APACC(TRNS_ADDR,0x0000,0x4722);
		dummy = SWDREAD(DATA_RD);	//Dummy SWD Read, Next Read gives correct status
		 do		// Poll status register
		    {
		       StatusReg = SWDREAD(DATA_RD); // Save status register value
		                  } while (StatusReg != 0x02);

		 if (eccEnableChanged){
			 enterPsocProgMode();
		    }
		}
	}
	unsigned char IBackPlane::programFlash() {
		/*Get the die temperature and store it in “Sign, Magnitude” bytes.
		 Note that when this command is called the first time after device comes out of reset
		 (which is in this step), it should be called twice. This is because the “Get Temp” command
		 returns accurate value only from the second time it is called after device comes out of
		 reset.*/
		/************************************************************************/
		//Start of “Get_Temp” routine to get Die temperature
//		byte Temp_Sign, Temp_Magnitude; //Die temperature - used in the PROGRAM_ROW
//		//instruction
		uint8_t loop = 0; //This variable is used to do the Get_Temp routine twice.
		uint32_t StatusReg; //To store SPC_SR status register value
	while (loop <= 1)
	{
		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00B6);
//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 00B6]

		//SPC_KEY1
		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00E1);
//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 00E1]

		//SPC_KEY2 + SPC_GET_TEMP (0xD3+0x0E)
		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X000E);
//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 000E]

		//SPC_ GET_TEMP opcode
		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X0003);
//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 0003] //Number of samples, valid values [1..5]
		//Wait until Temperature data is ready

		APACC(TRNS_ADDR, 0X0000, 0X4722);
//		APACC ADDR Write [0x0000 4722]

		unsigned int dummy = SWDREAD(DATA_RD);
		//Dummy SWD Read, Next Read gives correct status

		do
		{
			StatusReg = SWDREAD(DATA_RD); // Save status register value
		}while ((StatusReg != 0x01));

		APACC(TRNS_ADDR,0x0000,0x4720);
		dummy = SWDREAD(DATA_RD);
		unsigned int Temp_Sign =SWDREAD(DATA_RD);// First byte read is sign of temperature
		unsigned int Temp_Magnitude =SWDREAD(DATA_RD);// Second byte read is magnitude of temperature

		APACC(TRNS_ADDR,0x0000,0x4722);// Poll status register
		dummy = SWDREAD(DATA_RD);
		do
		{
			StatusReg = SWDREAD(DATA_RD); // Save status register value
		}while (StatusReg != 0x02);

		loop++;
	}
//	/* End of “Get_Temp” routine to get Die temperature. The temperature value received
//	 During second time of above loop is stored in Temp_Magnitude, Temp_Sign, and used in below
//	 programming step */
//	/***********************************************************************/
//	/* Setting DP configuration register for four-byte access to SRAM. */
//	DPACC DP CONFIG Write [0x0000 0004]
//	//Program Rows
//	int Row_Count = 0 //Variable to keep track of Row being programmed
//	int Byte_Count = 0 //Variable to keep track of byte number in a row
//	while (Row_Count < N)// See “Step 6:Program Flash” section for ‘N’
//	{
//		//-------------Programming EVEN ROW ----------------------
//		//"B6" - SPC_KEY1, "D5" - SPC_KEY2, "02" - LOAD_ROW opcode, "00" - Flash ArrayID

		APACC(TRNS_ADDR, 0X0000, 0X000);
		APACC(DATA_WR, 0X0002, 0XD5B6);
//		APACC ADDR Write [0x0000 0000]// SRAM address- 32’h00
//		APACC DATA Write [0x0002 D5B6]// 4 byte data

//		Byte_Count = 0
		//Send Row data to SRAM from HEX
//		while (Byte_Count < L)
		// Define L according to ECC settings
//		{
//			APACC ADDR Write [Byte_Count + 0x4]
			/* 4-bytes (d3d2d1d0) are from hex file starting at address (address of d0):
			 i.) if Byte_Count < 256: Address of do = (0x00000000 + (Row_Count * 256) +
			 Byte_Count)
			 ii.) if 256 <= Byte_Count < 288: Address of do = (0x80000000 + (Row_Count*32) +
			 (Byte_Count – 256))
			 The ii) address will be needed only if ECC is disabled.
			 ECC data is 32 bytes per row.*/
//			APACC DATA Write [d3d2d1d0]
//			Byte_Count = Byte_Count + 4
//		}
		//"00","00","00" - 3 NOPs for short delay, "B6" - SPC_KEY1
//		APACC ADDR Write [(L - 1) + 0x05]
		APACC(DATA_WR,0xB600,0x0000);
//		APACC DATA Write [0xB600 0000]
		//"DA"- SPC_KEY1+SPC_PRG_ROW, "07" - SPC_PRG_ROW, "00" - Flash Array ID
		//”00”- High Byte of RowCount

//		APACC ADDR Write [(L - 1) + 0x09]
//		APACC DATA Write [0x0000 07DA]

		//LOW TEMP BYTE
		//		APACC ADDR Write [(L - 1) + 0xD]
//		APACC DATA Write [(0x00 << 24) | (Temp_Magnitude << 16) | (Temp_Sign << 8) |
//		(RowCount & 0xFF)]
		//DMA operations

		APACC(TRNS_ADDR, 0X0000, 0X7018);
		APACC(DATA_WR, 0X0000, 0X0000);

//		APACC ADDR Write [0x0000 7018]// PHUB_CH0_STATUS Register
//		APACC DATA Write [0x0000 0000]// Disable chain event, use TDMEM1_ORIG_TD0

		APACC(TRNS_ADDR, 0X0000, 0X7010);
		APACC(DATA_WR, 0X0000, 0X0021);

//		APACC ADDR Write [0x0000 7010]// PHUB_CH0_BASIC_CFG register
//		APACC DATA Write [0x0000 0021] // Enable DMA CH 0

		APACC(TRNS_ADDR, 0X0000, 0X7600);
		APACC(DATA_WR, 0X0000, 0X0080);

//		APACC ADDR Write [0x0000 7600]// PHUB_CFGMEM0_CFG0 register
//		APACC DATA Write [0x0000 0080]// DMA request is required for each burst

		APACC(TRNS_ADDR, 0X0000, 0X7604);
		APACC(DATA_WR, 0X0000, 0X0000);

//		APACC ADDR Write [0x0000 7604]// PHUB_CFGMEM0_CFG1 register
//		APACC DATA Write [0x0000 0000] // Sets upper 16-bit address of destination/source

//		APACC ADDR Write [0x0000 7800] //PHUB_TDMEM0_ORIG_TD0 register
//		APACC DATA Write [(0x01FF 0000) + L + 15] // Set TD transfer counts

		APACC(TRNS_ADDR, 0X0000, 0X7804);
		APACC(DATA_WR, 0X4720, 0X0000);

//		APACC ADDR Write [0x0000 7804] // PHUB_TDMEM0_ORIG_TD1 register
//		APACC DATA Write [0x4720 0000] // Set lower 16-bit address of the destination/source

		//Wait until SPC has done previous request
		APACC(TRNS_ADDR, 0X0000, 0X4722);
//		APACC ADDR Write [0x0000 4722]// Poll status register

//		dummyByte = APACC DATA Read
		//Dummy SWD Read, Next Read gives correct status
//		time_elapsed = 0
//		do
//		{
//			StatusReg = (byte) APACC DATA Read // Save status register value
//		}while ((StatusReg != [0x02]) AND time_elapsed < 1 sec)
//		if (time_elapsed > 1 sec) then FAIL_EXIT

		APACC(TRNS_ADDR, 0X0000, 0X7014);
		APACC(DATA_WR, 0X0000, 0X0001);

//		APACC ADDR Write [0x0000 7014]// PHUB_CH0_ACTION register
//		APACC DATA Write [0x0000 0001]// This creates a direct DMA request for channel ‘0’
		// DMA will transfer data from SRAM, and call LOAD_ROW and then WRITE_ROW
		//When the DMA is transferring data using Channel ‘0’, configure Channel ‘1’ to speed up
		//programming time
		//-------------Programming ODD ROW ----------------------
//		Row_Count = Row_Count + 1// Increment row count and repeat process for the next row
		//"B6" - SPC_KEY1, "D5" - SPC_KEY2, "02" - LOAD_ROW opcode, "00" - ArrayID

		APACC(TRNS_ADDR, 0X0000, 0X0200);
		APACC(DATA_WR, 0X0002, 0XD5B6);

//		APACC ADDR Write [0x0000 0200]// SRAM address 32’h200
//		APACC DATA Write [0x0002 D5B6]// 4-byte data as commented above

		//Send Row to SRAM from HEX
//		Byte_Count = 0
//		while (Byte_Count < L)//Define L according to ECC settings
//		{
//			APACC ADDR Write [Byte_Count + 0x204]
			/* 4-bytes (d3d2d1d0) are from hex file starting at address (address of d0):
			 i.) if Byte_Count < 256: Address of do = (0x00000000 + (Row_Count * 256) +
			 Byte_Count)
			 ii.) if 256 <= Byte_Count < 288: Address of do = (0x80000000 + (Row_Count*32) +
			 (Byte_Count – 256))
			 The ii) address will be needed only if ECC is disabled.
			 ECC data is 32 bytes per row.*/
//			APACC DATA Write [d3d2d1d0] // Write 4 bytes at a time, 4-bytes are from hex file
//			Byte_Count = Byte_Count + 4
//		}
		//"00","00","00" - 3 NOPs for short delay, "B6" - SPC_KEY1

//		APACC ADDR Write [(L - 1) + 0x205]

		APACC(DATA_WR, 0XB600, 0X0000);
//		APACC DATA Write [0xB600 0000]
		//"DA"- SPC_KEY1+SPC_PRG_ROW, "07" - SPC_PRG_ROW, "00" - Flash Array ID
		//”00”- High Byte of RowCount
//		APACC ADDR Write [(L - 1) + 0x209]
		APACC(DATA_WR,0x0000,0x07DA);// 0xDA = 0xD3 + 0x07 ( “WRITE_ROW” opcode)
//		APACC DATA Write [0x0000 07DA]// 0xDA = 0xD3 + 0x07 ( “WRITE_ROW” opcode)

		                  //Low byte of row number, Temperature data
//		APACC ADDR Write [(L - 1) + 0x20D]
//		APACC DATA Write [(0x00 << 24) | (Temp_Magnitude << 16) | (Temp_Sign << 8) |
//		(RowCount & 0xFF)]
		//DMA operations

		APACC(TRNS_ADDR, 0X0000, 0X7028);
		APACC(DATA_WR, 0X0000, 0X0100);

//		APACC ADDR Write [0x0000 7028]// PHUB_CH1_STATUS Register
//		APACC DATA Write [0x0000 0100] // Disable chain event, use TDMEM1_ORIG_TD1

   		APACC(TRNS_ADDR, 0X0000, 0X7020);
   		APACC(DATA_WR, 0X0000, 0X0021);

//		APACC ADDR Write [0x0000 7020]// PHUB_CH1_BASIC_CFG register
//		APACC DATA Write [0x0000 0021]// Enable DMA CH 0

   		APACC(TRNS_ADDR, 0X0000, 0X7608);
   		APACC(DATA_WR, 0X0000, 0X0080);

//		APACC ADDR Write [0x0000 7608]// PHUB_CFGMEM1_CFG0 register
//		APACC DATA Write [0x0000 0080]// DMA request is required for each burst

		APACC(TRNS_ADDR, 0X0000, 0X760C);
		APACC(DATA_WR, 0X0000, 0X0000);

//		APACC ADDR Write [0x0000 760C]// PHUB_CFGMEM1_CFG1 register
//		APACC DATA Write [0x0000 0000]// Sets upper 16-bit address of destination/source

   		APACC(TRNS_ADDR, 0X0000, 0X7808);
   		APACC(DATA_WR, 0X01FF, 0X0000);

//		APACC ADDR Write [0x0000 7808]//PHUB_TDMEM0_ORIG_TD0 register
//		APACC DATA Write [(0x01FF 0000) + L + 15] // Set TD transfer counts

   		APACC(TRNS_ADDR, 0X0000, 0X780C);
   		APACC(DATA_WR, 0X4720, 0X0200);

//		APACC ADDR Write [0x0000 780C] // PHUB_TDMEM1_ORIG_TD1 register
//		APACC DATA Write [0x4720 0200] // Set lower 16-bit address of the destination/source

		//Wait until SPC has done previous request
   		APACC(TRNS_ADDR, 0X0000, 0X4722);
//		APACC ADDR Write [0x0000 4722]

//		dummyByte = APACC DATA Read
		//Dummy SWD Read, Next Read gives correct status
//		time_elapsed = 0
//		do
		// Poll status register
//		{
//			StatusReg = (byte) APACC DATA Read // Save status register value
//		}while ((StatusReg != [0x02]) AND time_elapsed < 1 sec)
//		if (time_elapsed > 1 sec) then FAIL_EXIT
   		APACC(TRNS_ADDR, 0X0000, 0X7024);
   		APACC(DATA_WR, 0X0000, 0X0001);

//		APACC ADDR Write [0x0000 7024] // PHUB_CH1_ACTION register
//		APACC DATA Write [0x0000 0001] // This creates a direct DMA request Channel ‘1’
		// DMA will transfer data from SRAM, and call LOAD_ROW and then WRITE_ROW
//		Row_Count = Row_Count + 1
//	}
	//Make sure that last SPC request is completed

 		APACC(TRNS_ADDR, 0X0000, 0X4722);
//		APACC ADDR Write [0x0000 4722]

//	dummyByte = APACC DATA Read //Dummy SWD Read, Next Read gives correct
//	time_elapsed = 0
//	do
	// Poll status register
//	{
//		StatusReg = (byte) APACC DATA Read // Save status register value
//	}while ((StatusReg != [0x02]) AND time_elapsed < 1 sec)
//	if (time_elapsed > 1 sec) then FAIL_EXIT
	// Resetting DP configuration register for one-byte access after Flash programming
	DPACC(DPGPRT_CFG, 0x0000, 0x0000);

//	DPACC DP CONFIG Write [0x0000 0000]

}
unsigned char IBackPlane::verifyFlash() {
//	int RowCount = 0 //Variable to keep track of flash rows that have been read
//	int byte_index = 0 //Variable to keep track of number of bytes read in a Flash row
//	byte StatusReg //To store SPC_SR status register value
//	byte Data_Array[L] //Array of size ‘L’ bytes to store one row of data read from device
//	int32 address
	// Iterate through all rows of flash
//	while (RowCount < N)
//	{
//		address = RowCount * 256
		//Starting address of Flash row
   		APACC(TRNS_ADDR, 0X0000, 0X4720);
   		APACC(DATA_WR, 0X0000, 0X00B6);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 00B6]//First initiation key

   		APACC(TRNS_ADDR, 0X0000, 0X4720);
   		APACC(DATA_WR, 0X0000, 0X00D7);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 00D7]//0xD7= (0xD3 + READ_MULTI_BYTE opcode)

   		APACC(TRNS_ADDR, 0X0000, 0X4720);
   		APACC(DATA_WR, 0X0000, 0X0004);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 0004] // READ_MULTI_BYTE opcode

   		APACC(TRNS_ADDR, 0X0000, 0X4720);
   		APACC(DATA_WR, 0X0000, 0X0000);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 0000]// Array ID

   		APACC(TRNS_ADDR, 0X0000, 0X4720);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [(address >> 16) & 0xFF]//MSB byte2 of 3-byte address

   		APACC(TRNS_ADDR, 0X0000, 0X4720);
//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [(address >> 8) & 0xFF]//Byte1 of 3-byte address

   		APACC(TRNS_ADDR, 0X0000, 0X4720);
//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [(address >> 0) & 0xFF]//LSB Byte0 of 3-byte address

   		APACC(TRNS_ADDR, 0X0000, 0X4720);
//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 00FF]// Number of bytes to be read minus one

   		//Wait until Data is ready

   		APACC(TRNS_ADDR, 0X0000, 0X4722);
//		APACC ADDR Write [0x0000 4722]

//		dummyByte = APACC DATA Read
		//Dummy SWD Read, Next Read gives correct status
//		time_elapsed = 0
//		do
//		{
//			StatusReg = (byte) APACC DATA Read // Save status register value
//		}while ((StatusReg != [0x01]) AND time_elapsed < 1 sec)
//		if (time_elapsed > 1 sec) then FAIL_EXIT
   		APACC(TRNS_ADDR, 0X0000, 0X4720);
//		APACC ADDR Write [0x0000 4720]

//		dummyByte = APACC DATA Read // Dummy SWD read
		// Read 256 bytes of row data in to Data_Array
//		int ByteRead = 0
//		while (ByteRead <= 0x0000 00FF)
//		{
//			Data_Array[byte_index] = APACC DATA Read// Save read data in to array
//			ByteRead = ByteRead + 1
//			byte_index = byte_index + 1
//		}
		// If ECC is disabled, row size is 288
//		If (L = 288)
//		{
			// Configuration(ECC) data is addressed as following. MSB bit is ‘1’ to
			//specify that addressed memory is ECC (config) memory
//			address = (RowCount * 32) | 0x00800000;
			// Call READ_MULTI_BYTE to read configuration data in ECC memory space
   		APACC(TRNS_ADDR, 0X0000, 0X4720);
   		APACC(DATA_WR, 0X0000, 0X00B6);

//			APACC ADDR Write [0x0000 4720]
//			APACC DATA Write [0x0000 00B6]

			//First initiation key
   		APACC(TRNS_ADDR, 0X0000, 0X4720);
   		APACC(DATA_WR, 0X0000, 0X00D7);

//			APACC ADDR Write [0x00004720]
//			APACC DATA Write [0x0000 00D7] //0xD7= (0xD3 + READ_MULTI_BYTE opcode)

   		APACC(TRNS_ADDR, 0X0000, 0X4720);
   		APACC(DATA_WR, 0X0000, 0X0004);

//			APACC ADDR Write [0x0000 4720]
//			APACC DATA Write [0x0000 0004] // READ_MULTI_BYTE opcode

   		APACC(TRNS_ADDR, 0X0000, 0X4720);
   		APACC(DATA_WR, 0X0000, 0X0000);

//			APACC ADDR Write [0x0000 4720]
//			APACC DATA Write [0x0000 0000] // Array ID

   		APACC(TRNS_ADDR, 0X0000, 0X4720);

//			APACC ADDR Write [0x0000 4720]
//			APACC DATA Write [(address >> 16) & 0xFF] //MSB Byte 2 of 3-byte address;

   		APACC(TRNS_ADDR, 0X0000, 0X4720);

//			APACC ADDR Write [0x0000 4720]
//			APACC DATA Write [(address >> 8) & 0xFF] //Byte 1 of 3-byte address

   		APACC(TRNS_ADDR, 0X0000, 0X4720);

//			APACC ADDR Write [0x0000 4720]
//			APACC DATA Write [(address >> 0) & 0xFF] //LSB Byte 0 of 3-byte address

   		APACC(TRNS_ADDR, 0X0000, 0X4720);
   		APACC(DATA_WR, 0X0000, 0X001F);

//			APACC ADDR Write [0x0000 4720]
//			APACC DATA Write [0x0000 001F]

			 //Each row has 32 ECC bytes to be read
			//Wait until Data is ready
//			APACC ADDR Write [0x0000 4722]
//			dummyByte = APACC DATA Read
			//Dummy SWD Read, Next Read gives correct status
//			time_elapsed = 0
//			do
//			{
//				StatusReg = (byte) APACC DATA Read // Save status register value
//			}while ((StatusReg != [0x01]) AND time_elapsed < 1 sec)
//			if (time_elapsed > 1 sec) then FAIL_EXIT

   		APACC(TRNS_ADDR, 0X0000, 0X4720);

//   		APACC ADDR Write [0x0000 4720]
//			dummyByte = APACC DATA Read // Dummy SWD read
//			ByteRead = 0
			/* Number of ECC bytes per row is 32 */
//			while (ByteRead <= 0x000 0001F)
//			{
//				Data_Array[byte_index] = APACC DATA Read// Save configuration data
//				ByteRead = ByteRead + 1
//				byte_index = byte_index + 1
//			}
//		}
		/* Now, the array Data_Array contains a row of Flash data (+ECC data if applicable).
		 Compare it with data in hex file to check if the correct data has been programmed in
		 to Flash row. If there is data mismatch, Abort the Programming operation and retry
		 again. Repeat for all Flash rows. */
//		RowCount = RowCount + 1; // Next Flash row
//	}

}
unsigned char IBackPlane::prgWrtOnceNVLatch() {
	/* The NV Latches have a lesser endurance, and hence written only when the data has changed.
	 First read the Write Once NVL bytes from target device and dump in to an
	 array, Data_Array.
	 Compare the bytes read from the silicon to the NVL bytes in hex file at address 0x90100000.
	 Perform write operation only if there is a byte mismatch */
//	byte ByteRead = 0 //Variable to track number of bytes that are read
//	byte StatusReg //To store SPC_SR status register value
//	byte Data_Array[4] //4-byte array to store the NVL data read from device
//	while (ByteRead < 0x0000 0004)
//	{
		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00B6);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 00B6] // First initiation key

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00D6);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 00D6] // Second key:00D6(0xD3 + 0x03); 0x03 is Read Byte opcode

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X0003);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 0003] //0x03 is Read Byte opcode

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00F8);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 00F8] //Write Once NVL array ID

		APACC(TRNS_ADDR, 0X0000, 0X4720);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [ByteRead]

		//Byte number of Write Once NVL to be read
		// Poll status register bit till data is ready

		APACC(TRNS_ADDR, 0X0000, 0X4722);

//		APACC ADDR Write [0x0000 4722]

//		dummyByte = APACC DATA Read
		//Dummy SWD Read, Next Read gives correct status
//		do
//		{
//			StatusReg = (byte) APACC DATA Read // Save status register value
//		}while ((StatusReg != [0x01]) AND time_elapsed < 1 sec)
//		if (time_elapsed > 1 sec) then FAIL_EXIT // Check if command execution time < 1 second

		APACC(TRNS_ADDR, 0X0000, 0X4720);

//		APACC ADDR Write [0x0000 4720]

//		dummyByte = APACC DATA Read
		//Dummy SWD read, first byte read is garbage
//		Data_Array[ByteRead] = APACC DATA Read //Store the data read from device in to array
//		ByteRead = ByteRead + 1
		//Check if SPC Idle bit is high
//		time_elapsed = 0

		APACC(TRNS_ADDR, 0X0000, 0X4722);
//		APACC ADDR Write [0x0000 4722]// SPC status register address
//		dummyByte = APACC DATA Read
		//Dummy SWD Read, Next Read gives correct status
//		do
//		{
//			StatusReg = (byte) APACC DATA Read// Save status register value
//		}while ((StatusReg != [0x02]) AND time_elapsed < 1 sec)
//		if (time_elapsed > 1 sec) then FAIL_EXIT
//	}
	//Compare the NVL bytes read from target device with those in hex file at address 0x90100000
//	ByteRead = 0
//	byte WriteFlag=0 /* This flag determines whether the NV latch will be programmed or not.
//	 Flag is set when new data needs to be written; otherwise reset */
//	while (ByteRead < 0x00000004)
//	{
		// Replace XX in the following line with data at address (0x90100000 + ByteRead) of .hex
//		file
//		if(Data_Array[ByteRead] != XX)
//		{
//			WriteFlag=1 //Set the flag if NV latch needs to be programmed
//		}
//		ByteRead = ByteRead + 1
//	}
	//Check if the WriteFlag is set before programming Write Once NVL
//	if (WriteFlag == 1)
//	{
//		byte AddrCount = 0
//		while (AddrCount < 4)
//		{

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00B6);

//			APACC ADDR Write [0x0000 4720]// Write to command data register
//			APACC DATA Write [0x0000 00B6]// First initiation key

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00D3);

//			APACC ADDR Write [0x0000 4720]
//			APACC DATA Write [0x0000 00D3] // Second initiation key: 0xD3 + 0x00

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X0000);

//			APACC ADDR Write [0x0000 4720]
//			APACC DATA Write [0x0000 0000]// LOAD_BYTE opcode

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00F8);

//			APACC ADDR Write [0x0000 4720]
//			APACC DATA Write [0x0000 00F8]// Array ID of “Write Once NVL”

		APACC(TRNS_ADDR, 0X0000, 0X4720);

//			APACC ADDR Write [0x0000 4720]

//			APACC DATA Write [AddrCount]// Byte index in “Write Once NVL”

		APACC(TRNS_ADDR, 0X0000, 0X4720);

//			APACC ADDR Write [0x0000 4720]
//			APACC DATA Write [0x0000 00XX]
			/* Replace XX with data located in
			 (0x90100000 + AddrCount) of .hex file */
//			time_elapsed = 0

		APACC(TRNS_ADDR, 0X0000, 0X4722);

//			APACC ADDR Write [0x0000 4722]
//			dummyByte = APACC DATA Read
			//Dummy SWD Read, Next Read gives correct status
//			do
			// Poll status register
//			{
//				StatusReg = (byte) APACC DATA Read // Save status register value
//			}while ((StatusReg != [0x02]) AND time_elapsed < 1 sec)
//			if (time_elapsed > 1 sec) then FAIL_EXIT //Check if command execution time < 1 sec
//			AddrCount = AddrCount + 1 //Increment to load the next NVL byte
//		}

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00B6);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 00B6] // SPC_KEY1

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00D9);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 00D9]// SPC_KEY2 + SPC_USER_NVL

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X0006);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 0006]// SPC_WRITE_USER_NVL opcode

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00F8);

//		APACC ADDR Write [0x0000 4720]
//		APACC DATA Write [0x0000 00F8]//Array ID of “Write Once NVL”
//		time_elapsed = 0

		APACC(TRNS_ADDR, 0X0000, 0X4722);

//		APACC ADDR Write [0x0000 4722]
//		dummyByte = APACC DATA Read
//		//Dummy SWD Read, Next Read gives correct status
//		do
		// Poll status register
//		{
//			StatusReg = (byte) APACC DATA Read // Save status register value
//		}while ((StatusReg != [0x02]) AND time_elapsed < 1 sec)
//		if (time_elapsed > 1 sec) then FAIL_EXIT// Check if command execution time < 1 second
//	}

}
unsigned char IBackPlane::prgFlashProtectData() {
//	byte protectionSize = N/4 //Each Flash protection byte stores protection data of 4 Flash rows
//	byte StatusReg //To store SPC_SR status register value
	//Get the die temperature and store it in “Sign, Magnitude” bytes
	/************************************************************************/
//	byte Temp_Sign, Temp_Magnitude; //Die temperature -used in the PROGRAM_PROTECT_ROW
	//instruction
	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X00B6);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 00B6]

	//SPC_KEY1
	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X00E1);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 00E1]

	//SPC_KEY2 + SPC_GET_TEMP (0xD3+0x0E)
	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X000E);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 000E]

	//SPC_ GET_TEMP opcode
	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X0003);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 0003] //Number of samples, valid values [1..5]
	//Wait until Temperature data is ready

	APACC(TRNS_ADDR, 0X0000, 0X4722);
//	APACC ADDR Write [0x0000 4722]

//	dummyByte = APACC DATA Read
	//Dummy SWD Read, Next Read gives correct status
//	time_elapsed = 0
//	do
//	{
//		StatusReg = (byte) APACC DATA Read // Save status register value
//	}while ((StatusReg != [0x01]) AND time_elapsed < 1 sec)
//	if (time_elapsed > 1 sec) then FAIL_EXIT

	APACC(TRNS_ADDR, 0X0000, 0X4720);
//	APACC ADDR Write [0x0000 4720]

//	dummyByte = APACC DATA Read // Dummy SWD read
//	Temp_Sign =(byte) APACC DATA Read // First byte read is sign of temperature
//	Temp_Magnitude =(byte) APACC DATA Read // Second byte read is magnitude of temperature
	//Wait for IDLE - just in case. Must be in idle state once data byte is read.

	APACC(TRNS_ADDR, 0X0000, 0X4722);
//	APACC ADDR Write [0x0000 4722]// Poll status register

//	dummyByte = APACC DATA Read
	//Dummy SWD Read, Next Read gives correct status
//	time_elapsed = 0
//	do
//	{
//		StatusReg = (byte) APACC DATA Read // Save status register value
//	}while ((StatusReg != [0x02]) AND time_elapsed < 1 sec)
//	if (time_elapsed > 1 sec) then FAIL_EXIT
	//End of “Get_Temp” routine to get Die temperature
	/***********************************************************************/

	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X00B6);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 00B6] // First initiation key

	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X00D5);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 00D5] // Second initiation key: 0xD3 + 0x02

	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X0002);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 0002] // LOAD_ROW opcode

	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X0002);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 0000]//Flash Array ID
//	int ByteCount = 0
//	while (ByteCount < L)
//	{

	APACC(TRNS_ADDR, 0X0000, 0X4720);
//	APACC ADDR Write [0x0000 4720]

//		if (ByteCount < protectionSize)
//		{
//			APACC DATA Write [0x0000 00XX]//Data at address (32’h90400000 + ByteCount) of HEX file
//		}
//		else
//		{
		APACC(DATA_WR, 0X0000, 0X0000);
//		APACC DATA Write [0x0000 0000]//Fill bytes greater than protection size with zero
//		}
//		ByteCount = ByteCount + 1
//	}
	// After loading the protection data, program it in to the Flash hidden rows
	//using PROGRAM_PROTECT_ROW command

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00B6);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 00B6] // First initiation key

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X00DE);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 00DE] // Second initiation key: 0xD3 + 0x0B

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X000B);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 000B]// PROGRAM_PROTECT_ROW opcode

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X0000);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 0000] //Flash array ID

		APACC(TRNS_ADDR, 0X0000, 0X4720);
		APACC(DATA_WR, 0X0000, 0X0000);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 0000] //Row select value is always zero for protection data

		APACC(TRNS_ADDR, 0X0000, 0X4720);

//	APACC ADDR Write [0x0000 4720]

//	APACC DATA Write [Temp_Sign] //Send Sign byte of die temperature

		APACC(TRNS_ADDR, 0X0000, 0X4720);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [Temp_Magnitude] //Send Magnitude byte of die temperature

		APACC(TRNS_ADDR, 0X0000, 0X4722);

//	APACC ADDR Write [0x0000 4722]
//	dummyByte = APACC DATA Read
	//Dummy SWD Read, Next Read gives correct status
//	time_elapsed = 0
//	do
	// Poll status register
//	{
//		StatusReg = (byte) APACC DATA Read // Save status register value
//	}while ((StatusReg != [0x02]) AND time_elapsed < 1 sec)
//	if (time_elapsed > 1 sec) then FAIL_EXIT

}
unsigned char IBackPlane::verifyFlashProtectData() {
	/* Array to store the protection bytes read from PSoC3. Even though the maximum number of
	 protection bytes is only 64 for a 64 KB Flash memory, it is still required to read all the
	 256 bytes in Flash protection row to ensure that the SPC returns back to the idle state. Even
	 if ECC is disabled, only 256 bytes need to be read in case of reading protection rows */
//	byte Data_Array[256];
//	byte StatusReg; //Variable to store the SPC status register value

	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X00B6);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 00B6]//First initiation key

	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X00DD);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 00DD]//0xDD= (0xD3 + READ_HIDDEN_ROW opcode)

	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X000A);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 000A]// READ_HIDDEN_ROW opcode

	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X0000);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 0000]// Flash Array ID

	APACC(TRNS_ADDR, 0X0000, 0X4720);
	APACC(DATA_WR, 0X0000, 0X0000);

//	APACC ADDR Write [0x0000 4720]
//	APACC DATA Write [0x0000 0000]// RowID of Protection bytes row

	//Wait until Data is ready, and also the command status code is success
	APACC(TRNS_ADDR, 0X0000, 0X4722);
//	APACC ADDR Write [0x0000 4722]
//	dummyByte = APACC DATA Read
	//Dummy SWD Read, Next Read gives correct status
//	time_elapsed = 0
//	do
//	{
//		StatusReg = (byte) APACC DATA Read // Save status register value
//	}while ((StatusReg != [0x01]) AND time_elapsed < 1 sec)
	APACC(TRNS_ADDR, 0X0000, 0X4720);
//	APACC ADDR Write [0x0000 4720]
//	dummyByte = APACC DATA Read // Dummy SWD read
	/* Read 256 bytes of row data in to Data_Array. Even though the maximum number of protection
	 bytes is only 64 for a 64 KB flash memory, it is still required to read all the 256 bytes in
	 Flash protection row to ensure that the SPC returns back to the idle state. Even if ECC is
	 disabled, only 256 bytes need to be read in case of reading protection rows */
//	byte_index = 0
//	while (byte_index < 256)
//	{
//		Data_Array[byte_index] = APACC DATA Read// Save data in to the array
//		byte_index = byte_index + 1
//	}
	/* Now, the array Data_Array contains a row of Flash protection data (256 bytes) read from
	 the device. Compare the first “NumberOfProtectionBytes” in the array with the protection data
	 in the hex file. In the hex file, the Flash protection bytes are present starting from the
	 address 32’h90400000 of the hex file. */
//	byte_index = 0
//	while (byte_index < NumberOfProtectionBytes)
//	{
		/* hexData[i] is from address (32’h90400000 + i) of hex file */
//		if (Data_Array[byte_index] != hexData[i])
//		{
//			FAIL_EXIT /* Byte mismatch. Verify operation for Protection bytes failed. Abort
//			 Operation, Exit */
//		}
//		byte_index = byte_index + 1
//	}
	/* Verify operation for Protection bytes passed. Go to next step */

}
unsigned char IBackPlane::validateChecksum() {
	//	byte 	StatusReg; //Variable to store the SPC status register value
	unsigned int StatusReg;
	//	byte	b1, b2, b3, b4; //Variables to store the Checksum read from the device
	unsigned int b1, b2, b3, b4;

	//	APACC ADDR Write [0x0000 4720]
	APACC(TRNS_ADDR, 0x0000, 0x4720);

	//	APACC DATA Write [0x0000 00B6] //First initiation key
	APACC(DATA_WR, 0x0000, 0x00B6);

	//	APACC ADDR Write [0x0000 4720]
	APACC(TRNS_ADDR, 0x0000, 4720);

	//	APACC DATA Write [0x0000 00DF] //0xDF = 0xD3 + 0x0C
	APACC(DATA_WR, 0x0000, 0x00DF);

	//	APACC ADDR Write [0x0000 4720]
	APACC(TRNS_ADDR, 0x0000, 0x4720);

	//	APACC DATA Write [0x0000 000C] // GET_CHECKSUM opcode
	APACC(DATA_WR, 0x0000, 0x000C);

	//	APACC ADDR Write [0x0000 4720]
	APACC(TRNS_ADDR, 0x0000, 0x4720);

	//	APACC DATA Write [0x0000 0000] //Flash array ID
	APACC(DATA_WR, 0x0000, 0x0000);

	//	APACC ADDR Write [0x0000 4720]
	APACC(TRNS_ADDR, 0x0000, 0x4720);

	//	APACC DATA Write [0x0000 0000] //Starting row number (lower byte)
	APACC(DATA_WR, 0x0000, 0x0000);

	//	APACC ADDR Write [0x0000 4720]
	APACC(TRNS_ADDR, 0x0000, 0x4720);

	//	APACC DATA Write [0x0000 0000] //Number of rows (higher byte)
	APACC(DATA_WR, 0x0000, 0x0000);

	//	APACC ADDR Write [0x0000 4720]
	APACC(TRNS_ADDR, 0x0000, 0x4720);

	//	Number of rows (lower byte) minus one
	//	APACC DATA Write [N - 1]

	//	APACC ADDR Write [0x0000 4722]
	APACC(TRNS_ADDR, 0x0000, 0x4722);

	//	  dummyByte = APACC DATA Read
	//	  //Dummy SWD Read, Next Read gives correct status
	//	  time_elapsed = 0
	//	  do
	//	  // Poll status register
	//	  {
	//	  StatusReg = (byte) APACC DATA Read // Save status register value
	//	  } while ((StatusReg != [0x01]) AND time_elapsed < 1 sec)
	//	  if (time_elapsed > 1 sec) then FAIL_EXIT
	//	  APACC ADDR Write [0x0000 4720]
	APACC(TRNS_ADDR, 0x0000, 0x4720);
	//	  dummyByte = APACC DATA Read// Dummy SWD read
	//	  b4 = (byte) APACC DATA Read
	//	  // Checksum byte 4 (MSB byte)
	//	  b3 = (byte) APACC DATA Read
	//	  // Checksum byte 3
	//	  b2 = (byte) APACC DATA Read
	//	  // Checksum byte 2
	//	  b1 = (byte) APACC DATA Read
	//	  // Checksum byte 1 (LSB byte)
	//	  read_checksum = [0xb2b1]// Save lower 2 bytes of checksum to a local variable
	//	  APACC ADDR Write [0x0000 4722]
	APACC(TRNS_ADDR, 0x0000, 0x4722);
	//	  dummyByte = APACC DATA Read
	//	  //Dummy SWD Read, Next Read gives correct status
	//	  time_elapsed = 0
	//	  do
	//	  // Poll status register till SPC is IDLE
	//	  {
	//	  StatusReg = (byte) APACC DATA Read // Save status register value
	//	  } while ((StatusReg != [0x02]) AND time_elapsed < 1 sec)
	//	  if (time_elapsed > 1 sec) then FAIL_EXIT
	//	  /* Compare with 2-byte checksum value in hex file (big endian format) at address 0x9030 0000.
	//	  Only the lower two bytes of checksum are stored in the hex file. The MSB byte is stored at
	//	  address 0x90300000, and the LSB byte is stored at address 0x90300001. */
	//	  if (read_checksum != hexfile_checksum) then FAIL_EXIT

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Q_EXPORT_PLUGIN2(InterfaceBackPlane,IBackPlane)
;

