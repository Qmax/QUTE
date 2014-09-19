/*******************************************************************************
* File Name: DIV_SEL2.h  
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

#if !defined(CY_PINS_DIV_SEL2_H) /* Pins DIV_SEL2_H */
#define CY_PINS_DIV_SEL2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIV_SEL2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    DIV_SEL2_Write(uint8 value) ;
void    DIV_SEL2_SetDriveMode(uint8 mode) ;
uint8   DIV_SEL2_ReadDataReg(void) ;
uint8   DIV_SEL2_Read(void) ;
uint8   DIV_SEL2_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DIV_SEL2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DIV_SEL2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DIV_SEL2_DM_RES_UP          PIN_DM_RES_UP
#define DIV_SEL2_DM_RES_DWN         PIN_DM_RES_DWN
#define DIV_SEL2_DM_OD_LO           PIN_DM_OD_LO
#define DIV_SEL2_DM_OD_HI           PIN_DM_OD_HI
#define DIV_SEL2_DM_STRONG          PIN_DM_STRONG
#define DIV_SEL2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DIV_SEL2_MASK               DIV_SEL2__MASK
#define DIV_SEL2_SHIFT              DIV_SEL2__SHIFT
#define DIV_SEL2_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIV_SEL2_PS                     (* (reg8 *) DIV_SEL2__PS)
/* Data Register */
#define DIV_SEL2_DR                     (* (reg8 *) DIV_SEL2__DR)
/* Port Number */
#define DIV_SEL2_PRT_NUM                (* (reg8 *) DIV_SEL2__PRT) 
/* Connect to Analog Globals */                                                  
#define DIV_SEL2_AG                     (* (reg8 *) DIV_SEL2__AG)                       
/* Analog MUX bux enable */
#define DIV_SEL2_AMUX                   (* (reg8 *) DIV_SEL2__AMUX) 
/* Bidirectional Enable */                                                        
#define DIV_SEL2_BIE                    (* (reg8 *) DIV_SEL2__BIE)
/* Bit-mask for Aliased Register Access */
#define DIV_SEL2_BIT_MASK               (* (reg8 *) DIV_SEL2__BIT_MASK)
/* Bypass Enable */
#define DIV_SEL2_BYP                    (* (reg8 *) DIV_SEL2__BYP)
/* Port wide control signals */                                                   
#define DIV_SEL2_CTL                    (* (reg8 *) DIV_SEL2__CTL)
/* Drive Modes */
#define DIV_SEL2_DM0                    (* (reg8 *) DIV_SEL2__DM0) 
#define DIV_SEL2_DM1                    (* (reg8 *) DIV_SEL2__DM1)
#define DIV_SEL2_DM2                    (* (reg8 *) DIV_SEL2__DM2) 
/* Input Buffer Disable Override */
#define DIV_SEL2_INP_DIS                (* (reg8 *) DIV_SEL2__INP_DIS)
/* LCD Common or Segment Drive */
#define DIV_SEL2_LCD_COM_SEG            (* (reg8 *) DIV_SEL2__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIV_SEL2_LCD_EN                 (* (reg8 *) DIV_SEL2__LCD_EN)
/* Slew Rate Control */
#define DIV_SEL2_SLW                    (* (reg8 *) DIV_SEL2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIV_SEL2_PRTDSI__CAPS_SEL       (* (reg8 *) DIV_SEL2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIV_SEL2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIV_SEL2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIV_SEL2_PRTDSI__OE_SEL0        (* (reg8 *) DIV_SEL2__PRTDSI__OE_SEL0) 
#define DIV_SEL2_PRTDSI__OE_SEL1        (* (reg8 *) DIV_SEL2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIV_SEL2_PRTDSI__OUT_SEL0       (* (reg8 *) DIV_SEL2__PRTDSI__OUT_SEL0) 
#define DIV_SEL2_PRTDSI__OUT_SEL1       (* (reg8 *) DIV_SEL2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIV_SEL2_PRTDSI__SYNC_OUT       (* (reg8 *) DIV_SEL2__PRTDSI__SYNC_OUT) 


#if defined(DIV_SEL2__INTSTAT)  /* Interrupt Registers */

    #define DIV_SEL2_INTSTAT                (* (reg8 *) DIV_SEL2__INTSTAT)
    #define DIV_SEL2_SNAP                   (* (reg8 *) DIV_SEL2__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins DIV_SEL2_H */


/* [] END OF FILE */
