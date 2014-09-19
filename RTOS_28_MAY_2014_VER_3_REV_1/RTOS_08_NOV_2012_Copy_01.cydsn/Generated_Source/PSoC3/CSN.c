/*******************************************************************************
* File Name: CSN.c  
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
#include "CSN.h"


/*******************************************************************************
* Function Name: CSN_Write
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
void CSN_Write(uint8 value) 
{
    uint8 staticBits = CSN_DR & ~CSN_MASK;
    CSN_DR = staticBits | ((value << CSN_SHIFT) & CSN_MASK);
}


/*******************************************************************************
* Function Name: CSN_SetDriveMode
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
void CSN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(CSN_0, mode);
}


/*******************************************************************************
* Function Name: CSN_Read
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
*  Macro CSN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 CSN_Read(void) 
{
    return (CSN_PS & CSN_MASK) >> CSN_SHIFT;
}


/*******************************************************************************
* Function Name: CSN_ReadDataReg
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
uint8 CSN_ReadDataReg(void) 
{
    return (CSN_DR & CSN_MASK) >> CSN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(CSN_INTSTAT) 

    /*******************************************************************************
    * Function Name: CSN_ClearInterrupt
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
    uint8 CSN_ClearInterrupt(void) 
    {
        return (CSN_INTSTAT & CSN_MASK) >> CSN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
