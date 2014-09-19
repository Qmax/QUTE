/*******************************************************************************
* File Name: KEY.h  
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

#if !defined(CY_PINS_KEY_H) /* Pins KEY_H */
#define CY_PINS_KEY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KEY_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    KEY_Write(uint8 value) ;
void    KEY_SetDriveMode(uint8 mode) ;
uint8   KEY_ReadDataReg(void) ;
uint8   KEY_Read(void) ;
uint8   KEY_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KEY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define KEY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define KEY_DM_RES_UP          PIN_DM_RES_UP
#define KEY_DM_RES_DWN         PIN_DM_RES_DWN
#define KEY_DM_OD_LO           PIN_DM_OD_LO
#define KEY_DM_OD_HI           PIN_DM_OD_HI
#define KEY_DM_STRONG          PIN_DM_STRONG
#define KEY_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define KEY_MASK               KEY__MASK
#define KEY_SHIFT              KEY__SHIFT
#define KEY_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KEY_PS                     (* (reg8 *) KEY__PS)
/* Data Register */
#define KEY_DR                     (* (reg8 *) KEY__DR)
/* Port Number */
#define KEY_PRT_NUM                (* (reg8 *) KEY__PRT) 
/* Connect to Analog Globals */                                                  
#define KEY_AG                     (* (reg8 *) KEY__AG)                       
/* Analog MUX bux enable */
#define KEY_AMUX                   (* (reg8 *) KEY__AMUX) 
/* Bidirectional Enable */                                                        
#define KEY_BIE                    (* (reg8 *) KEY__BIE)
/* Bit-mask for Aliased Register Access */
#define KEY_BIT_MASK               (* (reg8 *) KEY__BIT_MASK)
/* Bypass Enable */
#define KEY_BYP                    (* (reg8 *) KEY__BYP)
/* Port wide control signals */                                                   
#define KEY_CTL                    (* (reg8 *) KEY__CTL)
/* Drive Modes */
#define KEY_DM0                    (* (reg8 *) KEY__DM0) 
#define KEY_DM1                    (* (reg8 *) KEY__DM1)
#define KEY_DM2                    (* (reg8 *) KEY__DM2) 
/* Input Buffer Disable Override */
#define KEY_INP_DIS                (* (reg8 *) KEY__INP_DIS)
/* LCD Common or Segment Drive */
#define KEY_LCD_COM_SEG            (* (reg8 *) KEY__LCD_COM_SEG)
/* Enable Segment LCD */
#define KEY_LCD_EN                 (* (reg8 *) KEY__LCD_EN)
/* Slew Rate Control */
#define KEY_SLW                    (* (reg8 *) KEY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KEY_PRTDSI__CAPS_SEL       (* (reg8 *) KEY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KEY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KEY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KEY_PRTDSI__OE_SEL0        (* (reg8 *) KEY__PRTDSI__OE_SEL0) 
#define KEY_PRTDSI__OE_SEL1        (* (reg8 *) KEY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KEY_PRTDSI__OUT_SEL0       (* (reg8 *) KEY__PRTDSI__OUT_SEL0) 
#define KEY_PRTDSI__OUT_SEL1       (* (reg8 *) KEY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KEY_PRTDSI__SYNC_OUT       (* (reg8 *) KEY__PRTDSI__SYNC_OUT) 


#if defined(KEY__INTSTAT)  /* Interrupt Registers */

    #define KEY_INTSTAT                (* (reg8 *) KEY__INTSTAT)
    #define KEY_SNAP                   (* (reg8 *) KEY__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins KEY_H */


/* [] END OF FILE */
