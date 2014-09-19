/*******************************************************************************
* File Name: SPIS_2_PM.c
* Version 2.20
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIS_2.h"

static SPIS_2_BACKUP_STRUCT SPIS_2_backup = {
                                        0u,
                                        SPIS_2_BITCTR_INIT,
                                        #if(CY_PSOC3_ES2 || CY_PSOC5_ES1)
                                            SPIS_2_TX_INIT_INTERRUPTS_MASK,
                                            SPIS_2_RX_INIT_INTERRUPTS_MASK
                                        #endif /* CY_PSOC3_ES2 || CY_PSOC5_ES1 */
                                        };

#if (SPIS_2_TXBUFFERSIZE > 4u)

    extern volatile uint8 SPIS_2_txBufferRead;
    extern volatile uint8 SPIS_2_txBufferWrite;

#endif /* SPIS_2_TXBUFFERSIZE > 4u */

#if (SPIS_2_RXBUFFERSIZE > 4u)

    extern volatile uint8 SPIS_2_rxBufferRead;
    extern volatile uint8 SPIS_2_rxBufferWrite;

#endif /* SPIS_2_RXBUFFERSIZE > 4u */


/*******************************************************************************
* Function Name: SPIS_2_SaveConfig
********************************************************************************
*
* Summary:
*  Saves SPIM configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIS_2_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_2_SaveConfig(void)
{
    /* Store Status Mask registers */
    #if (CY_PSOC3_ES2 || CY_PSOC5_ES1)

       SPIS_2_backup.saveSrTxIntMask = SPIS_2_TX_STATUS_MASK_REG;
       SPIS_2_backup.saveSrRxIntMask = SPIS_2_RX_STATUS_MASK_REG;
       SPIS_2_backup.cntrPeriod = SPIS_2_COUNTER_PERIOD_REG;

    #endif /* (CY_PSOC3_ES2 || CY_PSOC5_ES1) */
}


/*******************************************************************************
* Function Name: SPIS_2_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores SPIM configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIS_2_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer:
*  SPIS_2_STATUS_MASK_REG and SPIS_2_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void SPIS_2_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if (CY_PSOC3_ES2 || CY_PSOC5_ES1)

        SPIS_2_TX_STATUS_MASK_REG = SPIS_2_backup.saveSrTxIntMask;
        SPIS_2_RX_STATUS_MASK_REG = SPIS_2_backup.saveSrRxIntMask;
        SPIS_2_COUNTER_PERIOD_REG = SPIS_2_backup.cntrPeriod;

    #endif /* (CY_PSOC3_ES2 || CY_PSOC5_ES1) */
}


/*******************************************************************************
* Function Name: SPIS_2_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIS_2_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_2_Sleep(void)
{
    /* Save components enable state */
    if ((SPIS_2_TX_STATUS_ACTL_REG & SPIS_2_INT_ENABLE) == SPIS_2_INT_ENABLE)
    {
        SPIS_2_backup.enableState = 1u;
    }
    else /* Components block is disabled */
    {
        SPIS_2_backup.enableState = 0u;
    }

    SPIS_2_Stop();

    SPIS_2_SaveConfig();
}


/*******************************************************************************
* Function Name: SPIS_2_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIS_2_backup - used when non-retention registers are restored.
*  SPIS_2_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIS_2_txBufferRead - modified every function call - resets to
*  zero.
*  SPIS_2_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIS_2_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_2_Wakeup(void)
{
    SPIS_2_RestoreConfig();

    #if (SPIS_2_TXBUFFERSIZE > 4u)

        SPIS_2_txBufferRead = 0u;
        SPIS_2_txBufferWrite = 0u;

    #endif /* SPIS_2_TXBUFFERSIZE > 4u */

    #if (SPIS_2_RXBUFFERSIZE > 4u)

        SPIS_2_rxBufferRead = 0u;
        SPIS_2_rxBufferWrite = 0u;

    #endif /* SPIS_2_RXBUFFERSIZE > 4u */

    SPIS_2_ClearFIFO();

    /* Restore components block enable state */
    if (SPIS_2_backup.enableState != 0u)
    {
         /* Components block was enabled */
         SPIS_2_Enable();
    } /* Do nothing if components block was disabled */
}


/* [] END OF FILE */
