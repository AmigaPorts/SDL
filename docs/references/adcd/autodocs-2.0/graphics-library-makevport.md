---
title: graphics.library/MakeVPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-makevport
functions: [InitVPort, MakeScreen, MrgCop, RemakeDisplay, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# graphics.library/MakeVPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    MakeVPort -- generate display copper list for a viewport.
SYNOPSIS

```c
    MakeVPort( view, viewport )
                a0      a1

    void MakeVPort( struct [View](autodocs-2.0/includes-graphics-view-h.md) *, struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) * );
```
FUNCTION

```c
    Uses information in the [View](autodocs-2.0/includes-graphics-view-h.md), [ViewPort](autodocs-2.0/includes-graphics-view-h.md), ViewPort->RasInfo to
    construct and intermediate copper list for this [ViewPort](autodocs-2.0/includes-graphics-view-h.md).
```
INPUTS

```c
    view - pointer to a [View](autodocs-2.0/includes-graphics-view-h.md) structure
    viewport - pointer to a [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure
             The viewport must have valid pointer to a RasInfo.
```
RESULTS

```c
    constructs intermediate copper list and puts pointers in
    viewport.DspIns
    If the [ColorMap](autodocs-2.0/includes-graphics-view-h.md) ptr in [ViewPort](autodocs-2.0/includes-graphics-view-h.md) is NULL then it uses colors
    from the default color table.
    If DUALPF in Modes then there must be a second RasInfo pointed
    to by the first RasInfo
```
BUGS

```c
    Narrow Viewports (whose righthand edge is less than 3/4 of the
    way across the display) still do not work properly.
```
SEE ALSO

```c
    [InitVPort()](autodocs-2.0/graphics-library-initvport.md) [MrgCop()](autodocs-2.0/graphics-library-mrgcop.md) [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md) [intuition.library/MakeScreen()](autodocs-2.0/intuition-library-makescreen.md)
    [intuition.library/RemakeDisplay()](autodocs-2.0/intuition-library-remakedisplay.md) [intuition.library/RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md)
```

---

## See Also

- [InitVPort — graphics.library](../autodocs/graphics.library.md#initvport)
- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RemakeDisplay — intuition.library](../autodocs/intuition.library.md#remakedisplay)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
