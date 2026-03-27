---
title: layers.library/MoveSizeLayer
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-movesizelayer
functions: []
libraries: []
---

# layers.library/MoveSizeLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME                                                              (V36)

    MoveSizeLayer -- Position/Size layer
SYNOPSIS

```c
    result = MoveSizeLayer( layer, dx, dy, dw, dh )
    d0                      a0     d0  d1  d2  d3

    LONG MoveSizeLayer( struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *, LONG, LONG, LONG, LONG);
```
FUNCTION

```c
    Change upperleft and lower right position of [Layer](autodocs-2.0/includes-graphics-clip-h.md).
```
INPUTS

```c
    dummy - unused
    l - pointer to a nonbackdrop layer
    dx,dy - change upper left corner by (dx,dy)
    dw,dy - change size by (dw,dh)
```
RETURNS

```c
    result - TRUE if operation successful
             FALSE if failed (due to out of memory)
             FALSE if failed (due to illegal layer->bounds)
```
BUGS

SEE ALSO

```c
    [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md), [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
```
