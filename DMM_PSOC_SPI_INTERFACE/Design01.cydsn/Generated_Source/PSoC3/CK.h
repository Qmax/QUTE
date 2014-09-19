/*******************************************************************************
* File Name: CK.h  
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

#if !defined(CY_PINS_CK_H) /* Pins CK_H */
#define CY_PINS_CK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CK_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    CK_Write(uint8 value) ;
void    CK_SetDriveMode(uint8 mode) ;
uint8   CK_ReadDataReg(void) ;
uint8   CK_Read(void) ;
uint8   CK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CK_DM_RES_UP          PIN_DM_RES_UP
#define CK_DM_RES_DWN         PIN_DM_RES_DWN
#define CK_DM_OD_LO           PIN_DM_OD_LO
#define CK_DM_OD_HI           PIN_DM_OD_HI
#define CK_DM_STRONG          PIN_DM_STRONG
#define CK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CK_MASK               CK__MASK
#define CK_SHIFT              CK__SHIFT
#define CK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CK_PS                     (* (reg8 *) CK__PS)
/* Data Register */
#define CK_DR                     (* (reg8 *) CK__DR)
/* Port Number */
#define CK_PRT_NUM                (* (reg8 *) CK__PRT) 
/* Connect to Analog Globals */                                                  
#define CK_AG                     (* (reg8 *) CK__AG)                       
/* Analog MUX bux enable */
#define CK_AMUX                   (* (reg8 *) CK__AMUX) 
/* Bidirectional Enable */                                                        
#define CK_BIE                    (* (reg8 *) CK__BIE)
/* Bit-mask for Aliased Register Access */
#define CK_BIT_MASK               (* (reg8 *) CK__BIT_MASK)
/* Bypass Enable */
#define CK_BYP                    (* (reg8 *) CK__BYP)
/* Port wide control signals */                                                   
#define CK_CTL                    (* (reg8 *) CK__CTL)
/* Drive Modes */
#define CK_DM0                    (* (reg8 *) CK__DM0) 
#define CK_DM1                    (* (reg8 *) CK__DM1)
#define CK_DM2                    (* (reg8 *) CK__DM2) 
/* Input Buffer Disable Override */
#define CK_INP_DIS                (* (reg8 *) CK__INP_DIS)
/* LCD Common or Segment Drive */
#define CK_LCD_COM_SEG            (* (reg8 *) CK__LCD_COM_SEG)
/* Enable Segment LCD */
#define CK_LCD_EN                 (* (reg8 *) CK__LCD_EN)
/* Slew Rate Control */
#define CK_SLW                    (* (reg8 *) CK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CK_PRTDSI__CAPS_SEL       (* (reg8 *) CK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CK_PRTDSI__OE_SEL0        (* (reg8 *) CK__PRTDSI__OE_SEL0) 
#define CK_PRTDSI__OE_SEL1        (* (reg8 *) CK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CK_PRTDSI__OUT_SEL0       (* (reg8 *) CK__PRTDSI__OUT_SEL0) 
#define CK_PRTDSI__OUT_SEL1       (* (reg8 *) CK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CK_PRTDSI__SYNC_OUT       (* (reg8 *) CK__PRTDSI__SYNC_OUT) 


#if defined(CK__INTSTAT)  /* Interrupt Registers */

    #define CK_INTSTAT                (* (reg8 *) CK__INTSTAT)
    #define CK_SNAP                   (* (reg8 *) CK__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins CK_H */


/* [] END OF FILE */
