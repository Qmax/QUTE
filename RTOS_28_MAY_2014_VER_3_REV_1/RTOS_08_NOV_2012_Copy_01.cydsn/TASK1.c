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

unsigned char prnt_en,i,prt_12,prt_15,prt_12_15,ucKey1Read,ucKey2Read,dat_cnt,cmd_exct;
unsigned char RLY_PRT_STS,val,pos,tst_ch,ref_ch,tst_bank,ref_bank,prt_12_s,e_prb_sts,VI,ShL;
unsigned char spi_tst_ch_tmp,spi_tst_ch_tmp1,spi_ref_ch_tmp,spi_ref_ch_tmp1,SC1,SC2,FG,DMM;
uint16 delay=0x000A;
uint16 swtch_delay=0x0001;

unsigned char tp1[24];
unsigned char k;

void task1 (void) _task_ 1
{
	uint8 p=0,k;
	for(;;)
	{
		os_wait1(K_SIG);					//	Wait for Signal from TASK 2
		
		if(prnt_en)
		{
			p=i-1;
			if(i == 0x00)					//	If Local Buffer is empty or overrun Print 0 else Print data
			{
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				
				UART_WriteTxData(rx_word[1]);
			}
			else
			{
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
				{
					;
				}
				for(k=0 ; k <= p ; k++)
				{
					UART_WriteTxData(rx_word[k]);
					while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
					{
						;
					}
				}
			}
			prnt_en = 0;
		}
		else
		{
			switching_main(&switch_cmd);
		}
    }    
}

void Relays_Init()							// Relays Initialize
{
	if (CyPins_ReadPin(PC_VI_2SEL0_P2_5))
		CyPins_ClearPin(PC_VI_2SEL0_P2_5);
        
	if (CyPins_ReadPin(PC_VI_2SEL1_P2_4))
		CyPins_ClearPin(PC_VI_2SEL1_P2_4);
        
	if (CyPins_ReadPin(BICM_SEL_P2_2))
		CyPins_ClearPin(BICM_SEL_P2_2);
        
	if (CyPins_ReadPin(BFG1_SEL_P2_3))
		CyPins_ClearPin(BFG1_SEL_P2_3);
        
	if (CyPins_ReadPin(MUXASEL_P2_1))
		CyPins_ClearPin(MUXASEL_P2_1);
        
	if (CyPins_ReadPin(SRC_0_P2_6))
		CyPins_ClearPin(SRC_0_P2_6);
        
	if (CyPins_ReadPin(SRC_1_P2_7))
		CyPins_ClearPin(SRC_1_P2_7);
        
	if (CyPins_ReadPin(SRC_2_P12_4))
		CyPins_ClearPin(SRC_2_P12_4);
        
	if (CyPins_ReadPin(SRC_3_P12_5))
		CyPins_ClearPin(SRC_3_P12_5);

    if (CyPins_ReadPin(SRC_4_P6_4))
		CyPins_ClearPin(SRC_4_P6_4);
}

void k1_k2_check()							//	Subroutine to Check Connection of Probe 1 & 2
{
	ucKey1Read  = CyPins_ReadPin(K1_SENSE_P0_3);
	ucKey2Read  = CyPins_ReadPin(K2_SENSE_P0_7);
}


void Test_Chnl_Switch(val_t)
{
	uint16 temp=0x0000;
	uint8 temp1;
	
	if(val_t <= 0x0F)
	{
		temp	= 0x0001 << val_t;
		temp1	= temp >> 0x08;
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(temp1);
		SPIM_WriteTxData(temp);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}

		CyDelayUs(15);

		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x01);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x02);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x03);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x08);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x11);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
	}
	else if(val_t >= 0x10 && val_t <= 0x1F)
	{
		val_t = val_t - 0x10;
		temp	= 0x0001 << val_t;
		temp1	= temp >> 0x08;		
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x01);
		SPIM_WriteTxData(temp1);
		SPIM_WriteTxData(temp);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x02);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x03);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x08);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x12);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
	}
	else if(val_t >= 0x20 && val_t <= 0x2F)
	{
		val_t = val_t - 0x20;
		temp	= 0x0001 << val_t;
		temp1	= temp >> 0x08;
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x01);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x02);
		SPIM_WriteTxData(temp1);
		SPIM_WriteTxData(temp);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);

		CyPins_ClearPin(CSN_P5_4);

		SPIM_WriteTxData(0x03);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x08);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x14);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
	}
	else if(val_t >= 0x30 && val_t <= 0x3F)
	{
		val_t = val_t - 0x30;
		temp	= 0x0001 << val_t;
		temp1	= temp >> 0x08;

		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x01);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x02);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x03);
		SPIM_WriteTxData(temp1);
		SPIM_WriteTxData(temp);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);

		CyPins_ClearPin(CSN_P5_4);

		SPIM_WriteTxData(0x08);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x18);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
	}
	else
	{
	
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x01);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x02);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);

		CyPins_ClearPin(CSN_P5_4);

		SPIM_WriteTxData(0x03);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);

		CyPins_ClearPin(CSN_P5_4);

		SPIM_WriteTxData(0x08);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
	}
	CyDelay(10);
}

