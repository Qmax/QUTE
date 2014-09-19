/*******************************************************************************
* File Name: SPIS_2.c
* Version 2.20
*
* Description:
*  This file provides all API functionality of the SPI Slave component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "SPIS_2.h"

#if (SPIS_2_TXBUFFERSIZE > 4u)

    volatile uint8 SPIS_2_TXBUFFER[SPIS_2_TXBUFFERSIZE] = {0u};
    volatile uint8 SPIS_2_txBufferRead = 0u;
    volatile uint8 SPIS_2_txBufferWrite = 0u;
    volatile uint8 SPIS_2_txBufferFull = 0u;

#endif /* SPIS_2_TXBUFFERSIZE > 4u */

#if (SPIS_2_RXBUFFERSIZE > 4u)

    volatile uint8 SPIS_2_RXBUFFER[SPIS_2_RXBUFFERSIZE] = {0u};
    volatile uint8 SPIS_2_rxBufferRead = 0u;
    volatile uint8 SPIS_2_rxBufferWrite = 0u;
    volatile uint8 SPIS_2_rxBufferFull = 0u;

#endif /* SPIS_2_RXBUFFERSIZE > 4u */

uint8 SPIS_2_initVar = 0u;

extern volatile uint8 SPIS_2_swStatusTx;
extern volatile uint8 SPIS_2_swStatusRx;


/*******************************************************************************
* Function Name: SPIS_2_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default SPIS configuration provided with customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  When this function is called it initializes all of the necessary parameters
*  for execution. i.e. setting the initial interrupt mask, configuring the
*  interrupt service routine, configuring the bit-counter parameters and
*  clearing the FIFO and Status Register.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_2_Init(void)
{
    /*Initialize the Bit counter */
    SPIS_2_COUNTER_PERIOD_REG = SPIS_2_BITCTR_INIT;

    /* ISR initialization */
    #if(SPIS_2_InternalTxInterruptEnabled)

        CyIntDisable(SPIS_2_TX_ISR_NUMBER);

        /* Set the ISR to point to the SPIS_2_isr Interrupt. */
        CyIntSetVector(SPIS_2_TX_ISR_NUMBER, SPIS_2_TX_ISR);

        /* Set the priority. */
        CyIntSetPriority(SPIS_2_TX_ISR_NUMBER, SPIS_2_TX_ISR_PRIORITY);

    #endif /* SPIS_2_InternalTxInterruptEnabled */

    #if(SPIS_2_InternalRxInterruptEnabled)

        CyIntDisable(SPIS_2_RX_ISR_NUMBER);

        /* Set the ISR to point to the SPIS_2_isr Interrupt. */
        CyIntSetVector(SPIS_2_RX_ISR_NUMBER, SPIS_2_RX_ISR);

        /* Set the priority. */
        CyIntSetPriority(SPIS_2_RX_ISR_NUMBER, SPIS_2_RX_ISR_PRIORITY);

    #endif /* SPIS_2_InternalRxInterruptEnabled */

    /* Clear any stray data from the RX and TX FIFO */
    SPIS_2_ClearFIFO();

    #if(SPIS_2_RXBUFFERSIZE > 4u)

        SPIS_2_rxBufferRead = 0u;
        SPIS_2_rxBufferWrite = 0u;

    #endif /* SPIS_2_RXBUFFERSIZE > 4u */

    #if(SPIS_2_TXBUFFERSIZE > 4u)

        SPIS_2_txBufferRead = 0u;
        SPIS_2_txBufferWrite = 0u;

    #endif /* SPIS_2_TXBUFFERSIZE > 4u */

    (void) SPIS_2_ReadTxStatus(); /* Clear any pending status bits */
    (void) SPIS_2_ReadRxStatus(); /* Clear any pending status bits */


    /* Configure the Initial interrupt mask */
    #if (SPIS_2_TXBUFFERSIZE > 4u)
        SPIS_2_TX_STATUS_MASK_REG  = SPIS_2_TX_INIT_INTERRUPTS_MASK &
                                                ~SPIS_2_STS_TX_FIFO_NOT_FULL;
    #else /* SPIS_2_TXBUFFERSIZE < 4u */
        SPIS_2_TX_STATUS_MASK_REG  = SPIS_2_TX_INIT_INTERRUPTS_MASK;
    #endif /* SPIS_2_TXBUFFERSIZE > 4u */

    SPIS_2_RX_STATUS_MASK_REG  = SPIS_2_RX_INIT_INTERRUPTS_MASK;

}


