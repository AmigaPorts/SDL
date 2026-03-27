---
title: 30 Layers Library / Function Reference
manual: libraries
chapter: libraries
section: 30-layers-library-function-reference
functions: [AndRectRegion, AndRegionRegion, AttemptLockLayerRom, BeginUpdate, BehindLayer, ClearRectRegion, ClearRegion, CreateBehindLayer, CreateUpfrontLayer, DeleteLayer, DisposeLayerInfo, DisposeRegion, EndUpdate, InstallClipRegion, LockLayer, LockLayerInfo, LockLayerRom, LockLayers, MoveLayer, MoveLayerInFrontOf, NewLayerInfo, NewRegion, OrRectRegion, OrRegionRegion, ScrollLayer, SizeLayer, SwapBitsRastPortClipRect, UnlockLayer, UnlockLayerInfo, UnlockLayerRom, UnlockLayers, UpfrontLayer, WhichLayer, XorRectRegion, XorRegionRegion]
libraries: [graphics.library, layers.library]
---

# 30 Layers Library / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the layers library functions and
related routines from the graphics library.  See the Amiga ROM Kernel
Reference Manual: Includes and Autodocs for details on each function call.


                  Table 30-5: Layers Library Functions
  ______________________________________________________________________
 |                                                                      |
 |              Function                   Description                  |
 |======================================================================|
 |              [NewLayerInfo()](autodocs-2.0/layers-library-newlayerinfo.md)  Allocating a [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure.      |
 |          [DisposeLayerInfo()](autodocs-2.0/layers-library-disposelayerinfo.md)  Deallocating a Layer_Info structure.    |
 |----------------------------------------------------------------------|
 |        [CreateUpfrontLayer()](autodocs-2.0/layers-library-createupfrontlayer.md)  Make a new layer in front of others.    |
 |         [CreateBehindLayer()](autodocs-2.0/layers-library-createbehindlayer.md)  Make a new layer behind others.         |
 |               [DeleteLayer()](autodocs-2.0/layers-library-deletelayer.md)  Remove and delete an existing layer.    |
 |----------------------------------------------------------------------|
 |                 [MoveLayer()](autodocs-2.0/layers-library-movelayer.md)  Change the position (not depth) of a    |
 |                              layer.                                  |
 |                 [SizeLayer()](autodocs-2.0/layers-library-sizelayer.md)  Change the size of a layer.             |
 |               [ScrollLayer()](autodocs-2.0/layers-library-scrolllayer.md)  Change the internal coordinates of a    |
 |                              layer.                                  |
 |----------------------------------------------------------------------|
 |               [BehindLayer()](autodocs-2.0/layers-library-behindlayer.md)  Depth arrange a layer behind others.    |
 |              [UpfrontLayer()](autodocs-2.0/layers-library-upfrontlayer.md)  Depth arrange a layer in front of       |
 |                              others.                                 |
 |        [MoveLayerInFrontOf()](autodocs-2.0/layers-library-movelayerinfrontof.md)  Depth arrange a layer to a specific     |
 |                              position.                               |
 |----------------------------------------------------------------------|
 |                [WhichLayer()](autodocs-2.0/layers-library-whichlayer.md)  Find the frontmost layer at a position. |
 |----------------------------------------------------------------------|
 |  [SwapBitsRastPortClipRect()](autodocs-2.0/layers-library-swapbitsrastportcliprect.md)  Fast, non-layered and non-damaging      |
 |                              display operation.                      |
 |----------------------------------------------------------------------|
 |               [BeginUpdate()](autodocs-2.0/layers-library-beginupdate.md)  Synchronize optimized refreshing for    |
 |                              layer.                                  |
 |                 [EndUpdate()](autodocs-2.0/layers-library-endupdate.md)  End optimized layer refresh.            |
 |----------------------------------------------------------------------|
 |                 [LockLayer()](autodocs-2.0/layers-library-locklayer.md)  Lock out rendering in a single layer.   |
 |               [UnlockLayer()](autodocs-2.0/layers-library-unlocklayer.md)  Release LockLayer() lock.               |
 |                [LockLayers()](autodocs-2.0/layers-library-locklayers.md)  Lock out rendering in all layers of a   |
 |                              display.                                |
 |              [UnlockLayers()](autodocs-2.0/layers-library-unlocklayers.md)  Release LockLayers() lock.              |
 |             [LockLayerInfo()](autodocs-2.0/layers-library-locklayerinfo.md)  Gain exclusive access to the display's  |
 |                              layers.                                 |
 |           [UnlockLayerInfo()](autodocs-2.0/layers-library-unlocklayerinfo.md)  Release LockLayerInfo() lock.           |
 |----------------------------------------------------------------------|
 |         [InstallClipRegion()](autodocs-2.0/layers-library-installclipregion.md)  Add a clipping region to a layer.       |
 |______________________________________________________________________|


The following routines from graphics library are also required for certain
layers library functions:

  ______________________________________________________________________
 |                                                                      |
 |            Routine                        Description                |
 |======================================================================|
 |         [LockLayerRom()](autodocs-2.0/graphics-library-locklayerrom.md)  Same as LockLayer(), from layers library.    |
 |       [UnlockLayerRom()](autodocs-2.0/graphics-library-unlocklayerrom.md)  Release LockLayerRom() lock.                 |
 |  [AttemptLockLayerRom()](autodocs-2.0/graphics-library-attemptlocklayerrom.md)  Lock layer only if it is immediately         |
 |                         available.                                   |
 |----------------------------------------------------------------------|
 |            [NewRegion()](autodocs-2.0/graphics-library-newregion.md)  Create a new, empty region.                  |
 |        [DisposeRegion()](autodocs-2.0/graphics-library-disposeregion.md)  Dispose of an existing region and its        |
 |                         rectangles.                                  |
 |----------------------------------------------------------------------|
 |        [AndRectRegion()](autodocs-2.0/graphics-library-andrectregion.md)  AND a rectangle into a region.               |
 |         [OrRectRegion()](autodocs-2.0/graphics-library-orrectregion.md)  OR a rectangle into a region.                |
 |        [XorRectRegion()](autodocs-2.0/graphics-library-xorrectregion.md)  Exclusive-OR a rectangle into a region.      |
 |      [ClearRectRegion()](autodocs-2.0/graphics-library-clearrectregion.md)  Clear a region.                              |
 |      [AndRegionRegion()](autodocs-2.0/graphics-library-andregionregion.md)  AND two regions together.                    |
 |       [OrRegionRegion()](autodocs-2.0/graphics-library-orregionregion.md)  OR two regions together.                     |
 |      [XorRegionRegion()](autodocs-2.0/graphics-library-xorregionregion.md)  Exclusive-OR two regions together.           |
 |          [ClearRegion()](autodocs-2.0/graphics-library-clearregion.md)  Clear a region.                              |
 |______________________________________________________________________|

---

## See Also

- [AndRectRegion — graphics.library](../autodocs/graphics.library.md#andrectregion)
- [AndRegionRegion — graphics.library](../autodocs/graphics.library.md#andregionregion)
- [AttemptLockLayerRom — graphics.library](../autodocs/graphics.library.md#attemptlocklayerrom)
- [BeginUpdate — layers.library](../autodocs/layers.library.md#beginupdate)
- [BehindLayer — layers.library](../autodocs/layers.library.md#behindlayer)
- [ClearRectRegion — graphics.library](../autodocs/graphics.library.md#clearrectregion)
- [ClearRegion — graphics.library](../autodocs/graphics.library.md#clearregion)
- [CreateBehindLayer — layers.library](../autodocs/layers.library.md#createbehindlayer)
- [CreateUpfrontLayer — layers.library](../autodocs/layers.library.md#createupfrontlayer)
- [DeleteLayer — layers.library](../autodocs/layers.library.md#deletelayer)
- [DisposeLayerInfo — layers.library](../autodocs/layers.library.md#disposelayerinfo)
- [DisposeRegion — graphics.library](../autodocs/graphics.library.md#disposeregion)
- [EndUpdate — layers.library](../autodocs/layers.library.md#endupdate)
- [InstallClipRegion — layers.library](../autodocs/layers.library.md#installclipregion)
- [LockLayer — layers.library](../autodocs/layers.library.md#locklayer)
- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [LockLayerRom — graphics.library](../autodocs/graphics.library.md#locklayerrom)
- [LockLayers — layers.library](../autodocs/layers.library.md#locklayers)
- [MoveLayer — layers.library](../autodocs/layers.library.md#movelayer)
- [MoveLayerInFrontOf — layers.library](../autodocs/layers.library.md#movelayerinfrontof)
- [NewLayerInfo — layers.library](../autodocs/layers.library.md#newlayerinfo)
- [NewRegion — graphics.library](../autodocs/graphics.library.md#newregion)
- [OrRectRegion — graphics.library](../autodocs/graphics.library.md#orrectregion)
- [OrRegionRegion — graphics.library](../autodocs/graphics.library.md#orregionregion)
- [ScrollLayer — layers.library](../autodocs/layers.library.md#scrolllayer)
- [SizeLayer — layers.library](../autodocs/layers.library.md#sizelayer)
- [SwapBitsRastPortClipRect — layers.library](../autodocs/layers.library.md#swapbitsrastportcliprect)
- [UnlockLayer — layers.library](../autodocs/layers.library.md#unlocklayer)
- [UnlockLayerInfo — layers.library](../autodocs/layers.library.md#unlocklayerinfo)
- [UnlockLayerRom — graphics.library](../autodocs/graphics.library.md#unlocklayerrom)
- [UnlockLayers — layers.library](../autodocs/layers.library.md#unlocklayers)
- [UpfrontLayer — layers.library](../autodocs/layers.library.md#upfrontlayer)
- [WhichLayer — layers.library](../autodocs/layers.library.md#whichlayer)
- [XorRectRegion — graphics.library](../autodocs/graphics.library.md#xorrectregion)
- [XorRegionRegion — graphics.library](../autodocs/graphics.library.md#xorregionregion)
