---
title: 20 / Allocating Multiple Memory Blocks / Sample Code
manual: libraries
chapter: libraries
section: 20-allocating-multiple-memory-blocks-sample-code
functions: [FreeEntry]
libraries: [exec.library]
---

# 20 / Allocating Multiple Memory Blocks / Sample Code

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's an example of showing how to use the [AllocEntry()](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) with multiple
blocks of memory.


```c
     [allocentry.c](libraries/lib-examples-allocentry-c.md) 
```
[AllocEntry()](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) returns a pointer to a new [MemList](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) of the same size as the
MemList that you passed to it.  For example, ROM code can provide a
MemList containing the requirements of a task and create a RAM-resident
copy of the list containing the addresses of the allocated entries.  The
pointer to the MemList is used as the argument for [FreeEntry()](autodocs-2.0/exec-library-freeentry.md) to free the
memory blocks.


```c
    Assembly Does Not Have [MemEntry](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md).
    --------------------------------
    The [MemList](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) structure used by assembly programmers is slightly
    different; it has only a label for the start of the MemEntry
    array.  See the Exec [AllocEntry()](autodocs-2.0/exec-library-allocentry.md) Autodoc for an example of using
    AllocEntry() from assembler.
```

---

## See Also

- [FreeEntry — exec.library](../autodocs/exec.library.md#freeentry)