/*******************************************************************************
* Function Name: SPIS_2_Enable
********************************************************************************
*
* Summary:
*  Enable SPIS component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIS_2_Enable(void) 
{
    uint8 enableInterrupts = 0u;

    enableInterrupts = CyEnterCriticalSection();

    SPIS_2_COUNTER_CONTROL_REG |= SPIS_2_CNTR_ENABLE;
    SPIS_2_TX_STATUS_ACTL_REG |= SPIS_2_INT_ENABLE;
    SPIS_2_RX_STATUS_ACTL_REG |= SPIS_2_INT_ENABLE;

    CyExitCriticalSection(enableInterrupts);

    #if(SPIS_2_InternalTxInterruptEnabled)
        CyIntEnable(SPIS_2_TX_ISR_NUMBER);
    #endif /* SPIS_2_InternalTxInterruptEnabled */

    #if(SPIS_2_InternalRxInterruptEnabled)
        CyIntEnable(SPIS_2_RX_ISR_NUMBER);
    #endif /* SPIS_2_InternalRxInterruptEnabled */
}


/*******************************************************************************
* Function Name: SPIS_2_Start
********************************************************************************
*
* Summary:
*  Initialize and Enable the SPI Slave component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIS_2_initVar - used to check initial configuration, modified on
*  first function call.
*
* Theory:
*  Enable the clock input to enable operation.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_2_Start(void)
{
    if(SPIS_2_initVar == 0u)
    {
        SPIS_2_Init();
        SPIS_2_initVar = 1u;
    }

    SPIS_2_Enable();
}


/*******************************************************************************
* Function Name: SPIS_2_Stop
********************************************************************************
*
* Summary:
*  Disable the SPI Slave component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal interrupt if one is used.
*
*******************************************************************************/
void SPIS_2_Stop(void) 
{
    uint8 enableInterrupts = 0u;

    enableInterrupts = CyEnterCriticalSection();

    SPIS_2_TX_STATUS_ACTL_REG &= ~SPIS_2_INT_ENABLE;
    SPIS_2_RX_STATUS_ACTL_REG &= ~SPIS_2_INT_ENABLE;

    CyExitCriticalSection(enableInterrupts);

    #if(SPIS_2_InternalTxInterruptEnabled)
        CyIntDisable(SPIS_2_TX_ISR_NUMBER);
    #endif /* SPIS_2_InternalTxInterruptEnabled */

    #if(SPIS_2_InternalRxInterruptEnabled)
        CyIntDisable(SPIS_2_RX_ISR_NUMBER);
    #endif /* SPIS_2_InternalRxInterruptEnabled */
}


/*******************************************************************************
* Function Name: SPIS_2_EnableTxInt
********************************************************************************
*
* Summary:
*  Enable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIS_2_EnableTxInt(void) 
{
    #if(SPIS_2_InternalTxInterruptEnabled)
        CyIntEnable(SPIS_2_TX_ISR_NUMBER);
    #endif /* SPIS_2_InternalTxInterruptEnabled */
}


/*******************************************************************************
* Function Name: SPIS_2_EnableRxInt
********************************************************************************
*
* Summary:
*  Enable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIS_2_EnableRxInt(void) 
{
    #if(SPIS_2_InternalRxInterruptEnabled)
        CyIntEnable(SPIS_2_RX_ISR_NUMBER);
    #endif /* SPIS_2_InternalRxInterruptEnabled */
}


/*******************************************************************************
* Function Name: SPIS_2_DisableTxInt
********************************************************************************
*
* Summary:
*  Disable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIS_2_DisableTxInt(void) 
{
    #if(SPIS_2_InternalTxInterruptEnabled)
        CyIntDisable(SPIS_2_TX_ISR_NUMBER);
    #endif /* SPIS_2_InternalTxInterruptEnabled */
}


