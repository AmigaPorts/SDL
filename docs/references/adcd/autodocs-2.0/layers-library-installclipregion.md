---
title: layers.library/InstallClipRegion
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-installclipregion
functions: [CloseWindow]
libraries: [intuition.library]
---

# layers.library/InstallClipRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    InstallClipRegion -- Install clip region in layer
SYNOPSIS

```c
    oldclipregion = InstallClipRegion( l,  region )
    d0                                 a0  a1

    struct [Region](autodocs-2.0/includes-graphics-regions-h.md) *InstallClipRegion( struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *, struct [Region](autodocs-2.0/includes-graphics-regions-h.md) *);
```
FUNCTION

```c
    Installs a transparent Clip region in the layer. All
    subsequent graphics calls will be clipped to this region.
    You MUST remember to call InstallClipRegion(l,NULL) before
    calling DeleteLayer(l) or the Intuition function [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md)
    if you have installed a non-NULL ClipRegion in l.
```
INPUTS

    l - pointer to a layer
    region - pointer to a region
RESULTS

    oldclipregion - The pointer to the previous ClipRegion that
        was installed. Returns NULL if no previous ClipRegion installed.

        Note: If the system runs out of memory while computing the
            resulting ClipRects the LAYERS_CLIPRECTS_LOST bit will
            be set in l->Flags.
BUGS

```c
    If the system runs out of memory during normal layer operations,
    the [ClipRect](autodocs-2.0/includes-graphics-clip-h.md) list may get swept away and not restored.
    As soon as there is enough memory and the layer library
    gets called again the [ClipRect](autodocs-2.0/includes-graphics-clip-h.md) list will be rebuilt.
```
SEE ALSO

```c
    [BeginUpdate](autodocs-2.0/layers-library-beginupdate.md) [EndUpdate](autodocs-2.0/layers-library-endupdate.md),
    [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md), [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md), [graphics/regions.h](autodocs-2.0/includes-graphics-regions-h.md)
```

---

## See Also

- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
