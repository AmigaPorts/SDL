---
title: icon.library/FreeFreeList
manual: autodocs-2.0
chapter: autodocs-2.0
section: icon-library-freefreelist
functions: [AddFreeList, FreeEntry]
libraries: [exec.library, icon.library]
---

# icon.library/FreeFreeList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeFreeList - free all memory in a free list.
SYNOPSIS

```c
    FreeFreeList(free)
                 A0

    void FreeFreeList(struct [FreeList](autodocs-2.0/includes-workbench-workbench-h.md) *);
```
FUNCTION

```c
    This routine frees all memory in a free list, and the
    free list itself.  It is useful for easily getting
    rid of all memory in a series of structures.  There is
    a free list in a Workbench object, and this contains
    all the memory associated with that object.

    A [FreeList](autodocs-2.0/includes-workbench-workbench-h.md) is a list of [MemList](autodocs-2.0/includes-exec-memory-h.md) structures.  See the
    [MemList](autodocs-2.0/includes-exec-memory-h.md) and [MemEntry](autodocs-2.0/includes-exec-memory-h.md) documentation for more information.

    If the [FreeList](autodocs-2.0/includes-workbench-workbench-h.md) itself is in the free list, it must be
    in the first [MemList](autodocs-2.0/includes-exec-memory-h.md) in the [FreeList](autodocs-2.0/includes-workbench-workbench-h.md).
```
INPUTS

```c
    free -- a pointer to a [FreeList](autodocs-2.0/includes-workbench-workbench-h.md) structure
```
RESULTS

    None
SEE ALSO

```c
    [AllocEntry()](autodocs-2.0/exec-library-allocentry.md), [FreeEntry()](autodocs-2.0/exec-library-freeentry.md), [AddFreeList()](autodocs-2.0/icon-library-addfreelist.md)
```
BUGS

    None

---

## See Also

- [AddFreeList — icon.library](../autodocs/icon.library.md#addfreelist)
- [FreeEntry — exec.library](../autodocs/exec.library.md#freeentry)
