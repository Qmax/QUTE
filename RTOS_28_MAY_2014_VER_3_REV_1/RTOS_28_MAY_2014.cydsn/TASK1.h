/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#if !defined(__TASK1_H__)
#define __TASK1_H__
#include <rtx51tny.h>

#include <device.h>

void TASK_1 (void);

extern unsigned char embd_prb_int_config;
void Test_Chnl_Switch(unsigned char);
void Ref_Chnl_Switch(unsigned char);
void switching_main(unsigned char*);
void Relays_Init(void);
void SRCIMP_Init(void);
void k1_k2_check(void);

/* FRONT PANEL FIRMWARE VERSION AND REVISION HISTORY */

	//  #define VERSION  0x02		//	VERSION	 : 2
	//#define REVISION 0x00		//	REVISION : 0	>PSoC Firmware Changed to support FRONT PANEL Hardware Ver 2.0
	//------------------------------------------------------------------------------------------------------------------//
	//#define REVISION 0x01		//	REVISION : 1	>RL14 SCOPE1 ADDED
	//------------------------------------------------------------------------------------------------------------------//
	//#define REVISION 0x02		//	REVISION : 2	>RL14 SCOPE1 ADDED AND REMOVED FROM CMPTBL MODES OFF RL SEQ
	//							//					 VI Ch is Switched only after checking for the presence of VI probes
	//------------------------------------------------------------------------------------------------------------------//
	//#define REVISION 0x03		//	REVISION : 3	>FG ON & OFF CONTROL in SCOPE 1&2 FG Combination and one ACK for
	//							//					 every SCOPE 1&2 and FG Combination instead of ACK for each mode.
	//------------------------------------------------------------------------------------------------------------------//
	//  #define REVISION 0x04		//	REVISION : 4	>TASK 4 Deletion command os_delete_task (4) added at the end of the
	//												 Task 4.
	//												>ACKNOWLEDGEMENT status "***#" & "***?" added for all the Header 
	//												 command with one or more data byte command following TASK 2.
	//												>In the Relays_Init() function the Ports are checked for OFF State. IF
	//												 its off already NOP is followed else CyPins_ClearPin() is executed.
	//												>Under CMD 0x0A - Ext-Mux Detect LINE 2306: mux_detect = 0x00;
	//												 Prev Statement at LINE 2306: mux_detect = SPIM_ReadRxData();
	//-------------------------------------------------------------------------------------------------------------------//
    #define VERSION  0x03   //ADDED BY RRV FOR V3R1
    #define REVISION 0x01   //ADDED BY RRV FOR V3R1

//[] END OF FILE
