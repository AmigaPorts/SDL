---
title: graphics.library/EraseRect
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-eraserect-2
functions: []
libraries: []
---

# graphics.library/EraseRect

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       EraseRect -- Fill a defined rectangular area using the current
		     	BackFill hook. (V36)

   SYNOPSIS
	EraseRect( rp, xmin, ymin, xmax, ymax)

                  a1  d0:16 d1:16 d2:16 d3:16
	void EraseRect(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [SHORT](autodocs-3.5/include-exec-types-h.md), [SHORT](autodocs-3.5/include-exec-types-h.md), [SHORT](autodocs-3.5/include-exec-types-h.md), SHORT);

   FUNCTION
	Fill the rectangular region specified by the parameters with the
	BackFill hook. If non-layered, the rectangular region specified by
	the parameters is cleared. If layered the Layer->BackFill [Hook](autodocs-3.5/include-utility-hooks-h.md) is used.

   INPUTS
	rp	- pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
	xmin	- x coordinate of the upper left corner of the region to fill.
	ymin	- y coordinate of the upper left corner of the region to fill.
	xmax	- x coordinate of the lower right corner of the region to fill.
	ymax	- y coordinate of the lower right corner of the region to fill.

   BUGS

   NOTES
	The following relation MUST be true:
	(xmax >= xmin) and (ymax >= ymin)

   SEE ALSO
	[graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md) [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)

