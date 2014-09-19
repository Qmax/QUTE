/*******************************************************************************
* File Name: clk_out.h  
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

#if !defined(CY_PINS_clk_out_H) /* Pins clk_out_H */
#define CY_PINS_clk_out_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "clk_out_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    clk_out_Write(uint8 value) ;
void    clk_out_SetDriveMode(uint8 mode) ;
uint8   clk_out_ReadDataReg(void) ;
uint8   clk_out_Read(void) ;
uint8   clk_out_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define clk_out_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define clk_out_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define clk_out_DM_RES_UP          PIN_DM_RES_UP
#define clk_out_DM_RES_DWN         PIN_DM_RES_DWN
#define clk_out_DM_OD_LO           PIN_DM_OD_LO
#define clk_out_DM_OD_HI           PIN_DM_OD_HI
#define clk_out_DM_STRONG          PIN_DM_STRONG
#define clk_out_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define clk_out_MASK               clk_out__MASK
#define clk_out_SHIFT              clk_out__SHIFT
#define clk_out_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define clk_out_PS                     (* (reg8 *) clk_out__PS)
/* Data Register */
#define clk_out_DR                     (* (reg8 *) clk_out__DR)
/* Port Number */
#define clk_out_PRT_NUM                (* (reg8 *) clk_out__PRT) 
/* Connect to Analog Globals */                                                  
#define clk_out_AG                     (* (reg8 *) clk_out__AG)                       
/* Analog MUX bux enable */
#define clk_out_AMUX                   (* (reg8 *) clk_out__AMUX) 
/* Bidirectional Enable */                                                        
#define clk_out_BIE                    (* (reg8 *) clk_out__BIE)
/* Bit-mask for Aliased Register Access */
#define clk_out_BIT_MASK               (* (reg8 *) clk_out__BIT_MASK)
/* Bypass Enable */
#define clk_out_BYP                    (* (reg8 *) clk_out__BYP)
/* Port wide control signals */                                                   
#define clk_out_CTL                    (* (reg8 *) clk_out__CTL)
/* Drive Modes */
#define clk_out_DM0                    (* (reg8 *) clk_out__DM0) 
#define clk_out_DM1                    (* (reg8 *) clk_out__DM1)
#define clk_out_DM2                    (* (reg8 *) clk_out__DM2) 
/* Input Buffer Disable Override */
#define clk_out_INP_DIS                (* (reg8 *) clk_out__INP_DIS)
/* LCD Common or Segment Drive */
#define clk_out_LCD_COM_SEG            (* (reg8 *) clk_out__LCD_COM_SEG)
/* Enable Segment LCD */
#define clk_out_LCD_EN                 (* (reg8 *) clk_out__LCD_EN)
/* Slew Rate Control */
#define clk_out_SLW                    (* (reg8 *) clk_out__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define clk_out_PRTDSI__CAPS_SEL       (* (reg8 *) clk_out__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define clk_out_PRTDSI__DBL_SYNC_IN    (* (reg8 *) clk_out__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define clk_out_PRTDSI__OE_SEL0        (* (reg8 *) clk_out__PRTDSI__OE_SEL0) 
#define clk_out_PRTDSI__OE_SEL1        (* (reg8 *) clk_out__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define clk_out_PRTDSI__OUT_SEL0       (* (reg8 *) clk_out__PRTDSI__OUT_SEL0) 
#define clk_out_PRTDSI__OUT_SEL1       (* (reg8 *) clk_out__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define clk_out_PRTDSI__SYNC_OUT       (* (reg8 *) clk_out__PRTDSI__SYNC_OUT) 


#if defined(clk_out__INTSTAT)  /* Interrupt Registers */

    #define clk_out_INTSTAT                (* (reg8 *) clk_out__INTSTAT)
    #define clk_out_SNAP                   (* (reg8 *) clk_out__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins clk_out_H */


/* [] END OF FILE */
