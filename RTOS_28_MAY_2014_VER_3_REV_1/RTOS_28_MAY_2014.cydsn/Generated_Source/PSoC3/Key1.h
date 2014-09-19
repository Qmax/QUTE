/*******************************************************************************
* File Name: Key1.h  
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

#if !defined(CY_PINS_Key1_H) /* Pins Key1_H */
#define CY_PINS_Key1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Key1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Key1_Write(uint8 value) ;
void    Key1_SetDriveMode(uint8 mode) ;
uint8   Key1_ReadDataReg(void) ;
uint8   Key1_Read(void) ;
uint8   Key1_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Key1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Key1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Key1_DM_RES_UP          PIN_DM_RES_UP
#define Key1_DM_RES_DWN         PIN_DM_RES_DWN
#define Key1_DM_OD_LO           PIN_DM_OD_LO
#define Key1_DM_OD_HI           PIN_DM_OD_HI
#define Key1_DM_STRONG          PIN_DM_STRONG
#define Key1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Key1_MASK               Key1__MASK
#define Key1_SHIFT              Key1__SHIFT
#define Key1_WIDTH              3u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Key1_PS                     (* (reg8 *) Key1__PS)
/* Data Register */
#define Key1_DR                     (* (reg8 *) Key1__DR)
/* Port Number */
#define Key1_PRT_NUM                (* (reg8 *) Key1__PRT) 
/* Connect to Analog Globals */                                                  
#define Key1_AG                     (* (reg8 *) Key1__AG)                       
/* Analog MUX bux enable */
#define Key1_AMUX                   (* (reg8 *) Key1__AMUX) 
/* Bidirectional Enable */                                                        
#define Key1_BIE                    (* (reg8 *) Key1__BIE)
/* Bit-mask for Aliased Register Access */
#define Key1_BIT_MASK               (* (reg8 *) Key1__BIT_MASK)
/* Bypass Enable */
#define Key1_BYP                    (* (reg8 *) Key1__BYP)
/* Port wide control signals */                                                   
#define Key1_CTL                    (* (reg8 *) Key1__CTL)
/* Drive Modes */
#define Key1_DM0                    (* (reg8 *) Key1__DM0) 
#define Key1_DM1                    (* (reg8 *) Key1__DM1)
#define Key1_DM2                    (* (reg8 *) Key1__DM2) 
/* Input Buffer Disable Override */
#define Key1_INP_DIS                (* (reg8 *) Key1__INP_DIS)
/* LCD Common or Segment Drive */
#define Key1_LCD_COM_SEG            (* (reg8 *) Key1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Key1_LCD_EN                 (* (reg8 *) Key1__LCD_EN)
/* Slew Rate Control */
#define Key1_SLW                    (* (reg8 *) Key1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Key1_PRTDSI__CAPS_SEL       (* (reg8 *) Key1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Key1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Key1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Key1_PRTDSI__OE_SEL0        (* (reg8 *) Key1__PRTDSI__OE_SEL0) 
#define Key1_PRTDSI__OE_SEL1        (* (reg8 *) Key1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Key1_PRTDSI__OUT_SEL0       (* (reg8 *) Key1__PRTDSI__OUT_SEL0) 
#define Key1_PRTDSI__OUT_SEL1       (* (reg8 *) Key1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Key1_PRTDSI__SYNC_OUT       (* (reg8 *) Key1__PRTDSI__SYNC_OUT) 


#if defined(Key1__INTSTAT)  /* Interrupt Registers */

    #define Key1_INTSTAT                (* (reg8 *) Key1__INTSTAT)
    #define Key1_SNAP                   (* (reg8 *) Key1__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Key1_H */


/* [] END OF FILE */
