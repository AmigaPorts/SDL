---
title: 20 Exec Memory Allocation / Other Memory Functions
manual: libraries
chapter: libraries
section: 20-exec-memory-allocation-other-memory-functions
functions: [AllocMem, Allocate]
libraries: [exec.library]
---

# 20 Exec Memory Allocation / Other Memory Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[Allocate()](autodocs-2.0/exec-library-allocate.md) and [Deallocate()](autodocs-2.0/exec-library-deallocate.md) use a memory region header, called [MemHeader](autodocs-2.0/includes-exec-memory-h.md),
as part of the calling sequence.  You can build your own local header to
manage memory locally. This structure takes the form:


```c
    struct MemHeader {
        struct Node       mh_Node;
        UWORD             mh_Attributes; /* characteristics of region  */
        struct  MemChunk *mh_First;      /* first free region          */
        APTR              mh_Lower;      /* lower memory bound         */
        APTR              mh_Upper;      /* upper memory bound + 1     */
        ULONG             mh_Free;       /* total number of free bytes */
    };
```
mh_Attributes

```c
    is ignored by [Allocate()](autodocs-2.0/exec-library-allocate.md) and [Deallocate()](autodocs-2.0/exec-library-deallocate.md).
```
mh_First

```c
    is the pointer to the first [MemChunk](autodocs-2.0/includes-exec-memory-h.md) structure.
```
mh_Lower

    is the lowest address within the memory block. This must be a
    multiple of eight bytes.
mh_Upper

```c
    is the highest address within the memory block + 1.  The highest
    address will itself be a multiple of eight if the block was allocated
    to you by [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md).
```
mh_Free

    is the total free space.
This structure is included in the include files <exec/[memory.h](autodocs-2.0/includes-exec-memory-h.md)> and
<exec/[memory.i](autodocs-2.0/includes-exec-memory-i.md)>.

The following sample code fragment shows the correct initialization of a
MemHeader structure.  It assumes that you wish to allocate a block of
memory from the global pool and thereafter manage it yourself using
[Allocate()](autodocs-2.0/exec-library-allocate.md) and [Deallocate()](autodocs-2.0/exec-library-deallocate.md).


```c
     [allocate.c](libraries/lib-examples-allocate-c.md) 

    How Memory Is Tagged.
    ---------------------
    Only free memory is "tagged" using a [MemChunk](autodocs-2.0/includes-exec-memory-h.md) linked list. Once
    memory is allocated, the system has no way of determining which task
    now has control of that memory.
```
If you allocate memory from the system, be sure to deallocate it when your
task exits.  You can accomplish this with matched deallocations, or by
adding a [MemList](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) to your task's [tc_MemEntry](libraries/20-exec-memory-allocation-memory-functions.md), or you can deallocate the
memory in the finalPC routine (which can be specified if you perform
[AddTask()](libraries/21-exec-tasks-task-creation.md) yourself).

 [Allocating Memory at an Absolute Address](libraries/20-other-memory-functions-allocating-memory-at-an-absolute.md) 
 [Adding Memory to the System Pool](libraries/20-other-memory-functions-adding-memory-to-the-system-pool.md) 

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [Allocate — exec.library](../autodocs/exec.library.md#allocate)
