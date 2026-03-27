---
title: intuition.library/ActivateWindow
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-activatewindow-2
functions: [OpenWindow]
libraries: [intuition.library]
---

# intuition.library/ActivateWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ActivateWindow -- Activate an Intuition window.

    SYNOPSIS
	ActivateWindow( [Window](autodocs-3.5/include-intuition-intuition-h.md) )
	                A0

	VOID ActivateWindow( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Activates an Intuition window.

	Note that this call may have its action deferred: you cannot assume
	that when this call is made the selected window has become active.
	This action will be postponed while the user plays with gadgets and
	menus, or sizes and drags windows.  You may detect when the window
	actually has become active by the IDCMP_ACTIVEWINDOW IDCMP message.

	This call is intended to provide flexibility but not to confuse the
	user.  Please call this function synchronously with some action
	by the user.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = a pointer to a [Window](autodocs-3.5/include-intuition-intuition-h.md) structure

    RESULT
	None.

    BUGS
	Some versions of the documentation claimed that this function
	had a meaningful return value under V36 and higher.  That is
	not true.

	Calling this function in a tight loop can blow out Intuition's
	deferred action queue.

    SEE ALSO
	[OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md), and the WFLG_ACTIVATE window flag

---

## See Also

- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
