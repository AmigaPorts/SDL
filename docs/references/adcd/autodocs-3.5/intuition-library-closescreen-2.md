---
title: intuition.library/CloseScreen
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-closescreen-2
functions: [CloseScreen, LockPubScreen, OpenScreen]
libraries: [intuition.library]
---

# intuition.library/CloseScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CloseScreen -- [Close](autodocs-3.5/dos-library-close-2.md) an Intuition screen.

    SYNOPSIS
	Success = CloseScreen( [Screen](autodocs-3.5/include-intuition-screens-h.md) )
	D0 (V36)               A0

	[BOOL](autodocs-3.5/include-exec-types-h.md) CloseScreen( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) * );
	/* returns [BOOL](autodocs-3.5/include-exec-types-h.md) in V36 and greater */

    FUNCTION
	Unlinks the screen, unlinks the viewport, deallocates everything that
	Intuition allocated when the screen was opened (using [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md)).
	Doesn't care whether or not there are still any windows attached to the
	screen.  Doesn't try to close any attached windows; in fact, ignores
	them altogether (but see below for changes in V36).

	If this is the last screen to go, attempts to reopen Workbench.

	New for V36: this function will refuse to close the screen
	if there are windows open on the screen or if there are any
	outstanding screen locks (see [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md)) when
	CloseScreen() is called.  This avoids the almost certain crash
	when a screen is closed out from under a window.

    INPUTS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = pointer to the screen to be closed.

    RESULT
	New for V36: returns TRUE (1) if screen is closed,
	returns FALSE (0) if screen had open windows when
	called.

    BUGS

    SEE ALSO
	[OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md)

---

## See Also

- [CloseScreen — intuition.library](../autodocs/intuition.library.md#closescreen)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
