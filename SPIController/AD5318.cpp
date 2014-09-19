#include "AD5318.h"

AD5318::AD5318(IApplicationCardInterface *pObjAppcard)
{
    objAppcard = pObjAppcard;
}



void AD5318::configureAD5318DACCW(AD5318_ctrlTemplate pDACAD5318CW)
{
    unsigned short DACCRWORD=0;
    if(pDACAD5318CW.m_bCtrlBit == true)
      DACCRWORD |= 1<<CRBits;
    if(pDACAD5318CW.m_bHGainBit==true)
      DACCRWORD |= 1<<GHBit;
    if(pDACAD5318CW.m_bLGainBit==true)
      DACCRWORD |= 1<<GLBit;
    if(pDACAD5318CW.m_bHBuffBit==true)
      DACCRWORD |= 1<<BUFHBit;
    if(pDACAD5318CW.m_bLBuffBit==true)
      DACCRWORD |= 1<<BUFLBit;
    if(pDACAD5318CW.m_bHVddBit==true)
      DACCRWORD |= 1<<VDDHBit;
    if(pDACAD5318CW.m_bLVddBit==true)
      DACCRWORD |= 1<<VDDLBit;
    //objAppcard->setSPITXLSW(DACCRWORD,SPI1);
    DACCRWORD =0x8020;
    objAppcard->setSPITXLSW(DACCRWORD,SPI1);
    qDebug()<<"DAC ControlWord:"<<hex<<DACCRWORD;


}

void AD5318::configureAD5318DACData(AD5318_dataTemplate pDACAD5318Data)
{
    unsigned short DACDATAWORD=0;
    //cout << "Selected DAC:"<<pDACAD5318Data.m_eDACSelect<<endl;
   unsigned short l_nShiftData = convertToDecimalValue(pDACAD5318Data.m_nVout,pDACAD5318Data.m_nVRef,pDACAD5318Data.m_bUniPolor,pDACAD5318Data.m_eDACSelect);
      if(pDACAD5318Data.m_nVout == pDACAD5318Data.m_nVRef)
        DACDATAWORD= l_nShiftData;
      else
        DACDATAWORD= l_nShiftData;//<<2;
      DACDATAWORD|= pDACAD5318Data.m_eDACSelect;
      objAppcard->setSPITXLSW(DACDATAWORD,SPI1);

      qDebug()<<"DAC DataWord:"<<hex<<DACDATAWORD;
}

void AD5318::resetDAC5318(bool bDCRReset)
{

  unsigned short l_nResetDACData = 0xE000;
  if(bDCRReset == true)
    l_nResetDACData |= 0x1000;
  qDebug()<<"DAC Reset:"<<hex<<l_nResetDACData;
 // cout<<"DAC Reset:"<<hex<<l_nResetDACData<<endl;

  objAppcard->setSPITXLSW(l_nResetDACData,SPI1);
  objAppcard->setSPICW(0x103,SPI1);
  objAppcard->readSPIDriveDoneBit(SPI1);

  // Read the Start Bit of Register 0x08. if it's 0 continue to the next step else wait until the BIT is '0'.
  //configureSPI(AD5318,0,true,false,BIT_16,true);
  //1. Write to SPI MSW
  //2. Configure SPIMode in 16 bit Format
  //3. Issue Drive Command
}

void AD5318::configureADC5318CW()
{
      AD5318_ctrlTemplate l_nAD5318CW;
    // configure DAC Control Word template
    //2. Write 0x8021 to 0x0A [CONFIG AD5318: GAIN BUF Md | DAC A-D= GAIN 1 | DACE-H = GAIN 2 | DAC A-H UNBUFFERED | DAC A-H Ext VREF]
    l_nAD5318CW.m_bCtrlBit = true;
    l_nAD5318CW.m_nCtrlBits=0;
    l_nAD5318CW.m_bHGainBit = false;
    l_nAD5318CW.m_bLGainBit = false;
    l_nAD5318CW.m_bHBuffBit = false;
    l_nAD5318CW.m_bLBuffBit = false;
    l_nAD5318CW.m_bHVddBit = false;
    l_nAD5318CW.m_bLVddBit=false;
    if(l_nAD5318CW.m_bHGainBit == true)
      GAINVALUE = 1;
    else
      GAINVALUE = 1;
    configureAD5318DACCW(l_nAD5318CW);
   // Write 0x0103 to Register 0x08[SPI1 CONFIG : SEL AD5318 | Auto CS Assertion | 16 Bit Md Start Drive]
    objAppcard->setSPICW(0x103,SPI1);
    objAppcard->readSPIDriveDoneBit(SPI1);      // Read the Start Bit of Register 0x08. if it's 0 continue to the next step else wait until the BIT is '0'.
}

void AD5318::configureADC5318Data(AD5318_dataTemplate pstDAC)
{
    //configure DAC Data template
//    AD5318_dataTemplate l_nAD5318DW;
	qDebug() <<"Data:"<<pstDAC.m_nVout;
    configureAD5318DACData(pstDAC);

    // Write 0x0103 to Register 0x08[SPI1 CONFIG : SEL AD5318 | Auto CS Assertion | 16 Bit Md Start Drive]
    objAppcard->setSPICW(0x103,SPI1);
    objAppcard->readSPIDriveDoneBit(SPI1);      // Read the Start Bit of Register 0x08. if it's 0 continue to the next step else wait until the BIT is '0'.
  //[STATUS READ]→ Write 0x0112 to Register 0x08 [SPI1 CONFIG : PULSE LDAC]
    objAppcard->setSPICW(0x10,SPI1);
    objAppcard->readSPIDriveDoneBit(SPI1);      // Read the Start Bit of Register 0x08. if it's 0 continue to the next step else wait until the BIT is '0'.
      // Read the Start Bit of Register 0x08. if it's 0 continue to the next step else wait until the BIT is '0'.
}

unsigned short  AD5318::convertToDecimalValue(double pVout,double pVref,bool bUnipolar,AD5318_DACSELECT p_eDACSelect)
{
    unsigned int l_nD=0x0;
     if( bUnipolar == false && (p_eDACSelect == DACF|| p_eDACSelect == DACG))
       l_nD = ((pVout*GAINVALUE)+5.0) * (pow(2,DACResoultion)-1) / 10.0;
    	// l_nD = ((pVout/GAINVALUE) * pow(2,DACResoultion)) / pVref;
     else if( bUnipolar == true)
       l_nD = ((pVout/GAINVALUE) * pow(2,DACResoultion)) / pVref;
     qDebug()<<"DAC Digital Value:"<<l_nD;

     return l_nD;
}
