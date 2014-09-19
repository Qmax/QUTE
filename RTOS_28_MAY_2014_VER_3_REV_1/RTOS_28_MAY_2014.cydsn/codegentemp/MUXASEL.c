/*******************************************************************************
* File Name: MUXASEL.c  
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
#include "MUXASEL.h"


/*******************************************************************************
* Function Name: MUXASEL_Write
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
void MUXASEL_Write(uint8 value) 
{
    uint8 staticBits = (MUXASEL_DR & (uint8)(~MUXASEL_MASK));
    MUXASEL_DR = staticBits | ((uint8)(value << MUXASEL_SHIFT) & MUXASEL_MASK);
}


/*******************************************************************************
* Function Name: MUXASEL_SetDriveMode
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
void MUXASEL_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MUXASEL_0, mode);
}


/*******************************************************************************
* Function Name: MUXASEL_Read
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
*  Macro MUXASEL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MUXASEL_Read(void) 
{
    return (MUXASEL_PS & MUXASEL_MASK) >> MUXASEL_SHIFT;
}


/*******************************************************************************
* Function Name: MUXASEL_ReadDataReg
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
uint8 MUXASEL_ReadDataReg(void) 
{
    return (MUXASEL_DR & MUXASEL_MASK) >> MUXASEL_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MUXASEL_INTSTAT) 

    /*******************************************************************************
    * Function Name: MUXASEL_ClearInterrupt
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
    uint8 MUXASEL_ClearInterrupt(void) 
    {
        return (MUXASEL_INTSTAT & MUXASEL_MASK) >> MUXASEL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
