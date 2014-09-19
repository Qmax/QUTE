/*******************************************************************************
* File Name: ISO_DI2.h  
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

#if !defined(CY_PINS_ISO_DI2_H) /* Pins ISO_DI2_H */
#define CY_PINS_ISO_DI2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ISO_DI2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ISO_DI2_Write(uint8 value) ;
void    ISO_DI2_SetDriveMode(uint8 mode) ;
uint8   ISO_DI2_ReadDataReg(void) ;
uint8   ISO_DI2_Read(void) ;
uint8   ISO_DI2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ISO_DI2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ISO_DI2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ISO_DI2_DM_RES_UP          PIN_DM_RES_UP
#define ISO_DI2_DM_RES_DWN         PIN_DM_RES_DWN
#define ISO_DI2_DM_OD_LO           PIN_DM_OD_LO
#define ISO_DI2_DM_OD_HI           PIN_DM_OD_HI
#define ISO_DI2_DM_STRONG          PIN_DM_STRONG
#define ISO_DI2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ISO_DI2_MASK               ISO_DI2__MASK
#define ISO_DI2_SHIFT              ISO_DI2__SHIFT
#define ISO_DI2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ISO_DI2_PS                     (* (reg8 *) ISO_DI2__PS)
/* Data Register */
#define ISO_DI2_DR                     (* (reg8 *) ISO_DI2__DR)
/* Port Number */
#define ISO_DI2_PRT_NUM                (* (reg8 *) ISO_DI2__PRT) 
/* Connect to Analog Globals */                                                  
#define ISO_DI2_AG                     (* (reg8 *) ISO_DI2__AG)                       
/* Analog MUX bux enable */
#define ISO_DI2_AMUX                   (* (reg8 *) ISO_DI2__AMUX) 
/* Bidirectional Enable */                                                        
#define ISO_DI2_BIE                    (* (reg8 *) ISO_DI2__BIE)
/* Bit-mask for Aliased Register Access */
#define ISO_DI2_BIT_MASK               (* (reg8 *) ISO_DI2__BIT_MASK)
/* Bypass Enable */
#define ISO_DI2_BYP                    (* (reg8 *) ISO_DI2__BYP)
/* Port wide control signals */                                                   
#define ISO_DI2_CTL                    (* (reg8 *) ISO_DI2__CTL)
/* Drive Modes */
#define ISO_DI2_DM0                    (* (reg8 *) ISO_DI2__DM0) 
#define ISO_DI2_DM1                    (* (reg8 *) ISO_DI2__DM1)
#define ISO_DI2_DM2                    (* (reg8 *) ISO_DI2__DM2) 
/* Input Buffer Disable Override */
#define ISO_DI2_INP_DIS                (* (reg8 *) ISO_DI2__INP_DIS)
/* LCD Common or Segment Drive */
#define ISO_DI2_LCD_COM_SEG            (* (reg8 *) ISO_DI2__LCD_COM_SEG)
/* Enable Segment LCD */
#define ISO_DI2_LCD_EN                 (* (reg8 *) ISO_DI2__LCD_EN)
/* Slew Rate Control */
#define ISO_DI2_SLW                    (* (reg8 *) ISO_DI2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ISO_DI2_PRTDSI__CAPS_SEL       (* (reg8 *) ISO_DI2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ISO_DI2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ISO_DI2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ISO_DI2_PRTDSI__OE_SEL0        (* (reg8 *) ISO_DI2__PRTDSI__OE_SEL0) 
#define ISO_DI2_PRTDSI__OE_SEL1        (* (reg8 *) ISO_DI2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ISO_DI2_PRTDSI__OUT_SEL0       (* (reg8 *) ISO_DI2__PRTDSI__OUT_SEL0) 
#define ISO_DI2_PRTDSI__OUT_SEL1       (* (reg8 *) ISO_DI2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ISO_DI2_PRTDSI__SYNC_OUT       (* (reg8 *) ISO_DI2__PRTDSI__SYNC_OUT) 


#if defined(ISO_DI2__INTSTAT)  /* Interrupt Registers */

    #define ISO_DI2_INTSTAT                (* (reg8 *) ISO_DI2__INTSTAT)
    #define ISO_DI2_SNAP                   (* (reg8 *) ISO_DI2__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ISO_DI2_H */


/* [] END OF FILE */
