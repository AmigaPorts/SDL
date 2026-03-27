---
title: lib_examples/vertb.c
manual: libraries
chapter: libraries
section: lib-examples-vertb-c
functions: []
libraries: []
---

# lib_examples/vertb.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* vertb.c - Execute me to compile me with SAS C 5.10
LC -d0 -b1 -cfistq -v -y -j73 vertb.c
Blink FROM LIB:c.o,vertb.o,vertbserver.o TO vertb LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit ; */
/* vertb.c - Vertical blank interrupt server example.  Must be linked with vertbserver.o. */

#include <exec/memory.h>
#include <exec/interrupts.h>
#include <dos/dos.h>
#include <hardware/custom.h>
#include <hardware/intbits.h>
#include <clib/exec_protos.h>
#include <stdio.h>

#ifdef LATTICE
int CXBRK(void)  { return(0); }  /* Disable Lattice CTRL/C handling */
void chkabort(void) { return; }  /* really */
#endif

extern void VertBServer();  /* proto for asm interrupt server */

void main(void)
{
```c
    struct Interrupt *vbint;
    ULONG counter = 0;
    ULONG endcount;
                                                                         /* Allocate memory for  */
    if (vbint = AllocMem(sizeof(struct Interrupt), MEMF_PUBLIC|MEMF_CLEAR))   /* interrupt node. */
    {
        vbint->is_Node.ln_Type = NT_INTERRUPT;         /* Initialize the node. */
        vbint->is_Node.ln_Pri = -60;
        vbint->is_Node.ln_Name = "VertB-Example";
        vbint->is_Data = (APTR)&counter;
        vbint->is_Code = VertBServer;


        AddIntServer(INTB_VERTB, vbint); /* Kick this interrupt server to life. */

        printf("VBlank server will increment a counter every frame.\n");
        printf("counter started at zero, CTRL-C to remove server\n");

        Wait(SIGBREAKF_CTRL_C);
        endcount = counter;
        printf("%ld vertical blanks occurred\nRemoving server\n", endcount);

        RemIntServer(INTB_VERTB, vbint);
        FreeMem(vbint, sizeof(struct Interrupt));
    }
    else printf("Can't allocate memory for interrupt node\n");
```
}

