---
title: graphics.library/SyncSBitMap
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-syncsbitmap-2
functions: [CopySBitMap]
libraries: [graphics.library]
---

# graphics.library/SyncSBitMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
```c
       SyncSBitMap --	Syncronize Super [BitMap](autodocs-3.5/include-graphics-gfx-h.md) with whatever is
```
			in the standard [Layer](autodocs-3.5/include-graphics-clip-h.md) bounds.

   SYNOPSIS

```c
       SyncSBitMap( layer )
                      a0
```
	void SyncSBitMap( struct [Layer](autodocs-3.5/include-graphics-clip-h.md) * );

   FUNCTION
```c
       Copy all bits from ClipRects in [Layer](autodocs-3.5/include-graphics-clip-h.md) into Super [BitMap](autodocs-3.5/include-graphics-gfx-h.md)
```
	[BitMap](autodocs-3.5/include-graphics-gfx-h.md).  This is used for those functions that do not
	want to deal with the [ClipRect](autodocs-3.5/include-graphics-clip-h.md) structures but do want
	to be able to work with a SuperBitMap [Layer](autodocs-3.5/include-graphics-clip-h.md).

   INPUTS
	layer - pointer to a [Layer](autodocs-3.5/include-graphics-clip-h.md) that has a SuperBitMap
		The [Layer](autodocs-3.5/include-graphics-clip-h.md) should already be locked by the caller.

   RESULT
	After calling this function, the programmer can manipulate
	the bits in the superbitmap associated with the layer.
	Afterwards, the programmer should call [CopySBitMap](autodocs-3.5/graphics-library-copysbitmap-2.md) to
	copy the bits back into the onscreen layer.

   BUGS

   SEE ALSO
	[CopySBitMap()](autodocs-3.5/graphics-library-copysbitmap-2.md) [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)

---

## See Also

- [CopySBitMap — graphics.library](../autodocs/graphics.library.md#copysbitmap)
