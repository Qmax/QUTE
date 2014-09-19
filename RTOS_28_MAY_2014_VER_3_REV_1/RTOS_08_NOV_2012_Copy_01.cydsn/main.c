/* ========================================
 *
 * Copyright QMAX, 2012
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF QMAX.
 *
 * ========================================
*/
#include <device.h>
#include <rtx51tny.h>
#include "os.h"
#include "TASK1.h"
#include "TASK2.h"
#include "TASK3.h"
#include "TASK4.h"

void os (void) _task_ OS			//	FUNCTION OF 'OS' IS TO CREATE TASK'S 1 2 & 3 AND DELETE ITSELF
{
	CyDelay(1000);
	RTX51_Start();					//	RTX51TINY MODULE INITIALISATION
	U_CLOCK_SetDividerValue(38);	//	CLOCK DIVIDER INITIALISATION BAUD RATE SET AT 38400 BAUD RATE-> 19-08-2013
	isr_Start();					//	UART ISR INITIALISATION
	k_isr_Start();					//	EMBEDDED KEYPAD INTERRUPT INITIALISATION
	UART_Start();					//	UART INITIALISATION
	SPIM_Start();					//	SPIM INITIALISATION

    QuadDecoder_Start();            //ADDED BY RRV FOR V3R1
    QuadDecoder_SetCounter(0u);     //ADDED BY RRV FOR V3R1
    qdCountPrev=0;                  //ADDED BY RRV FOR V3R1
    
	/*	DMM HV_1000V DEFAULT PoR MODE	*/
	
	Relays_Init();					//	Relays Initialise Subroutine
			
	/*/////  Relays Switched ON ///// //COMMNETED BY RRV FOR V3R1
	
	CyPins_SetPin(RES_SEL1_P2_6);   
	CyPins_SetPin(RR1_100V_P4_4);
	CyPins_SetPin(DMM_SEL_P12_2);*/

	UART_ClearRxBuffer();			//	Clear Receive Buffer
	UART_ClearTxBuffer();			//	Clear Transmit Buffer
    SPIS_ClearRxBuffer();           //ADDED BY RRV FOR V3R1

	TASK_1 ();						//	INITIALISATION OF TASK1: FRONT PANEL RELAY SWITCHING FUNCTION
	TASK_2 ();						//	INITIALISATION OF TASK2: COMMAND AND DATA RECEIVE SIGNALLED BY UART INTERRUPT
	TASK_3 ();						//	INITIALISATION OF TASK3: EMBEDDED KEYPAD RECEIVE INTERRUPT
	TASK_4 ();						//	INITIALISATION OF TASK4: PoR/RESET STATUS ACKNOWLEDGMENT
    TASK_5 ();						//	INITIALISATION OF TASK5: QUAD DECODER
	
	os_send_signal(4);				//	SEND SIGNAL TO TASK_4
	os_delete_task (OS); 			//	DELETE 'OS' TASK
}

/* [] END OF FILE */
