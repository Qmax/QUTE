/*******************************************************************************
* File Name: BTRG_EXT5_RLY.c  
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
#include "BTRG_EXT5_RLY.h"


/*******************************************************************************
* Function Name: BTRG_EXT5_RLY_Write
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
void BTRG_EXT5_RLY_Write(uint8 value) 
{
    uint8 staticBits = (BTRG_EXT5_RLY_DR & (uint8)(~BTRG_EXT5_RLY_MASK));
    BTRG_EXT5_RLY_DR = staticBits | ((uint8)(value << BTRG_EXT5_RLY_SHIFT) & BTRG_EXT5_RLY_MASK);
}


/*******************************************************************************
* Function Name: BTRG_EXT5_RLY_SetDriveMode
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
void BTRG_EXT5_RLY_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BTRG_EXT5_RLY_0, mode);
}


/*******************************************************************************
* Function Name: BTRG_EXT5_RLY_Read
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
*  Macro BTRG_EXT5_RLY_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BTRG_EXT5_RLY_Read(void) 
{
    return (BTRG_EXT5_RLY_PS & BTRG_EXT5_RLY_MASK) >> BTRG_EXT5_RLY_SHIFT;
}


/*******************************************************************************
* Function Name: BTRG_EXT5_RLY_ReadDataReg
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
uint8 BTRG_EXT5_RLY_ReadDataReg(void) 
{
    return (BTRG_EXT5_RLY_DR & BTRG_EXT5_RLY_MASK) >> BTRG_EXT5_RLY_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BTRG_EXT5_RLY_INTSTAT) 

    /*******************************************************************************
    * Function Name: BTRG_EXT5_RLY_ClearInterrupt
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
    uint8 BTRG_EXT5_RLY_ClearInterrupt(void) 
    {
        return (BTRG_EXT5_RLY_INTSTAT & BTRG_EXT5_RLY_MASK) >> BTRG_EXT5_RLY_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
