#include "spimemoryinterface.h"


SPIMemoryInterface::SPIMemoryInterface(QObject *parent)
{
	Q_UNUSED(parent);
    QPluginLoader loader2("libBackPlaneInterface.so", this);
    IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
    IBackPlane->InitializeBpObject();
    //qDebug()<<"SPI Memory Initialized";
}

void SPIMemoryInterface::accessSPIMemory(SPIMEMORY_ACCESS pSPISelect)
{
	m_MemorySelect = pSPISelect;
}

unsigned int SPIMemoryInterface::getSPICodeID() {
	unsigned int l_nData=0;
		if(m_MemorySelect == BACKPLANE)
		{
			IBackPlane->writeBackPlaneRegister(0x9F00, BP_SPIFLASH_TXMSW);
			IBackPlane->writeBackPlaneRegister(0x0000, BP_SPIFLASH_TXLSW);
			IBackPlane->writeBackPlaneRegister(0xC007, BP_SPIFLASH_CMD);
			checkMemoryBusy();
			l_nData = 0x00FFFFFF&IBackPlane->readBackPlaneRegister(BP_SPIFLASH_RXMSW);
	        l_nData = l_nData << 16;
	        l_nData |= IBackPlane->readBackPlaneRegister(BP_SPIFLASH_RXLSW);
		}
		else if(m_MemorySelect == APPLICATIONCARD)
		{
			//qDebug()<<"SPIMemoryInterface::getSPICodeID-Appcard";
			IAppCard->setSPITXMSW(0x9F00,SPI1);
			IAppCard->setSPITXLSW(0x0000,SPI1);
			IAppCard->setSPICW(0x0207,SPI1);
			checkMemoryBusy();

			l_nData = 0x00FFFFFF & IAppCard->getSPIRXMSW(SPI1);
			//qDebug() << "MSW:"<<hex<<l_nData;
	        l_nData = l_nData << 16;
	        l_nData |= IAppCard->getSPIRXLSW(SPI1);
	        //qDebug() << "LSW:"<<hex<<l_nData;
		}
//	printf("MSW DATA:%X\n", l_nData);
//	printf("LSW DATA:%X\n", l_nData);
        return l_nData;
}
unsigned int SPIMemoryInterface::checkMemoryBusy() {
		if(m_MemorySelect == BACKPLANE)
			while (IBackPlane->readBackPlaneRegister(BP_SPIFLASH_CMD) & 0x0001);
		else{
			IAppCard->readSPIDriveDoneBit(SPI1);
			//usleep(100);
		}
        return 1;
}

