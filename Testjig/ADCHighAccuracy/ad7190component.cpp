#include "ad7190component.h"

AD7190Component::AD7190Component(IApplicationCardInterface *pobj)
{
     m_mapSPISelect.insert(0,SPI3);
     m_mapSPISelect.insert(1,SPI4);
     objAppcard = pobj;
     m_nSPIAppendBit = 0xC000;
}

void AD7190Component::resetADC(unsigned short pIndex)
{
    //pIndex =-1;
    objAppcard->setSPITXLSW(0x00FF,m_mapSPISelect.value(pIndex-1));
    objAppcard->setSPITXMSW(0xFFFF,m_mapSPISelect.value(pIndex-1));
    objAppcard->setSPICW(0x43,m_mapSPISelect.value(pIndex-1));
    //usleep(100);
    objAppcard->readSPIDriveDoneBit(m_mapSPISelect.value(pIndex-1));
    objAppcard->setSPITXLSW(0xFFFF,m_mapSPISelect.value(pIndex-1));
    objAppcard->setSPICW(0x47,m_mapSPISelect.value(pIndex-1));
    //usleep(100);
    objAppcard->readSPIDriveDoneBit(m_mapSPISelect.value(pIndex-1));
    objAppcard->setSPICW(0x60,m_mapSPISelect.value(pIndex-1));
}

unsigned short AD7190Component::readADCStatusRegister(unsigned short pIndex)
{
   if(pIndex == 1)
   {
    objAppcard->setSPITXLSW(0x40FF,SPI3);
    objAppcard->setSPICW(0x03,SPI3);
    objAppcard->readSPIDriveDoneBit(SPI3);
   }
   else if (pIndex ==2)
   {
       objAppcard->setSPITXLSW(0x00FF,SPI4);
       objAppcard->setSPICW(0x03,SPI4);
       objAppcard->readSPIDriveDoneBit(SPI4);
   }
   return 0;
}

