---
title: graphics.library/AskFont
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-askfont-2
functions: []
libraries: []
---

# graphics.library/AskFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AskFont -- get the text attributes of the current font

   SYNOPSIS
	AskFont(rp, textAttr)
	        A1  A0

	void AskFont(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *);

   FUNCTION
	This function fills the text attributes structure with the
	attributes of the current font in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

   INPUTS
	rp       - the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) from which the text attributes are
	           extracted
	textAttr - the [TextAttr](autodocs-3.5/include-graphics-text-h.md) structure to be filled.  Note that
	           there is no support for a [TTextAttr](autodocs-3.5/include-graphics-text-h.md).

   RESULT
	The textAttr structure is filled with the RastPort's text
	attributes.

   BUGS

   SEE ALSO
	[graphics/text.h](autodocs-3.5/include-graphics-text-h.md)

