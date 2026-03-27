---
title: intuition.library/SetPointer
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-setpointer-2
functions: [ClearPointer, SetWindowPointerA]
libraries: [intuition.library]
---

# intuition.library/SetPointer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetPointer -- Specify a pointer sprite image for a window.

    SYNOPSIS
	SetPointer( [Window](autodocs-3.5/include-intuition-intuition-h.md), Pointer, Height, Width, XOffset, YOffset )
		    A0      A1       D0      D1     D2       D3

	VOID SetPointer( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md) *, WORD, WORD, WORD, WORD );

    FUNCTION
	Sets up the window with the sprite definition for the pointer.
	Then, whenever the window is the active one, the pointer
	image will change to the window's version.  If the window is
	the active one when this routine is called, the change takes
	place immediately.

	The XOffset and YOffset parameters are used to offset the
	upper-left corner of the hardware sprite image from what Intuition
	regards as the current position of the pointer.  Another way of
	describing it is as the offset from the "hot spot" of the pointer
	to the top-left corner of the sprite.  For instance, if you specify
	offsets of zero, zero, then the top-left corner of your sprite
	image will be placed at the mouse position.  On the other hand,
	if you specify an XOffset of -7 (remember, sprites are 16 pixels
	wide) then your sprite will be centered over the mouse position.
	If you specify an XOffset of -15, the right-edge of the sprite
	will be over the mouse position.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window to receive this pointer definition
	Pointer = pointer to the data definition of a sprite
	Height = the height of the pointer
	Width = the width of the sprite (must be less than or equal to sixteen)
	XOffset = the offset for your sprite from the mouse position
	YOffset = the offset for your sprite from the mouse position

    RESULT
	None

    BUGS

    SEE ALSO
	[SetWindowPointerA()](autodocs-3.5/intuition-library-setwindowpointera.md), [ClearPointer()](autodocs-3.5/intuition-library-clearpointer-2.md), ROM Kernel Manual: Libraries

---

## See Also

- [ClearPointer — intuition.library](../autodocs/intuition.library.md#clearpointer)
- [SetWindowPointerA — intuition.library](../autodocs/intuition.library.md#setwindowpointera)
