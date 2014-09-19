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

unsigned char switch_cmd[8],rx_word[32],k_port,k_val,d_msb,prb_sts;

void task2 (void) _task_ 2
{
	unsigned char word,dat_cnt = 0,cmd_exct = 0,lst_byte=0,cmd_set,stat,status,pos = 0;

	for(;;)
	{
		os_wait1(K_SIG);							//	Wait for signal from UART_ISR
		
		word	= UART_ReadRxData();
        
		if(dat_cnt == 0)
		{
			if(word == 0xFF)						//	Software Reset Command
			{
				i=0;
				rx_word[i]	= word;
				i++;
				dat_cnt		= 1;
				status		= 2;
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
			else if(word == 0x00)					//	Check Busy Status
			{
				UART_ClearTxBuffer();

				cmd_exct	= 0;
				dat_cnt		= 0;
			}
			else if(word == 0x01)					//	Embedded Probe Key
			{
                k_val=0x00;
				if(CyPins_ReadPin(K1_SENSE_P0_3))        k_val = k_val & 0xF7;
                else                                     k_val = k_val | 0x08;
                
                if(CyPins_ReadPin(K2_SENSE_P4_1))        k_val = k_val & 0x7F;
                else                                     k_val = k_val | 0x80;
                
                CyDelayUs(1000);
                
				UART_PutString("*");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			
				UART_PutString("*");
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			
				UART_PutString("*");
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			
				UART_PutString("#");
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				
				UART_WriteTxData(k_val);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				k_val 		= 0;
				cmd_exct	= 0;
				dat_cnt		= 0;
			}
			else if(word == 0xF1)					//	VI 1 
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i=0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;
				
			}


			else if(word == 0xF2)					//	VI 2 changed to single Byte CMD on 23 NOV 2012 11:26 AM
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i=0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;
				
			}
			else if(word == 0x03)					//	ICM Select
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i=0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;
				
			}
            else if(word == 0xFC)					//	Switch fly channel
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i=0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;
				
			}
			else if(word == 0x06)					//	Function Generator
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i=0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;
				
			}
			else if(word == 0x08)					//	CodeID Read
			{
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}

				UART_ClearTxBuffer();
				UART_WriteTxData(Code_ID);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				cmd_exct	= 0;
				dat_cnt		= 0;

			}
			else if(word == 0xD0)					//	DEVICE VERSION & REVISION READ
			{										//	CHANGE OF REV or VER TO BE MADE IN TASK1 HEADER FILE
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}

				UART_ClearTxBuffer();
				UART_WriteTxData(VERSION);		//	VERSION OF THE CODE
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				UART_WriteTxData(REVISION);		//	REVISION OF THE CODE
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				cmd_exct	= 0;
				dat_cnt		= 0;
			}
			else if(word == 0x09)					//	External Mux I/F
			{
				i=0;
				rx_word[i]	= word;
				i++;
				dat_cnt		= 2;
				status		= 3;
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
			else if(word == 0x0A)					//	External Mux Detect
			{
				i=0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;

			}
			else if(word == 0x0B)					//	EX-MUX TEST Chnl ON
			{
				i=0;
				rx_word[i]	= word;
				i++;
				dat_cnt		= 1;
				status		= 2;
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
			else if(word == 0x0C)					//	EX-MUX REF Chnl ON
			{
				i=0;
				rx_word[i]	= word;
				i++;
				dat_cnt		= 1;
				status		= 2;
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
			else if(word == 0x10)					//	 PWM START
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i=0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;

			}
			else if(word == 0x11)					//	 PWM STOP
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i=0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;

			}
			else if(word == 0x18)					//	Embedded Probe Status
			{
                if(prb_sts==0){
                    if(CyPins_ReadPin(K1_SENSE_P0_3))        k_port = k_port | 0x08;
                    else                                     k_port = k_port & 0xF7;
        
                    if(CyPins_ReadPin(Key1_2_P0_0))          k_port = k_port | 0x01;
                    else                                     k_port = k_port & 0xFE;

                    if(CyPins_ReadPin(Key1_1_P0_1))          k_port = k_port | 0x02;
                    else                                     k_port = k_port & 0xFD;
                    
                    if(CyPins_ReadPin(Key1_0_P0_2))          k_port = k_port | 0x04;
                    else                                     k_port = k_port & 0xFB;
                    
                    if(CyPins_ReadPin(K2_SENSE_P4_1))        k_port = k_port | 0x80;
                    else                                     k_port = k_port & 0x7F;    
                    
                    if(CyPins_ReadPin(Key2_0_P4_0))          k_port = k_port | 0x40;
                    else                                     k_port = k_port & 0xBF;    
                    
                    if(CyPins_ReadPin(Key2_1_P12_3))         k_port = k_port | 0x20;
                    else                                     k_port = k_port & 0xDF;    
                    
                    if(CyPins_ReadPin(Key2_2_P12_2))         k_port = k_port | 0x10;
                    else                                     k_port = k_port & 0xEF;    
            	
                    CyDelayUs(500);     
                    
                    k_port = k_port  ^ 0x88;						//	Set Keysense active high '1'
                    prb_sts = k_port ;
                }
				//prb_sts = CY_GET_REG8(CYDEV_IO_PRT_PRT0_PS);		//Port0 Read
				//prb_sts = ~prb_sts;									//Invert Port0 Data
				//prb_sts = prb_sts & 0x88;							//Mask the Key Pin Input from Port0 Data
				//prb_sts = prb_sts >> 3;
				
				UART_PutString("*");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				
				UART_PutString("*");
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			
				UART_PutString("*");
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			
				UART_PutString("#");
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				
				UART_WriteTxData(prb_sts);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			
				cmd_exct	= 0;
				dat_cnt		= 0;
			}
			else if(word == 0x1C)					//	Interrupt Pin Configuration
			{
				i=0;
				rx_word[i]	= word;
				i++;
				dat_cnt		= 1;
				status		= 2;
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
			else if(word == 0x40)					//	Debug Mode
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i=0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;
				
			}
			else if(word == 0x45)					//	Port Status Read
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i = 0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;
				
			}
			else if(word == 0x46){					//	SRC IMP Status Read
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i = 0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
                
				cmd_exct	= 0;
				dat_cnt		= 0;
				
			}			
			else if(word == 0x47)					//	SRC IMP ENABLE
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i=0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;
				
			}            
			else if(word == 0x48)					//	SRC IMP DISABLE
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i=0;
				rx_word[i]	= word;
				switch_cmd[0] = rx_word[i];
				os_send_signal(1);
				
				cmd_exct	= 0;
				dat_cnt		= 0;
				
			}                        
			else if(word == 0x50)					//	BAUD RATE CHANGE
			{
				i=0;
				rx_word[i]	= word;
				i++;
				dat_cnt		= 1;
				status		= 2;
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
            else if(word == 0x51)					//	SRC IMP SELECTION
			{
				i=0;
				rx_word[i]	= word;
				i++;
				dat_cnt		= 1;
				status		= 2;
				
				UART_ClearRxBuffer();
                UART_ClearTxBuffer();                
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
                {
                    ;
                }
               UART_ClearTxBuffer();   
			}			
			else if(word == 0x55)					//	Loop Check
			{
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				
				UART_ClearTxBuffer();
				UART_WriteTxData(word);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				cmd_exct	= 0;
				dat_cnt		= 0;
			}
			else if(word == 0x0D)					//	Print Stored Values
			{
				cmd_exct	= 0;
				dat_cnt		= 0;
				prnt_en		= 1;
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				
				os_send_signal(1);					//	Send signal to TASK1 for execution
			}
			else if(word == 0xDE)					//	PROGRAMMABLE DELAY
			{
				for(i=0; i<=8; i++)
				{
					rx_word[i]	= 0x00;
				}
				i=0;
				rx_word[i]	= word;
				i++;
				dat_cnt		= 2;
				status		= 3;
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
			}
			else if(word == 0xDD)					//	PROGRAMABLE DELAY VALUE READ BACK
			{
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				
				d_msb = delay >> 8;
				
				UART_ClearTxBuffer();
				UART_WriteTxData(d_msb);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}

				UART_WriteTxData(delay);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				
				cmd_exct	= 0;
				dat_cnt		= 0;
			}
			else
			{
				for(i = 0; i <= 31; i++)
				{
					rx_word[i]	= 0x00;
				}
				dat_cnt		= 0;
				cmd_exct	= 0;
				
				UART_PutString("***?");
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
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
				if(rx_word[0] == 0xDE)
				{
					delay = 0;
					delay = delay + rx_word[1];
					delay = delay << 8;
					delay = delay + rx_word[2];
				}
			}
			else
			{
				cmd_exct = 0;
			}
		}
		if(cmd_exct == 1)
		{
			lst_byte = --i;
			cmd_set = status-1;
				
			for(stat = status; stat > 0; stat--)
			{
				switch_cmd[cmd_set] = rx_word[lst_byte];
				lst_byte--;cmd_set--;
			}
			
			cmd_exct = 0;
     		os_send_signal(1);						//	Send signal to TASK1 for execution
			++i;
		}
	}
}

void TASK_2 ()										//	INITIALISATION FUNCTION OF TASK2
{
	os_create_task(2);								//	CREATION OF TASK2
}

/* [] END OF FILE */
