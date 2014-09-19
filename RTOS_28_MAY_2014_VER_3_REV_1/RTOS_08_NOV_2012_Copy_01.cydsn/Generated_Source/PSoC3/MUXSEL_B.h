/*******************************************************************************
* File Name: MUXSEL_B.h  
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

#if !defined(CY_PINS_MUXSEL_B_H) /* Pins MUXSEL_B_H */
#define CY_PINS_MUXSEL_B_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MUXSEL_B_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    MUXSEL_B_Write(uint8 value) ;
void    MUXSEL_B_SetDriveMode(uint8 mode) ;
uint8   MUXSEL_B_ReadDataReg(void) ;
uint8   MUXSEL_B_Read(void) ;
uint8   MUXSEL_B_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MUXSEL_B_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MUXSEL_B_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MUXSEL_B_DM_RES_UP          PIN_DM_RES_UP
#define MUXSEL_B_DM_RES_DWN         PIN_DM_RES_DWN
#define MUXSEL_B_DM_OD_LO           PIN_DM_OD_LO
#define MUXSEL_B_DM_OD_HI           PIN_DM_OD_HI
#define MUXSEL_B_DM_STRONG          PIN_DM_STRONG
#define MUXSEL_B_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MUXSEL_B_MASK               MUXSEL_B__MASK
#define MUXSEL_B_SHIFT              MUXSEL_B__SHIFT
#define MUXSEL_B_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MUXSEL_B_PS                     (* (reg8 *) MUXSEL_B__PS)
/* Data Register */
#define MUXSEL_B_DR                     (* (reg8 *) MUXSEL_B__DR)
/* Port Number */
#define MUXSEL_B_PRT_NUM                (* (reg8 *) MUXSEL_B__PRT) 
/* Connect to Analog Globals */                                                  
#define MUXSEL_B_AG                     (* (reg8 *) MUXSEL_B__AG)                       
/* Analog MUX bux enable */
#define MUXSEL_B_AMUX                   (* (reg8 *) MUXSEL_B__AMUX) 
/* Bidirectional Enable */                                                        
#define MUXSEL_B_BIE                    (* (reg8 *) MUXSEL_B__BIE)
/* Bit-mask for Aliased Register Access */
#define MUXSEL_B_BIT_MASK               (* (reg8 *) MUXSEL_B__BIT_MASK)
/* Bypass Enable */
#define MUXSEL_B_BYP                    (* (reg8 *) MUXSEL_B__BYP)
/* Port wide control signals */                                                   
#define MUXSEL_B_CTL                    (* (reg8 *) MUXSEL_B__CTL)
/* Drive Modes */
#define MUXSEL_B_DM0                    (* (reg8 *) MUXSEL_B__DM0) 
#define MUXSEL_B_DM1                    (* (reg8 *) MUXSEL_B__DM1)
#define MUXSEL_B_DM2                    (* (reg8 *) MUXSEL_B__DM2) 
/* Input Buffer Disable Override */
#define MUXSEL_B_INP_DIS                (* (reg8 *) MUXSEL_B__INP_DIS)
/* LCD Common or Segment Drive */
#define MUXSEL_B_LCD_COM_SEG            (* (reg8 *) MUXSEL_B__LCD_COM_SEG)
/* Enable Segment LCD */
#define MUXSEL_B_LCD_EN                 (* (reg8 *) MUXSEL_B__LCD_EN)
/* Slew Rate Control */
#define MUXSEL_B_SLW                    (* (reg8 *) MUXSEL_B__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MUXSEL_B_PRTDSI__CAPS_SEL       (* (reg8 *) MUXSEL_B__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MUXSEL_B_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MUXSEL_B__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MUXSEL_B_PRTDSI__OE_SEL0        (* (reg8 *) MUXSEL_B__PRTDSI__OE_SEL0) 
#define MUXSEL_B_PRTDSI__OE_SEL1        (* (reg8 *) MUXSEL_B__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MUXSEL_B_PRTDSI__OUT_SEL0       (* (reg8 *) MUXSEL_B__PRTDSI__OUT_SEL0) 
#define MUXSEL_B_PRTDSI__OUT_SEL1       (* (reg8 *) MUXSEL_B__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MUXSEL_B_PRTDSI__SYNC_OUT       (* (reg8 *) MUXSEL_B__PRTDSI__SYNC_OUT) 


#if defined(MUXSEL_B__INTSTAT)  /* Interrupt Registers */

    #define MUXSEL_B_INTSTAT                (* (reg8 *) MUXSEL_B__INTSTAT)
    #define MUXSEL_B_SNAP                   (* (reg8 *) MUXSEL_B__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins MUXSEL_B_H */


/* [] END OF FILE */
