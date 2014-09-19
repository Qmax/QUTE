#ifndef INTERFACEFUNCTIONALCOMPONENTS_H
#define INTERFACEFUNCTIONALCOMPONENTS_H

#include<QtCore>
#include <appcardcomponents.h>
#include <ApplicationCardInterface.h>


using namespace APPCARD_DETAILS;
using namespace PT_APPCARD_FUNCTIONAL_MODULES;


class IAD5293
{
public:
    virtual void configureADC5293CW(SPI1_CONFIGURATION)=0;
    virtual void resetDAC5293(bool bDCRReset)=0;
    virtual void calculateADC5293DATA(AD5293_Template pObjstAD5293)=0;
    virtual unsigned short readADC5293()=0;
    virtual void powerDownmode()=0;
    virtual void writeAD5293(SPI_SELECT peSelect)=0;
};

class IAD5318
{
public:
    virtual void configureADC5318CW()=0;
    virtual void configureADC5318Data()=0;
    virtual void resetDAC5318(bool bDCRReset)=0;

};

class ILMH6518
{
public:
    virtual void configureLMH6518CW(CHANNELS_SELECTION eCHSelect)=0;
    virtual void configureLMH6518DW(CHANNELS_SELECTION eCHSelect)=0;
    virtual unsigned int ReadLM6518(CHANNELS_SELECTION eCHSelect)=0;

};

class IISLA118P50
{
public:
    virtual void configureADCChip()=0;
    virtual unsigned short readChipVersion(SPI5POTSELECT pPOTSelect)=0;
    virtual unsigned short readChipID(SPI5POTSELECT pPOTSelect)=0;
};

class IAD7190
{
public:
    virtual void resetADC(unsigned short pIndex)=0;
    virtual unsigned short readADCStatusRegister(unsigned short pIndex)=0;
    virtual unsigned int readADCModeRegister(unsigned short pIndex)=0;
    virtual void writeADCModeRegister(unsigned short,unsigned int)=0;
    virtual unsigned int readADCConfigurationRegister(unsigned short)=0;
    virtual void writeADCConfigurationRegister(unsigned short,unsigned int)=0;
    virtual unsigned int readADCDataRegister(unsigned short)=0;
    virtual unsigned short readADCIDRegister(unsigned short)=0;
    virtual unsigned short readADCGPConRegister(unsigned short)=0;
    virtual void writeADCGPConRegister(unsigned short,unsigned int)=0;
    virtual unsigned int readADCFullScaleRegister(unsigned short)=0;
    virtual unsigned int readADCOffsetRegister(unsigned short)=0;
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(IAD5293,"IAD5293/1.0")
Q_DECLARE_INTERFACE(IAD5318,"IAD5318/1.0")
Q_DECLARE_INTERFACE(ILMH6518,"ILMH6518/1.0")
Q_DECLARE_INTERFACE(IISLA118P50,"IISLA118P50/1.0")
Q_DECLARE_INTERFACE(IAD7190,"IAD7190/1.0")
QT_END_NAMESPACE



#endif // INTERFACEFUNCTIONALCOMPONENTS_H
