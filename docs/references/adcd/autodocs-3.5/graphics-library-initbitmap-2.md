---
title: graphics.library/InitBitMap
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-initbitmap-2
functions: []
libraries: []
---

# graphics.library/InitBitMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME   

   	InitBitMap -- Initialize bit map structure with input values.

   SYNOPSIS
	InitBitMap( bm, depth, width, height )
		    a0   d0     d1      d2

	void InitBitMap( struct [BitMap](autodocs-3.5/include-graphics-gfx-h.md) *, [BYTE](autodocs-3.5/include-exec-types-h.md), [UWORD](autodocs-3.5/include-exec-types-h.md), [UWORD](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION
	Initialize various elements in the [BitMap](autodocs-3.5/include-graphics-gfx-h.md) structure to
	correctly reflect depth, width, and height.
	Must be used before use of [BitMap](autodocs-3.5/include-graphics-gfx-h.md) in other graphics calls.
	The Planes[8] are not initialized and need to be set up
	by the caller.  The Planes table was put at the end of the
	structure so that it may be truncated to conserve space,
	as well as extended. All routines that use [BitMap](autodocs-3.5/include-graphics-gfx-h.md) should
	only depend on existence of depth number of bitplanes.
	The Flagsh and pad fields are reserved for future use and
	should not be used by application programs.

   INPUTS
	bm - pointer to a [BitMap](autodocs-3.5/include-graphics-gfx-h.md) structure (gfx.h)
	depth - number of bitplanes that this bitmap will have
	width - number of bits (columns) wide for this [BitMap](autodocs-3.5/include-graphics-gfx-h.md)
	height- number of bits (rows) tall for this [BitMap](autodocs-3.5/include-graphics-gfx-h.md)

   BUGS

   SEE ALSO
	[graphics/gfx.h](autodocs-3.5/include-graphics-gfx-h.md)

