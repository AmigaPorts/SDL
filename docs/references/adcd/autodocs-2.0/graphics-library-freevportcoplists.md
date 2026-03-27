---
title: graphics.library/FreeVPortCopLists
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-freevportcoplists
functions: [FreeMem]
libraries: [exec.library]
---

# graphics.library/FreeVPortCopLists

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeVPortCopLists -- deallocate all intermediate copper lists and
                         their headers from a viewport
SYNOPSIS

```c
    FreeVPortCopLists(vp)
                     a0

    void FreeVPortCopLists(struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) *);
```
FUNCTION

```c
    Search display, color, sprite, and user copper
    lists and call [FreeMem()](autodocs-2.0/exec-library-freemem.md) to deallocate them from memory
```
INPUTS

```c
    vp - pointer to [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure
```
RESULTS

    The memory allocated to the various copper lists will be returned
    to the system's free memory pool, and the following fields in
    the viewport structure will be set to NULL:

            DspIns, Sprins, ClrIns, UCopIns
BUGS

    none known
SEE ALSO

```c
    [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md)
```

---

## See Also

- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
