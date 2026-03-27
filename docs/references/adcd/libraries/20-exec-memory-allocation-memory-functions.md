---
title: 20 Exec Memory Allocation / Memory Functions
manual: libraries
chapter: libraries
section: 20-exec-memory-allocation-memory-functions
functions: [AllocMem, FreeMem]
libraries: [exec.library]
---

# 20 Exec Memory Allocation / Memory Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Normally, an application uses the [AllocMem()](autodocs-2.0/exec-library-allocmem.md) function to ask for memory:


```c
    APTR AllocMem(ULONG byteSize, ULONG attributes);
```
The byteSize argument is the amount of memory the application needs and
attributes is a bit field which specifies any special memory
characteristics ([described later](libraries/20-memory-functions-memory-attributes.md)).  If [AllocMem()](autodocs-2.0/exec-library-allocmem.md) is successful, it
returns a pointer to a block of memory.  The memory allocation will fail
if the system cannot find a big enough block with the requested
attributes.  If AllocMem() fails, it returns NULL.

Because the system only keeps track of how much free memory is available
and not how much is in use, it has no idea what memory has been allocated
by any task.  This means an application has to explicitly return, or
deallocate, any memory it has allocated so the system can return that
memory to the free memory list.  If an application does not return a block
of memory to the system, the system will not be able to reallocate that
memory to some other task.  That block of memory will be lost until the
Amiga is reset.  If you are using [AllocMem()](autodocs-2.0/exec-library-allocmem.md) to allocate memory, a call to
[FreeMem()](autodocs-2.0/exec-library-freemem.md) will return that memory to the system:


```c
    void FreeMem(APTR mymemblock, ULONG byteSize);
```
Here mymemblock is a pointer to the memory block the application is
returning to the system and byteSize is the same size that was passed when
the memory was allocated with [AllocMem()](autodocs-2.0/exec-library-allocmem.md).

Unlike some compiler memory allocation functions, the Amiga system memory
allocation functions return memory blocks that are at least longword
aligned.  This means that the allocated memory will always start on an
address which is at least evenly divisible by four.  This alignment makes
the memory suitable for any system structures or buffers which require
word or longword alignment, and also provides optimal alignment for stacks
and memory copying.

 [Memory Attributes](libraries/20-memory-functions-memory-attributes.md) 
 [Allocating System Memory](libraries/20-memory-functions-allocating-system-memory.md) 
 [Freeing System Memory](libraries/20-memory-functions-freeing-system-memory.md) 
 [Memory Information Functions](libraries/20-memory-functions-memory-information-functions.md) 
 [Using Memory Copy Functions](libraries/20-memory-functions-using-memory-copy-functions.md) 
 [Summary of System Controlled Memory Handling Routines](libraries/20-summary-of-system-controlled-memory-handling-routines.md) 

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
