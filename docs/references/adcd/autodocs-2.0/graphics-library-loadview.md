---
title: graphics.library/LoadView
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-loadview
functions: [InitVPort, MakeVPort, MrgCop, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# graphics.library/LoadView

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    LoadView -- Use a (possibly freshly created) coprocessor instruction
               list to create the current display.
```
SYNOPSIS

```c
    LoadView( [View](autodocs-2.0/includes-graphics-view-h.md) )
              A1

    void LoadView( struct [View](autodocs-2.0/includes-graphics-view-h.md) * );
```
FUNCTION

```c
    Install a new view to be displayed during the next display
    refresh pass.
    Coprocessor instruction list has been created by
    [InitVPort()](autodocs-2.0/graphics-library-initvport.md), [MakeVPort()](autodocs-2.0/graphics-library-makevport.md), and [MrgCop()](autodocs-2.0/graphics-library-mrgcop.md).
```
INPUTS

```c
    [View](autodocs-2.0/includes-graphics-view-h.md) - a pointer to the [View](autodocs-2.0/includes-graphics-view-h.md) structure which contains the
    pointer to the constructed coprocessor instructions list, or NULL.
```
RESULT

```c
    If the [View](autodocs-2.0/includes-graphics-view-h.md) pointer is non-NULL, the new [View](autodocs-2.0/includes-graphics-view-h.md) is displayed,
    according to your instructions.  The vertical blank routine
    will pick this pointer up and direct the copper to start
    displaying this [View](autodocs-2.0/includes-graphics-view-h.md).

    If the [View](autodocs-2.0/includes-graphics-view-h.md) pointer is NULL, no [View](autodocs-2.0/includes-graphics-view-h.md) is displayed.
```
NOTE

```c
    Even though a LoadView(NULL) is performed, display DMA will still be
    active.  Sprites will continue to be displayed after a LoadView(NULL)
    unless an OFF_SPRITE is subsequently performed.
```
BUGS

SEE ALSO

```c
    [InitVPort()](autodocs-2.0/graphics-library-initvport.md) [MakeVPort()](autodocs-2.0/graphics-library-makevport.md) [MrgCop()](autodocs-2.0/graphics-library-mrgcop.md) [intuition/RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md)
    [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md)
```

---

## See Also

- [InitVPort — graphics.library](../autodocs/graphics.library.md#initvport)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
