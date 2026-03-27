---
title: graphics.library/SetSoftStyle
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setsoftstyle-2
functions: [AskSoftStyle]
libraries: [graphics.library]
---

# graphics.library/SetSoftStyle

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetSoftStyle -- Set the soft style of the current font.

   SYNOPSIS
	newStyle = SetSoftStyle(rp, style, enable)
	D0                      A1  D0     D1

	ULONG SetSoftStyle(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, ULONG, ULONG);

   FUNCTION
	This function alters the soft style of the current font.  Only
	those bits that are also set in enable are affected.  The
	resulting style is returned, since some style request changes
	will not be honored when the implicit style of the font
	precludes changing them.

   INPUTS
	rp     - the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) from which the font and style
	         are extracted.
	style  - the new font style to set, subject to enable.
	enable - those bits in style to be changed.  Any set bits here
	         that would not be set as a result of [AskSoftStyle](autodocs-3.5/graphics-library-asksoftstyle-2.md) will
	         be ignored, and the newStyle result will not be as
	         expected.

   RESULTS
	newStyle - the resulting style, both as a result of previous
	           soft style selection, the effect of this function,
	           and the style inherent in the set font.

   BUGS

   SEE ALSO
	[AskSoftStyle()](autodocs-3.5/graphics-library-asksoftstyle-2.md)  [graphics/text.h](autodocs-3.5/include-graphics-text-h.md)

---

## See Also

- [AskSoftStyle — graphics.library](../autodocs/graphics.library.md#asksoftstyle)
