/*******************************************************************************
* File Name: K2_SENSE.h  
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

#if !defined(CY_PINS_K2_SENSE_H) /* Pins K2_SENSE_H */
#define CY_PINS_K2_SENSE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "K2_SENSE_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    K2_SENSE_Write(uint8 value) ;
void    K2_SENSE_SetDriveMode(uint8 mode) ;
uint8   K2_SENSE_ReadDataReg(void) ;
uint8   K2_SENSE_Read(void) ;
uint8   K2_SENSE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define K2_SENSE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define K2_SENSE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define K2_SENSE_DM_RES_UP          PIN_DM_RES_UP
#define K2_SENSE_DM_RES_DWN         PIN_DM_RES_DWN
#define K2_SENSE_DM_OD_LO           PIN_DM_OD_LO
#define K2_SENSE_DM_OD_HI           PIN_DM_OD_HI
#define K2_SENSE_DM_STRONG          PIN_DM_STRONG
#define K2_SENSE_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define K2_SENSE_MASK               K2_SENSE__MASK
#define K2_SENSE_SHIFT              K2_SENSE__SHIFT
#define K2_SENSE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define K2_SENSE_PS                     (* (reg8 *) K2_SENSE__PS)
/* Data Register */
#define K2_SENSE_DR                     (* (reg8 *) K2_SENSE__DR)
/* Port Number */
#define K2_SENSE_PRT_NUM                (* (reg8 *) K2_SENSE__PRT) 
/* Connect to Analog Globals */                                                  
#define K2_SENSE_AG                     (* (reg8 *) K2_SENSE__AG)                       
/* Analog MUX bux enable */
#define K2_SENSE_AMUX                   (* (reg8 *) K2_SENSE__AMUX) 
/* Bidirectional Enable */                                                        
#define K2_SENSE_BIE                    (* (reg8 *) K2_SENSE__BIE)
/* Bit-mask for Aliased Register Access */
#define K2_SENSE_BIT_MASK               (* (reg8 *) K2_SENSE__BIT_MASK)
/* Bypass Enable */
#define K2_SENSE_BYP                    (* (reg8 *) K2_SENSE__BYP)
/* Port wide control signals */                                                   
#define K2_SENSE_CTL                    (* (reg8 *) K2_SENSE__CTL)
/* Drive Modes */
#define K2_SENSE_DM0                    (* (reg8 *) K2_SENSE__DM0) 
#define K2_SENSE_DM1                    (* (reg8 *) K2_SENSE__DM1)
#define K2_SENSE_DM2                    (* (reg8 *) K2_SENSE__DM2) 
/* Input Buffer Disable Override */
#define K2_SENSE_INP_DIS                (* (reg8 *) K2_SENSE__INP_DIS)
/* LCD Common or Segment Drive */
#define K2_SENSE_LCD_COM_SEG            (* (reg8 *) K2_SENSE__LCD_COM_SEG)
/* Enable Segment LCD */
#define K2_SENSE_LCD_EN                 (* (reg8 *) K2_SENSE__LCD_EN)
/* Slew Rate Control */
#define K2_SENSE_SLW                    (* (reg8 *) K2_SENSE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define K2_SENSE_PRTDSI__CAPS_SEL       (* (reg8 *) K2_SENSE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define K2_SENSE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) K2_SENSE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define K2_SENSE_PRTDSI__OE_SEL0        (* (reg8 *) K2_SENSE__PRTDSI__OE_SEL0) 
#define K2_SENSE_PRTDSI__OE_SEL1        (* (reg8 *) K2_SENSE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define K2_SENSE_PRTDSI__OUT_SEL0       (* (reg8 *) K2_SENSE__PRTDSI__OUT_SEL0) 
#define K2_SENSE_PRTDSI__OUT_SEL1       (* (reg8 *) K2_SENSE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define K2_SENSE_PRTDSI__SYNC_OUT       (* (reg8 *) K2_SENSE__PRTDSI__SYNC_OUT) 


#if defined(K2_SENSE__INTSTAT)  /* Interrupt Registers */

    #define K2_SENSE_INTSTAT                (* (reg8 *) K2_SENSE__INTSTAT)
    #define K2_SENSE_SNAP                   (* (reg8 *) K2_SENSE__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins K2_SENSE_H */


/* [] END OF FILE */
