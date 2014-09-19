/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#if !defined(__TASK2_H__)
#define __TASK2_H__
#include <rtx51tny.h>

#include <device.h>
extern unsigned char prnt_en,i,switch_cmd[],rx_word[],dat_cnt,cmd_exct,pos;
extern uint16 delay;

#define Code_ID 0x27

void TASK_2 (void);

//[] END OF FILE
