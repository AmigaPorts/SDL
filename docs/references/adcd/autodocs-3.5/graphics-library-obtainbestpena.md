---
title: graphics.library/ObtainBestPenA
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-obtainbestpena
functions: [GetColorMap, ObtainPen, ReleasePen]
libraries: [graphics.library]
---

# graphics.library/ObtainBestPenA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ObtainBestPenA --- Search for the closest color match, or allocate a
	                   new one. (V39)
	ObtainBestPen  --- varargs stub for ObtainBestPenA

   SYNOPSIS
	color | -1 =ObtainBestPenA(  cm,  R,   G,    B,    taglist)
	                             a0   d1   d2    d3       a1

	[LONG](autodocs-3.5/include-exec-types-h.md) ObtainBestPenA( struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) *, ULONG, ULONG,
			ULONG, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	color = ObtainBestPen(cm,r,g,b,tags....);

   INPUTS
	cm = colormap
	R = red level   (32 bit left justified fraction)
	G = green level (32 bit left justified fraction)
	B = blue level  (32 bit left justified fraction)
	taglist = a pointer to a standard tag list specifying the color
	          matching settings desired:

	        OBP_Precision - specifies the desired precision for the
	                match. Should be PRECISION_GUI, PRECISION_ICON, or
	                PRECISION_IMAGE or PRECISION_EXACT.
	                Defaults to PRECISION_IMAGE.

	        OBP_FailIfBad - specifies that you want ObtainBestPen to return
	                a failure value if there is not a color within the
	                given tolerance, instead of returning the closest color.
	                With OBP_FailIfBad==FALSE, ObtainBestPen will only fail
	                if the [ViewPort](autodocs-3.5/include-graphics-view-h.md) contains no sharable colors.
	                Defaults to FALSE.


   FUNCTION
	This function can be used by applications to figure out
	what pen to use to represent a given color.

	The system will attempt to find the color in your viewport closest
	to the specified color. If there is no color within your tolerance,
	then a new one will be allocated, if available. If none is available,
	then the closest one found will be returned.

   RESULT
	The correct pen value, or -1 if no sharable palette entries are available.


   BUGS

   NOTES
	If this call succceeds, then you must call [ReleasePen()](autodocs-3.5/graphics-library-releasepen.md) when you are
	done with the color.

	The error metric used for ObtainBestPen() is based on the magnitude
	squared between the two RGB values, scaled by the percentage of free
	entries.

   SEE ALSO
	[GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [ObtainPen()](autodocs-3.5/graphics-library-obtainpen.md) [ReleasePen()](autodocs-3.5/graphics-library-releasepen.md)

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [ObtainPen — graphics.library](../autodocs/graphics.library.md#obtainpen)
- [ReleasePen — graphics.library](../autodocs/graphics.library.md#releasepen)
