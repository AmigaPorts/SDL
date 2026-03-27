---
title: diskfont.library/NewFontContents
manual: autodocs-3.5
chapter: autodocs-3.5
section: diskfont-library-newfontcontents-2
functions: [DisposeFontContents]
libraries: [diskfont.library]
---

# diskfont.library/NewFontContents

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	NewFontContents -- Create a [FontContents](autodocs-3.5/include-diskfont-diskfont-h.md) image for a font. (V34)

   SYNOPSIS
	fontContentsHeader = NewFontContents(fontsLock,fontName)

       D0                                   A0        A1
	struct [FontContentsHeader](autodocs-3.5/include-diskfont-diskfont-h.md) *NewFontContents( [BPTR](autodocs-3.5/include-dos-dos-h.md), char * );

   FUNCTION
	This function creates a new array of [FontContents](autodocs-3.5/include-diskfont-diskfont-h.md) entries
	that describe all the fonts associated with the fontName,
	specifically, all those in the font directory whose name
	is that of the font sans the ".font" suffix.

   INPUTS
	fontsLock - a DOS lock on the FONTS: directory (or other
	    directory where the font contents file and associated
	    font directory resides).
	fontName - the font name, with the ".font" suffix, which
	    is also the name of the font contents file.

   RESULT
	fontContentsHeader - a struct [FontContentsHeader](autodocs-3.5/include-diskfont-diskfont-h.md) pointer.

   EXCEPTIONS
	This command was first made available as of version 34.

	D0 is zero if the fontName is does not have a ".font" suffix,
	if the fontName is too long, if a DOS error occurred, or if
	memory could not be allocated for the fontContentsHeader.

   SEE ALSO
	[DisposeFontContents()](autodocs-3.5/diskfont-library-disposefontcontents-2.md) to free the structure acquired here.

---

## See Also

- [DisposeFontContents — diskfont.library](../autodocs/diskfont.library.md#disposefontcontents)
