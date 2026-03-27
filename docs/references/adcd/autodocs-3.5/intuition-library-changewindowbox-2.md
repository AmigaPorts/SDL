---
title: intuition.library/ChangeWindowBox
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-changewindowbox-2
functions: [ChangeWindowBox, MoveSizeLayer, MoveWindow, SizeWindow, ZipWindow]
libraries: [intuition.library, layers.library]
---

# intuition.library/ChangeWindowBox

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ChangeWindowBox -- Change window position and dimensions. (V36)

    SYNOPSIS
	ChangeWindowBox( [Window](autodocs-3.5/include-intuition-intuition-h.md), Left, Top, Width, Height )
			 A0	 D0    D1   D2     D3

	VOID ChangeWindowBox( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, WORD, WORD, WORD, WORD );

    FUNCTION
	Makes simultaneous changes in window position and dimensions,
	in absolute (not relative) coordinates.

	Like [MoveWindow()](autodocs-3.5/intuition-library-movewindow-2.md) and [SizeWindow()](autodocs-3.5/intuition-library-sizewindow-2.md), the effect of this function
	is deferred until the next input comes along.  Unlike these
	functions, ChangeWindowBox() specifies absolute window position
	and dimensions, not relative.  This makes for more reliable
	results considering that the action is deferred, so this
	function is typically preferable to [MoveWindow()](autodocs-3.5/intuition-library-movewindow-2.md) and [SizeWindow()](autodocs-3.5/intuition-library-sizewindow-2.md)
	paired.

	You can detect that this operation has completed by receiving
	the IDCMP_CHANGEWINDOW IDCMP message

	The dimensions are limited to legal range, but you should still
	take care to specify sensible inputs based on the window's dimension
	limits and the size of its screen.

	This function limits the position and dimensions to legal
	values.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = the window to change position/dimension
	Left, Top, Width, Height = new position and dimensions

    RESULT
	Position and dimension are changed to your specification,
	or as close as possible.
	Returns nothing.

    BUGS

    SEE ALSO
	[MoveWindow()](autodocs-3.5/intuition-library-movewindow-2.md), [SizeWindow()](autodocs-3.5/intuition-library-sizewindow-2.md), [ZipWindow()](autodocs-3.5/intuition-library-zipwindow-2.md),
	[layers.library/MoveSizeLayer()](autodocs-3.5/layers-library-movesizelayer-2.md)

---

## See Also

- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [MoveSizeLayer — layers.library](../autodocs/layers.library.md#movesizelayer)
- [MoveWindow — intuition.library](../autodocs/intuition.library.md#movewindow)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [ZipWindow — intuition.library](../autodocs/intuition.library.md#zipwindow)
