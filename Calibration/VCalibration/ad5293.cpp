#include "ad5293.h"

AD5293::AD5293(IApplicationCardInterface *pObjAppard)
{
	objAppcard = pObjAppard;
	objAppcard->setSPIAppendBit(0x8000);
}
void AD5293::setAD5293Voltage(double pVolt)
{
	m_nVoltage=pVolt;
}

void AD5293::writeAD5293(SPI_SELECT peSelect)
{
    //DATA REG PROGRAMMING SEQUENCE
    Q_UNUSED(peSelect)
    objAppcard->setSPITXLSW(0x1802,SPI1); // write protect bit,C1 of the control register is set to 1
    objAppcard->setSPICW(0x3,SPI1);
    usleep(1000);
    if( objAppcard->readSPIDriveDoneBit(SPI1))
    {
        AD5293_Template l_objAD5293;
        l_objAD5293.m_bc3 = false;
        l_objAD5293.m_bc2 = false;
        l_objAD5293.m_bc1 = false;
        l_objAD5293.m_bc0 = true;
        l_objAD5293.m_nIncrFlag = true;
        l_objAD5293.m_nSteps = 10;
        l_objAD5293.m_nData = m_nVoltage;
        l_objAD5293.m_bisCtrl = false;
        l_objAD5293.m_bResistorCalibMode = false;
        l_objAD5293.m_bRDACWiperMode = false;
        l_objAD5293.m_nPowerDownMode = false;
        calculateADC5293DATA(l_objAD5293); // Calcluate Data and write into SPI 1LSW  Register
    }
    objAppcard->setSPICW(0x3,SPI1);
    usleep(1000);
    objAppcard->setSPITXLSW(0x1800,SPI1);
    objAppcard->setSPICW(0x3,SPI1);
    usleep(1000);
    objAppcard->readSPIDriveDoneBit(SPI1);
//    if( objAppcard->readSPIDriveDoneBit(SPI1))
//    {
//        objAppcard->setSPITXLSW(0x1800,SPI1); // Write Read RDAC wiper setting in Tx LSW reg
//        objAppcard->setSPICW(0x3,SPI1);
//        objAppcard->setSPITXLSW(0x000,SPI1); // No Operation
//        objAppcard->setSPICW(0x3,SPI1);
//        objAppcard->readSPIDriveDoneBit(SPI1);
//        objAppcard->getSPIRXLSW(SPI1);
//    }
}

void AD5293::configureADC5293CW(SPI1_CONFIGURATION pOBJ)
{
    Q_UNUSED(pOBJ)
    resetDAC5293(true);
    SPI1_CONFIGURATION l_objSPI1;
    l_objSPI1.m_eCSSEL =  POT_AD5293;
    l_objSPI1.m_eCSEN = AUTO_ASSERT;
    l_objSPI1.m_bLDAC_AD5318 = true;
    l_objSPI1.m_bCD = false;
    l_objSPI1.m_eMode = MODE16;
    l_objSPI1.m_bSD = true;

    AD5293_Template l_objAD5293;
    l_objAD5293.m_bc3 = false;
    l_objAD5293.m_bc2 = true;
    l_objAD5293.m_bc1 = true;
    l_objAD5293.m_bc0 = false;
    l_objAD5293.m_nIncrFlag = true;
    l_objAD5293.m_nSteps = 10;
    l_objAD5293.m_nData = m_nVoltage;
    l_objAD5293.m_bisCtrl = true;
    l_objAD5293.m_bResistorCalibMode = false;
    l_objAD5293.m_bRDACWiperMode = false;
    l_objAD5293.m_nPowerDownMode = false;

    calculateADC5293DATA(l_objAD5293); // Calcluate Data and write into SPI 1LSW  Register
    objAppcard->setSPI1CommandWord(l_objSPI1); // DigPOT Select + Start Drive + 16 BIT mode
    objAppcard->readSPIDriveDoneBit(SPI1); // Read the drive done bit untile D0 =0
}

unsigned short AD5293::readADC5293()
{
    unsigned short l_nWriteCWData = 0x1C00;
    objAppcard->setSPITXLSW(l_nWriteCWData,SPI1);
    SPI1_CONFIGURATION l_objSPI1;
    l_objSPI1.m_eCSSEL =  POT_AD5293;
    l_objSPI1.m_eCSEN = AUTO_ASSERT;
    l_objSPI1.m_bLDAC_AD5318 = true;
    l_objSPI1.m_bCD = false;
    l_objSPI1.m_eMode = MODE16;
    l_objSPI1.m_bSD = true;
    objAppcard->setSPI1CommandWord(l_objSPI1); // DigPOT Select + Start Drive + 16 BIT mode
    objAppcard->setSPITXLSW(0,SPI1); //  No Operation
    objAppcard->setSPI1CommandWord(l_objSPI1); // DigPOT Select + Start Drive + 16 BIT mode
    objAppcard->readSPIDriveDoneBit(SPI1);; // Read the drive done bit untile D0 =0
    return objAppcard->getSPIRXLSW(SPI1); // Read the Control Reg setting from SDO output
}

