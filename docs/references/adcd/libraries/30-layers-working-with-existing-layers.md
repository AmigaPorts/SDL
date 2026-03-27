---
title: 30 / Layers / Working With Existing Layers
manual: libraries
chapter: libraries
section: 30-layers-working-with-existing-layers
functions: [AttemptLockLayerRom, LockLayer, LockLayerInfo, LockLayerRom, LockLayers, UnlockLayer, UnlockLayerInfo, UnlockLayerRom, UnlockLayers]
libraries: [graphics.library, layers.library]
---

# 30 / Layers / Working With Existing Layers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A common operation performed by applications is to render text or graphics
into an existing layer such as an Intuition window.  To prevent Intuition
from changing the layer (for instance when the user resizes or moves the
window) during a series of graphic operations, the layers library provides
locking functions for obtaining exclusive access to a layer.

These locking functions are also useful for applications that create their
own layers if the application has more than one task operating on the
layers asynchronously.  These calls coordinate multiple access to layers.


  Table 30-1: Functions for Intertask Control of Layers (Layers Library)
   ____________________________________________________________________
  |                                                                    |
  |        [LockLayer()](libraries/30-working-with-existing-layers-intertask-operations.md)  Lock out rendering in a single layer.          |
  |      [UnlockLayer()](libraries/30-working-with-existing-layers-intertask-operations.md)  Release LockLayer() lock.                      |
  |       [LockLayers()](libraries/30-working-with-existing-layers-intertask-operations.md)  Lock out rendering in all layers of a display. |
  |     [UnlockLayers()](libraries/30-working-with-existing-layers-intertask-operations.md)  Release LockLayers() lock.                     |
  |    [LockLayerInfo()](libraries/30-working-with-existing-layers-intertask-operations.md)  Gain exclusive access to the display's layers. |
  |  [UnlockLayerInfo()](libraries/30-working-with-existing-layers-intertask-operations.md)  Release LockLayerInfo() lock.                  |
  |____________________________________________________________________|


The following routines from the graphics library also allow multitasking
access to layer structures:


 Table 30-2: Functions for Intertask Control of Layers (Graphics Library)
   ____________________________________________________________________
  |                                                                    |
  |         [LockLayerRom()](autodocs-2.0/graphics-library-locklayerrom.md)  Same as [LockLayer()](libraries/30-working-with-existing-layers-intertask-operations.md), from layers library.  |
  |       [UnlockLayerRom()](autodocs-2.0/graphics-library-unlocklayerrom.md)  Release LockLayerRom() lock.               |
  |  [AttemptLockLayerRom()](autodocs-2.0/graphics-library-attemptlocklayerrom.md)  Lock layer only if it is immediately       |
  |                         available.                                 |
  |____________________________________________________________________|


These functions are similar to the layers [LockLayer()](libraries/30-working-with-existing-layers-intertask-operations.md) and [UnlockLayer()](libraries/30-working-with-existing-layers-intertask-operations.md)
functions, but do not require the layers library to be open.  See the
Amiga ROM Kernel Reference Manual: Includes and Autodocs for details.

 [Intertask Operations](libraries/30-working-with-existing-layers-intertask-operations.md)    [Determining Layer Position](libraries/30-working-with-existing-layers-determining-layer-position.md) 

---

## See Also

- [AttemptLockLayerRom — graphics.library](../autodocs/graphics.library.md#attemptlocklayerrom)
- [LockLayer — layers.library](../autodocs/layers.library.md#locklayer)
- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [LockLayerRom — graphics.library](../autodocs/graphics.library.md#locklayerrom)
- [LockLayers — layers.library](../autodocs/layers.library.md#locklayers)
- [UnlockLayer — layers.library](../autodocs/layers.library.md#unlocklayer)
- [UnlockLayerInfo — layers.library](../autodocs/layers.library.md#unlocklayerinfo)
- [UnlockLayerRom — graphics.library](../autodocs/graphics.library.md#unlocklayerrom)
- [UnlockLayers — layers.library](../autodocs/layers.library.md#unlocklayers)
