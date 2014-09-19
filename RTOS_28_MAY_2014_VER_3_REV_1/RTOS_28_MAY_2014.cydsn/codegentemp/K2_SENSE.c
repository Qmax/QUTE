/*******************************************************************************
* File Name: K2_SENSE.c  
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
#include "K2_SENSE.h"


/*******************************************************************************
* Function Name: K2_SENSE_Write
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
void K2_SENSE_Write(uint8 value) 
{
    uint8 staticBits = (K2_SENSE_DR & (uint8)(~K2_SENSE_MASK));
    K2_SENSE_DR = staticBits | ((uint8)(value << K2_SENSE_SHIFT) & K2_SENSE_MASK);
}


/*******************************************************************************
* Function Name: K2_SENSE_SetDriveMode
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
void K2_SENSE_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(K2_SENSE_0, mode);
}


/*******************************************************************************
* Function Name: K2_SENSE_Read
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
*  Macro K2_SENSE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 K2_SENSE_Read(void) 
{
    return (K2_SENSE_PS & K2_SENSE_MASK) >> K2_SENSE_SHIFT;
}


/*******************************************************************************
* Function Name: K2_SENSE_ReadDataReg
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
uint8 K2_SENSE_ReadDataReg(void) 
{
    return (K2_SENSE_DR & K2_SENSE_MASK) >> K2_SENSE_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(K2_SENSE_INTSTAT) 

    /*******************************************************************************
    * Function Name: K2_SENSE_ClearInterrupt
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
    uint8 K2_SENSE_ClearInterrupt(void) 
    {
        return (K2_SENSE_INTSTAT & K2_SENSE_MASK) >> K2_SENSE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