/*******************************************************************************
* Function Name: SPIS_2_DisableRxInt
********************************************************************************
*
* Summary:
*  Disable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIS_2_DisableRxInt(void) 
{
    #if(SPIS_2_InternalRxInterruptEnabled)
        CyIntDisable(SPIS_2_RX_ISR_NUMBER);
    #endif /* SPIS_2_InternalRxInterruptEnabled */
}


/*******************************************************************************
* Function Name: SPIS_2_SetTxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPIS_2_SetTxInterruptMode(uint8 intSrc) 
{
    SPIS_2_TX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: SPIS_2_SetRxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPIS_2_SetRxInterruptMode(uint8 intSrc) 
{
    SPIS_2_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: SPIS_2_ReadTxStatus
********************************************************************************
*
* Summary:
*  Read the Tx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Tx status register.
*
* Global variables:
*  SPIS_2_swStatusTx - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Tx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPIS_2_ReadTxStatus(void)
{
    uint8 tmpStatus = 0u;

    #if (SPIS_2_TXBUFFERSIZE > 4u)

        SPIS_2_DisableTxInt();

        tmpStatus = SPIS_2_GET_STATUS_TX(SPIS_2_swStatusTx);

        SPIS_2_swStatusTx = 0u;

        /* Enable Interrupts */
        SPIS_2_EnableTxInt();

    #else /* (SPIS_2_TXBUFFERSIZE < 4u) */

        tmpStatus = SPIS_2_TX_STATUS_REG;

    #endif /* (SPIS_2_TXBUFFERSIZE > 4u) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPIS_2_ReadRxStatus
