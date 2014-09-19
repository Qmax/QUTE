/*******************************************************************************
* File Name: `$INSTANCE_NAME`.c
* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* Description:
*   API for controlling the RTX51-Tiny RTOS.
*
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/


#include <CYDEVICE.H>
#include <`$INSTANCE_NAME`.H>

/* Address of the INTC.VECT[x] register that contains the Address of the `$INSTANCE_NAME` ISR. */
#define `$INSTANCE_NAME`_RTX51T_VECTOR              ((reg16 *) `$INSTANCE_NAME`_ISR__INTC_VECT)

/* Address of the `$INSTANCE_NAME` ISR priority. */
#define `$INSTANCE_NAME`_RTX51T_PRIOR             ((reg8 *) `$INSTANCE_NAME`_ISR__INTC_PRIOR_REG)

/* Priority of the `$INSTANCE_NAME` interrupt. */
#define `$INSTANCE_NAME`_RTX51T_PRIOR_NUMBER      `$INSTANCE_NAME`_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable `$INSTANCE_NAME` interrupt. */
#define `$INSTANCE_NAME`_RTX51T_SET_EN            ((reg8 *) `$INSTANCE_NAME`_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the `$INSTANCE_NAME` interrupt. */
#define `$INSTANCE_NAME`_RTX51T_CLR_EN            ((reg8 *) `$INSTANCE_NAME`_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the `$INSTANCE_NAME` interrupt state to pending. */
#define `$INSTANCE_NAME`_RTX51T_SET_PD            ((reg8 *) `$INSTANCE_NAME`_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the `$INSTANCE_NAME` interrupt. */
#define `$INSTANCE_NAME`_RTX51T_CLR_PD            ((reg8 *) `$INSTANCE_NAME`_ISR__INTC_CLR_PD_REG)

/* Hook for the RTOS */
extern void TIMERINT(void);

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Start
********************************************************************************
* Summary:
*  Set up the interrupt and enable it for RTX51-Tiny RTOS.
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*******************************************************************************/
void `$INSTANCE_NAME`_Start(void)
{
    /* Disable the general interrupt. */
    *`$INSTANCE_NAME`_RTX51T_CLR_EN = `$INSTANCE_NAME`_ISR__INTC_MASK;

    /* Change the ISR vector for the Interrupt */
    CY_SET_REG16(`$INSTANCE_NAME`_RTX51T_VECTOR, (uint16) TIMERINT);

    /* Sets the Priority of the Interrupt */
    *`$INSTANCE_NAME`_RTX51T_PRIOR = (`$INSTANCE_NAME`_RTX51T_PRIOR_NUMBER) << 5;

    /* Enable the general interrupt. */
    *`$INSTANCE_NAME`_RTX51T_SET_EN = `$INSTANCE_NAME`_ISR__INTC_MASK;
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Stop
********************************************************************************
* Summary:
*   Disables and removes the interrupt and stop the RTX51Tiny RTOS.
*
* Parameters:
*
*
* Return:
*   void.
*
*******************************************************************************/
void `$INSTANCE_NAME`_Stop(void)
{
    /* Disable the general interrupt. */
    *`$INSTANCE_NAME`_RTX51T_CLR_EN = `$INSTANCE_NAME`_ISR__INTC_MASK;
}
