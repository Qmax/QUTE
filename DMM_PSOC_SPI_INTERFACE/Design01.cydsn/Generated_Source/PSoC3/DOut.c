/*******************************************************************************
* File Name: DOut.c  
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
#include "DOut.h"


/*******************************************************************************
* Function Name: DOut_Write
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
void DOut_Write(uint8 value) 
{
    uint8 staticBits = (DOut_DR & (uint8)(~DOut_MASK));
    DOut_DR = staticBits | ((uint8)(value << DOut_SHIFT) & DOut_MASK);
}


/*******************************************************************************
* Function Name: DOut_SetDriveMode
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
void DOut_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(DOut_0, mode);
}


/*******************************************************************************
* Function Name: DOut_Read
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
*  Macro DOut_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DOut_Read(void) 
{
    return (DOut_PS & DOut_MASK) >> DOut_SHIFT;
}


/*******************************************************************************
* Function Name: DOut_ReadDataReg
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
uint8 DOut_ReadDataReg(void) 
{
    return (DOut_DR & DOut_MASK) >> DOut_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DOut_INTSTAT) 

    /*******************************************************************************
    * Function Name: DOut_ClearInterrupt
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
    uint8 DOut_ClearInterrupt(void) 
    {
        return (DOut_INTSTAT & DOut_MASK) >> DOut_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