********************************************************************************
*
* Summary:
*  Read the Rx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Rx status register.
*
* Global variables:
*  SPIS_2_swStatusRx - used to store in software Rx status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Rx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Rx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPIS_2_ReadRxStatus(void)
{
    uint8 tmpStatus = 0u;

    #if (SPIS_2_RXBUFFERSIZE > 4u)

        SPIS_2_DisableRxInt();

        tmpStatus = SPIS_2_GET_STATUS_RX(SPIS_2_swStatusRx);

        SPIS_2_swStatusRx = 0u;

        /* Enable Interrupts */
        SPIS_2_EnableRxInt();

    #else /* (SPIS_2_RXBUFFERSIZE < 4u) */

        tmpStatus = SPIS_2_RX_STATUS_REG;

    #endif /* (SPIS_2_RXBUFFERSIZE > 4u) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPIS_2_WriteTxData
********************************************************************************
*
* Summary:
*  Write a byte of data to be sent across the SPI.
*
* Parameters:
*  txDataByte: The data value to send across the SPI.
*
* Return:
*  None.
*
* Global variables:
*  SPIS_2_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call if TX Software Buffer is used.
*  SPIS_2_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*  SPIS_2_TXBUFFER[SPIS_2_TXBUFFERSIZE] - used to store
*  data to sending, modified every function call if TX Software Buffer is used.
*
* Theory:
*  Allows the user to transmit any byte of data in a single transfer.
*
* Side Effects:
*  If this function is called again before the previous byte is finished then
*  the next byte will be appended to the transfer with no time between
*  the byte transfers. Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_2_WriteTxData(uint8 txData)
{
    #if(SPIS_2_TXBUFFERSIZE > 4u)

        int16 tmpTxBufferRead = 0u;

        /* Block if buffer is full, so we don't overwrite. */
        do
        {
            tmpTxBufferRead = SPIS_2_txBufferRead - 1u;
            if (tmpTxBufferRead < 0u)
            {
                tmpTxBufferRead = SPIS_2_TXBUFFERSIZE - 1u;
            }
        } while(tmpTxBufferRead == SPIS_2_txBufferWrite);

        /* Disable Interrupt to protect variables that could change on interrupt. */
        SPIS_2_DisableTxInt();

        SPIS_2_swStatusTx = SPIS_2_GET_STATUS_TX(SPIS_2_swStatusTx);

        if((SPIS_2_txBufferRead == SPIS_2_txBufferWrite) &&
            ((SPIS_2_swStatusTx & SPIS_2_STS_TX_FIFO_NOT_FULL) != 0u))
        {
            /* Add directly to the FIFO. */
            CY_SET_REG8(SPIS_2_TXDATA_PTR, txData);
        }
        else
        {
            /* Add to the software buffer. */
            SPIS_2_txBufferWrite++;
            if(SPIS_2_txBufferWrite >= SPIS_2_TXBUFFERSIZE)
            {
                SPIS_2_txBufferWrite = 0u;
            }
               
            if(SPIS_2_txBufferWrite == SPIS_2_txBufferRead)
            {
                SPIS_2_txBufferRead++;
                if(SPIS_2_txBufferRead >= SPIS_2_RXBUFFERSIZE)
                {
                    SPIS_2_txBufferRead = 0u;
                }
                SPIS_2_txBufferFull = 1u;
            }

            SPIS_2_TXBUFFER[SPIS_2_txBufferWrite] = txData;
            
            SPIS_2_TX_STATUS_MASK_REG |= SPIS_2_STS_TX_FIFO_NOT_FULL;
        }                  
               
        /* Enable Interrupt. */
        SPIS_2_EnableTxInt();

    #else /* SPIS_2_TXBUFFERSIZE <= 4u */

        /* Block while FIFO is full */
        while((SPIS_2_TX_STATUS_REG & SPIS_2_STS_TX_FIFO_NOT_FULL) == 0u);

        /* Then write the byte */
        CY_SET_REG8(SPIS_2_TXDATA_PTR, txData);

    #endif /* SPIS_2_TXBUFFERSIZE > 4u */
}

#if(SPIS_2_ModeUseZero == 1u)

    /*******************************************************************************
    * Function Name: SPIS_2_WriteTxDataZero
    ********************************************************************************
    *
    * Summary:
    *  Write a byte zero of data to be sent across the SPI. This must be used in
    *  Mode 00 and 01 if the FIFO is empty and data is not being sent.
    *
    * Parameters:
    *  txDataByte: The data value to send across the SPI.
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Allows the user to transmit any byte of data in a single transfer. Clear
    *  status register of the component.
    *
    *******************************************************************************/
    void SPIS_2_WriteTxDataZero(uint8 txDataByte)
                                        
    {
        CY_SET_REG8(SPIS_2_TXDATA_ZERO_PTR, txDataByte);
    }

#endif /* (SPIS_2_ModeUseZero == 1u) */


/*******************************************************************************
* Function Name: SPIS_2_ReadRxData
********************************************************************************
*
* Summary:
*  Read the next byte of data received across the SPI.
*
* Parameters:
*  None.
*
* Return:
*  The next byte of data read from the FIFO.
*
* Global variables:
*  SPIS_2_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPIS_2_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function
*  call if RX Software Buffer is used.
*  SPIS_2_RXBUFFER[SPIS_2_RXBUFFERSIZE] - used to store
*  received data.
*
* Theory:
*  Allows the user to read a byte of data received.
*
* Side Effects:
*  Will return invalid data if the FIFO is empty.  User should poll for FIFO
*  empty status before calling Read function.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPIS_2_ReadRxData(void)
{
    uint8 rxData = 0u;

    #if(SPIS_2_RXBUFFERSIZE > 4u)

        /* Disable Interrupt to protect variables that could change on interrupt. */
        SPIS_2_DisableRxInt();

        if(SPIS_2_rxBufferRead != SPIS_2_rxBufferWrite)
        {
            if(SPIS_2_rxBufferFull == 0u)
            {
                SPIS_2_rxBufferRead++;
                if(SPIS_2_rxBufferRead >= SPIS_2_RXBUFFERSIZE)
                {
                    SPIS_2_rxBufferRead = 0u;
                }
            }
            else
            {
                SPIS_2_rxBufferFull = 0u;
            }
        }

        rxData = SPIS_2_RXBUFFER[SPIS_2_rxBufferRead];

        /* Enable Interrupt. */
        SPIS_2_EnableRxInt();

    #else /* SPIS_2_RXBUFFERSIZE <= 4u */

        rxData = CY_GET_REG8(SPIS_2_RXDATA_PTR);

    #endif /* SPIS_2_RXBUFFERSIZE > 4u */

    return (rxData);

}


