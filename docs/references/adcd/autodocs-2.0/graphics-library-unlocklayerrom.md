---
title: graphics.library/UnlockLayerRom
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-unlocklayerrom
functions: [LockLayerRom, UnlockLayer]
libraries: [graphics.library, layers.library]
---

# graphics.library/UnlockLayerRom

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    UnlockLayerRom -- Unlock [Layer](autodocs-2.0/includes-graphics-clip-h.md) structure by rom(gfx lib) code.
```
SYNOPSIS

```c
    UnlockLayerRom( layer )
                     a5

    void UnlockLayerRom( struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) * );
```
FUNCTION

```c
    Release the lock on this layer. If the same task has called
    [LockLayerRom](autodocs-2.0/graphics-library-locklayerrom.md) more than once than the same number of calls to
    UnlockLayerRom must happen before the layer is actually freed
    so that other tasks may use it.
    This call does destroy scratch registers.
    This call is identical to [UnlockLayer](autodocs-2.0/layers-library-unlocklayer.md) (layers.library).
```
INPUTS

```c
    layer - pointer to [Layer](autodocs-2.0/includes-graphics-clip-h.md) structure
```
BUGS

SEE ALSO

```c
    [LockLayerRom()](autodocs-2.0/graphics-library-locklayerrom.md) [layers.library/UnlockLayer()](autodocs-2.0/layers-library-unlocklayer.md) [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
```

---

## See Also

- [LockLayerRom — graphics.library](../autodocs/graphics.library.md#locklayerrom)
- [UnlockLayer — layers.library](../autodocs/layers.library.md#unlocklayer)
