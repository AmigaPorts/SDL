---
title: layers.library/LockLayer
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-locklayer
functions: [LockLayerInfo, UnlockLayerInfo]
libraries: [layers.library]
---

# layers.library/LockLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    LockLayer -- Lock layer to make changes to ClipRects.
SYNOPSIS

```c
    LockLayer( dummy, l )
               a0     a1

    void LockLayer( LONG, struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *);
```
FUNCTION

```c
    Make this layer unavailable for other tasks to use.
    If another task is already using this layer then wait for
    it to complete and then reserve the layer for your own use.
    (this function does the same thing as graphics.library/LockLayerRom)

    Note: if you wish to lock MORE THAN ONE layer at a time, you
        must call [LockLayerInfo()](autodocs-2.0/layers-library-locklayerinfo.md) before locking those layers and
        then call [UnlockLayerInfo()](autodocs-2.0/layers-library-unlocklayerinfo.md) when you have finished. This
        is to prevent system "deadlocks".

    Further Note: while you hold the lock on a layer, Intuition will block
        on operations such as windowsizing, dragging, menus, and depth
        arranging windows in this layer's screen.  It is recommended that
        YOU do not make Intuition function calls while the layer is locked.
```
INPUTS

    dummy - unused
    l - pointer to a layer
BUGS

SEE ALSO

```c
    [UnlockLayer](autodocs-2.0/layers-library-unlocklayer.md), [LockLayerInfo](autodocs-2.0/layers-library-locklayerinfo.md), [UnlockLayerInfo](autodocs-2.0/layers-library-unlocklayerinfo.md),
    [graphics.library/LockLayerRom](autodocs-2.0/graphics-library-locklayerrom.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md), [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
```

---

## See Also

- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [UnlockLayerInfo — layers.library](../autodocs/layers.library.md#unlocklayerinfo)
