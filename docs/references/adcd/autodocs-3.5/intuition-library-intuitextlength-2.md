---
title: intuition.library/IntuiTextLength
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-intuitextlength-2
functions: [OpenScreen]
libraries: [intuition.library]
---

# intuition.library/IntuiTextLength

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	IntuiTextLength -- Return the length (pixel-width) of an [IntuiText](autodocs-3.5/include-intuition-intuition-h.md).

    SYNOPSIS
	Length = IntuiTextLength( IText )
	D0                        A0

	[LONG](autodocs-3.5/include-exec-types-h.md) IntuiTextLength( struct [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	This routine accepts a pointer to an instance of an [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) structure,
	and returns the length (the pixel-width) of the string which that
	instance of the structure represents.

	NOTE: if the Font pointer of your [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) structure is set to NULL,
	you'll get the pixel-width of your text in terms of the current system
	default font.  You may wish to be sure that the field IText->ITextFont
	for 'default font' text is equal to the Font field of the screen it is
	being measured for.

    INPUTS
	IText = pointer to an instance of an [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) structure

    RESULT
	Returns the pixel-width of the text specified by the [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) data

    BUGS
	Would do better to take a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) as argument, so that a NULL in
	the Font pointer would lead automatically to the font for the
	intended target [RastPort](autodocs-3.5/include-graphics-rastport-h.md), rather than the system default font.

    SEE ALSO
	[OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md)

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
