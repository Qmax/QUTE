/*******************************************************************************
* File Name: ISO_SCS.c  
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
#include "ISO_SCS.h"


/*******************************************************************************
* Function Name: ISO_SCS_Write
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
void ISO_SCS_Write(uint8 value) 
{
    uint8 staticBits = (ISO_SCS_DR & (uint8)(~ISO_SCS_MASK));
    ISO_SCS_DR = staticBits | ((uint8)(value << ISO_SCS_SHIFT) & ISO_SCS_MASK);
}


/*******************************************************************************
* Function Name: ISO_SCS_SetDriveMode
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
void ISO_SCS_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ISO_SCS_0, mode);
}


/*******************************************************************************
* Function Name: ISO_SCS_Read
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
*  Macro ISO_SCS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ISO_SCS_Read(void) 
{
    return (ISO_SCS_PS & ISO_SCS_MASK) >> ISO_SCS_SHIFT;
}


/*******************************************************************************
* Function Name: ISO_SCS_ReadDataReg
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
uint8 ISO_SCS_ReadDataReg(void) 
{
    return (ISO_SCS_DR & ISO_SCS_MASK) >> ISO_SCS_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ISO_SCS_INTSTAT) 

    /*******************************************************************************
    * Function Name: ISO_SCS_ClearInterrupt
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
    uint8 ISO_SCS_ClearInterrupt(void) 
    {
        return (ISO_SCS_INTSTAT & ISO_SCS_MASK) >> ISO_SCS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
