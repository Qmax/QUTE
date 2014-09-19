/*******************************************************************************
* File Name: KEY.c  
* Version 1.60
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "KEY.h"


/*******************************************************************************
* Function Name: KEY_Write
********************************************************************************
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  void 
*  
*******************************************************************************/
void KEY_Write(uint8 value) 
{
    uint8 staticBits = KEY_DR & ~KEY_MASK;
    KEY_DR = staticBits | ((value << KEY_SHIFT) & KEY_MASK);
}


/*******************************************************************************
* Function Name: KEY_SetDriveMode
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  void
*
*******************************************************************************/
void KEY_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(KEY_0, mode);
}


/*******************************************************************************
* Function Name: KEY_Read
********************************************************************************
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro KEY_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 KEY_Read(void) 
{
    return (KEY_PS & KEY_MASK) >> KEY_SHIFT;
}


/*******************************************************************************
* Function Name: KEY_ReadDataReg
********************************************************************************
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 KEY_ReadDataReg(void) 
{
    return (KEY_DR & KEY_MASK) >> KEY_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(KEY_INTSTAT) 

    /*******************************************************************************
    * Function Name: KEY_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  void 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 KEY_ClearInterrupt(void) 
    {
        return (KEY_INTSTAT & KEY_MASK) >> KEY_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
