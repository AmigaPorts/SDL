---
title: graphics.library/GfxFree
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-gfxfree-2
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
```
	void GfxFree(struct [ExtendedNode](autodocs-3.5/include-graphics-gfxnodes-h.md) *);

   FUNCTION
	Free a special graphics extended data structure (each of which
	begins with an [ExtendedNode](autodocs-3.5/include-graphics-gfxnodes-h.md) structure).

   INPUTS
	node = pointer to a graphics extended data structure obtained via
	       [GfxNew()](autodocs-3.5/graphics-library-gfxnew-2.md).

   RESULT
	the node is deallocated from memory. graphics will disassociate
	this special graphics extended node from any associated data
	structures, if necessary, before freeing it (see [GfxAssociate()](autodocs-3.5/graphics-library-gfxassociate-2.md)).

   BUGS
	an [Alert()](autodocs-3.5/exec-library-alert-2.md) will be called if you attempt to free any structure
	other than a graphics extended data structure obtained via GfxFree().

   SEE ALSO
	[graphics/gfxnodes.h](autodocs-3.5/include-graphics-gfxnodes-h.md) [GfxNew()](autodocs-3.5/graphics-library-gfxnew-2.md) [GfxAssociate()](autodocs-3.5/graphics-library-gfxassociate-2.md) GfxLookUp()

---

## See Also

- [Alert — exec.library](../autodocs/exec.library.md#alert)
- [GfxAssociate — graphics.library](../autodocs/graphics.library.md#gfxassociate)
- [GfxFree — graphics.library](../autodocs/graphics.library.md#gfxfree)
- [GfxLookUp — graphics.library](../autodocs/graphics.library.md#gfxlookup)
- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
