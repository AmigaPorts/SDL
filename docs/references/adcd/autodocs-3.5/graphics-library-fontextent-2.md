---
title: graphics.library/FontExtent
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-fontextent-2
functions: [TextExtent]
libraries: [graphics.library]
---

# graphics.library/FontExtent

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FontExtent -- get the font attributes of the current font (V36)

   SYNOPSIS
	FontExtent(font, fontExtent)
	           A0    A1

	void FontExtent(struct [TextFont](autodocs-3.5/include-graphics-text-h.md) *, struct [TextExtent](autodocs-3.5/include-graphics-text-h.md) *);

   FUNCTION
	This function fills the text extent structure with a bounding
	(i.e. maximum) extent for the characters in the specified font.

   INPUTS
	font       - the [TextFont](autodocs-3.5/include-graphics-text-h.md) from which the font metrics are extracted.
	fontExtent - the [TextExtent](autodocs-3.5/include-graphics-text-h.md) structure to be filled.

   RESULT
	fontExtent is filled.

   NOTES
	The [TextFont](autodocs-3.5/include-graphics-text-h.md), not the [RastPort](autodocs-3.5/include-graphics-rastport-h.md), is specified -- unlike
	[TextExtent()](autodocs-3.5/graphics-library-textextent-2.md), effect of algorithmic enhancements is not
	included, nor does te_Width include any effect of
	rp_TxSpacing.  The returned te_Width will be negative only
	when FPF_REVPATH is set in the tf_Flags of the font -- the
	effect of left-moving characters is ignored for the width of
	a normal font, and the effect of right-moving characters is
	ignored if a REVPATH font.  These characters will, however,
	be reflected in the bounding extent.

   SEE ALSO
	[TextExtent()](autodocs-3.5/graphics-library-textextent-2.md)  [graphics/text.h](autodocs-3.5/include-graphics-text-h.md)

---

## See Also

- [TextExtent — graphics.library](../autodocs/graphics.library.md#textextent)
