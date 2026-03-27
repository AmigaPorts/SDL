---
title: lib_examples/allocate.c
manual: libraries
chapter: libraries
section: lib-examples-allocate-c
functions: []
libraries: []
---

# lib_examples/allocate.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* allocate.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 allocate.c
Blink FROM LIB:c.o,allocate.o TO allocate LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit ;
allocate.c - example of allocating and using a private memory pool.
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

#define BLOCKSIZE 4000     /* or whatever you need */

VOID main(VOID)
{
```c
    struct MemHeader *mh;
    struct MemChunk  *mc;
    APTR   block1, block2;

    /* Get the MemHeader needed to keep track of our new block. */
    mh = (struct MemHeader *)AllocMem((LONG)sizeof(struct MemHeader), MEMF_CLEAR);
    if (!mh) exit(10);

    /* Get the actual block the above MemHeader will manage. */
    if ( !(mc = (struct MemChunk *)AllocMem(BLOCKSIZE, 0)) );
    {
        FreeMem(mh, (LONG)sizeof(struct MemHeader));
        exit(10);
    }
    mh->mh_Node.ln_Type = NT_MEMORY;
    mh->mh_First        = mc;
    mh->mh_Lower        = (APTR)mc;
    mh->mh_Upper        = (APTR)(BLOCKSIZE + (ULONG)mc);
    mh->mh_Free         = BLOCKSIZE;

    mc->mc_Next  = NULL;                     /* Set up first chunk in the freelist */
    mc->mc_Bytes = BLOCKSIZE;

    block1 = (APTR)Allocate(mh,20);
    block2 = (APTR)Allocate(mh, 314);

    printf("Our MemHeader struct at $%lx. Our block of memory at $%lx\n", mh, mc);
    printf("Allocated from our pool: block1 at $%lx, block2 at $%lx\n", block1, block2);

    FreeMem(mh, (LONG)sizeof(struct MemHeader));
    FreeMem(mc, (LONG)BLOCKSIZE);
```
}

