;*******************************************************************************
;* FILENAME: `$INSTANCE_NAME`_config.A51
;* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
;*
;* DESCRIPTION:
;*  Configuration file for RTX51 Tiny Real-Time Operating System (RTOS)
;*  for PSoC 3.
;*
;* NOTE:
;*  This file is taken from RTX-51 TINY  Real-Time Operating System Package
;*  Copyright KEIL ELEKTRONIK GmbH and Keil Software, Inc. 1991-2002
;*  Version 2.02
;*
;********************************************************************************
;* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
;* You may use this file only in accordance with the license, terms, conditions, 
;* disclaimers, and limitations in the end user license agreement accompanying 
;* the software package with which this file was provided.
;********************************************************************************

$NOMOD51

;*******************************************************************************
;* RTX-51 TINY Scheduling mode
;* Configure the RTX51Tiny scheduling mode and Round Robin timeout value
;*******************************************************************************

;* Define the register bank used for the interrupt service routine.
INT_REGBANK     EQU     1   ; default is Registerbank 1

;* Define Round-Robin Timeout in clock ticks input to interrupt component.
IF (`$SchedulingMode`)
TIMESHARING     EQU     `$RoundRobinTimeout`   ; default is 5 clock ticks.
ELSE
TIMESHARING     EQU     0   ; 0 disables Round-Robin Task
ENDIF

;*******************************************************************************
;* Long User Interrupt Routines: set to 1 if application contains
;* user interrupt functions that may take longer than a hardware timer
;* interval for execution.
;*      0 user interrupts execute fast.
;*      1 user interrupts take long execution times.
;*******************************************************************************
LONG_USR_INTR   EQU `$LongUsrIntEnable`

;*******************************************************************************
;* RTX-51 TINY Stack Space
;* The following EQU statements defines the size of the internal RAM used
;* for stack area and the minimum free space on the stack.  A macro defines
;* the code executed when there is not enough free stack on the CPU stack.
;*******************************************************************************
;* Define the highest RAM address used for CPU stack
RAMTOP      EQU     0FFH    ; default is address (256-1)

IF (`$StackErrorMacroEn`)
        EXTRN CODE (`$StackErrorMacro`)
ENDIF

IF (`$StackCheckEnable`)

FREE_STACK  EQU `$FreeStackLimit`   ; default is 20 bytes free space on stack

STACK_ERROR MACRO
IF (`$StackErrorMacroEn`)
        lcall `$StackErrorMacro`
ELSE
        clr     EA      ; disable interrupts
        sjmp    $       ; endless loop if stack space is exhausted
ENDIF
        ENDM
ELSE

FREE_STACK  EQU     0   ; the value 0 disables stack checking

ENDIF

;*******************************************************************************
;*
;* PSoC 3 CPU IDLE CODE
;*
;* The following macro defines the code executed when there is no
;* ready task in the system.  The code must set the CPU into an IDLE MODE
;* that stops instruction execution until an interrupt occurs.
;*      0  CPU_IDLE MACRO is not inserted
;*      1  CPU_IDLE MACRO is executed
;*******************************************************************************

;* Disable or Enable CPU_IDLE CODE
CPU_IDLE_CODE   EQU     0

;* Stop CPU execution until hardware interrupt
;* Executed when there is no active task in the system.
CPU_IDLE    MACRO
        ENDM

;*******************************************************************************
;*                      End of User Configuration Part
;*******************************************************************************

        ;* SFR Symbols
        PSW     DATA    0D0H
        ACC     DATA    0E0H
        B       DATA    0F0H
        SP      DATA    81H
        DPL     DATA    82H
        DPH     DATA    83H
        IE      DATA    0A8H

        ;* IE
        EA      BIT     0AFH

        NAME    ?RTX51_TINY_KERNAL

        PUBLIC  ?RTX_CURRENTTASK
        PUBLIC  ?RTX_RAMTOP
        PUBLIC  os_switch_task
        PUBLIC  ?RTX?SET_ISR
        PUBLIC  TIMERINT

        EXTRN   NUMBER (?RTX_MAXTASKN)      ; max Task Number

?RTX_RAMTOP   EQU   RAMTOP

?RTX_REGISTERBANK EQU   INT_REGBANK * 8
        DSEG  AT  ?RTX_REGISTERBANK
        DS    2                 ; temporary space

?RTX_SAVEACC:       DS    1
saveacc             EQU   R2    ; for access in interrupt service routine
?RTX_SAVEPSW:       DS    1
savepsw             EQU   R3    ; for access in interrupt service routine
?RTX_CURRENTTASK:   DS    1
currenttask         EQU   R4    ; for access in interrupt service routine

IF (TIMESHARING <> 0)
?RTX_ROBINTIME:     DS    1
robintime           EQU   R5    ; for access in interrupt service routine
ENDIF

