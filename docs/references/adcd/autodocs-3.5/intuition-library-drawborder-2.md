---
title: intuition.library/DrawBorder
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-drawborder-2
functions: []
libraries: []
---

# intuition.library/DrawBorder

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DrawBorder -- [Draw](autodocs-3.5/graphics-library-draw-2.md) the specified [Border](autodocs-3.5/include-intuition-intuition-h.md) structure into a [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

    SYNOPSIS
	DrawBorder( [RastPort](autodocs-3.5/include-graphics-rastport-h.md), [Border](autodocs-3.5/include-intuition-intuition-h.md), LeftOffset, TopOffset )
		    A0        A1      D0          D1

	VOID DrawBorder( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, struct [Border](autodocs-3.5/include-intuition-intuition-h.md) *, WORD, WORD );

    FUNCTION
	First, sets up the draw mode and pens in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) according to the
	arguments of the [Border](autodocs-3.5/include-intuition-intuition-h.md) structure.  Then, draws the vectors of
	the border argument into the [RastPort](autodocs-3.5/include-graphics-rastport-h.md), offset by the left and top
	offsets.

	As with all graphics rendering routines, the border will be clipped to
	to the boundaries of the RastPort's layer, if it exists.  This is
	the case with window RastPorts.

	This routine will draw all borders in the NULL-terminated list linked
	by the NextBorder field of the border argument.

    INPUTS
	[RastPort](autodocs-3.5/include-graphics-rastport-h.md) = pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to receive the border rendering
	[Border](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a [Border](autodocs-3.5/include-intuition-intuition-h.md) structure
	LeftOffset = the offset to be added to each vector's x coordinate
	TopOffset = the offset to be added to each vector's y coordinate

    RESULT
	None


    BUGS

    SEE ALSO
