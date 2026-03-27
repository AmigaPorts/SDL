---
title: intuition.library/ZipWindow
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-zipwindow-2
functions: [ChangeWindowBox, MoveWindow, OpenWindow, SizeWindow]
libraries: [intuition.library]
---

# intuition.library/ZipWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ZipWindow -- Change window to "alternate" position and
	             dimensions. (V36)

    SYNOPSIS
	ZipWindow( [Window](autodocs-3.5/include-intuition-intuition-h.md) )
		   A0

	VOID ZipWindow( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Changes the position and dimension of a window to the values
	at the last occasion of ZipWindow being called (or invoked
	via the "zoom" gadget).

	Typically this is used to snap between a normal, large, working
	dimension of the window to a smaller, more innocuous position
	and dimension.

	Like [MoveWindow()](autodocs-3.5/intuition-library-movewindow-2.md), [SizeWindow()](autodocs-3.5/intuition-library-sizewindow-2.md), and [ChangeWindowBox()](autodocs-3.5/intuition-library-changewindowbox-2.md), the action of
	this function is deferred to the Intuition input handler.

	More tuning needs to be done to establish initial values for
	the first invocation of this function for a window.  You can
	provide initial values using the [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) tag item
	WA_Zoom.

	It could also use a new name, but "ZoomWindow" is misleading,
	since "Zoom" normally implies "scale."

	The zoom gadget will appear (in the place of the old "toback"
	gadget) when you open your window if you either specify a
	sizing gadget or use WA_Zoom.

	You can detect that this function has taken effect by receiving
	an IDCMP_CHANGEWINDOW IDCMP message.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) -- window to be changed.

    RESULT
	None

    BUGS
	[OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) assumes that the proper default "other" dimensions
	are "full size."

    SEE ALSO
	[ChangeWindowBox()](autodocs-3.5/intuition-library-changewindowbox-2.md), [MoveWindow()](autodocs-3.5/intuition-library-movewindow-2.md), [SizeWindow()](autodocs-3.5/intuition-library-sizewindow-2.md)

---

## See Also

- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [MoveWindow — intuition.library](../autodocs/intuition.library.md#movewindow)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
