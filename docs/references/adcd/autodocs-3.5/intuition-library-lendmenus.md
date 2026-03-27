---
title: intuition.library/LendMenus
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-lendmenus
functions: [ClearMenuStrip, SetMenuStrip]
libraries: [intuition.library]
---

# intuition.library/LendMenus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	LendMenus -- Lend window's menu action to another window. (V39)

    SYNOPSIS
	LendMenus( fromWindow, toWindow )
	           A0          A1

	VOID LendMenus( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	This function is used to "lend" the menus of one window to
	another.  This means that menu events (for example, the user
	presses the mouse menu button) will take place in another
	window's menu (using that other window's menu strip and screen).

	The sole intended use of this function is to unify two
	windows on different screens that are attached.  (See
	SA_Parent, SA_FrontChild, SA_BackChild).  An example would
	be a program with a full-sized parent screen which has a
	short control panel screen attached in the front.  Pressing the
	menu button even when the control panel window of the canvas
	screen is active can now cause the menus of the parent screen
	to appear.

    INPUTS
	fromWindow = pointer to the [Window](autodocs-3.5/include-intuition-intuition-h.md) structure whose menu actions
	    are to go to another window.
	toWindow = pointer to the [Window](autodocs-3.5/include-intuition-intuition-h.md) structure whose menus are to
	    be displayed in place of the fromWindow's.  If NULL, turns
	    off menu-lending from the fromWindow.

    RESULT
	None.

    BUGS
	The current behavior is such that the toWindow is temporarily
	activated.  This may not continue to be the case.  Be prepared
	to handle this!

    SEE ALSO
	[SetMenuStrip()](autodocs-3.5/intuition-library-setmenustrip-2.md), [ClearMenuStrip()](autodocs-3.5/intuition-library-clearmenustrip-2.md)

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
