---
title: graphics.library/GfxAssociate
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-gfxassociate
functions: [GfxFree, GfxLookUp, GfxNew]
libraries: [graphics.library]
---

# graphics.library/GfxAssociate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GfxAssociate -- associate a graphics extended node with a given pointer
                    (V36)
```
SYNOPSIS
   GfxAssociate(pointer, node);

```c
                A0       A1

    void GfxAssociate(VOID *, struct [ExtendedNode](autodocs-2.0/includes-graphics-gfxnodes-h.md) *);
```
FUNCTION

```c
    Associate a special graphics extended data structure (each of which
    begins with an [ExtendedNode](autodocs-2.0/includes-graphics-gfxnodes-h.md) structure)  with another structure via
    the other structure's pointer. Later, when you call GfxLookUp()
    with the other structure's pointer you may retrieve a pointer
    to this special graphics extended data structure, if it is
    available.
```
INPUTS

```c
    pointer = a pointer to a data structure.
    node = an [ExtendedNode](autodocs-2.0/includes-graphics-gfxnodes-h.md) structure to associate with the pointer
```
RESULT

```c
    an association is created between the pointer and the node such
    that given the pointer the node can be retrieved via GfxLookUp().
```
BUGS

SEE ALSO

```c
    [graphics/gfxnodes.h](autodocs-2.0/includes-graphics-gfxnodes-h.md) [GfxNew()](autodocs-2.0/graphics-library-gfxnew.md) [GfxFree()](autodocs-2.0/graphics-library-gfxfree.md) GfxLookUp()
```

---

## See Also

- [GfxFree — graphics.library](../autodocs/graphics.library.md#gfxfree)
- [GfxLookUp — graphics.library](../autodocs/graphics.library.md#gfxlookup)
- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
