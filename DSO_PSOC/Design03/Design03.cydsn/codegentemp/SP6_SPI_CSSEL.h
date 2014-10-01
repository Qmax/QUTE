/*******************************************************************************
* File Name: SP6_SPI_CSSEL.h  
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

#if !defined(CY_PINS_SP6_SPI_CSSEL_H) /* Pins SP6_SPI_CSSEL_H */
#define CY_PINS_SP6_SPI_CSSEL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SP6_SPI_CSSEL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SP6_SPI_CSSEL_Write(uint8 value) ;
void    SP6_SPI_CSSEL_SetDriveMode(uint8 mode) ;
uint8   SP6_SPI_CSSEL_ReadDataReg(void) ;
uint8   SP6_SPI_CSSEL_Read(void) ;
uint8   SP6_SPI_CSSEL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SP6_SPI_CSSEL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SP6_SPI_CSSEL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SP6_SPI_CSSEL_DM_RES_UP          PIN_DM_RES_UP
#define SP6_SPI_CSSEL_DM_RES_DWN         PIN_DM_RES_DWN
#define SP6_SPI_CSSEL_DM_OD_LO           PIN_DM_OD_LO
#define SP6_SPI_CSSEL_DM_OD_HI           PIN_DM_OD_HI
#define SP6_SPI_CSSEL_DM_STRONG          PIN_DM_STRONG
#define SP6_SPI_CSSEL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SP6_SPI_CSSEL_MASK               SP6_SPI_CSSEL__MASK
#define SP6_SPI_CSSEL_SHIFT              SP6_SPI_CSSEL__SHIFT
#define SP6_SPI_CSSEL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SP6_SPI_CSSEL_PS                     (* (reg8 *) SP6_SPI_CSSEL__PS)
/* Data Register */
#define SP6_SPI_CSSEL_DR                     (* (reg8 *) SP6_SPI_CSSEL__DR)
/* Port Number */
#define SP6_SPI_CSSEL_PRT_NUM                (* (reg8 *) SP6_SPI_CSSEL__PRT) 
/* Connect to Analog Globals */                                                  
#define SP6_SPI_CSSEL_AG                     (* (reg8 *) SP6_SPI_CSSEL__AG)                       
/* Analog MUX bux enable */
#define SP6_SPI_CSSEL_AMUX                   (* (reg8 *) SP6_SPI_CSSEL__AMUX) 
/* Bidirectional Enable */                                                        
#define SP6_SPI_CSSEL_BIE                    (* (reg8 *) SP6_SPI_CSSEL__BIE)
/* Bit-mask for Aliased Register Access */
#define SP6_SPI_CSSEL_BIT_MASK               (* (reg8 *) SP6_SPI_CSSEL__BIT_MASK)
/* Bypass Enable */
#define SP6_SPI_CSSEL_BYP                    (* (reg8 *) SP6_SPI_CSSEL__BYP)
/* Port wide control signals */                                                   
#define SP6_SPI_CSSEL_CTL                    (* (reg8 *) SP6_SPI_CSSEL__CTL)
/* Drive Modes */
#define SP6_SPI_CSSEL_DM0                    (* (reg8 *) SP6_SPI_CSSEL__DM0) 
#define SP6_SPI_CSSEL_DM1                    (* (reg8 *) SP6_SPI_CSSEL__DM1)
#define SP6_SPI_CSSEL_DM2                    (* (reg8 *) SP6_SPI_CSSEL__DM2) 
/* Input Buffer Disable Override */
#define SP6_SPI_CSSEL_INP_DIS                (* (reg8 *) SP6_SPI_CSSEL__INP_DIS)
/* LCD Common or Segment Drive */
#define SP6_SPI_CSSEL_LCD_COM_SEG            (* (reg8 *) SP6_SPI_CSSEL__LCD_COM_SEG)
/* Enable Segment LCD */
#define SP6_SPI_CSSEL_LCD_EN                 (* (reg8 *) SP6_SPI_CSSEL__LCD_EN)
/* Slew Rate Control */
#define SP6_SPI_CSSEL_SLW                    (* (reg8 *) SP6_SPI_CSSEL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SP6_SPI_CSSEL_PRTDSI__CAPS_SEL       (* (reg8 *) SP6_SPI_CSSEL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SP6_SPI_CSSEL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SP6_SPI_CSSEL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SP6_SPI_CSSEL_PRTDSI__OE_SEL0        (* (reg8 *) SP6_SPI_CSSEL__PRTDSI__OE_SEL0) 
#define SP6_SPI_CSSEL_PRTDSI__OE_SEL1        (* (reg8 *) SP6_SPI_CSSEL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SP6_SPI_CSSEL_PRTDSI__OUT_SEL0       (* (reg8 *) SP6_SPI_CSSEL__PRTDSI__OUT_SEL0) 
#define SP6_SPI_CSSEL_PRTDSI__OUT_SEL1       (* (reg8 *) SP6_SPI_CSSEL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SP6_SPI_CSSEL_PRTDSI__SYNC_OUT       (* (reg8 *) SP6_SPI_CSSEL__PRTDSI__SYNC_OUT) 


#if defined(SP6_SPI_CSSEL__INTSTAT)  /* Interrupt Registers */

    #define SP6_SPI_CSSEL_INTSTAT                (* (reg8 *) SP6_SPI_CSSEL__INTSTAT)
    #define SP6_SPI_CSSEL_SNAP                   (* (reg8 *) SP6_SPI_CSSEL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins SP6_SPI_CSSEL_H */


/* [] END OF FILE */
