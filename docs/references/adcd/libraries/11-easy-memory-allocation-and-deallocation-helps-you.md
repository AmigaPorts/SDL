---
title: 11 / Easy Memory Allocation and Deallocation / Helps You Remember
manual: libraries
chapter: libraries
section: 11-easy-memory-allocation-and-deallocation-helps-you
functions: [AllocMem, AllocRemember, FreeMem, FreeRemember]
libraries: [exec.library, intuition.library]
---

# 11 / Easy Memory Allocation and Deallocation / Helps You Remember

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [AllocRemember()](autodocs-2.0/intuition-library-allocremember.md) routine calls the Exec [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) function to perform
the memory allocation.  (Of course, the application may directly call Exec
memory functions, see the chapter "[Exec Memory Allocation](libraries/20-exec-memory-allocation.md)" for details.)

[AllocRemember()](autodocs-2.0/intuition-library-allocremember.md) performs two allocations each time it is called.  The
first allocation is the actual memory requested by the application.  This
memory is of the size and type specified in the call and is independent of
the second block of memory.  The second allocation is memory for a
[Remember](libraries/11-easy-memory-allocation-and-deallocation-the-remember.md) structure which is used to save the specifics of the allocation
in a linked list.  When [FreeRemember()](autodocs-2.0/intuition-library-freeremember.md) is called it uses the information
in this linked list to free all previous memory allocations at once.  This
is convenient since normally you would have to free each memory block one
at a time which requires knowing the size and base address of each one.

The [AllocRemember()](autodocs-2.0/intuition-library-allocremember.md) call takes three arguments:


```c
    APTR AllocRemember( struct Remember **rememberKey, unsigned long size,
                        unsigned long flags );
```
The rememberKey is the address of a pointer to a [Remember](libraries/11-easy-memory-allocation-and-deallocation-the-remember.md) structure.  Note
that this is a double indirection, not just a simple pointer.  The size is
the size, in bytes, of the requested allocation.  The flags argument is
the specification for the memory allocation.  These are the same as the
specifications for the Exec [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) function described in the chapter
on "[Exec Memory Allocation](libraries/20-exec-memory-allocation.md)".

If [AllocRemember()](autodocs-2.0/intuition-library-allocremember.md) succeeds, it returns the address of the allocated
memory block.  It returns a NULL if the allocation fails.

The [FreeRemember()](autodocs-2.0/intuition-library-freeremember.md) function gives the option of freeing memory in either
of two ways.  The first (and most useful) option is to free both the link
nodes that [AllocRemember()](autodocs-2.0/intuition-library-allocremember.md) created and the memory blocks to which they
correspond.  The second option is to free only the link nodes, leaving the
memory blocks for further use (and later deallocation via Exec's [FreeMem()](libraries/20-exec-memory-allocation-memory-functions.md)
function).  But, as a general rule, the application should never free only
the link nodes as this can greatly fragment memory.  If the link nodes are
not required, use the Exec memory allocation functions.

The [FreeRemember()](autodocs-2.0/intuition-library-freeremember.md) call is as follows:


```c
    void FreeRemember( struct Remember **rememberKey, long reallyForget );
```
Set the rememberKey argument to the address of a pointer to a [Remember](libraries/11-easy-memory-allocation-and-deallocation-the-remember.md)
structure.  This is the same value that was passed to previous calls to
[AllocRemember()](autodocs-2.0/intuition-library-allocremember.md).  The reallyForget argument is a boolean that should be
set to TRUE.  If TRUE, then both the link nodes and the memory blocks are
freed.  If FALSE, then only the link nodes are freed.  Again, applications
should avoid using the FALSE value since it can lead to highly fragmented
memory.

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [AllocRemember — intuition.library](../autodocs/intuition.library.md#allocremember)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [FreeRemember — intuition.library](../autodocs/intuition.library.md#freeremember)
