---
title: graphics.library/GfxNew
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-gfxnew
functions: [GfxAssociate, GfxFree, GfxLookUp]
libraries: [graphics.library]
---

# graphics.library/GfxNew

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GfxNew -- allocate a graphics extended data structure (V36)
```
SYNOPSIS

```c
    result = GfxNew( node_type );
    d0               d0

    struct [ExtendedNode](autodocs-2.0/includes-graphics-gfxnodes-h.md) *GfxNew( ULONG);
```
FUNCTION

```c
    Allocate a special graphics extended data structure (each of which
    begins with an [ExtendedNode](autodocs-2.0/includes-graphics-gfxnodes-h.md) structure).  The type of structure to
    be allocated is specified by the node_type identifier.
```
INPUTS

```c
    node_type = which type of graphics extended data structure to allocate.
                (see gfxnodes.h for identifier definitions.)
```
RESULT

```c
    result = a pointer to the allocated graphics node or NULL if the
             allocation failed.
```
BUGS

SEE ALSO

```c
    [graphics/gfxnodes.h](autodocs-2.0/includes-graphics-gfxnodes-h.md) [GfxFree()](autodocs-2.0/graphics-library-gfxfree.md) [GfxAssociate()](autodocs-2.0/graphics-library-gfxassociate.md) GfxLookUp()
```

---

## See Also

- [GfxAssociate — graphics.library](../autodocs/graphics.library.md#gfxassociate)
- [GfxFree — graphics.library](../autodocs/graphics.library.md#gfxfree)
- [GfxLookUp — graphics.library](../autodocs/graphics.library.md#gfxlookup)
