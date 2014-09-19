/*******************************************************************************
* File Name: SPIS_2.h
* Version 2.20
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the SPI Slave Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIS_SPIS_2_H)
#define CY_SPIS_SPIS_2_H

#include "cyfitter.h"

/* Check to see if required defines such as CY_PSOC3 and CY_PSOC5 are available */
/* They are defined starting with cy_boot v2.30 */
#ifndef CY_PSOC3
	#error Component SPI_Slave_v2_20 requires cy_boot v2.30 or later
#endif

#ifdef SPIS_2_TxInternalInterrupt__ES2_PATCH
    #if(CY_PSOC3_ES2 && SPIS_2_TxInternalInterrupt__ES2_PATCH)
        #include <intrins.h>
        #define SPIS_2_TX_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    #endif /* End PSOC3_ES2 */
#endif /* SPIS_2_TxInternalInterrupt__ES2_PATCH */

#ifdef SPIS_2_RxInternalInterrupt__ES2_PATCH
    #if(CY_PSOC3_ES2 && SPIS_2_RxInternalInterrupt__ES2_PATCH)
        #include <intrins.h>
        #define SPIS_2_RX_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    #endif /* End PSOC3_ES2 */
#endif /* SPIS_2_RxInternalInterrupt__ES2_PATCH */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define SPIS_2_DataWidth                  (8u)
#define SPIS_2_InternalTxInterruptEnabled (0u)
#define SPIS_2_InternalRxInterruptEnabled (0u)
#define SPIS_2_ModeUseZero                (1u)
#define SPIS_2_BidirectionalMode          (0u)
#define SPIS_2_Mode                       (0u)

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects
*/
#define SPIS_2_DATAWIDHT                (SPIS_2_DataWidth)
#define SPIS_2_InternalInterruptEnabled (0u)


/***************************************
*        Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct _SPIS_2_backupStruct
{
    uint8 enableState;
    uint8 cntrPeriod;

    #if(CY_PSOC3_ES2 || CY_PSOC5_ES1) /* PSoC3 ES2 or earlier, PSoC5 ES1 */

        uint8 saveSrTxIntMask;
        uint8 saveSrRxIntMask;

    #endif /* End CY_PSOC3_ES2 || CY_PSOC5_ES1 */

} SPIS_2_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  SPIS_2_Init(void);
void  SPIS_2_Enable(void) ;
void  SPIS_2_Start(void);
void  SPIS_2_Stop(void) ;
void  SPIS_2_EnableTxInt(void) ;
void  SPIS_2_EnableRxInt(void) ;
void  SPIS_2_DisableTxInt(void) ;
void  SPIS_2_DisableRxInt(void) ;
void  SPIS_2_SetTxInterruptMode(uint8 intSource) ;
void  SPIS_2_SetRxInterruptMode(uint8 intSource) ;
uint8 SPIS_2_ReadTxStatus(void);
uint8 SPIS_2_ReadRxStatus(void);
void  SPIS_2_WriteTxData(uint8 txData);

#if(SPIS_2_ModeUseZero == 1u)
    void  SPIS_2_WriteTxDataZero(uint8 txDataByte) \
                                              ;
#endif /* (SPIS_2_ModeUseZero == 1u) */

uint8 SPIS_2_ReadRxData(void);
uint8 SPIS_2_GetRxBufferSize(void) ;
uint8 SPIS_2_GetTxBufferSize(void) ;
void  SPIS_2_ClearRxBuffer(void);
void  SPIS_2_ClearTxBuffer(void);

#if (SPIS_2_BidirectionalMode == 1u)
    void  SPIS_2_TxEnable(void) ;
    void  SPIS_2_TxDisable(void) ;
#endif /* SPIS_2_BidirectionalMode == 1u */

void  SPIS_2_PutArray(uint8 *buffer, uint8 byteCount);
void  SPIS_2_ClearFIFO(void) ;
void  SPIS_2_Sleep(void);
void  SPIS_2_Wakeup(void);
void  SPIS_2_SaveConfig(void);
void  SPIS_2_RestoreConfig(void) ;

CY_ISR_PROTO(SPIS_2_TX_ISR);
CY_ISR_PROTO(SPIS_2_RX_ISR);

/* Macros for getting software status of SPIS Statusi Register */
#define SPIS_2_GET_STATUS_TX(swTxSts) (uint8)(SPIS_2_TX_STATUS_REG | \
                                                       (swTxSts & SPIS_2_STS_CLR_ON_RD_BYTES_MASK))
