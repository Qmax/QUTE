/*******************************************************************************
* File Name: SRC_4.c  
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
#include "SRC_4.h"


/*******************************************************************************
* Function Name: SRC_4_Write
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
void SRC_4_Write(uint8 value) 
{
    uint8 staticBits = (SRC_4_DR & (uint8)(~SRC_4_MASK));
    SRC_4_DR = staticBits | ((uint8)(value << SRC_4_SHIFT) & SRC_4_MASK);
}


/*******************************************************************************
* Function Name: SRC_4_SetDriveMode
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
void SRC_4_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SRC_4_0, mode);
}


/*******************************************************************************
* Function Name: SRC_4_Read
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
*  Macro SRC_4_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SRC_4_Read(void) 
{
    return (SRC_4_PS & SRC_4_MASK) >> SRC_4_SHIFT;
}


/*******************************************************************************
* Function Name: SRC_4_ReadDataReg
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
uint8 SRC_4_ReadDataReg(void) 
{
    return (SRC_4_DR & SRC_4_MASK) >> SRC_4_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SRC_4_INTSTAT) 

    /*******************************************************************************
    * Function Name: SRC_4_ClearInterrupt
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
    uint8 SRC_4_ClearInterrupt(void) 
    {
        return (SRC_4_INTSTAT & SRC_4_MASK) >> SRC_4_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
