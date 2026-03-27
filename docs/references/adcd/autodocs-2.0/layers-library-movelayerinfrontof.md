---
title: layers.library/MoveLayerInFrontOf
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-movelayerinfrontof
functions: []
libraries: []
---

# layers.library/MoveLayerInFrontOf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    MoveLayerInFrontOf -- Put layer in front of another layer.
SYNOPSIS

```c
    result = MoveLayerInFrontOf( layertomove, targetlayer )
                                a0           a1

    LONG MoveLayerInFrontOf( struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *, struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *);
```
FUNCTION

```c
    Move this layer in front of target layer, swapping bits
    in and out of the display with other layers.
    If this is a refresh layer then collect damage list and
    set the LAYERREFRESH bit in layer->Flags if redraw required.

    Note: this operation may generate refresh events in other layers
        associated with this layer's [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure.
```
INPUTS

    layertomove - pointer to layer which should be moved
    targetlayer - pointer to target layer in front of which to move layer
RESULTS

```c
    result = TRUE    if operation successful
             FALSE   if operation unsuccessful (probably out of memory)
```
BUGS

SEE ALSO

```c
    [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```
