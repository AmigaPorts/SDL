---
title: datatypes.library/DrawDTObjectA
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-drawdtobjecta
functions: []
libraries: []
---

# datatypes.library/DrawDTObjectA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DrawDTObjectA - [Draw](autodocs-3.5/graphics-library-draw-2.md) a DataTypes object.                (V44)

    SYNOPSIS
	retval = DrawDTObjectA (rp, o, x, y, w, h, th, tv, attrs);
	d0			a0  a1 d0 d1 d2 d3 d4  d5  a2

	[LONG](autodocs-3.5/include-exec-types-h.md) DrawDTObjectA (struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *rp, [Object](autodocs-3.5/include-intuition-classusr-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md) x, [LONG](autodocs-3.5/include-exec-types-h.md) y,
			    [LONG](autodocs-3.5/include-exec-types-h.md) w, [LONG](autodocs-3.5/include-exec-types-h.md) h, [LONG](autodocs-3.5/include-exec-types-h.md) th, [LONG](autodocs-3.5/include-exec-types-h.md) tv,
			    struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	retval = DrawDTObject (rp, o, x, y, w, h, th, tv, tag1, ...);

	[LONG](autodocs-3.5/include-exec-types-h.md) DrawDTObjectA (struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *rp, [Object](autodocs-3.5/include-intuition-classusr-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md) x, [LONG](autodocs-3.5/include-exec-types-h.md) y,
			    [LONG](autodocs-3.5/include-exec-types-h.md) w, [LONG](autodocs-3.5/include-exec-types-h.md) h, [LONG](autodocs-3.5/include-exec-types-h.md) th, [LONG](autodocs-3.5/include-exec-types-h.md) tv, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

    FUNCTION
	This function is used to draw a DataTypes object into a [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

	This function can be used for strip printing the object or
	embedding it within a document.

	You must successfully call [ObtainDTDrawInfoA()](autodocs-3.5/datatypes-library-obtaindtdrawinfoa.md) before using
	this function.

	This function invokes the object's DTM_DRAW method.

	Clipping MUST be turned on within the [RastPort](autodocs-3.5/include-graphics-rastport-h.md).  This means
	that there must be a valid layer structure attached to the
	[RastPort](autodocs-3.5/include-graphics-rastport-h.md).

    INPUTS
	rp - Pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to draw into.
	o - Pointer to an object returned by [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).
	x - Left-most point of area to draw into.
	y - Top-most point of area to draw into.
	w - Width of area to draw into.
	h - Height of area to draw into.
	th - Horizontal top in units.
	tv - Vertical top in units.
	attrs - Additional attributes.

    TAGS
	none defined at this time.

    RETURNS
	TRUE to indicate that it was able to render, FALSE on failure.

    SEE ALSO
	ObtainDTDrawInfo(), [ReleaseDTDrawInfo()](autodocs-3.5/datatypes-library-releasedtdrawinfo.md)

