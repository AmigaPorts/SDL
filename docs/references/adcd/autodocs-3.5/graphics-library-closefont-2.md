---
title: graphics.library/CloseFont
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-closefont-2
functions: [OpenDiskFont, OpenFont]
libraries: [diskfont.library, graphics.library]
---

# graphics.library/CloseFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CloseFont -- Release a pointer to a system font.

   SYNOPSIS
	CloseFont(font)
	          A1

	void CloseFont(struct [TextFont](autodocs-3.5/include-graphics-text-h.md) *);

   FUNCTION
	This function indicates that the font specified is no longer
	in use.  It is used to close a font opened by [OpenFont](autodocs-3.5/graphics-library-openfont-2.md), so
	that fonts that are no longer in use do not consume system
	resources.

   INPUTS
	font -	a font pointer as returned by [OpenFont()](autodocs-3.5/graphics-library-openfont-2.md) or [OpenDiskFont()](autodocs-3.5/diskfont-library-opendiskfont-2.md)

   RESULT

   BUGS

   SEE ALSO
	[OpenFont()](autodocs-3.5/graphics-library-openfont-2.md)  [diskfont.library/OpenDiskFont](autodocs-3.5/diskfont-library-opendiskfont-2.md)  [graphics/text.h](autodocs-3.5/include-graphics-text-h.md)

---

## See Also

- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
