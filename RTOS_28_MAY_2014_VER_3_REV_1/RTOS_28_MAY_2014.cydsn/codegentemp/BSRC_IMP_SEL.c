/*******************************************************************************
* File Name: BSRC_IMP_SEL.c  
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
#include "BSRC_IMP_SEL.h"


/*******************************************************************************
* Function Name: BSRC_IMP_SEL_Write
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
void BSRC_IMP_SEL_Write(uint8 value) 
{
    uint8 staticBits = (BSRC_IMP_SEL_DR & (uint8)(~BSRC_IMP_SEL_MASK));
    BSRC_IMP_SEL_DR = staticBits | ((uint8)(value << BSRC_IMP_SEL_SHIFT) & BSRC_IMP_SEL_MASK);
}


/*******************************************************************************
* Function Name: BSRC_IMP_SEL_SetDriveMode
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
void BSRC_IMP_SEL_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BSRC_IMP_SEL_0, mode);
}


/*******************************************************************************
* Function Name: BSRC_IMP_SEL_Read
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
*  Macro BSRC_IMP_SEL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BSRC_IMP_SEL_Read(void) 
{
    return (BSRC_IMP_SEL_PS & BSRC_IMP_SEL_MASK) >> BSRC_IMP_SEL_SHIFT;
}


/*******************************************************************************
* Function Name: BSRC_IMP_SEL_ReadDataReg
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
uint8 BSRC_IMP_SEL_ReadDataReg(void) 
{
    return (BSRC_IMP_SEL_DR & BSRC_IMP_SEL_MASK) >> BSRC_IMP_SEL_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BSRC_IMP_SEL_INTSTAT) 

    /*******************************************************************************
    * Function Name: BSRC_IMP_SEL_ClearInterrupt
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
    uint8 BSRC_IMP_SEL_ClearInterrupt(void) 
    {
        return (BSRC_IMP_SEL_INTSTAT & BSRC_IMP_SEL_MASK) >> BSRC_IMP_SEL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
