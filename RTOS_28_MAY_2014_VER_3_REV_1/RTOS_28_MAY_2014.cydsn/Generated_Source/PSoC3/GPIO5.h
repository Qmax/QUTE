/*******************************************************************************
* File Name: GPIO5.h  
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

#if !defined(CY_PINS_GPIO5_H) /* Pins GPIO5_H */
#define CY_PINS_GPIO5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "GPIO5_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GPIO5_Write(uint8 value) ;
void    GPIO5_SetDriveMode(uint8 mode) ;
uint8   GPIO5_ReadDataReg(void) ;
uint8   GPIO5_Read(void) ;
uint8   GPIO5_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GPIO5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define GPIO5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define GPIO5_DM_RES_UP          PIN_DM_RES_UP
#define GPIO5_DM_RES_DWN         PIN_DM_RES_DWN
#define GPIO5_DM_OD_LO           PIN_DM_OD_LO
#define GPIO5_DM_OD_HI           PIN_DM_OD_HI
#define GPIO5_DM_STRONG          PIN_DM_STRONG
#define GPIO5_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define GPIO5_MASK               GPIO5__MASK
#define GPIO5_SHIFT              GPIO5__SHIFT
#define GPIO5_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GPIO5_PS                     (* (reg8 *) GPIO5__PS)
/* Data Register */
#define GPIO5_DR                     (* (reg8 *) GPIO5__DR)
/* Port Number */
#define GPIO5_PRT_NUM                (* (reg8 *) GPIO5__PRT) 
/* Connect to Analog Globals */                                                  
#define GPIO5_AG                     (* (reg8 *) GPIO5__AG)                       
/* Analog MUX bux enable */
#define GPIO5_AMUX                   (* (reg8 *) GPIO5__AMUX) 
/* Bidirectional Enable */                                                        
#define GPIO5_BIE                    (* (reg8 *) GPIO5__BIE)
/* Bit-mask for Aliased Register Access */
#define GPIO5_BIT_MASK               (* (reg8 *) GPIO5__BIT_MASK)
/* Bypass Enable */
#define GPIO5_BYP                    (* (reg8 *) GPIO5__BYP)
/* Port wide control signals */                                                   
#define GPIO5_CTL                    (* (reg8 *) GPIO5__CTL)
/* Drive Modes */
#define GPIO5_DM0                    (* (reg8 *) GPIO5__DM0) 
#define GPIO5_DM1                    (* (reg8 *) GPIO5__DM1)
#define GPIO5_DM2                    (* (reg8 *) GPIO5__DM2) 
/* Input Buffer Disable Override */
#define GPIO5_INP_DIS                (* (reg8 *) GPIO5__INP_DIS)
/* LCD Common or Segment Drive */
#define GPIO5_LCD_COM_SEG            (* (reg8 *) GPIO5__LCD_COM_SEG)
/* Enable Segment LCD */
#define GPIO5_LCD_EN                 (* (reg8 *) GPIO5__LCD_EN)
/* Slew Rate Control */
#define GPIO5_SLW                    (* (reg8 *) GPIO5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define GPIO5_PRTDSI__CAPS_SEL       (* (reg8 *) GPIO5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define GPIO5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) GPIO5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define GPIO5_PRTDSI__OE_SEL0        (* (reg8 *) GPIO5__PRTDSI__OE_SEL0) 
#define GPIO5_PRTDSI__OE_SEL1        (* (reg8 *) GPIO5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define GPIO5_PRTDSI__OUT_SEL0       (* (reg8 *) GPIO5__PRTDSI__OUT_SEL0) 
#define GPIO5_PRTDSI__OUT_SEL1       (* (reg8 *) GPIO5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define GPIO5_PRTDSI__SYNC_OUT       (* (reg8 *) GPIO5__PRTDSI__SYNC_OUT) 


#if defined(GPIO5__INTSTAT)  /* Interrupt Registers */

    #define GPIO5_INTSTAT                (* (reg8 *) GPIO5__INTSTAT)
    #define GPIO5_SNAP                   (* (reg8 *) GPIO5__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins GPIO5_H */


/* [] END OF FILE */
