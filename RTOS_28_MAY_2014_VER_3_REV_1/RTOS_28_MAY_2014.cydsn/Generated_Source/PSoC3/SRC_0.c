/*******************************************************************************
* File Name: SRC_0.c  
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
#include "SRC_0.h"


/*******************************************************************************
* Function Name: SRC_0_Write
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
void SRC_0_Write(uint8 value) 
{
    uint8 staticBits = (SRC_0_DR & (uint8)(~SRC_0_MASK));
    SRC_0_DR = staticBits | ((uint8)(value << SRC_0_SHIFT) & SRC_0_MASK);
}


/*******************************************************************************
* Function Name: SRC_0_SetDriveMode
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
void SRC_0_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SRC_0_0, mode);
}


/*******************************************************************************
* Function Name: SRC_0_Read
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
*  Macro SRC_0_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SRC_0_Read(void) 
{
    return (SRC_0_PS & SRC_0_MASK) >> SRC_0_SHIFT;
}


/*******************************************************************************
* Function Name: SRC_0_ReadDataReg
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
uint8 SRC_0_ReadDataReg(void) 
{
    return (SRC_0_DR & SRC_0_MASK) >> SRC_0_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SRC_0_INTSTAT) 

    /*******************************************************************************
    * Function Name: SRC_0_ClearInterrupt
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
    uint8 SRC_0_ClearInterrupt(void) 
    {
        return (SRC_0_INTSTAT & SRC_0_MASK) >> SRC_0_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