;*******************************************************************************
;* Table of Task Entry Pointers
;*******************************************************************************
        PUBLIC  ?RTX_TASKENTRY

?RTX?TASKENT?S  SEGMENT CODE
        RSEG    ?RTX?TASKENT?S
?RTX_TASKENTRY: DS  2

;*******************************************************************************
;* Table of Stack Pointers for each task
;*******************************************************************************
        PUBLIC  ?RTX_TASKSP

?RTX?TASKSP?S   SEGMENT IDATA
        RSEG    ?RTX?TASKSP?S
?RTX_TASKSP:    DS  1

;*******************************************************************************
;* Table of Task Timer/State Pointers
;*******************************************************************************
        PUBLIC  ?RTX_TASKSTATUS

?RTX?TASKSTATE?S  SEGMENT IDATA
            RSEG    ?RTX?TASKSTATE?S
?RTX_TASKSTATUS:
TimerVal:   DS  1   ; Task Timer (Software Timer for each task)
TaskState:  DS  1   ; Task Status (state of each Task)

;*******************************************************************************
;*  Definitions for Bits in Task State
;*  TaskState.0  = Wait for Signal
;*  TaskState.1  = Wait for TimeOut
;*  TaskState.2  = Signal Flag
;*  TaskState.3  = TimeOut Flag
;*  TaskState.4  = Task Ready (Wait for Running)
;*  TaskState.5  = Task Active (enabled with os_create)
;*  TaskState.6  = Round Robin Time Out
;*  TaskState.7  = Run Flag
;*******************************************************************************
;* Byte mask definitions
    K_SIG       EQU     1
    K_TMO       EQU     2
    SIG_EVENT   EQU     4
    TMO_EVENT   EQU     8
    K_READY     EQU     16
    K_ACTIVE    EQU     32
    K_ROBIN     EQU     64
    K_IVL       EQU     128  ; not a task state bit; only used in os_wait
    RDY_EVENT   EQU     128  ; READY status flag
    K_RDY       EQU     128

;* Bit position definitions
    B_WAITSIG   EQU     0
    B_WAITTIM   EQU     1
    B_SIGNAL    EQU     2
    B_TIMEOUT   EQU     3
    B_READY     EQU     4
    B_ACTIVE    EQU     5
    B_ROBIN     EQU     6
    B_IVL       EQU     7    ; not a task state bit; only used in os_wait
    B_RDY       EQU     7


IF (TIMESHARING OR CPU_IDLE_CODE)
?RTX?BITS   SEGMENT     BIT
        RSEG    ?RTX?BITS
ENDIF

IF (TIMESHARING)
?RTX_TS_DELAY:  DBIT    1   ; Status bit set when task switch in progress
ENDIF

IF (CPU_IDLE_CODE)
?RTX_ISR_SIG:   DBIT    1   ; Status bit set when interrupt or os_set_signal
ENDIF

?RTX?CODE       SEGMENT CODE
        RSEG    ?RTX?CODE
        USING   0           ; Registerbank 0 for following code

IF (FREE_STACK <> 0)
?RTX_STACKERROR:
        STACK_ERROR         ; User defined Stack Error Code
ENDIF

HW_TIMER:
        reti

;*******************************************************************************
;* void TIMERINT(void)
;* This function is called from the interrupt component of RTX51Tiny Component
;* This function is responsible for task scheduling.
;*******************************************************************************
TIMERINT:

IF (LONG_USR_INTR)
        push    ACC
        mov     A,PSW
        anl     A,#018H
        xrl     A,#?RTX_REGISTERBANK
        jnz     CONT_TIMINT

;* Avoid recursive timer interrupt
        pop     ACC
        reti        ; Return from Recursive Timer Interrupt

CONT_TIMINT:
        pop     ACC
ENDIF
        lcall   HW_TIMER

        mov     ?RTX_SAVEPSW,PSW
        mov     PSW,#?RTX_REGISTERBANK
        mov     saveacc,ACC     ; ACC required by some Cygnal devices

IF (FREE_STACK <> 0)
;* Check if enough free stack is available
        mov     A,currenttask
        add     A,#?RTX?TASKSP?S+1
        mov     R0,A
        mov     A,@R0
        cjne    currenttask,#?RTX_MAXTASKN,checkstack
        mov     A,#RAMTOP
checkstack:
        clr     C
        subb    A,SP
        cjne    A,#FREE_STACK,$+3
        jc      ?RTX_STACKERROR
ENDIF

;* Update & Check Task Timers
        mov     R1,#?RTX_MAXTASKN+1
        mov     R0,#?RTX?TASKSTATE?S
