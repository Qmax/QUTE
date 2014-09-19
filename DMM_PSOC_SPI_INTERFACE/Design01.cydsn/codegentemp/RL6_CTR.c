/*******************************************************************************
* File Name: RL6_CTR.c  
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
#include "RL6_CTR.h"


/*******************************************************************************
* Function Name: RL6_CTR_Write
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
void RL6_CTR_Write(uint8 value) 
{
    uint8 staticBits = (RL6_CTR_DR & (uint8)(~RL6_CTR_MASK));
    RL6_CTR_DR = staticBits | ((uint8)(value << RL6_CTR_SHIFT) & RL6_CTR_MASK);
}


/*******************************************************************************
* Function Name: RL6_CTR_SetDriveMode
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
void RL6_CTR_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(RL6_CTR_0, mode);
}


/*******************************************************************************
* Function Name: RL6_CTR_Read
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
*  Macro RL6_CTR_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 RL6_CTR_Read(void) 
{
    return (RL6_CTR_PS & RL6_CTR_MASK) >> RL6_CTR_SHIFT;
}


/*******************************************************************************
* Function Name: RL6_CTR_ReadDataReg
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
uint8 RL6_CTR_ReadDataReg(void) 
{
    return (RL6_CTR_DR & RL6_CTR_MASK) >> RL6_CTR_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(RL6_CTR_INTSTAT) 

    /*******************************************************************************
    * Function Name: RL6_CTR_ClearInterrupt
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
    uint8 RL6_CTR_ClearInterrupt(void) 
    {
        return (RL6_CTR_INTSTAT & RL6_CTR_MASK) >> RL6_CTR_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
