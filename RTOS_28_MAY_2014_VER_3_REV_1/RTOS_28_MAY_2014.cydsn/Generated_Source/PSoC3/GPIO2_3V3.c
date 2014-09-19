/*******************************************************************************
* File Name: GPIO2_3V3.c  
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
#include "GPIO2_3V3.h"


/*******************************************************************************
* Function Name: GPIO2_3V3_Write
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
void GPIO2_3V3_Write(uint8 value) 
{
    uint8 staticBits = (GPIO2_3V3_DR & (uint8)(~GPIO2_3V3_MASK));
    GPIO2_3V3_DR = staticBits | ((uint8)(value << GPIO2_3V3_SHIFT) & GPIO2_3V3_MASK);
}


/*******************************************************************************
* Function Name: GPIO2_3V3_SetDriveMode
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
void GPIO2_3V3_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(GPIO2_3V3_0, mode);
}


/*******************************************************************************
* Function Name: GPIO2_3V3_Read
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
*  Macro GPIO2_3V3_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 GPIO2_3V3_Read(void) 
{
    return (GPIO2_3V3_PS & GPIO2_3V3_MASK) >> GPIO2_3V3_SHIFT;
}


/*******************************************************************************
* Function Name: GPIO2_3V3_ReadDataReg
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
uint8 GPIO2_3V3_ReadDataReg(void) 
{
    return (GPIO2_3V3_DR & GPIO2_3V3_MASK) >> GPIO2_3V3_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(GPIO2_3V3_INTSTAT) 

    /*******************************************************************************
    * Function Name: GPIO2_3V3_ClearInterrupt
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
    uint8 GPIO2_3V3_ClearInterrupt(void) 
    {
        return (GPIO2_3V3_INTSTAT & GPIO2_3V3_MASK) >> GPIO2_3V3_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
