/*******************************************************************************
* File Name: CSN.h  
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

#if !defined(CY_PINS_CSN_H) /* Pins CSN_H */
#define CY_PINS_CSN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CSN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    CSN_Write(uint8 value) ;
void    CSN_SetDriveMode(uint8 mode) ;
uint8   CSN_ReadDataReg(void) ;
uint8   CSN_Read(void) ;
uint8   CSN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CSN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CSN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CSN_DM_RES_UP          PIN_DM_RES_UP
#define CSN_DM_RES_DWN         PIN_DM_RES_DWN
#define CSN_DM_OD_LO           PIN_DM_OD_LO
#define CSN_DM_OD_HI           PIN_DM_OD_HI
#define CSN_DM_STRONG          PIN_DM_STRONG
#define CSN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CSN_MASK               CSN__MASK
#define CSN_SHIFT              CSN__SHIFT
#define CSN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CSN_PS                     (* (reg8 *) CSN__PS)
/* Data Register */
#define CSN_DR                     (* (reg8 *) CSN__DR)
/* Port Number */
#define CSN_PRT_NUM                (* (reg8 *) CSN__PRT) 
/* Connect to Analog Globals */                                                  
#define CSN_AG                     (* (reg8 *) CSN__AG)                       
/* Analog MUX bux enable */
#define CSN_AMUX                   (* (reg8 *) CSN__AMUX) 
/* Bidirectional Enable */                                                        
#define CSN_BIE                    (* (reg8 *) CSN__BIE)
/* Bit-mask for Aliased Register Access */
#define CSN_BIT_MASK               (* (reg8 *) CSN__BIT_MASK)
/* Bypass Enable */
#define CSN_BYP                    (* (reg8 *) CSN__BYP)
/* Port wide control signals */                                                   
#define CSN_CTL                    (* (reg8 *) CSN__CTL)
/* Drive Modes */
#define CSN_DM0                    (* (reg8 *) CSN__DM0) 
#define CSN_DM1                    (* (reg8 *) CSN__DM1)
#define CSN_DM2                    (* (reg8 *) CSN__DM2) 
/* Input Buffer Disable Override */
#define CSN_INP_DIS                (* (reg8 *) CSN__INP_DIS)
/* LCD Common or Segment Drive */
#define CSN_LCD_COM_SEG            (* (reg8 *) CSN__LCD_COM_SEG)
/* Enable Segment LCD */
#define CSN_LCD_EN                 (* (reg8 *) CSN__LCD_EN)
/* Slew Rate Control */
#define CSN_SLW                    (* (reg8 *) CSN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CSN_PRTDSI__CAPS_SEL       (* (reg8 *) CSN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CSN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CSN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CSN_PRTDSI__OE_SEL0        (* (reg8 *) CSN__PRTDSI__OE_SEL0) 
#define CSN_PRTDSI__OE_SEL1        (* (reg8 *) CSN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CSN_PRTDSI__OUT_SEL0       (* (reg8 *) CSN__PRTDSI__OUT_SEL0) 
#define CSN_PRTDSI__OUT_SEL1       (* (reg8 *) CSN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CSN_PRTDSI__SYNC_OUT       (* (reg8 *) CSN__PRTDSI__SYNC_OUT) 


#if defined(CSN__INTSTAT)  /* Interrupt Registers */

    #define CSN_INTSTAT                (* (reg8 *) CSN__INTSTAT)
    #define CSN_SNAP                   (* (reg8 *) CSN__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins CSN_H */


/* [] END OF FILE */
