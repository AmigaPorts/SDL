---
title: 20 Exec Memory Allocation / Function Reference
manual: libraries
chapter: libraries
section: 20-exec-memory-allocation-function-reference
functions: [AddMemList, AllocAbs, AllocMem, AllocVec, Allocate, AvailMem, CopyMem, CopyMemQuick, FreeEntry, FreeMem, FreeVec, InitStruct, TypeOfMem]
libraries: [exec.library]
---

# 20 Exec Memory Allocation / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the Exec functions that handle
memory management.  See the Amiga ROM Kernel Reference Manual: Includes
and Autodocs for details on each call.


                    Table 20-1: Exec Memory Functions
  ________________________________________________________________________
 |                                                                        |
 |  Memory Function               Description                             |
 |========================================================================|
 |      [AllocMem()](autodocs-2.0/exec-library-allocmem.md)  Allocate memory with specified attributes.  If an     |
 |                  application needs to allocate some memory, it will    |
 |                  usually use this function.                            |
 |    [AddMemList()](autodocs-2.0/exec-library-addmemlist.md)  Add memory to the system free pool.                   |
 |      [AllocAbs()](autodocs-2.0/exec-library-allocabs.md)  Allocate memory at a specified location.              |
 |      [Allocate()](autodocs-2.0/exec-library-allocate.md)  Allocate memory from a private memory pool.           |
 |    [AllocEntry()](autodocs-2.0/exec-library-allocentry.md)  Allocate multiple memory blocks.                      |
 |      [AllocVec()](autodocs-2.0/exec-library-allocvec.md)  Allocate memory with specified attributes and keep    |
 |                  track of the size (V36).                              |
 |      [AvailMem()](autodocs-2.0/exec-library-availmem.md)  Return the amount of free memory, given certain       |
 |                  conditions.                                           |
 |       [CopyMem()](autodocs-2.0/exec-library-copymem.md)  Copy memory block, which can be non-aligned and of    |
 |                  arbitrary length.                                     |
 |  [CopyMemQuick()](autodocs-2.0/exec-library-copymemquick.md)  Copy aligned memory block.                            |
 |    [Deallocate()](autodocs-2.0/exec-library-deallocate.md)  Return memory block allocated, with Allocate() to the |
 |                  private memory pool.                                  |
 |     [FreeEntry()](autodocs-2.0/exec-library-freeentry.md)  Free multiple memory blocks, allocated with           |
 |                  AllocEntry().                                         |
 |       [FreeMem()](autodocs-2.0/exec-library-freemem.md)  Free a memory block of specified size, allocated with |
 |                  AllocMem().                                           |
 |       [FreeVec()](autodocs-2.0/exec-library-freevec.md)  Free a memory block allocated with AllocVec().        |
 |    [InitStruct()](autodocs-2.0/exec-library-initstruct.md)  Initialize memory from a table.                       |
 |     [TypeOfMem()](autodocs-2.0/exec-library-typeofmem.md)  Determine attributes of a specified memory address.   |
 |________________________________________________________________________|

---

## See Also

- [AddMemList — exec.library](../autodocs/exec.library.md#addmemlist)
- [AllocAbs — exec.library](../autodocs/exec.library.md#allocabs)
- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [AllocVec — exec.library](../autodocs/exec.library.md#allocvec)
- [Allocate — exec.library](../autodocs/exec.library.md#allocate)
- [AvailMem — exec.library](../autodocs/exec.library.md#availmem)
- [CopyMem — exec.library](../autodocs/exec.library.md#copymem)
- [CopyMemQuick — exec.library](../autodocs/exec.library.md#copymemquick)
- [FreeEntry — exec.library](../autodocs/exec.library.md#freeentry)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [FreeVec — exec.library](../autodocs/exec.library.md#freevec)
- [InitStruct — exec.library](../autodocs/exec.library.md#initstruct)
- [TypeOfMem — exec.library](../autodocs/exec.library.md#typeofmem)
