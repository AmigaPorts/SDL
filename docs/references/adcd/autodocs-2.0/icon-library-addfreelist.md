---
title: icon.library/AddFreeList
manual: autodocs-2.0
chapter: autodocs-2.0
section: icon-library-addfreelist
functions: [FreeEntry, FreeFreeList]
libraries: [exec.library, icon.library]
---

# icon.library/AddFreeList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddFreeList - add memory to a free list.
SYNOPSIS

```c
    status = AddFreeList(free, mem, len)
      D0                  A0    A1   A2

    BOOL AddFreeList(struct [FreeList](autodocs-2.0/includes-workbench-workbench-h.md) *, APTR, ULONG);
```
FUNCTION

```c
    This routine adds the specified memory to the free list.
    The free list will be extended (if required).  If there
    is not enough memory to complete the call, a null is returned.

    Note that AddFreeList does NOT allocate the requested memory.
    It only records the memory in the free list.
```
INPUTS

```c
    free -- a pointer to a [FreeList](autodocs-2.0/includes-workbench-workbench-h.md) structure
    mem -- the base of the memory to be recorded
    len -- the length of the memory to be recorded
```
RESULTS

```c
    status -- TRUE if the call succeeded else FALSE;
```
SEE ALSO

```c
    [AllocEntry()](autodocs-2.0/exec-library-allocentry.md), [FreeEntry()](autodocs-2.0/exec-library-freeentry.md), [FreeFreeList()](autodocs-2.0/icon-library-freefreelist.md)
```
BUGS

    None

---

## See Also

- [FreeEntry — exec.library](../autodocs/exec.library.md#freeentry)
- [FreeFreeList — icon.library](../autodocs/icon.library.md#freefreelist)
