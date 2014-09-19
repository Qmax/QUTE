/*******************************************************************************
* File Name: QuadDecoder_Cnt8_PM.c  
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

#include "QuadDecoder_Cnt8.h"

static QuadDecoder_Cnt8_backupStruct QuadDecoder_Cnt8_backup;


/*******************************************************************************
* Function Name: QuadDecoder_Cnt8_SaveConfig
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
*  QuadDecoder_Cnt8_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void QuadDecoder_Cnt8_SaveConfig(void) 
{
    #if (!QuadDecoder_Cnt8_UsingFixedFunction)

        QuadDecoder_Cnt8_backup.CounterUdb = QuadDecoder_Cnt8_ReadCounter();

        #if (CY_UDB_V0)
            QuadDecoder_Cnt8_backup.CounterPeriod = QuadDecoder_Cnt8_ReadPeriod();
            QuadDecoder_Cnt8_backup.CompareValue = QuadDecoder_Cnt8_ReadCompare();
            QuadDecoder_Cnt8_backup.InterruptMaskValue = QuadDecoder_Cnt8_STATUS_MASK;
        #endif /* CY_UDB_V0 */

        #if(!QuadDecoder_Cnt8_ControlRegRemoved)
            QuadDecoder_Cnt8_backup.CounterControlRegister = QuadDecoder_Cnt8_ReadControlRegister();
        #endif /* (!QuadDecoder_Cnt8_ControlRegRemoved) */

    #endif /* (!QuadDecoder_Cnt8_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: QuadDecoder_Cnt8_RestoreConfig
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
*  QuadDecoder_Cnt8_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void QuadDecoder_Cnt8_RestoreConfig(void) 
{      
    #if (!QuadDecoder_Cnt8_UsingFixedFunction)

        #if (CY_UDB_V0)
            uint8 QuadDecoder_Cnt8_interruptState;
        #endif  /* (CY_UDB_V0) */

       QuadDecoder_Cnt8_WriteCounter(QuadDecoder_Cnt8_backup.CounterUdb);

        #if (CY_UDB_V0)
            QuadDecoder_Cnt8_WritePeriod(QuadDecoder_Cnt8_backup.CounterPeriod);
            QuadDecoder_Cnt8_WriteCompare(QuadDecoder_Cnt8_backup.CompareValue);

            QuadDecoder_Cnt8_interruptState = CyEnterCriticalSection();
            QuadDecoder_Cnt8_STATUS_AUX_CTRL |= QuadDecoder_Cnt8_STATUS_ACTL_INT_EN_MASK;
            CyExitCriticalSection(QuadDecoder_Cnt8_interruptState);

            QuadDecoder_Cnt8_STATUS_MASK = QuadDecoder_Cnt8_backup.InterruptMaskValue;
        #endif  /* (CY_UDB_V0) */

        #if(!QuadDecoder_Cnt8_ControlRegRemoved)
            QuadDecoder_Cnt8_WriteControlRegister(QuadDecoder_Cnt8_backup.CounterControlRegister);
        #endif /* (!QuadDecoder_Cnt8_ControlRegRemoved) */

    #endif /* (!QuadDecoder_Cnt8_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: QuadDecoder_Cnt8_Sleep
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
*  QuadDecoder_Cnt8_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void QuadDecoder_Cnt8_Sleep(void) 
{
    #if(!QuadDecoder_Cnt8_ControlRegRemoved)
        /* Save Counter's enable state */
        if(QuadDecoder_Cnt8_CTRL_ENABLE == (QuadDecoder_Cnt8_CONTROL & QuadDecoder_Cnt8_CTRL_ENABLE))
        {
            /* Counter is enabled */
            QuadDecoder_Cnt8_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            QuadDecoder_Cnt8_backup.CounterEnableState = 0u;
        }
    #else
        QuadDecoder_Cnt8_backup.CounterEnableState = 1u;
        if(QuadDecoder_Cnt8_backup.CounterEnableState != 0u)
        {
            QuadDecoder_Cnt8_backup.CounterEnableState = 0u;
        }
    #endif /* (!QuadDecoder_Cnt8_ControlRegRemoved) */
    
    QuadDecoder_Cnt8_Stop();
    QuadDecoder_Cnt8_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDecoder_Cnt8_Wakeup
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
*  QuadDecoder_Cnt8_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void QuadDecoder_Cnt8_Wakeup(void) 
{
    QuadDecoder_Cnt8_RestoreConfig();
    #if(!QuadDecoder_Cnt8_ControlRegRemoved)
        if(QuadDecoder_Cnt8_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            QuadDecoder_Cnt8_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!QuadDecoder_Cnt8_ControlRegRemoved) */
    
}


/* [] END OF FILE */
