---
title: graphics.library/ReleasePen
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-releasepen
functions: [GetColorMap, ObtainBestPenA, ObtainPen]
libraries: [graphics.library]
---

# graphics.library/ReleasePen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReleasePen -- Release an allocated palette entry to the free pool. (V39)


   SYNOPSIS
	ReleasePen( cm, n)
	            a0 d0

	void ReleasePen( Struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) *, ULONG);

   FUNCTION
	Return the palette entry for use by other applications.
	If the reference count for this palette entry goes to zero,
	then it may be reset to another RGB value.

   INPUTS

```c
       cm  =  A pointer to a color map created by [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md).
```
	n   =  A palette index obtained via any of the palette allocation
	       functions. Passing a -1 will result in this call doing
	       nothing.

   BUGS

   NOTES
	This function works for both shared and exclusive palette entries.

   SEE ALSO
	[GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [ObtainPen()](autodocs-3.5/graphics-library-obtainpen.md) [ObtainBestPenA()](autodocs-3.5/graphics-library-obtainbestpena.md)

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [ObtainBestPenA — graphics.library](../autodocs/graphics.library.md#obtainbestpena)
- [ObtainPen — graphics.library](../autodocs/graphics.library.md#obtainpen)
