---
title: exec.library/AllocVec
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-allocvec
functions: [AllocMem]
libraries: [exec.library]
---

# exec.library/AllocVec

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AllocVec -- allocate memory and keep track of the size  (V36)
```
SYNOPSIS

```c
    memoryBlock = AllocVec(byteSize, attributes)
    D0                     D0        D1

    void *AllocVec(ULONG, ULONG);
```
FUNCTION

```c
    This function works identically to [AllocMem()](autodocs-2.0/exec-library-allocmem.md), but tracks the size
    of the allocation.

    See the [AllocMem()](autodocs-2.0/exec-library-allocmem.md) documentation for details.
```
WARNING

    The result of any memory allocation MUST be checked, and a viable
    error handling path taken.  ANY allocation may fail if memory has
    been filled.
SEE ALSO

```c
    [FreeVec](autodocs-2.0/exec-library-freevec.md), [AllocMem](autodocs-2.0/exec-library-allocmem.md)
```

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