/*******************************************************************************
* Function Name: SPIS_2_GetRxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the RX buffer.
*  If RX Software Buffer not used then function return 0 if FIFO empty or 1 if
*  FIFO not empty. In another case function return size of RX Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the RX buffer.
*
* Global variables:
*  SPIS_2_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPIS_2_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer.
*
* Theory:
*  Allows the user to find out how full the RX Buffer is.
*
*******************************************************************************/
uint8 SPIS_2_GetRxBufferSize(void) 
{
    uint8 size = 0u;

    #if(SPIS_2_RXBUFFERSIZE > 4u)

        /* Disable Interrupt to protect variables that could change on interrupt. */
        SPIS_2_DisableRxInt();

        if(SPIS_2_rxBufferRead == SPIS_2_rxBufferWrite)
        {
            size = 0u; /* No data in RX buffer */
        }
        else if(SPIS_2_rxBufferRead < SPIS_2_rxBufferWrite)
        {
            size = (SPIS_2_rxBufferWrite - SPIS_2_rxBufferRead);
        }
        else
        {
            size = (SPIS_2_RXBUFFERSIZE - SPIS_2_rxBufferRead) + SPIS_2_rxBufferWrite;
        }

        /* Enable interrupt. */
        SPIS_2_EnableRxInt();

    #else /* SPIS_2_RXBUFFERSIZE > 4u */

        /* We can only know if there is data in the fifo. */
        size = ((SPIS_2_RX_STATUS_REG & SPIS_2_STS_RX_FIFO_NOT_EMPTY) == 
                 SPIS_2_STS_RX_FIFO_NOT_EMPTY) ? 1u : 0u;

    #endif /* SPIS_2_RXBUFFERSIZE > 4u */

    return (size);
}


/*******************************************************************************
* Function Name: SPIS_2_GetTxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the TX buffer.
*  If TX Software Buffer not used then function return 0 - if FIFO empty, 1 - if
*  FIFO not full, 4 - if FIFO full. In another case function return size of TX
*  Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the TX buffer.
*
* Global variables:
*  SPIS_2_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIS_2_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*
* Theory:
*  Allows the user to find out how full the TX Buffer is.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8  SPIS_2_GetTxBufferSize(void) 
{
    uint8 size = 0u;

    #if(SPIS_2_TXBUFFERSIZE > 4u)

        /* Disable Interrupt to protect variables that could change on interrupt. */
        SPIS_2_DisableTxInt();

        if(SPIS_2_txBufferRead == SPIS_2_txBufferWrite)
        {
            size = 0u;
        }
        else if(SPIS_2_txBufferRead < SPIS_2_txBufferWrite)
        {
            size = (SPIS_2_txBufferWrite - SPIS_2_txBufferRead);
        }
        else
        {
            size = (SPIS_2_TXBUFFERSIZE - SPIS_2_txBufferRead) + SPIS_2_txBufferWrite;
        }

        /* Enable Interrupt. */
        SPIS_2_EnableTxInt();

    #else /* SPIS_2_TXBUFFERSIZE <= 4u */

        size = SPIS_2_TX_STATUS_REG;

        /* Is the fifo is full. */
        if((size & SPIS_2_STS_TX_FIFO_EMPTY) == SPIS_2_STS_TX_FIFO_EMPTY)
        {
            size = 0u;
        }
        else if((size & SPIS_2_STS_TX_FIFO_NOT_FULL) == SPIS_2_STS_TX_FIFO_NOT_FULL)
        {
            size = 1u;
        }
        else
        {
            size = 4u;
        }

    #endif /* SPIS_2_TXBUFFERSIZE > 4u */

    return (size);
}


/*******************************************************************************
* Function Name: SPIS_2_ClearRxBuffer
********************************************************************************
*
* Summary:
*  Clear the RX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIS_2_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer, modified every function
*  call - resets to zero.
*  SPIS_2_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any received data not read from the RAM buffer will be lost when overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_2_ClearRxBuffer(void)
{
    /* Clear Hardware RX FIFO */
    while((!(SPIS_2_RX_STATUS_REG & SPIS_2_STS_RX_FIFO_NOT_EMPTY)) == 0u)
    {
        CY_GET_REG8(SPIS_2_RXDATA_PTR);
    }

    #if(SPIS_2_RXBUFFERSIZE > 4u)

        /* Disable interrupt to protect variables that could change on interrupt. */
        SPIS_2_DisableRxInt();

        SPIS_2_rxBufferRead = 0u;
        SPIS_2_rxBufferWrite = 0u;

        /* Enable interrupt. */
        SPIS_2_EnableRxInt();

    #endif /* SPIS_2_RXBUFFERSIZE > 4u */
}


