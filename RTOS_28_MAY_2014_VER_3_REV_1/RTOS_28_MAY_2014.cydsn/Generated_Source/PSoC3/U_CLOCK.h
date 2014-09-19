/*******************************************************************************
* File Name: U_CLOCK.h
* Version 2.10
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_U_CLOCK_H)
#define CY_CLOCK_U_CLOCK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void U_CLOCK_Start(void) ;
void U_CLOCK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void U_CLOCK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void U_CLOCK_StandbyPower(uint8 state) ;
void U_CLOCK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 U_CLOCK_GetDividerRegister(void) ;
void U_CLOCK_SetModeRegister(uint8 modeBitMask) ;
void U_CLOCK_ClearModeRegister(uint8 modeBitMask) ;
uint8 U_CLOCK_GetModeRegister(void) ;
void U_CLOCK_SetSourceRegister(uint8 clkSource) ;
uint8 U_CLOCK_GetSourceRegister(void) ;
#if defined(U_CLOCK__CFG3)
void U_CLOCK_SetPhaseRegister(uint8 clkPhase) ;
uint8 U_CLOCK_GetPhaseRegister(void) ;
#endif /* defined(U_CLOCK__CFG3) */

#define U_CLOCK_Enable()                       U_CLOCK_Start()
#define U_CLOCK_Disable()                      U_CLOCK_Stop()
#define U_CLOCK_SetDivider(clkDivider)         U_CLOCK_SetDividerRegister(clkDivider, 1u)
#define U_CLOCK_SetDividerValue(clkDivider)    U_CLOCK_SetDividerRegister((clkDivider) - 1u, 1u)
#define U_CLOCK_SetMode(clkMode)               U_CLOCK_SetModeRegister(clkMode)
#define U_CLOCK_SetSource(clkSource)           U_CLOCK_SetSourceRegister(clkSource)
#if defined(U_CLOCK__CFG3)
#define U_CLOCK_SetPhase(clkPhase)             U_CLOCK_SetPhaseRegister(clkPhase)
#define U_CLOCK_SetPhaseValue(clkPhase)        U_CLOCK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(U_CLOCK__CFG3) */


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
#endif /* defined(U_CLOCK__CFG3) */


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
#endif /* defined(U_CLOCK__CFG3) */

#endif /* CY_CLOCK_U_CLOCK_H */


/* [] END OF FILE */
