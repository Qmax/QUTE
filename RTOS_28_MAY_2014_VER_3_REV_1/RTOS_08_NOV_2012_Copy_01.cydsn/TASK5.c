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

void task5 (void) _task_ 5{
    for(;;){
        uint8 m_u8MOSI;
        
        qdCount = QuadDecoder_GetCounter();  /* Get value of counts */
        
        if(qdCount!=qdCountPrev){
            CyPins_ClearPin(DEC_INT_P3_2);		//	Interrupt line to CPU(i.MX51) Set low
		    CyPins_SetPin(DEC_INT_P3_2);			//	Interrupt line Set high
        }
        
       	while(!(SPIS_ReadRxStatus() & SPIS_STS_RX_FIFO_EMPTY)){
		m_u8MOSI=SPIS_ReadRxData();       /* Read SPI Data */ 
		SPIS_ClearRxBuffer();
	    }
        if(m_u8MOSI&0x80){
        SPIS_WriteTxData(qdCount);
		while(!(SPIS_ReadTxStatus() & SPIS_STS_TX_FIFO_EMPTY)){;}
        CyDelay(500u);
        }
    }
}
void TASK_5 ()								//	INITIALISATION FUNCTION OF TASK5
{
	os_create_task(5);						//	CREATION OF TASK5
}
/* [] END OF FILE */
