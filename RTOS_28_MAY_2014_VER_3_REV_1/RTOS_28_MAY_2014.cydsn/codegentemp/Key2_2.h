/*******************************************************************************
* File Name: Key2_2.h  
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

#if !defined(CY_PINS_Key2_2_H) /* Pins Key2_2_H */
#define CY_PINS_Key2_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Key2_2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Key2_2_Write(uint8 value) ;
void    Key2_2_SetDriveMode(uint8 mode) ;
uint8   Key2_2_ReadDataReg(void) ;
uint8   Key2_2_Read(void) ;
uint8   Key2_2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Key2_2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Key2_2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Key2_2_DM_RES_UP          PIN_DM_RES_UP
#define Key2_2_DM_RES_DWN         PIN_DM_RES_DWN
#define Key2_2_DM_OD_LO           PIN_DM_OD_LO
#define Key2_2_DM_OD_HI           PIN_DM_OD_HI
#define Key2_2_DM_STRONG          PIN_DM_STRONG
#define Key2_2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Key2_2_MASK               Key2_2__MASK
#define Key2_2_SHIFT              Key2_2__SHIFT
#define Key2_2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Key2_2_PS                     (* (reg8 *) Key2_2__PS)
/* Data Register */
#define Key2_2_DR                     (* (reg8 *) Key2_2__DR)
/* Port Number */
#define Key2_2_PRT_NUM                (* (reg8 *) Key2_2__PRT) 
/* Connect to Analog Globals */                                                  
#define Key2_2_AG                     (* (reg8 *) Key2_2__AG)                       
/* Analog MUX bux enable */
#define Key2_2_AMUX                   (* (reg8 *) Key2_2__AMUX) 
/* Bidirectional Enable */                                                        
#define Key2_2_BIE                    (* (reg8 *) Key2_2__BIE)
/* Bit-mask for Aliased Register Access */
#define Key2_2_BIT_MASK               (* (reg8 *) Key2_2__BIT_MASK)
/* Bypass Enable */
#define Key2_2_BYP                    (* (reg8 *) Key2_2__BYP)
/* Port wide control signals */                                                   
#define Key2_2_CTL                    (* (reg8 *) Key2_2__CTL)
/* Drive Modes */
#define Key2_2_DM0                    (* (reg8 *) Key2_2__DM0) 
#define Key2_2_DM1                    (* (reg8 *) Key2_2__DM1)
#define Key2_2_DM2                    (* (reg8 *) Key2_2__DM2) 
/* Input Buffer Disable Override */
#define Key2_2_INP_DIS                (* (reg8 *) Key2_2__INP_DIS)
/* LCD Common or Segment Drive */
#define Key2_2_LCD_COM_SEG            (* (reg8 *) Key2_2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Key2_2_LCD_EN                 (* (reg8 *) Key2_2__LCD_EN)
/* Slew Rate Control */
#define Key2_2_SLW                    (* (reg8 *) Key2_2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Key2_2_PRTDSI__CAPS_SEL       (* (reg8 *) Key2_2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Key2_2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Key2_2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Key2_2_PRTDSI__OE_SEL0        (* (reg8 *) Key2_2__PRTDSI__OE_SEL0) 
#define Key2_2_PRTDSI__OE_SEL1        (* (reg8 *) Key2_2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Key2_2_PRTDSI__OUT_SEL0       (* (reg8 *) Key2_2__PRTDSI__OUT_SEL0) 
#define Key2_2_PRTDSI__OUT_SEL1       (* (reg8 *) Key2_2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Key2_2_PRTDSI__SYNC_OUT       (* (reg8 *) Key2_2__PRTDSI__SYNC_OUT) 


#if defined(Key2_2__INTSTAT)  /* Interrupt Registers */

    #define Key2_2_INTSTAT                (* (reg8 *) Key2_2__INTSTAT)
    #define Key2_2_SNAP                   (* (reg8 *) Key2_2__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Key2_2_H */


/* [] END OF FILE */
