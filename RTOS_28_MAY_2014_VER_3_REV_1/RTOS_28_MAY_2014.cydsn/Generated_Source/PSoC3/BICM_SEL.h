/*******************************************************************************
* File Name: BICM_SEL.h  
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

#if !defined(CY_PINS_BICM_SEL_H) /* Pins BICM_SEL_H */
#define CY_PINS_BICM_SEL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BICM_SEL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BICM_SEL_Write(uint8 value) ;
void    BICM_SEL_SetDriveMode(uint8 mode) ;
uint8   BICM_SEL_ReadDataReg(void) ;
uint8   BICM_SEL_Read(void) ;
uint8   BICM_SEL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BICM_SEL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define BICM_SEL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define BICM_SEL_DM_RES_UP          PIN_DM_RES_UP
#define BICM_SEL_DM_RES_DWN         PIN_DM_RES_DWN
#define BICM_SEL_DM_OD_LO           PIN_DM_OD_LO
#define BICM_SEL_DM_OD_HI           PIN_DM_OD_HI
#define BICM_SEL_DM_STRONG          PIN_DM_STRONG
#define BICM_SEL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define BICM_SEL_MASK               BICM_SEL__MASK
#define BICM_SEL_SHIFT              BICM_SEL__SHIFT
#define BICM_SEL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BICM_SEL_PS                     (* (reg8 *) BICM_SEL__PS)
/* Data Register */
#define BICM_SEL_DR                     (* (reg8 *) BICM_SEL__DR)
/* Port Number */
#define BICM_SEL_PRT_NUM                (* (reg8 *) BICM_SEL__PRT) 
/* Connect to Analog Globals */                                                  
#define BICM_SEL_AG                     (* (reg8 *) BICM_SEL__AG)                       
/* Analog MUX bux enable */
#define BICM_SEL_AMUX                   (* (reg8 *) BICM_SEL__AMUX) 
/* Bidirectional Enable */                                                        
#define BICM_SEL_BIE                    (* (reg8 *) BICM_SEL__BIE)
/* Bit-mask for Aliased Register Access */
#define BICM_SEL_BIT_MASK               (* (reg8 *) BICM_SEL__BIT_MASK)
/* Bypass Enable */
#define BICM_SEL_BYP                    (* (reg8 *) BICM_SEL__BYP)
/* Port wide control signals */                                                   
#define BICM_SEL_CTL                    (* (reg8 *) BICM_SEL__CTL)
/* Drive Modes */
#define BICM_SEL_DM0                    (* (reg8 *) BICM_SEL__DM0) 
#define BICM_SEL_DM1                    (* (reg8 *) BICM_SEL__DM1)
#define BICM_SEL_DM2                    (* (reg8 *) BICM_SEL__DM2) 
/* Input Buffer Disable Override */
#define BICM_SEL_INP_DIS                (* (reg8 *) BICM_SEL__INP_DIS)
/* LCD Common or Segment Drive */
#define BICM_SEL_LCD_COM_SEG            (* (reg8 *) BICM_SEL__LCD_COM_SEG)
/* Enable Segment LCD */
#define BICM_SEL_LCD_EN                 (* (reg8 *) BICM_SEL__LCD_EN)
/* Slew Rate Control */
#define BICM_SEL_SLW                    (* (reg8 *) BICM_SEL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BICM_SEL_PRTDSI__CAPS_SEL       (* (reg8 *) BICM_SEL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BICM_SEL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BICM_SEL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BICM_SEL_PRTDSI__OE_SEL0        (* (reg8 *) BICM_SEL__PRTDSI__OE_SEL0) 
#define BICM_SEL_PRTDSI__OE_SEL1        (* (reg8 *) BICM_SEL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BICM_SEL_PRTDSI__OUT_SEL0       (* (reg8 *) BICM_SEL__PRTDSI__OUT_SEL0) 
#define BICM_SEL_PRTDSI__OUT_SEL1       (* (reg8 *) BICM_SEL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BICM_SEL_PRTDSI__SYNC_OUT       (* (reg8 *) BICM_SEL__PRTDSI__SYNC_OUT) 


#if defined(BICM_SEL__INTSTAT)  /* Interrupt Registers */

    #define BICM_SEL_INTSTAT                (* (reg8 *) BICM_SEL__INTSTAT)
    #define BICM_SEL_SNAP                   (* (reg8 *) BICM_SEL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins BICM_SEL_H */


/* [] END OF FILE */
