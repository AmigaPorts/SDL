---
title: intuition.library/SetMenuStrip
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-setmenustrip-2
functions: [ClearMenuStrip, CloseWindow, OpenWindow, ResetMenuStrip, SetMenuStrip]
libraries: [intuition.library]
---

# intuition.library/SetMenuStrip

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetMenuStrip -- Attach a menu strip to a window.

    SYNOPSIS
	Success = SetMenuStrip( [Window](autodocs-3.5/include-intuition-intuition-h.md), [Menu](autodocs-3.5/include-intuition-intuition-h.md) )
	D0		        A0      A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) SetMenuStrip( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Menu](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Attaches the menu strip to the window.  After calling this routine,
	if the user presses the menu button, this specified menu strip
	will be displayed and accessible by the user.

	Menus with zero menu items are not allowed.

	NOTE:  You should always design your menu strip changes to be a
	two-way operation, where for every menu strip you add to your
	window you should always plan to clear that strip sometime.  Even
	in the simplest case, where you will have just one menu strip for
	the lifetime of your window, you should always clear the menu strip
	before closing the window.  If you already have a menu strip attached
	to this window, the correct procedure for changing to a new menu
	strip involves calling [ClearMenuStrip()](autodocs-3.5/intuition-library-clearmenustrip-2.md) to clear the old first.

	The sequence of events should be:
	- [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md)
	- zero or more iterations of:
```c
      	- SetMenuStrip()
      	- [ClearMenuStrip()](autodocs-3.5/intuition-library-clearmenustrip-2.md)
```
	- [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md)

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a [Window](autodocs-3.5/include-intuition-intuition-h.md) structure
	[Menu](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the first menu in the menu strip

    RESULT
	TRUE if there were no problems.  TRUE always, since this routine
	will wait until it is OK to proceed.

    BUGS

    SEE ALSO
	[ClearMenuStrip()](autodocs-3.5/intuition-library-clearmenustrip-2.md), [ResetMenuStrip()](autodocs-3.5/intuition-library-resetmenustrip-2.md)

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
