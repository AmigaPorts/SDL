---
title: diskfont.library/NewScaledDiskFont
manual: autodocs-3.5
chapter: autodocs-3.5
section: diskfont-library-newscaleddiskfont-2
functions: [StripFont, UnLoadSeg]
libraries: [dos.library, graphics.library]
---

# diskfont.library/NewScaledDiskFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	NewScaledDiskFont -- Create a DiskFont scaled from another. (V36)

   SYNOPSIS
	header = NewScaledDiskFont(srcFont, destTextAttr)
	D0                         A0       A1

	struct [DiskFontHeader](autodocs-3.5/include-diskfont-diskfont-h.md) *NewScaledDiskFont( struct [TextFont](autodocs-3.5/include-graphics-text-h.md) *,
		struct [TTextAttr](autodocs-3.5/include-graphics-text-h.md) * );

   INPUTS
	srcFont - the font from which the scaled font is to be
	    constructed.
	destTextAttr - the desired attributes for the new scaled
	    font.  This may be a structure of type [TextAttr](autodocs-3.5/include-graphics-text-h.md) or
	    [TTextAttr](autodocs-3.5/include-graphics-text-h.md).

   RESULT
	header - a pointer to a [DiskFontHeader](autodocs-3.5/include-diskfont-diskfont-h.md) structure.  This is not
		being managed by the diskfont.library, however.

   NOTES
	o   This function may use the blitter.
	o   Fonts containing characters that render wholly outside
	    the character advance cell are currently not scalable.
	o   The font, and memory allocated for the scaled font can
	    can be freed by calling [StripFont()](autodocs-3.5/graphics-library-stripfont-2.md) on the font,
	    and then calling [UnLoadSeg()](autodocs-3.5/dos-library-unloadseg-2.md) on the segment created
	    by this function.

	    Both the [TextFont](autodocs-3.5/include-graphics-text-h.md) structure, and segment pointer are contained
	    within the [DiskFontHeader](autodocs-3.5/include-diskfont-diskfont-h.md) struct.  The [DiskFontHeader](autodocs-3.5/include-diskfont-diskfont-h.md) structure
	    will also be freed as part of the [UnLoadSeg()](autodocs-3.5/dos-library-unloadseg-2.md) call.
	    [StripFont()](autodocs-3.5/graphics-library-stripfont-2.md) is a new graphics.library call as of V36.

---

## See Also

- [StripFont — graphics.library](../autodocs/graphics.library.md#stripfont)
- [UnLoadSeg — dos.library](../autodocs/dos.library.md#unloadseg)
