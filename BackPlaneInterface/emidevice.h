#ifndef EMIDEVICE_H
#define EMIDEVICE_H
/*
 * emidevice.h
 *
 *  Created on: Mar 28, 2012
 *      Author: sountharya
 */
/*--------------------------------PSOC Programming Macros -Ravivarman.R-----------------------------------------------------*/
#define			PSOC_CMD					0x0034
#define			PSOC_WMSW					0x0038
#define			PSOC_WLSW					0x0036
#define			PSOC_RMSW					0x003C
#define			PSOC_RLSW					0x003A

#define			PSOC_XRES					0x0000
#define 		JTAG_IDCODE					0X0005
#define 		DPGPRT_CFG					0X0009
#define 		READBUFF					0X000D
#define 		TRNS_ADDR					0X0011
#define 		DATA_WR						0X0015
#define 		DATA_RD						0X0019

#define			OK							0x0001
#define			WAIT						0x0002
#define			FAULT						0x0004

#define			BUSY						0x0001
#define			DONE						0x0002

#define 		DUMMY_DATA					0xFFFF

/*--------------------------------End SPI flash Registers-----------------------------------------------------*/

/*--------------------------------System Registers----------------------------------------------------*/

#define         BP_CR                       0x0000          /* Code ID Register */
#define         BP_SPR                      0x0002          /* Scratch Pad Register */

/*--------------------------------End System Registers------------------------------------------------*/

/*--------------------------------Buzzer Control Registers---------------------------------------------
        The Buzzer are used in Portable Tester to generate the modulating Audio tone
        in Short locator application and Audio notification for processor operation.
        Here the buzzer control are implemented using PWM controller. By varying the
        period and duty cycle the volume, tone of the buzzer can be controlled.
*/

#define         BP_BVCPR                    0x0004          /* Buzzer volume control period register*/
#define         BP_BVCDCR                   0x0006          /* Buzzer volume control duty cycle register*/
#define         BP_BVCER                    0x0008          /* Buzzer volume control enable register*/

#define         BP_BVCER_ENABLE_PERIOD      0x0001   /* Load new period, duty cycle value */
#define         BP_BVCER_ENABLE_PWM         0x0002   /* Load PWM output */

#define         BP_BTCPR                    0x000A          /* Buzzer tone control period register*/
#define         BP_BTCDCR                   0x000C          /* Buzzer tone control duty cycle register */
#define         BP_BTCER                    0x000E          /* Buzzer tone control enable register*/

#define         BP_BTCER_ENABLE_PERIOD      0x0001   /* Load new period, duty cycle value */
#define         BP_BTCER_ENABLE_PWM         0x0002   /* Load PWM output */

/*--------------------------------End Buzzer Control Registers---------------------------------------------*/


/*--------------------------------LCD Control Registers-----------------------------------------------------
        The following registers are used to control the Backlight of 8.4 inch TFT Display (800 X 600)
        and operation mode( 6bit or 8 bit LVDS interface).
*/

#define         BP_LCDMS                   XXXXXX          /* LCD Mode Selection */
#define         BP_LCDTE                   XXXXXX          /* Touch Enable */
#define         BP_LBCPR                   0x0010          /* LCD Backlight control period register */
#define         BP_LBCDCR                0x0012          /* LCD Backlight control duty cycle register */
#define         BP_LBER                     0x0014          /* LCD Backlight enable register */

#define         BP_LBER_ENABLE_PERIOD       0x0001   /* Load new period, duty cycle value */
#define         BP_LBER_ENABLE_PWM          0x0002   /* Load PWM output */

/*--------------------------------End LCD Control Registers------------------------------------------------*/

/*--------------------------------Magnetic Rotary Knob Control Registers-----------------------------------------------------*/

#define     BP_KCR			0x0016			/*Knob Command Register*/
#define     BP_KLSWR		0x0018			/*Knob LSW Register*/
#define     BP_KMSWR		0x001A		/*Knob MSW Register*/
#define     BP_KLTR			0x001C		/*Knob Loop Timer Register*/

/*--------------------------------End Magnetic Rotary Knob Control Registers-----------------------------------------------------*/

/*--------------------------------Interrupt Control Registers-----------------------------------------------------*/

#define   BP_ISCR			0x001E		/*Interrupt status/clear register*/
#define   BP_IER				0x0020			/*Interrupt Enable register*/
#define   BP_ISDR			0x0022			/*Interrupt Source/direct register*/
#define   BP_IGER			0x0024			/*Interrupt Global Enable register*/

/*--------------------------------End Interrupt Control Registers-----------------------------------------------------*/
/*--------------------------------SPI flash Registers-----------------------------------------------------*/
#define BP_SPIFLASH_CMD   0x0028
#define BP_SPIFLASH_TXLSW   0x002A
#define BP_SPIFLASH_TXMSW   0x002C
#define BP_SPIFLASH_RXLSW   0x2E
#define BP_SPIFLASH_RXMSW   0x0030
#define BP_SPI_BUSY 0x0
#define BP_SPI_STP_DRV     0x60
/*--------------------------------End SPI flash Registers-----------------------------------------------------*/




#endif // EMIDEVICE_H
