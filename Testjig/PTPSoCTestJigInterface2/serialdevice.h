/*
 * serialdevice.h
 *
 *  Created on: Mar 21, 2012
 *       By:Ravivarman.R
 */
#ifndef SERIALDEVICE_H_
#define SERIALDEVICE_H_

#define check_busy 								0x00
#define Psoc_CodeId 							0x08

#define vi_Trace								0x02
/**DMM selection**/
#define  l_nDmmSelection 						0x07
/*DMM resistance-2 wire*/
#define  l_n200E								0x20
#define  l_n2KE									0x21
#define  l_n20KE								0x22
#define  l_n200KE								0x23
#define  l_n2M									0x24
#define  l_n20M									0x25
/*DMM resistance-4 wire*/
#define  l_n4Wre200E							0x30
#define  l_n4Wre2KE								0x31
#define  l_n4Wre20KE							0x32
#define  l_n4Wre200KE							0x33
#define  l_n4Wre2M								0x34
#define  l_n4Wre20M								0x35

/*DMM Current*/
#define  l_n3Amp								0x10
#define  l_n200mAmp								0x11
#define  l_n20mAmp								0x12
#define  l_n2mAmp								0x13
/*DMM Voltage*/
#define  l_n1000V								0x00
#define  l_n200V								0x01
#define  l_n20V									0x02
#define  l_n2V									0x03
#define  l_n200mV								0x04
/**DMM selection**/

#define  l_nIcmValue							0x03			/*ICM*/
#define  l_nShortLocatorValue					0x05			/*Short locator*/
#define  l_nFgValue								0x06			/*Function Generator*/
#define  l_nSwitchFly							0xFC			/*Flying Channel Switch*/

#define  l_nScopeSelection						0x04			/*Scope*/
#define  l_nScope1_1Volt						0x00			/*Scope1*/
#define  l_nScope1_10Volt						0x01			/*Scope1*/
#define  l_nScope1_100Volt						0x02			/*Scope1*/
#define  l_nScope2_1Volt						0x03			/*Scope2*/
#define  l_nScope2_10Volt						0x04			/*Scope2*/
#define  l_nScope2_100Volt						0x05			/*Scope2*/
#define  l_nViSelection							0x02			/*VI*/
#define  l_nVi1Value							0x00			/*VI1*/
#define  l_nVi2Value							0x01			/*VI2*/

#define reset_relay 							0x40
#define l_nonTopRelay 							0x41
#define l_nonBottomRelay						0x42

#define l_noffTopRelay 							0x43
#define l_noffBottomRelay						0x44

#define l_nReadRlyStatus 						0x45
#define l_nReadRlySRCStatus						0x46
#define l_nSRCIMPEnable						    0x47
#define l_nSRCIMPDisable						0x48

#define embeddedKey 							0x01
#define  l_nExternalMuxValue					0x09			/*External Mux*/

//new functions & combination functions

#define No_Change								0x0F

#define Pwm_Start  							0x10
#define Pwm_Stop  							0x11

#define	vi12_scope2							0x12
#define	shloc_scope2						0x13
#define	dmm_scope2							0x14
#define	fg_scope12							0x15
#define	scope1_fg_scope2					0x16
#define	scope2_fg_scope1					0x17
#define	shloc_On							0x01
#define	shloc_Off							0x00
#define	fg_On								0x01


//typedef struct tty_info_t
//{
//    int fd;
//    pthread_mutex_t mt;
//    char name[24];
//    struct termios ntm;
//    struct termios otm;
//} TTY_INFO;
//
//TTY_INFO pttyInfo;
//TTY_INFO *ptty;

//SOURCE IMPEDANCE SELECTION

#define SRC_IMP_0E		0x0
#define SRC_IMP_10E		0x1
#define SRC_IMP_20E		0x2
#define SRC_IMP_50E		0x3
#define SRC_IMP_100E	0x4
#define SRC_IMP_200E	0x5
#define SRC_IMP_500E	0x6
#define SRC_IMP_1KE		0x7
#define SRC_IMP_2KE		0x8
#define SRC_IMP_5KE		0x9
#define SRC_IMP_10KE	0xA
#define SRC_IMP_20KE	0xB
#define SRC_IMP_50KE	0xC
#define SRC_IMP_100KE	0xD
#define SRC_IMP_200KE	0xE
#define SRC_IMP_500KE	0xF
#define SRC_IMP_1ME		0x10
#define SRC_IMP_1E		0x11
#define SRC_IMP_2E		0x12
#define SRC_IMP_3E		0x13
#define SRC_IMP_4E		0x14
#define SRC_IMP_5E		0x15
#define SRC_IMP_6E		0x16
#define SRC_IMP_7E		0x17





#endif /* SERIALDEVICE_H_ */