TIMERLOOP:
        dec     @R0          ; Decrement timer
        mov     A,@R0
        inc     R0           ; advance to TaskState
        jnz     NoTimeout
        clr     EA
        mov     A,@R0
        jnb     ACC.B_WAITTIM,NoWaitTimeout
        orl     A,#(K_READY+TMO_EVENT)
        mov     @R0,A
NoWaitTimeout:
        setb    EA
NoTimeout:
        inc     R0           ; advance to TaskTimer
        djnz    R1,TIMERLOOP

        mov     A,saveacc
        mov     PSW,savepsw
        USING   0           ; Registerbank 0 for following code

IF (TIMESHARING == 0)
;* Round Robin Task Switching not required.  System Interrupt ends here
?RTX?SET_ISR:
IF (CPU_IDLE_CODE)
        setb    ?RTX_ISR_SIG
ENDIF
        ret
ENDIF

IF (TIMESHARING)
;* Round Robin Task Switching required.  Check if task generates timeout
;* Check for Round Robin Timeout on the current task
        jnb     ?RTX_TS_DELAY,CheckRobinTime
NoRobinTimeout:
?RTX?SET_ISR:
IF (CPU_IDLE_CODE)
        setb    ?RTX_ISR_SIG
ENDIF
        ret
CheckRobinTime:
        djnz    ?RTX_ROBINTIME,NoRobinTimeout

?RTX_TASKSWITCHING:
        push    ACC
        push    PSW
        push    B
        push    DPH
        push    DPL
        push    AR0
        push    AR1
        push    AR2
        push    AR3
        push    AR4
        push    AR5
        push    AR6
        push    AR7

        mov     A,?RTX_CURRENTTASK
        rl      A
        add     A,#?RTX?TASKSTATE?S+1
        mov     R0,A
        mov     A,#K_ROBIN
        clr     EA
        orl     A,@R0
        mov     @R0,A
        setb    EA
ENDIF

;*******************************************************************************
;* void os_switch_task (void)
;* Performs a Task-Switch
;*
;* Variable 'current' assigned to Register 'R6'
;* Variable 'next'    assigned to Register 'R7'
;* Variable 'i'       assigned to Register 'R0'
;* Variable 'limit'   assigned to Register 'R5'
;*******************************************************************************

os_switch_task:
os_switch_task1:

;*      next = current;
IF (TIMESHARING <> 0)
        setb    ?RTX_TS_DELAY       ; Delay Task Switching
ENDIF
        mov     A,?RTX_CURRENTTASK
        mov     R7,A

;*      while (1) {
        rl      A
        add     A,#?RTX?TASKSTATE?S+1
        mov     R0,A
?C0001:
;*      if (++next == MAXTASKN+1)  next = 0;
        inc     R7
        inc     R0
        inc     R0
IF (CPU_IDLE_CODE)
        mov     A,R7
        cjne    A,?RTX_CURRENTTASK,NoIDLE
        jbc     ?RTX_ISR_SIG,NoIDLE
        CPU_IDLE          ; CPU sleep
NoIDLE:
ENDIF
        cjne    R7,#?RTX_MAXTASKN+1,?C0003
        mov     R7,#0
        mov     R0,#?RTX?TASKSTATE?S+1
?C0003:
;*      if (STATE[next].st & K_READY)  break;
        mov     A,@R0
        jnb     ACC.B_READY,?C0001
;*      }

PUBLIC  ?RTX_NEXTID
PUBLIC  ?RTX_NEXTTASK

?RTX_NEXTID     EQU     AR7
?RTX_NEXTTASK:
        nop     ; for Debugging

;*      while (current < next) {
?C0005:
        mov     A,?RTX_CURRENTTASK
        clr     C
        subb    A,R7
        jnc     ?C0011

;*      current++;
        inc     ?RTX_CURRENTTASK

;*      i = STKP[current];
        mov     A,#?RTX?TASKSP?S
        add     A,?RTX_CURRENTTASK
        mov     R0,A
        mov     A,@R0
        mov     R5,A

;*      STKP[current] = SP;
        mov     @R0,SP

;*      if (current == MAXTASKN) limit = RAMTOP;
        inc     R0
        mov     A,@R0
        mov     R6,?RTX_CURRENTTASK
        cjne    R6,#?RTX_MAXTASKN,?C0007
        mov     A,#RAMTOP
?C0007:
        xch     A,R5
        mov     R0,A

;*      else    limit = STKP[current+1];
;*      while (i != limit) {
?C0009:
        mov     A,R0
        xrl     A,R5
        jz      ?C0005
;*      SP++; i++; STACK[SP] = STACK[i];
        inc     R0
        mov     A,@R0
        push    ACC
        sjmp    ?C0009
;*      }
;*  }
?C0011:

