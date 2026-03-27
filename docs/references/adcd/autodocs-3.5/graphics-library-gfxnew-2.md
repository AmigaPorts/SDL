---
title: graphics.library/GfxNew
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-gfxnew-2
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
 	result = GfxNew( node_type );
	d0		 d0

	struct [ExtendedNode](autodocs-3.5/include-graphics-gfxnodes-h.md) *GfxNew( ULONG);

   FUNCTION
	[Allocate](autodocs-3.5/exec-library-allocate-2.md) a special graphics extended data structure (each of which
	begins with an [ExtendedNode](autodocs-3.5/include-graphics-gfxnodes-h.md) structure).  The type of structure to
	be allocated is specified by the node_type identifier.

   INPUTS
	node_type = which type of graphics extended data structure to allocate.
		    (see gfxnodes.h for identifier definitions.)

   RESULT
	result = a pointer to the allocated graphics node or NULL if the
		 allocation failed.

   BUGS

   SEE ALSO
	[graphics/gfxnodes.h](autodocs-3.5/include-graphics-gfxnodes-h.md) [GfxFree()](autodocs-3.5/graphics-library-gfxfree-2.md) [GfxAssociate()](autodocs-3.5/graphics-library-gfxassociate-2.md) GfxLookUp()

---

## See Also

- [GfxAssociate — graphics.library](../autodocs/graphics.library.md#gfxassociate)
- [GfxFree — graphics.library](../autodocs/graphics.library.md#gfxfree)
- [GfxLookUp — graphics.library](../autodocs/graphics.library.md#gfxlookup)
