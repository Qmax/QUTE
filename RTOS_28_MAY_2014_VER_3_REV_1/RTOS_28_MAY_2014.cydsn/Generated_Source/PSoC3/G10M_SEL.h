/*******************************************************************************
* File Name: G10M_SEL.h  
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

#if !defined(CY_PINS_G10M_SEL_H) /* Pins G10M_SEL_H */
#define CY_PINS_G10M_SEL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "G10M_SEL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    G10M_SEL_Write(uint8 value) ;
void    G10M_SEL_SetDriveMode(uint8 mode) ;
uint8   G10M_SEL_ReadDataReg(void) ;
uint8   G10M_SEL_Read(void) ;
uint8   G10M_SEL_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define G10M_SEL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define G10M_SEL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define G10M_SEL_DM_RES_UP          PIN_DM_RES_UP
#define G10M_SEL_DM_RES_DWN         PIN_DM_RES_DWN
#define G10M_SEL_DM_OD_LO           PIN_DM_OD_LO
#define G10M_SEL_DM_OD_HI           PIN_DM_OD_HI
#define G10M_SEL_DM_STRONG          PIN_DM_STRONG
#define G10M_SEL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define G10M_SEL_MASK               G10M_SEL__MASK
#define G10M_SEL_SHIFT              G10M_SEL__SHIFT
#define G10M_SEL_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define G10M_SEL_PS                     (* (reg8 *) G10M_SEL__PS)
/* Data Register */
#define G10M_SEL_DR                     (* (reg8 *) G10M_SEL__DR)
/* Port Number */
#define G10M_SEL_PRT_NUM                (* (reg8 *) G10M_SEL__PRT) 
/* Connect to Analog Globals */                                                  
#define G10M_SEL_AG                     (* (reg8 *) G10M_SEL__AG)                       
/* Analog MUX bux enable */
#define G10M_SEL_AMUX                   (* (reg8 *) G10M_SEL__AMUX) 
/* Bidirectional Enable */                                                        
#define G10M_SEL_BIE                    (* (reg8 *) G10M_SEL__BIE)
/* Bit-mask for Aliased Register Access */
#define G10M_SEL_BIT_MASK               (* (reg8 *) G10M_SEL__BIT_MASK)
/* Bypass Enable */
#define G10M_SEL_BYP                    (* (reg8 *) G10M_SEL__BYP)
/* Port wide control signals */                                                   
#define G10M_SEL_CTL                    (* (reg8 *) G10M_SEL__CTL)
/* Drive Modes */
#define G10M_SEL_DM0                    (* (reg8 *) G10M_SEL__DM0) 
#define G10M_SEL_DM1                    (* (reg8 *) G10M_SEL__DM1)
#define G10M_SEL_DM2                    (* (reg8 *) G10M_SEL__DM2) 
/* Input Buffer Disable Override */
#define G10M_SEL_INP_DIS                (* (reg8 *) G10M_SEL__INP_DIS)
/* LCD Common or Segment Drive */
#define G10M_SEL_LCD_COM_SEG            (* (reg8 *) G10M_SEL__LCD_COM_SEG)
/* Enable Segment LCD */
#define G10M_SEL_LCD_EN                 (* (reg8 *) G10M_SEL__LCD_EN)
/* Slew Rate Control */
#define G10M_SEL_SLW                    (* (reg8 *) G10M_SEL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define G10M_SEL_PRTDSI__CAPS_SEL       (* (reg8 *) G10M_SEL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define G10M_SEL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) G10M_SEL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define G10M_SEL_PRTDSI__OE_SEL0        (* (reg8 *) G10M_SEL__PRTDSI__OE_SEL0) 
#define G10M_SEL_PRTDSI__OE_SEL1        (* (reg8 *) G10M_SEL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define G10M_SEL_PRTDSI__OUT_SEL0       (* (reg8 *) G10M_SEL__PRTDSI__OUT_SEL0) 
#define G10M_SEL_PRTDSI__OUT_SEL1       (* (reg8 *) G10M_SEL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define G10M_SEL_PRTDSI__SYNC_OUT       (* (reg8 *) G10M_SEL__PRTDSI__SYNC_OUT) 


#if defined(G10M_SEL__INTSTAT)  /* Interrupt Registers */

    #define G10M_SEL_INTSTAT                (* (reg8 *) G10M_SEL__INTSTAT)
    #define G10M_SEL_SNAP                   (* (reg8 *) G10M_SEL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins G10M_SEL_H */


/* [] END OF FILE */