---
title: intuition.library/WindowToBack
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-windowtoback-2
functions: [MoveWindow, MoveWindowInFrontOf, SizeWindow, WindowToFront]
libraries: [intuition.library]
---

# intuition.library/WindowToBack

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	WindowToBack -- Ask Intuition to send a window behind others.

    SYNOPSIS
	WindowToBack( [Window](autodocs-3.5/include-intuition-intuition-h.md) )
		      A0

	VOID WindowToBack( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	This routine sends a request to Intuition asking to send the window
	in back of all other windows in the screen.

	Note that the window will not be depth-arranged immediately, but rather
	will be arranged the next time Intuition receives an input event,
	which happens currently at a minimum rate of ten times per second,
	and a maximum of sixty times a second.

	[Remember](autodocs-3.5/include-intuition-intuition-h.md) that WFLG_BACKDROP windows cannot be depth-arranged.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the structure of the window to be sent to the back

    RESULT
	None

    BUGS

    SEE ALSO
	[MoveWindow()](autodocs-3.5/intuition-library-movewindow-2.md), [SizeWindow()](autodocs-3.5/intuition-library-sizewindow-2.md), [WindowToFront()](autodocs-3.5/intuition-library-windowtofront-2.md), [MoveWindowInFrontOf()](autodocs-3.5/intuition-library-movewindowinfrontof-2.md)

---

## See Also

- [MoveWindow — intuition.library](../autodocs/intuition.library.md#movewindow)
- [MoveWindowInFrontOf — intuition.library](../autodocs/intuition.library.md#movewindowinfrontof)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [WindowToFront — intuition.library](../autodocs/intuition.library.md#windowtofront)
