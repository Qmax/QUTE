/*******************************************************************************
* File Name: ATTN_SEL2.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "ATTN_SEL2.h"


/*******************************************************************************
* Function Name: ATTN_SEL2_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void ATTN_SEL2_Write(uint8 value) 
{
    uint8 staticBits = (ATTN_SEL2_DR & (uint8)(~ATTN_SEL2_MASK));
    ATTN_SEL2_DR = staticBits | ((uint8)(value << ATTN_SEL2_SHIFT) & ATTN_SEL2_MASK);
}


/*******************************************************************************
* Function Name: ATTN_SEL2_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void ATTN_SEL2_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ATTN_SEL2_0, mode);
}


/*******************************************************************************
* Function Name: ATTN_SEL2_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro ATTN_SEL2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ATTN_SEL2_Read(void) 
{
    return (ATTN_SEL2_PS & ATTN_SEL2_MASK) >> ATTN_SEL2_SHIFT;
}


/*******************************************************************************
* Function Name: ATTN_SEL2_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 ATTN_SEL2_ReadDataReg(void) 
{
    return (ATTN_SEL2_DR & ATTN_SEL2_MASK) >> ATTN_SEL2_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ATTN_SEL2_INTSTAT) 

    /*******************************************************************************
    * Function Name: ATTN_SEL2_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 ATTN_SEL2_ClearInterrupt(void) 
    {
        return (ATTN_SEL2_INTSTAT & ATTN_SEL2_MASK) >> ATTN_SEL2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
