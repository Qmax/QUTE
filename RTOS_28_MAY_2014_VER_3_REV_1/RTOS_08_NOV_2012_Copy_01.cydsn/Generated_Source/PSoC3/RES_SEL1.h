/*******************************************************************************
* File Name: RES_SEL1.h  
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

#if !defined(CY_PINS_RES_SEL1_H) /* Pins RES_SEL1_H */
#define CY_PINS_RES_SEL1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RES_SEL1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RES_SEL1_Write(uint8 value) ;
void    RES_SEL1_SetDriveMode(uint8 mode) ;
uint8   RES_SEL1_ReadDataReg(void) ;
uint8   RES_SEL1_Read(void) ;
uint8   RES_SEL1_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RES_SEL1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RES_SEL1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RES_SEL1_DM_RES_UP          PIN_DM_RES_UP
#define RES_SEL1_DM_RES_DWN         PIN_DM_RES_DWN
#define RES_SEL1_DM_OD_LO           PIN_DM_OD_LO
#define RES_SEL1_DM_OD_HI           PIN_DM_OD_HI
#define RES_SEL1_DM_STRONG          PIN_DM_STRONG
#define RES_SEL1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RES_SEL1_MASK               RES_SEL1__MASK
#define RES_SEL1_SHIFT              RES_SEL1__SHIFT
#define RES_SEL1_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RES_SEL1_PS                     (* (reg8 *) RES_SEL1__PS)
/* Data Register */
#define RES_SEL1_DR                     (* (reg8 *) RES_SEL1__DR)
/* Port Number */
#define RES_SEL1_PRT_NUM                (* (reg8 *) RES_SEL1__PRT) 
/* Connect to Analog Globals */                                                  
#define RES_SEL1_AG                     (* (reg8 *) RES_SEL1__AG)                       
/* Analog MUX bux enable */
#define RES_SEL1_AMUX                   (* (reg8 *) RES_SEL1__AMUX) 
/* Bidirectional Enable */                                                        
#define RES_SEL1_BIE                    (* (reg8 *) RES_SEL1__BIE)
/* Bit-mask for Aliased Register Access */
#define RES_SEL1_BIT_MASK               (* (reg8 *) RES_SEL1__BIT_MASK)
/* Bypass Enable */
#define RES_SEL1_BYP                    (* (reg8 *) RES_SEL1__BYP)
/* Port wide control signals */                                                   
#define RES_SEL1_CTL                    (* (reg8 *) RES_SEL1__CTL)
/* Drive Modes */
#define RES_SEL1_DM0                    (* (reg8 *) RES_SEL1__DM0) 
#define RES_SEL1_DM1                    (* (reg8 *) RES_SEL1__DM1)
#define RES_SEL1_DM2                    (* (reg8 *) RES_SEL1__DM2) 
/* Input Buffer Disable Override */
#define RES_SEL1_INP_DIS                (* (reg8 *) RES_SEL1__INP_DIS)
/* LCD Common or Segment Drive */
#define RES_SEL1_LCD_COM_SEG            (* (reg8 *) RES_SEL1__LCD_COM_SEG)
/* Enable Segment LCD */
#define RES_SEL1_LCD_EN                 (* (reg8 *) RES_SEL1__LCD_EN)
/* Slew Rate Control */
#define RES_SEL1_SLW                    (* (reg8 *) RES_SEL1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RES_SEL1_PRTDSI__CAPS_SEL       (* (reg8 *) RES_SEL1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RES_SEL1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RES_SEL1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RES_SEL1_PRTDSI__OE_SEL0        (* (reg8 *) RES_SEL1__PRTDSI__OE_SEL0) 
#define RES_SEL1_PRTDSI__OE_SEL1        (* (reg8 *) RES_SEL1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RES_SEL1_PRTDSI__OUT_SEL0       (* (reg8 *) RES_SEL1__PRTDSI__OUT_SEL0) 
#define RES_SEL1_PRTDSI__OUT_SEL1       (* (reg8 *) RES_SEL1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RES_SEL1_PRTDSI__SYNC_OUT       (* (reg8 *) RES_SEL1__PRTDSI__SYNC_OUT) 


#if defined(RES_SEL1__INTSTAT)  /* Interrupt Registers */

    #define RES_SEL1_INTSTAT                (* (reg8 *) RES_SEL1__INTSTAT)
    #define RES_SEL1_SNAP                   (* (reg8 *) RES_SEL1__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins RES_SEL1_H */


/* [] END OF FILE */
