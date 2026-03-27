---
title: intuition.library/ViewAddress
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-viewaddress-2
functions: [ViewAddress]
libraries: [intuition.library]
---

# intuition.library/ViewAddress

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ViewAddress -- Return the address of the Intuition [View](autodocs-3.5/include-graphics-view-h.md) structure.

    SYNOPSIS
	view = ViewAddress()
	D0

	struct [View](autodocs-3.5/include-graphics-view-h.md) *ViewAddress( VOID );

    FUNCTION
	Returns the address of the Intuition [View](autodocs-3.5/include-graphics-view-h.md) structure.  If you
	want to use any of the graphics, text, or animation primitives
	in your window and that primitive requires a pointer to a view,
	this routine will return the address of the view for you.

    INPUTS
	None

    RESULT
	Returns the address of the Intuition [View](autodocs-3.5/include-graphics-view-h.md) structure

    BUGS

    SEE ALSO
	graphics.library

---

## See Also

- [ViewAddress — intuition.library](../autodocs/intuition.library.md#viewaddress)
