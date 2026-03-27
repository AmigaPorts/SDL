---
title: graphics.library/GfxAssociate
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-gfxassociate-2
functions: [GfxFree, GfxLookUp, GfxNew]
libraries: [graphics.library]
---

# graphics.library/GfxAssociate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GfxAssociate -- associate a graphics extended node with a given pointer
	                (V36)

   SYNOPSIS

```c
       GfxAssociate(pointer, node);
                    A0       A1
```
	void GfxAssociate(VOID *, struct [ExtendedNode](autodocs-3.5/include-graphics-gfxnodes-h.md) *);

   FUNCTION
	Associate a special graphics extended data structure (each of which
	begins with an [ExtendedNode](autodocs-3.5/include-graphics-gfxnodes-h.md) structure)  with another structure via
	the other structure's pointer. Later, when you call GfxLookUp()
	with the other structure's pointer you may retrieve a pointer
	to this special graphics extended data structure, if it is
	available.

   INPUTS
	pointer = a pointer to a data structure.
	node = an [ExtendedNode](autodocs-3.5/include-graphics-gfxnodes-h.md) structure to associate with the pointer

   RESULT
	an association is created between the pointer and the node such
	that given the pointer the node can be retrieved via GfxLookUp().

   BUGS

   SEE ALSO
	[graphics/gfxnodes.h](autodocs-3.5/include-graphics-gfxnodes-h.md) [GfxNew()](autodocs-3.5/graphics-library-gfxnew-2.md) [GfxFree()](autodocs-3.5/graphics-library-gfxfree-2.md) GfxLookUp()

---

## See Also

- [GfxFree — graphics.library](../autodocs/graphics.library.md#gfxfree)
- [GfxLookUp — graphics.library](../autodocs/graphics.library.md#gfxlookup)
- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
