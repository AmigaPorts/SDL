---
title: Lib_examples/trap_c.c
manual: libraries
chapter: libraries
section: lib-examples-trap-c-c
functions: []
libraries: []
---

# Lib_examples/trap_c.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* trap_c.c - Execute me to compile me with SAS C 5.10
LC -b0 -cfistq -v -y -j73 trap_c.c
Blink FROM LIB:c.o,trap_c.o,trap_a.o TO trap LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit

trap_c.c - C module of sample integer divide-by-zero trap
*/
#include <exec/types.h>
#include <exec/tasks.h>
#include <clib/exec_protos.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) {return(0); }
#endif

extern ULONG trapa();           /* assembler trap code in trap_a.asm */

APTR oldTrapCode;
ULONG countdiv0;

void main(int argc, char **argv)
{
```c
    struct Task *thistask;
    ULONG k,j;

    thistask = FindTask(NULL);

    /* Save our task's current trap code pointer */
    oldTrapCode = thistask->tc_TrapCode;

    /* Point task to our assembler trap handler code.  Ours will just count */
    /* divide-by-zero traps, and pass other traps on to the normal TrapCode */
    thistask->tc_TrapCode = (APTR)trapa;

    countdiv0 = 0L;

    for(k=0; k<4; k++)            /* Let's divide by zero a few times */
       {
       printf("dividing %ld by zero... ",k);
       j = k/0L;
       printf("did it\n");
       }
    printf("\nDivide by zero happened %ld times\n",countdiv0);

    thistask->tc_TrapCode = oldTrapCode;     /* Restore old trap code */
```
}



* trap_a.asm - Example trap handling code (leaves D0 intact).  Entered
* in supervisor mode with the following on the supervisor stack:
*    0(sp).l = trap#
*    4(sp) Processor dependent exception frame

    INCLUDE "exec/types.i"
    INCLUDE "libraries/dos.i"

        XDEF _trapa
        XREF _countdiv0
        XREF _oldTrapCode

        CODE
_trapa:                                 ; our trap handler entry
```c
        CMPI.L  #5,(SP)                 ; is this a divide by zero ?
        BNE.S   notdiv0                 ; no
        ADD.L   #1,_countdiv0           ; yes, increment our div0 count
```
endtrap:
```c
        ADDQ    #4,SP                   ; remove exception number from SSP
        RTE                             ; return from exception
```
notdiv0:

```c
        TST.L   _oldTrapCode            ; is there another trap handler ?
        BEQ.S   endtrap                 ; no, so we'll exit
        MOVE.L  _oldTrapCode,-(SP)      ; yes, go on to old TrapCode
        RTS                             ; jumps to old TrapCode

        END
```
