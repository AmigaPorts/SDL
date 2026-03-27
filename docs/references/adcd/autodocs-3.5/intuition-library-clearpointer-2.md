---
title: intuition.library/ClearPointer
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-clearpointer-2
functions: [ClearPointer, SetPointer, SetWindowPointerA]
libraries: [intuition.library]
---

# intuition.library/ClearPointer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ClearPointer -- Clear the mouse pointer definition from a window.

    SYNOPSIS
	ClearPointer( [Window](autodocs-3.5/include-intuition-intuition-h.md) )
		      A0

	VOID ClearPointer( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Clears the window of its own definition of the Intuition mouse pointer.
	After calling ClearPointer(), every time this window is the active
	one the default Intuition pointer will be the pointer displayed
	to the user.  If your window is the active one when this routine
	is called, the change will take place immediately.

	[Custom](autodocs-3.5/include-hardware-custom-h.md) definitions of the mouse pointer which this function clears
	are installed by a call to [SetPointer()](autodocs-3.5/intuition-library-setpointer-2.md).

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window to be cleared of its pointer definition

    RESULT
	None

    BUGS

    SEE ALSO
	[SetWindowPointerA()](autodocs-3.5/intuition-library-setwindowpointera.md), [SetPointer()](autodocs-3.5/intuition-library-setpointer-2.md)

---

## See Also

- [ClearPointer — intuition.library](../autodocs/intuition.library.md#clearpointer)
- [SetPointer — intuition.library](../autodocs/intuition.library.md#setpointer)
- [SetWindowPointerA — intuition.library](../autodocs/intuition.library.md#setwindowpointera)
