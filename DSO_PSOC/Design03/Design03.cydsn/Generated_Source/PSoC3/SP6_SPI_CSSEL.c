/*******************************************************************************
* File Name: SP6_SPI_CSSEL.c  
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
#include "SP6_SPI_CSSEL.h"


/*******************************************************************************
* Function Name: SP6_SPI_CSSEL_Write
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
void SP6_SPI_CSSEL_Write(uint8 value) 
{
    uint8 staticBits = (SP6_SPI_CSSEL_DR & (uint8)(~SP6_SPI_CSSEL_MASK));
    SP6_SPI_CSSEL_DR = staticBits | ((uint8)(value << SP6_SPI_CSSEL_SHIFT) & SP6_SPI_CSSEL_MASK);
}


/*******************************************************************************
* Function Name: SP6_SPI_CSSEL_SetDriveMode
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
void SP6_SPI_CSSEL_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SP6_SPI_CSSEL_0, mode);
}


/*******************************************************************************
* Function Name: SP6_SPI_CSSEL_Read
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
*  Macro SP6_SPI_CSSEL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SP6_SPI_CSSEL_Read(void) 
{
    return (SP6_SPI_CSSEL_PS & SP6_SPI_CSSEL_MASK) >> SP6_SPI_CSSEL_SHIFT;
}


/*******************************************************************************
* Function Name: SP6_SPI_CSSEL_ReadDataReg
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
uint8 SP6_SPI_CSSEL_ReadDataReg(void) 
{
    return (SP6_SPI_CSSEL_DR & SP6_SPI_CSSEL_MASK) >> SP6_SPI_CSSEL_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SP6_SPI_CSSEL_INTSTAT) 

    /*******************************************************************************
    * Function Name: SP6_SPI_CSSEL_ClearInterrupt
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
    uint8 SP6_SPI_CSSEL_ClearInterrupt(void) 
    {
        return (SP6_SPI_CSSEL_INTSTAT & SP6_SPI_CSSEL_MASK) >> SP6_SPI_CSSEL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
