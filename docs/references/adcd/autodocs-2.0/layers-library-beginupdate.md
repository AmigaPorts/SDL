---
title: layers.library/BeginUpdate
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-beginupdate
functions: []
libraries: []
---

# layers.library/BeginUpdate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    BeginUpdate -- Prepare to repair damaged layer.
SYNOPSIS

```c
    result = BeginUpdate( l )
    d0                    a0

    LONG BeginUpdate( struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *);
```
FUNCTION

```c
    Convert damage list to [ClipRect](autodocs-2.0/includes-graphics-clip-h.md) list and swap in for
    programmer to redraw through. This routine simulates
    the ROM library environment. The idea is to only render in the
    "damaged" areas, saving time over redrawing all of the layer.
    The layer is locked against changes made by the layer library.
```
INPUTS

    l - pointer to a layer
RESULTS

```c
    result - TRUE if damage list converted to [ClipRect](autodocs-2.0/includes-graphics-clip-h.md) list sucessfully.
             FALSE if list conversion aborted. (probably out of memory)
```
BUGS

```c
    If BeginUpdate returns FALSE, programmer must abort the attempt to
    refresh this layer and instead call EndUpdate( l, FALSE ) to restore
    original [ClipRect](autodocs-2.0/includes-graphics-clip-h.md) and damage list.
```
SEE ALSO

```c
    [EndUpdate](autodocs-2.0/layers-library-endupdate.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md), [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
```
