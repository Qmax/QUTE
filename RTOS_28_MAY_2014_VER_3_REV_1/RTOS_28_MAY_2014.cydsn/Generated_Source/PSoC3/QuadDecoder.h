/*******************************************************************************
* File Name: QuadDecoder.h  
* Version 2.30
*
* Description:
*  This file provides constants and parameter values for the Quadrature
*  Decoder component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_QUADRATURE_DECODER_QuadDecoder_H)
#define CY_QUADRATURE_DECODER_QuadDecoder_H

#include "cyfitter.h"
#include "CyLib.h"
#include "cytypes.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component QuadDec_v2_30 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#define QuadDecoder_COUNTER_SIZE               (8u)
#define QuadDecoder_COUNTER_SIZE_8_BIT         (8u)
#define QuadDecoder_COUNTER_SIZE_16_BIT        (16u)
#define QuadDecoder_COUNTER_SIZE_32_BIT        (32u)

#if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT)
    #include "QuadDecoder_Cnt8.h"
#else 
    /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT) || 
    *  (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT) 
    */
    #include "QuadDecoder_Cnt16.h"
#endif /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT */

extern uint8 QuadDecoder_initVar;


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define QuadDecoder_COUNTER_RESOLUTION         (1u)


/***************************************
*       Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} QuadDecoder_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  QuadDecoder_Init(void) ;
void  QuadDecoder_Start(void) ;
void  QuadDecoder_Stop(void) ;
void  QuadDecoder_Enable(void) ;
uint8 QuadDecoder_GetEvents(void) ;
void  QuadDecoder_SetInterruptMask(uint8 mask) ;
uint8 QuadDecoder_GetInterruptMask(void) ;
int8 QuadDecoder_GetCounter(void) ;
void  QuadDecoder_SetCounter(int8 value)
;
void  QuadDecoder_Sleep(void) ;
void  QuadDecoder_Wakeup(void) ;
void  QuadDecoder_SaveConfig(void) ;
void  QuadDecoder_RestoreConfig(void) ;

#if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT)
    CY_ISR_PROTO(QuadDecoder_ISR);
#endif /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT */


/***************************************
*           API Constants
***************************************/

#if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT)
    #define QuadDecoder_ISR_NUMBER             ((uint8) QuadDecoder_isr__INTC_NUMBER)
    #define QuadDecoder_ISR_PRIORITY           ((uint8) QuadDecoder_isr__INTC_PRIOR_NUM)
#endif /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT */


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QuadDecoder_GLITCH_FILTERING           (1u)
#define QuadDecoder_INDEX_INPUT                (0u)


/***************************************
*    Initial Parameter Constants
***************************************/

#if (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT)
    #define QuadDecoder_COUNTER_INIT_VALUE    (0x80u)
#else 
    /* (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_16_BIT) ||
    *  (QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_32_BIT)
    */
    #define QuadDecoder_COUNTER_INIT_VALUE    (0x8000u)
    #define QuadDecoder_COUNTER_MAX_VALUE     (0x7FFFu)
#endif /* QuadDecoder_COUNTER_SIZE == QuadDecoder_COUNTER_SIZE_8_BIT */


/***************************************
*             Registers
***************************************/

#define QuadDecoder_STATUS_REG                 (* (reg8 *) QuadDecoder_bQuadDec_Stsreg__STATUS_REG)
#define QuadDecoder_STATUS_PTR                 (  (reg8 *) QuadDecoder_bQuadDec_Stsreg__STATUS_REG)
#define QuadDecoder_STATUS_MASK                (* (reg8 *) QuadDecoder_bQuadDec_Stsreg__MASK_REG)
#define QuadDecoder_STATUS_MASK_PTR            (  (reg8 *) QuadDecoder_bQuadDec_Stsreg__MASK_REG)
#define QuadDecoder_SR_AUX_CONTROL             (* (reg8 *) QuadDecoder_bQuadDec_Stsreg__STATUS_AUX_CTL_REG)
#define QuadDecoder_SR_AUX_CONTROL_PTR         (  (reg8 *) QuadDecoder_bQuadDec_Stsreg__STATUS_AUX_CTL_REG)


/***************************************
*        Register Constants
***************************************/

#define QuadDecoder_COUNTER_OVERFLOW_SHIFT     (0x00u)
#define QuadDecoder_COUNTER_UNDERFLOW_SHIFT    (0x01u)
#define QuadDecoder_COUNTER_RESET_SHIFT        (0x02u)
#define QuadDecoder_INVALID_IN_SHIFT           (0x03u)
#define QuadDecoder_COUNTER_OVERFLOW           ((uint8) (0x01u << QuadDecoder_COUNTER_OVERFLOW_SHIFT))
#define QuadDecoder_COUNTER_UNDERFLOW          ((uint8) (0x01u << QuadDecoder_COUNTER_UNDERFLOW_SHIFT))
#define QuadDecoder_COUNTER_RESET              ((uint8) (0x01u << QuadDecoder_COUNTER_RESET_SHIFT))
#define QuadDecoder_INVALID_IN                 ((uint8) (0x01u << QuadDecoder_INVALID_IN_SHIFT))

#define QuadDecoder_INTERRUPTS_ENABLE_SHIFT    (0x04u)
#define QuadDecoder_INTERRUPTS_ENABLE          ((uint8)(0x01u << QuadDecoder_INTERRUPTS_ENABLE_SHIFT))
#define QuadDecoder_INIT_INT_MASK              (0x0Fu)


/******************************************************************************************
* Following code are OBSOLETE and must not be used starting from Quadrature Decoder 2.20
******************************************************************************************/
#define QuadDecoder_DISABLE                    (0x00u)


#endif /* CY_QUADRATURE_DECODER_QuadDecoder_H */


/* [] END OF FILE */
