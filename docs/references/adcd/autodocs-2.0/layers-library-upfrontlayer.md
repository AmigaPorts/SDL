---
title: layers.library/UpfrontLayer
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-upfrontlayer
functions: []
libraries: []
---

# layers.library/UpfrontLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    UpfrontLayer -- Put layer in front of all other layers.
SYNOPSIS

```c
    result = UpfrontLayer( dummy, l )
    d0                     a0     a1

    LONG UpfrontLayer( LONG, struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *);
```
FUNCTION

```c
    Move this layer to the most upfront position swapping bits
    in and out of the display with other layers.
    If this is a refresh layer then collect damage list and
    set the LAYERREFRESH bit in layer->Flags if redraw required.
    By clearing the BACKDROP bit in the layers Flags you may
    bring a Backdrop layer up to the front of all other layers.

    Note: this operation may generate refresh events in other layers
       associated with this layer's [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure.
```
INPUTS

    dummy - unused
    l - pointer to a nonbackdrop layer
RESULTS

```c
    result - TRUE   if operation successful
             FALSE  if operation unsuccessful (probably out of memory)
```
BUGS

SEE ALSO

```c
    [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```
