/*******************************************************************************
* File Name: PSoC_INT1.h  
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

#if !defined(CY_PINS_PSoC_INT1_H) /* Pins PSoC_INT1_H */
#define CY_PINS_PSoC_INT1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PSoC_INT1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PSoC_INT1_Write(uint8 value) ;
void    PSoC_INT1_SetDriveMode(uint8 mode) ;
uint8   PSoC_INT1_ReadDataReg(void) ;
uint8   PSoC_INT1_Read(void) ;
uint8   PSoC_INT1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PSoC_INT1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PSoC_INT1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PSoC_INT1_DM_RES_UP          PIN_DM_RES_UP
#define PSoC_INT1_DM_RES_DWN         PIN_DM_RES_DWN
#define PSoC_INT1_DM_OD_LO           PIN_DM_OD_LO
#define PSoC_INT1_DM_OD_HI           PIN_DM_OD_HI
#define PSoC_INT1_DM_STRONG          PIN_DM_STRONG
#define PSoC_INT1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PSoC_INT1_MASK               PSoC_INT1__MASK
#define PSoC_INT1_SHIFT              PSoC_INT1__SHIFT
#define PSoC_INT1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PSoC_INT1_PS                     (* (reg8 *) PSoC_INT1__PS)
/* Data Register */
#define PSoC_INT1_DR                     (* (reg8 *) PSoC_INT1__DR)
/* Port Number */
#define PSoC_INT1_PRT_NUM                (* (reg8 *) PSoC_INT1__PRT) 
/* Connect to Analog Globals */                                                  
#define PSoC_INT1_AG                     (* (reg8 *) PSoC_INT1__AG)                       
/* Analog MUX bux enable */
#define PSoC_INT1_AMUX                   (* (reg8 *) PSoC_INT1__AMUX) 
/* Bidirectional Enable */                                                        
#define PSoC_INT1_BIE                    (* (reg8 *) PSoC_INT1__BIE)
/* Bit-mask for Aliased Register Access */
#define PSoC_INT1_BIT_MASK               (* (reg8 *) PSoC_INT1__BIT_MASK)
/* Bypass Enable */
#define PSoC_INT1_BYP                    (* (reg8 *) PSoC_INT1__BYP)
/* Port wide control signals */                                                   
#define PSoC_INT1_CTL                    (* (reg8 *) PSoC_INT1__CTL)
/* Drive Modes */
#define PSoC_INT1_DM0                    (* (reg8 *) PSoC_INT1__DM0) 
#define PSoC_INT1_DM1                    (* (reg8 *) PSoC_INT1__DM1)
#define PSoC_INT1_DM2                    (* (reg8 *) PSoC_INT1__DM2) 
/* Input Buffer Disable Override */
#define PSoC_INT1_INP_DIS                (* (reg8 *) PSoC_INT1__INP_DIS)
/* LCD Common or Segment Drive */
#define PSoC_INT1_LCD_COM_SEG            (* (reg8 *) PSoC_INT1__LCD_COM_SEG)
/* Enable Segment LCD */
#define PSoC_INT1_LCD_EN                 (* (reg8 *) PSoC_INT1__LCD_EN)
/* Slew Rate Control */
#define PSoC_INT1_SLW                    (* (reg8 *) PSoC_INT1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PSoC_INT1_PRTDSI__CAPS_SEL       (* (reg8 *) PSoC_INT1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PSoC_INT1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PSoC_INT1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PSoC_INT1_PRTDSI__OE_SEL0        (* (reg8 *) PSoC_INT1__PRTDSI__OE_SEL0) 
#define PSoC_INT1_PRTDSI__OE_SEL1        (* (reg8 *) PSoC_INT1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PSoC_INT1_PRTDSI__OUT_SEL0       (* (reg8 *) PSoC_INT1__PRTDSI__OUT_SEL0) 
#define PSoC_INT1_PRTDSI__OUT_SEL1       (* (reg8 *) PSoC_INT1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PSoC_INT1_PRTDSI__SYNC_OUT       (* (reg8 *) PSoC_INT1__PRTDSI__SYNC_OUT) 


#if defined(PSoC_INT1__INTSTAT)  /* Interrupt Registers */

    #define PSoC_INT1_INTSTAT                (* (reg8 *) PSoC_INT1__INTSTAT)
    #define PSoC_INT1_SNAP                   (* (reg8 *) PSoC_INT1__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins PSoC_INT1_H */


/* [] END OF FILE */
