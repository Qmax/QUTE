/*******************************************************************************
* File Name: k_isr.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include <cydevice_trm.h>
#include <CyLib.h>
#include <k_isr.h>

#if !defined(k_isr__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START k_isr_intc` */
#include <rtx51tny.h>
#include "TASK3.h"
/* `#END` */


/*******************************************************************************
* Function Name: k_isr_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void k_isr_Start(void) 
{
    /* For all we know the interrupt is active. */
    k_isr_Disable();

    /* Set the ISR to point to the k_isr Interrupt. */
    k_isr_SetVector(&k_isr_Interrupt);

    /* Set the priority. */
    k_isr_SetPriority((uint8)k_isr_INTC_PRIOR_NUMBER);

    /* Enable it. */
    k_isr_Enable();
}


/*******************************************************************************
* Function Name: k_isr_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void k_isr_StartEx(cyisraddress address) 
{
    /* For all we know the interrupt is active. */
    k_isr_Disable();

    /* Set the ISR to point to the k_isr Interrupt. */
    k_isr_SetVector(address);

    /* Set the priority. */
    k_isr_SetPriority((uint8)k_isr_INTC_PRIOR_NUMBER);

    /* Enable it. */
    k_isr_Enable();
}


/*******************************************************************************
* Function Name: k_isr_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void k_isr_Stop(void) 
{
    /* Disable this interrupt. */
    k_isr_Disable();
}


/*******************************************************************************
* Function Name: k_isr_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for k_isr.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(k_isr_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START k_isr_Interrupt` */
	
    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (k_isr__ES2_PATCH ))      
            k_isr_ISR_PATCH();
        #endif /* CYDEV_CHIP_REVISION_USED */
    #endif /* (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */
}


/*******************************************************************************
* Function Name: k_isr_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling k_isr_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use k_isr_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void k_isr_SetVector(cyisraddress address) 
{
    CY_SET_REG16(k_isr_INTC_VECTOR, (uint16) address);
}


/*******************************************************************************
* Function Name: k_isr_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress k_isr_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(k_isr_INTC_VECTOR);
}


/*******************************************************************************
* Function Name: k_isr_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling k_isr_Start
*   or k_isr_StartEx will override any effect this method would 
*   have had. This method should only be called after k_isr_Start or 
*   k_isr_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void k_isr_SetPriority(uint8 priority) 
{
    *k_isr_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: k_isr_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*******************************************************************************/
uint8 k_isr_GetPriority(void) 
{
    uint8 priority;


    priority = *k_isr_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: k_isr_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void k_isr_Enable(void) 
{
    /* Enable the general interrupt. */
    *k_isr_INTC_SET_EN = k_isr__INTC_MASK;
}


/*******************************************************************************
* Function Name: k_isr_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 k_isr_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return ((*k_isr_INTC_SET_EN & (uint8)k_isr__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: k_isr_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void k_isr_Disable(void) 
{
    /* Disable the general interrupt. */
    *k_isr_INTC_CLR_EN = k_isr__INTC_MASK;
}


/*******************************************************************************
* Function Name: k_isr_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void k_isr_SetPending(void) 
{
    *k_isr_INTC_SET_PD = k_isr__INTC_MASK;
}


/*******************************************************************************
* Function Name: k_isr_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void k_isr_ClearPending(void) 
{
    *k_isr_INTC_CLR_PD = k_isr__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
