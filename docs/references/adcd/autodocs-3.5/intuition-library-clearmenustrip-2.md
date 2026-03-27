---
title: intuition.library/ClearMenuStrip
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-clearmenustrip-2
functions: [ResetMenuStrip, SetMenuStrip, Wait]
libraries: [exec.library, intuition.library]
---

# intuition.library/ClearMenuStrip

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ClearMenuStrip -- Clear (detach) the menu strip from the window.

    SYNOPSIS
	ClearMenuStrip( [Window](autodocs-3.5/include-intuition-intuition-h.md) )
		        A0

	VOID ClearMenuStrip( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Detaches the current menu strip from the window; menu strips
	are attached to windows using the [SetMenuStrip()](autodocs-3.5/intuition-library-setmenustrip-2.md) function
	(or, for V36, [ResetMenuStrip()](autodocs-3.5/intuition-library-resetmenustrip-2.md) ).

	If the menu is in use (for that matter if any menu is in use)
	this function will block (Wait()) until the user has finished.

	Call this function before you make any changes to the data
	in a [Menu](autodocs-3.5/include-intuition-intuition-h.md) or [MenuItem](autodocs-3.5/include-intuition-intuition-h.md) structure which is part of a menu
	strip linked into a window.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a window structure

    RESULT
	None

    BUGS

    SEE ALSO
	[SetMenuStrip()](autodocs-3.5/intuition-library-setmenustrip-2.md), [ResetMenuStrip()](autodocs-3.5/intuition-library-resetmenustrip-2.md)

---

## See Also

- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
