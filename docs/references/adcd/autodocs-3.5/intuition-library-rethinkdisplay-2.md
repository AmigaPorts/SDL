---
title: intuition.library/RethinkDisplay
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-rethinkdisplay-2
functions: [LoadView, MakeScreen, MakeVPort, MrgCop, RemakeDisplay, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# intuition.library/RethinkDisplay

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	RethinkDisplay -- Grand manipulation of the entire Intuition display.

    SYNOPSIS
	failure = RethinkDisplay()
	D0 (V39)

	[LONG](autodocs-3.5/include-exec-types-h.md) RethinkDisplay( VOID );
	/* Returns [LONG](autodocs-3.5/include-exec-types-h.md) in V39 and greater */

    FUNCTION
	This function performs the Intuition global display reconstruction.
	This includes rethinking about all of the  ViewPorts and their
	relationship to one another and reconstructing the entire display
	based on the results of this rethinking.

	Specifically, and omitting many internal details, the operation
	consists of this:

	    Determine which ViewPorts are invisible and set their VP_HIDE
	    [ViewPort](autodocs-3.5/include-graphics-view-h.md) Mode flag. VP_HIDE flags are also set for screens that
	    may not be simultaneously displayed with the frontmost (V36).

	    If a change to a viewport height, or changing interlace or
	    monitor scan rates require, [MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md) is called for specific
	    screen viewports.  After this phase, the intermediate Copper lists
	    for each screen's viewport are correctly set up.

	    [MrgCop()](autodocs-3.5/graphics-library-mrgcop-2.md) and [LoadView()](autodocs-3.5/graphics-library-loadview-2.md) are then called to get these Copper lists
	    in action, thus establishing the new state of the Intuition
	    display.

	You may perform a [MakeScreen()](autodocs-3.5/intuition-library-makescreen-2.md) on your [Custom](autodocs-3.5/include-hardware-custom-h.md) [Screen](autodocs-3.5/include-intuition-screens-h.md) before calling
	this routine.  The results will be incorporated in the new display, but
	changing the INTERLACE [ViewPort](autodocs-3.5/include-graphics-view-h.md) mode for one screens must be reflected
	in the Intuition [View](autodocs-3.5/include-graphics-view-h.md), which is left to Intuition.

	WARNING:  This routine can take several milliseconds to run, so
	do not use it lightly.

	New for V36: This routine is substantially changed to support
	new screen modes.  In particular, if screen rearrangement has
	caused a change in interlace mode or scan rate, this routine
	will remake the copper lists for each screen's viewport.

    INPUTS
	None

    RESULT
	Starting with V39, returns zero for success, non-zero for failure.
	Probable cause of failure is failure of [graphics.library/MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md)
	or of [graphics.library/MrgCop()](autodocs-3.5/graphics-library-mrgcop-2.md).
	Prior to V39, the return code is invalid.  Do not interpret it when
	running on pre-V39 systems!

    BUGS
	In V35 and earlier, an interlaced screen coming to the front
	may not trigger a complete remake as required when the global
	interlace state is changed.  In some cases, this can be compensated
	for by setting the viewport DHeight field to 0 for hidden screens.

    SEE ALSO
	[RemakeDisplay()](autodocs-3.5/intuition-library-remakedisplay-2.md), [graphics.library/MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md), [graphics.library/MrgCop()](autodocs-3.5/graphics-library-mrgcop-2.md),
	[graphics.library/LoadView()](autodocs-3.5/graphics-library-loadview-2.md), [MakeScreen()](autodocs-3.5/intuition-library-makescreen-2.md)

---

## See Also

- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RemakeDisplay — intuition.library](../autodocs/intuition.library.md#remakedisplay)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
