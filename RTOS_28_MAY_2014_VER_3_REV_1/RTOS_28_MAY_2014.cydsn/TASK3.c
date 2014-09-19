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
        
    /*           if(CyPins_ReadPin(K1_SENSE_P0_3))        k_port = k_port | 0x80;
        else                                     k_port = k_port & 0x7F;    CyDelayUs(10);
        
        if(CyPins_ReadPin(Key1_2_P0_0))          k_port = k_port | 0x40;
        else                                     k_port = k_port & 0xBF;    CyDelayUs(10);

        if(CyPins_ReadPin(Key1_1_P0_1))          k_port = k_port | 0x20;        
        else                                     k_port = k_port & 0xDF;    CyDelayUs(10);        
        
        if(CyPins_ReadPin(Key1_0_P0_2))          k_port = k_port | 0x10;
        else                                     k_port = k_port & 0xEF;    CyDelayUs(10);
        

        
        if(CyPins_ReadPin(K2_SENSE_P4_1))        k_port = k_port | 0x8;
        else                                     k_port = k_port & 0xF7;    CyDelayUs(10);
        
        if(CyPins_ReadPin(Key2_0_P4_0))          k_port = k_port | 0x1;
        else                                     k_port = k_port & 0xFE;    CyDelayUs(10);
        
        if(CyPins_ReadPin(Key2_1_P12_3))         k_port = k_port | 0x2;
        else                                     k_port = k_port & 0xFD;    CyDelayUs(10);
        
        if(CyPins_ReadPin(Key2_2_P12_2))         k_port = k_port | 0x4;
        else                                     k_port = k_port & 0xFB;    CyDelayUs(10);        
        
		//k_port = CY_GET_REG8(CYDEV_IO_PRT_PRT0_PS);			//	store the key Value from PORT 0 to k_port
		k_port = k_port ^ 0x88;								//	Return key value
       		
  		do	{												//	Key Debounce Logic: Interrupt disabled &
            if(CyPins_ReadPin(K2_SENSE_P4_1))
                k_val1 = k_port | 0x80;
            else 
                k_val1 = k_port & 0x7F;
            
            if(CyPins_ReadPin(Key2_0_P4_0))
                k_val1 = k_port | 0x40;
            else 
                k_val1 = k_port & 0xBF;        
            
            if(CyPins_ReadPin(Key2_1_P12_3))
                k_val1 = k_port | 0x20;        
            else 
                k_val1 = k_port & 0xDF;        
            
            if(CyPins_ReadPin(Key2_2_P12_2))
                k_val1 = k_port | 0x10;        
            else 
                k_val1 = k_port & 0xEF;        
            
            if(CyPins_ReadPin(K1_SENSE_P0_3))
                k_val1 = k_port | 0x8;
            else 
                k_val1 = k_port & 0xF7;
            
            if(CyPins_ReadPin(Key1_0_P0_2))
                k_val1 = k_port | 0x4;
            else 
                k_val1 = k_port & 0xFB;
            
            if(CyPins_ReadPin(Key1_1_P0_1))
                k_val1 = k_port | 0x2;
            else 
                k_val1 = k_port & 0xFD;
            
            if(CyPins_ReadPin(Key1_2_P0_0))
                k_val1 = k_port | 0x1;
            else 
                k_val1 = k_port & 0xFE;        
		  		//k_val1 = CY_GET_REG8(CYDEV_IO_PRT_PRT0_PS);	//	key press on hold untill key is released
				k_val1 = k_val1 & 0x77;						//	this line was included inside the loop on [29/11/2012]
    		}	while(k_val1);								//	This does not interrupt the UART Process
		
		k_val =  k_port;									//	Return key vale
		CyIntEnable (24);							//	Enable k_isr Interrupt
		//if(embd_prb_int_config == 0x00)				//	Select PSoC_Int0
		//{
//			CyPins_ClearPin(PSoC_INT0_P3_7);		//	Interrupt line to CPU(i.MX51) Set low
//          CyDelayUs(1);
//			CyPins_SetPin(PSoC_INT0_P3_7);			//	Interrupt line Set high
		}
		else if(embd_prb_int_config == 0x01)		//	Select PSoC_Int1
		{
   			CyPins_ClearPin(PSoC_INT0_P3_7);		//	Interrupt line to CPU(i.MX51) Set low
			CyPins_SetPin(PSoC_INT0_P3_7);			//	Interrupt line Set high
//			CyPins_ClearPin(PSoC_INT1_P3_6);		//	Interrupt line to CPU(i.MX51) Set low
//			CyPins_SetPin(PSoC_INT1_P3_6);			//	Interrupt line Set high
		}*/
	}
}

CY_ISR(key_interrupt)							//	Relocated Key Pad ISR
{
 	CyIntDisable (24);							//	Disable k_isr Interrupt
	//k_port = CY_GET_REG8(CYDEV_IO_PRT_PRT0_PS);	//	store the key Value from PORT 0 to k_port
     k_port=0x00;  
    do{
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
        prb_sts = k_port ;//& 0x77;
    }while(!CyPins_ReadPin(KEY_INT));
	/*
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
	}*/
		CyPins_ClearPin(PSoC_INT0_P3_7);		//	Interrupt line to CPU(i.MX51) Set low
        CyDelayUs(1);
		CyPins_SetPin(PSoC_INT0_P3_7);			//	Interrupt line Set high    
            
        KEY_ClearInterrupt();					//	Enable k_isr Interrupt
		CyIntEnable (24);						//	Enable k_isr Interrupt

}

void TASK_3 ()									//	INITIALISATION FUNCTION OF TASK3
{
	os_create_task(3);							//	CREATION OF TASK3
}

/* [] END OF FILE */
