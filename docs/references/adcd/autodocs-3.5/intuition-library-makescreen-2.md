---
title: intuition.library/MakeScreen
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-makescreen-2
functions: [MakeVPort, RemakeDisplay, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# intuition.library/MakeScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	MakeScreen -- Do an Intuition-integrated [MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md) of a screen.

    SYNOPSIS
	failure = MakeScreen( [Screen](autodocs-3.5/include-intuition-screens-h.md) )
	D0 (V39)              A0

	[LONG](autodocs-3.5/include-exec-types-h.md) MakeScreen( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) * );
	/* Returns [LONG](autodocs-3.5/include-exec-types-h.md) in V39 and greater */

    FUNCTION
	This procedure allows you to do a [MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md) for the viewport of your
	custom screen in an Intuition-integrated way.  This way you can
	do your own screen manipulations without worrying about interference
	with Intuition's usage of the same viewport.

	The operation of this function is as follows:
	    - Block until the Intuition [View](autodocs-3.5/include-graphics-view-h.md) structure is not in being changed.
	    - Set the view modes correctly to reflect if there is a (visible)
	      interlaced screen.
	    - call [MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md), passing the Intuition [View](autodocs-3.5/include-graphics-view-h.md) and your screen's
	      [ViewPort](autodocs-3.5/include-graphics-view-h.md).
	    - Unlocks the Intuition [View](autodocs-3.5/include-graphics-view-h.md).

	After calling this routine, you should call [RethinkDisplay()](autodocs-3.5/intuition-library-rethinkdisplay-2.md) to
	incorporate the new viewport of your custom screen into the
	Intuition display.

	NOTE: Intuition may determine that because of a change in global
	interlace needs that all viewports need to be remade, so
	it may effectively call [RemakeDisplay()](autodocs-3.5/intuition-library-remakedisplay-2.md).

    INPUTS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = address of the custom screen structure

    RESULT
	Starting with V39, returns zero for success, non-zero for failure.
	Probable cause of failure is failure of [graphics.library/MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md).
	Prior to V39, the return code is invalid.  Do not interpret it when
	running on pre-V39 systems!

    BUGS

    SEE ALSO
	[RethinkDisplay()](autodocs-3.5/intuition-library-rethinkdisplay-2.md), [RemakeDisplay()](autodocs-3.5/intuition-library-remakedisplay-2.md), [graphics.library/MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md)

---

## See Also

- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [RemakeDisplay — intuition.library](../autodocs/intuition.library.md#remakedisplay)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
