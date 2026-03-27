---
title: graphics.library/AllocBitMap
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-allocbitmap
functions: [BltBitMap, FreeBitMap]
libraries: [graphics.library]
---

# graphics.library/AllocBitMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocBitMap -- [Allocate](autodocs-3.5/exec-library-allocate-2.md) a bitmap and attach bitplanes to it. (V39)


   SYNOPSIS
	bitmap=AllocBitMap(sizex,sizey,depth, flags, friend_bitmap)
	                   d0    d1    d2     d3       a0

	struct [BitMap](autodocs-3.5/include-graphics-gfx-h.md) *AllocBitMap(ULONG,ULONG,ULONG,ULONG, struct [BitMap](autodocs-3.5/include-graphics-gfx-h.md) *);

   FUNCTION
	Allocates and initializes a bitmap structure. Allocates and initializes
	bitplane data, and sets the bitmap's planes to point to it.

   INPUTS
	sizex = the width (in pixels) desired for the bitmap data.

	sizey = the height (in pixels) desired.

	depth = the number of bitplanes deep for the allocation.
		Pixels with AT LEAST this many bits will be allocated.

	flags = BMF_CLEAR to specify that the allocated raster should be
	        filled with color 0.

	        BMF_DISPLAYABLE to specify that this bitmap data should
	        be allocated in such a manner that it can be displayed.
	        Displayable data has more severe alignment restrictions
	        than non-displayable data in some systems.

	        BMF_INTERLEAVED tells graphics that you would like your
	        bitmap to be allocated with one large chunk of display
	        memory for all bitplanes. This minimizes color flashing
	        on deep displays. If there is not enough contiguous RAM
		for an interleaved bitmap, graphics.library will fall
		back to a non-interleaved one.

	        BMF_MINPLANES causes graphics to only allocate enough space
	        in the bitmap structure for "depth" plane pointers. This
		is for system use and should not be used by applications use
		as it is inefficient, and may waste memory.

	friend_bitmap = pointer to another bitmap, or NULL. If this pointer
	        is passed, then the bitmap data will be allocated in
	        the most efficient form for blitting to friend_bitmap.

   BUGS

   NOTES
	When allocating using a friend bitmap, it is not safe to assume
	anything about the structure of the bitmap data if that friend
	[BitMap](autodocs-3.5/include-graphics-gfx-h.md) might not be a standard amiga bitmap (for instance, if
	the workbench is running on a non-amiga display device, its
	Screen->RastPort->BitMap won't be in standard amiga format.
	The only safe operations to perform on a non-standard [BitMap](autodocs-3.5/include-graphics-gfx-h.md) are:

	        - blitting it to another bitmap, which must be either a standard
	          Amiga bitmap, or a friend of this bitmap.

	        - blitting from this bitmap to a friend bitmap or to a standard
	          Amiga bitmap.

	        - attaching it to a rastport and making rendering calls.

	Good arguments to pass for the friend_bitmap are your window's
	RPort->BitMap, and your screen's RastPort->BitMap.
	Do NOT pass &(screenptr->BitMap)!

	BitMaps not allocated with BMF_DISPLAYABLE may not be used as
	Intuition [Custom](autodocs-3.5/include-hardware-custom-h.md) BitMaps or as RasInfo->BitMaps.  They may be blitted
	to a BMF_DISPLAYABLE [BitMap](autodocs-3.5/include-graphics-gfx-h.md), using one of the [BltBitMap()](autodocs-3.5/graphics-library-bltbitmap-2.md) family of
	functions.

   SEE ALSO
	[FreeBitMap()](autodocs-3.5/graphics-library-freebitmap.md)

---

## See Also

- [BltBitMap — graphics.library](../autodocs/graphics.library.md#bltbitmap)
- [FreeBitMap — graphics.library](../autodocs/graphics.library.md#freebitmap)
