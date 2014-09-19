/*******************************************************************************
* File Name: EMOSI.h  
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

#if !defined(CY_PINS_EMOSI_H) /* Pins EMOSI_H */
#define CY_PINS_EMOSI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EMOSI_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    EMOSI_Write(uint8 value) ;
void    EMOSI_SetDriveMode(uint8 mode) ;
uint8   EMOSI_ReadDataReg(void) ;
uint8   EMOSI_Read(void) ;
uint8   EMOSI_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EMOSI_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EMOSI_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EMOSI_DM_RES_UP          PIN_DM_RES_UP
#define EMOSI_DM_RES_DWN         PIN_DM_RES_DWN
#define EMOSI_DM_OD_LO           PIN_DM_OD_LO
#define EMOSI_DM_OD_HI           PIN_DM_OD_HI
#define EMOSI_DM_STRONG          PIN_DM_STRONG
#define EMOSI_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EMOSI_MASK               EMOSI__MASK
#define EMOSI_SHIFT              EMOSI__SHIFT
#define EMOSI_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EMOSI_PS                     (* (reg8 *) EMOSI__PS)
/* Data Register */
#define EMOSI_DR                     (* (reg8 *) EMOSI__DR)
/* Port Number */
#define EMOSI_PRT_NUM                (* (reg8 *) EMOSI__PRT) 
/* Connect to Analog Globals */                                                  
#define EMOSI_AG                     (* (reg8 *) EMOSI__AG)                       
/* Analog MUX bux enable */
#define EMOSI_AMUX                   (* (reg8 *) EMOSI__AMUX) 
/* Bidirectional Enable */                                                        
#define EMOSI_BIE                    (* (reg8 *) EMOSI__BIE)
/* Bit-mask for Aliased Register Access */
#define EMOSI_BIT_MASK               (* (reg8 *) EMOSI__BIT_MASK)
/* Bypass Enable */
#define EMOSI_BYP                    (* (reg8 *) EMOSI__BYP)
/* Port wide control signals */                                                   
#define EMOSI_CTL                    (* (reg8 *) EMOSI__CTL)
/* Drive Modes */
#define EMOSI_DM0                    (* (reg8 *) EMOSI__DM0) 
#define EMOSI_DM1                    (* (reg8 *) EMOSI__DM1)
#define EMOSI_DM2                    (* (reg8 *) EMOSI__DM2) 
/* Input Buffer Disable Override */
#define EMOSI_INP_DIS                (* (reg8 *) EMOSI__INP_DIS)
/* LCD Common or Segment Drive */
#define EMOSI_LCD_COM_SEG            (* (reg8 *) EMOSI__LCD_COM_SEG)
/* Enable Segment LCD */
#define EMOSI_LCD_EN                 (* (reg8 *) EMOSI__LCD_EN)
/* Slew Rate Control */
#define EMOSI_SLW                    (* (reg8 *) EMOSI__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EMOSI_PRTDSI__CAPS_SEL       (* (reg8 *) EMOSI__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EMOSI_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EMOSI__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EMOSI_PRTDSI__OE_SEL0        (* (reg8 *) EMOSI__PRTDSI__OE_SEL0) 
#define EMOSI_PRTDSI__OE_SEL1        (* (reg8 *) EMOSI__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EMOSI_PRTDSI__OUT_SEL0       (* (reg8 *) EMOSI__PRTDSI__OUT_SEL0) 
#define EMOSI_PRTDSI__OUT_SEL1       (* (reg8 *) EMOSI__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EMOSI_PRTDSI__SYNC_OUT       (* (reg8 *) EMOSI__PRTDSI__SYNC_OUT) 


#if defined(EMOSI__INTSTAT)  /* Interrupt Registers */

    #define EMOSI_INTSTAT                (* (reg8 *) EMOSI__INTSTAT)
    #define EMOSI_SNAP                   (* (reg8 *) EMOSI__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins EMOSI_H */


/* [] END OF FILE */
