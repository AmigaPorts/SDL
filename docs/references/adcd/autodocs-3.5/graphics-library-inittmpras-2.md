---
title: graphics.library/InitTmpRas
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-inittmpras-2
functions: [AreaEnd, Flood, Text]
libraries: [graphics.library]
---

# graphics.library/InitTmpRas

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InitTmpRas -- Initialize area of local memory for usage by
			areafill, floodfill, text.

   SYNOPSIS
   	InitTmpRas(tmpras, buffer, size)

              	    a0	     a1     d0
	void InitTmpRas( struct [TmpRas](autodocs-3.5/include-graphics-rastport-h.md) *, void *, ULONG );

   FUNCTION
	The area of memory pointed to by buffer is set up to be used
	by [RastPort](autodocs-3.5/include-graphics-rastport-h.md) routines that may need to get some memory for
	intermediate operations in preparation to putting the graphics
	into the final [BitMap](autodocs-3.5/include-graphics-gfx-h.md).
	Tmpras is used to control the usage of buffer.

   INPUTS
	tmpras - pointer to a [TmpRas](autodocs-3.5/include-graphics-rastport-h.md) structure to be linked into
		a [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	buffer - pointer to a contiguous piece of chip memory.
	size - size in bytes of buffer

   RESULT
	makes buffer available for users of [RastPort](autodocs-3.5/include-graphics-rastport-h.md)

   BUGS
	Would be nice if RastPorts could share one [TmpRas](autodocs-3.5/include-graphics-rastport-h.md).

   SEE ALSO
	[AreaEnd()](autodocs-3.5/graphics-library-areaend-2.md) [Flood()](autodocs-3.5/graphics-library-flood-2.md) [Text()](autodocs-3.5/graphics-library-text-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [Flood — graphics.library](../autodocs/graphics.library.md#flood)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
