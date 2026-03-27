---
title: 20 / Memory Functions / Allocating System Memory
manual: libraries
chapter: libraries
section: 20-memory-functions-allocating-system-memory
functions: [AllocMem, AllocVec]
libraries: [exec.library]
---

# 20 / Memory Functions / Allocating System Memory

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following examples show how to allocate memory.


```c
    APTR  apointer,anotherptr, yap;

    if (!(apointer = AllocMem(100, MEMF_ANY)))
        {  /* COULDN'T GET MEMORY, EXIT */ }
```
[AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) returns the address of the first byte of a memory block that is
at least 100 bytes in size or NULL if there is not that much free memory.
Because the requirement field is specified as [MEMF_ANY](libraries/20-memory-functions-memory-attributes.md) (zero), memory will
be allocated from any one of the system-managed memory regions.


```c
    if (!(anotherptr = (APTR)AllocMem(1000, MEMF_CHIP | MEMF_CLEAR)))
        {  /* COULDN'T GET MEMORY, EXIT */ }
```
The example above allocates only chip-accessible memory, which the system
fills with zeros before it lets the application use the memory.  If the
system free memory list does not contain enough contiguous memory bytes in
an area matching your requirements, [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) returns a zero.  You must
check for this condition.

If you are using Release 2, you can use the [AllocVec()](autodocs-2.0/exec-library-allocvec.md) function to
allocate memory.  In addition to allocating a block of memory, this
function keeps track of the size of the memory block, so your application
doesn't have to remember it when it deallocates that memory block.  The
AllocVec() function allocates a little more memory to store the size of
the memory allocation request.


```c
    if (!(yap = (APTR)AllocVec(512, MEMF_CLEAR)))
        {  /* COULDN'T GET MEMORY, EXIT */ }
```

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [AllocVec — exec.library](../autodocs/exec.library.md#allocvec)
