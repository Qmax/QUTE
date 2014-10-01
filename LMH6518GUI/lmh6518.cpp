#include "lmh6518.h"
#include <unistd.h>
#include <qdebug.h>

void LMH6518::configureLMH6518CW(CHANNELS_SELECTION eCHSelect)
{
   Q_UNUSED(eCHSelect)
}

void LMH6518::configureLMH6518DW(LMH6518_DataTemplate l_objDW)
{
   qDebug()<<"inside lmh6518.cpp:line-12";

//   LMH6518_DataTemplate l_objDW;
//   //SPI6_CONFIGURATION l_objSPI6;
//
//   l_objDW.m_eFilter = BW_20;
//   l_objDW.m_eLAttenuation = MINUS12_ATTENUATION;
//   l_objDW.m_bPower = false;
//   l_objDW.m_nbPreAmp = false;

   unsigned short l_nData =0,l_nCW=0;
   //l_nData |= l_objDW.m_eFilter;//commented vy RRV
   l_nData |= l_objDW.m_eFilter<<6;//added by RRV
   if(l_objDW.m_nbPreAmp == true)
//       l_nData |= 1 << 3;//commented by RRV
	   l_nData |=0x10;//added by RRV

   //l_nData |= l_objDW.m_eLAttenuation << 5;//commented by RRV
   l_nData |= l_objDW.m_eLAttenuation;//added by RRV
   if(l_objDW.m_bPower == true)
       //l_nData |= 1 << 9;//commented by RRV
	   l_nData |=0x200;//added by RRV

   objAppcard->setSPITXLSW(l_nData,SPI6);
   objAppcard->setSPITXMSW(0x0,SPI6);

   if(l_objDW.m_eChannelSel == CH1)
       //l_nCW = 0x5;//commented by RRV
	   //l_nCW = 0xC005;//added by RRV
	   l_nCW = 0xC205;//added by RRV
   else if(l_objDW.m_eChannelSel == CH2)
       //l_nCW = 0x105;//commented by RRV
	   l_nCW = 0xC105;//added by RRV
   objAppcard->setSPICW(l_nCW,SPI6);
   objAppcard->readSPIDriveDoneBit(SPI6);
   qDebug()<<"inside lmh6518.cpp:line-47";
}

unsigned int LMH6518::ReadLM6518(LMH6518_DataTemplate l_objDW)
{
//   unsigned short l_nLSW = 0,l_nMSW = 0x80;
//   objAppcard->setSPITXLSW(l_nLSW,SPI6);//to set read configuration<16bit LSW>			//0x60
//   objAppcard->setSPITXMSW(l_nMSW,SPI6);// to set read configuration<8bit MSW>			//0x62
//   unsigned short l_nCW=0;
//   if(l_objDW.m_eChannelSel == CH1)
//       l_nCW = 0xC005;	//changed by RRV
//   else if(l_objDW.m_eChannelSel == CH2)
//       l_nCW = 0xC105;	//changed by RRV
//   objAppcard->setSPICW(l_nCW,SPI6);													  //0x5E
//   objAppcard->readSPIDriveDoneBit(SPI6);      // Read the Start Bit of Register 0x08. if it's 0 continue to the next step else wait until the BIT is '0'.
//   return objAppcard->getSPIRXLSW(SPI6);												//0x64

	unsigned int l_nData=0;

	objAppcard->setSPITXLSW(0x80,SPI6);
	usleep(1000);

	if(l_objDW.m_eChannelSel == CH1){
		objAppcard->setSPICW(0xc241,SPI6);
		usleep(1000);
		objAppcard->setSPICW(0xc24b,SPI6);
		usleep(1000);
		objAppcard->setSPICW(0xc260,SPI6); // changed 060 to 260 for individul CH1 testing.... 7-Mar02014 as per Anbu
		usleep(1000);
	}
	else if(l_objDW.m_eChannelSel == CH2){
		objAppcard->setSPICW(0xc141,SPI6);
		usleep(1000);
		objAppcard->setSPICW(0xc14b,SPI6);
		usleep(1000);
		objAppcard->setSPICW(0xc160,SPI6);
		usleep(1000);
	}

	l_nData=objAppcard->getSPIRXLSW(SPI6);

	return l_nData;
}

void LMH6518::calculateSignalPathGain(VOLTAGEPERDIVISION pEVoltageSelect)
{
    m_nKSignalPathGain=0.0;
   double l_nS=0.0,l_nFPAttenuation=0.0;
   l_nS = m_nVoltperDivisionarray[pEVoltageSelect];
  // qDebug()<<"Selecte Voltage:"<<l_nS;
   if((l_nS* 8.0)<=0.8)
   {
	   l_nFPAttenuation = 1.0;
	   m_nFPAttenuation =1;
   }
   else if((l_nS* 8.0) <= 8.0)
   {
	   l_nFPAttenuation = 10.0;
	   m_nFPAttenuation =10;
   }
   else if((l_nS* 8.0) > 8.0)
   {
	   l_nFPAttenuation = 100.0;
	   m_nFPAttenuation =100;
   }

   m_nAttuenation = (l_nS * 8.0) / l_nFPAttenuation;
   m_nKSignalPathGain = 20 * (log10((0.95*0.7)/m_nAttuenation));
}



LMH6518Data LMH6518::calculateGain()
{
   m_nGSignalGain = (int(-m_nKSignalPathGain/2) +(int)m_nKSignalPathGain ) *2 + 0.8;
   if(m_nGSignalGain >= 18.8)
   {
       m_nHGorLG = true;
       m_nLadderAttuenator = -(38.8 - m_nGSignalGain);
   }
   else
   {
       m_nHGorLG = false;
       m_nLadderAttuenator = -(18.8 - m_nGSignalGain);
   }
   m_nOutput = (m_nAttuenation*1.05)* pow(10,m_nGSignalGain/20);
   m_nFSADC = m_nOutput  *2.0;
   Data.m_sOutput=m_nOutput;
   Data.m_sFullScaleADC=m_nFSADC;

   return Data;
}
//Q_EXPORT_PLUGIN2(ILMH6518,LMH6518)

