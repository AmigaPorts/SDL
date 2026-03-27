---
title: layers.library/MoveLayer
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-movelayer
functions: []
libraries: []
---

# layers.library/MoveLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    MoveLayer -- Move layer to new position in [BitMap](autodocs-2.0/includes-graphics-gfx-h.md).
```
SYNOPSIS

```c
    result = MoveLayer( dummy, l, dx, dy )
    d0                  a0     a1 d0  d1

    LONG MoveLayer( LONG, struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *, LONG, LONG);
```
FUNCTION

```c
    Move this layer to new position in shared [BitMap](autodocs-2.0/includes-graphics-gfx-h.md).
    If any refresh layers become revealed, collect damage and
    set REFRESH bit in layer Flags.
```
INPUTS

    dummy - unused
    l - pointer to a nonbackdrop layer
    dx - delta to add to current x position
    dy - delta to add to current y position
RETURNS

```c
    result - TRUE if operation successful
             FALSE if failed (out of memory)
```
BUGS

```c
    May not handle (dx,dy) which attempts to move the layer ouside the
    layer's RastPort->BitMap bounds .
```
SEE ALSO

```c
    [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md), [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
```
