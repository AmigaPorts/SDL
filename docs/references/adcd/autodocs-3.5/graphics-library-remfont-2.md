---
title: graphics.library/RemFont
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-remfont-2
functions: [AddFont, SetFont]
libraries: [graphics.library]
---

# graphics.library/RemFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemFont -- [Remove](autodocs-3.5/exec-library-remove-2.md) a font from the system list.

   SYNOPSIS
	RemFont(textFont)
	        A1

	void RemFont(struct [TextFont](autodocs-3.5/include-graphics-text-h.md) *);

   FUNCTION
	This function removes a font from the system, ensuring that
	access to it is restricted to those applications that
	currently have an active pointer to it: i.e. no new [SetFont](autodocs-3.5/graphics-library-setfont-2.md)
	requests to this font are satisfied.

   INPUTS
	textFont - the [TextFont](autodocs-3.5/include-graphics-text-h.md) structure to remove.

   RESULT

   BUGS

   SEE ALSO
	[SetFont()](autodocs-3.5/graphics-library-setfont-2.md)  [AddFont()](autodocs-3.5/graphics-library-addfont-2.md)  [graphics/text.h](autodocs-3.5/include-graphics-text-h.md)

---

## See Also

- [AddFont — graphics.library](../autodocs/graphics.library.md#addfont)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
