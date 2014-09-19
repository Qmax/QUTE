/*******************************************************************************
* File Name: EMOSI.c  
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
#include "EMOSI.h"


/*******************************************************************************
* Function Name: EMOSI_Write
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
void EMOSI_Write(uint8 value) 
{
    uint8 staticBits = (EMOSI_DR & (uint8)(~EMOSI_MASK));
    EMOSI_DR = staticBits | ((uint8)(value << EMOSI_SHIFT) & EMOSI_MASK);
}


/*******************************************************************************
* Function Name: EMOSI_SetDriveMode
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
void EMOSI_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(EMOSI_0, mode);
}


/*******************************************************************************
* Function Name: EMOSI_Read
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
*  Macro EMOSI_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EMOSI_Read(void) 
{
    return (EMOSI_PS & EMOSI_MASK) >> EMOSI_SHIFT;
}


/*******************************************************************************
* Function Name: EMOSI_ReadDataReg
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
uint8 EMOSI_ReadDataReg(void) 
{
    return (EMOSI_DR & EMOSI_MASK) >> EMOSI_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EMOSI_INTSTAT) 

    /*******************************************************************************
    * Function Name: EMOSI_ClearInterrupt
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
    uint8 EMOSI_ClearInterrupt(void) 
    {
        return (EMOSI_INTSTAT & EMOSI_MASK) >> EMOSI_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
