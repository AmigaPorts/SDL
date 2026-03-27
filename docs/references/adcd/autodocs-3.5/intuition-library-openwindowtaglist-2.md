---
title: intuition.library/OpenWindowTagList
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-openwindowtaglist-2
functions: [OpenScreenTagList, OpenWindow]
libraries: [intuition.library]
---

# intuition.library/OpenWindowTagList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME	
	OpenWindowTagList -- [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) with [TagItem](autodocs-3.5/include-utility-tagitem-h.md) extension. (V36)
	OpenWindowTags -- Varargs stub for OpenWindowTagList (V36)

   SYNOPSIS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = OpenWindowTagList( [NewWindow](autodocs-3.5/include-intuition-intuition-h.md), TagItems )
	D0	  		    A0         A1

	struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *OpenWindowTagList( struct [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) *,
		struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * );

	[Window](autodocs-3.5/include-intuition-intuition-h.md) = OpenWindowTags( [NewWindow](autodocs-3.5/include-intuition-intuition-h.md), Tag1, ... )

	struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *OpenWindowTags( struct [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG, ... );

   FUNCTION
	A variation of [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) that allow direct specification of
	a [TagItem](autodocs-3.5/include-utility-tagitem-h.md) array of extension data.  Recommended over using the
	ExtNewWindow.Extension field.

	If you omit the [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) (pass NULL), a set of defaults
	are used, and overridden by the tag items.  Even without
	any tag items at all, a reasonable window opens on the Workbench
	or default public screen.

	See [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) for all the details.

   INPUTS
 	[NewWindow](autodocs-3.5/include-intuition-intuition-h.md) - (optional) pointer to a [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) structure.
	TagItems - (optional) pointer to [TagItem](autodocs-3.5/include-utility-tagitem-h.md) array, with tag
		values as described under the description for
		[OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md).

   RESULT
 	[Window](autodocs-3.5/include-intuition-intuition-h.md) - newly created window, per your specifications.

   EXAMPLE
	See [OpenScreenTagList()](autodocs-3.5/intuition-library-openscreentaglist-2.md) for an example of how to create
	a "varargs" version of this function for convenient C
	language programming.

   NOTES


   BUGS


   SEE ALSO
	[OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md)

---

## See Also

- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
