/*******************************************************************************
* File Name: U_CLOCK.h
* Version 1.60
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_CLOCK_U_CLOCK_H)
#define CY_CLOCK_U_CLOCK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void U_CLOCK_Start(void) ;
void U_CLOCK_Stop(void) ;

#if(!(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3 && \
    CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES2) && \
	!(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5 && \
	CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_5A_ES1))
void U_CLOCK_StopBlock(void) ;
#endif

void U_CLOCK_StandbyPower(uint8 state) ;
void U_CLOCK_SetDividerRegister(uint16 clkDivider, uint8 reset) ;
uint16 U_CLOCK_GetDividerRegister(void) ;
void U_CLOCK_SetModeRegister(uint8 modeBitMask) ;
void U_CLOCK_ClearModeRegister(uint8 modeBitMask) ;
uint8 U_CLOCK_GetModeRegister(void) ;
void U_CLOCK_SetSourceRegister(uint8 clkSource) ;
uint8 U_CLOCK_GetSourceRegister(void) ;
#if defined(U_CLOCK__CFG3)
void U_CLOCK_SetPhaseRegister(uint8 clkPhase) ;
uint8 U_CLOCK_GetPhaseRegister(void) ;
#endif

#define U_CLOCK_Enable()                       U_CLOCK_Start()
#define U_CLOCK_Disable()                      U_CLOCK_Stop()
#define U_CLOCK_SetDivider(clkDivider)         U_CLOCK_SetDividerRegister(clkDivider, 1)
#define U_CLOCK_SetDividerValue(clkDivider)    U_CLOCK_SetDividerRegister((clkDivider) - 1, 1)
#define U_CLOCK_SetMode(clkMode)               U_CLOCK_SetModeRegister(clkMode)
#define U_CLOCK_SetSource(clkSource)           U_CLOCK_SetSourceRegister(clkSource)
#if defined(U_CLOCK__CFG3)
#define U_CLOCK_SetPhase(clkPhase)             U_CLOCK_SetPhaseRegister(clkPhase)
#define U_CLOCK_SetPhaseValue(clkPhase)        U_CLOCK_SetPhaseRegister((clkPhase) + 1)
#endif


/***************************************
*           API Constants
***************************************/

/* Constants SetPhase(), clkPhase parameter. Only valid for PSoC 3 ES2 and earlier. See datasheet for details. */
#if CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3 && \
   (CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES1 || \
    CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES2)
#define CYCLK_2_5NS             0x01 /* 2.5 ns delay. */
#define CYCLK_3_5NS             0x02 /* 3.5 ns delay. */
#define CYCLK_4_5NS             0x03 /* 4.5 ns delay. */
#define CYCLK_5_5NS             0x04 /* 5.5 ns delay. */
#define CYCLK_6_5NS             0x05 /* 6.5 ns delay. */
#define CYCLK_7_5NS             0x06 /* 7.5 ns delay. */
#define CYCLK_8_5NS             0x07 /* 8.5 ns delay. */
#define CYCLK_9_5NS             0x08 /* 9.5 ns delay. */
#define CYCLK_10_5NS            0x09 /* 10.5 ns delay. */
#define CYCLK_11_5NS            0x0A /* 11.5 ns delay. */
#define CYCLK_12_5NS            0x0B /* 12.5 ns delay. */
#endif


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define U_CLOCK_CLKEN              (* (reg8 *) U_CLOCK__PM_ACT_CFG)
#define U_CLOCK_CLKEN_PTR          ((reg8 *) U_CLOCK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define U_CLOCK_CLKSTBY            (* (reg8 *) U_CLOCK__PM_STBY_CFG)
#define U_CLOCK_CLKSTBY_PTR        ((reg8 *) U_CLOCK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define U_CLOCK_DIV_LSB            (* (reg8 *) U_CLOCK__CFG0)
#define U_CLOCK_DIV_LSB_PTR        ((reg8 *) U_CLOCK__CFG0)
#define U_CLOCK_DIV_PTR            ((reg16 *) U_CLOCK__CFG0)

/* Clock MSB divider configuration register. */
#define U_CLOCK_DIV_MSB            (* (reg8 *) U_CLOCK__CFG1)
#define U_CLOCK_DIV_MSB_PTR        ((reg8 *) U_CLOCK__CFG1)

/* Mode and source configuration register */
#define U_CLOCK_MOD_SRC            (* (reg8 *) U_CLOCK__CFG2)
#define U_CLOCK_MOD_SRC_PTR        ((reg8 *) U_CLOCK__CFG2)

#if defined(U_CLOCK__CFG3)
/* Analog clock phase configuration register */
#define U_CLOCK_PHASE              (* (reg8 *) U_CLOCK__CFG3)
#define U_CLOCK_PHASE_PTR          ((reg8 *) U_CLOCK__CFG3)
#endif


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define U_CLOCK_CLKEN_MASK         U_CLOCK__PM_ACT_MSK
#define U_CLOCK_CLKSTBY_MASK       U_CLOCK__PM_STBY_MSK

/* CFG2 field masks */
#define U_CLOCK_SRC_SEL_MSK        U_CLOCK__CFG2_SRC_SEL_MASK
#define U_CLOCK_MODE_MASK          (~(U_CLOCK_SRC_SEL_MSK))

#if defined(U_CLOCK__CFG3)
/* CFG3 phase mask */
#define U_CLOCK_PHASE_MASK         U_CLOCK__CFG3_PHASE_DLY_MASK
#endif

#endif /* CY_CLOCK_U_CLOCK_H */


/* [] END OF FILE */
