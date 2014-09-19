/*******************************************************************************
* File Name: GPIO0_5V.c  
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
#include "GPIO0_5V.h"


/*******************************************************************************
* Function Name: GPIO0_5V_Write
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
void GPIO0_5V_Write(uint8 value) 
{
    uint8 staticBits = (GPIO0_5V_DR & (uint8)(~GPIO0_5V_MASK));
    GPIO0_5V_DR = staticBits | ((uint8)(value << GPIO0_5V_SHIFT) & GPIO0_5V_MASK);
}


/*******************************************************************************
* Function Name: GPIO0_5V_SetDriveMode
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
void GPIO0_5V_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(GPIO0_5V_0, mode);
}


/*******************************************************************************
* Function Name: GPIO0_5V_Read
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
*  Macro GPIO0_5V_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 GPIO0_5V_Read(void) 
{
    return (GPIO0_5V_PS & GPIO0_5V_MASK) >> GPIO0_5V_SHIFT;
}


/*******************************************************************************
* Function Name: GPIO0_5V_ReadDataReg
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
uint8 GPIO0_5V_ReadDataReg(void) 
{
    return (GPIO0_5V_DR & GPIO0_5V_MASK) >> GPIO0_5V_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(GPIO0_5V_INTSTAT) 

    /*******************************************************************************
    * Function Name: GPIO0_5V_ClearInterrupt
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
    uint8 GPIO0_5V_ClearInterrupt(void) 
    {
        return (GPIO0_5V_INTSTAT & GPIO0_5V_MASK) >> GPIO0_5V_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
