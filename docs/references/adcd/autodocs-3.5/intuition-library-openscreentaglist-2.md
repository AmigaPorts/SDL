---
title: intuition.library/OpenScreenTagList
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-openscreentaglist-2
functions: [OpenScreen, OpenScreenTagList]
libraries: [intuition.library]
---

# intuition.library/OpenScreenTagList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME	
	OpenScreenTagList -- [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md) with [TagItem](autodocs-3.5/include-utility-tagitem-h.md) extension array. (V36)
	OpenScreenTags -- Varargs stub for OpenScreenTagList. (V36)

   SYNOPSIS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = OpenScreenTagList( [NewScreen](autodocs-3.5/include-intuition-screens-h.md), TagItems )
	D0	  		    A0         A1

	struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *OpenScreenTagList( struct [NewScreen](autodocs-3.5/include-intuition-screens-h.md) *,
		struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * );

	[Screen](autodocs-3.5/include-intuition-screens-h.md) = OpenScreenTags( [NewScreen](autodocs-3.5/include-intuition-screens-h.md), Tag1, ... )

	struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *OpenScreenTags( struct [NewScreen](autodocs-3.5/include-intuition-screens-h.md) *,
		ULONG, ... );

   FUNCTION
	Provides an extension to the parameters passed to [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md).
	This extensions is in the form of (a pointer to) an array of
	[TagItem](autodocs-3.5/include-utility-tagitem-h.md) structures, which have to fields: ti_Tag, an ID identifying
	the meaning of the other field, ti_Data.  See [<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md).

	The tag items can supplement or override the values in [NewScreen](autodocs-3.5/include-intuition-screens-h.md).
	In fact, you can pass a NULL value of the [NewScreen](autodocs-3.5/include-intuition-screens-h.md) pointer.
	For that matter, if you pass NULL in both arguments, you'll get
	a screen with defaults in all fields, including display mode,
	depth, colors, dimension, title, and so on.  We ask that
	you at least supply a title when you open a screen.

	See [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md) documentation for parameter specifications.

   INPUTS
 	[NewScreen](autodocs-3.5/include-intuition-screens-h.md)     - (optional) pointer to a [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure.
 	TagItems      - (optional) pointer to (an array of) [TagItem](autodocs-3.5/include-utility-tagitem-h.md)
			structures, terminated by the value TAG_END.

   RESULT
 	[Screen](autodocs-3.5/include-intuition-screens-h.md)	- an open Intuition screen.  See [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md) for
		extended error codes when [Screen](autodocs-3.5/include-intuition-screens-h.md) is returned NULL.

   EXAMPLE
	The version using a variable number of arguments must be
	created for each particular compiler, and may not have
	an analogue in all versions.  For vanilla, 32-bit C
	parameter passing conventions, this works (and will
	appear in amiga.lib):

	struct [Screen](autodocs-3.5/include-intuition-screens-h.md)	*
	OpenScreenTags( ns, tag1 )
	struct [NewScreen](autodocs-3.5/include-intuition-screens-h.md)	*ns;
	ULONG			tag1;
	{
	    struct [Screen](autodocs-3.5/include-intuition-screens-h.md)	*OpenScreenTagList();

	    return ( OpenScreenTagList( ns, (struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *) &tag1 ) );
	}

   NOTES
	We recommend this extension to [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md) over using the
	field ExtNewScreen.Extension.  However, the ExtNewScreen.Extension
	is a convenient way to supply a few tags to V36 Intuition which
	will be ignored by V34 Intuition.  See [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md) documentation
	for lots of details.

	A VERY IMPORTANT NOTE about the Screen->BitMap.  In the future,
	bitmaps will need to grow.  The embedded instance of a bitmap
	in the screen will no longer be large enough to hold the whole
	description of the bitmap.

	YOU ARE STRONGLY URGED to use Screen->RastPort.BitMap in place of
	&Screen->BitMap whenever and whereever possible.

   BUGS


   SEE ALSO
	[OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md)

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
