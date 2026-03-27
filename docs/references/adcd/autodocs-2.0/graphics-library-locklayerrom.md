---
title: graphics.library/LockLayerRom
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-locklayerrom
functions: [LockLayer, UnlockLayerRom]
libraries: [graphics.library, layers.library]
---

# graphics.library/LockLayerRom

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    LockLayerRom -- Lock [Layer](autodocs-2.0/includes-graphics-clip-h.md) structure by rom(gfx lib) code.
```
SYNOPSIS

```c
    LockLayerRom( layer )
                   a5

    void LockLayerRom( struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) * );
```
FUNCTION

```c
    Return when the layer is locked and no other task may
    alter the [ClipRect](autodocs-2.0/includes-graphics-clip-h.md) structure in the [Layer](autodocs-2.0/includes-graphics-clip-h.md) structure.
    This call does not destroy any registers.
    This call nests so that callers in this chain will not lock
    themselves out.
    Do not have the [Layer](autodocs-2.0/includes-graphics-clip-h.md) locked during a call to intuition.
    There is a potential deadlock problem here, if intuition
    needs to get other locks as well.
    Having the layer locked prevents other tasks from using the
    layer library functions, most notably intuition itself. So
    be brief.
    layers.library's [LockLayer](autodocs-2.0/layers-library-locklayer.md) is identical to LockLayerRom.
```
INPUTS

```c
    layer - pointer to [Layer](autodocs-2.0/includes-graphics-clip-h.md) structure
```
RESULTS

```c
    The layer is locked and the task can render assuming the
    ClipRects will not change out from underneath it until
    an [UnlockLayerRom](autodocs-2.0/graphics-library-unlocklayerrom.md) is called.
```
SEE ALSO

```c
    [UnlockLayerRom()](autodocs-2.0/graphics-library-unlocklayerrom.md) [layers.library/LockLayer()](autodocs-2.0/layers-library-locklayer.md) [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
```

---

## See Also

- [LockLayer — layers.library](../autodocs/layers.library.md#locklayer)
- [UnlockLayerRom — graphics.library](../autodocs/graphics.library.md#unlocklayerrom)
