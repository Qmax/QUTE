/*******************************************************************************
* File Name: RR1_1V.h  
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

#if !defined(CY_PINS_RR1_1V_H) /* Pins RR1_1V_H */
#define CY_PINS_RR1_1V_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RR1_1V_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RR1_1V_Write(uint8 value) ;
void    RR1_1V_SetDriveMode(uint8 mode) ;
uint8   RR1_1V_ReadDataReg(void) ;
uint8   RR1_1V_Read(void) ;
uint8   RR1_1V_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RR1_1V_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RR1_1V_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RR1_1V_DM_RES_UP          PIN_DM_RES_UP
#define RR1_1V_DM_RES_DWN         PIN_DM_RES_DWN
#define RR1_1V_DM_OD_LO           PIN_DM_OD_LO
#define RR1_1V_DM_OD_HI           PIN_DM_OD_HI
#define RR1_1V_DM_STRONG          PIN_DM_STRONG
#define RR1_1V_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RR1_1V_MASK               RR1_1V__MASK
#define RR1_1V_SHIFT              RR1_1V__SHIFT
#define RR1_1V_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RR1_1V_PS                     (* (reg8 *) RR1_1V__PS)
/* Data Register */
#define RR1_1V_DR                     (* (reg8 *) RR1_1V__DR)
/* Port Number */
#define RR1_1V_PRT_NUM                (* (reg8 *) RR1_1V__PRT) 
/* Connect to Analog Globals */                                                  
#define RR1_1V_AG                     (* (reg8 *) RR1_1V__AG)                       
/* Analog MUX bux enable */
#define RR1_1V_AMUX                   (* (reg8 *) RR1_1V__AMUX) 
/* Bidirectional Enable */                                                        
#define RR1_1V_BIE                    (* (reg8 *) RR1_1V__BIE)
/* Bit-mask for Aliased Register Access */
#define RR1_1V_BIT_MASK               (* (reg8 *) RR1_1V__BIT_MASK)
/* Bypass Enable */
#define RR1_1V_BYP                    (* (reg8 *) RR1_1V__BYP)
/* Port wide control signals */                                                   
#define RR1_1V_CTL                    (* (reg8 *) RR1_1V__CTL)
/* Drive Modes */
#define RR1_1V_DM0                    (* (reg8 *) RR1_1V__DM0) 
#define RR1_1V_DM1                    (* (reg8 *) RR1_1V__DM1)
#define RR1_1V_DM2                    (* (reg8 *) RR1_1V__DM2) 
/* Input Buffer Disable Override */
#define RR1_1V_INP_DIS                (* (reg8 *) RR1_1V__INP_DIS)
/* LCD Common or Segment Drive */
#define RR1_1V_LCD_COM_SEG            (* (reg8 *) RR1_1V__LCD_COM_SEG)
/* Enable Segment LCD */
#define RR1_1V_LCD_EN                 (* (reg8 *) RR1_1V__LCD_EN)
/* Slew Rate Control */
#define RR1_1V_SLW                    (* (reg8 *) RR1_1V__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RR1_1V_PRTDSI__CAPS_SEL       (* (reg8 *) RR1_1V__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RR1_1V_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RR1_1V__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RR1_1V_PRTDSI__OE_SEL0        (* (reg8 *) RR1_1V__PRTDSI__OE_SEL0) 
#define RR1_1V_PRTDSI__OE_SEL1        (* (reg8 *) RR1_1V__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RR1_1V_PRTDSI__OUT_SEL0       (* (reg8 *) RR1_1V__PRTDSI__OUT_SEL0) 
#define RR1_1V_PRTDSI__OUT_SEL1       (* (reg8 *) RR1_1V__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RR1_1V_PRTDSI__SYNC_OUT       (* (reg8 *) RR1_1V__PRTDSI__SYNC_OUT) 


#if defined(RR1_1V__INTSTAT)  /* Interrupt Registers */

    #define RR1_1V_INTSTAT                (* (reg8 *) RR1_1V__INTSTAT)
    #define RR1_1V_SNAP                   (* (reg8 *) RR1_1V__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins RR1_1V_H */


/* [] END OF FILE */