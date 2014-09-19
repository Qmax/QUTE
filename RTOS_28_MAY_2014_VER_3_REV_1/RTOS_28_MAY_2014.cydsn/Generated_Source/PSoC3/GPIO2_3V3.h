/*******************************************************************************
* File Name: GPIO2_3V3.h  
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

#if !defined(CY_PINS_GPIO2_3V3_H) /* Pins GPIO2_3V3_H */
#define CY_PINS_GPIO2_3V3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "GPIO2_3V3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GPIO2_3V3_Write(uint8 value) ;
void    GPIO2_3V3_SetDriveMode(uint8 mode) ;
uint8   GPIO2_3V3_ReadDataReg(void) ;
uint8   GPIO2_3V3_Read(void) ;
uint8   GPIO2_3V3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GPIO2_3V3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define GPIO2_3V3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define GPIO2_3V3_DM_RES_UP          PIN_DM_RES_UP
#define GPIO2_3V3_DM_RES_DWN         PIN_DM_RES_DWN
#define GPIO2_3V3_DM_OD_LO           PIN_DM_OD_LO
#define GPIO2_3V3_DM_OD_HI           PIN_DM_OD_HI
#define GPIO2_3V3_DM_STRONG          PIN_DM_STRONG
#define GPIO2_3V3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define GPIO2_3V3_MASK               GPIO2_3V3__MASK
#define GPIO2_3V3_SHIFT              GPIO2_3V3__SHIFT
#define GPIO2_3V3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GPIO2_3V3_PS                     (* (reg8 *) GPIO2_3V3__PS)
/* Data Register */
#define GPIO2_3V3_DR                     (* (reg8 *) GPIO2_3V3__DR)
/* Port Number */
#define GPIO2_3V3_PRT_NUM                (* (reg8 *) GPIO2_3V3__PRT) 
/* Connect to Analog Globals */                                                  
#define GPIO2_3V3_AG                     (* (reg8 *) GPIO2_3V3__AG)                       
/* Analog MUX bux enable */
#define GPIO2_3V3_AMUX                   (* (reg8 *) GPIO2_3V3__AMUX) 
/* Bidirectional Enable */                                                        
#define GPIO2_3V3_BIE                    (* (reg8 *) GPIO2_3V3__BIE)
/* Bit-mask for Aliased Register Access */
#define GPIO2_3V3_BIT_MASK               (* (reg8 *) GPIO2_3V3__BIT_MASK)
/* Bypass Enable */
#define GPIO2_3V3_BYP                    (* (reg8 *) GPIO2_3V3__BYP)
/* Port wide control signals */                                                   
#define GPIO2_3V3_CTL                    (* (reg8 *) GPIO2_3V3__CTL)
/* Drive Modes */
#define GPIO2_3V3_DM0                    (* (reg8 *) GPIO2_3V3__DM0) 
#define GPIO2_3V3_DM1                    (* (reg8 *) GPIO2_3V3__DM1)
#define GPIO2_3V3_DM2                    (* (reg8 *) GPIO2_3V3__DM2) 
/* Input Buffer Disable Override */
#define GPIO2_3V3_INP_DIS                (* (reg8 *) GPIO2_3V3__INP_DIS)
/* LCD Common or Segment Drive */
#define GPIO2_3V3_LCD_COM_SEG            (* (reg8 *) GPIO2_3V3__LCD_COM_SEG)
/* Enable Segment LCD */
#define GPIO2_3V3_LCD_EN                 (* (reg8 *) GPIO2_3V3__LCD_EN)
/* Slew Rate Control */
#define GPIO2_3V3_SLW                    (* (reg8 *) GPIO2_3V3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define GPIO2_3V3_PRTDSI__CAPS_SEL       (* (reg8 *) GPIO2_3V3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define GPIO2_3V3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) GPIO2_3V3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define GPIO2_3V3_PRTDSI__OE_SEL0        (* (reg8 *) GPIO2_3V3__PRTDSI__OE_SEL0) 
#define GPIO2_3V3_PRTDSI__OE_SEL1        (* (reg8 *) GPIO2_3V3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define GPIO2_3V3_PRTDSI__OUT_SEL0       (* (reg8 *) GPIO2_3V3__PRTDSI__OUT_SEL0) 
#define GPIO2_3V3_PRTDSI__OUT_SEL1       (* (reg8 *) GPIO2_3V3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define GPIO2_3V3_PRTDSI__SYNC_OUT       (* (reg8 *) GPIO2_3V3__PRTDSI__SYNC_OUT) 


#if defined(GPIO2_3V3__INTSTAT)  /* Interrupt Registers */

    #define GPIO2_3V3_INTSTAT                (* (reg8 *) GPIO2_3V3__INTSTAT)
    #define GPIO2_3V3_SNAP                   (* (reg8 *) GPIO2_3V3__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins GPIO2_3V3_H */


/* [] END OF FILE */
