/*******************************************************************************
* File Name: ATTN_SEL3.h  
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

#if !defined(CY_PINS_ATTN_SEL3_H) /* Pins ATTN_SEL3_H */
#define CY_PINS_ATTN_SEL3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ATTN_SEL3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ATTN_SEL3_Write(uint8 value) ;
void    ATTN_SEL3_SetDriveMode(uint8 mode) ;
uint8   ATTN_SEL3_ReadDataReg(void) ;
uint8   ATTN_SEL3_Read(void) ;
uint8   ATTN_SEL3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ATTN_SEL3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ATTN_SEL3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ATTN_SEL3_DM_RES_UP          PIN_DM_RES_UP
#define ATTN_SEL3_DM_RES_DWN         PIN_DM_RES_DWN
#define ATTN_SEL3_DM_OD_LO           PIN_DM_OD_LO
#define ATTN_SEL3_DM_OD_HI           PIN_DM_OD_HI
#define ATTN_SEL3_DM_STRONG          PIN_DM_STRONG
#define ATTN_SEL3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ATTN_SEL3_MASK               ATTN_SEL3__MASK
#define ATTN_SEL3_SHIFT              ATTN_SEL3__SHIFT
#define ATTN_SEL3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ATTN_SEL3_PS                     (* (reg8 *) ATTN_SEL3__PS)
/* Data Register */
#define ATTN_SEL3_DR                     (* (reg8 *) ATTN_SEL3__DR)
/* Port Number */
#define ATTN_SEL3_PRT_NUM                (* (reg8 *) ATTN_SEL3__PRT) 
/* Connect to Analog Globals */                                                  
#define ATTN_SEL3_AG                     (* (reg8 *) ATTN_SEL3__AG)                       
/* Analog MUX bux enable */
#define ATTN_SEL3_AMUX                   (* (reg8 *) ATTN_SEL3__AMUX) 
/* Bidirectional Enable */                                                        
#define ATTN_SEL3_BIE                    (* (reg8 *) ATTN_SEL3__BIE)
/* Bit-mask for Aliased Register Access */
#define ATTN_SEL3_BIT_MASK               (* (reg8 *) ATTN_SEL3__BIT_MASK)
/* Bypass Enable */
#define ATTN_SEL3_BYP                    (* (reg8 *) ATTN_SEL3__BYP)
/* Port wide control signals */                                                   
#define ATTN_SEL3_CTL                    (* (reg8 *) ATTN_SEL3__CTL)
/* Drive Modes */
#define ATTN_SEL3_DM0                    (* (reg8 *) ATTN_SEL3__DM0) 
#define ATTN_SEL3_DM1                    (* (reg8 *) ATTN_SEL3__DM1)
#define ATTN_SEL3_DM2                    (* (reg8 *) ATTN_SEL3__DM2) 
/* Input Buffer Disable Override */
#define ATTN_SEL3_INP_DIS                (* (reg8 *) ATTN_SEL3__INP_DIS)
/* LCD Common or Segment Drive */
#define ATTN_SEL3_LCD_COM_SEG            (* (reg8 *) ATTN_SEL3__LCD_COM_SEG)
/* Enable Segment LCD */
#define ATTN_SEL3_LCD_EN                 (* (reg8 *) ATTN_SEL3__LCD_EN)
/* Slew Rate Control */
#define ATTN_SEL3_SLW                    (* (reg8 *) ATTN_SEL3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ATTN_SEL3_PRTDSI__CAPS_SEL       (* (reg8 *) ATTN_SEL3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ATTN_SEL3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ATTN_SEL3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ATTN_SEL3_PRTDSI__OE_SEL0        (* (reg8 *) ATTN_SEL3__PRTDSI__OE_SEL0) 
#define ATTN_SEL3_PRTDSI__OE_SEL1        (* (reg8 *) ATTN_SEL3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ATTN_SEL3_PRTDSI__OUT_SEL0       (* (reg8 *) ATTN_SEL3__PRTDSI__OUT_SEL0) 
#define ATTN_SEL3_PRTDSI__OUT_SEL1       (* (reg8 *) ATTN_SEL3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ATTN_SEL3_PRTDSI__SYNC_OUT       (* (reg8 *) ATTN_SEL3__PRTDSI__SYNC_OUT) 


#if defined(ATTN_SEL3__INTSTAT)  /* Interrupt Registers */

    #define ATTN_SEL3_INTSTAT                (* (reg8 *) ATTN_SEL3__INTSTAT)
    #define ATTN_SEL3_SNAP                   (* (reg8 *) ATTN_SEL3__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ATTN_SEL3_H */


/* [] END OF FILE */
