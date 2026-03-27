---
title: diskfont.library/DisposeFontContents
manual: autodocs-3.5
chapter: autodocs-3.5
section: diskfont-library-disposefontcontents-2
functions: [NewFontContents]
libraries: [diskfont.library]
---

# diskfont.library/DisposeFontContents

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DisposeFontContents -- Free the result from [NewFontContents](autodocs-3.5/diskfont-library-newfontcontents-2.md). (V34)

   SYNOPSIS
	DisposeFontContents(fontContentsHeader)
			    A1

	VOID DisposeFontContents( struct [FontContentsHeader](autodocs-3.5/include-diskfont-diskfont-h.md) * );

   FUNCTION
	This function frees the array of [FontContents](autodocs-3.5/include-diskfont-diskfont-h.md) entries
	returned by [NewFontContents](autodocs-3.5/diskfont-library-newfontcontents-2.md).

   INPUTS
	fontContentsHeader - a struct [FontContentsHeader](autodocs-3.5/include-diskfont-diskfont-h.md) pointer
	    returned by [NewFontContents](autodocs-3.5/diskfont-library-newfontcontents-2.md).

   EXCEPTIONS
 	This command was first made available as of version 34.

	A fontContentsHeader other than one acquired by a call
	[NewFontContents](autodocs-3.5/diskfont-library-newfontcontents-2.md) will crash.

   SEE ALSO
	[NewFontContents()](autodocs-3.5/diskfont-library-newfontcontents-2.md) to get structure freed here.

---

## See Also

- [NewFontContents — diskfont.library](../autodocs/diskfont.library.md#newfontcontents)
