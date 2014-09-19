/*******************************************************************************
* File Name: RTX51.c
* Version 1.0
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
#include <RTX51.H>

/* Address of the INTC.VECT[x] register that contains the Address of the RTX51 ISR. */
#define RTX51_RTX51T_VECTOR              ((reg16 *) RTX51_ISR__INTC_VECT)

/* Address of the RTX51 ISR priority. */
#define RTX51_RTX51T_PRIOR             ((reg8 *) RTX51_ISR__INTC_PRIOR_REG)

/* Priority of the RTX51 interrupt. */
#define RTX51_RTX51T_PRIOR_NUMBER      RTX51_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable RTX51 interrupt. */
#define RTX51_RTX51T_SET_EN            ((reg8 *) RTX51_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the RTX51 interrupt. */
#define RTX51_RTX51T_CLR_EN            ((reg8 *) RTX51_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the RTX51 interrupt state to pending. */
#define RTX51_RTX51T_SET_PD            ((reg8 *) RTX51_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the RTX51 interrupt. */
#define RTX51_RTX51T_CLR_PD            ((reg8 *) RTX51_ISR__INTC_CLR_PD_REG)

/* Hook for the RTOS */
extern void TIMERINT(void);

/*******************************************************************************
* Function Name: RTX51_Start
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
void RTX51_Start(void)
{
    /* Disable the general interrupt. */
    *RTX51_RTX51T_CLR_EN = RTX51_ISR__INTC_MASK;

    /* Change the ISR vector for the Interrupt */
    CY_SET_REG16(RTX51_RTX51T_VECTOR, (uint16) TIMERINT);

    /* Sets the Priority of the Interrupt */
    *RTX51_RTX51T_PRIOR = (RTX51_RTX51T_PRIOR_NUMBER) << 5;

    /* Enable the general interrupt. */
    *RTX51_RTX51T_SET_EN = RTX51_ISR__INTC_MASK;
}

/*******************************************************************************
* Function Name: RTX51_Stop
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
void RTX51_Stop(void)
{
    /* Disable the general interrupt. */
    *RTX51_RTX51T_CLR_EN = RTX51_ISR__INTC_MASK;
}
