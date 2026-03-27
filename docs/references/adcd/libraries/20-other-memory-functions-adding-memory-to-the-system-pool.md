---
title: 20 / Other Memory Functions / Adding Memory to the System Pool
manual: libraries
chapter: libraries
section: 20-other-memory-functions-adding-memory-to-the-system-pool
functions: [AddMemList]
libraries: [exec.library]
---

# 20 / Other Memory Functions / Adding Memory to the System Pool

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When non-Autoconfig memory needs to be added to the system free pool, the
[AddMemList()](autodocs-2.0/exec-library-addmemlist.md) function can be used.  This function takes the size of the
memoryblock, its type, the priority for the memory list, the base address
and the name of the memory block.  A [MemHeader](libraries/20-exec-memory-allocation-other-memory-functions.md) structure will be placed at
the start of the memory block, the remainder of the memory block will be
made available for allocation. For example:


```c
    AddMemList(0x200000, MEMF_FAST, 0, 0xF00000, "FZeroBoard");
```
will add a two megabyte memory block, starting at $F00000 to the system
free pool as Fast memory.  The memory list entry is identified with
"FZeroBoard".

---

## See Also

- [AddMemList — exec.library](../autodocs/exec.library.md#addmemlist)
