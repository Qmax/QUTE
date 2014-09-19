/*******************************************************************************
* File Name: SRC_0.h  
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

#if !defined(CY_PINS_SRC_0_H) /* Pins SRC_0_H */
#define CY_PINS_SRC_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SRC_0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SRC_0_Write(uint8 value) ;
void    SRC_0_SetDriveMode(uint8 mode) ;
uint8   SRC_0_ReadDataReg(void) ;
uint8   SRC_0_Read(void) ;
uint8   SRC_0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SRC_0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SRC_0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SRC_0_DM_RES_UP          PIN_DM_RES_UP
#define SRC_0_DM_RES_DWN         PIN_DM_RES_DWN
#define SRC_0_DM_OD_LO           PIN_DM_OD_LO
#define SRC_0_DM_OD_HI           PIN_DM_OD_HI
#define SRC_0_DM_STRONG          PIN_DM_STRONG
#define SRC_0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SRC_0_MASK               SRC_0__MASK
#define SRC_0_SHIFT              SRC_0__SHIFT
#define SRC_0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SRC_0_PS                     (* (reg8 *) SRC_0__PS)
/* Data Register */
#define SRC_0_DR                     (* (reg8 *) SRC_0__DR)
/* Port Number */
#define SRC_0_PRT_NUM                (* (reg8 *) SRC_0__PRT) 
/* Connect to Analog Globals */                                                  
#define SRC_0_AG                     (* (reg8 *) SRC_0__AG)                       
/* Analog MUX bux enable */
#define SRC_0_AMUX                   (* (reg8 *) SRC_0__AMUX) 
/* Bidirectional Enable */                                                        
#define SRC_0_BIE                    (* (reg8 *) SRC_0__BIE)
/* Bit-mask for Aliased Register Access */
#define SRC_0_BIT_MASK               (* (reg8 *) SRC_0__BIT_MASK)
/* Bypass Enable */
#define SRC_0_BYP                    (* (reg8 *) SRC_0__BYP)
/* Port wide control signals */                                                   
#define SRC_0_CTL                    (* (reg8 *) SRC_0__CTL)
/* Drive Modes */
#define SRC_0_DM0                    (* (reg8 *) SRC_0__DM0) 
#define SRC_0_DM1                    (* (reg8 *) SRC_0__DM1)
#define SRC_0_DM2                    (* (reg8 *) SRC_0__DM2) 
/* Input Buffer Disable Override */
#define SRC_0_INP_DIS                (* (reg8 *) SRC_0__INP_DIS)
/* LCD Common or Segment Drive */
#define SRC_0_LCD_COM_SEG            (* (reg8 *) SRC_0__LCD_COM_SEG)
/* Enable Segment LCD */
#define SRC_0_LCD_EN                 (* (reg8 *) SRC_0__LCD_EN)
/* Slew Rate Control */
#define SRC_0_SLW                    (* (reg8 *) SRC_0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SRC_0_PRTDSI__CAPS_SEL       (* (reg8 *) SRC_0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SRC_0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SRC_0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SRC_0_PRTDSI__OE_SEL0        (* (reg8 *) SRC_0__PRTDSI__OE_SEL0) 
#define SRC_0_PRTDSI__OE_SEL1        (* (reg8 *) SRC_0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SRC_0_PRTDSI__OUT_SEL0       (* (reg8 *) SRC_0__PRTDSI__OUT_SEL0) 
#define SRC_0_PRTDSI__OUT_SEL1       (* (reg8 *) SRC_0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SRC_0_PRTDSI__SYNC_OUT       (* (reg8 *) SRC_0__PRTDSI__SYNC_OUT) 


#if defined(SRC_0__INTSTAT)  /* Interrupt Registers */

    #define SRC_0_INTSTAT                (* (reg8 *) SRC_0__INTSTAT)
    #define SRC_0_SNAP                   (* (reg8 *) SRC_0__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins SRC_0_H */


/* [] END OF FILE */
