---
title: graphics.library/CopySBitMap
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-copysbitmap-2
functions: [LockLayerRom, SyncSBitMap]
libraries: [graphics.library]
---

# graphics.library/CopySBitMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
```c
       CopySBitMap --	Syncronize [Layer](autodocs-3.5/include-graphics-clip-h.md) window with contents of
```
						Super [BitMap](autodocs-3.5/include-graphics-gfx-h.md)

   SYNOPSIS

```c
       CopySBitMap( layer )
                     a0
```
	void CopySBitMap(struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *);

   FUNCTION
	This is the inverse of [SyncSBitMap](autodocs-3.5/graphics-library-syncsbitmap-2.md).
```c
       Copy all bits from SuperBitMap to [Layer](autodocs-3.5/include-graphics-clip-h.md) bounds.
```
	This is used for those functions that do not
	want to deal with the [ClipRect](autodocs-3.5/include-graphics-clip-h.md) structures but do want
	to be able to work with a SuperBitMap [Layer](autodocs-3.5/include-graphics-clip-h.md).

   INPUTS
	layer - pointer to a SuperBitMap [Layer](autodocs-3.5/include-graphics-clip-h.md)
	    The [Layer](autodocs-3.5/include-graphics-clip-h.md) must already be locked by the caller.

   BUGS

   SEE ALSO
	[LockLayerRom()](autodocs-3.5/graphics-library-locklayerrom-2.md) [SyncSBitMap()](autodocs-3.5/graphics-library-syncsbitmap-2.md)

---

## See Also

- [LockLayerRom — graphics.library](../autodocs/graphics.library.md#locklayerrom)
- [SyncSBitMap — graphics.library](../autodocs/graphics.library.md#syncsbitmap)
