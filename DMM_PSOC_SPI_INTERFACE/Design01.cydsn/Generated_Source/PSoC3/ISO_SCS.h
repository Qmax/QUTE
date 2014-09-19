/*******************************************************************************
* File Name: ISO_SCS.h  
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

#if !defined(CY_PINS_ISO_SCS_H) /* Pins ISO_SCS_H */
#define CY_PINS_ISO_SCS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ISO_SCS_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ISO_SCS_Write(uint8 value) ;
void    ISO_SCS_SetDriveMode(uint8 mode) ;
uint8   ISO_SCS_ReadDataReg(void) ;
uint8   ISO_SCS_Read(void) ;
uint8   ISO_SCS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ISO_SCS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ISO_SCS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ISO_SCS_DM_RES_UP          PIN_DM_RES_UP
#define ISO_SCS_DM_RES_DWN         PIN_DM_RES_DWN
#define ISO_SCS_DM_OD_LO           PIN_DM_OD_LO
#define ISO_SCS_DM_OD_HI           PIN_DM_OD_HI
#define ISO_SCS_DM_STRONG          PIN_DM_STRONG
#define ISO_SCS_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ISO_SCS_MASK               ISO_SCS__MASK
#define ISO_SCS_SHIFT              ISO_SCS__SHIFT
#define ISO_SCS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ISO_SCS_PS                     (* (reg8 *) ISO_SCS__PS)
/* Data Register */
#define ISO_SCS_DR                     (* (reg8 *) ISO_SCS__DR)
/* Port Number */
#define ISO_SCS_PRT_NUM                (* (reg8 *) ISO_SCS__PRT) 
/* Connect to Analog Globals */                                                  
#define ISO_SCS_AG                     (* (reg8 *) ISO_SCS__AG)                       
/* Analog MUX bux enable */
#define ISO_SCS_AMUX                   (* (reg8 *) ISO_SCS__AMUX) 
/* Bidirectional Enable */                                                        
#define ISO_SCS_BIE                    (* (reg8 *) ISO_SCS__BIE)
/* Bit-mask for Aliased Register Access */
#define ISO_SCS_BIT_MASK               (* (reg8 *) ISO_SCS__BIT_MASK)
/* Bypass Enable */
#define ISO_SCS_BYP                    (* (reg8 *) ISO_SCS__BYP)
/* Port wide control signals */                                                   
#define ISO_SCS_CTL                    (* (reg8 *) ISO_SCS__CTL)
/* Drive Modes */
#define ISO_SCS_DM0                    (* (reg8 *) ISO_SCS__DM0) 
#define ISO_SCS_DM1                    (* (reg8 *) ISO_SCS__DM1)
#define ISO_SCS_DM2                    (* (reg8 *) ISO_SCS__DM2) 
/* Input Buffer Disable Override */
#define ISO_SCS_INP_DIS                (* (reg8 *) ISO_SCS__INP_DIS)
/* LCD Common or Segment Drive */
#define ISO_SCS_LCD_COM_SEG            (* (reg8 *) ISO_SCS__LCD_COM_SEG)
/* Enable Segment LCD */
#define ISO_SCS_LCD_EN                 (* (reg8 *) ISO_SCS__LCD_EN)
/* Slew Rate Control */
#define ISO_SCS_SLW                    (* (reg8 *) ISO_SCS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ISO_SCS_PRTDSI__CAPS_SEL       (* (reg8 *) ISO_SCS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ISO_SCS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ISO_SCS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ISO_SCS_PRTDSI__OE_SEL0        (* (reg8 *) ISO_SCS__PRTDSI__OE_SEL0) 
#define ISO_SCS_PRTDSI__OE_SEL1        (* (reg8 *) ISO_SCS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ISO_SCS_PRTDSI__OUT_SEL0       (* (reg8 *) ISO_SCS__PRTDSI__OUT_SEL0) 
#define ISO_SCS_PRTDSI__OUT_SEL1       (* (reg8 *) ISO_SCS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ISO_SCS_PRTDSI__SYNC_OUT       (* (reg8 *) ISO_SCS__PRTDSI__SYNC_OUT) 


#if defined(ISO_SCS__INTSTAT)  /* Interrupt Registers */

    #define ISO_SCS_INTSTAT                (* (reg8 *) ISO_SCS__INTSTAT)
    #define ISO_SCS_SNAP                   (* (reg8 *) ISO_SCS__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ISO_SCS_H */


/* [] END OF FILE */