unsigned int AD7190Component::readADCModeRegister(unsigned short pIndex)
{
    pIndex =pIndex-1;
    unsigned int l_nModeData=0,l_nMSWData=0;
    objAppcard->setSPITXLSW(0xFFFF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPITXMSW(0x48FF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPICW(0x07,m_mapSPISelect.value(pIndex));
    objAppcard->readSPIDriveDoneBit(m_mapSPISelect.value(pIndex));
    l_nMSWData = objAppcard->getSPIRXMSW(m_mapSPISelect.value(pIndex));
    l_nModeData = (l_nMSWData << 16) | ( objAppcard->getSPIRXLSW(m_mapSPISelect.value(pIndex)));
    return l_nModeData;
}

void AD7190Component::writeADCModeRegister(unsigned short pIndex, unsigned int pModeData)
{
	pIndex =pIndex-1;
    unsigned int l_nLSWData=0x8;
    l_nLSWData = (l_nLSWData<<8) |((pModeData & 0x00FF0000)>>16);
    //qDebug() <<"Data1:"<<hex<<l_nLSWData;

    unsigned int l_nMSWData=pModeData & 0x0000FFFF;
   // qDebug() << "Data2:"<<hex<<l_nMSWData;
    objAppcard->setSPITXLSW(l_nMSWData,m_mapSPISelect.value(pIndex));
    objAppcard->setSPITXMSW(l_nLSWData,m_mapSPISelect.value(pIndex));
    objAppcard->setSPICW(0x07,m_mapSPISelect.value(pIndex));
}

unsigned int AD7190Component::readADCConfigurationRegister(unsigned short pIndex)
{
    unsigned int l_nConfigurationData=0,l_nMSWData=0;
    pIndex =pIndex-1;
    objAppcard->setSPITXMSW(0x50FF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPITXLSW(0xFFFF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPICW(0x07,m_mapSPISelect.value(pIndex));
    objAppcard->readSPIDriveDoneBit(m_mapSPISelect.value(pIndex));
   // usleep(50000);
    l_nMSWData = objAppcard->getSPIRXMSW(m_mapSPISelect.value(pIndex));
   // qDebug()<<"MSW Data:"<<hex<<l_nMSWData;
    l_nConfigurationData = (l_nMSWData << 16) | (objAppcard->getSPIRXLSW(m_mapSPISelect.value(pIndex)));
  //  qDebug()<<"Configuration Data:"<<hex<<l_nConfigurationData;
    return l_nConfigurationData;
 }

void AD7190Component::writeADCConfigurationRegister(unsigned short pIndex, unsigned int pConfigurationData)
{
	pIndex =pIndex-1;
    unsigned int l_nLSWData=0x10;
    l_nLSWData = (l_nLSWData<<8) |((pConfigurationData & 0x00FF0000)>>16);
    unsigned int l_nMSWData=pConfigurationData & 0x0000FFFF;
    objAppcard->setSPITXLSW(l_nMSWData,m_mapSPISelect.value(pIndex));
    objAppcard->setSPITXMSW(l_nLSWData,m_mapSPISelect.value(pIndex));
    objAppcard->setSPICW(0x07,m_mapSPISelect.value(pIndex));

}

unsigned int AD7190Component::readADCDataRegister(unsigned short pIndex)
{
    unsigned int l_nData=0,l_nMSWData=0;
    pIndex =pIndex-1;
    objAppcard->setSPITXMSW(0x58FF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPITXLSW(0xFFFF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPICW(0x07,m_mapSPISelect.value(pIndex));
    objAppcard->readSPIDriveDoneBit(m_mapSPISelect.value(pIndex));
    l_nMSWData = objAppcard->getSPIRXMSW(m_mapSPISelect.value(pIndex));
    l_nData = (l_nMSWData << 16) | (objAppcard->getSPIRXLSW(m_mapSPISelect.value(pIndex)));
    return l_nData;
}

unsigned short AD7190Component::readADCIDRegister(unsigned short pIndex)
{
	pIndex =pIndex-1;
    objAppcard->setSPITXLSW(0x60FF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPICW(0x03,m_mapSPISelect.value(pIndex));
    objAppcard->readSPIDriveDoneBit(m_mapSPISelect.value(pIndex));
    return objAppcard->getSPIRXLSW(m_mapSPISelect.value(pIndex));
}

unsigned short AD7190Component::readADCGPConRegister(unsigned short pIndex)
{
	pIndex =pIndex-1;
    objAppcard->setSPITXLSW(0x68FF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPICW(0x03,m_mapSPISelect.value(pIndex));
    objAppcard->readSPIDriveDoneBit(m_mapSPISelect.value(pIndex));
    return objAppcard->getSPIRXLSW(m_mapSPISelect.value(pIndex));
}

void AD7190Component::writeADCGPConRegister(unsigned short pIndex, unsigned int pGpConfigurationData)
{
    pIndex-=1;
    unsigned short l_nMSWData=0x28;
    printf("MSW DATA %x\n",l_nMSWData);
    unsigned short l_nLSWData=pGpConfigurationData & 0x00FF;
    l_nLSWData = (l_nMSWData << 8) | pGpConfigurationData;
    qDebug()<<"DATA :"<<hex<<l_nLSWData;
    objAppcard->setSPITXLSW(l_nLSWData,m_mapSPISelect.value(pIndex));
    objAppcard->setSPICW(0x03,m_mapSPISelect.value(pIndex));
    objAppcard->readSPIDriveDoneBit(m_mapSPISelect.value(pIndex));
}

unsigned int AD7190Component::readADCFullScaleRegister(unsigned short pIndex)
{
    unsigned int l_nFullScaleData=0,l_nMSWData=0;
    pIndex =pIndex-1;
    objAppcard->setSPITXMSW(0x78FF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPITXLSW(0xFFFF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPICW(0x07,m_mapSPISelect.value(pIndex));
    objAppcard->readSPIDriveDoneBit(m_mapSPISelect.value(pIndex));
    l_nMSWData = objAppcard->getSPIRXMSW(m_mapSPISelect.value(pIndex));
    l_nFullScaleData = (l_nMSWData << 16) | (objAppcard->getSPIRXLSW(m_mapSPISelect.value(pIndex)));
    return l_nFullScaleData;
}

unsigned int AD7190Component::readADCOffsetRegister(unsigned short pIndex)
{
    unsigned int l_nOffsetData=0,l_nMSWData=0;
    pIndex =pIndex-1;
    objAppcard->setSPITXMSW(0x70FF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPITXLSW(0xFFFF,m_mapSPISelect.value(pIndex));
    objAppcard->setSPICW(0x07,m_mapSPISelect.value(pIndex));
    objAppcard->readSPIDriveDoneBit(m_mapSPISelect.value(pIndex));
    l_nMSWData = objAppcard->getSPIRXMSW(m_mapSPISelect.value(pIndex));
    l_nOffsetData = (l_nMSWData << 16) | (objAppcard->getSPIRXLSW(m_mapSPISelect.value(pIndex)));
    return l_nOffsetData;
}
