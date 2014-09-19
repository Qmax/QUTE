/*******************************************************************************
* File Name: EN_CHA.h  
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

#if !defined(CY_PINS_EN_CHA_H) /* Pins EN_CHA_H */
#define CY_PINS_EN_CHA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EN_CHA_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    EN_CHA_Write(uint8 value) ;
void    EN_CHA_SetDriveMode(uint8 mode) ;
uint8   EN_CHA_ReadDataReg(void) ;
uint8   EN_CHA_Read(void) ;
uint8   EN_CHA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EN_CHA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EN_CHA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EN_CHA_DM_RES_UP          PIN_DM_RES_UP
#define EN_CHA_DM_RES_DWN         PIN_DM_RES_DWN
#define EN_CHA_DM_OD_LO           PIN_DM_OD_LO
#define EN_CHA_DM_OD_HI           PIN_DM_OD_HI
#define EN_CHA_DM_STRONG          PIN_DM_STRONG
#define EN_CHA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EN_CHA_MASK               EN_CHA__MASK
#define EN_CHA_SHIFT              EN_CHA__SHIFT
#define EN_CHA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EN_CHA_PS                     (* (reg8 *) EN_CHA__PS)
/* Data Register */
#define EN_CHA_DR                     (* (reg8 *) EN_CHA__DR)
/* Port Number */
#define EN_CHA_PRT_NUM                (* (reg8 *) EN_CHA__PRT) 
/* Connect to Analog Globals */                                                  
#define EN_CHA_AG                     (* (reg8 *) EN_CHA__AG)                       
/* Analog MUX bux enable */
#define EN_CHA_AMUX                   (* (reg8 *) EN_CHA__AMUX) 
/* Bidirectional Enable */                                                        
#define EN_CHA_BIE                    (* (reg8 *) EN_CHA__BIE)
/* Bit-mask for Aliased Register Access */
#define EN_CHA_BIT_MASK               (* (reg8 *) EN_CHA__BIT_MASK)
/* Bypass Enable */
#define EN_CHA_BYP                    (* (reg8 *) EN_CHA__BYP)
/* Port wide control signals */                                                   
#define EN_CHA_CTL                    (* (reg8 *) EN_CHA__CTL)
/* Drive Modes */
#define EN_CHA_DM0                    (* (reg8 *) EN_CHA__DM0) 
#define EN_CHA_DM1                    (* (reg8 *) EN_CHA__DM1)
#define EN_CHA_DM2                    (* (reg8 *) EN_CHA__DM2) 
/* Input Buffer Disable Override */
#define EN_CHA_INP_DIS                (* (reg8 *) EN_CHA__INP_DIS)
/* LCD Common or Segment Drive */
#define EN_CHA_LCD_COM_SEG            (* (reg8 *) EN_CHA__LCD_COM_SEG)
/* Enable Segment LCD */
#define EN_CHA_LCD_EN                 (* (reg8 *) EN_CHA__LCD_EN)
/* Slew Rate Control */
#define EN_CHA_SLW                    (* (reg8 *) EN_CHA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EN_CHA_PRTDSI__CAPS_SEL       (* (reg8 *) EN_CHA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EN_CHA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EN_CHA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EN_CHA_PRTDSI__OE_SEL0        (* (reg8 *) EN_CHA__PRTDSI__OE_SEL0) 
#define EN_CHA_PRTDSI__OE_SEL1        (* (reg8 *) EN_CHA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EN_CHA_PRTDSI__OUT_SEL0       (* (reg8 *) EN_CHA__PRTDSI__OUT_SEL0) 
#define EN_CHA_PRTDSI__OUT_SEL1       (* (reg8 *) EN_CHA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EN_CHA_PRTDSI__SYNC_OUT       (* (reg8 *) EN_CHA__PRTDSI__SYNC_OUT) 


#if defined(EN_CHA__INTSTAT)  /* Interrupt Registers */

    #define EN_CHA_INTSTAT                (* (reg8 *) EN_CHA__INTSTAT)
    #define EN_CHA_SNAP                   (* (reg8 *) EN_CHA__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins EN_CHA_H */


/* [] END OF FILE */
