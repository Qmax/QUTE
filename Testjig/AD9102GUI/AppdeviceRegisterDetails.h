#ifndef APPDEVICEREGISTERDETAILS_H
#define APPDEVICEREGISTERDETAILS_H
#include <QFlags>
/*
 * emiappdevice.h
 *
 *  Created on: April 25, 2013
 *      Author: D.Elangovan
 */


/*
 *      Application Card Register Details and Declaration header file

     The Applicationcard module is interfaced with CPU module via WEIM Bus, to access Application card internal registers.
        Base Address        :   0xB0000000 ( EIMM_CS0S0 )
        Memory              :   0xB000_0000 - 0xB00FF_FFFF (32 MB)

        Base Address        :   0xB2000000 ( EIMM_CS0S1 )
        Memory              :   0xB200_0000 - 0xB2FF_FFFF (32 MB)

        Base Address        :   0xB4000000 ( EIMM_CS0S2 )
        Memory              :   0xB400_0000 - 0xB4FF_FFFF (32 MB)

        Base Address        :   0xB6000000 ( EIMM_CS0S3 )
        Memory              :   0xB600_0000 - 0xB6FF_FFFF (32 MB)

        Chipselect          :  EIM_CS0

        Boudary Range(Registers)         :   to be specified
        / Functions
        1. General Read and Write App card Register
 */

#define DFIFODRIVE "./DFIFODrive.txt"
#define DFIFORECEIVE "./DFIFOReceive.txt"


class PT_APPCARD_MODULES
{
public:
    enum PT_APPCARD_MEMORY_SLOTS
    {
        PT_APPCARD_SLOT0 = 0xB0000000,
        PT_APPCARD_SLOT1 = 0xB2000000,
        PT_APPCARD_SLOT2 = 0xB4000000,
        PT_APPCARD_SLOT3 = 0xB5000000
    };

    enum PT_APPCARD_SYSTEM_REG
    {
        PT_SYSTEM_APPCARD_CR = 0x0000,  /* Code ID Register */
        PT_SYSTEM_APPCARD_SPR = 0x0002 /* Scratch Pad Register */
        /*
                Functions
                1. Read CODE ID register
                2. Read and Write Scracth Pad Register
          */

    };

    enum PT_APPCARD_DRIVE_REG
    {
        PT_DRIVE_APPCARD_BTUR       =   0x0004,  /* Basic Time Unit Register         */
        PT_DRIVE_APPCARD_BDR        =   0x0006,  /* Basic Duration Register          */
        PT_DRIVE_APPCARD_DCR        =   0x0012,  /* Drive Command Register           */
        PT_DRIVE_APPCARD_DPR        =   0x0018,  /* Drive Period Register            */
        PT_DRIVE_APPCARD_SSDR       =   0x001C,  /* Start Stop Delay Register        */
        PT_DRIVE_APPCARD_DPC        =   0x001A,  /* Drive Pattern Count              */

        /*        Functions
                  1. Write Basic Time Unit Register
                  2. Write Basic Duration Register
                  3. Write Drive Period Register
                  4. Read BTU
                  5. Read BDU
                  6. Read Drive Period Register
                  7. Writing Value to the Drive Register
                  8. Reading Value until drive done bit set
                  9. Writing Value to SSDR
                  10.Reading Value to SSDR
                  11.Writing Value to DPC
                  12.Reading Value to DPC
                  13.Writing Value to DSAR
                  14.Reading Value to DSAR
                  15.Writing Value to DRGSR
                  16.Reading Value to DRGSR
         */
    };

