---
title: layers.library/SizeLayer
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-sizelayer
functions: []
libraries: []
---

# layers.library/SizeLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SizeLayer -- Change the size of this nonbackdrop layer.
SYNOPSIS

```c
    result = SizeLayer( dummy, l, dx, dy )
    d0                  a0     a1 d0  d1

    LONG SizeLayer( LONG, struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *, LONG, LONG);
```
FUNCTION

```c
    Change the size of this layer by (dx,dy). The lower right hand
    corner is extended to make room for the larger layer.
    If there is SuperBitMap for this layer then copy pixels into
    or out of the layer depending on whether the layer increases or
    decreases in size.  Collect damage list for those layers that may
    need to be refreshed if damage occurred.
```
INPUTS

    dummy - unused
    l - pointer to a nonbackdrop layer
    dx - delta to add to current x size
    dy - delta to add to current y size
RESULTS

```c
    result - TRUE if operation successful
             FALSE if failed (out of memory)
```
BUGS

SEE ALSO

```c
    [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md), [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
```
