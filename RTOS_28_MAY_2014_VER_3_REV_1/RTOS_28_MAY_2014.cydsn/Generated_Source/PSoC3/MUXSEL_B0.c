/*******************************************************************************
* File Name: MUXSEL_B0.c  
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
#include "MUXSEL_B0.h"


/*******************************************************************************
* Function Name: MUXSEL_B0_Write
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
void MUXSEL_B0_Write(uint8 value) 
{
    uint8 staticBits = (MUXSEL_B0_DR & (uint8)(~MUXSEL_B0_MASK));
    MUXSEL_B0_DR = staticBits | ((uint8)(value << MUXSEL_B0_SHIFT) & MUXSEL_B0_MASK);
}


/*******************************************************************************
* Function Name: MUXSEL_B0_SetDriveMode
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
void MUXSEL_B0_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MUXSEL_B0_0, mode);
}


/*******************************************************************************
* Function Name: MUXSEL_B0_Read
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
*  Macro MUXSEL_B0_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MUXSEL_B0_Read(void) 
{
    return (MUXSEL_B0_PS & MUXSEL_B0_MASK) >> MUXSEL_B0_SHIFT;
}


/*******************************************************************************
* Function Name: MUXSEL_B0_ReadDataReg
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
uint8 MUXSEL_B0_ReadDataReg(void) 
{
    return (MUXSEL_B0_DR & MUXSEL_B0_MASK) >> MUXSEL_B0_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MUXSEL_B0_INTSTAT) 

    /*******************************************************************************
    * Function Name: MUXSEL_B0_ClearInterrupt
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
    uint8 MUXSEL_B0_ClearInterrupt(void) 
    {
        return (MUXSEL_B0_INTSTAT & MUXSEL_B0_MASK) >> MUXSEL_B0_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */