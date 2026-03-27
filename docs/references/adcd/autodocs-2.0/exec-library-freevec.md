---
title: exec.library/FreeVec
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-freevec
functions: [AllocVec]
libraries: [exec.library]
---

# exec.library/FreeVec

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeVec -- return [AllocVec()](autodocs-2.0/exec-library-allocvec.md) memory to the system  (V36)
```
SYNOPSIS

```c
    FreeVec(memoryBlock)
            A1

    void FreeVec(void *);
```
FUNCTION

```c
    Free an allocation made by the [AllocVec()](autodocs-2.0/exec-library-allocvec.md) call.  The memory will
    be returned to the system pool from which it came.
```
NOTE

```c
    If a block of memory is freed twice, the system will Guru. The
    Alert is AN_FreeTwice ($01000009).   If you pass the wrong pointer,
    you will probably see AN_MemCorrupt $01000005.  Future versions may
    add more sanity checks to the memory lists.
```
INPUTS

    memoryBlock - pointer to the memory block to free, or NULL.
SEE ALSO

```c
    [AllocVec](autodocs-2.0/exec-library-allocvec.md)
```

---

## See Also

- [AllocVec — exec.library](../autodocs/exec.library.md#allocvec)
