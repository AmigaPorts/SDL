---
title: intuition.library/RemakeDisplay
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-remakedisplay
functions: [LoadView, MakeScreen, MakeVPort, MrgCop, RemakeDisplay, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# intuition.library/RemakeDisplay

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RemakeDisplay -- Remake the entire Intuition display.
SYNOPSIS

```c
    RemakeDisplay()

    VOID RemakeDisplay( VOID );
```
FUNCTION

```c
    This is the big one.

    This procedure remakes the entire [View](autodocs-2.0/includes-graphics-view-h.md) structure for the
    Intuition display.  It does the equivalent of [MakeScreen()](autodocs-2.0/intuition-library-makescreen.md) for
    every screen in the system, and then it calls the internal
    equivalent of [RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md).

    WARNING:  This routine can take many milliseconds to run, so
    do not use it lightly.

    Calling [MakeScreen()](autodocs-2.0/intuition-library-makescreen.md) followed by [RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md) is typically
    a more efficient method for affecting changes to a single
    screen's [ViewPort](autodocs-2.0/includes-graphics-view-h.md).
```
INPUTS

    None
RESULT

    None
BUGS

SEE ALSO

```c
    [MakeScreen()](autodocs-2.0/intuition-library-makescreen.md), [RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md), [graphics.library/MakeVPort()](autodocs-2.0/graphics-library-makevport.md)
    [graphics.library/MrgCop()](autodocs-2.0/graphics-library-mrgcop.md), [graphics.library/LoadView()](autodocs-2.0/graphics-library-loadview.md)
```

---

## See Also

- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RemakeDisplay — intuition.library](../autodocs/intuition.library.md#remakedisplay)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
