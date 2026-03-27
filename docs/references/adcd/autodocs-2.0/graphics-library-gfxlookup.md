---
title: graphics.library/GfxLookUP
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-gfxlookup
functions: [GfxAssociate, GfxFree, GfxNew]
libraries: [graphics.library]
---

# graphics.library/GfxLookUP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GfxLookUp -- find a graphics extended node associated with a
                 given pointer (V36)
```
SYNOPSIS

```c
    result = GfxLookUp( pointer );
      d0                   a0

    struct [ExtendedNode](autodocs-2.0/includes-graphics-gfxnodes-h.md) *GfxLookUp( void *);
```
FUNCTION

```c
    Finds a special graphics extended data structure (if any) associated
    with the pointer to a data structure (eg: [ViewExtra](autodocs-2.0/includes-graphics-view-h.md) associated with
    a [View](autodocs-2.0/includes-graphics-view-h.md) structure).
```
INPUTS

```c
    pointer = a pointer to a data structure which may have an
              [ExtendedNode](autodocs-2.0/includes-graphics-gfxnodes-h.md) associated with it (typically a [View](autodocs-2.0/includes-graphics-view-h.md) ).
```
RESULT

```c
    result = a pointer to the [ExtendedNode](autodocs-2.0/includes-graphics-gfxnodes-h.md) that has previously been
             associated with the pointer.
```
BUGS

SEE ALSO

```c
    [graphics/gfxnodes.h](autodocs-2.0/includes-graphics-gfxnodes-h.md) [GfxNew()](autodocs-2.0/graphics-library-gfxnew.md) [GfxFree()](autodocs-2.0/graphics-library-gfxfree.md) [GfxAssociate()](autodocs-2.0/graphics-library-gfxassociate.md)
```

---

## See Also

- [GfxAssociate — graphics.library](../autodocs/graphics.library.md#gfxassociate)
- [GfxFree — graphics.library](../autodocs/graphics.library.md#gfxfree)
- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
