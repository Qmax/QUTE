/* ========================================
 *
 * Copyright QMAX TEST EQUIPMENTS, 2014
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 * AUTHOR : RAVIVARMAN.R
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF QMAX TEST EQUIPMENTS.
 *
 * ========================================
*/
#include <project.h>
#include "macros.h"

int main()
{
   	uint16 m_u8MOSI=0,m_u8MISO=0;
    uint16 m_u8RLStatus[16];
	
	SPIS_Start();
	
	/* Initializations */
	/* Clear All Relays */
	CyPins_ClearPin(BCH1_DIV0_RLY_P4_7);
    CyPins_ClearPin(BCH1_DIV1_RLY_P4_6);
    CyPins_ClearPin(BCH1_CALIB_RLY_P4_5);
	
    CyPins_ClearPin(BCH2_DIV0_RLY_P4_4);
    CyPins_ClearPin(BCH2_DIV1_RLY_P4_3);
    CyPins_ClearPin(BCH2_CALIB_RLY_P4_2);
    
    CyPins_ClearPin(BTRG_EXT5_RLY_P0_7);
	
    CyPins_ClearPin(SAMPLEMODE_S0_P0_6);
    CyPins_ClearPin(SAMPLEMODE_S1_P0_5);
    
    CyPins_ClearPin(CH1_CUPSEL0_RLY_P0_3);
    CyPins_ClearPin(CH1_CUPSEL1_RLY_P0_2);
    CyPins_ClearPin(CH2_CUPSEL0_RLY_P0_1);
    CyPins_ClearPin(CH2_CUPSEL1_RLY_P0_0);
    
    CyPins_ClearPin(ATTN_SEL0_P4_1);
    CyPins_ClearPin(ATTN_SEL1_P4_0);
    CyPins_ClearPin(ATTN_SEL2_P12_3);
    CyPins_ClearPin(ATTN_SEL3_P12_2);
    CyPins_ClearPin(FILTER_SEL_P0_4);
	
    CyPins_ClearPin(TRIG_HSYS_SEL0_P6_0);
    CyPins_ClearPin(TRIG_HSYS_SEL1_P6_1); 
    
    CyGlobalIntEnable;
	SPIS_ClearRxBuffer();
    for(;;)
    {
        if(CyPins_ReadPin(SP6_SPI_CSSEL_P1_2)!=0){
          	while(!(SPIS_ReadRxStatus() & SPIS_STS_RX_FIFO_EMPTY)){
	        	m_u8MOSI=SPIS_ReadRxData();       /* Read SPI Data */ 
		        SPIS_ClearRxBuffer();
	        }
            if( (m_u8MOSI & READWRITE)!=0){    //Read
                switch(m_u8MOSI & FUNSELECT){
                    case 0:              //DSO
                       if( (m_u8MOSI & CHNSELECT)==CH1SELECT){//CHANNEL 1
                            if(CyPins_ReadPin(BCH1_CALIB_RLY_P4_5)!=0)
                                m_u8RLStatus[7] = 0x80;
                            else 
                                m_u8RLStatus[7] = 0;
                            if(CyPins_ReadPin(BCH1_DIV0_RLY_P4_7)!=0)
                                m_u8RLStatus[4] = 0x10;
                            else
                                m_u8RLStatus[4] = 0;    
                            if(CyPins_ReadPin(BCH1_DIV1_RLY_P4_6)!=0)    
                                m_u8RLStatus[3] = 0x8;
                            else    
                                m_u8RLStatus[3] = 0;
                            if(CyPins_ReadPin(CH1_CUPSEL0_RLY_P0_3)!=0)
                                m_u8RLStatus[2] = 0x4;
                            else    
                                m_u8RLStatus[2] = 0;
                            if(CyPins_ReadPin(CH1_CUPSEL1_RLY_P0_2)!=0)    
                                m_u8RLStatus[1] = 0x2;
                            else    
                                m_u8RLStatus[1] = 0;
                            if(CyPins_ReadPin(SAMPLEMODE_S0_P0_6)!=0)
                                m_u8RLStatus[0] = 0x1;
                            else
                                m_u8RLStatus[0] = 0;
                        }
                        else if( (m_u8MOSI & CHNSELECT)==CH2SELECT){//CHANNEL 2
                            if(CyPins_ReadPin(BCH2_CALIB_RLY_P4_2)!=0)
                                m_u8RLStatus[7] = 0x80;    
                            else    
                                m_u8RLStatus[7] = 0;        
                            if(CyPins_ReadPin(BCH2_DIV0_RLY_P4_4)!=0)    
                                m_u8RLStatus[4] = 0x10;
                            else    
                                m_u8RLStatus[4] = 0;
                            if(CyPins_ReadPin(BCH2_DIV1_RLY_P4_3)!=0)    
                                m_u8RLStatus[3] = 0x8;
                            else    
                                m_u8RLStatus[3] = 0;
                            if(CyPins_ReadPin(CH2_CUPSEL0_RLY_P0_1)!=0)
                                m_u8RLStatus[2] = 0x4;
                            else    
                                m_u8RLStatus[2] = 0;
                            if(CyPins_ReadPin(CH2_CUPSEL1_RLY_P0_0)!=0)    
                                m_u8RLStatus[1] = 0x2;
                            else    
                                m_u8RLStatus[1] = 0x0;
                            if(CyPins_ReadPin(SAMPLEMODE_S1_P0_5)!=0)
                                m_u8RLStatus[0] = 0x1;
                            else
                                m_u8RLStatus[0] = 0;
                        }
                        else{//EXT CHANNEL
                        
                        }
                         m_u8MISO = m_u8MISO | m_u8RLStatus[7] | m_u8RLStatus[4] | m_u8RLStatus[3] | m_u8RLStatus[2] |m_u8RLStatus[1] | m_u8RLStatus[0];                                
                    break;
                    
                    case 1:              //TRIGGER
                            if(CyPins_ReadPin(TRIG_HSYS_SEL0_P6_0)!=0)
                                m_u8RLStatus[1] =0x2;
                            else    
                                m_u8RLStatus[1] =0;
                            if(CyPins_ReadPin(TRIG_HSYS_SEL1_P6_1)!=0)    
                                m_u8RLStatus[0] =0x1; 
                            else    
                                m_u8RLStatus[0] =0; 
                            m_u8MISO = m_u8MISO | m_u8RLStatus[1] | m_u8RLStatus[0];    
                    break;
                    
                    case 2:              //AWG
                            if(CyPins_ReadPin(FILTER_SEL_P0_4)!=0)
                                m_u8RLStatus[4] =0x10;
                            else    
                                m_u8RLStatus[4] =0;
                            if(CyPins_ReadPin(ATTN_SEL0_P4_1)!=0)    
                                m_u8RLStatus[3] =0x8;
                            else    
                                m_u8RLStatus[3] =0;
                            if(CyPins_ReadPin(ATTN_SEL1_P4_0)!=0)    
                                m_u8RLStatus[2] =0x4;
                            else    
                                m_u8RLStatus[2] =0;
                            if(CyPins_ReadPin(ATTN_SEL2_P12_3)!=0)    
                                m_u8RLStatus[1] =0x2;
                            else
                                m_u8RLStatus[1] =0;
                            if(CyPins_ReadPin(ATTN_SEL3_P12_2)!=0)    
                                m_u8RLStatus[0] =0x1;
                            else    
                                m_u8RLStatus[0] =0;
                            m_u8MISO = m_u8MISO | m_u8RLStatus[4] | m_u8RLStatus[3] | m_u8RLStatus[2] | m_u8RLStatus[1] | m_u8RLStatus[0];        
                    break;
                }
                SPIS_ClearTxBuffer();
				SPIS_WriteTxData(m_u8MISO);
				while(!(SPIS_ReadTxStatus() & SPIS_STS_TX_FIFO_EMPTY));
            }
            else{                           //Write
                switch(m_u8MOSI & FUNSELECT){
                    case 0:              //DSO

                    //CALIBRATION ENABLE/DISABLE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if((m_u8MOSI & CALIBENAB)==ENABLE)
                    {
                        if( (m_u8MOSI & CHNSELECT)==CH1SELECT){//CHANNEL 1
                            CyPins_SetPin(BCH1_CALIB_RLY_P4_5);
                        }
                        else if( (m_u8MOSI & CHNSELECT)==CH2SELECT){//CHANNEL 2
                            CyPins_SetPin(BCH2_CALIB_RLY_P4_2);                        
                        }
                        else{//EXT CHANNEL
                            
                        }
                    }
                    else if((m_u8MOSI & CALIBENAB)==DISABLE){
                        if( (m_u8MOSI & CHNSELECT)==CH1SELECT){//CHANNEL 1
                            CyPins_ClearPin(BCH1_CALIB_RLY_P4_5);                            
                        }
                        else if( (m_u8MOSI & CHNSELECT)==CH2SELECT){//CHANNEL 2
                            CyPins_ClearPin(BCH2_CALIB_RLY_P4_2);                        
                        }
                        else{//EXT CHANNEL
                            
                        }
                    }
                    //CHANNEL SELECT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if( (m_u8MOSI & CHNSELECT)==CH1SELECT){//CHANNEL 1
                            
                    }
                    else if( (m_u8MOSI & CHNSELECT)==CH2SELECT){//CHANNEL 2
                        
                    }
                    else if( (m_u8MOSI & CHNSELECT)==EXTCHNSEL){//EXT CHANNEL
                            
                    }
                    //FRONTEND ATTENUATION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if((m_u8MOSI & FRONTATTN)==DIVBY100){   //DIV BY 100
                        if( (m_u8MOSI & CHNSELECT)==CH1SELECT){//CHANNEL 1
                        	CyPins_ClearPin(BCH1_DIV0_RLY_P4_7);
                            CyPins_ClearPin(BCH1_DIV1_RLY_P4_6);
                        }
                        else if( (m_u8MOSI & CHNSELECT)==CH2SELECT){//CHANNEL 2
                            CyPins_ClearPin(BCH2_DIV0_RLY_P4_4);
                            CyPins_ClearPin(BCH2_DIV1_RLY_P4_3);                            
                        }
                    }
                    else if((m_u8MOSI & FRONTATTN)==DIVBY10){ //DIV BY 10
                        if( (m_u8MOSI & CHNSELECT)==CH1SELECT){//CHANNEL 1
                        	CyPins_ClearPin(BCH1_DIV0_RLY_P4_7);
                            CyPins_SetPin(BCH1_DIV1_RLY_P4_6);
                        }
                        else if( (m_u8MOSI & CHNSELECT)==CH2SELECT){//CHANNEL 2
                            CyPins_ClearPin(BCH2_DIV0_RLY_P4_4);
                            CyPins_SetPin(BCH2_DIV1_RLY_P4_3);                                                        
                        }
                    }
                    else if((m_u8MOSI & FRONTATTN)==DIVBY5){ //DIV BY 5
                        if( (m_u8MOSI & CHNSELECT)==EXTCHNSEL){//EXT CHANNEL
                                
                        }                                    
                    }

                    else if((m_u8MOSI & FRONTATTN)==DIVBY1){    //DIV BY 1
                        if( (m_u8MOSI & CHNSELECT)==CH1SELECT){//CHANNEL 1
                        	CyPins_SetPin(BCH1_DIV0_RLY_P4_7);
                            CyPins_ClearPin(BCH1_DIV1_RLY_P4_6);                           
                        }
                        else if( (m_u8MOSI & CHNSELECT)==CH2SELECT){//CHANNEL 2
                            CyPins_SetPin(BCH2_DIV0_RLY_P4_4);
                            CyPins_ClearPin(BCH2_DIV1_RLY_P4_3);                                                        
                        }
                        else if( (m_u8MOSI & CHNSELECT)==EXTCHNSEL){//EXT CHANNEL
                                
                        }                                    
                    } 
                    //INPUT COUPLING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if((m_u8MOSI & COUPLGSEL)==DCCOUPLING){   //DC Coupling
                        if( (m_u8MOSI & CHNSELECT)==CH1SELECT){//CHANNEL 1
                            CyPins_ClearPin(CH1_CUPSEL0_RLY_P0_3);
                            CyPins_ClearPin(CH1_CUPSEL1_RLY_P0_2);
                        }
                        else if( (m_u8MOSI & CHNSELECT)==CH2SELECT){//CHANNEL 2
                            CyPins_ClearPin(CH2_CUPSEL0_RLY_P0_1);
                            CyPins_ClearPin(CH2_CUPSEL1_RLY_P0_0);
                        }
                    }
                    else if((m_u8MOSI & COUPLGSEL)==ACCOUPLING){ //AC Coupling
                        if( (m_u8MOSI & CHNSELECT)==CH1SELECT){//CHANNEL 1
                            CyPins_ClearPin(CH1_CUPSEL0_RLY_P0_3);
                            CyPins_SetPin(CH1_CUPSEL1_RLY_P0_2);
                        }
                        else if( (m_u8MOSI & CHNSELECT)==CH2SELECT){//CHANNEL 2
                            CyPins_ClearPin(CH2_CUPSEL0_RLY_P0_1);
                            CyPins_SetPin(CH2_CUPSEL1_RLY_P0_0);                            
                        }
                    }
                    //SAMPLING MODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if((m_u8MOSI & SAMPLMODE)==INTERLACED)   //Interlaced Sampling Mode
                    {
                        if( (m_u8MOSI & CHNSELECT)==CH1SELECT){//CHANNEL 1
                            
                        }
                        else if( (m_u8MOSI & CHNSELECT)==CH2SELECT){//CHANNEL 2
                        
                        }
                    }
                    else if((m_u8MOSI & SAMPLMODE)==NORMAL)   {//Normal Sampling Mode
                        if( (m_u8MOSI & CHNSELECT)==CH1SELECT){//CHANNEL 1
                            
                        }
                        else if( (m_u8MOSI & CHNSELECT)==CH2SELECT){//CHANNEL 2
                        
                        }
                    } 
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    break;
                    
                    case 1:             //TRIGGER   
                    //TRIGGER SELECT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if((m_u8MOSI & TRIGGRSEL)!=CH1SELECT){//CHANNEL 1 TRIGGER
                        CyPins_ClearPin(TRIG_HSYS_SEL0_P6_0);
                        CyPins_ClearPin(TRIG_HSYS_SEL1_P6_1); 
                    }
                    else if( (m_u8MOSI & TRIGGRSEL)==CH2SELECT){//CHANNEL 2 TRIGGER
                        CyPins_ClearPin(TRIG_HSYS_SEL0_P6_0);
                        CyPins_SetPin(TRIG_HSYS_SEL1_P6_1);                         
                    }
                    else if( (m_u8MOSI & TRIGGRSEL)==EXTCHNSEL){//EXT CHANNEL  TRIGGER
                        CyPins_SetPin(TRIG_HSYS_SEL0_P6_0);
                        CyPins_ClearPin(TRIG_HSYS_SEL1_P6_1);                             
                    }
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    break;
                    
                    case 2:             //AWG
                    //ATTENUATION SELECT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if( (m_u8MOSI & ATTNSELCT) == ATTN_0DB){
                        CyPins_ClearPin(ATTN_SEL0_P4_1);
                        CyPins_ClearPin(ATTN_SEL1_P4_0);
                        CyPins_ClearPin(ATTN_SEL2_P12_3);
                        CyPins_ClearPin(ATTN_SEL3_P12_2);
                    }
                    else if( (m_u8MOSI & ATTNSELCT) == ATTN_6DB){
                        CyPins_SetPin(ATTN_SEL0_P4_1);
                        CyPins_SetPin(ATTN_SEL1_P4_0);
                        CyPins_ClearPin(ATTN_SEL2_P12_3);
                        CyPins_ClearPin(ATTN_SEL3_P12_2);
                    }
                    else if( (m_u8MOSI & ATTNSELCT) == ATTN_12DB){
                        CyPins_ClearPin(ATTN_SEL0_P4_1);
                        CyPins_SetPin(ATTN_SEL1_P4_0);
                        CyPins_SetPin(ATTN_SEL2_P12_3);
                        CyPins_ClearPin(ATTN_SEL3_P12_2);
                    }
                    else if( (m_u8MOSI & ATTNSELCT) == ATTN_18DB){
                        CyPins_SetPin(ATTN_SEL0_P4_1);
                        CyPins_ClearPin(ATTN_SEL1_P4_0);
                        CyPins_ClearPin(ATTN_SEL2_P12_3);
                        CyPins_SetPin(ATTN_SEL3_P12_2);
                    }
                    else if( (m_u8MOSI & ATTNSELCT) == ATTN_24DB){
                        CyPins_ClearPin(ATTN_SEL0_P4_1);
                        CyPins_ClearPin(ATTN_SEL1_P4_0);
                        CyPins_SetPin(ATTN_SEL2_P12_3);
                        CyPins_SetPin(ATTN_SEL3_P12_2);
                    }
                    else if( (m_u8MOSI & ATTNSELCT) == ATTN_30DB){
                        CyPins_SetPin(ATTN_SEL0_P4_1);
                        CyPins_SetPin(ATTN_SEL1_P4_0);
                        CyPins_SetPin(ATTN_SEL2_P12_3);
                        CyPins_SetPin(ATTN_SEL3_P12_2);                        
                    }
                    //FILTER SELECT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if((m_u8MOSI & FILTERSEL)==BEZZEL){
                        CyPins_ClearPin(FILTER_SEL_P0_4);
                    }
                    else if((m_u8MOSI & FILTERSEL)==ELIPTICAL){
                        CyPins_SetPin(FILTER_SEL_P0_4);
                    }
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    break;
                }
            }
        }
    }
}

/* [] END OF FILE */
