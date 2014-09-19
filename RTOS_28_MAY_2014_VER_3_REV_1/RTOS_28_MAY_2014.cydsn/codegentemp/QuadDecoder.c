/*******************************************************************************
* File Name: QuadDecoder.c  
* Version 2.30
*
* Description:
*  This file provides the source code to the API for the Quadrature Decoder
*  component.
*
* Note:
*  None.
*   
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "QuadDecoder.h"

#if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT)
    #include "QuadDecoder_PVT.h"
#endif /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT */

uint8 QuadDecoder_initVar = 0u;


/*******************************************************************************
* Function Name: QuadDecoder_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default QuadDec configuration provided with customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDecoder_Init(void) 
{
    #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT)
        /* Disable Interrupt. */
        CyIntDisable(QuadDecoder_ISR_NUMBER);
        /* Set the ISR to point to the QuadDecoder_isr Interrupt. */
        (void) CyIntSetVector(QuadDecoder_ISR_NUMBER, & QuadDecoder_ISR);
        /* Set the priority. */
        CyIntSetPriority(QuadDecoder_ISR_NUMBER, QuadDecoder_ISR_PRIORITY);
    #endif /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT */
}


/*******************************************************************************
* Function Name: QuadDecoder_Enable
********************************************************************************
*
* Summary:
*  This function enable interrupts from Component and also enable Component's
*  ISR in case of 32-bit counter.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDecoder_Enable(void) 
{
    uint8 enableInterrupts;

    QuadDecoder_SetInterruptMask(QuadDecoder_INIT_INT_MASK);

    enableInterrupts = CyEnterCriticalSection();

    /* Enable interrupts from Statusi register */
    QuadDecoder_SR_AUX_CONTROL |= QuadDecoder_INTERRUPTS_ENABLE;

    CyExitCriticalSection(enableInterrupts);

    #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT)
        /* Enable Component interrupts */
        CyIntEnable(QuadDecoder_ISR_NUMBER);
    #endif /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT */
}


/*******************************************************************************
* Function Name: QuadDecoder_Start
********************************************************************************
*
* Summary:
*  Initializes UDBs and other relevant hardware.
*  Resets counter, enables or disables all relevant interrupts.
*  Starts monitoring the inputs and counting.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  QuadDecoder_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QuadDecoder_Start(void) 
{
    #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT)
        QuadDecoder_Cnt8_Start();
        QuadDecoder_Cnt8_WriteCounter(QuadDecoder_COUNTER_INIT_VALUE);
    #else 
        /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT) || 
        *  (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT) 
        */
        QuadDecoder_Cnt16_Start();
        QuadDecoder_Cnt16_WriteCounter(QuadDecoder_COUNTER_INIT_VALUE);
    #endif /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT */

    if (QuadDecoder_initVar == 0u)
    {
        QuadDecoder_Init();
        QuadDecoder_initVar = 1u;
    }

    QuadDecoder_Enable();
}


/*******************************************************************************
* Function Name: QuadDecoder_Stop
********************************************************************************
*
* Summary:
*  Turns off UDBs and other relevant hardware.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDecoder_Stop(void) 
{
    uint8 enableInterrupts;

    #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT)
        QuadDecoder_Cnt8_Stop();
    #else 
        /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT) ||
        *  (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT)
        */
        QuadDecoder_Cnt16_Stop();    /* counter disable */
    #endif /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT) */
 
    enableInterrupts = CyEnterCriticalSection();

    /* Disable interrupts interrupts from Statusi register */
    QuadDecoder_SR_AUX_CONTROL &= (uint8) (~QuadDecoder_INTERRUPTS_ENABLE);

    CyExitCriticalSection(enableInterrupts);

    #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT)
        CyIntDisable(QuadDecoder_ISR_NUMBER);    /* interrupt disable */
    #endif /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT */
}


