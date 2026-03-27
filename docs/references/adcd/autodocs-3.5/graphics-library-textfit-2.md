---
title: graphics.library/TextFit
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-textfit-2
functions: [Text, TextExtent, TextFit, TextLength]
libraries: [graphics.library]
---

# graphics.library/TextFit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TextFit - count characters that will fit in a given extent (V36)

   SYNOPSIS
	chars = TextFit(rastport, string, strLen, textExtent,
	D0              A1        A0      D0      A2
	        constrainingExtent, strDirection,
	        A3                  D1
	        constrainingBitWidth, constrainingBitHeight)
	        D2                    D3

	ULONG TextFit(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [STRPTR](autodocs-3.5/include-exec-types-h.md), [UWORD](autodocs-3.5/include-exec-types-h.md),
	    struct [TextExtent](autodocs-3.5/include-graphics-text-h.md) *, struct [TextExtent](autodocs-3.5/include-graphics-text-h.md) *, WORD, [UWORD](autodocs-3.5/include-exec-types-h.md), UWORD);

   FUNCTION
	This function determines how many of the characters of the
	provided string will fit into the space described by the
	constraining parameters.  It also returns the extent of
	that number of characters.

   INPUTS
	rp     - a pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) which describes where the
	         text attributes reside.
	string - the address of string to determine the constraint of
	strLen - The number of characters in the string.
	         If zero, there are no characters in the string.
	textExtent - a structure to hold the extent result.
	constrainingExtent - the extent that the text must fit in.
	    This can be NULL, indicating only the constrainingBit
	    dimensions will describe the constraint.
	strDirection - the offset to add to the string pointer to
	    get to the next character in the string.  Usually 1.
	    Set to -1 and the string to the end of the string to
	    perform a TextFit() anchored at the end.  No other value
	    is valid.
	constrainingBitWidth - an alternative way to specify the
	    rendering box constraint width that is independent of
	    the rendering origin.  Range 0..32767.
	constrainingBitHeight - an alternative way to specify the
	    rendering box constraint height that is independent of
	    the rendering origin.  Range 0..32767.

   RESULTS
	chars - the number of characters from the origin of the
	        given string that will fit in both the constraining
	        extent (which specifies a CP bound and a rendering
	        box relative to the origin) and in the rendering width
	        and height specified.

   NOTES
	The result is zero chars and an empty textExtent when the fit
	cannot be performed.  This occurs not only when no text will
	fit in the provided constraints, but also when:
	-   the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) rp's rp_TxSpacing sign and magnitude is so
	    great it reverses the path of the text.
	-   the constrainingExtent does not include x = 0.


   BUGS
	Under V37, TextFit() would return one too few characters if the
	font was proportional. This can be worked around by passing
	(constrainingBitWidth + 1) for proportional fonts. This is fixed
	for V39.

   SEE ALSO
	[TextExtent()](autodocs-3.5/graphics-library-textextent-2.md)  [TextLength()](autodocs-3.5/graphics-library-textlength-2.md)  [Text()](autodocs-3.5/graphics-library-text-2.md)
	[graphics/text.h](autodocs-3.5/include-graphics-text-h.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [Text — graphics.library](../autodocs/graphics.library.md#text)
- [TextExtent — graphics.library](../autodocs/graphics.library.md#textextent)
- [TextFit — graphics.library](../autodocs/graphics.library.md#textfit)
- [TextLength — graphics.library](../autodocs/graphics.library.md#textlength)
