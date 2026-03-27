---
title: graphics.library/ScrollVPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-scrollvport
functions: [LoadView, MakeVPort, MrgCop]
libraries: [graphics.library]
---

# graphics.library/ScrollVPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ScrollVPort -- Reinterpret RasInfo information in [ViewPort](autodocs-2.0/includes-graphics-view-h.md) to reflect
                    the current Offset values.
```
SYNOPSIS

```c
    ScrollVPort( vp )
                 a0

    void ScrollVPort(struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) *);
```
FUNCTION

```c
    After the programmer has adjusted the Offset values in
    the RasInfo structures of [ViewPort](autodocs-2.0/includes-graphics-view-h.md), change the
    the copper lists to reflect the the Scroll positions.
    Changing the [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) ptr in RasInfo and not changing the
    the Offsets will effect a double buffering affect.
```
INPUTS
```c
    vp - pointer to a [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure
         that is currently be displayed.
```
RESULTS

    modifies hardware and intermediate copperlists to reflect
    new RasInfo
BUGS
   pokes not fast enough to avoid some visible hashing of display

SEE ALSO

```c
    [MakeVPort()](autodocs-2.0/graphics-library-makevport.md) [MrgCop()](autodocs-2.0/graphics-library-mrgcop.md) [LoadView()](autodocs-2.0/graphics-library-loadview.md)  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md)
```

---

## See Also

- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
