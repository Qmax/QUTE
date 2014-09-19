#include "ISLA118P50.h"

ISLA118P50::ISLA118P50(IApplicationCardInterface *pobj){
    objAppcard = pobj;
    m_nSPIAppendBit = ACTIVE_LOW_CLKPOL;

    objAppcard->setSPIClock(14,SPI5);





}

void ISLA118P50::configureADCChip(){

}

unsigned short ISLA118P50::readChipVersion(){

    unsigned short int pAddress=0;

    pAddress = pAddress | ONE_BYTE;
    pAddress = pAddress | CHIP_VER;
    pAddress = pAddress | READ_MODE;

    objAppcard->setSPIAppendBit(ACTIVE_LOW_CLKPOL);
    objAppcard->setSPITXMSW(pAddress,SPI5);
    objAppcard->setSPICW(DRIVE_24BIT,SPI5);
    objAppcard->readSPIDriveDoneBit(SPI5);
    usleep(1000);

    unsigned short int l_nLSWData = objAppcard->getSPIRXLSW(SPI5);
    usleep(1000);

    qDebug()<<"RXMSW:"<<hex<<objAppcard->getSPIRXMSW(SPI5);
    qDebug()<<"RXLSW:"<<hex<<objAppcard->getSPIRXLSW(SPI5);

    return l_nLSWData;

}

unsigned short ISLA118P50::readChipID(){

        unsigned short int pAddress=0;

        pAddress = pAddress | ONE_BYTE;  //One-Byte Read
        pAddress = pAddress | CHIP_ID;   //Read Chip ID
        pAddress = pAddress | READ_MODE;    //Read Selection

        objAppcard->setSPIAppendBit(ACTIVE_LOW_CLKPOL);    //Active Low selection
        objAppcard->setSPITXMSW(pAddress,SPI5);
        objAppcard->setSPICW(DRIVE_32BIT,SPI5);
        objAppcard->readSPIDriveDoneBit(SPI5);
        usleep(1000);
    	        
        unsigned short l_nLSWData = objAppcard->getSPIRXLSW(SPI5);
        usleep(1000);

        qDebug()<<"RXMSW:"<<hex<<objAppcard->getSPIRXMSW(SPI5);
        qDebug()<<"RXLSW:"<<hex<<objAppcard->getSPIRXLSW(SPI5);

        return l_nLSWData;
}
