/*******************************************************************************
* File Name: S1_100V.h  
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

#if !defined(CY_PINS_S1_100V_H) /* Pins S1_100V_H */
#define CY_PINS_S1_100V_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "S1_100V_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    S1_100V_Write(uint8 value) ;
void    S1_100V_SetDriveMode(uint8 mode) ;
uint8   S1_100V_ReadDataReg(void) ;
uint8   S1_100V_Read(void) ;
uint8   S1_100V_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define S1_100V_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define S1_100V_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define S1_100V_DM_RES_UP          PIN_DM_RES_UP
#define S1_100V_DM_RES_DWN         PIN_DM_RES_DWN
#define S1_100V_DM_OD_LO           PIN_DM_OD_LO
#define S1_100V_DM_OD_HI           PIN_DM_OD_HI
#define S1_100V_DM_STRONG          PIN_DM_STRONG
#define S1_100V_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define S1_100V_MASK               S1_100V__MASK
#define S1_100V_SHIFT              S1_100V__SHIFT
#define S1_100V_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define S1_100V_PS                     (* (reg8 *) S1_100V__PS)
/* Data Register */
#define S1_100V_DR                     (* (reg8 *) S1_100V__DR)
/* Port Number */
#define S1_100V_PRT_NUM                (* (reg8 *) S1_100V__PRT) 
/* Connect to Analog Globals */                                                  
#define S1_100V_AG                     (* (reg8 *) S1_100V__AG)                       
/* Analog MUX bux enable */
#define S1_100V_AMUX                   (* (reg8 *) S1_100V__AMUX) 
/* Bidirectional Enable */                                                        
#define S1_100V_BIE                    (* (reg8 *) S1_100V__BIE)
/* Bit-mask for Aliased Register Access */
#define S1_100V_BIT_MASK               (* (reg8 *) S1_100V__BIT_MASK)
/* Bypass Enable */
#define S1_100V_BYP                    (* (reg8 *) S1_100V__BYP)
/* Port wide control signals */                                                   
#define S1_100V_CTL                    (* (reg8 *) S1_100V__CTL)
/* Drive Modes */
#define S1_100V_DM0                    (* (reg8 *) S1_100V__DM0) 
#define S1_100V_DM1                    (* (reg8 *) S1_100V__DM1)
#define S1_100V_DM2                    (* (reg8 *) S1_100V__DM2) 
/* Input Buffer Disable Override */
#define S1_100V_INP_DIS                (* (reg8 *) S1_100V__INP_DIS)
/* LCD Common or Segment Drive */
#define S1_100V_LCD_COM_SEG            (* (reg8 *) S1_100V__LCD_COM_SEG)
/* Enable Segment LCD */
#define S1_100V_LCD_EN                 (* (reg8 *) S1_100V__LCD_EN)
/* Slew Rate Control */
#define S1_100V_SLW                    (* (reg8 *) S1_100V__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define S1_100V_PRTDSI__CAPS_SEL       (* (reg8 *) S1_100V__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define S1_100V_PRTDSI__DBL_SYNC_IN    (* (reg8 *) S1_100V__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define S1_100V_PRTDSI__OE_SEL0        (* (reg8 *) S1_100V__PRTDSI__OE_SEL0) 
#define S1_100V_PRTDSI__OE_SEL1        (* (reg8 *) S1_100V__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define S1_100V_PRTDSI__OUT_SEL0       (* (reg8 *) S1_100V__PRTDSI__OUT_SEL0) 
#define S1_100V_PRTDSI__OUT_SEL1       (* (reg8 *) S1_100V__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define S1_100V_PRTDSI__SYNC_OUT       (* (reg8 *) S1_100V__PRTDSI__SYNC_OUT) 


#if defined(S1_100V__INTSTAT)  /* Interrupt Registers */

    #define S1_100V_INTSTAT                (* (reg8 *) S1_100V__INTSTAT)
    #define S1_100V_SNAP                   (* (reg8 *) S1_100V__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins S1_100V_H */


/* [] END OF FILE */
