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
#include "TASK5.h"

uint16 qdCount=0,qdCountPrev=0;

void task5 (void) _task_ 5{
//    while(1){
//            CyPins_ClearPin(PSoC_INT1_P3_6);		
//            CyDelayUs(100); 
//			CyPins_SetPin(PSoC_INT1_P3_6);			
//    }
    for(;;){
        uint16 m_u8MOSI;
        CyDelay(10);
        qdCount = QuadDecoder_GetCounter();// & 0x00FF;  // Get value of counts 
        
        if(!CyPins_ReadPin(EN_SW1_P6_7))
            qdCount = qdCount | 0x0100;
        
        //if(!CyPins_ReadPin(EN_SW1_P6_7))
          //  qdCount = qdCount + 0x8000;
        
        //if(qdCount!=qdCountPrev){
            CyPins_ClearPin(PSoC_INT1_P3_6);		
            CyDelayUs(100); 
			CyPins_SetPin(PSoC_INT1_P3_6);	
        //}
        
       	//while(!(SPIS_ReadRxStatus() & SPIS_STS_RX_FIFO_EMPTY)){
		//m_u8MOSI=SPIS_ReadRxData();       // Read SPI Data 
		//SPIS_ClearRxBuffer();
	    //}
        //if(m_u8MOSI&0x80){
        SPIS_WriteTxData(qdCount);
    	while(!(SPIS_ReadTxStatus() & SPIS_STS_TX_FIFO_EMPTY)){;}
        CyDelayUs(100);
        //}
    }
    /*for(;;){
        qdCount = QuadDecoder_GetCounter();  // Get value of counts 
        
            if(!CyPins_ReadPin(EN_SW1_P6_7))
                qdCount = qdCount + 0x5;
       
        UART_WriteTxData(qdCount);
		while(!(UART_ReadTxStatus() & UART_TX_STS_FIFO_EMPTY)){;}
        CyDelay(500u);
    }*/
}

void TASK_5 ()								//	INITIALISATION FUNCTION OF TASK5
{
	os_create_task(5);						//	CREATION OF TASK5
}
/* [] END OF FILE */
