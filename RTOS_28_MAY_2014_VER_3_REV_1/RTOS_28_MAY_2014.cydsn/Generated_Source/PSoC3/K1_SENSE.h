/*******************************************************************************
* File Name: K1_SENSE.h  
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

#if !defined(CY_PINS_K1_SENSE_H) /* Pins K1_SENSE_H */
#define CY_PINS_K1_SENSE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "K1_SENSE_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    K1_SENSE_Write(uint8 value) ;
void    K1_SENSE_SetDriveMode(uint8 mode) ;
uint8   K1_SENSE_ReadDataReg(void) ;
uint8   K1_SENSE_Read(void) ;
uint8   K1_SENSE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define K1_SENSE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define K1_SENSE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define K1_SENSE_DM_RES_UP          PIN_DM_RES_UP
#define K1_SENSE_DM_RES_DWN         PIN_DM_RES_DWN
#define K1_SENSE_DM_OD_LO           PIN_DM_OD_LO
#define K1_SENSE_DM_OD_HI           PIN_DM_OD_HI
#define K1_SENSE_DM_STRONG          PIN_DM_STRONG
#define K1_SENSE_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define K1_SENSE_MASK               K1_SENSE__MASK
#define K1_SENSE_SHIFT              K1_SENSE__SHIFT
#define K1_SENSE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define K1_SENSE_PS                     (* (reg8 *) K1_SENSE__PS)
/* Data Register */
#define K1_SENSE_DR                     (* (reg8 *) K1_SENSE__DR)
/* Port Number */
#define K1_SENSE_PRT_NUM                (* (reg8 *) K1_SENSE__PRT) 
/* Connect to Analog Globals */                                                  
#define K1_SENSE_AG                     (* (reg8 *) K1_SENSE__AG)                       
/* Analog MUX bux enable */
#define K1_SENSE_AMUX                   (* (reg8 *) K1_SENSE__AMUX) 
/* Bidirectional Enable */                                                        
#define K1_SENSE_BIE                    (* (reg8 *) K1_SENSE__BIE)
/* Bit-mask for Aliased Register Access */
#define K1_SENSE_BIT_MASK               (* (reg8 *) K1_SENSE__BIT_MASK)
/* Bypass Enable */
#define K1_SENSE_BYP                    (* (reg8 *) K1_SENSE__BYP)
/* Port wide control signals */                                                   
#define K1_SENSE_CTL                    (* (reg8 *) K1_SENSE__CTL)
/* Drive Modes */
#define K1_SENSE_DM0                    (* (reg8 *) K1_SENSE__DM0) 
#define K1_SENSE_DM1                    (* (reg8 *) K1_SENSE__DM1)
#define K1_SENSE_DM2                    (* (reg8 *) K1_SENSE__DM2) 
/* Input Buffer Disable Override */
#define K1_SENSE_INP_DIS                (* (reg8 *) K1_SENSE__INP_DIS)
/* LCD Common or Segment Drive */
#define K1_SENSE_LCD_COM_SEG            (* (reg8 *) K1_SENSE__LCD_COM_SEG)
/* Enable Segment LCD */
#define K1_SENSE_LCD_EN                 (* (reg8 *) K1_SENSE__LCD_EN)
/* Slew Rate Control */
#define K1_SENSE_SLW                    (* (reg8 *) K1_SENSE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define K1_SENSE_PRTDSI__CAPS_SEL       (* (reg8 *) K1_SENSE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define K1_SENSE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) K1_SENSE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define K1_SENSE_PRTDSI__OE_SEL0        (* (reg8 *) K1_SENSE__PRTDSI__OE_SEL0) 
#define K1_SENSE_PRTDSI__OE_SEL1        (* (reg8 *) K1_SENSE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define K1_SENSE_PRTDSI__OUT_SEL0       (* (reg8 *) K1_SENSE__PRTDSI__OUT_SEL0) 
#define K1_SENSE_PRTDSI__OUT_SEL1       (* (reg8 *) K1_SENSE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define K1_SENSE_PRTDSI__SYNC_OUT       (* (reg8 *) K1_SENSE__PRTDSI__SYNC_OUT) 


#if defined(K1_SENSE__INTSTAT)  /* Interrupt Registers */

    #define K1_SENSE_INTSTAT                (* (reg8 *) K1_SENSE__INTSTAT)
    #define K1_SENSE_SNAP                   (* (reg8 *) K1_SENSE__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins K1_SENSE_H */


/* [] END OF FILE */
