/*******************************************************************************
* File Name: MUXSEL_B0.h  
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

#if !defined(CY_PINS_MUXSEL_B0_H) /* Pins MUXSEL_B0_H */
#define CY_PINS_MUXSEL_B0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MUXSEL_B0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    MUXSEL_B0_Write(uint8 value) ;
void    MUXSEL_B0_SetDriveMode(uint8 mode) ;
uint8   MUXSEL_B0_ReadDataReg(void) ;
uint8   MUXSEL_B0_Read(void) ;
uint8   MUXSEL_B0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MUXSEL_B0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MUXSEL_B0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MUXSEL_B0_DM_RES_UP          PIN_DM_RES_UP
#define MUXSEL_B0_DM_RES_DWN         PIN_DM_RES_DWN
#define MUXSEL_B0_DM_OD_LO           PIN_DM_OD_LO
#define MUXSEL_B0_DM_OD_HI           PIN_DM_OD_HI
#define MUXSEL_B0_DM_STRONG          PIN_DM_STRONG
#define MUXSEL_B0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MUXSEL_B0_MASK               MUXSEL_B0__MASK
#define MUXSEL_B0_SHIFT              MUXSEL_B0__SHIFT
#define MUXSEL_B0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MUXSEL_B0_PS                     (* (reg8 *) MUXSEL_B0__PS)
/* Data Register */
#define MUXSEL_B0_DR                     (* (reg8 *) MUXSEL_B0__DR)
/* Port Number */
#define MUXSEL_B0_PRT_NUM                (* (reg8 *) MUXSEL_B0__PRT) 
/* Connect to Analog Globals */                                                  
#define MUXSEL_B0_AG                     (* (reg8 *) MUXSEL_B0__AG)                       
/* Analog MUX bux enable */
#define MUXSEL_B0_AMUX                   (* (reg8 *) MUXSEL_B0__AMUX) 
/* Bidirectional Enable */                                                        
#define MUXSEL_B0_BIE                    (* (reg8 *) MUXSEL_B0__BIE)
/* Bit-mask for Aliased Register Access */
#define MUXSEL_B0_BIT_MASK               (* (reg8 *) MUXSEL_B0__BIT_MASK)
/* Bypass Enable */
#define MUXSEL_B0_BYP                    (* (reg8 *) MUXSEL_B0__BYP)
/* Port wide control signals */                                                   
#define MUXSEL_B0_CTL                    (* (reg8 *) MUXSEL_B0__CTL)
/* Drive Modes */
#define MUXSEL_B0_DM0                    (* (reg8 *) MUXSEL_B0__DM0) 
#define MUXSEL_B0_DM1                    (* (reg8 *) MUXSEL_B0__DM1)
#define MUXSEL_B0_DM2                    (* (reg8 *) MUXSEL_B0__DM2) 
/* Input Buffer Disable Override */
#define MUXSEL_B0_INP_DIS                (* (reg8 *) MUXSEL_B0__INP_DIS)
/* LCD Common or Segment Drive */
#define MUXSEL_B0_LCD_COM_SEG            (* (reg8 *) MUXSEL_B0__LCD_COM_SEG)
/* Enable Segment LCD */
#define MUXSEL_B0_LCD_EN                 (* (reg8 *) MUXSEL_B0__LCD_EN)
/* Slew Rate Control */
#define MUXSEL_B0_SLW                    (* (reg8 *) MUXSEL_B0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MUXSEL_B0_PRTDSI__CAPS_SEL       (* (reg8 *) MUXSEL_B0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MUXSEL_B0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MUXSEL_B0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MUXSEL_B0_PRTDSI__OE_SEL0        (* (reg8 *) MUXSEL_B0__PRTDSI__OE_SEL0) 
#define MUXSEL_B0_PRTDSI__OE_SEL1        (* (reg8 *) MUXSEL_B0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MUXSEL_B0_PRTDSI__OUT_SEL0       (* (reg8 *) MUXSEL_B0__PRTDSI__OUT_SEL0) 
#define MUXSEL_B0_PRTDSI__OUT_SEL1       (* (reg8 *) MUXSEL_B0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MUXSEL_B0_PRTDSI__SYNC_OUT       (* (reg8 *) MUXSEL_B0__PRTDSI__SYNC_OUT) 


#if defined(MUXSEL_B0__INTSTAT)  /* Interrupt Registers */

    #define MUXSEL_B0_INTSTAT                (* (reg8 *) MUXSEL_B0__INTSTAT)
    #define MUXSEL_B0_SNAP                   (* (reg8 *) MUXSEL_B0__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins MUXSEL_B0_H */


/* [] END OF FILE */
