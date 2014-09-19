/*******************************************************************************
* File Name: ICM_SEL.h  
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

#if !defined(CY_PINS_ICM_SEL_H) /* Pins ICM_SEL_H */
#define CY_PINS_ICM_SEL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ICM_SEL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ICM_SEL_Write(uint8 value) ;
void    ICM_SEL_SetDriveMode(uint8 mode) ;
uint8   ICM_SEL_ReadDataReg(void) ;
uint8   ICM_SEL_Read(void) ;
uint8   ICM_SEL_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ICM_SEL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ICM_SEL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ICM_SEL_DM_RES_UP          PIN_DM_RES_UP
#define ICM_SEL_DM_RES_DWN         PIN_DM_RES_DWN
#define ICM_SEL_DM_OD_LO           PIN_DM_OD_LO
#define ICM_SEL_DM_OD_HI           PIN_DM_OD_HI
#define ICM_SEL_DM_STRONG          PIN_DM_STRONG
#define ICM_SEL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ICM_SEL_MASK               ICM_SEL__MASK
#define ICM_SEL_SHIFT              ICM_SEL__SHIFT
#define ICM_SEL_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ICM_SEL_PS                     (* (reg8 *) ICM_SEL__PS)
/* Data Register */
#define ICM_SEL_DR                     (* (reg8 *) ICM_SEL__DR)
/* Port Number */
#define ICM_SEL_PRT_NUM                (* (reg8 *) ICM_SEL__PRT) 
/* Connect to Analog Globals */                                                  
#define ICM_SEL_AG                     (* (reg8 *) ICM_SEL__AG)                       
/* Analog MUX bux enable */
#define ICM_SEL_AMUX                   (* (reg8 *) ICM_SEL__AMUX) 
/* Bidirectional Enable */                                                        
#define ICM_SEL_BIE                    (* (reg8 *) ICM_SEL__BIE)
/* Bit-mask for Aliased Register Access */
#define ICM_SEL_BIT_MASK               (* (reg8 *) ICM_SEL__BIT_MASK)
/* Bypass Enable */
#define ICM_SEL_BYP                    (* (reg8 *) ICM_SEL__BYP)
/* Port wide control signals */                                                   
#define ICM_SEL_CTL                    (* (reg8 *) ICM_SEL__CTL)
/* Drive Modes */
#define ICM_SEL_DM0                    (* (reg8 *) ICM_SEL__DM0) 
#define ICM_SEL_DM1                    (* (reg8 *) ICM_SEL__DM1)
#define ICM_SEL_DM2                    (* (reg8 *) ICM_SEL__DM2) 
/* Input Buffer Disable Override */
#define ICM_SEL_INP_DIS                (* (reg8 *) ICM_SEL__INP_DIS)
/* LCD Common or Segment Drive */
#define ICM_SEL_LCD_COM_SEG            (* (reg8 *) ICM_SEL__LCD_COM_SEG)
/* Enable Segment LCD */
#define ICM_SEL_LCD_EN                 (* (reg8 *) ICM_SEL__LCD_EN)
/* Slew Rate Control */
#define ICM_SEL_SLW                    (* (reg8 *) ICM_SEL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ICM_SEL_PRTDSI__CAPS_SEL       (* (reg8 *) ICM_SEL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ICM_SEL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ICM_SEL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ICM_SEL_PRTDSI__OE_SEL0        (* (reg8 *) ICM_SEL__PRTDSI__OE_SEL0) 
#define ICM_SEL_PRTDSI__OE_SEL1        (* (reg8 *) ICM_SEL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ICM_SEL_PRTDSI__OUT_SEL0       (* (reg8 *) ICM_SEL__PRTDSI__OUT_SEL0) 
#define ICM_SEL_PRTDSI__OUT_SEL1       (* (reg8 *) ICM_SEL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ICM_SEL_PRTDSI__SYNC_OUT       (* (reg8 *) ICM_SEL__PRTDSI__SYNC_OUT) 


#if defined(ICM_SEL__INTSTAT)  /* Interrupt Registers */

    #define ICM_SEL_INTSTAT                (* (reg8 *) ICM_SEL__INTSTAT)
    #define ICM_SEL_SNAP                   (* (reg8 *) ICM_SEL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ICM_SEL_H */


/* [] END OF FILE */
