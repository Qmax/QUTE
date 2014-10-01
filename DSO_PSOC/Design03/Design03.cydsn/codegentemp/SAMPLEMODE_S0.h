/*******************************************************************************
* File Name: SAMPLEMODE_S0.h  
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

#if !defined(CY_PINS_SAMPLEMODE_S0_H) /* Pins SAMPLEMODE_S0_H */
#define CY_PINS_SAMPLEMODE_S0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SAMPLEMODE_S0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SAMPLEMODE_S0_Write(uint8 value) ;
void    SAMPLEMODE_S0_SetDriveMode(uint8 mode) ;
uint8   SAMPLEMODE_S0_ReadDataReg(void) ;
uint8   SAMPLEMODE_S0_Read(void) ;
uint8   SAMPLEMODE_S0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SAMPLEMODE_S0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SAMPLEMODE_S0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SAMPLEMODE_S0_DM_RES_UP          PIN_DM_RES_UP
#define SAMPLEMODE_S0_DM_RES_DWN         PIN_DM_RES_DWN
#define SAMPLEMODE_S0_DM_OD_LO           PIN_DM_OD_LO
#define SAMPLEMODE_S0_DM_OD_HI           PIN_DM_OD_HI
#define SAMPLEMODE_S0_DM_STRONG          PIN_DM_STRONG
#define SAMPLEMODE_S0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SAMPLEMODE_S0_MASK               SAMPLEMODE_S0__MASK
#define SAMPLEMODE_S0_SHIFT              SAMPLEMODE_S0__SHIFT
#define SAMPLEMODE_S0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SAMPLEMODE_S0_PS                     (* (reg8 *) SAMPLEMODE_S0__PS)
/* Data Register */
#define SAMPLEMODE_S0_DR                     (* (reg8 *) SAMPLEMODE_S0__DR)
/* Port Number */
#define SAMPLEMODE_S0_PRT_NUM                (* (reg8 *) SAMPLEMODE_S0__PRT) 
/* Connect to Analog Globals */                                                  
#define SAMPLEMODE_S0_AG                     (* (reg8 *) SAMPLEMODE_S0__AG)                       
/* Analog MUX bux enable */
#define SAMPLEMODE_S0_AMUX                   (* (reg8 *) SAMPLEMODE_S0__AMUX) 
/* Bidirectional Enable */                                                        
#define SAMPLEMODE_S0_BIE                    (* (reg8 *) SAMPLEMODE_S0__BIE)
/* Bit-mask for Aliased Register Access */
#define SAMPLEMODE_S0_BIT_MASK               (* (reg8 *) SAMPLEMODE_S0__BIT_MASK)
/* Bypass Enable */
#define SAMPLEMODE_S0_BYP                    (* (reg8 *) SAMPLEMODE_S0__BYP)
/* Port wide control signals */                                                   
#define SAMPLEMODE_S0_CTL                    (* (reg8 *) SAMPLEMODE_S0__CTL)
/* Drive Modes */
#define SAMPLEMODE_S0_DM0                    (* (reg8 *) SAMPLEMODE_S0__DM0) 
#define SAMPLEMODE_S0_DM1                    (* (reg8 *) SAMPLEMODE_S0__DM1)
#define SAMPLEMODE_S0_DM2                    (* (reg8 *) SAMPLEMODE_S0__DM2) 
/* Input Buffer Disable Override */
#define SAMPLEMODE_S0_INP_DIS                (* (reg8 *) SAMPLEMODE_S0__INP_DIS)
/* LCD Common or Segment Drive */
#define SAMPLEMODE_S0_LCD_COM_SEG            (* (reg8 *) SAMPLEMODE_S0__LCD_COM_SEG)
/* Enable Segment LCD */
#define SAMPLEMODE_S0_LCD_EN                 (* (reg8 *) SAMPLEMODE_S0__LCD_EN)
/* Slew Rate Control */
#define SAMPLEMODE_S0_SLW                    (* (reg8 *) SAMPLEMODE_S0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SAMPLEMODE_S0_PRTDSI__CAPS_SEL       (* (reg8 *) SAMPLEMODE_S0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SAMPLEMODE_S0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SAMPLEMODE_S0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SAMPLEMODE_S0_PRTDSI__OE_SEL0        (* (reg8 *) SAMPLEMODE_S0__PRTDSI__OE_SEL0) 
#define SAMPLEMODE_S0_PRTDSI__OE_SEL1        (* (reg8 *) SAMPLEMODE_S0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SAMPLEMODE_S0_PRTDSI__OUT_SEL0       (* (reg8 *) SAMPLEMODE_S0__PRTDSI__OUT_SEL0) 
#define SAMPLEMODE_S0_PRTDSI__OUT_SEL1       (* (reg8 *) SAMPLEMODE_S0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SAMPLEMODE_S0_PRTDSI__SYNC_OUT       (* (reg8 *) SAMPLEMODE_S0__PRTDSI__SYNC_OUT) 


#if defined(SAMPLEMODE_S0__INTSTAT)  /* Interrupt Registers */

    #define SAMPLEMODE_S0_INTSTAT                (* (reg8 *) SAMPLEMODE_S0__INTSTAT)
    #define SAMPLEMODE_S0_SNAP                   (* (reg8 *) SAMPLEMODE_S0__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins SAMPLEMODE_S0_H */


/* [] END OF FILE */
