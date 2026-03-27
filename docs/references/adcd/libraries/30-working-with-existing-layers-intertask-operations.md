---
title: 30 / / Working With Existing Layers / Intertask Operations
manual: libraries
chapter: libraries
section: 30-working-with-existing-layers-intertask-operations
functions: [BehindLayer, LockLayer, LockLayerInfo, LockLayers, MoveLayer, MoveLayerInFrontOf, ScrollLayer, SizeLayer, UnlockLayer, UnlockLayerInfo, UnlockLayers, UpfrontLayer]
libraries: [layers.library]
---

# 30 / / Working With Existing Layers / Intertask Operations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If multiple tasks are manipulating layers on the same display they will be
sharing a [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure and their use of it and its related data
structures need to be coordinated.  To ensure that a structure remains
cohesive, it should be operated on by only one task at a time.  The
Layer_Info encompasses all the layers existing on a single display.

[LockLayerInfo()](autodocs-2.0/layers-library-locklayerinfo.md) must be called whenever the visible portions of layers may
be affected, or when the [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure is changed.


```c
    void LockLayerInfo( struct Layer_Info *li );
```
The lock should be obtained whenever a layer is created, deleted sized or
moved, as the list of layers that is being managed by the [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) data
structure must be updated.

It is not necessary to lock the [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) data structure while rendering,
or when calling routines like [ScrollLayer()](libraries/30-layers-creating-and-using-new-layers.md), because layer sizes and
on-display positions are not being affected.

Use [UnlockLayerInfo()](autodocs-2.0/layers-library-unlocklayerinfo.md) when you have finished the layer operation:


```c
    void UnlockLayerInfo( struct Layer_Info *li );
```
If you don't unlock the [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) then any other task calling
[LockLayerInfo()](autodocs-2.0/layers-library-locklayerinfo.md) on the same Layer_Info structure will be blocked creating
a potential deadlock situation.

In addition to locking the [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure, the layer itself should
be locked if it is shared between tasks so that only one task at a time
renders graphics to it.  [LockLayer()](autodocs-2.0/layers-library-locklayer.md) is used to get exclusive graphics
output to a layer.


```c
    void LockLayer( long dummy, struct Layer *layer );
```
If a graphics function is in process, the lock will return when the
function is completed.  Other tasks are blocked only if they attempt to
draw graphics into this layer, or try to obtain a lock on this layer. The
[MoveLayer()](libraries/30-layers-creating-and-using-new-layers.md), [SizeLayer()](libraries/30-layers-creating-and-using-new-layers.md) and [ScrollLayer()](libraries/30-layers-creating-and-using-new-layers.md) functions automatically lock
and unlock the layer they operate on.

[UnlockLayer()](autodocs-2.0/layers-library-unlocklayer.md) should be used after the graphics operation to make the
layer available to other tasks again.


```c
    void UnlockLayer( struct Layer *layer );
```
If more than one layer must be locked, then the [LockLayer()](autodocs-2.0/layers-library-locklayer.md) calls should
be surrounded by [LockLayerInfo()](autodocs-2.0/layers-library-locklayerinfo.md) and [UnlockLayerInfo()](autodocs-2.0/layers-library-unlocklayerinfo.md) calls, to prevent
deadlock situations.

The layers library provides two additional functions, [LockLayers()](autodocs-2.0/layers-library-locklayers.md) and
[UnlockLayers()](autodocs-2.0/layers-library-unlocklayers.md), for locking multiple layers.


```c
    void LockLayers( struct Layer_Info *li );
    void UnlockLayers( struct Layer_Info *li );
```
[LockLayers()](autodocs-2.0/layers-library-locklayers.md) is used to lock all layers in a single command.
[UnlockLayers()](autodocs-2.0/layers-library-unlocklayers.md) releases the layers lock.  The system calls these routines
during the [BehindLayer()](libraries/30-layers-creating-and-using-new-layers.md), [UpfrontLayer()](libraries/30-layers-creating-and-using-new-layers.md) and [MoveLayerInFrontOf()](libraries/30-layers-creating-and-using-new-layers.md)
operations ([described below](libraries/30-layers-creating-and-using-new-layers.md)).

---

## See Also

- [BehindLayer — layers.library](../autodocs/layers.library.md#behindlayer)
- [LockLayer — layers.library](../autodocs/layers.library.md#locklayer)
- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [LockLayers — layers.library](../autodocs/layers.library.md#locklayers)
- [MoveLayer — layers.library](../autodocs/layers.library.md#movelayer)
- [MoveLayerInFrontOf — layers.library](../autodocs/layers.library.md#movelayerinfrontof)
- [ScrollLayer — layers.library](../autodocs/layers.library.md#scrolllayer)
- [SizeLayer — layers.library](../autodocs/layers.library.md#sizelayer)
- [UnlockLayer — layers.library](../autodocs/layers.library.md#unlocklayer)
- [UnlockLayerInfo — layers.library](../autodocs/layers.library.md#unlocklayerinfo)
- [UnlockLayers — layers.library](../autodocs/layers.library.md#unlocklayers)
- [UpfrontLayer — layers.library](../autodocs/layers.library.md#upfrontlayer)