#define SPIS_2_GET_STATUS_RX(swRxSts) (uint8)(SPIS_2_RX_STATUS_REG | \
                                                       (swRxSts & SPIS_2_STS_CLR_ON_RD_BYTES_MASK))

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects
*/
#define SPIS_2_WriteByte      (SPIS_2_WriteTxData)
#define SPIS_2_ReadByte       (SPIS_2_ReadRxData)
#define SPIS_2_WriteByteZero  (SPIS_2_WriteTxDataZero)
void  SPIS_2_SetInterruptMode(uint8 intSource) ;
uint8 SPIS_2_ReadStatus(void);
void  SPIS_2_EnableInt(void) ;
void  SPIS_2_DisableInt(void) ;


/***************************************
*           API Constants
***************************************/

#define SPIS_2_TX_ISR_NUMBER     (SPIS_2_TxInternalInterrupt__INTC_NUMBER)
#define SPIS_2_RX_ISR_NUMBER     (SPIS_2_RxInternalInterrupt__INTC_NUMBER)
#define SPIS_2_TX_ISR_PRIORITY   (SPIS_2_TxInternalInterrupt__INTC_PRIOR_NUM)
#define SPIS_2_RX_ISR_PRIORITY   (SPIS_2_RxInternalInterrupt__INTC_PRIOR_NUM)


/***************************************
*    Initial Parameter Constants
***************************************/

#define SPIS_2_INT_ON_SPI_DONE    (0u << SPIS_2_STS_SPI_DONE_SHIFT)
#define SPIS_2_INT_ON_TX_EMPTY    (0u << SPIS_2_STS_TX_FIFO_EMPTY_SHIFT)
#define SPIS_2_INT_ON_TX_NOT_FULL (0u << SPIS_2_STS_TX_FIFO_NOT_FULL_SHIFT)
#define SPIS_2_INT_ON_BYTE_COMP   (0u << SPIS_2_STS_BYTE_COMPLETE_SHIFT)

#define SPIS_2_TX_INIT_INTERRUPTS_MASK  (SPIS_2_INT_ON_SPI_DONE | \
                                            SPIS_2_INT_ON_TX_EMPTY | SPIS_2_INT_ON_TX_NOT_FULL | \
                                            SPIS_2_INT_ON_BYTE_COMP)

#define SPIS_2_INT_ON_RX_EMPTY     (0u << SPIS_2_STS_RX_FIFO_EMPTY_SHIFT)
#define SPIS_2_INT_ON_RX_NOT_EMPTY (0u << SPIS_2_STS_RX_FIFO_NOT_EMPTY_SHIFT)
#define SPIS_2_INT_ON_RX_OVER      (0u << SPIS_2_STS_RX_FIFO_OVERRUN_SHIFT)
#define SPIS_2_INT_ON_RX_FULL      (0u << SPIS_2_STS_RX_FIFO_FULL_SHIFT)

#define SPIS_2_RX_INIT_INTERRUPTS_MASK (SPIS_2_INT_ON_RX_EMPTY | \
                                            SPIS_2_INT_ON_RX_NOT_EMPTY | SPIS_2_INT_ON_RX_OVER | \
                                            SPIS_2_INT_ON_RX_FULL)

#define SPIS_2_BITCTR_INIT           (SPIS_2_DataWidth - 1u)

#define SPIS_2__MODE_00 0
#define SPIS_2__MODE_01 1
#define SPIS_2__MODE_10 2
#define SPIS_2__MODE_11 3


#define SPIS_2_TXBUFFERSIZE          (4u)
#define SPIS_2_RXBUFFERSIZE          (4u)

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects
*/
#define SPIS_2_INIT_INTERRUPTS_MASK  (SPIS_2_INT_ON_SPI_DONE | SPIS_2_INT_ON_TX_EMPTY | \
                                            SPIS_2_INT_ON_TX_NOT_FULL | SPIS_2_INT_ON_RX_EMPTY | \
                                            SPIS_2_INT_ON_RX_NOT_EMPTY | SPIS_2_INT_ON_RX_OVER | \
                                            SPIS_2_INT_ON_BYTE_COMP)


/***************************************
*             Registers
***************************************/

