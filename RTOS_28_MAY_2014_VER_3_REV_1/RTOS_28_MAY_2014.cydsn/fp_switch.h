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

#if !defined(__FP_SWITCH_H__)
#define __FP_SWITCH_H__
#include <device.h>
#include <rtx51tny.h>
#include <CYDEVICE.H>
#include <CYDEVICE_TRM.H>
#include <CYLIB.H>
#include <isr.H>

extern unsigned char prnt_en;

void fpswitch_INIT (void);
//void outside_main(char);
void Test_Chnl_Switch(unsigned char);
void Ref_Chnl_Switch(unsigned char);

//#define FPSWITCH 2

/* __FP_SWITCH_H__ */
#endif
//[] END OF FILE
