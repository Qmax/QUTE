/*******************************************************************************
* File Name: ECLK.h  
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

#if !defined(CY_PINS_ECLK_H) /* Pins ECLK_H */
#define CY_PINS_ECLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ECLK_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ECLK_Write(uint8 value) ;
void    ECLK_SetDriveMode(uint8 mode) ;
uint8   ECLK_ReadDataReg(void) ;
uint8   ECLK_Read(void) ;
uint8   ECLK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ECLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ECLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ECLK_DM_RES_UP          PIN_DM_RES_UP
#define ECLK_DM_RES_DWN         PIN_DM_RES_DWN
#define ECLK_DM_OD_LO           PIN_DM_OD_LO
#define ECLK_DM_OD_HI           PIN_DM_OD_HI
#define ECLK_DM_STRONG          PIN_DM_STRONG
#define ECLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ECLK_MASK               ECLK__MASK
#define ECLK_SHIFT              ECLK__SHIFT
#define ECLK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ECLK_PS                     (* (reg8 *) ECLK__PS)
/* Data Register */
#define ECLK_DR                     (* (reg8 *) ECLK__DR)
/* Port Number */
#define ECLK_PRT_NUM                (* (reg8 *) ECLK__PRT) 
/* Connect to Analog Globals */                                                  
#define ECLK_AG                     (* (reg8 *) ECLK__AG)                       
/* Analog MUX bux enable */
#define ECLK_AMUX                   (* (reg8 *) ECLK__AMUX) 
/* Bidirectional Enable */                                                        
#define ECLK_BIE                    (* (reg8 *) ECLK__BIE)
/* Bit-mask for Aliased Register Access */
#define ECLK_BIT_MASK               (* (reg8 *) ECLK__BIT_MASK)
/* Bypass Enable */
#define ECLK_BYP                    (* (reg8 *) ECLK__BYP)
/* Port wide control signals */                                                   
#define ECLK_CTL                    (* (reg8 *) ECLK__CTL)
/* Drive Modes */
#define ECLK_DM0                    (* (reg8 *) ECLK__DM0) 
#define ECLK_DM1                    (* (reg8 *) ECLK__DM1)
#define ECLK_DM2                    (* (reg8 *) ECLK__DM2) 
/* Input Buffer Disable Override */
#define ECLK_INP_DIS                (* (reg8 *) ECLK__INP_DIS)
/* LCD Common or Segment Drive */
#define ECLK_LCD_COM_SEG            (* (reg8 *) ECLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define ECLK_LCD_EN                 (* (reg8 *) ECLK__LCD_EN)
/* Slew Rate Control */
#define ECLK_SLW                    (* (reg8 *) ECLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ECLK_PRTDSI__CAPS_SEL       (* (reg8 *) ECLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ECLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ECLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ECLK_PRTDSI__OE_SEL0        (* (reg8 *) ECLK__PRTDSI__OE_SEL0) 
#define ECLK_PRTDSI__OE_SEL1        (* (reg8 *) ECLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ECLK_PRTDSI__OUT_SEL0       (* (reg8 *) ECLK__PRTDSI__OUT_SEL0) 
#define ECLK_PRTDSI__OUT_SEL1       (* (reg8 *) ECLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ECLK_PRTDSI__SYNC_OUT       (* (reg8 *) ECLK__PRTDSI__SYNC_OUT) 


#if defined(ECLK__INTSTAT)  /* Interrupt Registers */

    #define ECLK_INTSTAT                (* (reg8 *) ECLK__INTSTAT)
    #define ECLK_SNAP                   (* (reg8 *) ECLK__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ECLK_H */


/* [] END OF FILE */
