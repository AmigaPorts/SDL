---
title: 30 / Layers / Creating and Using New Layers
manual: libraries
chapter: libraries
section: 30-layers-creating-and-using-new-layers
functions: [BeginUpdate, BehindLayer, CreateBehindLayer, CreateUpfrontLayer, DeleteLayer, DisposeLayerInfo, EndUpdate, MoveLayer, MoveLayerInFrontOf, NewLayerInfo, ScrollLayer, SizeLayer, SwapBitsRastPortClipRect, UpfrontLayer]
libraries: [layers.library]
---

# 30 / Layers / Creating and Using New Layers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The functions described in this section are generally not safe to use with
Intuition.  To create new layers for Intuition you use Intuition window
calls (see the "[Intuition Windows](libraries/4-intuition-windows-basic-window-structures-and-functions.md)" chapter earlier in this book).

Only applications that create and mange their own [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) will be able to
call the layer creation and updating functions discussed here.


         Table 30-3: Functions for Creating and Updating Layers
   ___________________________________________________________________
  |                                                                   |
  |              [NewLayerInfo()](libraries/30-allocating-and-deallocating-layer-info.md)  Allocating a [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure.   |
  |          [DisposeLayerInfo()](libraries/30-allocating-and-deallocating-layer-info.md)  Deallocating a Layer_Info structure. |
  |-------------------------------------------------------------------|
  |        [CreateUpfrontLayer()](libraries/30-creating-and-using-layers-allocating-and-deallocating.md)  Make a new layer in front of others. |
  |         [CreateBehindLayer()](libraries/30-creating-and-using-layers-allocating-and-deallocating.md)  Make a new layer behind others.      |
  |               [DeleteLayer()](libraries/30-creating-and-using-layers-allocating-and-deallocating.md)  Remove and delete an existing layer. |
  |-------------------------------------------------------------------|
  |                 [MoveLayer()](libraries/30-creating-and-using-new-layers-moving-and-sizing-layers.md)  Change the position (not depth) of a |
  |                              layer.                               |
  |                 [SizeLayer()](libraries/30-creating-and-using-new-layers-moving-and-sizing-layers.md)  Change the size of a layer.          |
  |               [ScrollLayer()](libraries/30-creating-and-using-new-layers-changing-a-viewpoint.md)  Change the internal coordinates of a |
  |                              layer.                               |
  |-------------------------------------------------------------------|
  |               [BehindLayer()](libraries/30-creating-and-using-new-layers-reordering-layers.md)  Depth arrange a layer behind others. |
  |              [UpfrontLayer()](libraries/30-creating-and-using-new-layers-reordering-layers.md)  Depth arrange a layer in front of    |
  |                              others.                              |
  |        [MoveLayerInFrontOf()](libraries/30-creating-and-using-new-layers-reordering-layers.md)  Depth arrange a layer to a specific  |
  |                              position.                            |
  |-------------------------------------------------------------------|
  |  [SwapBitsRastPortClipRect()](libraries/30-creating-and-using-new-layers-sub-layer-rectangle.md)  Fast, non-layered and non-damaging   |
  |                              display operation.                   |
  |-------------------------------------------------------------------|
  |               [BeginUpdate()](libraries/30-creating-and-using-new-layers-reordering-layers.md)  Synchronize optimized refreshing for |
  |                              layer.                               |
  |                 [EndUpdate()](libraries/30-creating-and-using-new-layers-reordering-layers.md)  End optimized layer refresh.         |
  |___________________________________________________________________|


 [Creating a Viewing Workspace](libraries/30-creating-and-using-new-layers-creating-a-viewing.md) 
 [Creating the Layers](libraries/30-creating-and-using-new-layers-creating-the-layers.md) 
 [Allocating and Deallocating Layer_Info](libraries/30-allocating-and-deallocating-layer-info.md) 
 [Allocating and Deallocating Layers](libraries/30-creating-and-using-layers-allocating-and-deallocating.md) 
 [Moving and Sizing Layers](libraries/30-creating-and-using-new-layers-moving-and-sizing-layers.md) 
 [Changing a Viewpoint](libraries/30-creating-and-using-new-layers-changing-a-viewpoint.md) 
 [Reordering Layers](libraries/30-creating-and-using-new-layers-reordering-layers.md) 
 [Sub-Layer Rectangle Operations](libraries/30-creating-and-using-new-layers-sub-layer-rectangle.md) 

---

## See Also

- [BeginUpdate — layers.library](../autodocs/layers.library.md#beginupdate)
- [BehindLayer — layers.library](../autodocs/layers.library.md#behindlayer)
- [CreateBehindLayer — layers.library](../autodocs/layers.library.md#createbehindlayer)
- [CreateUpfrontLayer — layers.library](../autodocs/layers.library.md#createupfrontlayer)
- [DeleteLayer — layers.library](../autodocs/layers.library.md#deletelayer)
- [DisposeLayerInfo — layers.library](../autodocs/layers.library.md#disposelayerinfo)
- [EndUpdate — layers.library](../autodocs/layers.library.md#endupdate)
- [MoveLayer — layers.library](../autodocs/layers.library.md#movelayer)
- [MoveLayerInFrontOf — layers.library](../autodocs/layers.library.md#movelayerinfrontof)
- [NewLayerInfo — layers.library](../autodocs/layers.library.md#newlayerinfo)
- [ScrollLayer — layers.library](../autodocs/layers.library.md#scrolllayer)
- [SizeLayer — layers.library](../autodocs/layers.library.md#sizelayer)
- [SwapBitsRastPortClipRect — layers.library](../autodocs/layers.library.md#swapbitsrastportcliprect)
- [UpfrontLayer — layers.library](../autodocs/layers.library.md#upfrontlayer)
