/*******************************************************************************
* File Name: MUXASEL.h  
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

#if !defined(CY_PINS_MUXASEL_H) /* Pins MUXASEL_H */
#define CY_PINS_MUXASEL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MUXASEL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    MUXASEL_Write(uint8 value) ;
void    MUXASEL_SetDriveMode(uint8 mode) ;
uint8   MUXASEL_ReadDataReg(void) ;
uint8   MUXASEL_Read(void) ;
uint8   MUXASEL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MUXASEL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MUXASEL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MUXASEL_DM_RES_UP          PIN_DM_RES_UP
#define MUXASEL_DM_RES_DWN         PIN_DM_RES_DWN
#define MUXASEL_DM_OD_LO           PIN_DM_OD_LO
#define MUXASEL_DM_OD_HI           PIN_DM_OD_HI
#define MUXASEL_DM_STRONG          PIN_DM_STRONG
#define MUXASEL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MUXASEL_MASK               MUXASEL__MASK
#define MUXASEL_SHIFT              MUXASEL__SHIFT
#define MUXASEL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MUXASEL_PS                     (* (reg8 *) MUXASEL__PS)
/* Data Register */
#define MUXASEL_DR                     (* (reg8 *) MUXASEL__DR)
/* Port Number */
#define MUXASEL_PRT_NUM                (* (reg8 *) MUXASEL__PRT) 
/* Connect to Analog Globals */                                                  
#define MUXASEL_AG                     (* (reg8 *) MUXASEL__AG)                       
/* Analog MUX bux enable */
#define MUXASEL_AMUX                   (* (reg8 *) MUXASEL__AMUX) 
/* Bidirectional Enable */                                                        
#define MUXASEL_BIE                    (* (reg8 *) MUXASEL__BIE)
/* Bit-mask for Aliased Register Access */
#define MUXASEL_BIT_MASK               (* (reg8 *) MUXASEL__BIT_MASK)
/* Bypass Enable */
#define MUXASEL_BYP                    (* (reg8 *) MUXASEL__BYP)
/* Port wide control signals */                                                   
#define MUXASEL_CTL                    (* (reg8 *) MUXASEL__CTL)
/* Drive Modes */
#define MUXASEL_DM0                    (* (reg8 *) MUXASEL__DM0) 
#define MUXASEL_DM1                    (* (reg8 *) MUXASEL__DM1)
#define MUXASEL_DM2                    (* (reg8 *) MUXASEL__DM2) 
/* Input Buffer Disable Override */
#define MUXASEL_INP_DIS                (* (reg8 *) MUXASEL__INP_DIS)
/* LCD Common or Segment Drive */
#define MUXASEL_LCD_COM_SEG            (* (reg8 *) MUXASEL__LCD_COM_SEG)
/* Enable Segment LCD */
#define MUXASEL_LCD_EN                 (* (reg8 *) MUXASEL__LCD_EN)
/* Slew Rate Control */
#define MUXASEL_SLW                    (* (reg8 *) MUXASEL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MUXASEL_PRTDSI__CAPS_SEL       (* (reg8 *) MUXASEL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MUXASEL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MUXASEL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MUXASEL_PRTDSI__OE_SEL0        (* (reg8 *) MUXASEL__PRTDSI__OE_SEL0) 
#define MUXASEL_PRTDSI__OE_SEL1        (* (reg8 *) MUXASEL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MUXASEL_PRTDSI__OUT_SEL0       (* (reg8 *) MUXASEL__PRTDSI__OUT_SEL0) 
#define MUXASEL_PRTDSI__OUT_SEL1       (* (reg8 *) MUXASEL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MUXASEL_PRTDSI__SYNC_OUT       (* (reg8 *) MUXASEL__PRTDSI__SYNC_OUT) 


#if defined(MUXASEL__INTSTAT)  /* Interrupt Registers */

    #define MUXASEL_INTSTAT                (* (reg8 *) MUXASEL__INTSTAT)
    #define MUXASEL_SNAP                   (* (reg8 *) MUXASEL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins MUXASEL_H */


/* [] END OF FILE */
