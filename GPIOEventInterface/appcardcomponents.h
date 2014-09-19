#ifndef APPCARDCOMPONENTS_H
#define APPCARDCOMPONENTS_H
#include <math.h>



#define 	GHBit		5
#define 	GLBit		4
#define 	BUFHBit 	3
#define 	BUFLBit 	2
#define 	VDDHBit		1
#define 	VDDLBit		0
#define		CRBits		15

#define		DACResoultion	10




namespace PT_APPCARD_FUNCTIONAL_MODULES
{
    enum AD5318_DACSELECT
    {
        DACA=0,
        DACB=0x1000,
        DACC=0x2000,
        DACD=0x3000,
        DACE=0x4000,
        DACF=0x5000,
        DACG=0x6000,
        DACH=0x7000,
        ALL=0xFF
    };

    struct AD5318_ctrlTemplate
    {
      bool m_bCtrlBit;
      unsigned short m_nCtrlBits;
      bool m_bHGainBit;
      bool m_bLGainBit;
      bool m_bHBuffBit;
      bool m_bLBuffBit;
      bool m_bHVddBit;
      bool m_bLVddBit;
    };

    struct AD5318_dataTemplate
    {
      bool m_bCtrlBit;
      AD5318_DACSELECT m_eDACSelect;
      double m_nVRef;
      double m_nVout;
      bool m_bUniPolor;
    };

    struct DACRESET
    {
      bool DACResetBits[8];
    };


    struct AD5293_Template
    {
      bool m_bc3;
      bool m_bc2;
      bool m_bc1;
      bool m_bc0;
      unsigned short m_nData;
      bool m_nIncrFlag;
      unsigned short m_nSteps;
      bool m_bisCtrl;
      bool m_bResistorCalibMode;
      bool m_bRDACWiperMode;
      bool m_nPowerDownMode;
    };


    enum LMH6518_FILTER
    {
        BW_FULL =0,
        BW_20,BW_100,BW_200,BW_350,BW_650,BW_750,BW_UNALLOWED
    };


    enum LM6518_LADDER_ATTENUATION
    {
        ZERO_ATTENUATION =0,
        MINUS2_ATTENUATION,
        MINUS4_ATTENUATION,
        MINUS6_ATTENUATION,
        MINUS8ATTENUATION,
        MINUS10_ATTENUATION,
        MINUS12_ATTENUATION,
        MINUS14_ATTENUATION,
        MINUS16_ATTENUATION,
        MINUS20_ATTENUATION,
        UNALLOWED1_ATTENUATION,
        UNALLOWED2_ATTENUATION,
        UNALLOWED3_ATTENUATION,
        UNALLOWED4_ATTENUATION,
        UNALLOWED5_ATTENUATION,
    };

    struct LMH6518_DataTemplate
    {
        LMH6518_FILTER m_eFilter;
        LM6518_LADDER_ATTENUATION m_eLAttenuation;
        bool m_nbPreAmp;
        bool m_bPower;
    };


    enum VOLTAGEPERDIVISION
    {
        MV20=0,MV50,MV100,MV200,MV500,V1,V2,V5,V10
    };

    enum CHANNELS_SELECTION
    {
        CH1=1,CH2=2
    };
    enum ISLA118050
    {
        CHIP_PORT_CONFIG=0x00,
        BURSTMODE =0x02,
        CHIPID=0x08,
        CHIPVERSION=0x09,
        DEVICEINDEX=0x10,
        OFFSET_COARSE=0x20,
        OFFSET_FINE=0x21,
        GAIN_COARSE=0x22,
        GAIN_MEDIUM=0x23,
        GAIN_FINE=0x24,
        MODES=0x25,
        I2E_STATUS=0x30,
        I2E_CONTROl=0x31,
        I2E_STATICCONTROL=0x32,
        I2E_POWERDOWN=0x4A,
        I2E_RMSPOWER_THRESHOLD_LSB=0x50,
        I2E_RMSPOWER_THRESHOLD_MSB=0x51,
        RMS_HYSTERESIS=0x52,
        COARSE_OFFSET_INIT=0x60,
        FINE_OFFSET_INIT=0x61,
        MEDIUM_GAIN_INIT=0x62,
        FINE_GAIN_INIT=0x63,
        SAMPLETIME_SKEW_INIT=0x64,
        SKEW_DIFF=0x70,
        PHASE_SLIP=0x71,
        OUTPUT_MODEA=0x73,
        OUTPUT_MODEB=0x74,
        CONFIG_STATUS=0x75,
        TEST_IO=0xC0,
        USER_PATT1_LSB= 0xC2,
        USER_PATT1_MSB= 0xC3,
        USER_PATT2_LSB= 0xC4,
        USER_PATT2_MSB= 0xC5
    };
    enum SPI5TRANSFERSEL { ONE_BYTE=0x00,TWO_BYTE=0x01,THREE_BYTE=0x02,N_BYTE=0x03};
    struct HSADC_ctrlTemplate
    {
       bool m_bCtrlR_Wbit;
       SPI5TRANSFERSEL m_eTranserMode;
       unsigned short m_nAddressBits;
       unsigned short m_nLSWData;
    };
// HAADC
    enum SPI2POTSELECT
    {
        HAADC1 =1,
        HAADC2 =2
    };
}
#endif // APPCARDCOMPONENTS_H
