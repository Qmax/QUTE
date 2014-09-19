/*******************************************************************************
* File Name: FG1_SEL.h  
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

#if !defined(CY_PINS_FG1_SEL_H) /* Pins FG1_SEL_H */
#define CY_PINS_FG1_SEL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FG1_SEL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    FG1_SEL_Write(uint8 value) ;
void    FG1_SEL_SetDriveMode(uint8 mode) ;
uint8   FG1_SEL_ReadDataReg(void) ;
uint8   FG1_SEL_Read(void) ;
uint8   FG1_SEL_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define FG1_SEL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define FG1_SEL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define FG1_SEL_DM_RES_UP          PIN_DM_RES_UP
#define FG1_SEL_DM_RES_DWN         PIN_DM_RES_DWN
#define FG1_SEL_DM_OD_LO           PIN_DM_OD_LO
#define FG1_SEL_DM_OD_HI           PIN_DM_OD_HI
#define FG1_SEL_DM_STRONG          PIN_DM_STRONG
#define FG1_SEL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define FG1_SEL_MASK               FG1_SEL__MASK
#define FG1_SEL_SHIFT              FG1_SEL__SHIFT
#define FG1_SEL_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FG1_SEL_PS                     (* (reg8 *) FG1_SEL__PS)
/* Data Register */
#define FG1_SEL_DR                     (* (reg8 *) FG1_SEL__DR)
/* Port Number */
#define FG1_SEL_PRT_NUM                (* (reg8 *) FG1_SEL__PRT) 
/* Connect to Analog Globals */                                                  
#define FG1_SEL_AG                     (* (reg8 *) FG1_SEL__AG)                       
/* Analog MUX bux enable */
#define FG1_SEL_AMUX                   (* (reg8 *) FG1_SEL__AMUX) 
/* Bidirectional Enable */                                                        
#define FG1_SEL_BIE                    (* (reg8 *) FG1_SEL__BIE)
/* Bit-mask for Aliased Register Access */
#define FG1_SEL_BIT_MASK               (* (reg8 *) FG1_SEL__BIT_MASK)
/* Bypass Enable */
#define FG1_SEL_BYP                    (* (reg8 *) FG1_SEL__BYP)
/* Port wide control signals */                                                   
#define FG1_SEL_CTL                    (* (reg8 *) FG1_SEL__CTL)
/* Drive Modes */
#define FG1_SEL_DM0                    (* (reg8 *) FG1_SEL__DM0) 
#define FG1_SEL_DM1                    (* (reg8 *) FG1_SEL__DM1)
#define FG1_SEL_DM2                    (* (reg8 *) FG1_SEL__DM2) 
/* Input Buffer Disable Override */
#define FG1_SEL_INP_DIS                (* (reg8 *) FG1_SEL__INP_DIS)
/* LCD Common or Segment Drive */
#define FG1_SEL_LCD_COM_SEG            (* (reg8 *) FG1_SEL__LCD_COM_SEG)
/* Enable Segment LCD */
#define FG1_SEL_LCD_EN                 (* (reg8 *) FG1_SEL__LCD_EN)
/* Slew Rate Control */
#define FG1_SEL_SLW                    (* (reg8 *) FG1_SEL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FG1_SEL_PRTDSI__CAPS_SEL       (* (reg8 *) FG1_SEL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FG1_SEL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FG1_SEL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FG1_SEL_PRTDSI__OE_SEL0        (* (reg8 *) FG1_SEL__PRTDSI__OE_SEL0) 
#define FG1_SEL_PRTDSI__OE_SEL1        (* (reg8 *) FG1_SEL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FG1_SEL_PRTDSI__OUT_SEL0       (* (reg8 *) FG1_SEL__PRTDSI__OUT_SEL0) 
#define FG1_SEL_PRTDSI__OUT_SEL1       (* (reg8 *) FG1_SEL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FG1_SEL_PRTDSI__SYNC_OUT       (* (reg8 *) FG1_SEL__PRTDSI__SYNC_OUT) 


#if defined(FG1_SEL__INTSTAT)  /* Interrupt Registers */

    #define FG1_SEL_INTSTAT                (* (reg8 *) FG1_SEL__INTSTAT)
    #define FG1_SEL_SNAP                   (* (reg8 *) FG1_SEL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins FG1_SEL_H */


/* [] END OF FILE */
