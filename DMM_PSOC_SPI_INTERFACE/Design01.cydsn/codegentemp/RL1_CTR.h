/*******************************************************************************
* File Name: RL1_CTR.h  
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

#if !defined(CY_PINS_RL1_CTR_H) /* Pins RL1_CTR_H */
#define CY_PINS_RL1_CTR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RL1_CTR_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RL1_CTR_Write(uint8 value) ;
void    RL1_CTR_SetDriveMode(uint8 mode) ;
uint8   RL1_CTR_ReadDataReg(void) ;
uint8   RL1_CTR_Read(void) ;
uint8   RL1_CTR_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RL1_CTR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RL1_CTR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RL1_CTR_DM_RES_UP          PIN_DM_RES_UP
#define RL1_CTR_DM_RES_DWN         PIN_DM_RES_DWN
#define RL1_CTR_DM_OD_LO           PIN_DM_OD_LO
#define RL1_CTR_DM_OD_HI           PIN_DM_OD_HI
#define RL1_CTR_DM_STRONG          PIN_DM_STRONG
#define RL1_CTR_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RL1_CTR_MASK               RL1_CTR__MASK
#define RL1_CTR_SHIFT              RL1_CTR__SHIFT
#define RL1_CTR_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RL1_CTR_PS                     (* (reg8 *) RL1_CTR__PS)
/* Data Register */
#define RL1_CTR_DR                     (* (reg8 *) RL1_CTR__DR)
/* Port Number */
#define RL1_CTR_PRT_NUM                (* (reg8 *) RL1_CTR__PRT) 
/* Connect to Analog Globals */                                                  
#define RL1_CTR_AG                     (* (reg8 *) RL1_CTR__AG)                       
/* Analog MUX bux enable */
#define RL1_CTR_AMUX                   (* (reg8 *) RL1_CTR__AMUX) 
/* Bidirectional Enable */                                                        
#define RL1_CTR_BIE                    (* (reg8 *) RL1_CTR__BIE)
/* Bit-mask for Aliased Register Access */
#define RL1_CTR_BIT_MASK               (* (reg8 *) RL1_CTR__BIT_MASK)
/* Bypass Enable */
#define RL1_CTR_BYP                    (* (reg8 *) RL1_CTR__BYP)
/* Port wide control signals */                                                   
#define RL1_CTR_CTL                    (* (reg8 *) RL1_CTR__CTL)
/* Drive Modes */
#define RL1_CTR_DM0                    (* (reg8 *) RL1_CTR__DM0) 
#define RL1_CTR_DM1                    (* (reg8 *) RL1_CTR__DM1)
#define RL1_CTR_DM2                    (* (reg8 *) RL1_CTR__DM2) 
/* Input Buffer Disable Override */
#define RL1_CTR_INP_DIS                (* (reg8 *) RL1_CTR__INP_DIS)
/* LCD Common or Segment Drive */
#define RL1_CTR_LCD_COM_SEG            (* (reg8 *) RL1_CTR__LCD_COM_SEG)
/* Enable Segment LCD */
#define RL1_CTR_LCD_EN                 (* (reg8 *) RL1_CTR__LCD_EN)
/* Slew Rate Control */
#define RL1_CTR_SLW                    (* (reg8 *) RL1_CTR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RL1_CTR_PRTDSI__CAPS_SEL       (* (reg8 *) RL1_CTR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RL1_CTR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RL1_CTR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RL1_CTR_PRTDSI__OE_SEL0        (* (reg8 *) RL1_CTR__PRTDSI__OE_SEL0) 
#define RL1_CTR_PRTDSI__OE_SEL1        (* (reg8 *) RL1_CTR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RL1_CTR_PRTDSI__OUT_SEL0       (* (reg8 *) RL1_CTR__PRTDSI__OUT_SEL0) 
#define RL1_CTR_PRTDSI__OUT_SEL1       (* (reg8 *) RL1_CTR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RL1_CTR_PRTDSI__SYNC_OUT       (* (reg8 *) RL1_CTR__PRTDSI__SYNC_OUT) 


#if defined(RL1_CTR__INTSTAT)  /* Interrupt Registers */

    #define RL1_CTR_INTSTAT                (* (reg8 *) RL1_CTR__INTSTAT)
    #define RL1_CTR_SNAP                   (* (reg8 *) RL1_CTR__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins RL1_CTR_H */


/* [] END OF FILE */
