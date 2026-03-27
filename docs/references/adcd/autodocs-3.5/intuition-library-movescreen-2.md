---
title: intuition.library/MoveScreen
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-movescreen-2
functions: [RethinkDisplay, ScreenPosition]
libraries: [intuition.library]
---

# intuition.library/MoveScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	MoveScreen -- Attempt to move the screen by the increments provided.

    SYNOPSIS
	MoveScreen( [Screen](autodocs-3.5/include-intuition-screens-h.md), DeltaX, DeltaY )
		    A0      D0      D1

	VOID MoveScreen( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, WORD, WORD );

    FUNCTION
	Moves the screen the specified increment, specified in screen
	pixel resolution coordinates.

	New for V36: [Screen](autodocs-3.5/include-intuition-screens-h.md) movement limits have been greatly relaxed,
	to support screen scrolling.  In particular, negative values
	for screen LeftEdge and TopEdge may now be valid.

       If the DeltaX and DeltaY variables you specify would move the screen
       in a way that violates any restrictions, the screen will be moved
       as far as possible.  You may examine the LeftEdge and TopEdge fields
	of the [Screen](autodocs-3.5/include-intuition-screens-h.md) structure after this function returns to see where
	the screen really ended up.

    INPUTS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = pointer to a [Screen](autodocs-3.5/include-intuition-screens-h.md) structure
	DeltaX = amount to move the screen on the x-axis
		Note that DeltaX no longer (V36) need be set to zero
	DeltaY = amount to move the screen on the y-axis
		Note that these coordinates are in the same resolution
		as the screen (such as HIRES or INTERLACE)

    RESULT
	None

    BUGS

    SEE ALSO
	[ScreenPosition()](autodocs-3.5/intuition-library-screenposition.md), [RethinkDisplay()](autodocs-3.5/intuition-library-rethinkdisplay-2.md)

---

## See Also

- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
- [ScreenPosition — intuition.library](../autodocs/intuition.library.md#screenposition)
