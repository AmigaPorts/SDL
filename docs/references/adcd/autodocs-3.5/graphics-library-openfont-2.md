---
title: graphics.library/OpenFont
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-openfont-2
functions: [CloseFont, OpenDiskFont, OpenFont, SetFont]
libraries: [diskfont.library, graphics.library]
---

# graphics.library/OpenFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	OpenFont -- Get a pointer to a system font.

   SYNOPSIS
	font = OpenFont(textAttr)
	D0              A0

	struct [TextFont](autodocs-3.5/include-graphics-text-h.md) *OpenFont(struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *);

   FUNCTION
	This function searches the system font space for the graphics
	text font that best matches the attributes specified.  The
	pointer to the font returned can be used in subsequent
	[SetFont](autodocs-3.5/graphics-library-setfont-2.md) and [CloseFont](autodocs-3.5/graphics-library-closefont-2.md) calls.  It is important to match this
	call with a corresponding [CloseFont](autodocs-3.5/graphics-library-closefont-2.md) call for effective
	management of ram fonts.

   INPUTS
	textAttr - a [TextAttr](autodocs-3.5/include-graphics-text-h.md) or [TTextAttr](autodocs-3.5/include-graphics-text-h.md) structure that describes the
	           text font attributes desired.

   RESULT
	font is zero if the desired font cannot be found.  If the named
	font is found, but the size and style specified are not
	available, a font with the nearest attributes is returned.

   BUGS
	Prior to V39 this function would return a [TextFont](autodocs-3.5/include-graphics-text-h.md) pointer
	for any font which matched exactly in Y size, regardless of
	differences in DPI, or DotSize.

	As part of fixing this bug it is REQUIRED that you use pass the
	same [TextAttr](autodocs-3.5/include-graphics-text-h.md) (or TTextAttr) to this function that was used when
	[OpenDiskFont()](autodocs-3.5/diskfont-library-opendiskfont-2.md) was called.

	OpenFont(), and [OpenDiskFont()](autodocs-3.5/diskfont-library-opendiskfont-2.md) use WeighTAMatch() to measure
	how well two fonts match.  WeightTAMatch() was a public function
	in graphics.library V36-V37; it is now a system PRIVATE function
	as of V39.

   SEE ALSO
	[CloseFont()](autodocs-3.5/graphics-library-closefont-2.md)  [SetFont()](autodocs-3.5/graphics-library-setfont-2.md)
	[diskfont.library/OpenDiskFont](autodocs-3.5/diskfont-library-opendiskfont-2.md)  [graphics/text.h](autodocs-3.5/include-graphics-text-h.md)
	[intuition/intuition.h](autodocs-3.5/include-intuition-intuition-h.md)

---

## See Also

- [CloseFont — graphics.library](../autodocs/graphics.library.md#closefont)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
