/*******************************************************************************
* File Name: BCH2_DIV1_RLY.h  
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

#if !defined(CY_PINS_BCH2_DIV1_RLY_H) /* Pins BCH2_DIV1_RLY_H */
#define CY_PINS_BCH2_DIV1_RLY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BCH2_DIV1_RLY_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BCH2_DIV1_RLY_Write(uint8 value) ;
void    BCH2_DIV1_RLY_SetDriveMode(uint8 mode) ;
uint8   BCH2_DIV1_RLY_ReadDataReg(void) ;
uint8   BCH2_DIV1_RLY_Read(void) ;
uint8   BCH2_DIV1_RLY_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BCH2_DIV1_RLY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define BCH2_DIV1_RLY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define BCH2_DIV1_RLY_DM_RES_UP          PIN_DM_RES_UP
#define BCH2_DIV1_RLY_DM_RES_DWN         PIN_DM_RES_DWN
#define BCH2_DIV1_RLY_DM_OD_LO           PIN_DM_OD_LO
#define BCH2_DIV1_RLY_DM_OD_HI           PIN_DM_OD_HI
#define BCH2_DIV1_RLY_DM_STRONG          PIN_DM_STRONG
#define BCH2_DIV1_RLY_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define BCH2_DIV1_RLY_MASK               BCH2_DIV1_RLY__MASK
#define BCH2_DIV1_RLY_SHIFT              BCH2_DIV1_RLY__SHIFT
#define BCH2_DIV1_RLY_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BCH2_DIV1_RLY_PS                     (* (reg8 *) BCH2_DIV1_RLY__PS)
/* Data Register */
#define BCH2_DIV1_RLY_DR                     (* (reg8 *) BCH2_DIV1_RLY__DR)
/* Port Number */
#define BCH2_DIV1_RLY_PRT_NUM                (* (reg8 *) BCH2_DIV1_RLY__PRT) 
/* Connect to Analog Globals */                                                  
#define BCH2_DIV1_RLY_AG                     (* (reg8 *) BCH2_DIV1_RLY__AG)                       
/* Analog MUX bux enable */
#define BCH2_DIV1_RLY_AMUX                   (* (reg8 *) BCH2_DIV1_RLY__AMUX) 
/* Bidirectional Enable */                                                        
#define BCH2_DIV1_RLY_BIE                    (* (reg8 *) BCH2_DIV1_RLY__BIE)
/* Bit-mask for Aliased Register Access */
#define BCH2_DIV1_RLY_BIT_MASK               (* (reg8 *) BCH2_DIV1_RLY__BIT_MASK)
/* Bypass Enable */
#define BCH2_DIV1_RLY_BYP                    (* (reg8 *) BCH2_DIV1_RLY__BYP)
/* Port wide control signals */                                                   
#define BCH2_DIV1_RLY_CTL                    (* (reg8 *) BCH2_DIV1_RLY__CTL)
/* Drive Modes */
#define BCH2_DIV1_RLY_DM0                    (* (reg8 *) BCH2_DIV1_RLY__DM0) 
#define BCH2_DIV1_RLY_DM1                    (* (reg8 *) BCH2_DIV1_RLY__DM1)
#define BCH2_DIV1_RLY_DM2                    (* (reg8 *) BCH2_DIV1_RLY__DM2) 
/* Input Buffer Disable Override */
#define BCH2_DIV1_RLY_INP_DIS                (* (reg8 *) BCH2_DIV1_RLY__INP_DIS)
/* LCD Common or Segment Drive */
#define BCH2_DIV1_RLY_LCD_COM_SEG            (* (reg8 *) BCH2_DIV1_RLY__LCD_COM_SEG)
/* Enable Segment LCD */
#define BCH2_DIV1_RLY_LCD_EN                 (* (reg8 *) BCH2_DIV1_RLY__LCD_EN)
/* Slew Rate Control */
#define BCH2_DIV1_RLY_SLW                    (* (reg8 *) BCH2_DIV1_RLY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BCH2_DIV1_RLY_PRTDSI__CAPS_SEL       (* (reg8 *) BCH2_DIV1_RLY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BCH2_DIV1_RLY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BCH2_DIV1_RLY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BCH2_DIV1_RLY_PRTDSI__OE_SEL0        (* (reg8 *) BCH2_DIV1_RLY__PRTDSI__OE_SEL0) 
#define BCH2_DIV1_RLY_PRTDSI__OE_SEL1        (* (reg8 *) BCH2_DIV1_RLY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BCH2_DIV1_RLY_PRTDSI__OUT_SEL0       (* (reg8 *) BCH2_DIV1_RLY__PRTDSI__OUT_SEL0) 
#define BCH2_DIV1_RLY_PRTDSI__OUT_SEL1       (* (reg8 *) BCH2_DIV1_RLY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BCH2_DIV1_RLY_PRTDSI__SYNC_OUT       (* (reg8 *) BCH2_DIV1_RLY__PRTDSI__SYNC_OUT) 


#if defined(BCH2_DIV1_RLY__INTSTAT)  /* Interrupt Registers */

    #define BCH2_DIV1_RLY_INTSTAT                (* (reg8 *) BCH2_DIV1_RLY__INTSTAT)
    #define BCH2_DIV1_RLY_SNAP                   (* (reg8 *) BCH2_DIV1_RLY__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins BCH2_DIV1_RLY_H */


/* [] END OF FILE */
