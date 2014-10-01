/*******************************************************************************
* File Name: PSOC_SPI_CLK.c  
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
#include "PSOC_SPI_CLK.h"


/*******************************************************************************
* Function Name: PSOC_SPI_CLK_Write
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
void PSOC_SPI_CLK_Write(uint8 value) 
{
    uint8 staticBits = (PSOC_SPI_CLK_DR & (uint8)(~PSOC_SPI_CLK_MASK));
    PSOC_SPI_CLK_DR = staticBits | ((uint8)(value << PSOC_SPI_CLK_SHIFT) & PSOC_SPI_CLK_MASK);
}


/*******************************************************************************
* Function Name: PSOC_SPI_CLK_SetDriveMode
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
void PSOC_SPI_CLK_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PSOC_SPI_CLK_0, mode);
}


/*******************************************************************************
* Function Name: PSOC_SPI_CLK_Read
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
*  Macro PSOC_SPI_CLK_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PSOC_SPI_CLK_Read(void) 
{
    return (PSOC_SPI_CLK_PS & PSOC_SPI_CLK_MASK) >> PSOC_SPI_CLK_SHIFT;
}


/*******************************************************************************
* Function Name: PSOC_SPI_CLK_ReadDataReg
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
uint8 PSOC_SPI_CLK_ReadDataReg(void) 
{
    return (PSOC_SPI_CLK_DR & PSOC_SPI_CLK_MASK) >> PSOC_SPI_CLK_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PSOC_SPI_CLK_INTSTAT) 

    /*******************************************************************************
    * Function Name: PSOC_SPI_CLK_ClearInterrupt
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
    uint8 PSOC_SPI_CLK_ClearInterrupt(void) 
    {
        return (PSOC_SPI_CLK_INTSTAT & PSOC_SPI_CLK_MASK) >> PSOC_SPI_CLK_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
