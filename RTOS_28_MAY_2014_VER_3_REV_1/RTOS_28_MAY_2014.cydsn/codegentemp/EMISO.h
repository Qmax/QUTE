/*******************************************************************************
* File Name: EMISO.h  
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

#if !defined(CY_PINS_EMISO_H) /* Pins EMISO_H */
#define CY_PINS_EMISO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EMISO_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    EMISO_Write(uint8 value) ;
void    EMISO_SetDriveMode(uint8 mode) ;
uint8   EMISO_ReadDataReg(void) ;
uint8   EMISO_Read(void) ;
uint8   EMISO_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EMISO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EMISO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EMISO_DM_RES_UP          PIN_DM_RES_UP
#define EMISO_DM_RES_DWN         PIN_DM_RES_DWN
#define EMISO_DM_OD_LO           PIN_DM_OD_LO
#define EMISO_DM_OD_HI           PIN_DM_OD_HI
#define EMISO_DM_STRONG          PIN_DM_STRONG
#define EMISO_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EMISO_MASK               EMISO__MASK
#define EMISO_SHIFT              EMISO__SHIFT
#define EMISO_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EMISO_PS                     (* (reg8 *) EMISO__PS)
/* Data Register */
#define EMISO_DR                     (* (reg8 *) EMISO__DR)
/* Port Number */
#define EMISO_PRT_NUM                (* (reg8 *) EMISO__PRT) 
/* Connect to Analog Globals */                                                  
#define EMISO_AG                     (* (reg8 *) EMISO__AG)                       
/* Analog MUX bux enable */
#define EMISO_AMUX                   (* (reg8 *) EMISO__AMUX) 
/* Bidirectional Enable */                                                        
#define EMISO_BIE                    (* (reg8 *) EMISO__BIE)
/* Bit-mask for Aliased Register Access */
#define EMISO_BIT_MASK               (* (reg8 *) EMISO__BIT_MASK)
/* Bypass Enable */
#define EMISO_BYP                    (* (reg8 *) EMISO__BYP)
/* Port wide control signals */                                                   
#define EMISO_CTL                    (* (reg8 *) EMISO__CTL)
/* Drive Modes */
#define EMISO_DM0                    (* (reg8 *) EMISO__DM0) 
#define EMISO_DM1                    (* (reg8 *) EMISO__DM1)
#define EMISO_DM2                    (* (reg8 *) EMISO__DM2) 
/* Input Buffer Disable Override */
#define EMISO_INP_DIS                (* (reg8 *) EMISO__INP_DIS)
/* LCD Common or Segment Drive */
#define EMISO_LCD_COM_SEG            (* (reg8 *) EMISO__LCD_COM_SEG)
/* Enable Segment LCD */
#define EMISO_LCD_EN                 (* (reg8 *) EMISO__LCD_EN)
/* Slew Rate Control */
#define EMISO_SLW                    (* (reg8 *) EMISO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EMISO_PRTDSI__CAPS_SEL       (* (reg8 *) EMISO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EMISO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EMISO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EMISO_PRTDSI__OE_SEL0        (* (reg8 *) EMISO__PRTDSI__OE_SEL0) 
#define EMISO_PRTDSI__OE_SEL1        (* (reg8 *) EMISO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EMISO_PRTDSI__OUT_SEL0       (* (reg8 *) EMISO__PRTDSI__OUT_SEL0) 
#define EMISO_PRTDSI__OUT_SEL1       (* (reg8 *) EMISO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EMISO_PRTDSI__SYNC_OUT       (* (reg8 *) EMISO__PRTDSI__SYNC_OUT) 


#if defined(EMISO__INTSTAT)  /* Interrupt Registers */

    #define EMISO_INTSTAT                (* (reg8 *) EMISO__INTSTAT)
    #define EMISO_SNAP                   (* (reg8 *) EMISO__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins EMISO_H */


/* [] END OF FILE */
