#include "AD9102.h"

AD9102Component::AD9102Component(IApplicationCardInterface *pobj)
{
     objAppcard = pobj;
     objAppcard->setSPIAppendBit(0xC000);
}

void AD9102Component::writeAD9102SPI(unsigned short pAddress,unsigned short pData){

	pAddress =0x7FFF & pAddress;

	objAppcard->setSPIAppendBit(0xC000);
    objAppcard->setSPITXLSW(pData,SPI2);
    objAppcard->setSPITXMSW(pAddress,SPI2);
    objAppcard->setSPICW(0x07,SPI2);
    objAppcard->readSPIDriveDoneBit(SPI2);
}

unsigned short AD9102Component::readAD9102SPI(unsigned short pAddress){

	pAddress = pAddress | 0x8000;

	objAppcard->setSPIAppendBit(0xC000);
    objAppcard->setSPITXMSW(pAddress,SPI2);
    objAppcard->setSPITXLSW(0x0000,SPI2);
    objAppcard->setSPICW(0x07,SPI2);
    objAppcard->readSPIDriveDoneBit(SPI2);

    unsigned short l_nMSWData = objAppcard->getSPIRXMSW(SPI2);
    unsigned short l_nLSWData = objAppcard->getSPIRXLSW(SPI2);
    unsigned short l_nData = (l_nMSWData << 16) | l_nLSWData;
    return l_nData;

}
