---
title: intuition.library/RethinkDisplay
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-rethinkdisplay
functions: [LoadView, MakeScreen, MakeVPort, MrgCop, RemakeDisplay, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# intuition.library/RethinkDisplay

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RethinkDisplay -- Grand manipulation of the entire Intuition display.
SYNOPSIS

```c
    RethinkDisplay()

    VOID RethinkDisplay( VOID );
```
FUNCTION

```c
    This function performs the Intuition global display reconstruction.
    This includes rethinking about all of the  ViewPorts and their
    relationship to one another and reconstructing the entire display
    based on the results of this rethinking.

    Specifically, and omitting many internal details, the operation
    consists of this:

        Determine which ViewPorts are invisible and set their VP_HIDE
        [ViewPort](autodocs-2.0/includes-graphics-view-h.md) Mode flag. VP_HIDE flags are also set for screens that
        may not be simultaneously displayed with the frontmost (V36).

        If a change to a viewport height, or changing interlace or
        monitor scan rates require, [MakeVPort()](autodocs-2.0/graphics-library-makevport.md) is called for specific
        screen viewports.  After this phase, the intermediate Copper lists
        for each screen's viewport are correctly set up.

        [MrgCop()](autodocs-2.0/graphics-library-mrgcop.md) and [LoadView()](autodocs-2.0/graphics-library-loadview.md) are then called to get these Copper lists
        in action, thus establishing the new state of the Intuition
        display.

    You may perform a [MakeScreen()](autodocs-2.0/intuition-library-makescreen.md) on your [Custom](autodocs-2.0/includes-hardware-custom-h.md) [Screen](autodocs-2.0/includes-intuition-screens-h.md) before calling
    this routine.  The results will be incorporated in the new display, but
    changing the INTERLACE [ViewPort](autodocs-2.0/includes-graphics-view-h.md) mode for one screens must be reflected
    in the Intuition [View](autodocs-2.0/includes-graphics-view-h.md), which is left to Intuition.

    WARNING:  This routine can take several milliseconds to run, so
    do not use it lightly.

    New for V36: This routine is substantially changed to support
    new screen modes.  In particular, if screen rearrangement has
    caused a change in interlace mode or scan rate, this routine
    will remake the copper lists for each screen's viewport.
```
INPUTS

    None
RESULT

    None
BUGS

    In V35 and earlier, an interlaced screen coming to the front
    may not trigger a complete remake as required when the global
    interlace state is changed.  In some cases, this can be compensated
    for by setting the viewport DHeight field to 0 for hidden screens.
SEE ALSO

```c
    [RemakeDisplay()](autodocs-2.0/intuition-library-remakedisplay.md), [graphics.library/MakeVPort()](autodocs-2.0/graphics-library-makevport.md),
    [graphics.library/MrgCop()](autodocs-2.0/graphics-library-mrgcop.md), [graphics.library/LoadView()](autodocs-2.0/graphics-library-loadview.md), [MakeScreen()](autodocs-2.0/intuition-library-makescreen.md)
```

---

## See Also

- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RemakeDisplay — intuition.library](../autodocs/intuition.library.md#remakedisplay)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
