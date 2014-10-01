/*******************************************************************************
* File Name: PSOC_SPI_CLK.h  
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

#if !defined(CY_PINS_PSOC_SPI_CLK_H) /* Pins PSOC_SPI_CLK_H */
#define CY_PINS_PSOC_SPI_CLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PSOC_SPI_CLK_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PSOC_SPI_CLK_Write(uint8 value) ;
void    PSOC_SPI_CLK_SetDriveMode(uint8 mode) ;
uint8   PSOC_SPI_CLK_ReadDataReg(void) ;
uint8   PSOC_SPI_CLK_Read(void) ;
uint8   PSOC_SPI_CLK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PSOC_SPI_CLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PSOC_SPI_CLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PSOC_SPI_CLK_DM_RES_UP          PIN_DM_RES_UP
#define PSOC_SPI_CLK_DM_RES_DWN         PIN_DM_RES_DWN
#define PSOC_SPI_CLK_DM_OD_LO           PIN_DM_OD_LO
#define PSOC_SPI_CLK_DM_OD_HI           PIN_DM_OD_HI
#define PSOC_SPI_CLK_DM_STRONG          PIN_DM_STRONG
#define PSOC_SPI_CLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PSOC_SPI_CLK_MASK               PSOC_SPI_CLK__MASK
#define PSOC_SPI_CLK_SHIFT              PSOC_SPI_CLK__SHIFT
#define PSOC_SPI_CLK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PSOC_SPI_CLK_PS                     (* (reg8 *) PSOC_SPI_CLK__PS)
/* Data Register */
#define PSOC_SPI_CLK_DR                     (* (reg8 *) PSOC_SPI_CLK__DR)
/* Port Number */
#define PSOC_SPI_CLK_PRT_NUM                (* (reg8 *) PSOC_SPI_CLK__PRT) 
/* Connect to Analog Globals */                                                  
#define PSOC_SPI_CLK_AG                     (* (reg8 *) PSOC_SPI_CLK__AG)                       
/* Analog MUX bux enable */
#define PSOC_SPI_CLK_AMUX                   (* (reg8 *) PSOC_SPI_CLK__AMUX) 
/* Bidirectional Enable */                                                        
#define PSOC_SPI_CLK_BIE                    (* (reg8 *) PSOC_SPI_CLK__BIE)
/* Bit-mask for Aliased Register Access */
#define PSOC_SPI_CLK_BIT_MASK               (* (reg8 *) PSOC_SPI_CLK__BIT_MASK)
/* Bypass Enable */
#define PSOC_SPI_CLK_BYP                    (* (reg8 *) PSOC_SPI_CLK__BYP)
/* Port wide control signals */                                                   
#define PSOC_SPI_CLK_CTL                    (* (reg8 *) PSOC_SPI_CLK__CTL)
/* Drive Modes */
#define PSOC_SPI_CLK_DM0                    (* (reg8 *) PSOC_SPI_CLK__DM0) 
#define PSOC_SPI_CLK_DM1                    (* (reg8 *) PSOC_SPI_CLK__DM1)
#define PSOC_SPI_CLK_DM2                    (* (reg8 *) PSOC_SPI_CLK__DM2) 
/* Input Buffer Disable Override */
#define PSOC_SPI_CLK_INP_DIS                (* (reg8 *) PSOC_SPI_CLK__INP_DIS)
/* LCD Common or Segment Drive */
#define PSOC_SPI_CLK_LCD_COM_SEG            (* (reg8 *) PSOC_SPI_CLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define PSOC_SPI_CLK_LCD_EN                 (* (reg8 *) PSOC_SPI_CLK__LCD_EN)
/* Slew Rate Control */
#define PSOC_SPI_CLK_SLW                    (* (reg8 *) PSOC_SPI_CLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PSOC_SPI_CLK_PRTDSI__CAPS_SEL       (* (reg8 *) PSOC_SPI_CLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PSOC_SPI_CLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PSOC_SPI_CLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PSOC_SPI_CLK_PRTDSI__OE_SEL0        (* (reg8 *) PSOC_SPI_CLK__PRTDSI__OE_SEL0) 
#define PSOC_SPI_CLK_PRTDSI__OE_SEL1        (* (reg8 *) PSOC_SPI_CLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PSOC_SPI_CLK_PRTDSI__OUT_SEL0       (* (reg8 *) PSOC_SPI_CLK__PRTDSI__OUT_SEL0) 
#define PSOC_SPI_CLK_PRTDSI__OUT_SEL1       (* (reg8 *) PSOC_SPI_CLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PSOC_SPI_CLK_PRTDSI__SYNC_OUT       (* (reg8 *) PSOC_SPI_CLK__PRTDSI__SYNC_OUT) 


#if defined(PSOC_SPI_CLK__INTSTAT)  /* Interrupt Registers */

    #define PSOC_SPI_CLK_INTSTAT                (* (reg8 *) PSOC_SPI_CLK__INTSTAT)
    #define PSOC_SPI_CLK_SNAP                   (* (reg8 *) PSOC_SPI_CLK__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins PSOC_SPI_CLK_H */


/* [] END OF FILE */
