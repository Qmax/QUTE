/*******************************************************************************
* File Name: Key2_0.h  
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

#if !defined(CY_PINS_Key2_0_H) /* Pins Key2_0_H */
#define CY_PINS_Key2_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Key2_0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Key2_0_Write(uint8 value) ;
void    Key2_0_SetDriveMode(uint8 mode) ;
uint8   Key2_0_ReadDataReg(void) ;
uint8   Key2_0_Read(void) ;
uint8   Key2_0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Key2_0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Key2_0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Key2_0_DM_RES_UP          PIN_DM_RES_UP
#define Key2_0_DM_RES_DWN         PIN_DM_RES_DWN
#define Key2_0_DM_OD_LO           PIN_DM_OD_LO
#define Key2_0_DM_OD_HI           PIN_DM_OD_HI
#define Key2_0_DM_STRONG          PIN_DM_STRONG
#define Key2_0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Key2_0_MASK               Key2_0__MASK
#define Key2_0_SHIFT              Key2_0__SHIFT
#define Key2_0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Key2_0_PS                     (* (reg8 *) Key2_0__PS)
/* Data Register */
#define Key2_0_DR                     (* (reg8 *) Key2_0__DR)
/* Port Number */
#define Key2_0_PRT_NUM                (* (reg8 *) Key2_0__PRT) 
/* Connect to Analog Globals */                                                  
#define Key2_0_AG                     (* (reg8 *) Key2_0__AG)                       
/* Analog MUX bux enable */
#define Key2_0_AMUX                   (* (reg8 *) Key2_0__AMUX) 
/* Bidirectional Enable */                                                        
#define Key2_0_BIE                    (* (reg8 *) Key2_0__BIE)
/* Bit-mask for Aliased Register Access */
#define Key2_0_BIT_MASK               (* (reg8 *) Key2_0__BIT_MASK)
/* Bypass Enable */
#define Key2_0_BYP                    (* (reg8 *) Key2_0__BYP)
/* Port wide control signals */                                                   
#define Key2_0_CTL                    (* (reg8 *) Key2_0__CTL)
/* Drive Modes */
#define Key2_0_DM0                    (* (reg8 *) Key2_0__DM0) 
#define Key2_0_DM1                    (* (reg8 *) Key2_0__DM1)
#define Key2_0_DM2                    (* (reg8 *) Key2_0__DM2) 
/* Input Buffer Disable Override */
#define Key2_0_INP_DIS                (* (reg8 *) Key2_0__INP_DIS)
/* LCD Common or Segment Drive */
#define Key2_0_LCD_COM_SEG            (* (reg8 *) Key2_0__LCD_COM_SEG)
/* Enable Segment LCD */
#define Key2_0_LCD_EN                 (* (reg8 *) Key2_0__LCD_EN)
/* Slew Rate Control */
#define Key2_0_SLW                    (* (reg8 *) Key2_0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Key2_0_PRTDSI__CAPS_SEL       (* (reg8 *) Key2_0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Key2_0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Key2_0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Key2_0_PRTDSI__OE_SEL0        (* (reg8 *) Key2_0__PRTDSI__OE_SEL0) 
#define Key2_0_PRTDSI__OE_SEL1        (* (reg8 *) Key2_0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Key2_0_PRTDSI__OUT_SEL0       (* (reg8 *) Key2_0__PRTDSI__OUT_SEL0) 
#define Key2_0_PRTDSI__OUT_SEL1       (* (reg8 *) Key2_0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Key2_0_PRTDSI__SYNC_OUT       (* (reg8 *) Key2_0__PRTDSI__SYNC_OUT) 


#if defined(Key2_0__INTSTAT)  /* Interrupt Registers */

    #define Key2_0_INTSTAT                (* (reg8 *) Key2_0__INTSTAT)
    #define Key2_0_SNAP                   (* (reg8 *) Key2_0__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Key2_0_H */


/* [] END OF FILE */
