---
title: intuition.library/ResetMenuStrip
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-resetmenustrip-2
functions: [ClearMenuStrip, CloseWindow, OpenWindow, ResetMenuStrip, SetMenuStrip]
libraries: [intuition.library]
---

# intuition.library/ResetMenuStrip

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ResetMenuStrip -- Re-attach a menu strip to a window. (V36)

    SYNOPSIS
	Success = ResetMenuStrip( [Window](autodocs-3.5/include-intuition-intuition-h.md), [Menu](autodocs-3.5/include-intuition-intuition-h.md) )
	D0		          A0      A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) ResetMenuStrip( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Menu](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	This function is simply a "fast" version of [SetMenuStrip()](autodocs-3.5/intuition-library-setmenustrip-2.md) that
	doesn't perform the precalculations of menu page sizes that
	[SetMenuStrip()](autodocs-3.5/intuition-library-setmenustrip-2.md) does.

	You may call this function ONLY IF the menu strip and all items
	and sub-items have not changed since the menu strip was passed to
	[SetMenuStrip()](autodocs-3.5/intuition-library-setmenustrip-2.md), with the following exceptions:

	- You may change the CHECKED flag to turn a checkmark on or off.
	- You may change the ITEMENABLED flag to enable/disable some
	  [MenuItem](autodocs-3.5/include-intuition-intuition-h.md) or [Menu](autodocs-3.5/include-intuition-intuition-h.md) structures.

	In all other ways, this function performs like [SetMenuStrip()](autodocs-3.5/intuition-library-setmenustrip-2.md).

	The new sequence of events you can use is:
	- [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md)
	- [SetMenuStrip()](autodocs-3.5/intuition-library-setmenustrip-2.md)
	zero or more iterations of:
	    - [ClearMenuStrip()](autodocs-3.5/intuition-library-clearmenustrip-2.md)
	    - change CHECKED or ITEMENABLED flags
	    - ResetMenuStrip()
	- [ClearMenuStrip()](autodocs-3.5/intuition-library-clearmenustrip-2.md)
	- [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md)

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a [Window](autodocs-3.5/include-intuition-intuition-h.md) structure
	[Menu](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the first menu in the menu strip

    RESULT
	TRUE always.

    BUGS

    SEE ALSO
	[SetMenuStrip()](autodocs-3.5/intuition-library-setmenustrip-2.md), [ClearMenuStrip()](autodocs-3.5/intuition-library-clearmenustrip-2.md)

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
