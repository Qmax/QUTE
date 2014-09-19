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

extern unsigned char prnt_en,i,rx_word[32];
//unsigned char rx_flag;

void UART_INT (void) _task_ 3
{
	unsigned char lst_byte=0,cmd_set,word,dat_cnt=0,status,rx_word[32],cmd_exct,switch_cmd[8];
	int	stat;
	
	UART_PutString("UART_INIT");
	
	for(;;)
	{
//		os_wait(K_SIG,0);		//	Wait for Signal from UART Interrupt	//
		
//		if(rx_flag)
		{
			word	= UART_ReadRxData();
//			rx_flag	= 0;
			
			if(i > 31)				//	if(i >= 31) till 31_10_2012 /*	Clear Local Buffer when 32 bytes are overrun	*/
			{
				i = 0;
//				for(i = 0; i <= 31; i++)
//				{
//					rx_word[i]	= 0x00;
//				}
			}
			
			if(dat_cnt == 0)
			{
				if(word == 0xFF)
				{
					CySoftwareReset();
				}
				else if(word == 0x00)
				{
					UART_PutString("00H has been passed");
				}
				else if(word == 0x01)
				{
					UART_PutString("01H has been passed");
				}
				else if(word == 0x02)
				{
					rx_word[i]	= word;
					i++;
					dat_cnt	= 2;
					status = 3;
				}
				else if(word == 0x40)
				{
					rx_word[i]	= word;
					i++;
					dat_cnt	= 1;
					status = 2;
				}
				else if(word == 0x03)
				{
					rx_word[i]	= word;
					i++;				
					dat_cnt	= 3;
					status = 4;
				}
				else if(word == 0x04)
				{
					rx_word[i]	= word;
					i++;
					dat_cnt	= 4;
					status = 5;
				}
				else if(word == 0x0A)				//	Print Stored Values	//
				{
					cmd_exct	= 0;
					dat_cnt		= 0;
					prnt_en		= 1;
//					outside_main();
				}
				else if(word == 0x05)
				{
					rx_word[i]	= word;
					i++;				
					dat_cnt	= 2;
					status = 3;
				}
				else if(word == 0x06)
				{
					rx_word[i]	= word;
					i++;				
					dat_cnt	= 1;
					status = 2;
				}
				else if(word == 0x07)
				{
					rx_word[i]	= word;
					i++;				
					dat_cnt	= 1;
					status = 2;
				}
				else if(word == 0x50)				//	BAUD RATE CHANGE	//
				{
					rx_word[i]	= word;
					i++;
					dat_cnt		= 1;
					status = 2;
				}
				else
				{
//					for(i = 0; i <= 31; i++)
//					{
//						rx_word[i]	= 0x00;
//					}
					dat_cnt		= 0;
					cmd_exct	= 0;
					UART_PutString("Unknown Value");
				}
			}
			else if(dat_cnt)
			{
				rx_word[i]	= word;
				i++;
				dat_cnt--;
				if(dat_cnt == 0)
				{
					cmd_exct = 1;
				}
				else
				{
					cmd_exct = 0;
				}
			}
		}
		if(cmd_exct)
		{
			lst_byte = --i;
			cmd_set = status-1;
			for(stat = status; stat > 0; stat--)
			{
				switch_cmd[cmd_set] = rx_word[lst_byte];
				lst_byte--;cmd_set--;
			}
			cmd_exct = 0;
			os_send_signal(4);
//			outside_main(&switch_cmd);
			++i;
		}
	}
}

//void UART_INIT (void)
//{
//	os_create_task(3);
//}

/* [] END OF FILE */
