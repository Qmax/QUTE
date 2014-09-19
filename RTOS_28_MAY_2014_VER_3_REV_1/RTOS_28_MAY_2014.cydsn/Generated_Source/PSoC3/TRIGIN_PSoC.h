/*******************************************************************************
* File Name: TRIGIN_PSoC.h  
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

#if !defined(CY_PINS_TRIGIN_PSoC_H) /* Pins TRIGIN_PSoC_H */
#define CY_PINS_TRIGIN_PSoC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TRIGIN_PSoC_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TRIGIN_PSoC_Write(uint8 value) ;
void    TRIGIN_PSoC_SetDriveMode(uint8 mode) ;
uint8   TRIGIN_PSoC_ReadDataReg(void) ;
uint8   TRIGIN_PSoC_Read(void) ;
uint8   TRIGIN_PSoC_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TRIGIN_PSoC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define TRIGIN_PSoC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define TRIGIN_PSoC_DM_RES_UP          PIN_DM_RES_UP
#define TRIGIN_PSoC_DM_RES_DWN         PIN_DM_RES_DWN
#define TRIGIN_PSoC_DM_OD_LO           PIN_DM_OD_LO
#define TRIGIN_PSoC_DM_OD_HI           PIN_DM_OD_HI
#define TRIGIN_PSoC_DM_STRONG          PIN_DM_STRONG
#define TRIGIN_PSoC_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define TRIGIN_PSoC_MASK               TRIGIN_PSoC__MASK
#define TRIGIN_PSoC_SHIFT              TRIGIN_PSoC__SHIFT
#define TRIGIN_PSoC_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TRIGIN_PSoC_PS                     (* (reg8 *) TRIGIN_PSoC__PS)
/* Data Register */
#define TRIGIN_PSoC_DR                     (* (reg8 *) TRIGIN_PSoC__DR)
/* Port Number */
#define TRIGIN_PSoC_PRT_NUM                (* (reg8 *) TRIGIN_PSoC__PRT) 
/* Connect to Analog Globals */                                                  
#define TRIGIN_PSoC_AG                     (* (reg8 *) TRIGIN_PSoC__AG)                       
/* Analog MUX bux enable */
#define TRIGIN_PSoC_AMUX                   (* (reg8 *) TRIGIN_PSoC__AMUX) 
/* Bidirectional Enable */                                                        
#define TRIGIN_PSoC_BIE                    (* (reg8 *) TRIGIN_PSoC__BIE)
/* Bit-mask for Aliased Register Access */
#define TRIGIN_PSoC_BIT_MASK               (* (reg8 *) TRIGIN_PSoC__BIT_MASK)
/* Bypass Enable */
#define TRIGIN_PSoC_BYP                    (* (reg8 *) TRIGIN_PSoC__BYP)
/* Port wide control signals */                                                   
#define TRIGIN_PSoC_CTL                    (* (reg8 *) TRIGIN_PSoC__CTL)
/* Drive Modes */
#define TRIGIN_PSoC_DM0                    (* (reg8 *) TRIGIN_PSoC__DM0) 
#define TRIGIN_PSoC_DM1                    (* (reg8 *) TRIGIN_PSoC__DM1)
#define TRIGIN_PSoC_DM2                    (* (reg8 *) TRIGIN_PSoC__DM2) 
/* Input Buffer Disable Override */
#define TRIGIN_PSoC_INP_DIS                (* (reg8 *) TRIGIN_PSoC__INP_DIS)
/* LCD Common or Segment Drive */
#define TRIGIN_PSoC_LCD_COM_SEG            (* (reg8 *) TRIGIN_PSoC__LCD_COM_SEG)
/* Enable Segment LCD */
#define TRIGIN_PSoC_LCD_EN                 (* (reg8 *) TRIGIN_PSoC__LCD_EN)
/* Slew Rate Control */
#define TRIGIN_PSoC_SLW                    (* (reg8 *) TRIGIN_PSoC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TRIGIN_PSoC_PRTDSI__CAPS_SEL       (* (reg8 *) TRIGIN_PSoC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TRIGIN_PSoC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TRIGIN_PSoC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TRIGIN_PSoC_PRTDSI__OE_SEL0        (* (reg8 *) TRIGIN_PSoC__PRTDSI__OE_SEL0) 
#define TRIGIN_PSoC_PRTDSI__OE_SEL1        (* (reg8 *) TRIGIN_PSoC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TRIGIN_PSoC_PRTDSI__OUT_SEL0       (* (reg8 *) TRIGIN_PSoC__PRTDSI__OUT_SEL0) 
#define TRIGIN_PSoC_PRTDSI__OUT_SEL1       (* (reg8 *) TRIGIN_PSoC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TRIGIN_PSoC_PRTDSI__SYNC_OUT       (* (reg8 *) TRIGIN_PSoC__PRTDSI__SYNC_OUT) 


#if defined(TRIGIN_PSoC__INTSTAT)  /* Interrupt Registers */

    #define TRIGIN_PSoC_INTSTAT                (* (reg8 *) TRIGIN_PSoC__INTSTAT)
    #define TRIGIN_PSoC_SNAP                   (* (reg8 *) TRIGIN_PSoC__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins TRIGIN_PSoC_H */


/* [] END OF FILE */
