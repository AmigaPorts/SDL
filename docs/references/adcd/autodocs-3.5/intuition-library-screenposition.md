---
title: intuition.library/ScreenPosition
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-screenposition
functions: [MoveScreen, RethinkDisplay, ScreenPosition]
libraries: [intuition.library]
---

# intuition.library/ScreenPosition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ScreenPosition -- [Move](autodocs-3.5/graphics-library-move-2.md) screens with greater control. (V39)

    SYNOPSIS
	ScreenPosition( [Screen](autodocs-3.5/include-intuition-screens-h.md), flags, x1, y1, x2, y2 )
	                A0      D0     D1  D2  D3  D4

	VOID ScreenPosition( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, ULONG, [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	Moves the screen to the specified position or by the specified
	increment, in screen pixel resolution coordinates.

	If the x1 and y1 variables you specify would move the screen in
	a way that violates any restrictions, the screen will be moved
	as far as possible.  You may examine the LeftEdge and TopEdge
	fields of the [Screen](autodocs-3.5/include-intuition-screens-h.md) structure after this function returns to
	see where the screen really ended up.

	Note that negative values for screen LeftEdge and TopEdge are
	valid for screens bigger than their display clip.

    INPUTS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = pointer to a [Screen](autodocs-3.5/include-intuition-screens-h.md) structure
	flags = Set to one of SPOS_RELATIVE, SPOS_ABSOLUTE, or
		SPOS_MAKEVISIBLE.   You may additionally set SPOS_FORCEDRAG
		if you need.  Use SPOS_RELATIVE (zero) for normal use
		(move screen a relative amount expressed by x1,y1).  Set
		the SPOS_ABSOLUTE flag if you wish x1 and y1 to be absolute
		coordinates to move the screen to.  Set SPOS_MAKEVISIBLE to
		position an oversized scrolling screen so that the rectangle
		described by (x1,y1)-(x2,y2) is on the visible part of
		the display. (A word-processor may wish to support
		autoscrolling as the user types.  In that case, it could
		call ScreenPosition() with the SPOS_MAKEVISIBLE flag and
		a rectangle that encompasses the cursor with some space
		around it.

		In addition to any one of the above choices, you can
		additionally set SPOS_FORCEDRAG if you wish to reposition
		a screen that was opened with the {SA_Draggable,FALSE}
		attribute.

	x1,y1 = Absolute position or change in position you wish to apply
		to the screen, when using SPOS_ABSOLUTE or SPOS_RELATIVE.
		When using SPOS_MAKEVISIBLE, these variables describe
		the upper-left corner of the rectangle you would like to
		ensure is on the visible part of a scrolling screen.
	x2,y2 = Ignored when using SPOS_ABSOLUTE or SPOS_RELATIVE.
		When using SPOS_MAKEVISIBLE, these variables describe
		the lower-right corner of the rectangle you would like to
		ensure is on the visible part of a scrolling screen.

		Note that these coordinates are in the same resolution
		as the screen (such as HIRES or INTERLACE)

    RESULT
	None

    NOTES
	ONLY the owner of the screen should use SPOS_FORCEDRAG.
	It is incorrect style (and against the intentions of the
	screen opener) for programs such as commodities or
	mouse-helpers to move non-draggable screens.


    BUGS

    SEE ALSO
	[MoveScreen()](autodocs-3.5/intuition-library-movescreen-2.md), [RethinkDisplay()](autodocs-3.5/intuition-library-rethinkdisplay-2.md)

---

## See Also

- [MoveScreen — intuition.library](../autodocs/intuition.library.md#movescreen)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
- [ScreenPosition — intuition.library](../autodocs/intuition.library.md#screenposition)
