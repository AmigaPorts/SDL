---
title: intuition.library/MakeScreen
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-makescreen
functions: [MakeVPort, RemakeDisplay, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# intuition.library/MakeScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    MakeScreen -- Do an Intuition-integrated [MakeVPort()](autodocs-2.0/graphics-library-makevport.md) of a screen.
```
SYNOPSIS

```c
    MakeScreen( [Screen](autodocs-2.0/includes-intuition-screens-h.md) )
                A0

    VOID MakeScreen( struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) * );
```
FUNCTION

```c
    This procedure allows you to do a [MakeVPort()](autodocs-2.0/graphics-library-makevport.md) for the viewport of your
    custom screen in an Intuition-integrated way.  This way you can
    do your own screen manipulations without worrying about interference
    with Intuition's usage of the same viewport.

    The operation of this function is as follows:
        - Block until the Intuition [View](autodocs-2.0/includes-graphics-view-h.md) structure is not in being changed.
        - Set the view modes correctly to reflect if there is a (visible)
          interlaced screen.
        - call [MakeVPort()](autodocs-2.0/graphics-library-makevport.md), passing the Intuition [View](autodocs-2.0/includes-graphics-view-h.md) and your screen's
          [ViewPort](autodocs-2.0/includes-graphics-view-h.md).
        - Unlocks the Intuition [View](autodocs-2.0/includes-graphics-view-h.md).

    After calling this routine, you should call [RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md) to
    incorporate the new viewport of your custom screen into the
    Intuition display.

    NOTE: Intuition may determine that because of a change in global
    interlace needs that all viewports need to be remade, so
    it may effectively call [RemakeDisplay()](autodocs-2.0/intuition-library-remakedisplay.md).
```
INPUTS

```c
    [Screen](autodocs-2.0/includes-intuition-screens-h.md) = address of the custom screen structure
```
RESULT

    None
BUGS

SEE ALSO

```c
    [RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md), [RemakeDisplay()](autodocs-2.0/intuition-library-remakedisplay.md), [graphics.library/MakeVPort()](autodocs-2.0/graphics-library-makevport.md)
```

---

## See Also

- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [RemakeDisplay — intuition.library](../autodocs/intuition.library.md#remakedisplay)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
