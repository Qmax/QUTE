/*******************************************************************************
* File Name: ISO_SDO.h  
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

#if !defined(CY_PINS_ISO_SDO_H) /* Pins ISO_SDO_H */
#define CY_PINS_ISO_SDO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ISO_SDO_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ISO_SDO_Write(uint8 value) ;
void    ISO_SDO_SetDriveMode(uint8 mode) ;
uint8   ISO_SDO_ReadDataReg(void) ;
uint8   ISO_SDO_Read(void) ;
uint8   ISO_SDO_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ISO_SDO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ISO_SDO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ISO_SDO_DM_RES_UP          PIN_DM_RES_UP
#define ISO_SDO_DM_RES_DWN         PIN_DM_RES_DWN
#define ISO_SDO_DM_OD_LO           PIN_DM_OD_LO
#define ISO_SDO_DM_OD_HI           PIN_DM_OD_HI
#define ISO_SDO_DM_STRONG          PIN_DM_STRONG
#define ISO_SDO_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ISO_SDO_MASK               ISO_SDO__MASK
#define ISO_SDO_SHIFT              ISO_SDO__SHIFT
#define ISO_SDO_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ISO_SDO_PS                     (* (reg8 *) ISO_SDO__PS)
/* Data Register */
#define ISO_SDO_DR                     (* (reg8 *) ISO_SDO__DR)
/* Port Number */
#define ISO_SDO_PRT_NUM                (* (reg8 *) ISO_SDO__PRT) 
/* Connect to Analog Globals */                                                  
#define ISO_SDO_AG                     (* (reg8 *) ISO_SDO__AG)                       
/* Analog MUX bux enable */
#define ISO_SDO_AMUX                   (* (reg8 *) ISO_SDO__AMUX) 
/* Bidirectional Enable */                                                        
#define ISO_SDO_BIE                    (* (reg8 *) ISO_SDO__BIE)
/* Bit-mask for Aliased Register Access */
#define ISO_SDO_BIT_MASK               (* (reg8 *) ISO_SDO__BIT_MASK)
/* Bypass Enable */
#define ISO_SDO_BYP                    (* (reg8 *) ISO_SDO__BYP)
/* Port wide control signals */                                                   
#define ISO_SDO_CTL                    (* (reg8 *) ISO_SDO__CTL)
/* Drive Modes */
#define ISO_SDO_DM0                    (* (reg8 *) ISO_SDO__DM0) 
#define ISO_SDO_DM1                    (* (reg8 *) ISO_SDO__DM1)
#define ISO_SDO_DM2                    (* (reg8 *) ISO_SDO__DM2) 
/* Input Buffer Disable Override */
#define ISO_SDO_INP_DIS                (* (reg8 *) ISO_SDO__INP_DIS)
/* LCD Common or Segment Drive */
#define ISO_SDO_LCD_COM_SEG            (* (reg8 *) ISO_SDO__LCD_COM_SEG)
/* Enable Segment LCD */
#define ISO_SDO_LCD_EN                 (* (reg8 *) ISO_SDO__LCD_EN)
/* Slew Rate Control */
#define ISO_SDO_SLW                    (* (reg8 *) ISO_SDO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ISO_SDO_PRTDSI__CAPS_SEL       (* (reg8 *) ISO_SDO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ISO_SDO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ISO_SDO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ISO_SDO_PRTDSI__OE_SEL0        (* (reg8 *) ISO_SDO__PRTDSI__OE_SEL0) 
#define ISO_SDO_PRTDSI__OE_SEL1        (* (reg8 *) ISO_SDO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ISO_SDO_PRTDSI__OUT_SEL0       (* (reg8 *) ISO_SDO__PRTDSI__OUT_SEL0) 
#define ISO_SDO_PRTDSI__OUT_SEL1       (* (reg8 *) ISO_SDO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ISO_SDO_PRTDSI__SYNC_OUT       (* (reg8 *) ISO_SDO__PRTDSI__SYNC_OUT) 


#if defined(ISO_SDO__INTSTAT)  /* Interrupt Registers */

    #define ISO_SDO_INTSTAT                (* (reg8 *) ISO_SDO__INTSTAT)
    #define ISO_SDO_SNAP                   (* (reg8 *) ISO_SDO__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ISO_SDO_H */


/* [] END OF FILE */
