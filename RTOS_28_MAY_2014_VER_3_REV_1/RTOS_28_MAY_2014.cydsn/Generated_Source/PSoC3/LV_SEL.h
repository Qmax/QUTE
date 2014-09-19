/*******************************************************************************
* File Name: LV_SEL.h  
* Version 1.60
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PINS_LV_SEL_H) /* Pins LV_SEL_H */
#define CY_PINS_LV_SEL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LV_SEL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LV_SEL_Write(uint8 value) ;
void    LV_SEL_SetDriveMode(uint8 mode) ;
uint8   LV_SEL_ReadDataReg(void) ;
uint8   LV_SEL_Read(void) ;
uint8   LV_SEL_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LV_SEL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LV_SEL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LV_SEL_DM_RES_UP          PIN_DM_RES_UP
#define LV_SEL_DM_RES_DWN         PIN_DM_RES_DWN
#define LV_SEL_DM_OD_LO           PIN_DM_OD_LO
#define LV_SEL_DM_OD_HI           PIN_DM_OD_HI
#define LV_SEL_DM_STRONG          PIN_DM_STRONG
#define LV_SEL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LV_SEL_MASK               LV_SEL__MASK
#define LV_SEL_SHIFT              LV_SEL__SHIFT
#define LV_SEL_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LV_SEL_PS                     (* (reg8 *) LV_SEL__PS)
/* Data Register */
#define LV_SEL_DR                     (* (reg8 *) LV_SEL__DR)
/* Port Number */
#define LV_SEL_PRT_NUM                (* (reg8 *) LV_SEL__PRT) 
/* Connect to Analog Globals */                                                  
#define LV_SEL_AG                     (* (reg8 *) LV_SEL__AG)                       
/* Analog MUX bux enable */
#define LV_SEL_AMUX                   (* (reg8 *) LV_SEL__AMUX) 
/* Bidirectional Enable */                                                        
#define LV_SEL_BIE                    (* (reg8 *) LV_SEL__BIE)
/* Bit-mask for Aliased Register Access */
#define LV_SEL_BIT_MASK               (* (reg8 *) LV_SEL__BIT_MASK)
/* Bypass Enable */
#define LV_SEL_BYP                    (* (reg8 *) LV_SEL__BYP)
/* Port wide control signals */                                                   
#define LV_SEL_CTL                    (* (reg8 *) LV_SEL__CTL)
/* Drive Modes */
#define LV_SEL_DM0                    (* (reg8 *) LV_SEL__DM0) 
#define LV_SEL_DM1                    (* (reg8 *) LV_SEL__DM1)
#define LV_SEL_DM2                    (* (reg8 *) LV_SEL__DM2) 
/* Input Buffer Disable Override */
#define LV_SEL_INP_DIS                (* (reg8 *) LV_SEL__INP_DIS)
/* LCD Common or Segment Drive */
#define LV_SEL_LCD_COM_SEG            (* (reg8 *) LV_SEL__LCD_COM_SEG)
/* Enable Segment LCD */
#define LV_SEL_LCD_EN                 (* (reg8 *) LV_SEL__LCD_EN)
/* Slew Rate Control */
#define LV_SEL_SLW                    (* (reg8 *) LV_SEL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LV_SEL_PRTDSI__CAPS_SEL       (* (reg8 *) LV_SEL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LV_SEL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LV_SEL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LV_SEL_PRTDSI__OE_SEL0        (* (reg8 *) LV_SEL__PRTDSI__OE_SEL0) 
#define LV_SEL_PRTDSI__OE_SEL1        (* (reg8 *) LV_SEL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LV_SEL_PRTDSI__OUT_SEL0       (* (reg8 *) LV_SEL__PRTDSI__OUT_SEL0) 
#define LV_SEL_PRTDSI__OUT_SEL1       (* (reg8 *) LV_SEL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LV_SEL_PRTDSI__SYNC_OUT       (* (reg8 *) LV_SEL__PRTDSI__SYNC_OUT) 


#if defined(LV_SEL__INTSTAT)  /* Interrupt Registers */

    #define LV_SEL_INTSTAT                (* (reg8 *) LV_SEL__INTSTAT)
    #define LV_SEL_SNAP                   (* (reg8 *) LV_SEL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins LV_SEL_H */


/* [] END OF FILE */
