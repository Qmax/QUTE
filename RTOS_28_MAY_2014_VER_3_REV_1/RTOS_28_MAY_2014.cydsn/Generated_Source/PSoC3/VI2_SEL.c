/*******************************************************************************
* File Name: VI2_SEL.c  
* Version 1.60
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "VI2_SEL.h"


/*******************************************************************************
* Function Name: VI2_SEL_Write
********************************************************************************
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  void 
*  
*******************************************************************************/
void VI2_SEL_Write(uint8 value) 
{
    uint8 staticBits = VI2_SEL_DR & ~VI2_SEL_MASK;
    VI2_SEL_DR = staticBits | ((value << VI2_SEL_SHIFT) & VI2_SEL_MASK);
}


/*******************************************************************************
* Function Name: VI2_SEL_SetDriveMode
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  void
*
*******************************************************************************/
void VI2_SEL_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(VI2_SEL_0, mode);
}


/*******************************************************************************
* Function Name: VI2_SEL_Read
********************************************************************************
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro VI2_SEL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VI2_SEL_Read(void) 
{
    return (VI2_SEL_PS & VI2_SEL_MASK) >> VI2_SEL_SHIFT;
}


/*******************************************************************************
* Function Name: VI2_SEL_ReadDataReg
********************************************************************************
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 VI2_SEL_ReadDataReg(void) 
{
    return (VI2_SEL_DR & VI2_SEL_MASK) >> VI2_SEL_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VI2_SEL_INTSTAT) 

    /*******************************************************************************
    * Function Name: VI2_SEL_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  void 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 VI2_SEL_ClearInterrupt(void) 
    {
        return (VI2_SEL_INTSTAT & VI2_SEL_MASK) >> VI2_SEL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
