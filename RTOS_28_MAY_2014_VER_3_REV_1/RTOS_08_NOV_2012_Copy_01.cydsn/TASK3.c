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

#include "TASK1.h"
#include "TASK2.h"
#include "TASK3.h"
#include "TASK5.h"

unsigned char k_val1,embd_prb_int_config;
uint8 count;
int t;

CY_ISR_PROTO(key_interrupt);						//	prototype for reloacted keypad isr Interrupt

void task3 (void) _task_ 3
{
	k_isr_ClearPending();							//	clear any pending Interrupt
	k_isr_StartEx(key_interrupt);					//	Change the Interrupt Address to custom ISR routine
		
	while (1)
	{
		os_wait1(K_SIG);							//	Wait for signal from k_isr Interrupt routine
		
		k_port = CY_GET_REG8(CYDEV_IO_PRT_PRT0_PS);			//	store the key Value from PORT 0 to k_port
		k_port = k_port ^ 0x88;								//	Return key value
       		
  		do	{												//	Key Debounce Logic: Interrupt disabled &
		  		k_val1 = CY_GET_REG8(CYDEV_IO_PRT_PRT0_PS);	//	key press on hold untill key is released
				k_val1 = k_val1 & 0x77;						//	this line was included inside the loop on [29/11/2012]
    		}	while(k_val1);								//	This does not interrupt the UART Process
		
		k_val =  k_port;									//	Return key vale
		CyIntEnable (24);							//	Enable k_isr Interrupt
		if(embd_prb_int_config == 0x00)				//	Select PSoC_Int0
		{
			CyPins_ClearPin(PSoC_INT0_P3_7);		//	Interrupt line to CPU(i.MX51) Set low
			CyPins_SetPin(PSoC_INT0_P3_7);			//	Interrupt line Set high
		}
		else if(embd_prb_int_config == 0x01)		//	Select PSoC_Int1
		{
			CyPins_ClearPin(PSoC_INT1_P3_6);		//	Interrupt line to CPU(i.MX51) Set low
			CyPins_SetPin(PSoC_INT1_P3_6);			//	Interrupt line Set high
		}
	}
}

CY_ISR(key_interrupt)							//	Relocated Key Pad ISR
{
 	CyIntDisable (24);							//	Disable k_isr Interrupt
	k_port = CY_GET_REG8(CYDEV_IO_PRT_PRT0_PS);	//	store the key Value from PORT 0 to k_port
	k_port = k_port ^ 0x88;						//	Set Keysense active high '1'
	
	if(k_port)									//	Execute if Key probe connected
	{
		if(k_port & 0x77)    
		{
		 	isr_send_signal(3);
	  	 	KEY_ClearInterrupt();				//	Enable k_isr Interrupt
		}
		else
		{
			CyIntEnable (24);					//	Enable k_isr Interrupt
			KEY_ClearInterrupt();				//	Enable k_isr Interrupt
		}
	}
	else
	{
	  	KEY_ClearInterrupt();					//	Enable k_isr Interrupt
		CyIntEnable (24);						//	Enable k_isr Interrupt
	}

}

void TASK_3 ()									//	INITIALISATION FUNCTION OF TASK3
{
	os_create_task(3);							//	CREATION OF TASK3
}

/* [] END OF FILE */