/*******************************************************************************
* Function Name: QuadDecoder_GetCounter
********************************************************************************
*
* Summary:
*  Reports the current value of the counter.
*
* Parameters:
*  None.
*
* Return:
*  The counter value. Return type is signed and per the counter size setting.
*  A positive value indicates clockwise movement (B before A).
*
* Global variables:
*  QuadDecoder_count32SoftPart - used to get hi 16 bit for current value
*  of the 32-bit counter, when Counter size equal 32-bit.
*
*******************************************************************************/
int8 QuadDecoder_GetCounter(void) 
{
    int8 count;
    uint8 tmpCnt;

    #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT)
        int16 hwCount;

        CyIntDisable(QuadDecoder_ISR_NUMBER);

        tmpCnt = QuadDecoder_Cnt16_ReadCounter();
        hwCount = (int16) ((int32) tmpCnt - (int32) QuadDecoder_COUNTER_INIT_VALUE);
        count = QuadDecoder_count32SoftPart + hwCount;

        CyIntEnable(QuadDecoder_ISR_NUMBER);
    #else 
        /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT) || 
        *  (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT)
        */
        #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT)
            tmpCnt = QuadDecoder_Cnt8_ReadCounter();
        #else /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT) */
            tmpCnt = QuadDecoder_Cnt16_ReadCounter();
        #endif  /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT */

        count = (int8) ((int16) tmpCnt -
                (int16) QuadDecoder_COUNTER_INIT_VALUE);

    #endif /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT */ 

    return (count);
}


/*******************************************************************************
* Function Name: QuadDecoder_SetCounter
********************************************************************************
*
* Summary:
*  Sets the current value of the counter.
*
* Parameters:
*  value:  The new value. Parameter type is signed and per the counter size
*  setting.
*
* Return:
*  None.
*
* Global variables:
*  QuadDecoder_count32SoftPart - modified to set hi 16 bit for current
*  value of the 32-bit counter, when Counter size equal 32-bit.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QuadDecoder_SetCounter(int8 value) 
{
    #if ((QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT) || \
         (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT))
        uint8 count;
        
        if (value >= 0)
        {
            count = (uint8) value + QuadDecoder_COUNTER_INIT_VALUE;
        }
        else
        {
            count = (uint8) (-value);
        }
        #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT)
            QuadDecoder_Cnt8_WriteCounter(count);
        #else /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT) */
            QuadDecoder_Cnt16_WriteCounter(count);
        #endif  /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT */
    #else /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT) */
        CyIntDisable(QuadDecoder_ISR_NUMBER);

        QuadDecoder_Cnt16_WriteCounter(QuadDecoder_COUNTER_INIT_VALUE);
        QuadDecoder_count32SoftPart = value;

        CyIntEnable(QuadDecoder_ISR_NUMBER);
    #endif  /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT) ||
             * (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT)
             */
}


/*******************************************************************************
* Function Name: QuadDecoder_GetEvents
********************************************************************************
* 
* Summary:
*   Reports the current status of events. This function clears the bits of the 
*   status register.
*
* Parameters:
*  None.
*
* Return:
*  The events, as bits in an unsigned 8-bit value:
*    Bit      Description
*     0        Counter overflow.
*     1        Counter underflow.
*     2        Counter reset due to index, if index input is used.
*     3        Invalid A, B inputs state transition.
*
*******************************************************************************/
uint8 QuadDecoder_GetEvents(void) 
{
    return (QuadDecoder_STATUS_REG & QuadDecoder_INIT_INT_MASK);
}


/*******************************************************************************
* Function Name: QuadDecoder_SetInterruptMask
********************************************************************************
*
* Summary:
*  Enables / disables interrupts due to the events.
*  For the 32-bit counter, the overflow, underflow and reset interrupts cannot
*  be disabled, these bits are ignored.
*
* Parameters:
*  mask: Enable / disable bits in an 8-bit value, where 1 enables the interrupt.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDecoder_SetInterruptMask(uint8 mask) 
{
    #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT)
        /* Underflow, Overflow and Reset interrupts for 32-bit Counter are always enable */
        mask |= (QuadDecoder_COUNTER_OVERFLOW | QuadDecoder_COUNTER_UNDERFLOW |
                 QuadDecoder_COUNTER_RESET);
    #endif /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT */

    QuadDecoder_STATUS_MASK = mask;
}


/*******************************************************************************
* Function Name: QuadDecoder_GetInterruptMask
********************************************************************************
*
* Summary:
*  Reports the current interrupt mask settings.
*
* Parameters:
*  None.
*
* Return:
*  Enable / disable bits in an 8-bit value, where 1 enables the interrupt.
*  For the 32-bit counter, the overflow, underflow and reset enable bits are
*  always set.
*
*******************************************************************************/
uint8 QuadDecoder_GetInterruptMask(void) 
{
    return (QuadDecoder_STATUS_MASK & QuadDecoder_INIT_INT_MASK);
}


/* [] END OF FILE */
