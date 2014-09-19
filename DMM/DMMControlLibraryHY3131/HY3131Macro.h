/*
 * macro.h
 *
 *  Created on: 04-Mar-2014
 *      Author: Ravivarman.R
 */
#ifndef MACRO_H
#define MACRO_H

#define R50E        0
#define R500E       1
#define R5K         2
#define R50K        3
#define R500K       4
#define R5M         5
#define R50M        6

#define CNTY        7

#define DIODE       8

#define AC50mV      9
#define AC500mV     10
#define AC5V        11
#define AC50V       12
#define AC500V      13
#define AC1000V     14

#define DC50mV      15
#define DC500mV     16
#define DC5V        17
#define DC50V       18
#define DC500V      19
#define DC1000V     20

#define DC500uA		21
#define DC5mA		22
#define DC50mA      23
#define DC500mA     24
#define DC3A        25

#define AC500uA		26
#define AC5mA		27
#define AC50mA      28
#define AC500mA     29
#define AC3A        30

#define DMM_CMD             0x00F0
#define DMM_ADDR            0x00F2
#define DMM_DATA_TX_MSW     0x00F6
#define DMM_DATA_TX_LSW     0x00F4
#define DMM_DATA_RX_MSW     0x00FA
#define DMM_DATA_RX_LSW     0x00F8
#define DMM_CLK_DIV         0x00FC
#define DMM_RLY_SEL         0x00FE

#define DMM_CMD_BP             0x0036
#define DMM_ADDR_BP            0x0038
#define DMM_DATA_TX_MSW_BP     0x003C
#define DMM_DATA_TX_LSW_BP     0x003A
#define DMM_DATA_RX_MSW_BP     0x0040
#define DMM_DATA_RX_LSW_BP     0x003E
#define DMM_CLK_DIV_BP         0x0042
#define DMM_RLY_SEL_BP         0x0044

#define overRange   0x7fffff




#endif // MACRO_H
