/*******************************************************************************
* File Name: SRC_3.h  
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

#if !defined(CY_PINS_SRC_3_H) /* Pins SRC_3_H */
#define CY_PINS_SRC_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SRC_3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SRC_3_Write(uint8 value) ;
void    SRC_3_SetDriveMode(uint8 mode) ;
uint8   SRC_3_ReadDataReg(void) ;
uint8   SRC_3_Read(void) ;
uint8   SRC_3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SRC_3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SRC_3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SRC_3_DM_RES_UP          PIN_DM_RES_UP
#define SRC_3_DM_RES_DWN         PIN_DM_RES_DWN
#define SRC_3_DM_OD_LO           PIN_DM_OD_LO
#define SRC_3_DM_OD_HI           PIN_DM_OD_HI
#define SRC_3_DM_STRONG          PIN_DM_STRONG
#define SRC_3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SRC_3_MASK               SRC_3__MASK
#define SRC_3_SHIFT              SRC_3__SHIFT
#define SRC_3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SRC_3_PS                     (* (reg8 *) SRC_3__PS)
/* Data Register */
#define SRC_3_DR                     (* (reg8 *) SRC_3__DR)
/* Port Number */
#define SRC_3_PRT_NUM                (* (reg8 *) SRC_3__PRT) 
/* Connect to Analog Globals */                                                  
#define SRC_3_AG                     (* (reg8 *) SRC_3__AG)                       
/* Analog MUX bux enable */
#define SRC_3_AMUX                   (* (reg8 *) SRC_3__AMUX) 
/* Bidirectional Enable */                                                        
#define SRC_3_BIE                    (* (reg8 *) SRC_3__BIE)
/* Bit-mask for Aliased Register Access */
#define SRC_3_BIT_MASK               (* (reg8 *) SRC_3__BIT_MASK)
/* Bypass Enable */
#define SRC_3_BYP                    (* (reg8 *) SRC_3__BYP)
/* Port wide control signals */                                                   
#define SRC_3_CTL                    (* (reg8 *) SRC_3__CTL)
/* Drive Modes */
#define SRC_3_DM0                    (* (reg8 *) SRC_3__DM0) 
#define SRC_3_DM1                    (* (reg8 *) SRC_3__DM1)
#define SRC_3_DM2                    (* (reg8 *) SRC_3__DM2) 
/* Input Buffer Disable Override */
#define SRC_3_INP_DIS                (* (reg8 *) SRC_3__INP_DIS)
/* LCD Common or Segment Drive */
#define SRC_3_LCD_COM_SEG            (* (reg8 *) SRC_3__LCD_COM_SEG)
/* Enable Segment LCD */
#define SRC_3_LCD_EN                 (* (reg8 *) SRC_3__LCD_EN)
/* Slew Rate Control */
#define SRC_3_SLW                    (* (reg8 *) SRC_3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SRC_3_PRTDSI__CAPS_SEL       (* (reg8 *) SRC_3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SRC_3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SRC_3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SRC_3_PRTDSI__OE_SEL0        (* (reg8 *) SRC_3__PRTDSI__OE_SEL0) 
#define SRC_3_PRTDSI__OE_SEL1        (* (reg8 *) SRC_3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SRC_3_PRTDSI__OUT_SEL0       (* (reg8 *) SRC_3__PRTDSI__OUT_SEL0) 
#define SRC_3_PRTDSI__OUT_SEL1       (* (reg8 *) SRC_3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SRC_3_PRTDSI__SYNC_OUT       (* (reg8 *) SRC_3__PRTDSI__SYNC_OUT) 


#if defined(SRC_3__INTSTAT)  /* Interrupt Registers */

    #define SRC_3_INTSTAT                (* (reg8 *) SRC_3__INTSTAT)
    #define SRC_3_SNAP                   (* (reg8 *) SRC_3__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins SRC_3_H */


/* [] END OF FILE */
