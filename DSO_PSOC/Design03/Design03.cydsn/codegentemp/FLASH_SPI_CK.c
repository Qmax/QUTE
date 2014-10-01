/*******************************************************************************
* File Name: FLASH_SPI_CK.c  
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
#include "FLASH_SPI_CK.h"


/*******************************************************************************
* Function Name: FLASH_SPI_CK_Write
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
void FLASH_SPI_CK_Write(uint8 value) 
{
    uint8 staticBits = (FLASH_SPI_CK_DR & (uint8)(~FLASH_SPI_CK_MASK));
    FLASH_SPI_CK_DR = staticBits | ((uint8)(value << FLASH_SPI_CK_SHIFT) & FLASH_SPI_CK_MASK);
}


/*******************************************************************************
* Function Name: FLASH_SPI_CK_SetDriveMode
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
void FLASH_SPI_CK_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(FLASH_SPI_CK_0, mode);
}


/*******************************************************************************
* Function Name: FLASH_SPI_CK_Read
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
*  Macro FLASH_SPI_CK_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 FLASH_SPI_CK_Read(void) 
{
    return (FLASH_SPI_CK_PS & FLASH_SPI_CK_MASK) >> FLASH_SPI_CK_SHIFT;
}


/*******************************************************************************
* Function Name: FLASH_SPI_CK_ReadDataReg
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
uint8 FLASH_SPI_CK_ReadDataReg(void) 
{
    return (FLASH_SPI_CK_DR & FLASH_SPI_CK_MASK) >> FLASH_SPI_CK_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(FLASH_SPI_CK_INTSTAT) 

    /*******************************************************************************
    * Function Name: FLASH_SPI_CK_ClearInterrupt
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
    uint8 FLASH_SPI_CK_ClearInterrupt(void) 
    {
        return (FLASH_SPI_CK_INTSTAT & FLASH_SPI_CK_MASK) >> FLASH_SPI_CK_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
