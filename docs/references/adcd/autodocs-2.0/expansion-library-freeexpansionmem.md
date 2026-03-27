---
title: expansion.library/FreeExpansionMem
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-freeexpansionmem
functions: [Alert]
libraries: [exec.library]
---

# expansion.library/FreeExpansionMem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeExpansionMem - allocate standard device expansion memory
SYNOPSIS

```c
    FreeExpansionMem( startSlot, numSlots )
                      D0         D1
```
FUNCTION

```c
    (Not typically called by user code)

    This function allocates numslots of expansion space (each slot
    is E_SLOTSIZE bytes).  It is the inverse function of
    [AllocExpansionMem()](autodocs-2.0/expansion-library-allocexpansionmem.md).
```
INPUTS

    startSlot - the slot number that was allocated, or -1 for error.
    numSlots - the number of slots to be freed.
RESULTS

EXAMPLES

EXCEPTIONS

```c
    If the caller tries to free a slot that is already in the
    free list, FreeExpansionMem will [Alert()](autodocs-2.0/exec-library-alert.md) (e.g. crash the
    system).
```
SEE ALSO

```c
    [AllocExpansionMem](autodocs-2.0/expansion-library-allocexpansionmem.md)
```
BUGS

---

## See Also

- [Alert — exec.library](../autodocs/exec.library.md#alert)
