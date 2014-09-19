/*******************************************************************************
* File Name: ISO_SDI.h  
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

#if !defined(CY_PINS_ISO_SDI_H) /* Pins ISO_SDI_H */
#define CY_PINS_ISO_SDI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ISO_SDI_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ISO_SDI_Write(uint8 value) ;
void    ISO_SDI_SetDriveMode(uint8 mode) ;
uint8   ISO_SDI_ReadDataReg(void) ;
uint8   ISO_SDI_Read(void) ;
uint8   ISO_SDI_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ISO_SDI_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ISO_SDI_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ISO_SDI_DM_RES_UP          PIN_DM_RES_UP
#define ISO_SDI_DM_RES_DWN         PIN_DM_RES_DWN
#define ISO_SDI_DM_OD_LO           PIN_DM_OD_LO
#define ISO_SDI_DM_OD_HI           PIN_DM_OD_HI
#define ISO_SDI_DM_STRONG          PIN_DM_STRONG
#define ISO_SDI_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ISO_SDI_MASK               ISO_SDI__MASK
#define ISO_SDI_SHIFT              ISO_SDI__SHIFT
#define ISO_SDI_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ISO_SDI_PS                     (* (reg8 *) ISO_SDI__PS)
/* Data Register */
#define ISO_SDI_DR                     (* (reg8 *) ISO_SDI__DR)
/* Port Number */
#define ISO_SDI_PRT_NUM                (* (reg8 *) ISO_SDI__PRT) 
/* Connect to Analog Globals */                                                  
#define ISO_SDI_AG                     (* (reg8 *) ISO_SDI__AG)                       
/* Analog MUX bux enable */
#define ISO_SDI_AMUX                   (* (reg8 *) ISO_SDI__AMUX) 
/* Bidirectional Enable */                                                        
#define ISO_SDI_BIE                    (* (reg8 *) ISO_SDI__BIE)
/* Bit-mask for Aliased Register Access */
#define ISO_SDI_BIT_MASK               (* (reg8 *) ISO_SDI__BIT_MASK)
/* Bypass Enable */
#define ISO_SDI_BYP                    (* (reg8 *) ISO_SDI__BYP)
/* Port wide control signals */                                                   
#define ISO_SDI_CTL                    (* (reg8 *) ISO_SDI__CTL)
/* Drive Modes */
#define ISO_SDI_DM0                    (* (reg8 *) ISO_SDI__DM0) 
#define ISO_SDI_DM1                    (* (reg8 *) ISO_SDI__DM1)
#define ISO_SDI_DM2                    (* (reg8 *) ISO_SDI__DM2) 
/* Input Buffer Disable Override */
#define ISO_SDI_INP_DIS                (* (reg8 *) ISO_SDI__INP_DIS)
/* LCD Common or Segment Drive */
#define ISO_SDI_LCD_COM_SEG            (* (reg8 *) ISO_SDI__LCD_COM_SEG)
/* Enable Segment LCD */
#define ISO_SDI_LCD_EN                 (* (reg8 *) ISO_SDI__LCD_EN)
/* Slew Rate Control */
#define ISO_SDI_SLW                    (* (reg8 *) ISO_SDI__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ISO_SDI_PRTDSI__CAPS_SEL       (* (reg8 *) ISO_SDI__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ISO_SDI_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ISO_SDI__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ISO_SDI_PRTDSI__OE_SEL0        (* (reg8 *) ISO_SDI__PRTDSI__OE_SEL0) 
#define ISO_SDI_PRTDSI__OE_SEL1        (* (reg8 *) ISO_SDI__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ISO_SDI_PRTDSI__OUT_SEL0       (* (reg8 *) ISO_SDI__PRTDSI__OUT_SEL0) 
#define ISO_SDI_PRTDSI__OUT_SEL1       (* (reg8 *) ISO_SDI__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ISO_SDI_PRTDSI__SYNC_OUT       (* (reg8 *) ISO_SDI__PRTDSI__SYNC_OUT) 


#if defined(ISO_SDI__INTSTAT)  /* Interrupt Registers */

    #define ISO_SDI_INTSTAT                (* (reg8 *) ISO_SDI__INTSTAT)
    #define ISO_SDI_SNAP                   (* (reg8 *) ISO_SDI__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ISO_SDI_H */


/* [] END OF FILE */