;*      while (current > next) {
        mov     A,?RTX_CURRENTTASK
        setb    C
        subb    A,R7
        jc      ?C0012

        mov     A,?RTX_CURRENTTASK
        add     A,#?RTX?TASKSP?S+1
        mov     R0,A
        mov     A,@R0

;*      if (current == (MAXTASKN)) i = RAMTOP;
;*      else                       i = STKP[current+1];
        mov     R6,?RTX_CURRENTTASK
        cjne    R6,#?RTX_MAXTASKN,?C0013
        mov     A,#RAMTOP
?C0013:
        mov     R5,A
;*      limit = STKP[current];
        dec     R0
        mov     A,@R0
        xch     A,R5
        mov     R0,A

;*      while (SP != limit) {
?C0015:
        mov     A,SP
        xrl     A,R5
        jz      ?C0016

;*      STACK[i] = STACK[SP]; i--; SP--;
        pop     ACC
        mov     @R0,A
        dec     R0

        sjmp    ?C0015
?C0016:
;*      }
;*      STKP[current] = i;
        mov     A,?RTX_CURRENTTASK
        add     A,#?RTX?TASKSP?S
        xch     A,R0
        mov     @R0,A

;*      current--;
        dec     ?RTX_CURRENTTASK
        sjmp    ?C0011
?C0012:
;*  }

;*      RoundRobinTime = ?RTX_TIMESHARING
IF (TIMESHARING)
        mov     ?RTX_ROBINTIME,#TIMESHARING
ENDIF

;*      if (STATE[current].st & K_ROBIN)  goto RobinOn;
        mov     A,?RTX_CURRENTTASK
        rl      A
        add     A,#?RTX?TASKSTATE?S+1
        mov     R0,A
        mov     R7,#SIG_EVENT
        clr     EA
        mov     A,@R0
IF (TIMESHARING)
        jbc     ACC.B_ROBIN,RobinOn
ENDIF
;*      if ((STATE[current].st & K_SIG) && (STATE[current].st & SIG_EVENT)
;*      goto SignalOn;
        jnb     ACC.B_WAITSIG,SignalOff
        jbc     ACC.B_SIGNAL,SignalOn

SignalOff:
;*      if ((STATE[current].st & K_TMO) && (STATE[current].st & TMO_EVENT)
;*      goto TimeOutOn;
        mov     R7,#0       ; No Event
        jnb     ACC.B_WAITTIM,NoEvent
        jnb     ACC.B_TIMEOUT,NoEvent
TimeOutOn:
        mov     R7,#TMO_EVENT
        anl     A,#0F4H
SignalOn:
NoEvent:
        anl     A,#NOT (K_RDY + K_TMO + K_SIG)  ; Clear RDY + Wait bits
        xch     A,@R0
        setb    EA

        anl     A,#K_RDY
        orl     AR7,A
IF (TIMESHARING <> 0)
        clr     ?RTX_TS_DELAY
        ret
ELSE
        ret
ENDIF

IF (TIMESHARING <> 0)
RobinOn:
        mov     @R0,A
        setb    EA

        pop     AR7
        pop     AR6
        pop     AR5
        pop     AR4
        pop     AR3
        pop     AR2
        pop     AR1
        pop     AR0
        pop     DPL
        pop     DPH
        pop     B
        pop     PSW
        pop     ACC
        clr     ?RTX_TS_DELAY
        ret         ; Restart Task
ENDIF
;*      }
;*  }


;*******************************************************************************
;* void main(void)
;* Start RTX-51 Tiny Kernel
;*******************************************************************************

        EXTRN CODE (?C_STARTUP)
        PUBLIC  main

main:
        mov     R0,#?RTX?TASKSP?S
        mov     @R0,SP
        mov     A,#?RTX_MAXTASKN
        jz      main2
        mov     R7,A
main1:
        inc     R0
        mov     @R0,#RAMTOP
        djnz    R7,main1
main2:
        mov     R7,#?RTX_MAXTASKN+1
        clr     A
        mov     R0,#?RTX?TASKSTATE?S
main1x:
        mov     @R0,A
        inc     R0
        mov     @R0,A
        inc     R0
        djnz    R7,main1x
        mov     R0,#?RTX?TASKSTATE?S+1
        mov     @R0,#K_ACTIVE+K_READY
        mov     DPTR,#?RTX?TASKENT?S
        mov     A,#1
        movc    A,@A+DPTR
        push    ACC
        clr     A
        movc    A,@A+DPTR
        push    ACC
IF (TIMESHARING <> 0)
        mov     ?RTX_ROBINTIME,#TIMESHARING
ENDIF
        setb    EA
        ret     ; Start Task 0

;*******************************************************************************
;* For Debugging
;*******************************************************************************

PUBLIC ?RTX_TASKIDX
?RTX_TASKIDX:   DB  ?RTX_MAXTASKN

;*******************************************************************************
;* End of file.
;*******************************************************************************
        END