void AD5293::powerDownmode()
{
    AD5293_Template l_objAD5293;
    l_objAD5293.m_bc0 = false;
    l_objAD5293.m_bc2 = false;
    l_objAD5293.m_bc1 = false;
    l_objAD5293.m_bc3 = true;
    l_objAD5293.m_nIncrFlag = true;
    l_objAD5293.m_nSteps = 10;
    l_objAD5293.m_nData = 200;
    l_objAD5293.m_bisCtrl = true;
    l_objAD5293.m_bResistorCalibMode = true;
    l_objAD5293.m_bRDACWiperMode = false;
    l_objAD5293.m_nPowerDownMode = true;
    calculateADC5293DATA(l_objAD5293);
    SPI1_CONFIGURATION l_objSPI1;
    l_objSPI1.m_eCSSEL =  POT_AD5293;
    l_objSPI1.m_eCSEN = AUTO_ASSERT;
    l_objSPI1.m_bLDAC_AD5318 = true;
    l_objSPI1.m_bCD = false;
    l_objSPI1.m_eMode = MODE16;
    l_objSPI1.m_bSD = true;

    objAppcard->setSPI1CommandWord(l_objSPI1); // DigPOT Select + Start Drive + 16 BIT mode
    objAppcard->readSPIDriveDoneBit(SPI1);; // Read the drive done bit untile D0 =0

}


void AD5293::resetDAC5293(bool bDCRReset)
{
    Q_UNUSED(bDCRReset);
    objAppcard->setSPITXLSW(0x1000,SPI1); // Rst Refresh DAC with mide scale code
    objAppcard->setSPICW(0x03,SPI1); // Dig Pot select+Start drive+16 bit mode
    objAppcard->readSPIDriveDoneBit(SPI1);//BSY STS RD:If D0 = 0, continue to next step else wait till D0 =0
}


void AD5293::calculateADC5293DATA(AD5293_Template pObjstAD5293)
{

    unsigned short l_nRegisterData=0x0;
    short int RWB =0,RWA=0;
    short int RAB = pObjstAD5293.m_nSteps;
	unsigned short int l_nRAB =20000;
	unsigned short int l_nD=0;

    if(pObjstAD5293.m_bc0 == true)
    {
      l_nRegisterData = 1<<10;
    }
    if(pObjstAD5293.m_bc1 == true)
    {
      l_nRegisterData |= 1<<11;
    }
    if(pObjstAD5293.m_bc2 == true)
    {
      l_nRegisterData |= 1<<12;
    }
    if(pObjstAD5293.m_bc3 == true)
    {
      l_nRegisterData |= 1<<13;
    }
    if(pObjstAD5293.m_bisCtrl == false)
    {
        if(pObjstAD5293.m_nIncrFlag == true)
          // Increment Positively
        {
            //RWB = ((pObjstAD5293.m_nData) / 1024) * RAB;
            l_nD = ((pObjstAD5293.m_nData) * 1024) / l_nRAB;
            l_nRegisterData |= l_nD;
        }
        else if(pObjstAD5293.m_nIncrFlag == false)
          // Decrement Negatively
        {

        	l_nD = -((pObjstAD5293.m_nData * 1024)/l_nRAB) + 1024;
        	qDebug() << "D:"<<l_nD;
            //RWA = ((1024-pObjstAD5293.m_nData) / 1024) * RAB;
            l_nRegisterData |= l_nD;
        }
        qDebug() <<"Data:"<<pObjstAD5293.m_nData<<":"<<l_nD;
    }
    else
    {
      if( pObjstAD5293.m_bResistorCalibMode == true)
        l_nRegisterData |= 1<<1;
      if( pObjstAD5293.m_bRDACWiperMode == true)
        l_nRegisterData |= 1<<2;
      if( pObjstAD5293.m_nPowerDownMode == true)
        l_nRegisterData |= 1;

    }
    qDebug() <<"AD5293 Data:" << hex << l_nRegisterData;
    objAppcard->setSPITXLSW(l_nRegisterData,SPI1);
}
//QT_BEGIN_NAMESPACE
//Q_EXPORT_PLUGIN2(IAD5293,AD5293)
//QT_END_NAMESPACE
