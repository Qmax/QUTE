/*******************************************************************************
* File Name: FLASH_SPI_CS.h  
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

#if !defined(CY_PINS_FLASH_SPI_CS_H) /* Pins FLASH_SPI_CS_H */
#define CY_PINS_FLASH_SPI_CS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FLASH_SPI_CS_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    FLASH_SPI_CS_Write(uint8 value) ;
void    FLASH_SPI_CS_SetDriveMode(uint8 mode) ;
uint8   FLASH_SPI_CS_ReadDataReg(void) ;
uint8   FLASH_SPI_CS_Read(void) ;
uint8   FLASH_SPI_CS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define FLASH_SPI_CS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define FLASH_SPI_CS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define FLASH_SPI_CS_DM_RES_UP          PIN_DM_RES_UP
#define FLASH_SPI_CS_DM_RES_DWN         PIN_DM_RES_DWN
#define FLASH_SPI_CS_DM_OD_LO           PIN_DM_OD_LO
#define FLASH_SPI_CS_DM_OD_HI           PIN_DM_OD_HI
#define FLASH_SPI_CS_DM_STRONG          PIN_DM_STRONG
#define FLASH_SPI_CS_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define FLASH_SPI_CS_MASK               FLASH_SPI_CS__MASK
#define FLASH_SPI_CS_SHIFT              FLASH_SPI_CS__SHIFT
#define FLASH_SPI_CS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FLASH_SPI_CS_PS                     (* (reg8 *) FLASH_SPI_CS__PS)
/* Data Register */
#define FLASH_SPI_CS_DR                     (* (reg8 *) FLASH_SPI_CS__DR)
/* Port Number */
#define FLASH_SPI_CS_PRT_NUM                (* (reg8 *) FLASH_SPI_CS__PRT) 
/* Connect to Analog Globals */                                                  
#define FLASH_SPI_CS_AG                     (* (reg8 *) FLASH_SPI_CS__AG)                       
/* Analog MUX bux enable */
#define FLASH_SPI_CS_AMUX                   (* (reg8 *) FLASH_SPI_CS__AMUX) 
/* Bidirectional Enable */                                                        
#define FLASH_SPI_CS_BIE                    (* (reg8 *) FLASH_SPI_CS__BIE)
/* Bit-mask for Aliased Register Access */
#define FLASH_SPI_CS_BIT_MASK               (* (reg8 *) FLASH_SPI_CS__BIT_MASK)
/* Bypass Enable */
#define FLASH_SPI_CS_BYP                    (* (reg8 *) FLASH_SPI_CS__BYP)
/* Port wide control signals */                                                   
#define FLASH_SPI_CS_CTL                    (* (reg8 *) FLASH_SPI_CS__CTL)
/* Drive Modes */
#define FLASH_SPI_CS_DM0                    (* (reg8 *) FLASH_SPI_CS__DM0) 
#define FLASH_SPI_CS_DM1                    (* (reg8 *) FLASH_SPI_CS__DM1)
#define FLASH_SPI_CS_DM2                    (* (reg8 *) FLASH_SPI_CS__DM2) 
/* Input Buffer Disable Override */
#define FLASH_SPI_CS_INP_DIS                (* (reg8 *) FLASH_SPI_CS__INP_DIS)
/* LCD Common or Segment Drive */
#define FLASH_SPI_CS_LCD_COM_SEG            (* (reg8 *) FLASH_SPI_CS__LCD_COM_SEG)
/* Enable Segment LCD */
#define FLASH_SPI_CS_LCD_EN                 (* (reg8 *) FLASH_SPI_CS__LCD_EN)
/* Slew Rate Control */
#define FLASH_SPI_CS_SLW                    (* (reg8 *) FLASH_SPI_CS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FLASH_SPI_CS_PRTDSI__CAPS_SEL       (* (reg8 *) FLASH_SPI_CS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FLASH_SPI_CS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FLASH_SPI_CS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FLASH_SPI_CS_PRTDSI__OE_SEL0        (* (reg8 *) FLASH_SPI_CS__PRTDSI__OE_SEL0) 
#define FLASH_SPI_CS_PRTDSI__OE_SEL1        (* (reg8 *) FLASH_SPI_CS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FLASH_SPI_CS_PRTDSI__OUT_SEL0       (* (reg8 *) FLASH_SPI_CS__PRTDSI__OUT_SEL0) 
#define FLASH_SPI_CS_PRTDSI__OUT_SEL1       (* (reg8 *) FLASH_SPI_CS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FLASH_SPI_CS_PRTDSI__SYNC_OUT       (* (reg8 *) FLASH_SPI_CS__PRTDSI__SYNC_OUT) 


#if defined(FLASH_SPI_CS__INTSTAT)  /* Interrupt Registers */

    #define FLASH_SPI_CS_INTSTAT                (* (reg8 *) FLASH_SPI_CS__INTSTAT)
    #define FLASH_SPI_CS_SNAP                   (* (reg8 *) FLASH_SPI_CS__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins FLASH_SPI_CS_H */


/* [] END OF FILE */
