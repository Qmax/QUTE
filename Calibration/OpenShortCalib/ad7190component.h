/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#ifndef AD7190COMPONENT_H
#define AD7190COMPONENT_H

#include <ApplicationCardInterface.h>
#include <QMap>
#include <unistd.h>
#include <qdebug.h>

class AD7190Component
{

public:
    AD7190Component(IApplicationCardInterface *pobj);
    void resetADC(unsigned short pIndex);
    unsigned short readADCStatusRegister(unsigned short pIndex);
    unsigned int readADCModeRegister(unsigned short pIndex);
    void writeADCModeRegister(unsigned short,unsigned int);
    unsigned int readADCConfigurationRegister(unsigned short);
    void writeADCConfigurationRegister(unsigned short,unsigned int);
    unsigned int readADCDataRegister(unsigned short);
    unsigned short readADCIDRegister(unsigned short);
    unsigned short readADCGPConRegister(unsigned short);
    void writeADCGPConRegister(unsigned short,unsigned int);
    unsigned int readADCFullScaleRegister(unsigned short);
    unsigned int readADCOffsetRegister(unsigned short);

protected:
    QMap<short int,SPI_SELECT> m_mapSPISelect;
    IApplicationCardInterface *objAppcard;
};

#endif // AD7190COMPONENT_H
