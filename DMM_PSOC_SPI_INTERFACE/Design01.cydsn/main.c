/* ========================================
 *
 * Copyright QMAX TEST EQUIPMENTS, 2014
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 * AUTHOR : RAVIVARMAN.R
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF QMAX TEST EQUIPMENTS.
 * ========================================
*/
#include <device.h>
//Word address
//      #define ADDR_MSB 0x00 
//      #define ADDR_LSB 0x00 
//        #define DATA 0x77 

//Slave address
//      #define SLAVE_ADDR 0x50

//Message is the data which has to be written to EEPROM. 
//First data in this array is Word address
//      uint8 cMessage[] = {ADDR_MSB,ADDR_LSB,DATA};
//      uint8 dummy[] = {ADDR_MSB,ADDR_LSB};
// buffer to save read back data
//      uint8 cRx_Buffer[15]; 

// Length of data to be written including word address
//      uint8 cLength = 0x4; 

//      uint8 cStatus,cIndex,cPosn;
int main()
{
	/* Initializations */
    uint8 m_u8Data=0,m_u8DataPrev=0xf;

	// enable global interrupts
	CYGlobalIntEnable;  
	
	// enable I2C interrupts
//      	I2C_1_EnableInt();  
	
	//Start I2C
//        	I2C_1_Start();  
    
	/* Clear All Relays */
	CyPins_ClearPin(RL1_CTR_P0_2);
	CyPins_ClearPin(RL2_CTR_P0_1);
	CyPins_ClearPin(RL3_CTR_P0_0);
	CyPins_ClearPin(RL4_CTR_P4_1);
	CyPins_ClearPin(RL5_CTR_P4_0);
	CyPins_ClearPin(RL6_CTR_P12_3);
	CyPins_ClearPin(RL7_CTR_P12_2);
			
	/* Set AC & DC Voltage as Default */
	CyPins_SetPin(RL2_CTR_P0_1);
    CyDelay(10);// 10 milli seconds delay
	
    for(;;)
    {
                m_u8Data=0;
                if(CyPins_ReadPin(ISO_DI0_P15_3)!=0)
                    m_u8Data |= 1;
                else
                    m_u8Data |= 0;
                
                if(CyPins_ReadPin(ISO_DI1_P15_2)!=0)
                    m_u8Data |= 1<<1;
                else
                    m_u8Data |= 0<<1;
                
                if(CyPins_ReadPin(ISO_DI2_P3_7)!=0)
                    m_u8Data |= 1<<2;
                else
                    m_u8Data |= 0<<2;
                

                if((m_u8Data != m_u8DataPrev) && (m_u8Data != 0x07) ){
                
                    m_u8DataPrev = m_u8Data;
                    
				switch(m_u8Data)
				{
					case 0x00:									//ACV & DCV Mode
						CyPins_ClearPin(RL1_CTR_P0_2);
						CyPins_ClearPin(RL3_CTR_P0_0);
						CyPins_ClearPin(RL4_CTR_P4_1);
						CyPins_ClearPin(RL5_CTR_P4_0);
						CyPins_ClearPin(RL6_CTR_P12_3);
						CyPins_ClearPin(RL7_CTR_P12_2);
						CyDelay(10);// 10 milli seconds delay
                        CyPins_SetPin(RL2_CTR_P0_1);
                        CyDelay(10);// 10 milli seconds delay
					break;

					case 0x01:									//ACmV & DCmV Mode
						CyPins_ClearPin(RL2_CTR_P0_1);
						CyPins_ClearPin(RL3_CTR_P0_0);
						CyPins_ClearPin(RL4_CTR_P4_1);
						CyPins_ClearPin(RL5_CTR_P4_0);
						CyPins_ClearPin(RL6_CTR_P12_3);
						CyPins_ClearPin(RL7_CTR_P12_2);
						CyDelay(10);// 10 milli seconds delay
                        CyPins_SetPin(RL1_CTR_P0_2);
                        CyDelay(10);// 10 milli seconds delay
					break;
					case 0x02:									//ACI & DCI Mode	-	Amps
						CyPins_ClearPin(RL1_CTR_P0_2);
						CyPins_ClearPin(RL2_CTR_P0_1);
						CyPins_ClearPin(RL3_CTR_P0_0);
						CyPins_ClearPin(RL4_CTR_P4_1);
						CyPins_ClearPin(RL5_CTR_P4_0);
						CyPins_ClearPin(RL7_CTR_P12_2);
						CyDelay(10);// 10 milli seconds delay
                        CyPins_SetPin(RL6_CTR_P12_3);
                        CyDelay(10);// 10 milli seconds delay
					break;
					case 0x03:									//ACI & DCI Mode	-	mA
						CyPins_ClearPin(RL1_CTR_P0_2);
						CyPins_ClearPin(RL2_CTR_P0_1);
						CyPins_ClearPin(RL3_CTR_P0_0);
						CyPins_ClearPin(RL4_CTR_P4_1);
						CyPins_ClearPin(RL6_CTR_P12_3);
						CyPins_ClearPin(RL7_CTR_P12_2);
						CyDelay(10);// 10 milli seconds delay
                        CyPins_SetPin(RL5_CTR_P4_0);
                        CyDelay(10);// 10 milli seconds delay
					break;
					case 0x04:									//ACI & DCI Mode	-	uA
						CyPins_ClearPin(RL1_CTR_P0_2);
						CyPins_ClearPin(RL2_CTR_P0_1);
						CyPins_ClearPin(RL3_CTR_P0_0);
						CyPins_ClearPin(RL5_CTR_P4_0);
						CyPins_ClearPin(RL6_CTR_P12_3);
						CyPins_ClearPin(RL7_CTR_P12_2);
						CyDelay(10);// 10 milli seconds delay
                        CyPins_SetPin(RL4_CTR_P4_1);
                        CyDelay(10);// 10 milli seconds delay
					break;
					case 0x05:									//Resistor,Continuity,Diode&Capacitor
						CyPins_ClearPin(RL2_CTR_P0_1);
						CyPins_ClearPin(RL3_CTR_P0_0);
						CyPins_ClearPin(RL4_CTR_P4_1);
						CyPins_ClearPin(RL5_CTR_P4_0);
						CyPins_ClearPin(RL6_CTR_P12_3);
						CyPins_ClearPin(RL7_CTR_P12_2);
						CyDelay(10);// 10 milli seconds delay
                        CyPins_SetPin(RL1_CTR_P0_2);
                        CyDelay(10);// 10 milli seconds delay
					break;
					case 0x06:									//Frequency
						CyPins_ClearPin(RL2_CTR_P0_1);
						CyPins_ClearPin(RL4_CTR_P4_1);
						CyPins_ClearPin(RL5_CTR_P4_0);
						CyPins_ClearPin(RL6_CTR_P12_3);
						CyPins_ClearPin(RL7_CTR_P12_2);
                        
                        CyDelay(10);// 10 milli seconds delay
                        CyPins_SetPin(RL3_CTR_P0_0);
						CyDelay(10);// 10 milli seconds delay
                        CyPins_SetPin(RL1_CTR_P0_2);
                        CyDelay(10);// 10 milli seconds delay
					break;
					case 0x07:
                        CyPins_ClearPin(RL1_CTR_P0_2);
                        CyPins_ClearPin(RL2_CTR_P0_1);
						CyPins_SetPin(RL3_CTR_P0_0);
						CyPins_ClearPin(RL4_CTR_P4_1);
						CyPins_ClearPin(RL5_CTR_P4_0);
						CyPins_ClearPin(RL6_CTR_P12_3);
						                        
						CyDelay(10);// 10 milli seconds delay
                        CyPins_SetPin(RL7_CTR_P12_2);
                        CyDelay(10);// 10 milli seconds delay
						break;
				}
               }
                else if(m_u8Data == 0x07 && m_u8DataPrev==0x05){
                        m_u8DataPrev = m_u8Data;
                    
                        CyPins_ClearPin(RL2_CTR_P0_1);
						CyPins_ClearPin(RL3_CTR_P0_0);
						CyPins_ClearPin(RL4_CTR_P4_1);
						CyPins_ClearPin(RL5_CTR_P4_0);
						CyPins_ClearPin(RL6_CTR_P12_3);
					
                        CyPins_SetPin(RL7_CTR_P12_2);
                        CyDelay(10);// 10 milli seconds delay
                }
            }
//~~~~~~~~~~~~~~~~~~~~~I2C MEMORY~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                    
//                    I2C_1_MasterClearStatus(); /* Clear any previous status */
                    
                    //Following API writes the data from PSoC3 RAM buffer to EEPROM
		            //SLAVE_ADDR is the slave address in this API
            		//cMessage is the pointer to array which contains the data to be written to EEPROM.
		            //cLength is the number of bytes which have to be written to EEPROM
		            //I2C_MODE_COMPLETE_XFER, is to send data completly before sending stop command.
		            //The macro definition for 1) I2C_MODE_REPEAT_START = 0x01
                    //                         2) I2C_MODE_COMPLETE_XFER = 0x00
                    //                         3) I2C_MODE_NO_STOP = 0x02.
		            //I2C_1_MasterWriteBuf(SLAVE_ADDR, cMessage, 3, I2C_1_MODE_COMPLETE_XFER);
                    
                    //wait until Transfer is complete
		            //while((I2C_1_MasterStatus() & I2C_1_MSTAT_WR_CMPLT )==0);
                    
                    // delay to complete the write operation(twr)
		            //CyDelay(10);
                    
                    //write a dummy byte to initialize the address word counter of 
		            //eeprom to start address for read back operation. First location 
		            //of cMessage array has word address.
		
//		            I2C_1_MasterWriteBuf(SLAVE_ADDR, dummy, 2, I2C_1_MODE_COMPLETE_XFER);
		
		            //wait until Transfer is complete
//		            while((I2C_1_MasterStatus() & I2C_1_MSTAT_WR_CMPLT )==0);
		
		            //Delay for setting address in EEPROM
//		            CyDelayUs(1);
		
		            //Read the 16 bytes from slave, staring from word address specified by iMessage
		            //SLAVE_ADDR is the slave address in this API
		            //cRx_Buffer is the pointer to array where data has to be stored after reading from EEPROM.
		            //cLength-1 is the number of bytes which have to be read from EEPROM
		            //I2C_MODE_COMPLETE_XFER, is to read data completly before sending stop command.
		
//		            I2C_1_MasterReadBuf(SLAVE_ADDR, cRx_Buffer,1, I2C_1_MODE_COMPLETE_XFER );
				
		            //wait until Transfer is complete
//		            while((I2C_1_MasterStatus() & I2C_1_MSTAT_RD_CMPLT )==0); */
                

     	}

/* [] END OF FILE */
