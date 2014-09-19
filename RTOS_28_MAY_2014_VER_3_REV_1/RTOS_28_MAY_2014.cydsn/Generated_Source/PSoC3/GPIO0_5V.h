/*******************************************************************************
* File Name: GPIO0_5V.h  
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

#if !defined(CY_PINS_GPIO0_5V_H) /* Pins GPIO0_5V_H */
#define CY_PINS_GPIO0_5V_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "GPIO0_5V_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GPIO0_5V_Write(uint8 value) ;
void    GPIO0_5V_SetDriveMode(uint8 mode) ;
uint8   GPIO0_5V_ReadDataReg(void) ;
uint8   GPIO0_5V_Read(void) ;
uint8   GPIO0_5V_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GPIO0_5V_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define GPIO0_5V_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define GPIO0_5V_DM_RES_UP          PIN_DM_RES_UP
#define GPIO0_5V_DM_RES_DWN         PIN_DM_RES_DWN
#define GPIO0_5V_DM_OD_LO           PIN_DM_OD_LO
#define GPIO0_5V_DM_OD_HI           PIN_DM_OD_HI
#define GPIO0_5V_DM_STRONG          PIN_DM_STRONG
#define GPIO0_5V_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define GPIO0_5V_MASK               GPIO0_5V__MASK
#define GPIO0_5V_SHIFT              GPIO0_5V__SHIFT
#define GPIO0_5V_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GPIO0_5V_PS                     (* (reg8 *) GPIO0_5V__PS)
/* Data Register */
#define GPIO0_5V_DR                     (* (reg8 *) GPIO0_5V__DR)
/* Port Number */
#define GPIO0_5V_PRT_NUM                (* (reg8 *) GPIO0_5V__PRT) 
/* Connect to Analog Globals */                                                  
#define GPIO0_5V_AG                     (* (reg8 *) GPIO0_5V__AG)                       
/* Analog MUX bux enable */
#define GPIO0_5V_AMUX                   (* (reg8 *) GPIO0_5V__AMUX) 
/* Bidirectional Enable */                                                        
#define GPIO0_5V_BIE                    (* (reg8 *) GPIO0_5V__BIE)
/* Bit-mask for Aliased Register Access */
#define GPIO0_5V_BIT_MASK               (* (reg8 *) GPIO0_5V__BIT_MASK)
/* Bypass Enable */
#define GPIO0_5V_BYP                    (* (reg8 *) GPIO0_5V__BYP)
/* Port wide control signals */                                                   
#define GPIO0_5V_CTL                    (* (reg8 *) GPIO0_5V__CTL)
/* Drive Modes */
#define GPIO0_5V_DM0                    (* (reg8 *) GPIO0_5V__DM0) 
#define GPIO0_5V_DM1                    (* (reg8 *) GPIO0_5V__DM1)
#define GPIO0_5V_DM2                    (* (reg8 *) GPIO0_5V__DM2) 
/* Input Buffer Disable Override */
#define GPIO0_5V_INP_DIS                (* (reg8 *) GPIO0_5V__INP_DIS)
/* LCD Common or Segment Drive */
#define GPIO0_5V_LCD_COM_SEG            (* (reg8 *) GPIO0_5V__LCD_COM_SEG)
/* Enable Segment LCD */
#define GPIO0_5V_LCD_EN                 (* (reg8 *) GPIO0_5V__LCD_EN)
/* Slew Rate Control */
#define GPIO0_5V_SLW                    (* (reg8 *) GPIO0_5V__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define GPIO0_5V_PRTDSI__CAPS_SEL       (* (reg8 *) GPIO0_5V__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define GPIO0_5V_PRTDSI__DBL_SYNC_IN    (* (reg8 *) GPIO0_5V__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define GPIO0_5V_PRTDSI__OE_SEL0        (* (reg8 *) GPIO0_5V__PRTDSI__OE_SEL0) 
#define GPIO0_5V_PRTDSI__OE_SEL1        (* (reg8 *) GPIO0_5V__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define GPIO0_5V_PRTDSI__OUT_SEL0       (* (reg8 *) GPIO0_5V__PRTDSI__OUT_SEL0) 
#define GPIO0_5V_PRTDSI__OUT_SEL1       (* (reg8 *) GPIO0_5V__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define GPIO0_5V_PRTDSI__SYNC_OUT       (* (reg8 *) GPIO0_5V__PRTDSI__SYNC_OUT) 


#if defined(GPIO0_5V__INTSTAT)  /* Interrupt Registers */

    #define GPIO0_5V_INTSTAT                (* (reg8 *) GPIO0_5V__INTSTAT)
    #define GPIO0_5V_SNAP                   (* (reg8 *) GPIO0_5V__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins GPIO0_5V_H */


/* [] END OF FILE */
