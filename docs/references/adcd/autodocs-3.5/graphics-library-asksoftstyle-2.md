---
title: graphics.library/AskSoftStyle
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-asksoftstyle-2
functions: [SetSoftStyle]
libraries: [graphics.library]
---

# graphics.library/AskSoftStyle

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AskSoftStyle -- Get the soft style bits of the current font.

   SYNOPSIS
	enable = AskSoftStyle(rp)
	D0                    A1

	ULONG AskSoftStyle(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *);

   FUNCTION
	This function returns those style bits of the current font
	that are not intrinsic in the font itself, but
	algorithmically generated.  These are the bits that are
	valid to set in the enable mask for [SetSoftStyle()](autodocs-3.5/graphics-library-setsoftstyle-2.md).

   INPUTS
	rp - the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) from which the font and style	are extracted.

   RESULTS
	enable - those bits in the style algorithmically generated.
	         Style bits that are not defined are also set.

   BUGS

   SEE ALSO
	[SetSoftStyle()](autodocs-3.5/graphics-library-setsoftstyle-2.md)  [graphics/text.h](autodocs-3.5/include-graphics-text-h.md)

---

## See Also

- [SetSoftStyle — graphics.library](../autodocs/graphics.library.md#setsoftstyle)
