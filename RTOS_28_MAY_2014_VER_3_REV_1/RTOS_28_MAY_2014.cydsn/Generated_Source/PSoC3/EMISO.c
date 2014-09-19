/*******************************************************************************
* File Name: EMISO.c  
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
#include "EMISO.h"


/*******************************************************************************
* Function Name: EMISO_Write
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
void EMISO_Write(uint8 value) 
{
    uint8 staticBits = (EMISO_DR & (uint8)(~EMISO_MASK));
    EMISO_DR = staticBits | ((uint8)(value << EMISO_SHIFT) & EMISO_MASK);
}


/*******************************************************************************
* Function Name: EMISO_SetDriveMode
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
void EMISO_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(EMISO_0, mode);
}


/*******************************************************************************
* Function Name: EMISO_Read
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
*  Macro EMISO_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EMISO_Read(void) 
{
    return (EMISO_PS & EMISO_MASK) >> EMISO_SHIFT;
}


/*******************************************************************************
* Function Name: EMISO_ReadDataReg
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
uint8 EMISO_ReadDataReg(void) 
{
    return (EMISO_DR & EMISO_MASK) >> EMISO_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EMISO_INTSTAT) 

    /*******************************************************************************
    * Function Name: EMISO_ClearInterrupt
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
    uint8 EMISO_ClearInterrupt(void) 
    {
        return (EMISO_INTSTAT & EMISO_MASK) >> EMISO_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
