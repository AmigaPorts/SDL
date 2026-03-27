---
title: layers.library/InstallLayerHook
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-installlayerhook
functions: []
libraries: []
---

# layers.library/InstallLayerHook

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME                                                              (V36)

    InstallLayerHook -- safely install a new Layer->BackFill hook.
SYNOPSIS

```c
    oldhook = InstallLayerHook( layer, hook )
    d0                          a0     a1

    struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) *InstallLayerHook( struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *, struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) *);
```
FUNCTION

```c
    Installs a new Layer->Backfill [Hook](autodocs-2.0/includes-utility-hooks-h.md), waiting until it is safe to do
    so. Locks the layer while substituting the new [Hook](autodocs-2.0/includes-utility-hooks-h.md) and removing the
    old one. If a new [Hook](autodocs-2.0/includes-utility-hooks-h.md) is not provided, will install the default layer
    BackFill [Hook](autodocs-2.0/includes-utility-hooks-h.md).
```
INPUTS

```c
    layer - pointer to the layer in which to install the Backfill [Hook](autodocs-2.0/includes-utility-hooks-h.md).
    hook -  pointer to layer callback [Hook](autodocs-2.0/includes-utility-hooks-h.md) which will be called
            with object == (struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *) result->RastPort
            and message == [ (Layer *) layer, (struct Rectangle) bounds,
                           (WORD) offsetx, (WORD) offsety ]

            This hook should fill the [Rectangle](autodocs-2.0/includes-graphics-gfx-h.md) in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
            with the BackFill pattern appropriate for offset x/y.

            If this hook pointer is NULL, the function installs
            the "default" Layers BackFill [Hook](autodocs-2.0/includes-utility-hooks-h.md) into this [Layer](autodocs-2.0/includes-graphics-clip-h.md).
```
RESULTS

```c
    oldhook - pointer to the Layer->BackFill [Hook](autodocs-2.0/includes-utility-hooks-h.md) that was previously
              active.
```
BUGS

SEE ALSO

```c
    [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md) [utility/hooks.h](autodocs-2.0/includes-utility-hooks-h.md)
```
