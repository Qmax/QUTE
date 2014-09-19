/*******************************************************************************
* File Name: CK.c  
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
#include "CK.h"


/*******************************************************************************
* Function Name: CK_Write
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
void CK_Write(uint8 value) 
{
    uint8 staticBits = (CK_DR & (uint8)(~CK_MASK));
    CK_DR = staticBits | ((uint8)(value << CK_SHIFT) & CK_MASK);
}


/*******************************************************************************
* Function Name: CK_SetDriveMode
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
void CK_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(CK_0, mode);
}


/*******************************************************************************
* Function Name: CK_Read
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
*  Macro CK_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 CK_Read(void) 
{
    return (CK_PS & CK_MASK) >> CK_SHIFT;
}


/*******************************************************************************
* Function Name: CK_ReadDataReg
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
uint8 CK_ReadDataReg(void) 
{
    return (CK_DR & CK_MASK) >> CK_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(CK_INTSTAT) 

    /*******************************************************************************
    * Function Name: CK_ClearInterrupt
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
    uint8 CK_ClearInterrupt(void) 
    {
        return (CK_INTSTAT & CK_MASK) >> CK_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
