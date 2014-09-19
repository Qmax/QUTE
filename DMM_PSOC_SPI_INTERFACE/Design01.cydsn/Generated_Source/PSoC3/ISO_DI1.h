/*******************************************************************************
* File Name: ISO_DI1.h  
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

#if !defined(CY_PINS_ISO_DI1_H) /* Pins ISO_DI1_H */
#define CY_PINS_ISO_DI1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ISO_DI1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ISO_DI1_Write(uint8 value) ;
void    ISO_DI1_SetDriveMode(uint8 mode) ;
uint8   ISO_DI1_ReadDataReg(void) ;
uint8   ISO_DI1_Read(void) ;
uint8   ISO_DI1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ISO_DI1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ISO_DI1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ISO_DI1_DM_RES_UP          PIN_DM_RES_UP
#define ISO_DI1_DM_RES_DWN         PIN_DM_RES_DWN
#define ISO_DI1_DM_OD_LO           PIN_DM_OD_LO
#define ISO_DI1_DM_OD_HI           PIN_DM_OD_HI
#define ISO_DI1_DM_STRONG          PIN_DM_STRONG
#define ISO_DI1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ISO_DI1_MASK               ISO_DI1__MASK
#define ISO_DI1_SHIFT              ISO_DI1__SHIFT
#define ISO_DI1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ISO_DI1_PS                     (* (reg8 *) ISO_DI1__PS)
/* Data Register */
#define ISO_DI1_DR                     (* (reg8 *) ISO_DI1__DR)
/* Port Number */
#define ISO_DI1_PRT_NUM                (* (reg8 *) ISO_DI1__PRT) 
/* Connect to Analog Globals */                                                  
#define ISO_DI1_AG                     (* (reg8 *) ISO_DI1__AG)                       
/* Analog MUX bux enable */
#define ISO_DI1_AMUX                   (* (reg8 *) ISO_DI1__AMUX) 
/* Bidirectional Enable */                                                        
#define ISO_DI1_BIE                    (* (reg8 *) ISO_DI1__BIE)
/* Bit-mask for Aliased Register Access */
#define ISO_DI1_BIT_MASK               (* (reg8 *) ISO_DI1__BIT_MASK)
/* Bypass Enable */
#define ISO_DI1_BYP                    (* (reg8 *) ISO_DI1__BYP)
/* Port wide control signals */                                                   
#define ISO_DI1_CTL                    (* (reg8 *) ISO_DI1__CTL)
/* Drive Modes */
#define ISO_DI1_DM0                    (* (reg8 *) ISO_DI1__DM0) 
#define ISO_DI1_DM1                    (* (reg8 *) ISO_DI1__DM1)
#define ISO_DI1_DM2                    (* (reg8 *) ISO_DI1__DM2) 
/* Input Buffer Disable Override */
#define ISO_DI1_INP_DIS                (* (reg8 *) ISO_DI1__INP_DIS)
/* LCD Common or Segment Drive */
#define ISO_DI1_LCD_COM_SEG            (* (reg8 *) ISO_DI1__LCD_COM_SEG)
/* Enable Segment LCD */
#define ISO_DI1_LCD_EN                 (* (reg8 *) ISO_DI1__LCD_EN)
/* Slew Rate Control */
#define ISO_DI1_SLW                    (* (reg8 *) ISO_DI1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ISO_DI1_PRTDSI__CAPS_SEL       (* (reg8 *) ISO_DI1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ISO_DI1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ISO_DI1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ISO_DI1_PRTDSI__OE_SEL0        (* (reg8 *) ISO_DI1__PRTDSI__OE_SEL0) 
#define ISO_DI1_PRTDSI__OE_SEL1        (* (reg8 *) ISO_DI1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ISO_DI1_PRTDSI__OUT_SEL0       (* (reg8 *) ISO_DI1__PRTDSI__OUT_SEL0) 
#define ISO_DI1_PRTDSI__OUT_SEL1       (* (reg8 *) ISO_DI1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ISO_DI1_PRTDSI__SYNC_OUT       (* (reg8 *) ISO_DI1__PRTDSI__SYNC_OUT) 


#if defined(ISO_DI1__INTSTAT)  /* Interrupt Registers */

    #define ISO_DI1_INTSTAT                (* (reg8 *) ISO_DI1__INTSTAT)
    #define ISO_DI1_SNAP                   (* (reg8 *) ISO_DI1__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ISO_DI1_H */


/* [] END OF FILE */
