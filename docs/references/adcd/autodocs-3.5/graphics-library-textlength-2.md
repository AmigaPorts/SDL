---
title: graphics.library/TextLength
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-textlength-2
functions: [Text, TextExtent, TextFit]
libraries: [graphics.library]
---

# graphics.library/TextLength

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TextLength -- Determine raster length of text data.

   SYNOPSIS
	length = TextLength(rp, string, count)
	D0                  A1  A0      D0:16

	WORD TextLength(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [STRPTR](autodocs-3.5/include-exec-types-h.md), WORD);

   FUNCTION
	This graphics function determines the length that text data
	would occupy if output to the specified [RastPort](autodocs-3.5/include-graphics-rastport-h.md) with the
	current attributes.  The length is specified as the number of
	raster dots: to determine what the current position would be
	after a [Text()](autodocs-3.5/graphics-library-text-2.md) using this string, add the length to cp_x
	(cp_y is unchanged by [Text()](autodocs-3.5/graphics-library-text-2.md)).  Use the newer [TextExtent()](autodocs-3.5/graphics-library-textextent-2.md) to
	get more information.

   INPUTS
	rp     - a pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) which describes where the
	         text attributes reside.
	string - the address of string to determine the length of
	count  - the string length.  If zero, there are no characters
	         in the string.

   RESULTS
	length - the number of pixels in x this text would occupy, not
	         including any negative kerning that may take place at
	         the beginning of the text string, nor taking into
	         account the effects of any clipping that may take
	         place.

   NOTES
	Prior to V36, the result length occupied only the low word of
	d0 and was not sign extended into the high word.

   BUGS
	A length that would overflow single word arithmetic is not
	calculated correctly.

   SEE ALSO
	[TextExtent()](autodocs-3.5/graphics-library-textextent-2.md)  [Text()](autodocs-3.5/graphics-library-text-2.md)  [TextFit()](autodocs-3.5/graphics-library-textfit-2.md)
	[graphics/text.h](autodocs-3.5/include-graphics-text-h.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [Text — graphics.library](../autodocs/graphics.library.md#text)
- [TextExtent — graphics.library](../autodocs/graphics.library.md#textextent)
- [TextFit — graphics.library](../autodocs/graphics.library.md#textfit)
