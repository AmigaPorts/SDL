---
title: 20 / / Memory Info Functions / Calling Memory Information Functions
manual: libraries
chapter: libraries
section: 20-memory-info-functions-calling-memory-information
functions: [AvailMem, TypeOfMem]
libraries: [exec.library]
---

# 20 / / Memory Info Functions / Calling Memory Information Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following example shows how to find out how much memory of a
particular type is available.


```c
    ULONG size;

    size = AvailMem(MEMF_CHIP|MEMF_LARGEST);
```
[AvailMem()](autodocs-2.0/exec-library-availmem.md) returns the size of the largest chunk of available chip memory.


```c
    [AvailMem()](autodocs-2.0/exec-library-availmem.md) May Not Be Totally Accurate.
    ---------------------------------------
    Because of multitasking, the return value from AvailMem() may be
    inaccurate by the time you receive it.
```
The following example shows how to determine the type of memory of a
specified memory address.


```c
    ULONG memtype;

    memtype = TypeOfMem((APTR)0x090000);
    if ((memtype & MEMF_CHIP) == MEMF_CHIP) {/* ...It's chip memory... */}
```
[TypeOfMem()](autodocs-2.0/exec-library-typeofmem.md) returns the attributes of the memory at a specific address. If
it is passed an invalid memory address, TypeOfMem() returns NULL. This
routine is normally used to determine if a particular chunk of memory is
in chip memory.

---

## See Also

- [AvailMem — exec.library](../autodocs/exec.library.md#availmem)
- [TypeOfMem — exec.library](../autodocs/exec.library.md#typeofmem)
