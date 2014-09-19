/*******************************************************************************
* File Name: MUXSEL_A.h  
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

#if !defined(CY_PINS_MUXSEL_A_H) /* Pins MUXSEL_A_H */
#define CY_PINS_MUXSEL_A_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MUXSEL_A_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    MUXSEL_A_Write(uint8 value) ;
void    MUXSEL_A_SetDriveMode(uint8 mode) ;
uint8   MUXSEL_A_ReadDataReg(void) ;
uint8   MUXSEL_A_Read(void) ;
uint8   MUXSEL_A_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MUXSEL_A_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MUXSEL_A_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MUXSEL_A_DM_RES_UP          PIN_DM_RES_UP
#define MUXSEL_A_DM_RES_DWN         PIN_DM_RES_DWN
#define MUXSEL_A_DM_OD_LO           PIN_DM_OD_LO
#define MUXSEL_A_DM_OD_HI           PIN_DM_OD_HI
#define MUXSEL_A_DM_STRONG          PIN_DM_STRONG
#define MUXSEL_A_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MUXSEL_A_MASK               MUXSEL_A__MASK
#define MUXSEL_A_SHIFT              MUXSEL_A__SHIFT
#define MUXSEL_A_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MUXSEL_A_PS                     (* (reg8 *) MUXSEL_A__PS)
/* Data Register */
#define MUXSEL_A_DR                     (* (reg8 *) MUXSEL_A__DR)
/* Port Number */
#define MUXSEL_A_PRT_NUM                (* (reg8 *) MUXSEL_A__PRT) 
/* Connect to Analog Globals */                                                  
#define MUXSEL_A_AG                     (* (reg8 *) MUXSEL_A__AG)                       
/* Analog MUX bux enable */
#define MUXSEL_A_AMUX                   (* (reg8 *) MUXSEL_A__AMUX) 
/* Bidirectional Enable */                                                        
#define MUXSEL_A_BIE                    (* (reg8 *) MUXSEL_A__BIE)
/* Bit-mask for Aliased Register Access */
#define MUXSEL_A_BIT_MASK               (* (reg8 *) MUXSEL_A__BIT_MASK)
/* Bypass Enable */
#define MUXSEL_A_BYP                    (* (reg8 *) MUXSEL_A__BYP)
/* Port wide control signals */                                                   
#define MUXSEL_A_CTL                    (* (reg8 *) MUXSEL_A__CTL)
/* Drive Modes */
#define MUXSEL_A_DM0                    (* (reg8 *) MUXSEL_A__DM0) 
#define MUXSEL_A_DM1                    (* (reg8 *) MUXSEL_A__DM1)
#define MUXSEL_A_DM2                    (* (reg8 *) MUXSEL_A__DM2) 
/* Input Buffer Disable Override */
#define MUXSEL_A_INP_DIS                (* (reg8 *) MUXSEL_A__INP_DIS)
/* LCD Common or Segment Drive */
#define MUXSEL_A_LCD_COM_SEG            (* (reg8 *) MUXSEL_A__LCD_COM_SEG)
/* Enable Segment LCD */
#define MUXSEL_A_LCD_EN                 (* (reg8 *) MUXSEL_A__LCD_EN)
/* Slew Rate Control */
#define MUXSEL_A_SLW                    (* (reg8 *) MUXSEL_A__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MUXSEL_A_PRTDSI__CAPS_SEL       (* (reg8 *) MUXSEL_A__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MUXSEL_A_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MUXSEL_A__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MUXSEL_A_PRTDSI__OE_SEL0        (* (reg8 *) MUXSEL_A__PRTDSI__OE_SEL0) 
#define MUXSEL_A_PRTDSI__OE_SEL1        (* (reg8 *) MUXSEL_A__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MUXSEL_A_PRTDSI__OUT_SEL0       (* (reg8 *) MUXSEL_A__PRTDSI__OUT_SEL0) 
#define MUXSEL_A_PRTDSI__OUT_SEL1       (* (reg8 *) MUXSEL_A__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MUXSEL_A_PRTDSI__SYNC_OUT       (* (reg8 *) MUXSEL_A__PRTDSI__SYNC_OUT) 


#if defined(MUXSEL_A__INTSTAT)  /* Interrupt Registers */

    #define MUXSEL_A_INTSTAT                (* (reg8 *) MUXSEL_A__INTSTAT)
    #define MUXSEL_A_SNAP                   (* (reg8 *) MUXSEL_A__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins MUXSEL_A_H */


/* [] END OF FILE */
