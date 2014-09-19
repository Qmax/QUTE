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

#include "TASK1.h"
#include "TASK2.h"
#include "TASK3.h"
#include "TASK4.h"

void task4 (void) _task_ 4
{
	for(;;)
	{
		os_wait1(K_SIG);	//	Wait for Signal From Main OS
		
		UART_WriteTxData(0x2a);
		while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
		{
			;
		}
	
		UART_WriteTxData(0x2a);
		while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
		{
			;
		}
	
		UART_WriteTxData(0x2a);
		while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
		{
			;
		}
	
		UART_WriteTxData(0x2a);
		while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
		{
			;
		}
	
		UART_WriteTxData(0x2a);
		while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
		{
			;
		}
	
		UART_WriteTxData(0x2a);
		while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
		{
			;
		}
	
		UART_WriteTxData(0x3f);
		while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
		{
			;
		}
		os_delete_task (4); 			//	DELETE 'OS' TASK
	
	}
}

void TASK_4 ()								//	INITIALISATION FUNCTION OF TASK4
{
	os_create_task(4);						//	CREATION OF TASK4
}

/* [] END OF FILE */