void Ref_Chnl_Switch(val_r)
{
	uint16 temp=0x0000;
	uint8 temp1;

	if(val_r <= 0x0F)
	{
		temp	= 0x0001 << val_r;
		temp1	= temp >> 0x08;
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x04);
		SPIM_WriteTxData(temp1);
		SPIM_WriteTxData(temp);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}

		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x05);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x06);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x07);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x09);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x11);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
	}
	else if(val_r >= 0x10 && val_r <= 0x1F)
	{
		val_r = val_r - 0x10;
		temp	= 0x0001 << val_r;
		temp1	= temp >> 0x08;
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x04);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x05);
		SPIM_WriteTxData(temp1);
		SPIM_WriteTxData(temp);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x06);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x07);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x09);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x12);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
	}
	else if(val_r >= 0x20 && val_r <= 0x2F)
	{
		val_r = val_r - 0x20;
		temp	= 0x0001 << val_r;
		temp1	= temp >> 0x08;
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x04);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x05);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x06);
		SPIM_WriteTxData(temp1);
		SPIM_WriteTxData(temp);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x07);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x09);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x14);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
	}
	else if(val_r >= 0x30 && val_r <= 0x3F)
	{
		val_r = val_r - 0x30;
		temp	= 0x0001 << val_r;
		temp1	= temp >> 0x08;

		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x04);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x05);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x06);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x07);
		SPIM_WriteTxData(temp1);
		SPIM_WriteTxData(temp);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x09);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x18);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
	}
	else
	{
		CyPins_ClearPin(CSN_P5_4);
	
		SPIM_WriteTxData(0x04);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x05);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x06);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x07);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x09);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
		
		CyDelayUs(20);
		
		CyPins_ClearPin(CSN_P5_4);
		
		SPIM_WriteTxData(0x0F);
		SPIM_WriteTxData(0x00);
		SPIM_WriteTxData(0x00);
		while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY)){;}
		CyDelayUs(15);
		
		CyPins_SetPin(CSN_P5_4);
	}
	CyDelay(10);
}

