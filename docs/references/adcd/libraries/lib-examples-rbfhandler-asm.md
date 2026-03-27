---
title: lib_examples/rbfhandler.asm
manual: libraries
chapter: libraries
section: lib-examples-rbfhandler-asm
functions: []
libraries: []
---

# lib_examples/rbfhandler.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* rbfhandler.asm. Example interrupt handler for rbf.
*
* Assembled with Howesoft Adapt 680x0 Macro Assembler Rel. 1.0
* hx68 from: rbfhandler.asm to rbfhandler.o INCDIR include:
* blink from lib:c.o rbf.o rbfhandler.o to rbf lib lib:lc.lib lib:amiga.lib
*

    INCLUDE "exec/types.i"
    INCLUDE "hardware/custom.i"
    INCLUDE "hardware/intbits.i"

        XDEF    _RBFHandler
JSRLIB MACRO

```c
       XREF _LVO\1
       JSR  _LVO\1(A6)
       ENDM
```
BUFLEN    EQU    256


       STRUCTURE RBFDATA,0
        APTR   rd_task
        ULONG  rd_signal
        UWORD  rd_buffercount
        STRUCT rd_charbuffer,BUFLEN+2
        STRUCT rd_flagbuffer,BUFLEN+2
        STRUCT rd_name,32
        LABEL RBFDATA_SIZEOF
* Entered with:
*  D0 == scratch
*  D1 == INTENAT & INTREQR (scratch)
*  A0 == custom chips (scratch)
*  A1 == is_Data which is RBFDATA structure (scratch)
*  A5 == vector to our code (scratch)
*  A6 == pointer to ExecBase (scratch)
*
* Note - This simple handler just receives one buffer full of serial
* input data, signals main, then ignores all subsequent serial data.
*

    section code
_RBFHandler:                            ;entry to our interrupt handler

```c
        MOVE.W  serdatr(A0),D1          ;get the input word (flags and char)

        MOVE.W  rd_buffercount(A1),D0   ;get our buffer index
        CMPI.W  #BUFLEN,D0              ;no more room in our buffer ?
        BEQ.S   ExitHandler             ;yes - just exit (ignore new char)
        LEA.L   rd_charbuffer(A1),A5    ;else get our character buffer address
        MOVE.B  D1,0(A5,D0.W)           ;store character in our character buffer
        LEA.L   rd_flagbuffer(A1),A5    ;get our flag buffer address
        LSR.W   #8,d1                   ;shift flags down
        MOVE.B  D1,0(A5,D0.W)           ;store flags in flagbuffer

        ADDQ.W  #1,D0                   ;increment our buffer index
        MOVE.W  D0,rd_buffercount(A1)   ;   and replace it
        CMPI.W  #BUFLEN,D0              ;did our buffer just become full ?
        BNE.S   ExitHandler             ;no - we can exit
        MOVE.L  A0,-(SP)                ;yes - save custom
        MOVE.L  rd_signal(A1),D0        ;get signal allocated in main()
        MOVE.L  rd_task(A1),A1          ;and pointer to main task
        JSRLIB  Signal                  ;tell main we are full
        MOVE.L  (SP)+,A0                ;restore custom
                                        ;Note: system call trashed D0-D1/A0-A1
```
ExitHandler:

```c
        MOVE.W  #INTF_RBF,intreq(A0)    ;clear the interrupt
        RTS                             ;return to exec

        END
```
