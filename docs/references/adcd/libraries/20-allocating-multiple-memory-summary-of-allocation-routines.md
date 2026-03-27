---
title: 20 / Allocating Multiple Memory / Summary of Allocation Routines
manual: libraries
chapter: libraries
section: 20-allocating-multiple-memory-summary-of-allocation-routines
functions: [FreeEntry, InitStruct]
libraries: [exec.library]
---

# 20 / Allocating Multiple Memory / Summary of Allocation Routines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[AllocEntry()](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) and [FreeEntry()](libraries/20-allocating-multiple-memory-blocks-sample-code.md)

    These are routines for allocating and freeing multiple memory blocks
    with a single call.
[InitStruct()](autodocs-2.0/exec-library-initstruct.md)

    This routine initializes memory from data and offset values in a
    table.  Typically only assembly language programs benefit from using
    this routine.  For more details see the Amiga ROM Kernel Reference
    Manual: Include & Autodocs.

---

## See Also

- [FreeEntry — exec.library](../autodocs/exec.library.md#freeentry)
- [InitStruct — exec.library](../autodocs/exec.library.md#initstruct)
