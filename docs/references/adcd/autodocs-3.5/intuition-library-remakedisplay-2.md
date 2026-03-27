---
title: intuition.library/RemakeDisplay
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-remakedisplay-2
functions: [LoadView, MakeScreen, MakeVPort, MrgCop, RemakeDisplay, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# intuition.library/RemakeDisplay

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	RemakeDisplay -- Remake the entire Intuition display.

    SYNOPSIS
	failure = RemakeDisplay()
	D0 (V39)

	[LONG](autodocs-3.5/include-exec-types-h.md) RemakeDisplay( VOID );
	/* Returns [LONG](autodocs-3.5/include-exec-types-h.md) in V39 and greater */

    FUNCTION
	This is the big one.

	This procedure remakes the entire [View](autodocs-3.5/include-graphics-view-h.md) structure for the
	Intuition display.  It does the equivalent of [MakeScreen()](autodocs-3.5/intuition-library-makescreen-2.md) for
	every screen in the system, and then it calls the internal
	equivalent of [RethinkDisplay()](autodocs-3.5/intuition-library-rethinkdisplay-2.md).

	WARNING:  This routine can take many milliseconds to run, so
	do not use it lightly.

	Calling [MakeScreen()](autodocs-3.5/intuition-library-makescreen-2.md) followed by [RethinkDisplay()](autodocs-3.5/intuition-library-rethinkdisplay-2.md) is typically
	a more efficient method for affecting changes to a single
	screen's [ViewPort](autodocs-3.5/include-graphics-view-h.md).

    INPUTS
	None

    RESULT
	Starting with V39, returns zero for success, non-zero for failure.
	Probable cause of failure is failure of [graphics.library/MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md)
	or of [graphics.library/MrgCop()](autodocs-3.5/graphics-library-mrgcop-2.md).
	Prior to V39, the return code is invalid.  Do not interpret it when
	running on pre-V39 systems!

    BUGS

    SEE ALSO
	[MakeScreen()](autodocs-3.5/intuition-library-makescreen-2.md), [RethinkDisplay()](autodocs-3.5/intuition-library-rethinkdisplay-2.md), [graphics.library/MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md)
	[graphics.library/MrgCop()](autodocs-3.5/graphics-library-mrgcop-2.md), [graphics.library/LoadView()](autodocs-3.5/graphics-library-loadview-2.md)

---

## See Also

- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RemakeDisplay — intuition.library](../autodocs/intuition.library.md#remakedisplay)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