void switching_main(unsigned char *cmd)		// Main Relay Switching Subroutine
{
	unsigned char mux_detect,rx_sword[8];
	
	switch(*cmd)

			
		case 0xF2:										//	VI-CH_2
				
			Relays_Init();				//	Relays Initialise Subroutine

			CyPins_SetPin(PC_VI_2SEL0_P2_5);
			UART_PutString("*");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("*");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
				
			UART_PutString("*");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
				
			UART_PutString("#");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}

			break;

		case 0x03:										//	ICM Select

			Relays_Init();				//	Relays Initialise Subroutine
            
            CyPins_SetPin(BICM_SEL_P2_2);

			UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			break;

			
		case 0x06:										//	Function Generator
		
			Relays_Init();			//	Relays Initialise Subroutine
			
			CyPins_SetPin(BFG1_SEL_P2_3);
			
			UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
		
			break;
			
			
		case 0x09:										//	Ex-MUX I/F	//
            CyPins_SetPin(MUXASEL_P2_1);
			CyDelay(swtch_delay);			//	PROGRAMMABLE MODULE SWITCHING DELAY [DEFAULT = 1mS]
			
			cmd++;
			Test_Chnl_Switch(*cmd);
			
			tp1[0] = rx_word[1];
			
			CyDelay(swtch_delay);			//	PROGRAMMABLE MODULE SWITCHING DELAY [DEFAULT = 1mS]
			
			cmd++;
			Ref_Chnl_Switch(*cmd);

			tp1[2] = rx_word[2];
			
			tp1[4] = tst_bank;
			
			tp1[6] = spi_tst_ch_tmp;
			
			tp1[8] = spi_tst_ch_tmp1;
			
			tp1[10] = ref_bank;
			
			tp1[12] = spi_ref_ch_tmp;
			
			tp1[14] = spi_ref_ch_tmp1;

			CyDelay(delay);			//	PROGRAMMABLE DELAY [DEFAULT = 10mS]

			UART_PutString("S");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("U");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("C");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("C");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("E");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("S");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("S");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			break;
			
		case 0x0A:										//	Ex-MUX Detect	//
			
			UART_PutString("*");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("*");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("*");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("#");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			SPIM_ClearTxBuffer();
			
			CyPins_ClearPin(CSN_P5_4);	//	Manual Chip_Select LOW
			
			SPIM_WriteTxData(0x15);
			SPIM_WriteTxData(0x15);
			SPIM_WriteTxData(0x15);
			while(!(SPIM_ReadTxStatus() & SPIM_STS_TX_FIFO_EMPTY))
			{
				rx_sword[0] = SPIM_ReadRxData();
			}

			CyDelayUs(14);

			CyPins_SetPin(CSN_P5_4);	//	Manual Chip_Select HIGH
			
			CyDelayUs(5);
			
			if(SPIM_ReadRxStatus())
			{
				rx_sword[0] = SPIM_ReadRxData();
				
				if(rx_sword[0] == 0x15){
					mux_detect = rx_sword[0];
				}
				else{
					mux_detect = 0x00;			// To be changed to 0 after testing is done.
				}
				
				UART_WriteTxData(mux_detect);
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
				SPIM_ClearRxBuffer();
				mux_detect = 0x00;
				rx_sword[0] = 0x00;
			}
			
			break;
			
		case 0x0B:										//	EX-MUX TEST Chnl ON	//
		
			cmd++;
			
            CyPins_SetPin(MUXASEL_P2_1);
			CyDelay(swtch_delay);			//	PROGRAMMABLE MODULE SWITCHING DELAY [DEFAULT = 1mS]
			
			Test_Chnl_Switch(*cmd);

			UART_PutString("*");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("*");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("*");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("#");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
		
			break;
            
		case 0x0C:										//	EX-MUX REF Chnl ON	//
			
			cmd++;
			
            CyPins_SetPin(MUXASEL_P2_1);
			CyDelay(swtch_delay);			//	PROGRAMMABLE MODULE SWITCHING DELAY [DEFAULT = 1mS]
			
            
			Ref_Chnl_Switch(*cmd);

			UART_PutString("*");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("*");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("*");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			UART_PutString("#");
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
            
			break;
			
		case 0x10:										//	 PWM START	//
			
			PWM_Start();
			PWM_Enable();
			
			UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
			{
				;
			}
			
			break;

		case 0x11:										//	 PWM STOP	//
			
			PWM_Stop();
			
			UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY))
			{
				;
			}
			
			break;
			
				
		case 0x1C:										//	Interrupt Pin Configure	//
		
			cmd++;
			
			if(*cmd == 0x00 || *cmd == 0x01)
			{
				embd_prb_int_config = *cmd;
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			}
			else if(*cmd == 0x0F)
			{
				/*	No Change OP	*/

				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			}
			else						//	Reset local rx_buffer on Unknown Rx Value	//
			{
				for(i = 0; i <= 31; i++){
					rx_word[i]	= 0x00;
				}
				dat_cnt		= 0;
				cmd_exct	= 0;

				UART_PutString("***?");			//	FAILURE ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			}
			
			break;
			
		case 0x40:										//	Debug Mode	//
		
			Relays_Init();			//	Relays Initialise Subroutine	//

			UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			
			break;
			
		case 0x45:										//	Read Port Status	//
		
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
            
            RLY_PRT_STS=0;
            
           	if (CyPins_ReadPin(PC_VI_2SEL0_P2_5))
		        RLY_PRT_STS = RLY_PRT_STS | 0x1;
            else
                RLY_PRT_STS = RLY_PRT_STS & 0xFE;
            
           	if (CyPins_ReadPin(PC_VI_2SEL1_P2_4))
                RLY_PRT_STS = RLY_PRT_STS | 0x2;
            else
                RLY_PRT_STS = RLY_PRT_STS & 0xFD;
                    
           	if (CyPins_ReadPin(BICM_SEL_P2_2))
                RLY_PRT_STS = RLY_PRT_STS | 0x4;
            else
                RLY_PRT_STS = RLY_PRT_STS & 0xFB;
                    
           	if (CyPins_ReadPin(BFG1_SEL_P2_3))
                RLY_PRT_STS = RLY_PRT_STS | 0x8;
            else
                RLY_PRT_STS = RLY_PRT_STS & 0xF7;
                    
           	if (CyPins_ReadPin(MUXASEL_P2_1))
                RLY_PRT_STS = RLY_PRT_STS | 0x10;
            else
                RLY_PRT_STS = RLY_PRT_STS & 0xEF;

          
			RLY_PRT_STS	= RLY_PRT_STS & 0x1F;
			UART_ClearTxBuffer();
			UART_WriteTxData(RLY_PRT_STS);
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
            
			break;
            
		case 0x46:										//	Read Port Status	//

			UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
            
            RLY_PRT_STS=0;
            
			if (CyPins_ReadPin(SRC_0_P2_6))
		        RLY_PRT_STS = RLY_PRT_STS | 0x1;
            else
                RLY_PRT_STS = RLY_PRT_STS & 0xFE;

        
            if (CyPins_ReadPin(SRC_1_P2_7))
                RLY_PRT_STS = RLY_PRT_STS | 0x2;
            else
                RLY_PRT_STS = RLY_PRT_STS & 0xFD;
                   
           	if (CyPins_ReadPin(SRC_2_P12_4))
                RLY_PRT_STS = RLY_PRT_STS | 0x4;
            else
                RLY_PRT_STS = RLY_PRT_STS & 0xFB;
                    
           	if (CyPins_ReadPin(SRC_3_P12_5))
                RLY_PRT_STS = RLY_PRT_STS | 0x8;
            else
                RLY_PRT_STS = RLY_PRT_STS & 0xF7;

            if (CyPins_ReadPin(SRC_4_P6_4))
                RLY_PRT_STS = RLY_PRT_STS | 0x10;
            else
                RLY_PRT_STS = RLY_PRT_STS & 0xEF;

                RLY_PRT_STS	= RLY_PRT_STS & 0x1F;
    			UART_ClearTxBuffer();
    			UART_WriteTxData(RLY_PRT_STS);
    			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
					
			break;   
                
		case 0x50:										//	BAUD RATE CHANGE	//
		
			cmd++;
			if(*cmd == 0x01){			// Select 9600 BAUD Rate	//
				UART_Stop();
				U_CLOCK_SetDividerValue(156);
				UART_Start();
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			}
			else if(*cmd == 0x02){		// Select 19200 BAUD Rate	//
				UART_Stop();
				U_CLOCK_SetDividerValue(78);
				UART_Start();
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){
					;
				}
			}
			else if(*cmd == 0x03){		// Select 38400 BAUD Rate	//
				UART_Stop();
				U_CLOCK_SetDividerValue(38);
				UART_Start();
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){
					;
				}
			}
			else if(*cmd == 0x04){		// Select 57600 BAUD Rate	//
				UART_Stop();
				U_CLOCK_SetDividerValue(26);
				UART_Start();
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){
					;
				}
			}
			else if(*cmd == 0x05){		// Select 115200 BAUD Rate	//
				UART_Stop();
				U_CLOCK_SetDividerValue(13);
				UART_Start();
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){
					;
				}
			}
			else if(*cmd == 0x0F){
				/*	No Change OP	*/
			
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){
					;
				}
			}
			else{
				for(i = 0; i <= 31; i++){
					rx_word[i]	= 0x00;
				}
				dat_cnt		= 0;
				cmd_exct	= 0;
				
				UART_PutString("***?");			//	FAILURE ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			}
			break;
            
		case 0x51:										//	SRC IMP SELECTION	//
		
			cmd++;

			if(*cmd & 0x01)
                CyPins_SetPin(SRC_0_P2_6);
            else
                CyPins_ClearPin(SRC_0_P2_6);
                
            if(*cmd & 0x02)
                CyPins_SetPin(SRC_1_P2_7);
            else
                CyPins_ClearPin(SRC_1_P2_7);    
                
            if(*cmd & 0x04)
                CyPins_SetPin(SRC_2_P12_4);
            else
                CyPins_ClearPin(SRC_2_P12_4);
                
            if(*cmd & 0x08)
                CyPins_SetPin(SRC_3_P12_5);
            else
                CyPins_ClearPin(SRC_3_P12_5);  
                
            if(*cmd & 0x10)
                CyPins_SetPin(SRC_4_P6_4);
            else
                CyPins_ClearPin(SRC_4_P6_4);
            
		    UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
			while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
            
			break;   	
            
		case 0xFF:									//	SOFTWARE RESET
		
			cmd++;
			if(*cmd == 0xFF){						
				CySoftwareReset();					//	SOFTWARE RESET COMMAND
			}
			else if(*cmd == 0x0F){
				/*	No Change OP	*/
				
				UART_PutString("***#");			//	STATUS ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			}
			else{
				for(i = 0; i <= 31; i++){
					rx_word[i]	= 0x00;
				}
				dat_cnt		= 0;
				cmd_exct	= 0;
				
				UART_PutString("***?");			//	FAILURE ACKNOWLEDGEMENT to uP	//
				while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
			}
			break;
		}
}

void TASK_1 ()								//	INITIALISATION FUNCTION OF TASK1
{
	os_create_task(1);						//	CREATION OF TASK1
}

/* [] END OF FILE */