#if(CY_PSOC3_ES2 || CY_PSOC5_ES1)

    #define SPIS_2_TXDATA_ZERO_REG           (* (reg8  *) \
            SPIS_2_BSPIS_es2_SPISlave_sR8_DpMISO_u0__A0_REG)

    #define SPIS_2_TXDATA_ZERO_PTR           (  (reg8  *) \
            SPIS_2_BSPIS_es2_SPISlave_sR8_DpMISO_u0__A0_REG)

    #define SPIS_2_RXDATA_ZERO_REG           (* (reg8  *) \
            SPIS_2_BSPIS_es2_SPISlave_sR8_DpMOSI_u0__A0_REG)

    #define SPIS_2_RXDATA_ZERO_PTR           (  (reg8  *) \
            SPIS_2_BSPIS_es2_SPISlave_sR8_DpMOSI_u0__A0_REG)

    #define SPIS_2_TXDATA_REG                (* (reg8  *) \
            SPIS_2_BSPIS_es2_SPISlave_sR8_DpMISO_u0__F0_REG)

    #define SPIS_2_TXDATA_PTR                (  (reg8  *) \
            SPIS_2_BSPIS_es2_SPISlave_sR8_DpMISO_u0__F0_REG)

    #define SPIS_2_RXDATA_REG                (* (reg8  *) \
            SPIS_2_BSPIS_es2_SPISlave_sR8_DpMOSI_u0__F0_REG)

    #define SPIS_2_RXDATA_PTR                (  (reg8  *) \
            SPIS_2_BSPIS_es2_SPISlave_sR8_DpMOSI_u0__F0_REG)

    #define SPIS_2_TX_AUX_CONTROL_DP0_REG       (* (reg8 *) \
            SPIS_2_BSPIS_es2_SPISlave_sR8_DpMISO_u0__DP_AUX_CTL_REG)
    #define SPIS_2_TX_AUX_CONTROL_DP0_PTR       (  (reg8 *) \
            SPIS_2_BSPIS_es2_SPISlave_sR8_DpMISO_u0__DP_AUX_CTL_REG)

    #if(SPIS_2_DataWidth > 8u)

        #define SPIS_2_TX_AUX_CONTROL_DP1_REG   (* (reg8 *) \
                SPIS_2_BSPIS_es2_SPISlave_sR8_DpMISO_u1__DP_AUX_CTL_REG)
        #define SPIS_2_TX_AUX_CONTROL_DP1_PTR   (  (reg8 *) \
                SPIS_2_BSPIS_es2_SPISlave_sR8_DpMISO_u1__DP_AUX_CTL_REG)

    #endif /* SPIS_2_DataWidth > 8u */

#else /* CY_PSOC3_ES3  || CY_PSOC5_ES2 or later */

    #define SPIS_2_TXDATA_ZERO_REG          (* (reg8  *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

    #define SPIS_2_TXDATA_ZERO_PTR           (  (reg8  *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

    #define SPIS_2_RXDATA_ZERO_REG           (* (reg8  *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

    #define SPIS_2_RXDATA_ZERO_PTR           (  (reg8  *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

    #define SPIS_2_TXDATA_REG                (* (reg8  *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__F0_REG)

    #define SPIS_2_TXDATA_PTR                (  (reg8  *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__F0_REG)

    #define SPIS_2_RXDATA_REG                (* (reg8  *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__F1_REG)

    #define SPIS_2_RXDATA_PTR                (  (reg8  *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__F1_REG)

    #define SPIS_2_TX_AUX_CONTROL_DP0_REG       (* (reg8 *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__DP_AUX_CTL_REG)
    #define SPIS_2_TX_AUX_CONTROL_DP0_PTR       (  (reg8 *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__DP_AUX_CTL_REG)

    #define SPIS_2_RX_AUX_CONTROL_DP0_REG       (* (reg8 *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__DP_AUX_CTL_REG)
    #define SPIS_2_RX_AUX_CONTROL_DP0_PTR       (  (reg8 *) \
            SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u0__DP_AUX_CTL_REG)

    #if(SPIS_2_DataWidth > 8u)

        #define SPIS_2_TX_AUX_CONTROL_DP1_REG   (* (reg8 *) \
                SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u1__DP_AUX_CTL_REG)
        #define SPIS_2_TX_AUX_CONTROL_DP1_PTR   (  (reg8 *) \
                SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u1__DP_AUX_CTL_REG)

        #define SPIS_2_RX_AUX_CONTROL_DP1_REG   (* (reg8 *) \
                SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u1__DP_AUX_CTL_REG)
        #define SPIS_2_RX_AUX_CONTROL_DP1_PTR   (  (reg8 *) \
                SPIS_2_BSPIS_es3_SPISlave_sR8_Dp_u1__DP_AUX_CTL_REG)

    #endif /* SPIS_2_DataWidth > 8u */

#endif /* (CY_PSOC3_ES2 || CY_PSOC5_ES1) or earlier */

#define SPIS_2_COUNTER_PERIOD_REG    (* (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_BitCounter__PERIOD_REG)
#define SPIS_2_COUNTER_PERIOD_PTR    (  (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_BitCounter__PERIOD_REG)

