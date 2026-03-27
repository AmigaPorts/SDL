---
title: graphics.library/GfxFree
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-gfxfree
functions: [Alert, GfxAssociate, GfxFree, GfxLookUp, GfxNew]
libraries: [exec.library, graphics.library]
---

# graphics.library/GfxFree

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GfxFree -- free a graphics extended data structure (V36)
```
SYNOPSIS

```c
    GfxFree( node );
          a0

    void GfxFree(struct [ExtendedNode](autodocs-2.0/includes-graphics-gfxnodes-h.md) *);
```
FUNCTION

```c
    Free a special graphics extended data structure (each of which
    begins with an [ExtendedNode](autodocs-2.0/includes-graphics-gfxnodes-h.md) structure).
```
INPUTS

```c
    node = pointer to a graphics extended data structure obtained via
           [GfxNew()](autodocs-2.0/graphics-library-gfxnew.md).
```
RESULT

```c
    the node is deallocated from memory. graphics will dissassociate
    this special graphics extended node from any associated data
    structures, if necessary, before freeing it (see [GfxAssociate()](autodocs-2.0/graphics-library-gfxassociate.md)).
```
BUGS

```c
    an [Alert()](autodocs-2.0/exec-library-alert.md) will be called if you attempt to free any structure
    other than a graphics extended data strucure obtained via GfxFree().
```
SEE ALSO

```c
    [graphics/gfxnodes.h](autodocs-2.0/includes-graphics-gfxnodes-h.md) [GfxNew()](autodocs-2.0/graphics-library-gfxnew.md) [GfxAssociate()](autodocs-2.0/graphics-library-gfxassociate.md) GfxLookUp()
```

---

## See Also

- [Alert — exec.library](../autodocs/exec.library.md#alert)
- [GfxAssociate — graphics.library](../autodocs/graphics.library.md#gfxassociate)
- [GfxFree — graphics.library](../autodocs/graphics.library.md#gfxfree)
- [GfxLookUp — graphics.library](../autodocs/graphics.library.md#gfxlookup)
- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
