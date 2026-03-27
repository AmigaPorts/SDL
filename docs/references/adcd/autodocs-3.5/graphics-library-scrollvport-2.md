---
title: graphics.library/ScrollVPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-scrollvport-2
functions: [LoadView, MakeVPort, MrgCop]
libraries: [graphics.library]
---

# graphics.library/ScrollVPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ScrollVPort -- Reinterpret RasInfo information in [ViewPort](autodocs-3.5/include-graphics-view-h.md) to reflect
			the current Offset values.

   SYNOPSIS
	ScrollVPort( vp )
		     a0

	void ScrollVPort(struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *vp);

   FUNCTION
	After the programmer has adjusted the Offset values in
	the RasInfo structures of [ViewPort](autodocs-3.5/include-graphics-view-h.md), change the
	the copper lists to reflect the the Scroll positions.
	Changing the [BitMap](autodocs-3.5/include-graphics-gfx-h.md) ptr in RasInfo and not changing the
	the Offsets will effect a double buffering affect.

   INPUTS
```c
       vp - pointer to a [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure
```
	     that is currently be displayed.
   RESULTS
	modifies hardware and intermediate copperlists to reflect
	new RasInfo

   BUGS
```c
       pokes not fast enough to avoid some visible hashing of display (V37)
```
	This function was re-written in V39 and is ~10 times faster than
	before.

   SEE ALSO
	[MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md) [MrgCop()](autodocs-3.5/graphics-library-mrgcop-2.md) [LoadView()](autodocs-3.5/graphics-library-loadview-2.md)  [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)

---

## See Also

- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
