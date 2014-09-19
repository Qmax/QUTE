/*******************************************************************************
* File Name: ECLK.c  
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
#include "ECLK.h"


/*******************************************************************************
* Function Name: ECLK_Write
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
void ECLK_Write(uint8 value) 
{
    uint8 staticBits = (ECLK_DR & (uint8)(~ECLK_MASK));
    ECLK_DR = staticBits | ((uint8)(value << ECLK_SHIFT) & ECLK_MASK);
}


/*******************************************************************************
* Function Name: ECLK_SetDriveMode
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
void ECLK_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ECLK_0, mode);
}


/*******************************************************************************
* Function Name: ECLK_Read
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
*  Macro ECLK_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ECLK_Read(void) 
{
    return (ECLK_PS & ECLK_MASK) >> ECLK_SHIFT;
}


/*******************************************************************************
* Function Name: ECLK_ReadDataReg
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
uint8 ECLK_ReadDataReg(void) 
{
    return (ECLK_DR & ECLK_MASK) >> ECLK_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ECLK_INTSTAT) 

    /*******************************************************************************
    * Function Name: ECLK_ClearInterrupt
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
    uint8 ECLK_ClearInterrupt(void) 
    {
        return (ECLK_INTSTAT & ECLK_MASK) >> ECLK_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
