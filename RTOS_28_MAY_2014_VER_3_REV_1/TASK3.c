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

unsigned char k_val1,embd_prb_int_config,en_int;
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
		
		if(en_int)
		{
			en_int = 0;
			k_port = CY_GET_REG8(CYDEV_IO_PRT_PRT0_PS);			//	store the key Value from PORT 0 to k_port
			k_port = k_port ^ 0x88;								//	Return key value
        		
	  		do	{												//	Key Debounce Logic: Interrupt disabled &
			  		k_val1 = CY_GET_REG8(CYDEV_IO_PRT_PRT0_PS);	//	key press on hold untill key is released
					k_val1 = k_val1 & 0x77;						//	this line was included inside the loop on [29/11/2012]
	    		}	while(k_val1);								//	This does not interrupt the UART Process
			
			k_val =  k_port;									//	Return key vale
/*		if(!CyPins_ReadPin(KEY_INT))			//	Key Debounce Logic: Wait for defined time
		{										//	before the key press is released. If the 
			for(t =	-20000; t <= k_val; t++)	//	key press is released earlier the loop is broken.
			{
				if(!CyPins_ReadPin(KEY_INT))
				{
					k_val = 1;
				}
				else
				{
					k_val = -20000;
				}
			}
		}*/
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
			UART_PutString("ISR_ENABLED");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
			{
				;
			}
		}
		else
			UART_PutString("ISR_DISABLED");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
			{
				;
			}
			k_val =  0;								//	Return key vale
			CyIntEnable (24);						//	Enable k_isr Interrupt
	}
}

CY_ISR(key_interrupt)								//	Relocated Key Pad ISR
{
	UART_PutString("CY_ISR");
	while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
	{
		;
	}
	CyIntDisable (24);								//	Disable k_isr Interrupt
/*	for(k_val = 0; k_val <= 50; k_val++)
	{
		k_port = CY_GET_REG8(CYDEV_IO_PRT_PRT0_PS);	//	store the key Value from PORT 0 to k_port
		
		if(k_port)
		{
			break;
		}
	}	*/
	k_port = CY_GET_REG8(CYDEV_IO_PRT_PRT0_PS);		//	store the key Value from PORT 0 to k_port
	k_port = k_port ^ 0x88;							//	Set Keysense active high '1'
	
	if(k_port)										//	Execute if Key probe connected
	{
		if(k_port & 0x77)    
		{
			en_int	= 1;
		 	isr_send_signal(3);
	  	 	KEY_ClearInterrupt();
		}
	}
	else
	{
		en_int	= 0;
		isr_send_signal(3);
	  	KEY_ClearInterrupt();					//	Enable k_isr Interrupt
	}
	
//	isr_send_signal(3);							//	SEND SIGNAL TO TASK3 FOR EXECUTION
//	KEY_ClearInterrupt();						//	Clear the interrupt Status
}

void TASK_3 ()									//	INITIALISATION FUNCTION OF TASK3
{
	os_create_task(3);							//	CREATION OF TASK3
}

/* [] END OF FILE */
