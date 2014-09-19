/*******************************************************************************
* File Name: TRIGIN_PSoC.c  
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
#include "TRIGIN_PSoC.h"


/*******************************************************************************
* Function Name: TRIGIN_PSoC_Write
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
void TRIGIN_PSoC_Write(uint8 value) 
{
    uint8 staticBits = TRIGIN_PSoC_DR & ~TRIGIN_PSoC_MASK;
    TRIGIN_PSoC_DR = staticBits | ((value << TRIGIN_PSoC_SHIFT) & TRIGIN_PSoC_MASK);
}


/*******************************************************************************
* Function Name: TRIGIN_PSoC_SetDriveMode
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
void TRIGIN_PSoC_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(TRIGIN_PSoC_0, mode);
}


/*******************************************************************************
* Function Name: TRIGIN_PSoC_Read
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
*  Macro TRIGIN_PSoC_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TRIGIN_PSoC_Read(void) 
{
    return (TRIGIN_PSoC_PS & TRIGIN_PSoC_MASK) >> TRIGIN_PSoC_SHIFT;
}


/*******************************************************************************
* Function Name: TRIGIN_PSoC_ReadDataReg
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
uint8 TRIGIN_PSoC_ReadDataReg(void) 
{
    return (TRIGIN_PSoC_DR & TRIGIN_PSoC_MASK) >> TRIGIN_PSoC_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TRIGIN_PSoC_INTSTAT) 

    /*******************************************************************************
    * Function Name: TRIGIN_PSoC_ClearInterrupt
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
    uint8 TRIGIN_PSoC_ClearInterrupt(void) 
    {
        return (TRIGIN_PSoC_INTSTAT & TRIGIN_PSoC_MASK) >> TRIGIN_PSoC_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