unsigned int SPIMemoryInterface::stopDrive() {
		if(m_MemorySelect == BACKPLANE)
			IBackPlane->writeBackPlaneRegister(0xC060, BP_SPIFLASH_CMD);
		else
			IAppCard->setSPICW(0x260,SPI1);
        return 1;
}
unsigned int SPIMemoryInterface::writeEnable() {
	if(m_MemorySelect == BACKPLANE){
        IBackPlane->writeBackPlaneRegister(0x06, BP_SPIFLASH_TXLSW);
        IBackPlane->writeBackPlaneRegister(0xC001, BP_SPIFLASH_CMD);
        checkMemoryBusy();
	}
	else
	{
		IAppCard->setSPITXLSW(0x06,SPI1);
		IAppCard->setSPICW(0x201,SPI1);
		checkMemoryBusy();
	}
        return 1;
}
unsigned int SPIMemoryInterface::writeDisable() {
	if(m_MemorySelect == BACKPLANE){
        IBackPlane->writeBackPlaneRegister(0x04, BP_SPIFLASH_TXLSW);
        IBackPlane->writeBackPlaneRegister(0xC001, BP_SPIFLASH_CMD);
        checkMemoryBusy();
	}
	else
	{
		IAppCard->setSPITXLSW(0x04,SPI1);
		IAppCard->setSPICW(0x201,SPI1);
		checkMemoryBusy();

	}
        return 1;
}
unsigned int SPIMemoryInterface::bulkErase() {
    writeEnable();

	if(m_MemorySelect == BACKPLANE){
        IBackPlane->writeBackPlaneRegister(0xC7, BP_SPIFLASH_TXLSW);
        IBackPlane->writeBackPlaneRegister(0xC001, BP_SPIFLASH_CMD);
        checkMemoryBusy();
        usleep(100000);
	}
	else
	{
		IAppCard->setSPITXLSW(0xC7,SPI1);
		IAppCard->setSPICW(0x201,SPI1);
	}
    writeDisable();
    sleep(10); // sleep(25);
    return 1;
}
unsigned int SPIMemoryInterface::spiTxLsw(unsigned int pData) {
		if(m_MemorySelect == BACKPLANE)
			IBackPlane->writeBackPlaneRegister(pData, BP_SPIFLASH_TXLSW);
		else
			IAppCard->setSPITXLSW(pData,SPI1);
        return 1;
}
unsigned int SPIMemoryInterface::spiTxMsw(unsigned int pData) {
	if(m_MemorySelect == BACKPLANE)
        IBackPlane->writeBackPlaneRegister(pData, BP_SPIFLASH_TXMSW);
	else
		IAppCard->setSPITXMSW(pData,SPI1);
        return 1;
}
unsigned int SPIMemoryInterface::spiRxLsw() {
	if(m_MemorySelect == BACKPLANE)
        IBackPlane->readBackPlaneRegister(BP_SPIFLASH_RXLSW);
	else
		IAppCard->getSPIRXLSW(SPI1);
        return 1;
}
unsigned int SPIMemoryInterface::spiRxMsw() {
	if(m_MemorySelect == BACKPLANE)
        IBackPlane->readBackPlaneRegister(BP_SPIFLASH_RXMSW);
	else
		IAppCard->getSPIRXMSW(SPI1);
        return 1;
}
unsigned int SPIMemoryInterface::startTransmit() {
	if(m_MemorySelect == BACKPLANE)
        IBackPlane->writeBackPlaneRegister(0xC047, BP_SPIFLASH_CMD);
	else
		IAppCard->setSPICW(0x247,SPI1);
        return 1;
}
unsigned int SPIMemoryInterface::startTransmit2() {
	if(m_MemorySelect == BACKPLANE)
        IBackPlane->writeBackPlaneRegister(0xC041, BP_SPIFLASH_CMD);
	else
		IAppCard->setSPICW(0x241,SPI1);
        return 1;
}
unsigned int SPIMemoryInterface::readSPIFile(unsigned int pAddress, unsigned int pBytes) {
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
unsigned int SPIMemoryInterface::startTx8Bit() {
        IBackPlane->writeBackPlaneRegister(0xC049, BP_SPIFLASH_CMD);
        return 1;
}

void SPIMemoryInterface::checkSPIMemoryWrite()
{

	//qDebug()<<"check SPI Memory Write";
	unsigned int l_npageWrLsw, l_npageWrMsw, l_npageWrite;
    writeEnable();
    l_npageWrite = 0x0A000000;
    l_npageWrLsw = l_npageWrite & 0x0000FFFF;
    l_npageWrMsw = (l_npageWrite & 0xFFFF0000) >> 16;
	IAppCard->setSPITXLSW(l_npageWrLsw,SPI1);
	IAppCard->setSPITXMSW(l_npageWrMsw,SPI1);
	IAppCard->setSPICW(0x247,SPI1);
	checkMemoryBusy();
	IAppCard->setSPITXLSW(0xAA,SPI1);
	IAppCard->setSPICW(0x241,SPI1);
	checkMemoryBusy();
    stopDrive();
    usleep(100000);
    writeDisable();
}
void SPIMemoryInterface::checkSPIMemoryRead()
{
    unsigned int l_npageRead, l_npageRdLsw, l_npageRdMsw, l_nSpi1Busy;
    //unsigned short int *l_npageRetlsw;
    //l_npageRetlsw = new unsigned short int[bytes];

    l_npageRead = 0x03000000;
    l_npageRdLsw = l_npageRead & 0x0000FFFF;
    l_npageRdMsw = (l_npageRead & 0xFFFF0000) >> 16;
	IAppCard->setSPITXLSW(l_npageRdLsw,SPI1);
	IAppCard->setSPITXMSW(l_npageRdMsw,SPI1);
	IAppCard->setSPICW(0x247,SPI1);
	//usleep(10000);
	checkMemoryBusy();
	IAppCard->setSPICW(0x249,SPI1);
	//usleep(1000);
	checkMemoryBusy();
	stopDrive();
	//qDebug()<<"Data:"<<(IAppCard->getSPIRXLSW(SPI1) & 0x00FF);
}
void SPIMemoryInterface::writeSPIMemory(unsigned int pnWraddr, unsigned int pnBytes,
                unsigned short int *pnData)
{
		//IAppCard->setSPIAppendBit(0xC000);
		//qDebug()<<"Memory Select:"<<m_MemorySelect;
        unsigned int l_npageWrLsw, l_npageWrMsw, l_npageWrite, l_nLoopIndex;
        unsigned short int *l_nWriteData = pnData;
        unsigned int l_nTemp, l_nSpiBusy;

        // Taking Starting address of the page.
        unsigned int l_nDiffBytes;
        l_nDiffBytes = pnWraddr & 0xFF;
        l_nDiffBytes = 0xFF - l_nDiffBytes;
	//qDebug() << "Difference Bytes:" << hex<<l_nDiffBytes;
	//qDebug() << "Starting Address:" << pnWraddr;
        if (l_nDiffBytes >= pnBytes) {
                writeEnable();
                l_npageWrite = 0x0A000000 | pnWraddr;
                l_npageWrLsw = l_npageWrite & 0x0000FFFF;
                l_npageWrMsw = (l_npageWrite & 0xFFFF0000) >> 16;
                if(m_MemorySelect == BACKPLANE)
                {
					IBackPlane->writeBackPlaneRegister(l_npageWrLsw, BP_SPIFLASH_TXLSW);
					IBackPlane->writeBackPlaneRegister(l_npageWrMsw, BP_SPIFLASH_TXMSW);
					IBackPlane->writeBackPlaneRegister(0xC047, BP_SPIFLASH_CMD); //start transmission,32bit drive
                }
                else
                {
                	IAppCard->setSPITXLSW(l_npageWrLsw,SPI1);
                	IAppCard->setSPITXMSW(l_npageWrMsw,SPI1);
                	IAppCard->setSPICW(0x247,SPI1);
                }
        //}
                //qDebug()<< "1";
                usleep(1000);
				l_nSpiBusy = checkMemoryBusy();
                for (l_nLoopIndex = 0; l_nLoopIndex < pnBytes; l_nLoopIndex++) {
                      //  qDebug() <<"Index:"<<hex<<l_nLoopIndex<<"Write Data 0:" << l_nWriteData[l_nLoopIndex];
                	if(m_MemorySelect == BACKPLANE){
                        IBackPlane->writeBackPlaneRegister(l_nWriteData[l_nLoopIndex],
                                        BP_SPIFLASH_TXLSW);
                        IBackPlane->writeBackPlaneRegister(0xC041, BP_SPIFLASH_CMD); //start transmission
                	}
                	else
                	{
                		IAppCard->setSPITXLSW(l_nWriteData[l_nLoopIndex],SPI1);
                		IAppCard->setSPICW(0x241,SPI1);
                	}
                	//usleep(1000);
                    l_nSpiBusy = checkMemoryBusy();
                }
                stopDrive();
                writeDisable();
                usleep(50000);
               // qDebug()<< "2";
        }
        else
        {
                l_nTemp = pnBytes;
                pnBytes = l_nDiffBytes; // Write the Left out Bytes
                writeEnable();
                //qDebug()<<"Address:"<<hex<<pnWraddr;
                l_npageWrite = 0x0A000000 | pnWraddr;
               // qDebug() << "Starting Address1:" << hex<<l_npageWrite;
                l_npageWrLsw = l_npageWrite & 0x0000FFFF;
                l_npageWrMsw = (l_npageWrite & 0xFFFF0000) >> 16;
                if(m_MemorySelect == BACKPLANE)
                {
					IBackPlane->writeBackPlaneRegister(l_npageWrLsw, BP_SPIFLASH_TXLSW);
					IBackPlane->writeBackPlaneRegister(l_npageWrMsw, BP_SPIFLASH_TXMSW);
					IBackPlane->writeBackPlaneRegister(0xC047, BP_SPIFLASH_CMD); //start transmission,32bit drive
                }
                else
                {
                	IAppCard->setSPITXLSW(l_npageWrLsw,SPI1);
                	IAppCard->setSPITXMSW(l_npageWrMsw,SPI1);
                	IAppCard->setSPICW(0x247,SPI1);
                }
                usleep(1000);
              //  qDebug()<< "3";
                l_nSpiBusy = checkMemoryBusy();
                for (l_nLoopIndex = 0; l_nLoopIndex <= pnBytes; l_nLoopIndex++) {
                      //  qDebug() <<"Index:"<<l_nLoopIndex<<"Write Data 1:" << hex<<l_nWriteData[l_nLoopIndex];
                	if(m_MemorySelect == BACKPLANE){
                        IBackPlane->writeBackPlaneRegister(l_nWriteData[l_nLoopIndex],
                                        BP_SPIFLASH_TXLSW);
                        IBackPlane->writeBackPlaneRegister(0xC041, BP_SPIFLASH_CMD); //start transmission


                	}
                	else
                	{
                		IAppCard->setSPITXLSW(l_nWriteData[l_nLoopIndex],SPI1);
                		IAppCard->setSPICW(0x241,SPI1);

                	}
                	// usleep(1000);
                	l_nSpiBusy = checkMemoryBusy();
                }
                stopDrive();
                writeDisable();
                usleep(50000);

               // qDebug()<< "4";
                l_npageWrite = l_npageWrite + l_nDiffBytes;
                l_npageWrite++;
              //  qDebug() << "Starting Address2:" << hex<<l_npageWrite;
                writeEnable();
                pnBytes = l_nTemp;
                l_npageWrLsw = l_npageWrite & 0x0000FFFF;
                l_npageWrMsw = (l_npageWrite & 0xFFFF0000) >> 16;
                if(m_MemorySelect == BACKPLANE)
				{
					IBackPlane->writeBackPlaneRegister(l_npageWrLsw, BP_SPIFLASH_TXLSW);
					IBackPlane->writeBackPlaneRegister(l_npageWrMsw, BP_SPIFLASH_TXMSW);
					IBackPlane->writeBackPlaneRegister(0xC047, BP_SPIFLASH_CMD); //start transmission,32bit drive

				}
				else
				{
					IAppCard->setSPITXLSW(l_npageWrLsw,SPI1);
					IAppCard->setSPITXMSW(l_npageWrMsw,SPI1);
					IAppCard->setSPICW(0x247,SPI1);
				}
                usleep(1000);
                l_nSpiBusy = checkMemoryBusy();
                for (l_nLoopIndex = l_nDiffBytes + 1; l_nLoopIndex < pnBytes; l_nLoopIndex++) {
                     //   qDebug() <<"Index:"<<l_nLoopIndex<<"Write Data 2:" << hex<<l_nWriteData[l_nLoopIndex];
                	if(m_MemorySelect == BACKPLANE){
                        IBackPlane->writeBackPlaneRegister(l_nWriteData[l_nLoopIndex],
                                        BP_SPIFLASH_TXLSW);
                        IBackPlane->writeBackPlaneRegister(0xC041, BP_SPIFLASH_CMD); //start transmission

                	}
                	else
                	{
                		IAppCard->setSPITXLSW(l_nWriteData[l_nLoopIndex],SPI1);
                		IAppCard->setSPICW(0x241,SPI1);
                	}
                	//usleep(1000);
                	 l_nSpiBusy = checkMemoryBusy();
                }
                stopDrive();
                writeDisable();
                usleep(50000);
        }
}

unsigned int SPIMemoryInterface::WriteSPI(unsigned int pgWraddr, unsigned int l_nBytes,
                unsigned short int *l_nWriteData) {
        unsigned int l_npageWrLsw, l_npageWrMsw, l_npageWrite, l_nSpiBusy, a;
        unsigned short int *l_ndataWr;
        l_ndataWr = l_nWriteData;
        l_npageWrite = 0x0A000000 | pgWraddr;
        //qDebug() << "Page Write:"<<l_npageWrite;
        l_npageWrLsw = l_npageWrite & 0x0000FFFF;
        //qDebug()<< "Page Write LSW:"<<l_npageWrLsw;
        printf("page writelsw %x\n", l_npageWrLsw);
        l_npageWrMsw = (l_npageWrite & 0xFFFF0000) >> 16;
        //qDebug()<< "Page Write LSW:"<<l_npageWrMsw;

        if(m_MemorySelect == BACKPLANE)
		{
			IBackPlane->writeBackPlaneRegister(l_npageWrLsw, BP_SPIFLASH_TXLSW);
			IBackPlane->writeBackPlaneRegister(l_npageWrMsw, BP_SPIFLASH_TXMSW);
			IBackPlane->writeBackPlaneRegister(0xC047, BP_SPIFLASH_CMD); //start transmission,32bit drive
		}
		else
		{
			IAppCard->setSPITXLSW(l_npageWrLsw,SPI1);
			IAppCard->setSPITXMSW(l_npageWrMsw,SPI1);
			IAppCard->setSPICW(0x247,SPI1);
		}
        usleep(1000);
        l_nSpiBusy = checkMemoryBusy();
        //printf("Check busy  %x\n",l_nSpiBusy);
        for (a = 0; a < l_nBytes; a++) {
                //printf("data value %x\n",l_ndataWr[a]);
        	if(m_MemorySelect == BACKPLANE){
                IBackPlane->writeBackPlaneRegister(l_nWriteData[a],
                                BP_SPIFLASH_TXLSW);
                IBackPlane->writeBackPlaneRegister(0xC041, BP_SPIFLASH_CMD); //start transmission
        	}
        	else
        	{
        		IAppCard->setSPITXLSW(l_nWriteData[a],SPI1);
        		IAppCard->setSPICW(0x241,SPI1);
        	}
           l_nSpiBusy = checkMemoryBusy();
        }
        stopDrive();
        writeDisable();
        usleep(500000);
        return 1;
}
void SPIMemoryInterface::pageErase(unsigned int pgErAddr) {
        unsigned int l_npageErase = 0, l_npageErLsw = 0, l_npageErMsw = 0;
        l_npageErase = 0xDB000000 | pgErAddr;
        l_npageErLsw = l_npageErase & 0x0000FFFF;
        l_npageErMsw = (l_npageErase & 0xFFFF0000) >> 16;

        writeEnable();
        if(m_MemorySelect == BACKPLANE)
		{
			IBackPlane->writeBackPlaneRegister(l_npageErLsw, BP_SPIFLASH_TXLSW);
			IBackPlane->writeBackPlaneRegister(l_npageErMsw, BP_SPIFLASH_TXMSW);
			IBackPlane->writeBackPlaneRegister(0xC007, BP_SPIFLASH_CMD); //start transmission,32bit drive
		}
		else
		{
			IAppCard->setSPITXLSW(l_npageErLsw,SPI1);
			IAppCard->setSPITXMSW(l_npageErMsw,SPI1);
			IAppCard->setSPICW(0x207,SPI1);
		}
        checkMemoryBusy();
        usleep(50000);
        writeDisable();
        printf("Page Erased\n");
}
unsigned short int* SPIMemoryInterface::ReadSPI(unsigned int pgRdaddr, unsigned int bytes) {

	//IAppCard->setSPIAppendBit(0xC000);
		unsigned int l_npageRead, l_npageRdLsw, l_npageRdMsw, l_nSpi1Busy;
        unsigned short int *l_npageRetlsw;
        int b;
        //scanf("%d",&bytes);
        l_npageRetlsw = new unsigned short int[bytes];
        l_npageRead = 0x03000000 | pgRdaddr;
//	printf("page Read %x\n", l_npageRead);
        l_npageRdLsw = l_npageRead & 0x0000FFFF;
//	printf("page Read LSW%x\n", l_npageRdLsw);
        l_npageRdMsw = (l_npageRead & 0xFFFF0000) >> 16;
//	printf("page Read MSW%x\n", l_npageRdMsw);
        if(m_MemorySelect == BACKPLANE)
		{
			IBackPlane->writeBackPlaneRegister(l_npageRdLsw, BP_SPIFLASH_TXLSW);
			IBackPlane->writeBackPlaneRegister(l_npageRdMsw, BP_SPIFLASH_TXMSW);
			IBackPlane->writeBackPlaneRegister(0xC047, BP_SPIFLASH_CMD); //start transmission,32bit drive
		}
		else
		{
			IAppCard->setSPITXLSW(l_npageRdLsw,SPI1);
			IAppCard->setSPITXMSW(l_npageRdMsw,SPI1);
			IAppCard->setSPICW(0x247,SPI1);
		}
        usleep(10000);
        l_nSpi1Busy = checkMemoryBusy();
        //printf("Check busy  %x\n",l_nSpi1Busy);
        for (b = 0; b < bytes; b++) {
            	if(m_MemorySelect == BACKPLANE){
                    IBackPlane->writeBackPlaneRegister(0xC049, BP_SPIFLASH_CMD); //start transmission
            	}
            	else
            	{
            		IAppCard->setSPICW(0x249,SPI1);
            	}
                usleep(1000);
                l_nSpi1Busy = checkMemoryBusy();
                //printf("Check busy  %x\n",l_nSpi1Busy);
                if(m_MemorySelect == BACKPLANE){
                	l_npageRetlsw[b] = IBackPlane->readBackPlaneRegister(BP_SPIFLASH_RXLSW) & 0x00FF;
                }
                else
                	l_npageRetlsw[b] = IAppCard->getSPIRXLSW(SPI1) & 0x00FF;
              //  qDebug() << "Read Data:" <<hex<<l_npageRetlsw[b];
                //printf("page readlsw  %x\n",l_npageRetlsw[b]);
        }
        stopDrive();
        return &l_npageRetlsw[0];
}

void SPIMemoryInterface::setHardwarwObject(IApplicationCardInterface *pObj)
{
	IAppCard = pObj;
	IAppCard->setSPIAppendBit(0xC000);
}

unsigned short int* SPIMemoryInterface::readAppCardSystemMemory(unsigned int pStartAddr, unsigned short pCount)
{
	unsigned short int *l_npageRetlsw;
	l_npageRetlsw = new unsigned short int[pStartAddr+pCount];
	unsigned short int l_nAddressIndex=0;
    for (unsigned short b = pStartAddr; b < (pStartAddr+pCount)*2; b+=2)
    {
            l_npageRetlsw[l_nAddressIndex++] = IAppCard->readRegister(b);
    }
    return &l_npageRetlsw[0];
}

void SPIMemoryInterface::writeAppCardSystemMemory(unsigned int pgWraddr, unsigned int l_nBytes,
                unsigned short int *l_nWriteData)
{
	unsigned short l_nWriteIndex=0;
	if(l_nBytes == 1){
		IAppCard->writeRegister(l_nWriteData[l_nWriteIndex],pgWraddr);
		return;
	}
	for(unsigned  int l_nAddressIndex = pgWraddr;l_nAddressIndex< (pgWraddr+l_nBytes)*2;l_nAddressIndex+=2)
	{
		IAppCard->writeRegister(l_nWriteData[l_nWriteIndex],l_nAddressIndex);
	}
}

unsigned short int* SPIMemoryInterface::readBackPanelCardSystemMemory(unsigned int pStartAddr, unsigned short pCount)
{
	unsigned short int *l_npageRetlsw;
	l_npageRetlsw = new unsigned short int[pStartAddr+pCount];
	unsigned short int l_nAddressIndex=0;
    for (unsigned short b = pStartAddr; b < (pStartAddr+pCount)*2; b+=2)
    {
            l_npageRetlsw[l_nAddressIndex++] = IBackPlane->readBackPlaneRegister(b);
    }
    return &l_npageRetlsw[0];

}

void SPIMemoryInterface::writeBackPanelSystemMemory(unsigned int pgWraddr, unsigned int l_nBytes,
                unsigned short int *l_nWriteData)
{
	unsigned short l_nWriteIndex=0;
	if(l_nBytes == 1){
		IBackPlane->writeBackPlaneRegister(l_nWriteData[l_nWriteIndex],pgWraddr);
		return;
	}
	for(unsigned  int l_nAddressIndex = pgWraddr;l_nAddressIndex< (pgWraddr+l_nBytes)*2;l_nAddressIndex+=2)
	{
		IBackPlane->writeBackPlaneRegister(l_nWriteData[l_nWriteIndex++],l_nAddressIndex);
	}
}

void SPIMemoryInterface::accessSPIRAM(RAM_MODE pRAMSelect)
{
	m_RAMModeSelect = pRAMSelect;
	//qDebug() << "RAMMODE:" << m_RAMModeSelect;
}

void SPIMemoryInterface::setAutoIncrement()
{
	RAMACCESS pstAccess;

	pstAccess.m_bDRAMMODE =pstAccess.m_bRRAM1MODE=pstAccess.m_bRRAM2MODE = false;
	IAppCard->setRAMModeAccess(pstAccess);
	//qDebug() << "setAutoIncrement:" << m_RAMModeSelect;
}

void SPIMemoryInterface::SingleWriteAPPCardSRAM(unsigned int pgWraddr,unsigned short pData)
{
	setAutoIncrement();
	IAppCard->setRAMADDR(pgWraddr);
	if(m_RAMModeSelect == DRIVERAM)
		IAppCard->setDriveRAMData(pData&0x3FFF);
	else if(m_RAMModeSelect == RECEIVERAM)
		IAppCard->setReceiveRAMData(pData&0x3FFF);
}

unsigned short int SPIMemoryInterface::SingleReadAPPCardSRAM(unsigned int pgRdAddr)
{
	IAppCard->setRAMADDR(pgRdAddr);
	return IAppCard->readDriveRAMData();
}

void SPIMemoryInterface::writeAppCardSRAM(unsigned int pgWraddr, unsigned int l_nBytes,
        unsigned short int *l_nWriteData)
{
	//IAppCard->setDriveRAMStarAddress(pgWraddr|0x1000);
	//qDebug()<<"Write SRAM";
	unsigned short l_nCount = l_nBytes;
	if( (pgWraddr + l_nBytes) > 0xFFF)
	{
		l_nCount = (pgWraddr + l_nBytes) -0xFFF;
	}

	//qDebug() << "Address:" << hex<< (pgWraddr|0x1000);
	IAppCard->setRAMADDR(pgWraddr|0x1000);

	for(unsigned  int l_nAddressIndex = pgWraddr;l_nAddressIndex< (pgWraddr+l_nCount);l_nAddressIndex++)
	{
		//qDebug()<< "Data1:"<<hex<<l_nWriteData[l_nAddressIndex];
		if(m_RAMModeSelect == DRIVERAM)
			IAppCard->setDriveRAMData(l_nWriteData[l_nAddressIndex]&0x3FFF);
		else if(m_RAMModeSelect == RECEIVERAM)
			IAppCard->setReceiveRAMData(l_nWriteData[l_nAddressIndex]&0x3FFF);
	}
}

void SPIMemoryInterface::setSRAMPageSize(short int pSize)
{
	//m_npageRetlsw = new unsigned short int[pSize];
}

void SPIMemoryInterface::setReadCount(short int pCount)
{
	m_npageRetlsw = new unsigned short int[pCount];
}
void SPIMemoryInterface::readAppCardSRAM(unsigned int pStartAddr, unsigned short pCount,bool pValue)
{
	Q_UNUSED(pValue)
	  FILE *fpWaveFile;
		unsigned short l_nCount = pCount;

	  	  unsigned short l_nValue=0;
	    if(m_RAMModeSelect == DRIVERAM){
	    	fpWaveFile = fopen("./DWaveData.txt","w");
	    }
	    if(m_RAMModeSelect == RECEIVERAM)
	    {
	    	fpWaveFile = fopen("./RWaveData.txt","w");
	    }
		IAppCard->setRAMADDR(pStartAddr|0x1000);
		for(unsigned  int l_nAddressIndex = 0;l_nAddressIndex< (pStartAddr+l_nCount);l_nAddressIndex++)
		{
			if(m_RAMModeSelect == DRIVERAM){
				l_nValue = IAppCard->readDriveRAMData()&0x3FFF;
			}
			else if(m_RAMModeSelect == RECEIVERAM){
				l_nValue = IAppCard->readReceiveRAMData()&0x3FFF;
			}
			fprintf(fpWaveFile,"%X\n",l_nValue);
		}
		fclose(fpWaveFile);
		fpWaveFile=0;

}
unsigned short int* SPIMemoryInterface::readAppCardSRAM(unsigned int pStartAddr, unsigned short pCount)
{
	unsigned short int l_npageRetlsw[pStartAddr+pCount];
	unsigned short l_nCount = pCount;
	if( (pStartAddr + pCount) > 0xFFF)
	{
		l_nCount = (pStartAddr + pCount) -0xFFF;
	}
	  FILE *fpWaveFile;
	    unsigned short l_nWaveCount=0;
	    if(m_RAMModeSelect == DRIVERAM){
	    	fpWaveFile = fopen("./DWaveData.txt","w");
	    }
	    if(m_RAMModeSelect == RECEIVERAM)
	    {
	    	fpWaveFile = fopen("./RWaveData.txt","w");
	    }
	//setReadCount(pStartAddr+pCount);
	//qDebug()<< "Address:" <<(pStartAddr) <<"Count:"<<pCount;
	//l_npageRetlsw = new unsigned short int[pStartAddr + pCount];
	//qDebug() << "Address:" <<hex<< (pStartAddr|0x1000);
	IAppCard->setRAMADDR(pStartAddr|0x1000);
	for(unsigned  int l_nAddressIndex = 0;l_nAddressIndex< (pStartAddr+l_nCount);l_nAddressIndex++)
	{
		if(m_RAMModeSelect == DRIVERAM){
			l_npageRetlsw[l_nAddressIndex] = IAppCard->readDriveRAMData()&0x3FFF;
			//m_npageRetlsw[l_nAddressIndex] = l_npageRetlsw[l_nAddressIndex];
		}
		else if(m_RAMModeSelect == RECEIVERAM){
			l_npageRetlsw[l_nAddressIndex] = IAppCard->readReceiveRAMData()&0x3FFF;
			//m_npageRetlsw[l_nAddressIndex] = l_npageRetlsw[l_nAddressIndex];
		}
		fprintf(fpWaveFile,"%X\n",l_npageRetlsw[l_nAddressIndex]);
		//usleep(10);
		//qDebug() << "SRAM Data:"<<hex<<l_npageRetlsw[l_nAddressIndex];
	}
	fclose(fpWaveFile);
	return &l_npageRetlsw[0];
	//return m_npageRetlsw;
}

Q_EXPORT_PLUGIN2(ISPIMemoryInterface, SPIMemoryInterface)
;
