/*******************************************************************************
* File Name: I2C1_SCL.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_I2C1_SCL_H) /* Pins I2C1_SCL_H */
#define CY_PINS_I2C1_SCL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "I2C1_SCL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    I2C1_SCL_Write(uint8 value) ;
void    I2C1_SCL_SetDriveMode(uint8 mode) ;
uint8   I2C1_SCL_ReadDataReg(void) ;
uint8   I2C1_SCL_Read(void) ;
uint8   I2C1_SCL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define I2C1_SCL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define I2C1_SCL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define I2C1_SCL_DM_RES_UP          PIN_DM_RES_UP
#define I2C1_SCL_DM_RES_DWN         PIN_DM_RES_DWN
#define I2C1_SCL_DM_OD_LO           PIN_DM_OD_LO
#define I2C1_SCL_DM_OD_HI           PIN_DM_OD_HI
#define I2C1_SCL_DM_STRONG          PIN_DM_STRONG
#define I2C1_SCL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define I2C1_SCL_MASK               I2C1_SCL__MASK
#define I2C1_SCL_SHIFT              I2C1_SCL__SHIFT
#define I2C1_SCL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define I2C1_SCL_PS                     (* (reg8 *) I2C1_SCL__PS)
/* Data Register */
#define I2C1_SCL_DR                     (* (reg8 *) I2C1_SCL__DR)
/* Port Number */
#define I2C1_SCL_PRT_NUM                (* (reg8 *) I2C1_SCL__PRT) 
/* Connect to Analog Globals */                                                  
#define I2C1_SCL_AG                     (* (reg8 *) I2C1_SCL__AG)                       
/* Analog MUX bux enable */
#define I2C1_SCL_AMUX                   (* (reg8 *) I2C1_SCL__AMUX) 
/* Bidirectional Enable */                                                        
#define I2C1_SCL_BIE                    (* (reg8 *) I2C1_SCL__BIE)
/* Bit-mask for Aliased Register Access */
#define I2C1_SCL_BIT_MASK               (* (reg8 *) I2C1_SCL__BIT_MASK)
/* Bypass Enable */
#define I2C1_SCL_BYP                    (* (reg8 *) I2C1_SCL__BYP)
/* Port wide control signals */                                                   
#define I2C1_SCL_CTL                    (* (reg8 *) I2C1_SCL__CTL)
/* Drive Modes */
#define I2C1_SCL_DM0                    (* (reg8 *) I2C1_SCL__DM0) 
#define I2C1_SCL_DM1                    (* (reg8 *) I2C1_SCL__DM1)
#define I2C1_SCL_DM2                    (* (reg8 *) I2C1_SCL__DM2) 
/* Input Buffer Disable Override */
#define I2C1_SCL_INP_DIS                (* (reg8 *) I2C1_SCL__INP_DIS)
/* LCD Common or Segment Drive */
#define I2C1_SCL_LCD_COM_SEG            (* (reg8 *) I2C1_SCL__LCD_COM_SEG)
/* Enable Segment LCD */
#define I2C1_SCL_LCD_EN                 (* (reg8 *) I2C1_SCL__LCD_EN)
/* Slew Rate Control */
#define I2C1_SCL_SLW                    (* (reg8 *) I2C1_SCL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define I2C1_SCL_PRTDSI__CAPS_SEL       (* (reg8 *) I2C1_SCL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define I2C1_SCL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) I2C1_SCL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define I2C1_SCL_PRTDSI__OE_SEL0        (* (reg8 *) I2C1_SCL__PRTDSI__OE_SEL0) 
#define I2C1_SCL_PRTDSI__OE_SEL1        (* (reg8 *) I2C1_SCL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define I2C1_SCL_PRTDSI__OUT_SEL0       (* (reg8 *) I2C1_SCL__PRTDSI__OUT_SEL0) 
#define I2C1_SCL_PRTDSI__OUT_SEL1       (* (reg8 *) I2C1_SCL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define I2C1_SCL_PRTDSI__SYNC_OUT       (* (reg8 *) I2C1_SCL__PRTDSI__SYNC_OUT) 


#if defined(I2C1_SCL__INTSTAT)  /* Interrupt Registers */

    #define I2C1_SCL_INTSTAT                (* (reg8 *) I2C1_SCL__INTSTAT)
    #define I2C1_SCL_SNAP                   (* (reg8 *) I2C1_SCL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins I2C1_SCL_H */


/* [] END OF FILE */
