---
title: 20 / Memory Functions / Freeing System Memory
manual: libraries
chapter: libraries
section: 20-memory-functions-freeing-system-memory
functions: [AllocMem, AllocVec, FreeMem, FreeVec]
libraries: [exec.library]
---

# 20 / Memory Functions / Freeing System Memory

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following examples free the memory chunks shown in the previous calls
to [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md).


```c
    FreeMem(apointer, 100);
    FreeMem(anotherptr, 1000);
```
A memory block allocated with [AllocVec()](libraries/20-memory-functions-allocating-system-memory.md) must be returned to the system
pool with the [FreeVec()](autodocs-2.0/exec-library-freevec.md).  This function uses the stored size in the
allocation to free the memory block, so there is no need to specify the
size of the memory block to free.


```c
    FreeVec(yap);
```
[FreeMem()](libraries/20-exec-memory-allocation-memory-functions.md) and [FreeVec()](autodocs-2.0/exec-library-freevec.md) return no status.  However, if you attempt to free
a memory block in the middle of a chunk that the system believes is
already free, you will cause a system crash. Applications must free the
same size memory blocks that they allocated.  An allocated block may not
be deallocated as smaller pieces.  Due to the internal way the system
rounds up and aligns allocations.  Partial deallocations can corrupt the
system memory list.


```c
    Leave Memory Allocations Out Of Interrupt Code.
    -----------------------------------------------
    Do not allocate or deallocate system memory from within interrupt
    code.  The "[Exec Interrupts](libraries/26-servicing-interrupts-environment.md)" chapter explains that an interrupt may
    occur at any time, even during a memory allocation process.  As a
    result, system data structures may not be internally consistent at
    this time.
```

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [AllocVec — exec.library](../autodocs/exec.library.md#allocvec)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [FreeVec — exec.library](../autodocs/exec.library.md#freevec)
