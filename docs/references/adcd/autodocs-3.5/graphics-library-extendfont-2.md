---
title: graphics.library/ExtendFont
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-extendfont-2
functions: []
libraries: []
---

# graphics.library/ExtendFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ExtendFont -- ensure tf_Extension has been built for a font (V36)

   SYNOPSIS
	success = ExtendFont(font, fontTags)
	D0                   A0    A1

	ULONG ExtendFont(struct [TextFont](autodocs-3.5/include-graphics-text-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	success = ExtendFontTags(font, Tag1, ...)  (V39)

	ULONG ExtendFontTags(struct [TextFont](autodocs-3.5/include-graphics-text-h.md) *, ULONG, ...);

   FUNCTION
	To extend a [TextFont](autodocs-3.5/include-graphics-text-h.md) structure.

   INPUTS
	font - The font to extend.
	fontTags - An optional taglist.  If NULL, then a default is used.
	           Currently, the only tag defined is TA_DeviceDPI.

   RESULT
	success - 1 if the [TextFont](autodocs-3.5/include-graphics-text-h.md) was properly extended, else 0.

   NOTES
	The varargs stub was missing from amiga.lib until V39.

   SEE ALSO
	[graphics/text.h](autodocs-3.5/include-graphics-text-h.md)

