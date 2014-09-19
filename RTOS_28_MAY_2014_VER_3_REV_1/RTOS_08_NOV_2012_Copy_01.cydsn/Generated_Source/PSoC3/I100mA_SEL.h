/*******************************************************************************
* File Name: I100mA_SEL.h  
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

#if !defined(CY_PINS_I100mA_SEL_H) /* Pins I100mA_SEL_H */
#define CY_PINS_I100mA_SEL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "I100mA_SEL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    I100mA_SEL_Write(uint8 value) ;
void    I100mA_SEL_SetDriveMode(uint8 mode) ;
uint8   I100mA_SEL_ReadDataReg(void) ;
uint8   I100mA_SEL_Read(void) ;
uint8   I100mA_SEL_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define I100mA_SEL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define I100mA_SEL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define I100mA_SEL_DM_RES_UP          PIN_DM_RES_UP
#define I100mA_SEL_DM_RES_DWN         PIN_DM_RES_DWN
#define I100mA_SEL_DM_OD_LO           PIN_DM_OD_LO
#define I100mA_SEL_DM_OD_HI           PIN_DM_OD_HI
#define I100mA_SEL_DM_STRONG          PIN_DM_STRONG
#define I100mA_SEL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define I100mA_SEL_MASK               I100mA_SEL__MASK
#define I100mA_SEL_SHIFT              I100mA_SEL__SHIFT
#define I100mA_SEL_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define I100mA_SEL_PS                     (* (reg8 *) I100mA_SEL__PS)
/* Data Register */
#define I100mA_SEL_DR                     (* (reg8 *) I100mA_SEL__DR)
/* Port Number */
#define I100mA_SEL_PRT_NUM                (* (reg8 *) I100mA_SEL__PRT) 
/* Connect to Analog Globals */                                                  
#define I100mA_SEL_AG                     (* (reg8 *) I100mA_SEL__AG)                       
/* Analog MUX bux enable */
#define I100mA_SEL_AMUX                   (* (reg8 *) I100mA_SEL__AMUX) 
/* Bidirectional Enable */                                                        
#define I100mA_SEL_BIE                    (* (reg8 *) I100mA_SEL__BIE)
/* Bit-mask for Aliased Register Access */
#define I100mA_SEL_BIT_MASK               (* (reg8 *) I100mA_SEL__BIT_MASK)
/* Bypass Enable */
#define I100mA_SEL_BYP                    (* (reg8 *) I100mA_SEL__BYP)
/* Port wide control signals */                                                   
#define I100mA_SEL_CTL                    (* (reg8 *) I100mA_SEL__CTL)
/* Drive Modes */
#define I100mA_SEL_DM0                    (* (reg8 *) I100mA_SEL__DM0) 
#define I100mA_SEL_DM1                    (* (reg8 *) I100mA_SEL__DM1)
#define I100mA_SEL_DM2                    (* (reg8 *) I100mA_SEL__DM2) 
/* Input Buffer Disable Override */
#define I100mA_SEL_INP_DIS                (* (reg8 *) I100mA_SEL__INP_DIS)
/* LCD Common or Segment Drive */
#define I100mA_SEL_LCD_COM_SEG            (* (reg8 *) I100mA_SEL__LCD_COM_SEG)
/* Enable Segment LCD */
#define I100mA_SEL_LCD_EN                 (* (reg8 *) I100mA_SEL__LCD_EN)
/* Slew Rate Control */
#define I100mA_SEL_SLW                    (* (reg8 *) I100mA_SEL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define I100mA_SEL_PRTDSI__CAPS_SEL       (* (reg8 *) I100mA_SEL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define I100mA_SEL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) I100mA_SEL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define I100mA_SEL_PRTDSI__OE_SEL0        (* (reg8 *) I100mA_SEL__PRTDSI__OE_SEL0) 
#define I100mA_SEL_PRTDSI__OE_SEL1        (* (reg8 *) I100mA_SEL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define I100mA_SEL_PRTDSI__OUT_SEL0       (* (reg8 *) I100mA_SEL__PRTDSI__OUT_SEL0) 
#define I100mA_SEL_PRTDSI__OUT_SEL1       (* (reg8 *) I100mA_SEL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define I100mA_SEL_PRTDSI__SYNC_OUT       (* (reg8 *) I100mA_SEL__PRTDSI__SYNC_OUT) 


#if defined(I100mA_SEL__INTSTAT)  /* Interrupt Registers */

    #define I100mA_SEL_INTSTAT                (* (reg8 *) I100mA_SEL__INTSTAT)
    #define I100mA_SEL_SNAP                   (* (reg8 *) I100mA_SEL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins I100mA_SEL_H */


/* [] END OF FILE */
