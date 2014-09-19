/*******************************************************************************
* File Name: DOut.h  
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

#if !defined(CY_PINS_DOut_H) /* Pins DOut_H */
#define CY_PINS_DOut_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DOut_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    DOut_Write(uint8 value) ;
void    DOut_SetDriveMode(uint8 mode) ;
uint8   DOut_ReadDataReg(void) ;
uint8   DOut_Read(void) ;
uint8   DOut_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DOut_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DOut_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DOut_DM_RES_UP          PIN_DM_RES_UP
#define DOut_DM_RES_DWN         PIN_DM_RES_DWN
#define DOut_DM_OD_LO           PIN_DM_OD_LO
#define DOut_DM_OD_HI           PIN_DM_OD_HI
#define DOut_DM_STRONG          PIN_DM_STRONG
#define DOut_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DOut_MASK               DOut__MASK
#define DOut_SHIFT              DOut__SHIFT
#define DOut_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DOut_PS                     (* (reg8 *) DOut__PS)
/* Data Register */
#define DOut_DR                     (* (reg8 *) DOut__DR)
/* Port Number */
#define DOut_PRT_NUM                (* (reg8 *) DOut__PRT) 
/* Connect to Analog Globals */                                                  
#define DOut_AG                     (* (reg8 *) DOut__AG)                       
/* Analog MUX bux enable */
#define DOut_AMUX                   (* (reg8 *) DOut__AMUX) 
/* Bidirectional Enable */                                                        
#define DOut_BIE                    (* (reg8 *) DOut__BIE)
/* Bit-mask for Aliased Register Access */
#define DOut_BIT_MASK               (* (reg8 *) DOut__BIT_MASK)
/* Bypass Enable */
#define DOut_BYP                    (* (reg8 *) DOut__BYP)
/* Port wide control signals */                                                   
#define DOut_CTL                    (* (reg8 *) DOut__CTL)
/* Drive Modes */
#define DOut_DM0                    (* (reg8 *) DOut__DM0) 
#define DOut_DM1                    (* (reg8 *) DOut__DM1)
#define DOut_DM2                    (* (reg8 *) DOut__DM2) 
/* Input Buffer Disable Override */
#define DOut_INP_DIS                (* (reg8 *) DOut__INP_DIS)
/* LCD Common or Segment Drive */
#define DOut_LCD_COM_SEG            (* (reg8 *) DOut__LCD_COM_SEG)
/* Enable Segment LCD */
#define DOut_LCD_EN                 (* (reg8 *) DOut__LCD_EN)
/* Slew Rate Control */
#define DOut_SLW                    (* (reg8 *) DOut__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DOut_PRTDSI__CAPS_SEL       (* (reg8 *) DOut__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DOut_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DOut__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DOut_PRTDSI__OE_SEL0        (* (reg8 *) DOut__PRTDSI__OE_SEL0) 
#define DOut_PRTDSI__OE_SEL1        (* (reg8 *) DOut__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DOut_PRTDSI__OUT_SEL0       (* (reg8 *) DOut__PRTDSI__OUT_SEL0) 
#define DOut_PRTDSI__OUT_SEL1       (* (reg8 *) DOut__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DOut_PRTDSI__SYNC_OUT       (* (reg8 *) DOut__PRTDSI__SYNC_OUT) 


#if defined(DOut__INTSTAT)  /* Interrupt Registers */

    #define DOut_INTSTAT                (* (reg8 *) DOut__INTSTAT)
    #define DOut_SNAP                   (* (reg8 *) DOut__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins DOut_H */


/* [] END OF FILE */
