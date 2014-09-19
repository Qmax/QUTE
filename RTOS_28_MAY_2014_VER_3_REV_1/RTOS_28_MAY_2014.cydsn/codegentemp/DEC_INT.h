/*******************************************************************************
* File Name: DEC_INT.h  
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

#if !defined(CY_PINS_DEC_INT_H) /* Pins DEC_INT_H */
#define CY_PINS_DEC_INT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DEC_INT_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    DEC_INT_Write(uint8 value) ;
void    DEC_INT_SetDriveMode(uint8 mode) ;
uint8   DEC_INT_ReadDataReg(void) ;
uint8   DEC_INT_Read(void) ;
uint8   DEC_INT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DEC_INT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DEC_INT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DEC_INT_DM_RES_UP          PIN_DM_RES_UP
#define DEC_INT_DM_RES_DWN         PIN_DM_RES_DWN
#define DEC_INT_DM_OD_LO           PIN_DM_OD_LO
#define DEC_INT_DM_OD_HI           PIN_DM_OD_HI
#define DEC_INT_DM_STRONG          PIN_DM_STRONG
#define DEC_INT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DEC_INT_MASK               DEC_INT__MASK
#define DEC_INT_SHIFT              DEC_INT__SHIFT
#define DEC_INT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DEC_INT_PS                     (* (reg8 *) DEC_INT__PS)
/* Data Register */
#define DEC_INT_DR                     (* (reg8 *) DEC_INT__DR)
/* Port Number */
#define DEC_INT_PRT_NUM                (* (reg8 *) DEC_INT__PRT) 
/* Connect to Analog Globals */                                                  
#define DEC_INT_AG                     (* (reg8 *) DEC_INT__AG)                       
/* Analog MUX bux enable */
#define DEC_INT_AMUX                   (* (reg8 *) DEC_INT__AMUX) 
/* Bidirectional Enable */                                                        
#define DEC_INT_BIE                    (* (reg8 *) DEC_INT__BIE)
/* Bit-mask for Aliased Register Access */
#define DEC_INT_BIT_MASK               (* (reg8 *) DEC_INT__BIT_MASK)
/* Bypass Enable */
#define DEC_INT_BYP                    (* (reg8 *) DEC_INT__BYP)
/* Port wide control signals */                                                   
#define DEC_INT_CTL                    (* (reg8 *) DEC_INT__CTL)
/* Drive Modes */
#define DEC_INT_DM0                    (* (reg8 *) DEC_INT__DM0) 
#define DEC_INT_DM1                    (* (reg8 *) DEC_INT__DM1)
#define DEC_INT_DM2                    (* (reg8 *) DEC_INT__DM2) 
/* Input Buffer Disable Override */
#define DEC_INT_INP_DIS                (* (reg8 *) DEC_INT__INP_DIS)
/* LCD Common or Segment Drive */
#define DEC_INT_LCD_COM_SEG            (* (reg8 *) DEC_INT__LCD_COM_SEG)
/* Enable Segment LCD */
#define DEC_INT_LCD_EN                 (* (reg8 *) DEC_INT__LCD_EN)
/* Slew Rate Control */
#define DEC_INT_SLW                    (* (reg8 *) DEC_INT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DEC_INT_PRTDSI__CAPS_SEL       (* (reg8 *) DEC_INT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DEC_INT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DEC_INT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DEC_INT_PRTDSI__OE_SEL0        (* (reg8 *) DEC_INT__PRTDSI__OE_SEL0) 
#define DEC_INT_PRTDSI__OE_SEL1        (* (reg8 *) DEC_INT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DEC_INT_PRTDSI__OUT_SEL0       (* (reg8 *) DEC_INT__PRTDSI__OUT_SEL0) 
#define DEC_INT_PRTDSI__OUT_SEL1       (* (reg8 *) DEC_INT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DEC_INT_PRTDSI__SYNC_OUT       (* (reg8 *) DEC_INT__PRTDSI__SYNC_OUT) 


#if defined(DEC_INT__INTSTAT)  /* Interrupt Registers */

    #define DEC_INT_INTSTAT                (* (reg8 *) DEC_INT__INTSTAT)
    #define DEC_INT_SNAP                   (* (reg8 *) DEC_INT__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins DEC_INT_H */


/* [] END OF FILE */
