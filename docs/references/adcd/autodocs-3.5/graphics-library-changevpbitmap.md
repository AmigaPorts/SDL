---
title: graphics.library/ChangeVPBitMap
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-changevpbitmap
functions: [AllocBitMap, AllocDBufInfo]
libraries: [graphics.library]
---

# graphics.library/ChangeVPBitMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
       ChangeVPBitMap -- change display memory address for multi-buffered
			  animation (V39)

   SYNOPSIS
```c
       ChangeVPBitMap(vp,bm,db)
```
	               a0 a1 a2

	void ChangeVPBitMap(struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *, struct [BitMap](autodocs-3.5/include-graphics-gfx-h.md) *, struct [DBufInfo](autodocs-3.5/include-graphics-view-h.md) *);

   FUNCTION
	Changes the area of display memory which will be displayed in a
	viewport. This can be used to implement double (or triple)
	buffering, a method of achieving smooth animation.

   INPUTS
	vp  =  a pointer to a viewport
```c
       bm  = a pointer to a [BitMap](autodocs-3.5/include-graphics-gfx-h.md) structure. This [BitMap](autodocs-3.5/include-graphics-gfx-h.md) structure must be
```
	      of the same layout as the one attached to the viewport (same
	      depth, alignment, and BytesPerRow).
	db  =  A pointer to a [DBufInfo](autodocs-3.5/include-graphics-view-h.md).

   BUGS

   NOTES
	This will set the vp->RasInfo->BitMap field to the bm pointer which is
	passed.

	When using the synchronization features, you MUST carefully insure that
	all messages have been replied to before calling [FreeDBufInfo](autodocs-3.5/graphics-library-freedbufinfo.md) or
	calling ChangeVPBitMap with the same [DBufInfo](autodocs-3.5/include-graphics-view-h.md).


   SEE ALSO
	[AllocDBufInfo()](autodocs-3.5/graphics-library-allocdbufinfo.md) [AllocBitMap()](autodocs-3.5/graphics-library-allocbitmap.md)

---

## See Also

- [AllocBitMap — graphics.library](../autodocs/graphics.library.md#allocbitmap)
- [AllocDBufInfo — graphics.library](../autodocs/graphics.library.md#allocdbufinfo)
