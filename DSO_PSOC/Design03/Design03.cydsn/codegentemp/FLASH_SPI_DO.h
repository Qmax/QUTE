/*******************************************************************************
* File Name: FLASH_SPI_DO.h  
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

#if !defined(CY_PINS_FLASH_SPI_DO_H) /* Pins FLASH_SPI_DO_H */
#define CY_PINS_FLASH_SPI_DO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FLASH_SPI_DO_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    FLASH_SPI_DO_Write(uint8 value) ;
void    FLASH_SPI_DO_SetDriveMode(uint8 mode) ;
uint8   FLASH_SPI_DO_ReadDataReg(void) ;
uint8   FLASH_SPI_DO_Read(void) ;
uint8   FLASH_SPI_DO_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define FLASH_SPI_DO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define FLASH_SPI_DO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define FLASH_SPI_DO_DM_RES_UP          PIN_DM_RES_UP
#define FLASH_SPI_DO_DM_RES_DWN         PIN_DM_RES_DWN
#define FLASH_SPI_DO_DM_OD_LO           PIN_DM_OD_LO
#define FLASH_SPI_DO_DM_OD_HI           PIN_DM_OD_HI
#define FLASH_SPI_DO_DM_STRONG          PIN_DM_STRONG
#define FLASH_SPI_DO_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define FLASH_SPI_DO_MASK               FLASH_SPI_DO__MASK
#define FLASH_SPI_DO_SHIFT              FLASH_SPI_DO__SHIFT
#define FLASH_SPI_DO_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FLASH_SPI_DO_PS                     (* (reg8 *) FLASH_SPI_DO__PS)
/* Data Register */
#define FLASH_SPI_DO_DR                     (* (reg8 *) FLASH_SPI_DO__DR)
/* Port Number */
#define FLASH_SPI_DO_PRT_NUM                (* (reg8 *) FLASH_SPI_DO__PRT) 
/* Connect to Analog Globals */                                                  
#define FLASH_SPI_DO_AG                     (* (reg8 *) FLASH_SPI_DO__AG)                       
/* Analog MUX bux enable */
#define FLASH_SPI_DO_AMUX                   (* (reg8 *) FLASH_SPI_DO__AMUX) 
/* Bidirectional Enable */                                                        
#define FLASH_SPI_DO_BIE                    (* (reg8 *) FLASH_SPI_DO__BIE)
/* Bit-mask for Aliased Register Access */
#define FLASH_SPI_DO_BIT_MASK               (* (reg8 *) FLASH_SPI_DO__BIT_MASK)
/* Bypass Enable */
#define FLASH_SPI_DO_BYP                    (* (reg8 *) FLASH_SPI_DO__BYP)
/* Port wide control signals */                                                   
#define FLASH_SPI_DO_CTL                    (* (reg8 *) FLASH_SPI_DO__CTL)
/* Drive Modes */
#define FLASH_SPI_DO_DM0                    (* (reg8 *) FLASH_SPI_DO__DM0) 
#define FLASH_SPI_DO_DM1                    (* (reg8 *) FLASH_SPI_DO__DM1)
#define FLASH_SPI_DO_DM2                    (* (reg8 *) FLASH_SPI_DO__DM2) 
/* Input Buffer Disable Override */
#define FLASH_SPI_DO_INP_DIS                (* (reg8 *) FLASH_SPI_DO__INP_DIS)
/* LCD Common or Segment Drive */
#define FLASH_SPI_DO_LCD_COM_SEG            (* (reg8 *) FLASH_SPI_DO__LCD_COM_SEG)
/* Enable Segment LCD */
#define FLASH_SPI_DO_LCD_EN                 (* (reg8 *) FLASH_SPI_DO__LCD_EN)
/* Slew Rate Control */
#define FLASH_SPI_DO_SLW                    (* (reg8 *) FLASH_SPI_DO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FLASH_SPI_DO_PRTDSI__CAPS_SEL       (* (reg8 *) FLASH_SPI_DO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FLASH_SPI_DO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FLASH_SPI_DO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FLASH_SPI_DO_PRTDSI__OE_SEL0        (* (reg8 *) FLASH_SPI_DO__PRTDSI__OE_SEL0) 
#define FLASH_SPI_DO_PRTDSI__OE_SEL1        (* (reg8 *) FLASH_SPI_DO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FLASH_SPI_DO_PRTDSI__OUT_SEL0       (* (reg8 *) FLASH_SPI_DO__PRTDSI__OUT_SEL0) 
#define FLASH_SPI_DO_PRTDSI__OUT_SEL1       (* (reg8 *) FLASH_SPI_DO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FLASH_SPI_DO_PRTDSI__SYNC_OUT       (* (reg8 *) FLASH_SPI_DO__PRTDSI__SYNC_OUT) 


#if defined(FLASH_SPI_DO__INTSTAT)  /* Interrupt Registers */

    #define FLASH_SPI_DO_INTSTAT                (* (reg8 *) FLASH_SPI_DO__INTSTAT)
    #define FLASH_SPI_DO_SNAP                   (* (reg8 *) FLASH_SPI_DO__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins FLASH_SPI_DO_H */


/* [] END OF FILE */
