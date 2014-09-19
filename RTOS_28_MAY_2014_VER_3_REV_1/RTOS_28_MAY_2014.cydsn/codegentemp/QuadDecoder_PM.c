/*******************************************************************************
* File Name: QuadDecoder_PM.c
* Version 2.30
*
* Description:
*  This file contains the setup, control and status commands to support 
*  component operations in low power mode.  
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

static QuadDecoder_BACKUP_STRUCT QuadDecoder_backup = {0u};


/*******************************************************************************
* Function Name: QuadDecoder_SaveConfig
********************************************************************************
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDecoder_SaveConfig(void) 
{
    #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT)
        QuadDecoder_Cnt8_SaveConfig();
    #else 
        /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT) || 
         * (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT)
         */
        QuadDecoder_Cnt16_SaveConfig();
    #endif /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: QuadDecoder_RestoreConfig
********************************************************************************
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDecoder_RestoreConfig(void) 
{
    #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT)
        QuadDecoder_Cnt8_RestoreConfig();
    #else 
        /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT) || 
         * (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT) 
         */
        QuadDecoder_Cnt16_RestoreConfig();
    #endif /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: QuadDecoder_Sleep
********************************************************************************
* 
* Summary:
*  Prepare Quadrature Decoder Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  QuadDecoder_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QuadDecoder_Sleep(void) 
{
    if (0u != (QuadDecoder_SR_AUX_CONTROL & QuadDecoder_INTERRUPTS_ENABLE))
    {
        QuadDecoder_backup.enableState = 1u;
    }
    else /* The Quadrature Decoder Component is disabled */
    {
        QuadDecoder_backup.enableState = 0u;
    }

    QuadDecoder_Stop();
    QuadDecoder_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDecoder_Wakeup
********************************************************************************
*
* Summary:
*  Prepare Quadrature Decoder Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  QuadDecoder_backup - used when non-retention registers are restored.
*
*******************************************************************************/
void QuadDecoder_Wakeup(void) 
{
    QuadDecoder_RestoreConfig();

    if (QuadDecoder_backup.enableState != 0u)
    {
        #if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT)
            QuadDecoder_Cnt8_Enable();
        #else 
            /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT) || 
            *  (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT) 
            */
            QuadDecoder_Cnt16_Enable();
        #endif /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT) */

        /* Enable component's operation */
        QuadDecoder_Enable();
    } /* Do nothing if component's block was disabled before */
}


/* [] END OF FILE */

