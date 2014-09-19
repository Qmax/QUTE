/*******************************************************************************
* File Name: DMM_2WSEL.c  
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
#include "DMM_2WSEL.h"


/*******************************************************************************
* Function Name: DMM_2WSEL_Write
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
void DMM_2WSEL_Write(uint8 value) 
{
    uint8 staticBits = DMM_2WSEL_DR & ~DMM_2WSEL_MASK;
    DMM_2WSEL_DR = staticBits | ((value << DMM_2WSEL_SHIFT) & DMM_2WSEL_MASK);
}


/*******************************************************************************
* Function Name: DMM_2WSEL_SetDriveMode
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
void DMM_2WSEL_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(DMM_2WSEL_0, mode);
}


/*******************************************************************************
* Function Name: DMM_2WSEL_Read
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
*  Macro DMM_2WSEL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DMM_2WSEL_Read(void) 
{
    return (DMM_2WSEL_PS & DMM_2WSEL_MASK) >> DMM_2WSEL_SHIFT;
}


/*******************************************************************************
* Function Name: DMM_2WSEL_ReadDataReg
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
uint8 DMM_2WSEL_ReadDataReg(void) 
{
    return (DMM_2WSEL_DR & DMM_2WSEL_MASK) >> DMM_2WSEL_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DMM_2WSEL_INTSTAT) 

    /*******************************************************************************
    * Function Name: DMM_2WSEL_ClearInterrupt
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
    uint8 DMM_2WSEL_ClearInterrupt(void) 
    {
        return (DMM_2WSEL_INTSTAT & DMM_2WSEL_MASK) >> DMM_2WSEL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
