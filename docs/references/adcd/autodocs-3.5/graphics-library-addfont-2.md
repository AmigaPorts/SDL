---
title: graphics.library/AddFont
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-addfont-2
functions: [RemFont, SetFont]
libraries: [graphics.library]
---

# graphics.library/AddFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddFont -- add a font to the system list

   SYNOPSIS
	AddFont(textFont)
	        A1

	void AddFont(struct [TextFont](autodocs-3.5/include-graphics-text-h.md) *);

   FUNCTION
	This function adds the text font to the system, making it
	available for use by any application.  The font added must be
	in public memory, and remain until successfully removed.

   INPUTS
	textFont - a [TextFont](autodocs-3.5/include-graphics-text-h.md) structure in public ram.

   RESULT

   NOTES
	This function will set the tf_Accessors to 0.

   BUGS

   SEE ALSO
	[SetFont()](autodocs-3.5/graphics-library-setfont-2.md)  [RemFont()](autodocs-3.5/graphics-library-remfont-2.md)  [graphics/text.h](autodocs-3.5/include-graphics-text-h.md)

---

## See Also

- [RemFont — graphics.library](../autodocs/graphics.library.md#remfont)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
