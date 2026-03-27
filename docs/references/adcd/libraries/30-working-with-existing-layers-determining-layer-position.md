---
title: 30 / / Working With Existing Layers / Determining Layer Position
manual: libraries
chapter: libraries
section: 30-working-with-existing-layers-determining-layer-position
functions: [LockLayerInfo, UnlockLayerInfo, WhichLayer]
libraries: [layers.library]
---

# 30 / / Working With Existing Layers / Determining Layer Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If the viewing area has been separated into several layers, the
application may need to find out which layer is topmost at a particular
x,y coordinate.  Use the [WhichLayer()](autodocs-2.0/layers-library-whichlayer.md) function for this:


```c
    struct Layer *WhichLayer( struct Layer_Info *li, long x, long y );
```
To be sure that no task adds, deletes, or changes the sequence of layers
before this information is used, call [LockLayerInfo()](libraries/30-layers-working-with-existing-layers.md) before calling
[WhichLayer()](autodocs-2.0/layers-library-whichlayer.md), and call [UnlockLayerInfo()](libraries/30-layers-working-with-existing-layers.md) when the operation is complete.
In this way, the program may ensure that it is acting on valid
information.  Always check for a NULL return value (coordinate not in a
layer) from WhichLayer().

---

## See Also

- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [UnlockLayerInfo — layers.library](../autodocs/layers.library.md#unlocklayerinfo)
- [WhichLayer — layers.library](../autodocs/layers.library.md#whichlayer)
