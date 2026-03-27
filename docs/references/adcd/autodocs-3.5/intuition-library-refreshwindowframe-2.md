---
title: intuition.library/RefreshWindowFrame
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-refreshwindowframe-2
functions: []
libraries: []
---

# intuition.library/RefreshWindowFrame

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	RefreshWindowFrame -- Ask Intuition to redraw your window border.

    SYNOPSIS
	RefreshWindowFrame( [Window](autodocs-3.5/include-intuition-intuition-h.md) )
			    A0

	VOID RefreshWindowFrame( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Refreshes the border of a window, including title region and all
	of the window's gadgets.

	You may use this call if you wish to update the display of your borders.
	The expected use of this is to correct unavoidable corruption.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = a pointer to a [Window](autodocs-3.5/include-intuition-intuition-h.md) structure

    RESULT
	None


    BUGS

    SEE ALSO
