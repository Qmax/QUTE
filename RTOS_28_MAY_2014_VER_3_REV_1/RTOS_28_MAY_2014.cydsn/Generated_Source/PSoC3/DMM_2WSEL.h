/*******************************************************************************
* File Name: DMM_2WSEL.h  
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

#if !defined(CY_PINS_DMM_2WSEL_H) /* Pins DMM_2WSEL_H */
#define CY_PINS_DMM_2WSEL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DMM_2WSEL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    DMM_2WSEL_Write(uint8 value) ;
void    DMM_2WSEL_SetDriveMode(uint8 mode) ;
uint8   DMM_2WSEL_ReadDataReg(void) ;
uint8   DMM_2WSEL_Read(void) ;
uint8   DMM_2WSEL_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DMM_2WSEL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DMM_2WSEL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DMM_2WSEL_DM_RES_UP          PIN_DM_RES_UP
#define DMM_2WSEL_DM_RES_DWN         PIN_DM_RES_DWN
#define DMM_2WSEL_DM_OD_LO           PIN_DM_OD_LO
#define DMM_2WSEL_DM_OD_HI           PIN_DM_OD_HI
#define DMM_2WSEL_DM_STRONG          PIN_DM_STRONG
#define DMM_2WSEL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DMM_2WSEL_MASK               DMM_2WSEL__MASK
#define DMM_2WSEL_SHIFT              DMM_2WSEL__SHIFT
#define DMM_2WSEL_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DMM_2WSEL_PS                     (* (reg8 *) DMM_2WSEL__PS)
/* Data Register */
#define DMM_2WSEL_DR                     (* (reg8 *) DMM_2WSEL__DR)
/* Port Number */
#define DMM_2WSEL_PRT_NUM                (* (reg8 *) DMM_2WSEL__PRT) 
/* Connect to Analog Globals */                                                  
#define DMM_2WSEL_AG                     (* (reg8 *) DMM_2WSEL__AG)                       
/* Analog MUX bux enable */
#define DMM_2WSEL_AMUX                   (* (reg8 *) DMM_2WSEL__AMUX) 
/* Bidirectional Enable */                                                        
#define DMM_2WSEL_BIE                    (* (reg8 *) DMM_2WSEL__BIE)
/* Bit-mask for Aliased Register Access */
#define DMM_2WSEL_BIT_MASK               (* (reg8 *) DMM_2WSEL__BIT_MASK)
/* Bypass Enable */
#define DMM_2WSEL_BYP                    (* (reg8 *) DMM_2WSEL__BYP)
/* Port wide control signals */                                                   
#define DMM_2WSEL_CTL                    (* (reg8 *) DMM_2WSEL__CTL)
/* Drive Modes */
#define DMM_2WSEL_DM0                    (* (reg8 *) DMM_2WSEL__DM0) 
#define DMM_2WSEL_DM1                    (* (reg8 *) DMM_2WSEL__DM1)
#define DMM_2WSEL_DM2                    (* (reg8 *) DMM_2WSEL__DM2) 
/* Input Buffer Disable Override */
#define DMM_2WSEL_INP_DIS                (* (reg8 *) DMM_2WSEL__INP_DIS)
/* LCD Common or Segment Drive */
#define DMM_2WSEL_LCD_COM_SEG            (* (reg8 *) DMM_2WSEL__LCD_COM_SEG)
/* Enable Segment LCD */
#define DMM_2WSEL_LCD_EN                 (* (reg8 *) DMM_2WSEL__LCD_EN)
/* Slew Rate Control */
#define DMM_2WSEL_SLW                    (* (reg8 *) DMM_2WSEL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DMM_2WSEL_PRTDSI__CAPS_SEL       (* (reg8 *) DMM_2WSEL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DMM_2WSEL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DMM_2WSEL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DMM_2WSEL_PRTDSI__OE_SEL0        (* (reg8 *) DMM_2WSEL__PRTDSI__OE_SEL0) 
#define DMM_2WSEL_PRTDSI__OE_SEL1        (* (reg8 *) DMM_2WSEL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DMM_2WSEL_PRTDSI__OUT_SEL0       (* (reg8 *) DMM_2WSEL__PRTDSI__OUT_SEL0) 
#define DMM_2WSEL_PRTDSI__OUT_SEL1       (* (reg8 *) DMM_2WSEL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DMM_2WSEL_PRTDSI__SYNC_OUT       (* (reg8 *) DMM_2WSEL__PRTDSI__SYNC_OUT) 


#if defined(DMM_2WSEL__INTSTAT)  /* Interrupt Registers */

    #define DMM_2WSEL_INTSTAT                (* (reg8 *) DMM_2WSEL__INTSTAT)
    #define DMM_2WSEL_SNAP                   (* (reg8 *) DMM_2WSEL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins DMM_2WSEL_H */


/* [] END OF FILE */