#define SPIS_2_TX_STATUS_MASK_REG    (* (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_TxStsReg__MASK_REG)
#define SPIS_2_TX_STATUS_MASK_PTR    (  (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_TxStsReg__MASK_REG)

#define SPIS_2_RX_STATUS_MASK_REG    (* (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_RxStsReg__MASK_REG)
#define SPIS_2_RX_STATUS_MASK_PTR    (  (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_RxStsReg__MASK_REG)

#define SPIS_2_ONE_REG               (* (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_dpCounter_u0__D1_REG)
#define SPIS_2_ONE_PTR               (  (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_dpCounter_u0__D1_REG)

#define SPIS_2_TX_STATUS_REG         (* (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_TxStsReg__STATUS_REG)
#define SPIS_2_TX_STATUS_PTR         (  (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_TxStsReg__STATUS_REG)

#define SPIS_2_RX_STATUS_REG         (* (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_RxStsReg__STATUS_REG)
#define SPIS_2_RX_STATUS_PTR         (  (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_RxStsReg__STATUS_REG)

#define SPIS_2_COUNTER_CONTROL_REG   (* (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_BitCounter__CONTROL_AUX_CTL_REG)
#define SPIS_2_COUNTER_CONTROL_PTR   (  (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_BitCounter__CONTROL_AUX_CTL_REG)

#define SPIS_2_TX_STATUS_ACTL_REG    (* (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_TxStsReg__STATUS_AUX_CTL_REG)
#define SPIS_2_TX_STATUS_ACTL_PTR    (  (reg8 *) \
        SPIS_2_TX_BSPIS_es3_SPISlave_TxStsReg__STATUS_AUX_CTL_REG)

#define SPIS_2_RX_STATUS_ACTL_REG    (* (reg8 *) \
        SPIS_2_BSPIS_es3_SPISlave_RxStsReg__STATUS_AUX_CTL_REG)
#define SPIS_2_RX_STATUS_ACTL_PTR    (  (reg8 *) \
        SPIS_2_RX_BSPIS_es3_SPISlave_RxStsReg__STATUS_AUX_CTL_REG)

#if(SPIS_2_BidirectionalMode)

    #define SPIS_2_CONTROL_REG       (* (reg8 *) \
   SPIS_2_BSPIS_es3_SPISlave_SyncCtl_CtrlReg__CONTROL_REG)
    #define SPIS_2_CONTROL_PTR       (  (reg8 *) \
   SPIS_2_BSPIS_es3_SPISlave_SyncCtl_CtrlReg__CONTROL_REG)

#endif /* SPIS_2_BidirectionalMode */

/* Obsolete register names. Not to be used in new designs */
#define SPIS_2_TXDATA_ZERO               (SPIS_2_TXDATA_ZERO_REG)
#define SPIS_2_TXDATA                    (SPIS_2_TXDATA_REG)
#define SPIS_2_RXDATA                    (SPIS_2_RXDATA_REG)
#define SPIS_2_MISO_AUX_CONTROLDP0       (SPIS_2_MISO_AUX_CTRL_DP0_REG)
#define SPIS_2_MOSI_AUX_CONTROLDP0       (SPIS_2_MOSI_AUX_CTRL_DP0_REG)
#define SPIS_2_TXBUFFERREAD              (SPIS_2_txBufferRead)
#define SPIS_2_TXBUFFERWRITE             (SPIS_2_txBufferWrite)
#define SPIS_2_RXBUFFERREAD              (SPIS_2_rxBufferRead)
#define SPIS_2_RXBUFFERWRITE             (SPIS_2_rxBufferWrite)

#if(SPIS_2_DataWidth > 8u)

    #define SPIS_2_MISO_AUX_CONTROLDP1   (SPIS_2_MISO_AUX_CTRL_DP1_REG)
    #define SPIS_2_MOSI_AUX_CONTROLDP1   (SPIS_2_MOSI_AUX_CTRL_DP0_REG)

#endif /* SPIS_2_DataWidth > 8u */

#define SPIS_2_COUNTER_PERIOD            (SPIS_2_COUNTER_PERIOD_REG)
#define SPIS_2_COUNTER_CONTROL           (SPIS_2_COUNTER_CONTROL_REG)
#define SPIS_2_ONE                       (SPIS_2_ONE_REG)
#define SPIS_2_STATUS                    (SPIS_2_TX_STATUS_REG)
#define SPIS_2_STATUS_MASK               (SPIS_2_TX_STATUS_MASK_REG)
#define SPIS_2_STATUS_ACTL               (SPIS_2_TX_STATUS_ACTL_REG)


