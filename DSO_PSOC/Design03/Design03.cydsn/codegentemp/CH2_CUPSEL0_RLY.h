/*******************************************************************************
* File Name: CH2_CUPSEL0_RLY.h  
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

#if !defined(CY_PINS_CH2_CUPSEL0_RLY_H) /* Pins CH2_CUPSEL0_RLY_H */
#define CY_PINS_CH2_CUPSEL0_RLY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CH2_CUPSEL0_RLY_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    CH2_CUPSEL0_RLY_Write(uint8 value) ;
void    CH2_CUPSEL0_RLY_SetDriveMode(uint8 mode) ;
uint8   CH2_CUPSEL0_RLY_ReadDataReg(void) ;
uint8   CH2_CUPSEL0_RLY_Read(void) ;
uint8   CH2_CUPSEL0_RLY_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CH2_CUPSEL0_RLY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CH2_CUPSEL0_RLY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CH2_CUPSEL0_RLY_DM_RES_UP          PIN_DM_RES_UP
#define CH2_CUPSEL0_RLY_DM_RES_DWN         PIN_DM_RES_DWN
#define CH2_CUPSEL0_RLY_DM_OD_LO           PIN_DM_OD_LO
#define CH2_CUPSEL0_RLY_DM_OD_HI           PIN_DM_OD_HI
#define CH2_CUPSEL0_RLY_DM_STRONG          PIN_DM_STRONG
#define CH2_CUPSEL0_RLY_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CH2_CUPSEL0_RLY_MASK               CH2_CUPSEL0_RLY__MASK
#define CH2_CUPSEL0_RLY_SHIFT              CH2_CUPSEL0_RLY__SHIFT
#define CH2_CUPSEL0_RLY_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CH2_CUPSEL0_RLY_PS                     (* (reg8 *) CH2_CUPSEL0_RLY__PS)
/* Data Register */
#define CH2_CUPSEL0_RLY_DR                     (* (reg8 *) CH2_CUPSEL0_RLY__DR)
/* Port Number */
#define CH2_CUPSEL0_RLY_PRT_NUM                (* (reg8 *) CH2_CUPSEL0_RLY__PRT) 
/* Connect to Analog Globals */                                                  
#define CH2_CUPSEL0_RLY_AG                     (* (reg8 *) CH2_CUPSEL0_RLY__AG)                       
/* Analog MUX bux enable */
#define CH2_CUPSEL0_RLY_AMUX                   (* (reg8 *) CH2_CUPSEL0_RLY__AMUX) 
/* Bidirectional Enable */                                                        
#define CH2_CUPSEL0_RLY_BIE                    (* (reg8 *) CH2_CUPSEL0_RLY__BIE)
/* Bit-mask for Aliased Register Access */
#define CH2_CUPSEL0_RLY_BIT_MASK               (* (reg8 *) CH2_CUPSEL0_RLY__BIT_MASK)
/* Bypass Enable */
#define CH2_CUPSEL0_RLY_BYP                    (* (reg8 *) CH2_CUPSEL0_RLY__BYP)
/* Port wide control signals */                                                   
#define CH2_CUPSEL0_RLY_CTL                    (* (reg8 *) CH2_CUPSEL0_RLY__CTL)
/* Drive Modes */
#define CH2_CUPSEL0_RLY_DM0                    (* (reg8 *) CH2_CUPSEL0_RLY__DM0) 
#define CH2_CUPSEL0_RLY_DM1                    (* (reg8 *) CH2_CUPSEL0_RLY__DM1)
#define CH2_CUPSEL0_RLY_DM2                    (* (reg8 *) CH2_CUPSEL0_RLY__DM2) 
/* Input Buffer Disable Override */
#define CH2_CUPSEL0_RLY_INP_DIS                (* (reg8 *) CH2_CUPSEL0_RLY__INP_DIS)
/* LCD Common or Segment Drive */
#define CH2_CUPSEL0_RLY_LCD_COM_SEG            (* (reg8 *) CH2_CUPSEL0_RLY__LCD_COM_SEG)
/* Enable Segment LCD */
#define CH2_CUPSEL0_RLY_LCD_EN                 (* (reg8 *) CH2_CUPSEL0_RLY__LCD_EN)
/* Slew Rate Control */
#define CH2_CUPSEL0_RLY_SLW                    (* (reg8 *) CH2_CUPSEL0_RLY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CH2_CUPSEL0_RLY_PRTDSI__CAPS_SEL       (* (reg8 *) CH2_CUPSEL0_RLY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CH2_CUPSEL0_RLY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CH2_CUPSEL0_RLY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CH2_CUPSEL0_RLY_PRTDSI__OE_SEL0        (* (reg8 *) CH2_CUPSEL0_RLY__PRTDSI__OE_SEL0) 
#define CH2_CUPSEL0_RLY_PRTDSI__OE_SEL1        (* (reg8 *) CH2_CUPSEL0_RLY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CH2_CUPSEL0_RLY_PRTDSI__OUT_SEL0       (* (reg8 *) CH2_CUPSEL0_RLY__PRTDSI__OUT_SEL0) 
#define CH2_CUPSEL0_RLY_PRTDSI__OUT_SEL1       (* (reg8 *) CH2_CUPSEL0_RLY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CH2_CUPSEL0_RLY_PRTDSI__SYNC_OUT       (* (reg8 *) CH2_CUPSEL0_RLY__PRTDSI__SYNC_OUT) 


#if defined(CH2_CUPSEL0_RLY__INTSTAT)  /* Interrupt Registers */

    #define CH2_CUPSEL0_RLY_INTSTAT                (* (reg8 *) CH2_CUPSEL0_RLY__INTSTAT)
    #define CH2_CUPSEL0_RLY_SNAP                   (* (reg8 *) CH2_CUPSEL0_RLY__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins CH2_CUPSEL0_RLY_H */


/* [] END OF FILE */