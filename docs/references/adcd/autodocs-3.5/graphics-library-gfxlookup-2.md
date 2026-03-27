---
title: graphics.library/GfxLookUP
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-gfxlookup-2
functions: [GfxAssociate, GfxFree, GfxNew]
libraries: [graphics.library]
---

# graphics.library/GfxLookUP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
    	GfxLookUp -- find a graphics extended node associated with a 
		     given pointer (V36)

   SYNOPSIS

```c
       result = GfxLookUp( pointer );
       d0		    a0
```
	struct [ExtendedNode](autodocs-3.5/include-graphics-gfxnodes-h.md) *GfxLookUp( void *);

   FUNCTION
	Finds a special graphics extended data structure (if any) associated
	with the pointer to a data structure (eg: [ViewExtra](autodocs-3.5/include-graphics-view-h.md) associated with
	a [View](autodocs-3.5/include-graphics-view-h.md) structure).

   INPUTS
	pointer = a pointer to a data structure which may have an
		  [ExtendedNode](autodocs-3.5/include-graphics-gfxnodes-h.md) associated with it (typically a [View](autodocs-3.5/include-graphics-view-h.md) ).

   RESULT
	result = a pointer to the [ExtendedNode](autodocs-3.5/include-graphics-gfxnodes-h.md) that has previously been
		 associated with the pointer.

   BUGS

   SEE ALSO
	[graphics/gfxnodes.h](autodocs-3.5/include-graphics-gfxnodes-h.md) [GfxNew()](autodocs-3.5/graphics-library-gfxnew-2.md) [GfxFree()](autodocs-3.5/graphics-library-gfxfree-2.md) [GfxAssociate()](autodocs-3.5/graphics-library-gfxassociate-2.md)

---

## See Also

- [GfxAssociate — graphics.library](../autodocs/graphics.library.md#gfxassociate)
- [GfxFree — graphics.library](../autodocs/graphics.library.md#gfxfree)
- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
