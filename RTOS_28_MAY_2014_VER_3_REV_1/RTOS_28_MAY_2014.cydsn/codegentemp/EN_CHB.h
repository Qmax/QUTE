/*******************************************************************************
* File Name: EN_CHB.h  
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

#if !defined(CY_PINS_EN_CHB_H) /* Pins EN_CHB_H */
#define CY_PINS_EN_CHB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EN_CHB_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    EN_CHB_Write(uint8 value) ;
void    EN_CHB_SetDriveMode(uint8 mode) ;
uint8   EN_CHB_ReadDataReg(void) ;
uint8   EN_CHB_Read(void) ;
uint8   EN_CHB_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EN_CHB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EN_CHB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EN_CHB_DM_RES_UP          PIN_DM_RES_UP
#define EN_CHB_DM_RES_DWN         PIN_DM_RES_DWN
#define EN_CHB_DM_OD_LO           PIN_DM_OD_LO
#define EN_CHB_DM_OD_HI           PIN_DM_OD_HI
#define EN_CHB_DM_STRONG          PIN_DM_STRONG
#define EN_CHB_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EN_CHB_MASK               EN_CHB__MASK
#define EN_CHB_SHIFT              EN_CHB__SHIFT
#define EN_CHB_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EN_CHB_PS                     (* (reg8 *) EN_CHB__PS)
/* Data Register */
#define EN_CHB_DR                     (* (reg8 *) EN_CHB__DR)
/* Port Number */
#define EN_CHB_PRT_NUM                (* (reg8 *) EN_CHB__PRT) 
/* Connect to Analog Globals */                                                  
#define EN_CHB_AG                     (* (reg8 *) EN_CHB__AG)                       
/* Analog MUX bux enable */
#define EN_CHB_AMUX                   (* (reg8 *) EN_CHB__AMUX) 
/* Bidirectional Enable */                                                        
#define EN_CHB_BIE                    (* (reg8 *) EN_CHB__BIE)
/* Bit-mask for Aliased Register Access */
#define EN_CHB_BIT_MASK               (* (reg8 *) EN_CHB__BIT_MASK)
/* Bypass Enable */
#define EN_CHB_BYP                    (* (reg8 *) EN_CHB__BYP)
/* Port wide control signals */                                                   
#define EN_CHB_CTL                    (* (reg8 *) EN_CHB__CTL)
/* Drive Modes */
#define EN_CHB_DM0                    (* (reg8 *) EN_CHB__DM0) 
#define EN_CHB_DM1                    (* (reg8 *) EN_CHB__DM1)
#define EN_CHB_DM2                    (* (reg8 *) EN_CHB__DM2) 
/* Input Buffer Disable Override */
#define EN_CHB_INP_DIS                (* (reg8 *) EN_CHB__INP_DIS)
/* LCD Common or Segment Drive */
#define EN_CHB_LCD_COM_SEG            (* (reg8 *) EN_CHB__LCD_COM_SEG)
/* Enable Segment LCD */
#define EN_CHB_LCD_EN                 (* (reg8 *) EN_CHB__LCD_EN)
/* Slew Rate Control */
#define EN_CHB_SLW                    (* (reg8 *) EN_CHB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EN_CHB_PRTDSI__CAPS_SEL       (* (reg8 *) EN_CHB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EN_CHB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EN_CHB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EN_CHB_PRTDSI__OE_SEL0        (* (reg8 *) EN_CHB__PRTDSI__OE_SEL0) 
#define EN_CHB_PRTDSI__OE_SEL1        (* (reg8 *) EN_CHB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EN_CHB_PRTDSI__OUT_SEL0       (* (reg8 *) EN_CHB__PRTDSI__OUT_SEL0) 
#define EN_CHB_PRTDSI__OUT_SEL1       (* (reg8 *) EN_CHB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EN_CHB_PRTDSI__SYNC_OUT       (* (reg8 *) EN_CHB__PRTDSI__SYNC_OUT) 


#if defined(EN_CHB__INTSTAT)  /* Interrupt Registers */

    #define EN_CHB_INTSTAT                (* (reg8 *) EN_CHB__INTSTAT)
    #define EN_CHB_SNAP                   (* (reg8 *) EN_CHB__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins EN_CHB_H */


/* [] END OF FILE */
