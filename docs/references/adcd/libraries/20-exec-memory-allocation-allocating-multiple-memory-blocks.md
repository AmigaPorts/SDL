---
title: 20 Exec Memory Allocation / Allocating Multiple Memory Blocks
manual: libraries
chapter: libraries
section: 20-exec-memory-allocation-allocating-multiple-memory-blocks
functions: [FreeEntry]
libraries: [exec.library]
---

# 20 Exec Memory Allocation / Allocating Multiple Memory Blocks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Exec provides the routines [AllocEntry()](autodocs-2.0/exec-library-allocentry.md) and [FreeEntry()](libraries/20-allocating-multiple-memory-blocks-sample-code.md) to allocate
multiple memory blocks in a single call. AllocEntry() accepts a data
structure called a MemList, which contains the information about the size
of the memory blocks to be allocated and the requirements, if any, that
you have regarding the allocation. The MemList structure is found in the
include file <exec/[memory.h](autodocs-2.0/includes-exec-memory-h.md)> and is defined as follows:


```c
    struct MemList
    {
        struct Node     ml_Node;
        UWORD           ml_NumEntries;      /* number of MemEntrys */
        struct MemEntry ml_ME[1];           /* where the MemEntrys begin*/
    };
```
Node

```c
    allows you to link together multiple MemLists.  However, the node is
    ignored by the routines [AllocEntry()](autodocs-2.0/exec-library-allocentry.md) and [FreeEntry()](libraries/20-allocating-multiple-memory-blocks-sample-code.md).
```
ml_NumEntries

    tells the system how many MemEntry sets are contained in this
    MemList.  Notice that a MemList is a variable-length structure and
    can contain as many sets of entries as you wish.
The [MemEntry](autodocs-2.0/includes-exec-memory-h.md) structure looks like this:


```c
    struct MemEntry
    {
        union {
            ULONG   meu_Reqs;   /* the AllocMem requirements */
            APTR    meu_Addr;   /* address of your memory */
            } me_Un;
        ULONG   me_Length;      /* the size of this request */
    };
```
 [Sample Code for Allocating Multiple Memory Blocks](libraries/20-allocating-multiple-memory-blocks-sample-code.md) 
 [Result of Allocating Multiple Memory Blocks](libraries/20-allocating-multiple-memory-blocks-result.md) 
 [Multiple Memory Blocks and Tasks](libraries/20-allocating-multiple-memory-multiple-memory-blocks-and.md) 
 [Summary of Multiple Memory Blocks Allocation Routines](libraries/20-allocating-multiple-memory-summary-of-allocation-routines.md) 

---

## See Also

- [FreeEntry — exec.library](../autodocs/exec.library.md#freeentry)
