---
title: 20 / Allocating Multiple Memory Blocks / Result
manual: libraries
chapter: libraries
section: 20-allocating-multiple-memory-blocks-result
functions: []
libraries: []
---

# 20 / Allocating Multiple Memory Blocks / Result

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [MemList](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) created by [AllocEntry()](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) contains [MemEntry](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) entries.  MemEntrys
are defined by a union statement, which allows one memory space to be
defined in more than one way.

If [AllocEntry()](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) returns a value with bit 31 clear, then all of the
[meu_Addr](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) positions in the returned [MemList](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) will contain valid memory
addresses meeting the requirements you have provided.  To use this memory
area, you would use code similar to the following:


```c
    #define ALLOCERROR 0x80000000
    struct  MemList *ml;
    APTR    data, moredata;

    if ( ! ((ULONG)ml & ALLOCERROR)))    /* After calling AllocEntry to */
                                         /* allocate ml */
    {
        data     = ml->ml_ME[0].me_Addr;
        moredata = ml->ml_ME[1].me_Addr;
    }
    else  exit(200);                     /* error during AllocEntry */
```
If [AllocEntry()](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) has problems while trying to allocate the memory you have
requested, instead of the address of a new [MemList](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md), it will return the
memory requirements value with which it had the problem.  Bit 31 of the
value returned will be set, and no memory will be allocated.  Entries in
the list that were already allocated will be freed.  For example, a failed
allocation of cleared Chip memory ([MEMF_CLEAR](libraries/20-memory-functions-memory-attributes.md) | [MEMF_CHIP](libraries/20-memory-functions-memory-attributes.md)) could be
indicated with 0x80010002, where bit 31 indicates failure, bit 16 is the
MEMF_CLEAR flag and bit 1 is the MEMF_CHIP flag.

