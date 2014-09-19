/*******************************************************************************
* File Name: RL5_CTR.h  
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

#if !defined(CY_PINS_RL5_CTR_H) /* Pins RL5_CTR_H */
#define CY_PINS_RL5_CTR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RL5_CTR_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RL5_CTR_Write(uint8 value) ;
void    RL5_CTR_SetDriveMode(uint8 mode) ;
uint8   RL5_CTR_ReadDataReg(void) ;
uint8   RL5_CTR_Read(void) ;
uint8   RL5_CTR_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RL5_CTR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RL5_CTR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RL5_CTR_DM_RES_UP          PIN_DM_RES_UP
#define RL5_CTR_DM_RES_DWN         PIN_DM_RES_DWN
#define RL5_CTR_DM_OD_LO           PIN_DM_OD_LO
#define RL5_CTR_DM_OD_HI           PIN_DM_OD_HI
#define RL5_CTR_DM_STRONG          PIN_DM_STRONG
#define RL5_CTR_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RL5_CTR_MASK               RL5_CTR__MASK
#define RL5_CTR_SHIFT              RL5_CTR__SHIFT
#define RL5_CTR_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RL5_CTR_PS                     (* (reg8 *) RL5_CTR__PS)
/* Data Register */
#define RL5_CTR_DR                     (* (reg8 *) RL5_CTR__DR)
/* Port Number */
#define RL5_CTR_PRT_NUM                (* (reg8 *) RL5_CTR__PRT) 
/* Connect to Analog Globals */                                                  
#define RL5_CTR_AG                     (* (reg8 *) RL5_CTR__AG)                       
/* Analog MUX bux enable */
#define RL5_CTR_AMUX                   (* (reg8 *) RL5_CTR__AMUX) 
/* Bidirectional Enable */                                                        
#define RL5_CTR_BIE                    (* (reg8 *) RL5_CTR__BIE)
/* Bit-mask for Aliased Register Access */
#define RL5_CTR_BIT_MASK               (* (reg8 *) RL5_CTR__BIT_MASK)
/* Bypass Enable */
#define RL5_CTR_BYP                    (* (reg8 *) RL5_CTR__BYP)
/* Port wide control signals */                                                   
#define RL5_CTR_CTL                    (* (reg8 *) RL5_CTR__CTL)
/* Drive Modes */
#define RL5_CTR_DM0                    (* (reg8 *) RL5_CTR__DM0) 
#define RL5_CTR_DM1                    (* (reg8 *) RL5_CTR__DM1)
#define RL5_CTR_DM2                    (* (reg8 *) RL5_CTR__DM2) 
/* Input Buffer Disable Override */
#define RL5_CTR_INP_DIS                (* (reg8 *) RL5_CTR__INP_DIS)
/* LCD Common or Segment Drive */
#define RL5_CTR_LCD_COM_SEG            (* (reg8 *) RL5_CTR__LCD_COM_SEG)
/* Enable Segment LCD */
#define RL5_CTR_LCD_EN                 (* (reg8 *) RL5_CTR__LCD_EN)
/* Slew Rate Control */
#define RL5_CTR_SLW                    (* (reg8 *) RL5_CTR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RL5_CTR_PRTDSI__CAPS_SEL       (* (reg8 *) RL5_CTR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RL5_CTR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RL5_CTR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RL5_CTR_PRTDSI__OE_SEL0        (* (reg8 *) RL5_CTR__PRTDSI__OE_SEL0) 
#define RL5_CTR_PRTDSI__OE_SEL1        (* (reg8 *) RL5_CTR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RL5_CTR_PRTDSI__OUT_SEL0       (* (reg8 *) RL5_CTR__PRTDSI__OUT_SEL0) 
#define RL5_CTR_PRTDSI__OUT_SEL1       (* (reg8 *) RL5_CTR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RL5_CTR_PRTDSI__SYNC_OUT       (* (reg8 *) RL5_CTR__PRTDSI__SYNC_OUT) 


#if defined(RL5_CTR__INTSTAT)  /* Interrupt Registers */

    #define RL5_CTR_INTSTAT                (* (reg8 *) RL5_CTR__INTSTAT)
    #define RL5_CTR_SNAP                   (* (reg8 *) RL5_CTR__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins RL5_CTR_H */


/* [] END OF FILE */
