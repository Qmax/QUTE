/*******************************************************************************
* File Name: DIn.h  
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

#if !defined(CY_PINS_DIn_H) /* Pins DIn_H */
#define CY_PINS_DIn_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIn_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    DIn_Write(uint8 value) ;
void    DIn_SetDriveMode(uint8 mode) ;
uint8   DIn_ReadDataReg(void) ;
uint8   DIn_Read(void) ;
uint8   DIn_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DIn_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DIn_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DIn_DM_RES_UP          PIN_DM_RES_UP
#define DIn_DM_RES_DWN         PIN_DM_RES_DWN
#define DIn_DM_OD_LO           PIN_DM_OD_LO
#define DIn_DM_OD_HI           PIN_DM_OD_HI
#define DIn_DM_STRONG          PIN_DM_STRONG
#define DIn_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DIn_MASK               DIn__MASK
#define DIn_SHIFT              DIn__SHIFT
#define DIn_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIn_PS                     (* (reg8 *) DIn__PS)
/* Data Register */
#define DIn_DR                     (* (reg8 *) DIn__DR)
/* Port Number */
#define DIn_PRT_NUM                (* (reg8 *) DIn__PRT) 
/* Connect to Analog Globals */                                                  
#define DIn_AG                     (* (reg8 *) DIn__AG)                       
/* Analog MUX bux enable */
#define DIn_AMUX                   (* (reg8 *) DIn__AMUX) 
/* Bidirectional Enable */                                                        
#define DIn_BIE                    (* (reg8 *) DIn__BIE)
/* Bit-mask for Aliased Register Access */
#define DIn_BIT_MASK               (* (reg8 *) DIn__BIT_MASK)
/* Bypass Enable */
#define DIn_BYP                    (* (reg8 *) DIn__BYP)
/* Port wide control signals */                                                   
#define DIn_CTL                    (* (reg8 *) DIn__CTL)
/* Drive Modes */
#define DIn_DM0                    (* (reg8 *) DIn__DM0) 
#define DIn_DM1                    (* (reg8 *) DIn__DM1)
#define DIn_DM2                    (* (reg8 *) DIn__DM2) 
/* Input Buffer Disable Override */
#define DIn_INP_DIS                (* (reg8 *) DIn__INP_DIS)
/* LCD Common or Segment Drive */
#define DIn_LCD_COM_SEG            (* (reg8 *) DIn__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIn_LCD_EN                 (* (reg8 *) DIn__LCD_EN)
/* Slew Rate Control */
#define DIn_SLW                    (* (reg8 *) DIn__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIn_PRTDSI__CAPS_SEL       (* (reg8 *) DIn__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIn_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIn__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIn_PRTDSI__OE_SEL0        (* (reg8 *) DIn__PRTDSI__OE_SEL0) 
#define DIn_PRTDSI__OE_SEL1        (* (reg8 *) DIn__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIn_PRTDSI__OUT_SEL0       (* (reg8 *) DIn__PRTDSI__OUT_SEL0) 
#define DIn_PRTDSI__OUT_SEL1       (* (reg8 *) DIn__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIn_PRTDSI__SYNC_OUT       (* (reg8 *) DIn__PRTDSI__SYNC_OUT) 


#if defined(DIn__INTSTAT)  /* Interrupt Registers */

    #define DIn_INTSTAT                (* (reg8 *) DIn__INTSTAT)
    #define DIn_SNAP                   (* (reg8 *) DIn__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins DIn_H */


/* [] END OF FILE */
