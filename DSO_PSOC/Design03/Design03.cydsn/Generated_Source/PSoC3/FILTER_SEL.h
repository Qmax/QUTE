/*******************************************************************************
* File Name: FILTER_SEL.h  
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

#if !defined(CY_PINS_FILTER_SEL_H) /* Pins FILTER_SEL_H */
#define CY_PINS_FILTER_SEL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FILTER_SEL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    FILTER_SEL_Write(uint8 value) ;
void    FILTER_SEL_SetDriveMode(uint8 mode) ;
uint8   FILTER_SEL_ReadDataReg(void) ;
uint8   FILTER_SEL_Read(void) ;
uint8   FILTER_SEL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define FILTER_SEL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define FILTER_SEL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define FILTER_SEL_DM_RES_UP          PIN_DM_RES_UP
#define FILTER_SEL_DM_RES_DWN         PIN_DM_RES_DWN
#define FILTER_SEL_DM_OD_LO           PIN_DM_OD_LO
#define FILTER_SEL_DM_OD_HI           PIN_DM_OD_HI
#define FILTER_SEL_DM_STRONG          PIN_DM_STRONG
#define FILTER_SEL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define FILTER_SEL_MASK               FILTER_SEL__MASK
#define FILTER_SEL_SHIFT              FILTER_SEL__SHIFT
#define FILTER_SEL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FILTER_SEL_PS                     (* (reg8 *) FILTER_SEL__PS)
/* Data Register */
#define FILTER_SEL_DR                     (* (reg8 *) FILTER_SEL__DR)
/* Port Number */
#define FILTER_SEL_PRT_NUM                (* (reg8 *) FILTER_SEL__PRT) 
/* Connect to Analog Globals */                                                  
#define FILTER_SEL_AG                     (* (reg8 *) FILTER_SEL__AG)                       
/* Analog MUX bux enable */
#define FILTER_SEL_AMUX                   (* (reg8 *) FILTER_SEL__AMUX) 
/* Bidirectional Enable */                                                        
#define FILTER_SEL_BIE                    (* (reg8 *) FILTER_SEL__BIE)
/* Bit-mask for Aliased Register Access */
#define FILTER_SEL_BIT_MASK               (* (reg8 *) FILTER_SEL__BIT_MASK)
/* Bypass Enable */
#define FILTER_SEL_BYP                    (* (reg8 *) FILTER_SEL__BYP)
/* Port wide control signals */                                                   
#define FILTER_SEL_CTL                    (* (reg8 *) FILTER_SEL__CTL)
/* Drive Modes */
#define FILTER_SEL_DM0                    (* (reg8 *) FILTER_SEL__DM0) 
#define FILTER_SEL_DM1                    (* (reg8 *) FILTER_SEL__DM1)
#define FILTER_SEL_DM2                    (* (reg8 *) FILTER_SEL__DM2) 
/* Input Buffer Disable Override */
#define FILTER_SEL_INP_DIS                (* (reg8 *) FILTER_SEL__INP_DIS)
/* LCD Common or Segment Drive */
#define FILTER_SEL_LCD_COM_SEG            (* (reg8 *) FILTER_SEL__LCD_COM_SEG)
/* Enable Segment LCD */
#define FILTER_SEL_LCD_EN                 (* (reg8 *) FILTER_SEL__LCD_EN)
/* Slew Rate Control */
#define FILTER_SEL_SLW                    (* (reg8 *) FILTER_SEL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FILTER_SEL_PRTDSI__CAPS_SEL       (* (reg8 *) FILTER_SEL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FILTER_SEL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FILTER_SEL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FILTER_SEL_PRTDSI__OE_SEL0        (* (reg8 *) FILTER_SEL__PRTDSI__OE_SEL0) 
#define FILTER_SEL_PRTDSI__OE_SEL1        (* (reg8 *) FILTER_SEL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FILTER_SEL_PRTDSI__OUT_SEL0       (* (reg8 *) FILTER_SEL__PRTDSI__OUT_SEL0) 
#define FILTER_SEL_PRTDSI__OUT_SEL1       (* (reg8 *) FILTER_SEL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FILTER_SEL_PRTDSI__SYNC_OUT       (* (reg8 *) FILTER_SEL__PRTDSI__SYNC_OUT) 


#if defined(FILTER_SEL__INTSTAT)  /* Interrupt Registers */

    #define FILTER_SEL_INTSTAT                (* (reg8 *) FILTER_SEL__INTSTAT)
    #define FILTER_SEL_SNAP                   (* (reg8 *) FILTER_SEL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins FILTER_SEL_H */


/* [] END OF FILE */
