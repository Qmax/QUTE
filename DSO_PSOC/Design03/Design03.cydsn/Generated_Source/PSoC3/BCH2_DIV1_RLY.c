/*******************************************************************************
* File Name: BCH2_DIV1_RLY.c  
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
#include "BCH2_DIV1_RLY.h"


/*******************************************************************************
* Function Name: BCH2_DIV1_RLY_Write
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
void BCH2_DIV1_RLY_Write(uint8 value) 
{
    uint8 staticBits = (BCH2_DIV1_RLY_DR & (uint8)(~BCH2_DIV1_RLY_MASK));
    BCH2_DIV1_RLY_DR = staticBits | ((uint8)(value << BCH2_DIV1_RLY_SHIFT) & BCH2_DIV1_RLY_MASK);
}


/*******************************************************************************
* Function Name: BCH2_DIV1_RLY_SetDriveMode
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
void BCH2_DIV1_RLY_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BCH2_DIV1_RLY_0, mode);
}


/*******************************************************************************
* Function Name: BCH2_DIV1_RLY_Read
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
*  Macro BCH2_DIV1_RLY_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BCH2_DIV1_RLY_Read(void) 
{
    return (BCH2_DIV1_RLY_PS & BCH2_DIV1_RLY_MASK) >> BCH2_DIV1_RLY_SHIFT;
}


/*******************************************************************************
* Function Name: BCH2_DIV1_RLY_ReadDataReg
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
uint8 BCH2_DIV1_RLY_ReadDataReg(void) 
{
    return (BCH2_DIV1_RLY_DR & BCH2_DIV1_RLY_MASK) >> BCH2_DIV1_RLY_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BCH2_DIV1_RLY_INTSTAT) 

    /*******************************************************************************
    * Function Name: BCH2_DIV1_RLY_ClearInterrupt
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
    uint8 BCH2_DIV1_RLY_ClearInterrupt(void) 
    {
        return (BCH2_DIV1_RLY_INTSTAT & BCH2_DIV1_RLY_MASK) >> BCH2_DIV1_RLY_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
