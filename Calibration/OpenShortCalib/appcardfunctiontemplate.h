/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#ifndef APPCARDFUNCTIONTEMPLATE_H
#define APPCARDFUNCTIONTEMPLATE_H
#include <math.h>


namespace APPCARD_DETAILS
{
	enum	APP_SLOTS
	{
		SLOT0,SLOT1,SLOT2,SLOT3
	};
    enum DRIVE_PARAM
    {
        START_DRIVE=1,
        STOP_DRIVE=2
    };

/*    enum DDS_WAVESELECT		//rravi
    {
        DC_SIGNAL=0,
        SAW_TOOTH=1,
        PSEUDO_NOISE=2,
        DDS=3
    };*/
      enum DDS_WAVESELECT	//rravi
       {
    	    RAM_DATA=0,
            DC_SIGNAL=1,
            SAW_TOOTH=5,
            PSEUDO_NOISE=9,
            DDS=0xD,
            MODULATED=2
        };

    enum DDS_SAWTOOTH_REG
    {
        _RAMP_UP =0,
        _RAMP_DOWN=1,
        _TRIANGLE = 2,
        _ASYMMETRIC =3
    };

    struct DDSR1CONFIG
    {
        bool m_bSINEorCOSINE;
        bool m_bBaseClockorMSBRAM;
        bool m_bPTWRAMorREG;
        bool m_bFTWRAMorREG;
    };

    struct RAMACCESS
    {
        bool m_bRRAM2MODE;
        bool m_bRRAM1MODE;
        bool m_bDRAMMODE;
    };

    enum SPITRANSFERMODE
    {
        MODE8  = 0,
        MODE16 = 1,
        MODE24 = 2,
        MODE32 = 3
    };

    enum SPI1POTSELECT
    {
        POT_AD5293       = 0,
        POT_AD5318       = 1,
        POT_FLASH_25PE80 = 2,
        POT_RESERVED     = 3
    };

    enum SPI5POTSELECT
    {
        HSADC1      = 0,
        HSADC2      = 1,
        HSPLL       =  2,
        RESERVER    = 3
    };

    enum SPI6POTSELECT
    {
        SCOPE_CH1 = 0,
        SCOPE_CH2 = 1,
        RESERVED1 = 2,
        RESERVED2 = 3
    };

    enum CSMODE_CSEN
    {
        AUTO_ASSERT = 0,
        MANUAL_ASSERT = 2,
        MANUAL_DESERT = 3
    };

    enum IRS
    {
        SET_50MA=0,
        SET_500UA = 1,
        SET_5UA = 2,
        SET_RESERVED=3
    };

    enum SPI_SELECT
    {
        SPI1 =1,
        SPI2,
        SPI3,SPI4,SPI5,SPI6
    };

    enum DSO_RECEIVE_FIFO
    {
    	R1FIFO = 1,
    	R2FIFO
    };

    enum DSO_TRIGGER
    {
    	EDGE_RISING	=0,
    	EDGE_FALLING = 1,
    	PULSE_POSITIVE = 2,
    	PULSE_NEGATIVE = 3
    };

    enum VRAGNE
    {
        VOLT_0P5=0,
        VOLT_1P5=1,
        VOLT_3P5=2,
        VOLT_7P0=4,
        VOLT_13P0 =8

    };
    enum DSOCOUPLING
    {
        _DC=0,
        AC=1,
        GND=2
    };

    enum RECEIVER_CONF
    {
        RECEIVER1 =0,
        RECEIVER2 =1,
        EXTERNAL = 2
    };

    enum ICMRANGE
    {
        R_10OHM = 0,
        R_100OHM = 1,
        R_1KOHM = 2,
        R_10KOHM = 3,
        R_100KOHM=4,
        R_1MOHM=5,
        R_RESERVED1 = 6,
        R_RESERVED2 = 7
    };



    struct SPI1_CONFIGURATION
    {
        bool m_bSD; // 1 bit D0
        SPITRANSFERMODE m_eMode; // 2bits D[2:1]
        bool m_bCD; // 1 bit D3
        bool m_bLDAC_AD5318; // 1 bit D4
        CSMODE_CSEN m_eCSEN; //  D[6:5] 2 bits
        bool m_bResX; // D7 1 bit
        SPI1POTSELECT m_eCSSEL; // D[9:8] 2 bits
    };

    struct SPI2_CONFIGURATION
    {
        bool m_bSD; // 1 bit D0
        SPITRANSFERMODE m_eMode; // 2 bits D[2:1]
        bool m_bCD; // 1 bit D3
        bool m_bResX; // D4 1 bit
        CSMODE_CSEN m_eCSEN; //  D[6:5] 2 bits
    };

    struct SPI3_CONFIGURATION
    {
        bool m_bSD; // 1 bit D0
        SPITRANSFERMODE m_eMode; // 2 bits D[2:1]
        bool m_bCD; // 1 bit D3
    };
    struct SPI4_CONFIGURATION
    {
        bool m_bSD; // 1 bit D0
        SPITRANSFERMODE m_eMode; // 2 bits D[2:1]
        bool m_bCD; // 1 bit D3
    };
    struct SPI5_CONFIGURATION
    {
        bool m_bSD; // 1 bit D0
        SPITRANSFERMODE m_eMode; // 2 bits D[2:1]
        bool m_bCD; // 1 bit D3
        bool m_bResX; // D4 1 bit
        CSMODE_CSEN m_eCSEN; //  D[6:5] 2 bits
        //bool m_bResX; // D7 1 bit
        SPI5POTSELECT m_eCSSEL;
    };
    struct SPI6_CONFIGURATION
    {
        bool m_bSD; // 1 bit D0
        SPITRANSFERMODE m_eMode; // 2 bits D[2:1]
        bool m_bCD; // 1 bit D3
        bool m_bResX; // D4 1 bit
        CSMODE_CSEN m_eCSEN; //  D[6:5] 2 bits
        //bool m_bResX; // D7 1 bit
        SPI6POTSELECT m_eCSSEL;
    };

    struct DRSER
    {
        bool m_bDSE; // bit D0
        bool m_bR1SE; // bit D1
        bool m_bR2SE; // bit D2
    };


    struct DSAR
    {
        bool m_bSRCN; // bit D0
        IRS m_eIRS; //bit D[2:1]
        bool m_bVIS; // bit D3
    };

    struct DRGSR
    {
        VRAGNE m_eVRanges;
        bool m_bSlotFFS;
    };



    struct R1CR
    {
        bool m_bHSHA; // D0 Bit
        bool m_bHAAC; // D1 Bit
        bool m_bRMSIN; // D2 Bit
        bool m_bRMSGAIN; // D3 Bit
        bool m_bRMSAVG; // D4 Bit
        bool m_bHAIPR1_ICMSELR2; // D5 Bit
        bool m_bHSVI; // D6 Bit
        DSOCOUPLING m_eCoupling; // D8:D7
    };

    struct ICMMGR
    {
        ICMRANGE m_eRange;
        bool m_bGain;
        bool m_bIASel;
        bool m_bFBCAPSel;
    };
};



#endif // APPCARDFUNCTIONTEMPLATE_H
