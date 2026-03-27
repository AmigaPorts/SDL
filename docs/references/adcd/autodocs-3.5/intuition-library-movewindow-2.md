---
title: intuition.library/MoveWindow
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-movewindow-2
functions: [ChangeWindowBox, SizeWindow, WindowToBack, WindowToFront]
libraries: [intuition.library]
---

# intuition.library/MoveWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	MoveWindow -- Ask Intuition to move a window.

    SYNOPSIS
	MoveWindow( [Window](autodocs-3.5/include-intuition-intuition-h.md), DeltaX, DeltaY )
		    A0      D0      D1

	VOID MoveWindow( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, WORD, WORD );

    FUNCTION
	This routine sends a request to Intuition asking to move the window
	the specified distance.  The delta arguments describe how far to
	move the window along the respective axes.

	Note that the window will not be moved immediately, but rather
	will be moved the next time Intuition receives an input event,
	which happens currently at a minimum rate of ten times per second,
	and a maximum of sixty times a second.

	Interactions with other arbitration of Intuition data structures
	may defer this operation longer.  For V36, you can use the new
	IDCMP class IDCMP_CHANGEWINDOW to detect when this operation has
	completed.

	New for V36: Intuition now will do validity checking on the final
	position.  To send absolute movements, or to move and size a
	window in one step, use [ChangeWindowBox()](autodocs-3.5/intuition-library-changewindowbox-2.md).

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the structure of the [Window](autodocs-3.5/include-intuition-intuition-h.md) to be moved
	DeltaX = how far to move the [Window](autodocs-3.5/include-intuition-intuition-h.md) on the x-axis
	DeltaY = how far to move the [Window](autodocs-3.5/include-intuition-intuition-h.md) on the y-axis

    RESULT
	None

    BUGS

    SEE ALSO
	[ChangeWindowBox()](autodocs-3.5/intuition-library-changewindowbox-2.md), [SizeWindow()](autodocs-3.5/intuition-library-sizewindow-2.md), [WindowToFront()](autodocs-3.5/intuition-library-windowtofront-2.md), [WindowToBack()](autodocs-3.5/intuition-library-windowtoback-2.md)

---

## See Also

- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [WindowToBack — intuition.library](../autodocs/intuition.library.md#windowtoback)
- [WindowToFront — intuition.library](../autodocs/intuition.library.md#windowtofront)