    enum PT_APPCARD_DDSREG
    {
        PT_DDS_APPCARD_CR           =   0x0068,      /* DDS Command Register                      */
        PT_DDS_APPCARD_FTWR_LSW     =   0x006A,      /* DDS Frequency Tuning Word Register (LSW)  */
        PT_DDS_APPCARD_FTWR_MSW     =   0x006C,      /* DDS Frequency Tuning Word Register (MSW)  */
        PT_DDS_APPCARD_PTWR_LSW     =   0x006E,      /* DDS Phase Tuning Word Register (LSW)      */
        PT_DDS_APPCARD_PTWR_MSW     =   0x0070,      /* DDS Phase Tuning Word Register (MSW)      */
        PT_DDS_APPCARD_DDSWSELR     =   0x0072,      /* DDS Wave Select Register                  */
        PT_DDS_APPCARD_DDSSSTR      =   0x0074,      /* DDS SAWTooth Register                     */
        PT_DDS_APPCARD_DCDR         =   0x0076,      /* DDS DAC DC Drive Register                 */
        PT_DDS_APPCARD_CFG1R        =   0x0078,      /* DDS Configuration Register 1              */
        PT_DDS_APPCARD_TWRAMR       =   0x007A,      /* DDS TW RAM Register                       */
    };

    enum PT_APPCARD_SRAM
    {
        PT_SRAM_APPCARD_RAMADDRR    =   0x007C,      /* RAM address register                      */
        PT_SRAM_APPCARD_DRAMDATAR   =   0x007E,      /* Drive RAM Data register                   */
        PT_SRAM_APPCARD_RRAMDATAR   =   0x0080,      /* Receive RAM data register                 */
        PT_SRAM_APPCARD_DRSAR       =   0x0082,      /* Drive RAM start address register          */
        PT_SRAM_APPCARD_DREAR       =   0x0084,      /* DriveRAM end address register             */
        PT_SRAM_APPCARD_RAMR        =   0x0086,      /* RAM Access mode register                  */
    };

    enum PT_APPCARD_SPI1
    {
        PT_SPI1_APPCARD_CR          =   0x0008,      /* SPI1 Command Register                     */
        PT_SPI1_APPCARD_TXR_LSW     =   0x000A,      /* SPI1 Transer LSW Register                 */
        PT_SPI1_APPCARD_TXR_MSW     =   0x000C,      /* SPI1 Transer MSW Register                 */
        PT_SPI1_APPCARD_RXR_LSW     =   0x000E,      /* SPI1 Receive LSW Register                 */
        PT_SPI1_APPCARD_RXR_MSW     =   0x0010,      /* SPI1 Receive MSW Register*/
        PT_SPI1_APPCARD_SCLKDIV	    =   0x0088,		 /* SPI Clock Divider */
    };
    enum PT_APPCARD_SPI2
    {
        PT_SPI2_APPCARD_CR          =   0x004A,      /* SPI2 Command Register                     */
        PT_SPI2_APPCARD_TXR_LSW     =   0x004C,      /* SPI2 Transer LSW Register                 */
        PT_SPI2_APPCARD_TXR_MSW     =   0x004E,      /* SPI2 Transer MSW Register                 */
        PT_SPI2_APPCARD_RXR_LSW     =   0x0050,      /* SPI2 Receive LSW Register                 */
        PT_SPI2_APPCARD_RXR_MSW     =   0x0052,      /* SPI2 Receive MSW Register                 */
        PT_SPI2_APPCARD_SCLKDIV	    =   0x008A,		 /* SPI Clock Divider */
    };
    enum PT_APPCARD_SPI3
    {
        PT_SPI3_APPCARD_CR          =   0x0020,      /* SPI3 Command Register                     */
        PT_SPI3_APPCARD_TXR_LSW     =   0x0022,      /* SPI3 Transer LSW Register                 */
        PT_SPI3_APPCARD_TXR_MSW     =   0x0024,      /* SPI3 Transer MSW Register                 */
        PT_SPI3_APPCARD_RXR_LSW     =   0x0026,      /* SPI3 Receive LSW Register                 */
        PT_SPI3_APPCARD_RXR_MSW     =   0x0028,      /* SPI3 Receive MSW Register                 */
        PT_SPI3_APPCARD_SCLKDIV	    =   0x008C,		 /* SPI Clock Divider */
    };
    enum PT_APPCARD_SPI4
    {
        PT_SPI4_APPCARD_CR          =   0x002A,      /* SPI4 Command Register                     */
        PT_SPI4_APPCARD_TXR_LSW     =   0x002C,      /* SPI4 Transer LSW Register                 */
        PT_SPI4_APPCARD_TXR_MSW     =   0x002E,      /* SPI4 Transer MSW Register                 */
        PT_SPI4_APPCARD_RXR_LSW     =   0x0030,      /* SPI4 Receive LSW Register                 */
        PT_SPI4_APPCARD_RXR_MSW     =   0x0032,      /* SPI4 Receive MSW Register                 */
        PT_SPI4_APPCARD_SCLKDIV	    =   0x008E,		 /* SPI Clock Divider */
    };
    enum PT_APPCARD_SPI5
    {
        PT_SPI5_APPCARD_CR          =   0x0054,      /* SPI5 Command Register                     */
        PT_SPI5_APPCARD_TXR_LSW     =   0x0056,      /* SPI5 Transer LSW Register                 */
        PT_SPI5_APPCARD_TXR_MSW     =   0x0058,      /* SPI5 Transer MSW Register                 */
        PT_SPI5_APPCARD_RXR_LSW     =   0x005A,      /* SPI5 Receive LSW Register                 */
        PT_SPI5_APPCARD_RXR_MSW     =   0x005C,      /* SPI5 Receive MSW Register                 */
        PT_SPI5_APPCARD_SCLKDIV	    =   0x0090,		 /* SPI Clock Divider 						  */
    };
    enum PT_APPCARD_SPI6
    {
        PT_SPI6_APPCARD_CR          =   0x005E,      /* SPI6 Command Register                     */
        PT_SPI6_APPCARD_TXR_LSW     =   0x0060,      /* SPI6 Transer LSW Register                 */
        PT_SPI6_APPCARD_TXR_MSW     =   0x0062,      /* SPI6 Transer MSW Register                 */
        PT_SPI6_APPCARD_RXR_LSW     =   0x0064,      /* SPI6 Receive LSW Register                 */
        PT_SPI6_APPCARD_RXR_MSW     =   0x0066,      /* SPI6 Receive MSW Register                 */
        PT_SPI6_APPCARD_SCLKDIV	    =   0x0092,		 /* SPI Clock Divider 						  */
    };
    enum PT_APPCARD_DRV_RELAYS
    {
        PT_DRRLY_APPCARD_DRSER      =   0x0034,     /* Drive and Receive Source select Register    */
        PT_DRRLY_APPCARD_DSAR       =   0x0016,     /* Drive Source Amplitude Register             */
        PT_DRRLY_APPCARD_DRGSR      =   0x0048,     /* Drive Receive Gain Register                 */
    };

