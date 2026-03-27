---
title: 20 / / Summary of System Controlled Memory Handling Routines
manual: libraries
chapter: libraries
section: 20-summary-of-system-controlled-memory-handling-routines
functions: [AllocMem, AvailMem, CopyMem, CopyMemQuick, FreeMem, TypeOfMem]
libraries: [exec.library]
---

# 20 / / Summary of System Controlled Memory Handling Routines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) and [FreeMem()](libraries/20-exec-memory-allocation-memory-functions.md)

    These are system-wide memory allocation and deallocation routines.
    They use a memory free-list owned and managed by the system.
[AvailMem()](libraries/20-memory-info-functions-calling-memory-information.md)

    This routine returns the number of free bytes in a specified type of
    memory.
[TypeOfMem()](libraries/20-memory-info-functions-calling-memory-information.md)

    This routine returns the memory attributes of a specified memory
    address.
[CopyMem()](libraries/20-using-memory-copy-functions-copying-system-memory.md)/[CopyMemQuick()](libraries/20-using-memory-copy-functions-copying-system-memory.md)

```c
    CopyMem() is a general purpose memory copy routine. CopyMemQuick() is
    an optimized version of CopyMemQuick(), but has restrictions on the
    size and alignment of the arguments.
```

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [AvailMem — exec.library](../autodocs/exec.library.md#availmem)
- [CopyMem — exec.library](../autodocs/exec.library.md#copymem)
- [CopyMemQuick — exec.library](../autodocs/exec.library.md#copymemquick)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [TypeOfMem — exec.library](../autodocs/exec.library.md#typeofmem)
