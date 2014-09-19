/*******************************************************************************
* File Name: QuadDecoder_Cnt16_PM.c  
* Version 2.40
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "QuadDecoder_Cnt16.h"

static QuadDecoder_Cnt16_backupStruct QuadDecoder_Cnt16_backup;


/*******************************************************************************
* Function Name: QuadDecoder_Cnt16_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  QuadDecoder_Cnt16_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void QuadDecoder_Cnt16_SaveConfig(void) 
{
    #if (!QuadDecoder_Cnt16_UsingFixedFunction)

        QuadDecoder_Cnt16_backup.CounterUdb = QuadDecoder_Cnt16_ReadCounter();

        #if (CY_UDB_V0)
            QuadDecoder_Cnt16_backup.CounterPeriod = QuadDecoder_Cnt16_ReadPeriod();
            QuadDecoder_Cnt16_backup.CompareValue = QuadDecoder_Cnt16_ReadCompare();
            QuadDecoder_Cnt16_backup.InterruptMaskValue = QuadDecoder_Cnt16_STATUS_MASK;
        #endif /* CY_UDB_V0 */

        #if(!QuadDecoder_Cnt16_ControlRegRemoved)
            QuadDecoder_Cnt16_backup.CounterControlRegister = QuadDecoder_Cnt16_ReadControlRegister();
        #endif /* (!QuadDecoder_Cnt16_ControlRegRemoved) */

    #endif /* (!QuadDecoder_Cnt16_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: QuadDecoder_Cnt16_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  QuadDecoder_Cnt16_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void QuadDecoder_Cnt16_RestoreConfig(void) 
{      
    #if (!QuadDecoder_Cnt16_UsingFixedFunction)

        #if (CY_UDB_V0)
            uint8 QuadDecoder_Cnt16_interruptState;
        #endif  /* (CY_UDB_V0) */

       QuadDecoder_Cnt16_WriteCounter(QuadDecoder_Cnt16_backup.CounterUdb);

        #if (CY_UDB_V0)
            QuadDecoder_Cnt16_WritePeriod(QuadDecoder_Cnt16_backup.CounterPeriod);
            QuadDecoder_Cnt16_WriteCompare(QuadDecoder_Cnt16_backup.CompareValue);

            QuadDecoder_Cnt16_interruptState = CyEnterCriticalSection();
            QuadDecoder_Cnt16_STATUS_AUX_CTRL |= QuadDecoder_Cnt16_STATUS_ACTL_INT_EN_MASK;
            CyExitCriticalSection(QuadDecoder_Cnt16_interruptState);

            QuadDecoder_Cnt16_STATUS_MASK = QuadDecoder_Cnt16_backup.InterruptMaskValue;
        #endif  /* (CY_UDB_V0) */

        #if(!QuadDecoder_Cnt16_ControlRegRemoved)
            QuadDecoder_Cnt16_WriteControlRegister(QuadDecoder_Cnt16_backup.CounterControlRegister);
        #endif /* (!QuadDecoder_Cnt16_ControlRegRemoved) */

    #endif /* (!QuadDecoder_Cnt16_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: QuadDecoder_Cnt16_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  QuadDecoder_Cnt16_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void QuadDecoder_Cnt16_Sleep(void) 
{
    #if(!QuadDecoder_Cnt16_ControlRegRemoved)
        /* Save Counter's enable state */
        if(QuadDecoder_Cnt16_CTRL_ENABLE == (QuadDecoder_Cnt16_CONTROL & QuadDecoder_Cnt16_CTRL_ENABLE))
        {
            /* Counter is enabled */
            QuadDecoder_Cnt16_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            QuadDecoder_Cnt16_backup.CounterEnableState = 0u;
        }
    #else
        QuadDecoder_Cnt16_backup.CounterEnableState = 1u;
        if(QuadDecoder_Cnt16_backup.CounterEnableState != 0u)
        {
            QuadDecoder_Cnt16_backup.CounterEnableState = 0u;
        }
    #endif /* (!QuadDecoder_Cnt16_ControlRegRemoved) */
    
    QuadDecoder_Cnt16_Stop();
    QuadDecoder_Cnt16_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDecoder_Cnt16_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  QuadDecoder_Cnt16_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void QuadDecoder_Cnt16_Wakeup(void) 
{
    QuadDecoder_Cnt16_RestoreConfig();
    #if(!QuadDecoder_Cnt16_ControlRegRemoved)
        if(QuadDecoder_Cnt16_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            QuadDecoder_Cnt16_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!QuadDecoder_Cnt16_ControlRegRemoved) */
    
}


/* [] END OF FILE */