    enum PT_APPCARD_RECEV_RELAYS
    {
        PT_RECERLY_APPCARD_R1CR     =   0x0036,     /* RECEIVER1 Configuration Register            */
        PT_RECERLY_APPCARD_R2CR     =   0x0038,     /* RECEIVER2 Configuration Register            */
        PT_RECERLY_APPCARD_ICMMGR   =   0x003A,     /* ICM Measurement Range / Gain Register       */
    };
    enum PT_APPCARD_DSO_DRIVE
    {
    	PT_DSO_BWS					=	0x00DC,		/* DSO Band Widht Selection Register			*/
    	PT_DSO_BTUR					= 	0x0098,		/* DSO MSB Sample Frequency Register			*/
    	PT_DSO_BDR					=	0x009A,		/* DSO lSB Sample Frequency Register			*/
    	PT_DSO_CR					=	0x00B4,		/* DSO Command Register							*/
    	PT_DSO_MR					=	0x00FF,		/* DSO Mode Register							*/
    	PT_DSO_TR					=	0x00B8,		/* DSO Trigger Register							*/
    	PT_DSO_PRETCR				= 	0x00CE,		/* DSO Pre Trigger Counter 						*/
    	PT_DSO_POSTCR				=	0x00B2,		/* DSO Pos Trigger Counter						*/
    	PT_DSOFIFO_MODE				=	0x00A0,		/* DSO FIFO Mode Register						*/

    };
    enum PT_APPCARD_RECEIVE1_FIFO
    {
    	PT_DSOR1FIFO_CFG			=	0x009C,		/* DSO R1FIFO Configuration Register			*/
    	PT_DSOR1FIFO_ODD_WR			=	0x00A2,		/* DSO R1FIFO Odd Write Register				*/
    	PT_DSOR1FIFO_ODD_RD			=	0x00A6,		/* DSO R1FIFO Odd Read Register					*/
    	PT_DSOR1FIFO_EVEN_WR		=	0x00A4,		/* DSO R1FIFO Even Write Register				*/
    	PT_DSOR1FIFO_EVEN_RD		=	0x00A8,		/* DSO R1FIFO Even Read Register				*/
    	PT_DSOR1FIFO_ODD_DIRECT_RD	=	0x00BA,		/* DSO R1FIFO Odd Direct Read Register			*/
    	PT_DSOR1FIFO_EVEN_DIRECT_RD	=	0x00BC,		/* DSO R1FIFO Even Direct Read Register			*/
    	PT_DSOR1FIFO_ODD_WC			=	0x00C2,		/* DS0 R1FIFO Odd Write Counter					*/
    	PT_DSOR1FIFO_ODD_RC			=	0x00C4,		/* DSO R1FIFO Odd Read Counter					*/
    	PT_DSOR1FIFO_EVEN_WC		=	0x00C6,		/* DSO R1FIFO Even Write Counter				*/
    	PT_DSOR1FIFO_EVEN_RC		=	0x00C8,		/* DSO R1FIFO Even Read Counter					*/
    	PT_DSOR1FIFO_ODD_WPL		=	0x00CA,		/* DSO R1FIFO Odd Write Pointer Latch			*/
    	PT_DSOR1FIFO_EVEN_WPL		=	0x00CC,		/* DSO R1FIFO Even Write Pointer Latch			*/

    };
    enum PT_APPCARD_RECEIVE2_FIFO
    {
    	PT_DSOR2FIFO_CFG			=	0x009E,		/* DSO R2FIFO Configuration Register			*/
    	PT_DSOR2FIFO_ODD_WR			=	0x00AA,		/* DSO R2FIFO Odd Write Register				*/
    	PT_DSOR2FIFO_ODD_RD			=	0x00AE,		/* DSO R2FIFO Odd Read Register					*/
    	PT_DSOR2FIFO_EVEN_WR		=	0x00AC,		/* DSO R2FIFO Even Write Register				*/
    	PT_DSOR2FIFO_EVEN_RD		=	0x00B0,		/* DSO R2FIFO Even Read Register				*/
    	PT_DSOR2FIFO_ODD_DIRECT_RD	=	0x00BE,		/* DSO R2FIFO Odd Direct Read Register			*/
    	PT_DSOR2FIFO_EVEN_DIRECT_RD	=	0x00C0,		/* DSO R2FIFO Even Direct Read Register			*/
    	PT_DSOR2FIFO_ODD_WC			=	0x00D0,		/* DS0 R2FIFO Odd Write Counter					*/
    	PT_DSOR2FIFO_ODD_RC			=	0x00D2,		/* DSO R2FIFO Odd Read Counter					*/
    	PT_DSOR2FIFO_EVEN_WC		=	0x00D4,		/* DSO R2FIFO Even Write Counter				*/
    	PT_DSOR2FIFO_EVEN_RC		=	0x00D6,		/* DSO R2FIFO Even Read Counter					*/
    	PT_DSOR2FIFO_ODD_WPL		=	0x00D8,		/* DSO R2FIFO Odd Write Pointer Latch			*/
    	PT_DSOR2FIFO_EVEN_WPL		=	0x00DA,		/* DSO R2FIFO Even Write Pointer Latch			*/

    };

    Q_DECLARE_FLAGS(PT_APPCARD_REGISTERS, PT_APPCARD_MEMORY_SLOTS);
};
Q_DECLARE_OPERATORS_FOR_FLAGS(PT_APPCARD_MODULES::PT_APPCARD_REGISTERS);
#endif // APPDEVICEREGISTERDETAILS_H