/*******************************************************************************
* Function Name: SPIS_2_ClearTxBuffer
********************************************************************************
*
* Summary:
*  Clear the TX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIS_2_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call - resets to zero.
*  SPIS_2_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any data not yet transmitted from the RAM buffer will be lost when
*  overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_2_ClearTxBuffer(void)
{
    uint8 enableInterrupts = 0u;

    /* Clear Hardware TX FIFO */
    enableInterrupts = CyEnterCriticalSection();

    #if(SPIS_2_DataWidth <= 8u)

        /* Clear TX FIFO */
        SPIS_2_TX_AUX_CONTROL_DP0_REG |= SPIS_2_FIFO_CLR;
        SPIS_2_TX_AUX_CONTROL_DP0_REG &= ~SPIS_2_FIFO_CLR;

    #else

        /* Clear TX FIFO */
        SPIS_2_TX_AUX_CONTROL_DP0_REG |= SPIS_2_FIFO_CLR;
        SPIS_2_TX_AUX_CONTROL_DP0_REG &= ~SPIS_2_FIFO_CLR;
        SPIS_2_TX_AUX_CONTROL_DP1_REG |= SPIS_2_FIFO_CLR;
        SPIS_2_TX_AUX_CONTROL_DP1_REG &= ~SPIS_2_FIFO_CLR;

    #endif /* SPIS_2_DataWidth > 8u */

    CyExitCriticalSection(enableInterrupts);

    #if(SPIS_2_TXBUFFERSIZE > 4u)

        /* Disable Interrupt to protect variables that could change on interrupt. */
        SPIS_2_DisableTxInt();

        SPIS_2_txBufferRead = 0u;
        SPIS_2_txBufferWrite = 0u;

        /* If Buffer is empty then disable TX FIFO status interrupt */
        SPIS_2_TX_STATUS_MASK_REG &= ~SPIS_2_STS_TX_FIFO_NOT_FULL;

        /* Enable Interrupt. */
        SPIS_2_EnableTxInt();

    #endif /* SPIS_2_TXBUFFERSIZE > 4u */
}


#if (SPIS_2_BidirectionalMode == 1u)

    /*******************************************************************************
    * Function Name: SPIS_2_TxEnable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI Slave is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to transmit.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SPIS_2_TxEnable(void) 
    {
            SPIS_2_CONTROL_REG |= SPIS_2_CTRL_TX_SIGNAL_EN;
    }


    /*******************************************************************************
    * Function Name: SPIS_2_TxDisable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI Slave is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to receive.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SPIS_2_TxDisable(void) 
    {
            SPIS_2_CONTROL_REG &= ~SPIS_2_CTRL_TX_SIGNAL_EN;
    }

#endif /* SPIS_2_BidirectionalMode == 1u */


