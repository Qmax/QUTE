/*******************************************************************************
* File Name: LV_SEL.c  
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
#include "LV_SEL.h"


/*******************************************************************************
* Function Name: LV_SEL_Write
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
void LV_SEL_Write(uint8 value) 
{
    uint8 staticBits = LV_SEL_DR & ~LV_SEL_MASK;
    LV_SEL_DR = staticBits | ((value << LV_SEL_SHIFT) & LV_SEL_MASK);
}


/*******************************************************************************
* Function Name: LV_SEL_SetDriveMode
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
void LV_SEL_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LV_SEL_0, mode);
}


/*******************************************************************************
* Function Name: LV_SEL_Read
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
*  Macro LV_SEL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LV_SEL_Read(void) 
{
    return (LV_SEL_PS & LV_SEL_MASK) >> LV_SEL_SHIFT;
}


/*******************************************************************************
* Function Name: LV_SEL_ReadDataReg
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
uint8 LV_SEL_ReadDataReg(void) 
{
    return (LV_SEL_DR & LV_SEL_MASK) >> LV_SEL_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LV_SEL_INTSTAT) 

    /*******************************************************************************
    * Function Name: LV_SEL_ClearInterrupt
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
    uint8 LV_SEL_ClearInterrupt(void) 
    {
        return (LV_SEL_INTSTAT & LV_SEL_MASK) >> LV_SEL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
