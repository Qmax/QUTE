/*******************************************************************************
* File Name: FLASH_SPI_CK.h  
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

#if !defined(CY_PINS_FLASH_SPI_CK_H) /* Pins FLASH_SPI_CK_H */
#define CY_PINS_FLASH_SPI_CK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FLASH_SPI_CK_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    FLASH_SPI_CK_Write(uint8 value) ;
void    FLASH_SPI_CK_SetDriveMode(uint8 mode) ;
uint8   FLASH_SPI_CK_ReadDataReg(void) ;
uint8   FLASH_SPI_CK_Read(void) ;
uint8   FLASH_SPI_CK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define FLASH_SPI_CK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define FLASH_SPI_CK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define FLASH_SPI_CK_DM_RES_UP          PIN_DM_RES_UP
#define FLASH_SPI_CK_DM_RES_DWN         PIN_DM_RES_DWN
#define FLASH_SPI_CK_DM_OD_LO           PIN_DM_OD_LO
#define FLASH_SPI_CK_DM_OD_HI           PIN_DM_OD_HI
#define FLASH_SPI_CK_DM_STRONG          PIN_DM_STRONG
#define FLASH_SPI_CK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define FLASH_SPI_CK_MASK               FLASH_SPI_CK__MASK
#define FLASH_SPI_CK_SHIFT              FLASH_SPI_CK__SHIFT
#define FLASH_SPI_CK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FLASH_SPI_CK_PS                     (* (reg8 *) FLASH_SPI_CK__PS)
/* Data Register */
#define FLASH_SPI_CK_DR                     (* (reg8 *) FLASH_SPI_CK__DR)
/* Port Number */
#define FLASH_SPI_CK_PRT_NUM                (* (reg8 *) FLASH_SPI_CK__PRT) 
/* Connect to Analog Globals */                                                  
#define FLASH_SPI_CK_AG                     (* (reg8 *) FLASH_SPI_CK__AG)                       
/* Analog MUX bux enable */
#define FLASH_SPI_CK_AMUX                   (* (reg8 *) FLASH_SPI_CK__AMUX) 
/* Bidirectional Enable */                                                        
#define FLASH_SPI_CK_BIE                    (* (reg8 *) FLASH_SPI_CK__BIE)
/* Bit-mask for Aliased Register Access */
#define FLASH_SPI_CK_BIT_MASK               (* (reg8 *) FLASH_SPI_CK__BIT_MASK)
/* Bypass Enable */
#define FLASH_SPI_CK_BYP                    (* (reg8 *) FLASH_SPI_CK__BYP)
/* Port wide control signals */                                                   
#define FLASH_SPI_CK_CTL                    (* (reg8 *) FLASH_SPI_CK__CTL)
/* Drive Modes */
#define FLASH_SPI_CK_DM0                    (* (reg8 *) FLASH_SPI_CK__DM0) 
#define FLASH_SPI_CK_DM1                    (* (reg8 *) FLASH_SPI_CK__DM1)
#define FLASH_SPI_CK_DM2                    (* (reg8 *) FLASH_SPI_CK__DM2) 
/* Input Buffer Disable Override */
#define FLASH_SPI_CK_INP_DIS                (* (reg8 *) FLASH_SPI_CK__INP_DIS)
/* LCD Common or Segment Drive */
#define FLASH_SPI_CK_LCD_COM_SEG            (* (reg8 *) FLASH_SPI_CK__LCD_COM_SEG)
/* Enable Segment LCD */
#define FLASH_SPI_CK_LCD_EN                 (* (reg8 *) FLASH_SPI_CK__LCD_EN)
/* Slew Rate Control */
#define FLASH_SPI_CK_SLW                    (* (reg8 *) FLASH_SPI_CK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FLASH_SPI_CK_PRTDSI__CAPS_SEL       (* (reg8 *) FLASH_SPI_CK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FLASH_SPI_CK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FLASH_SPI_CK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FLASH_SPI_CK_PRTDSI__OE_SEL0        (* (reg8 *) FLASH_SPI_CK__PRTDSI__OE_SEL0) 
#define FLASH_SPI_CK_PRTDSI__OE_SEL1        (* (reg8 *) FLASH_SPI_CK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FLASH_SPI_CK_PRTDSI__OUT_SEL0       (* (reg8 *) FLASH_SPI_CK__PRTDSI__OUT_SEL0) 
#define FLASH_SPI_CK_PRTDSI__OUT_SEL1       (* (reg8 *) FLASH_SPI_CK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FLASH_SPI_CK_PRTDSI__SYNC_OUT       (* (reg8 *) FLASH_SPI_CK__PRTDSI__SYNC_OUT) 


#if defined(FLASH_SPI_CK__INTSTAT)  /* Interrupt Registers */

    #define FLASH_SPI_CK_INTSTAT                (* (reg8 *) FLASH_SPI_CK__INTSTAT)
    #define FLASH_SPI_CK_SNAP                   (* (reg8 *) FLASH_SPI_CK__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins FLASH_SPI_CK_H */


/* [] END OF FILE */
