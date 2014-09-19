/*******************************************************************************
* File Name: ISO_SCLK.h  
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

#if !defined(CY_PINS_ISO_SCLK_H) /* Pins ISO_SCLK_H */
#define CY_PINS_ISO_SCLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ISO_SCLK_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ISO_SCLK_Write(uint8 value) ;
void    ISO_SCLK_SetDriveMode(uint8 mode) ;
uint8   ISO_SCLK_ReadDataReg(void) ;
uint8   ISO_SCLK_Read(void) ;
uint8   ISO_SCLK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ISO_SCLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ISO_SCLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ISO_SCLK_DM_RES_UP          PIN_DM_RES_UP
#define ISO_SCLK_DM_RES_DWN         PIN_DM_RES_DWN
#define ISO_SCLK_DM_OD_LO           PIN_DM_OD_LO
#define ISO_SCLK_DM_OD_HI           PIN_DM_OD_HI
#define ISO_SCLK_DM_STRONG          PIN_DM_STRONG
#define ISO_SCLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ISO_SCLK_MASK               ISO_SCLK__MASK
#define ISO_SCLK_SHIFT              ISO_SCLK__SHIFT
#define ISO_SCLK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ISO_SCLK_PS                     (* (reg8 *) ISO_SCLK__PS)
/* Data Register */
#define ISO_SCLK_DR                     (* (reg8 *) ISO_SCLK__DR)
/* Port Number */
#define ISO_SCLK_PRT_NUM                (* (reg8 *) ISO_SCLK__PRT) 
/* Connect to Analog Globals */                                                  
#define ISO_SCLK_AG                     (* (reg8 *) ISO_SCLK__AG)                       
/* Analog MUX bux enable */
#define ISO_SCLK_AMUX                   (* (reg8 *) ISO_SCLK__AMUX) 
/* Bidirectional Enable */                                                        
#define ISO_SCLK_BIE                    (* (reg8 *) ISO_SCLK__BIE)
/* Bit-mask for Aliased Register Access */
#define ISO_SCLK_BIT_MASK               (* (reg8 *) ISO_SCLK__BIT_MASK)
/* Bypass Enable */
#define ISO_SCLK_BYP                    (* (reg8 *) ISO_SCLK__BYP)
/* Port wide control signals */                                                   
#define ISO_SCLK_CTL                    (* (reg8 *) ISO_SCLK__CTL)
/* Drive Modes */
#define ISO_SCLK_DM0                    (* (reg8 *) ISO_SCLK__DM0) 
#define ISO_SCLK_DM1                    (* (reg8 *) ISO_SCLK__DM1)
#define ISO_SCLK_DM2                    (* (reg8 *) ISO_SCLK__DM2) 
/* Input Buffer Disable Override */
#define ISO_SCLK_INP_DIS                (* (reg8 *) ISO_SCLK__INP_DIS)
/* LCD Common or Segment Drive */
#define ISO_SCLK_LCD_COM_SEG            (* (reg8 *) ISO_SCLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define ISO_SCLK_LCD_EN                 (* (reg8 *) ISO_SCLK__LCD_EN)
/* Slew Rate Control */
#define ISO_SCLK_SLW                    (* (reg8 *) ISO_SCLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ISO_SCLK_PRTDSI__CAPS_SEL       (* (reg8 *) ISO_SCLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ISO_SCLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ISO_SCLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ISO_SCLK_PRTDSI__OE_SEL0        (* (reg8 *) ISO_SCLK__PRTDSI__OE_SEL0) 
#define ISO_SCLK_PRTDSI__OE_SEL1        (* (reg8 *) ISO_SCLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ISO_SCLK_PRTDSI__OUT_SEL0       (* (reg8 *) ISO_SCLK__PRTDSI__OUT_SEL0) 
#define ISO_SCLK_PRTDSI__OUT_SEL1       (* (reg8 *) ISO_SCLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ISO_SCLK_PRTDSI__SYNC_OUT       (* (reg8 *) ISO_SCLK__PRTDSI__SYNC_OUT) 


#if defined(ISO_SCLK__INTSTAT)  /* Interrupt Registers */

    #define ISO_SCLK_INTSTAT                (* (reg8 *) ISO_SCLK__INTSTAT)
    #define ISO_SCLK_SNAP                   (* (reg8 *) ISO_SCLK__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ISO_SCLK_H */


/* [] END OF FILE */