/***************************************
*       Register Constants
***************************************/

/* Status Register Definitions */
#define SPIS_2_STS_SPI_DONE_SHIFT             (0x00u)
#define SPIS_2_STS_TX_FIFO_NOT_FULL_SHIFT     (0x01u)
#define SPIS_2_STS_TX_FIFO_EMPTY_SHIFT        (0x02u)
#define SPIS_2_STS_RX_FIFO_NOT_EMPTY_SHIFT    (0x03u)
#define SPIS_2_STS_RX_FIFO_EMPTY_SHIFT        (0x04u)
#define SPIS_2_STS_RX_FIFO_OVERRUN_SHIFT      (0x05u)
#define SPIS_2_STS_RX_FIFO_FULL_SHIFT         (0x06u)
#define SPIS_2_STS_BYTE_COMPLETE_SHIFT        (0x06u)

#define SPIS_2_STS_SPI_DONE                   (0x01u << SPIS_2_STS_SPI_DONE_SHIFT)
#define SPIS_2_STS_TX_FIFO_EMPTY              (0x01u << SPIS_2_STS_TX_FIFO_EMPTY_SHIFT)
#define SPIS_2_STS_TX_FIFO_NOT_FULL           (0x01u << SPIS_2_STS_TX_FIFO_NOT_FULL_SHIFT)
#define SPIS_2_STS_RX_FIFO_EMPTY              (0x01u << SPIS_2_STS_RX_FIFO_EMPTY_SHIFT)
#define SPIS_2_STS_RX_FIFO_NOT_EMPTY          (0x01u << SPIS_2_STS_RX_FIFO_NOT_EMPTY_SHIFT)
#define SPIS_2_STS_RX_FIFO_OVERRUN            (0x01u << SPIS_2_STS_RX_FIFO_OVERRUN_SHIFT)
#define SPIS_2_STS_RX_FIFO_FULL               (0x01u << SPIS_2_STS_RX_FIFO_FULL_SHIFT)
#define SPIS_2_STS_BYTE_COMPLETE              (0x01u << SPIS_2_STS_BYTE_COMPLETE_SHIFT)

#define SPIS_2_STS_CLR_ON_RD_BYTES_MASK       (0x61u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define SPIS_2_INT_ENABLE                     (0x10u)
#define SPIS_2_FIFO_CLR                       (0x03u)

/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define SPIS_2_CNTR_ENABLE                    (0x20u)

/* Bi-Directional mode control bit */
#define SPIS_2_CTRL_TX_SIGNAL_EN              (0x01u)

/* Datapath Auxillary Control Register definitions */
#define SPIS_2_AUX_CTRL_FIFO0_CLR             (0x00u)
#define SPIS_2_AUX_CTRL_FIFO1_CLR             (0x00u)
#define SPIS_2_AUX_CTRL_FIFO0_LVL             (0x00u)
#define SPIS_2_AUX_CTRL_FIFO1_LVL             (0x00u)
#define SPIS_2_STATUS_ACTL_INT_EN_MASK        (0x10u)

/* Obosolete Status Register Definitions *DO NOT USE IN NEW DESIGNS* */
#define SPIS_2_STS_TX_BUF_NOT_FULL_SHIFT      (0x01u)
#define SPIS_2_STS_TX_BUF_FULL_SHIFT          (0x02u)
#define SPIS_2_STS_RX_BUF_NOT_EMPTY_SHIFT     (0x03u)
#define SPIS_2_STS_RX_BUF_EMPTY_SHIFT         (0x04u)
#define SPIS_2_STS_RX_BUF_OVERRUN_SHIFT       (0x05u)

#define SPIS_2_STS_TX_BUF_NOT_FULL            (0x01u << SPIS_2_STS_TX_BUF_NOT_FULL_SHIFT)
#define SPIS_2_STS_TX_BUF_FULL                (0x01u << SPIS_2_STS_TX_BUF_FULL_SHIFT)
#define SPIS_2_STS_RX_BUF_NOT_EMPTY           (0x01u << SPIS_2_STS_RX_BUF_NOT_EMPTY_SHIFT)
#define SPIS_2_STS_RX_BUF_EMPTY               (0x01u << SPIS_2_STS_RX_BUF_EMPTY_SHIFT)
#define SPIS_2_STS_RX_BUF_OVERRUN             (0x01u << SPIS_2_STS_RX_BUF_OVERRUN_SHIFT)

#endif  /* CY_SPIS_SPIS_2_H */


/* [] END OF FILE */
