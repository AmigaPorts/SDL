---
title: lib_examples/allocentry.c
manual: libraries
chapter: libraries
section: lib-examples-allocentry-c
functions: [FreeEntry]
libraries: [exec.library]
---

# lib_examples/allocentry.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* allocentry.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 allocentry.c
Blink FROM LIB:c.o,allocentry.o TO allocentry LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit ;

allocentry.c - example of allocating several memory areas.
*/
#include <exec/types.h>
#include <exec/memory.h>
#include <clib/exec_protos.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef LATTICE
int CXBRK(void)  { return(0); }  /* Disable Lattice CTRL/C handling */
void chkabort(void) { return; }  /* really */
#endif

#define ALLOCERROR 0x80000000

struct MemList *memlist;             /* pointer to a MemList structure        */

struct MemBlocks /* define a new structure because C cannot initialize unions */
{
```c
    struct MemList  mn_head;         /* one entry in the header               */
    struct MemEntry mn_body[3];      /* additional entries follow directly as */
```
} memblocks;                         /* part of the same data structure       */

VOID main(VOID)
{
```c
    memblocks.mn_head.ml_NumEntries = 4; /* 4! Since the MemEntry starts at 1! */

    /* Describe the first piece of memory we want.  Because of our MemBlocks structure */
    /* setup, we reference the first MemEntry differently when initializing it.        */
    memblocks.mn_head.ml_ME[0].me_Reqs = MEMF_CLEAR;
    memblocks.mn_head.ml_ME[0].me_Length = 4000;

    memblocks.mn_body[0].me_Reqs   = MEMF_CHIP | MEMF_CLEAR;   /* Describe the other pieces of    */
    memblocks.mn_body[0].me_Length = 100000;                   /* memory we want. Additional      */
    memblocks.mn_body[1].me_Reqs   = MEMF_PUBLIC | MEMF_CLEAR; /* MemEntries are initialized this */
    memblocks.mn_body[1].me_Length = 200000;                   /* way. If we wanted even more en- */
    memblocks.mn_body[2].me_Reqs   = MEMF_PUBLIC;              /* tries, we would need to declare */
    memblocks.mn_body[2].me_Length = 25000;                    /* a larger MemEntry array in our  */
                                                               /* MemBlocks structure.            */

    memlist = (struct MemList *)AllocEntry((struct MemList *)&memblocks);

    if ((ULONG)memlist & ALLOCERROR)          /* 'error' bit 31 is set (see below). */
    {
       printf("AllocEntry FAILED\n");
       exit(200);
    }
    /* We got all memory we wanted.  Use it and call FreeEntry() to free it */
    printf("AllocEntry succeeded - now freeing all allocated blocks\n");
    FreeEntry(memlist);
```
}

---

## See Also

- [FreeEntry — exec.library](../autodocs/exec.library.md#freeentry)
