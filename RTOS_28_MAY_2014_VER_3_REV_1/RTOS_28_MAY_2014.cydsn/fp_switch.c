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

#include "os.h"
#include "UART_INT.h"
#include "fp_switch.h"

unsigned char prnt_en,i,*cmd,rx_word[32];

void fp_switch (void) _task_ 4
{
	uint8 p=0,k;
	*cmd = rx_word[32];
	
	for(;;)
	{
		os_wait1(K_SIG);			//	Wait for Signal from TASK 1 "UART_INT"	//

	if(prnt_en)
	{
		if(i == 0x00)
		{
			UART_WriteTxData(0);
		}
		else
		{
			p=i-1;
			for(k=0 ; k <= p ; k++)
			{
//				UART_WriteTxData(k);
//				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
//				{
//					;
//				}
				UART_WriteTxData(rx_word[k]);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
		}
//		do{
//			UART_ClearTxBuffer();
//			UART_WriteTxData(*cmd);
//			cmd++;j--;
//			}while(j);
			prnt_en = 0;
	}
	
	switch(*cmd)

		case 02:
		{
			cmd++;
			if(*cmd == 0x08)
			{
				UART_WriteTxData(0x08);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
			else if(*cmd == 0x04)
			{
				UART_WriteTxData(0x04);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
			else
			{}
			cmd++;
			if(*cmd == 0x07)
			{
				UART_WriteTxData(0x07);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
			else if(*cmd == 0x05)
			{
				UART_WriteTxData(0x05);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
			else
			{}
//			cmd++;
//			UART_WriteTxData(*cmd);
			break;

		case 03:
			cmd++;
			if(*cmd == 0x00)
			{
				UART_WriteTxData(0x00);			
			}
			else if(*cmd == 0xFF)
			{
				UART_WriteTxData(0xFF);
			}
			else
			{}
			cmd++;
			if(*cmd == 0x55)
			{
				UART_WriteTxData(0x55);
			}
			else if(*cmd == 0x77)
			{
				UART_WriteTxData(0x77);
			}
			else
			{}
			cmd++;
			if(*cmd == 0x66)
			{
				UART_WriteTxData(0x66);			
			}
			else if(*cmd == 0x99)
			{
				UART_WriteTxData(0x99);
			}
			else
			{}
			break;
			
		case 04:
			cmd++;
			if(*cmd == 0x00)
			{
				UART_WriteTxData(0x00);			
			}
			else if(*cmd == 0xFF)
			{
				UART_WriteTxData(0xFF);
			}
			else
			{}
			cmd++;
			if(*cmd == 0x55)
			{
				UART_WriteTxData(0x55);
			}
			else if(*cmd == 0x77)
			{
				UART_WriteTxData(0x77);
			}
			else
			{}
			cmd++;
			if(*cmd == 0x66)
			{
				UART_WriteTxData(0x66);			
			}
			else if(*cmd == 0x99)
			{
				UART_WriteTxData(0x99);
			}
			else
			{}
			cmd++;
			if(*cmd == 0xAB)
			{
				UART_WriteTxData(0xAB);			
			}
			else if(*cmd == 0xCD)
			{
				UART_WriteTxData(0xCD);
			}
			else
			{}
			break;
			
		case 05:
			cmd++;
			if(*cmd == 0x00)
			{
//				UART_WriteTxData(*cmd);
				cmd++;
				if(*cmd == 0x02)
				{
//					UART_WriteTxData(*cmd);
				}
				else if(*cmd == 0x03)
				{
//					UART_WriteTxData(*cmd);
				}
				else
				{}
			}
			else if(*cmd == 0x01)
			{
//				UART_WriteTxData(*cmd);
				cmd++;
				if(*cmd == 0x03)
				{
//					UART_WriteTxData(*cmd);
				}
				else if(*cmd == 0x04)
				{
//					UART_WriteTxData(*cmd);
				}
				else
				{}
			}
			break;
		
		case 06:
			
			cmd++;
//			UART_WriteTxData(*cmd);
			
			break;
			
		case 07:
			
			cmd++;
//			UART_WriteTxData(*cmd);
			
			break;
			
		case 0x40:
			
			UART_PutString("EXTERNAL MUX RELAYS SWITCHED");
			cmd++;
//			Test_Chnl_Switch(*cmd);
			CyDelay(10);
//			Ref_Chnl_Switch(*cmd);
			
			break;
			
		case 0x50:										//	BAUD RATE CHANGE	//
			
			cmd++;
			if(*cmd == 0x01)
			{
				UART_Stop();
//				U_CLOCK_SetDividerValue(156);
				UART_Start();
			}
			else if(*cmd == 0x02)
			{
				UART_Stop();
//				U_CLOCK_SetDividerValue(78);
				UART_Start();
			}
			else if(*cmd == 0x03)
			{
				UART_Stop();
//				U_CLOCK_SetDividerValue(38);
				UART_Start();
			}
			else if(*cmd == 0x04)
			{
				UART_Stop();
//				U_CLOCK_SetDividerValue(26);
				UART_Start();
			}
			else if(*cmd == 0x05)
			{
				UART_Stop();
//				U_CLOCK_SetDividerValue(13);
				UART_Start();
			}
			else if(*cmd == 0x0F)
			{
				/*	No Change OP	*/
			}
			else
			{
//				for(i = 0; i <= 31; i++)
//				{
//					rx_word[i]	= 0x00;
//				}
//				dat_cnt		= 0;
//				cmd_exct	= 0;
//				UART_PutString("Unknown Value");	
			}
			break;
			
//		case 0x0A:						//	logic to print last received CMD and DATA values	//
//		
//				p = i-1;
//				for(k=0 ; k <= p ; k++)
//				{
//					UART_WriteTxData(rx_word[k]);
//					while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
//					{
//						;
//					}
//				}
////				do{
////					UART_ClearTxBuffer();
////					UART_WriteTxData(*cmd);
////					cmd++;j--;
////				  }	while(j);
//				
//				break;
		}
	}
}

void fpswitch_INIT ()
{
	os_create_task(4);
}

/*void Test_Chnl_Switch(val)
{
	uint16 temp=0x0000;
	uint8 temp1;
	
	if(val <= 0x0F)
	{
		temp	= 0x0001 << val;
		temp1	= temp >> 0x08;

		UART_WriteTxData(temp1);
		
		UART_PutString("Inside Test Chnl Switch Val");
		
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(temp1);
		SPIM_WriteTxData(temp);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
		
		SPIM_WriteTxData(0x01);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
		
		SPIM_WriteTxData(0x02);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
		
		SPIM_WriteTxData(0x03);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
		
		SPIM_WriteTxData(0x08);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x11);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
	}

}*/

/*void Ref_Chnl_Switch(val)
{
	uint16 temp=0x0000;
	uint8 temp1;

	if(val <= 0x0F)
	{
		temp	= 0x0001 << val;
		temp1	= temp >> 0x08;
		
		UART_PutString("Inside Ref Chnl Switch Val");
		
		SPIM_WriteTxData(0x04);
		SPIM_WriteTxData(temp1);
		SPIM_WriteTxData(temp);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
		
		SPIM_WriteTxData(0x05);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
		
		SPIM_WriteTxData(0x06);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
		
		SPIM_WriteTxData(0x07);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
		
		SPIM_WriteTxData(0x09);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x11);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
		{
			;
		}
		CyDelayUs(10);
	}
	
}*/

/* [] END OF FILE */