/*******************************************************************************
* Function Name: SPIS_2_PutArray
********************************************************************************
*
* Summary:
*  Write available data from RAM/ROM to the TX buffer while space is available
*  in the TX buffer. Keep trying until all data is passed to the TX buffer. If
*  used Mode 00 or 01 before PutArray() function should be called
*  WriteTxDataZero() function.
*
* Parameters:
*  *buffer: Pointer to the location in RAM containing the data to send
*  byteCount: The number of bytes to move to the transmit buffer.
*
* Return:
*  None.
*
* Side Effects:
*  Will stay in this routine until all data has been sent.  May get locked in
*  this loop if data is not being initiated by the master if there is not
*  enough room in the TX FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_2_PutArray(uint8 *buffer, uint8 byteCount)
{
    while(byteCount > 0u)
    {
        SPIS_2_WriteTxData(*buffer++);
        byteCount--;
    }
}


/*******************************************************************************
* Function Name: SPIS_2_ClearFIFO
********************************************************************************
*
* Summary:
*  Clear the RX and TX FIFO's of all data for a fresh start.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
void SPIS_2_ClearFIFO(void) 
{
    uint8 enableInterrupts = 0u;

    while((!(SPIS_2_RX_STATUS_REG & SPIS_2_STS_RX_FIFO_NOT_EMPTY)) == 0u)
    {
        CY_GET_REG8(SPIS_2_RXDATA_PTR);
    }

    enableInterrupts = CyEnterCriticalSection();

    #if(SPIS_2_DataWidth <= 8u)

        /* Clear TX FIFO */
        SPIS_2_TX_AUX_CONTROL_DP0_REG |= SPIS_2_FIFO_CLR;
        SPIS_2_TX_AUX_CONTROL_DP0_REG &= ~SPIS_2_FIFO_CLR;

    #else

        /* Clear TX FIFO */
        SPIS_2_TX_AUX_CONTROL_DP0_REG |= SPIS_2_FIFO_CLR;
        SPIS_2_TX_AUX_CONTROL_DP0_REG &= ~SPIS_2_FIFO_CLR;
        SPIS_2_TX_AUX_CONTROL_DP1_REG |= SPIS_2_FIFO_CLR;
        SPIS_2_TX_AUX_CONTROL_DP1_REG &= ~SPIS_2_FIFO_CLR;

    #endif /* SPIS_2_DataWidth > 8u */

    CyExitCriticalSection(enableInterrupts);
}


/* Following functions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects.
*/

/*******************************************************************************
* Function Name: SPIS_2_EnableInt
********************************************************************************
*
* Summary:
*  Enable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIS_2_EnableInt(void) 
{
    #if(SPIS_2_InternalTxInterruptEnabled)    
        CyIntEnable(SPIS_2_TX_ISR_NUMBER);
    #endif /* SPIS_2_InternalTxInterruptEnabled */                                
    
    #if(SPIS_2_InternalRxInterruptEnabled)           
        CyIntEnable(SPIS_2_RX_ISR_NUMBER);
    #endif /* SPIS_2_InternalRxInterruptEnabled */
}


/*******************************************************************************
* Function Name: SPIS_2_DisableInt
********************************************************************************
*
* Summary:
*  Disable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIS_2_DisableInt(void) 
{
    #if(SPIS_2_InternalTxInterruptEnabled)    
        CyIntDisable(SPIS_2_TX_ISR_NUMBER);
    #endif /* SPIS_2_InternalTxInterruptEnabled */
    
    #if(SPIS_2_InternalRxInterruptEnabled)           
        CyIntDisable(SPIS_2_RX_ISR_NUMBER);
    #endif /* SPIS_2_InternalRxInterruptEnabled */
}


/*******************************************************************************
* Function Name: SPIS_2_SetInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPIS_2_SetInterruptMode(uint8 intSrc) 
{
    SPIS_2_TX_STATUS_MASK_REG  = intSrc;
    SPIS_2_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: SPIS_2_ReadStatus
********************************************************************************
*
* Summary:
*  Read the status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the status register.
*
* Global variables:
*  SPIS_2_swStatus - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the status register for error detection
*  and flow control.
*
* Side Effects:
*  Clear status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPIS_2_ReadStatus(void)
{
    uint8 tmpStatus;

    #if ((SPIS_2_TXBUFFERSIZE > 4u) || (SPIS_2_RXBUFFERSIZE > 4u))

        SPIS_2_DisableInt();

        tmpStatus = SPIS_2_GET_STATUS_TX(SPIS_2_swStatusTx) |
                    (SPIS_2_GET_STATUS_RX(SPIS_2_swStatusRx) & ~SPIS_2_STS_RX_FIFO_FULL);

        SPIS_2_swStatusTx = 0u;
        SPIS_2_swStatusRx = 0u;

        /* Enable Interrupts */
        SPIS_2_EnableInt();

    #else /* (SPIS_2_TXBUFFERSIZE < 4u) && (SPIS_2_RXBUFFERSIZE < 4u) */

        tmpStatus = SPIS_2_TX_STATUS_REG | (SPIS_2_RX_STATUS_REG &
                                                      ~SPIS_2_STS_RX_FIFO_FULL);

    #endif /* (SPIS_2_TXBUFFERSIZE > 4u) || (SPIS_2_RXBUFFERSIZE > 4u) */

    return(tmpStatus);
}


/* [] END OF FILE */
