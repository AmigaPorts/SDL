---
title: 30 Layers Library / Regions
manual: libraries
chapter: libraries
section: 30-layers-library-regions
functions: [AndRectRegion, AndRegionRegion, ClearRectRegion, ClearRegion, DisposeRegion, InstallClipRegion, NewRegion, OrRectRegion, OrRegionRegion, XorRectRegion, XorRegionRegion]
libraries: [graphics.library, layers.library]
---

# 30 Layers Library / Regions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Regions allow the application to install clipping rectangles into layers.
A clipping rectangle is a rectangular area into which the graphics
routines will draw.  All drawing that would fall outside of that
rectangular area is clipped (not rendered).

User clipping regions are linked lists of clipping rectangles created by
an application program through the graphics library routines described
below.  By combining together various clipping rectangles, any arbitrary
clipping shape can be created.  Once the region is set up, you use the
layers library call [InstallClipRegion()](libraries/30-regions-installing-regions.md) to make the clipping region active
in a layer.

Regions are safe to use with layers created by Intuition (i.e., windows).
The following table describes the routines available for the creation,
manipulation and use of regions.


                Table 30-4: Functions Used with Regions
  ____________________________________________________________________
 |                                                                    |
 |          Routine      Library         Description                  |
 |====================================================================|
 |  [InstallClipRegion()](libraries/30-regions-installing-regions.md)  Layers    Add a clipping region to a layer.  |
 |--------------------------------------------------------------------|
 |          [NewRegion()](libraries/30-regions-creating-and-deleting-regions.md)  Graphics  Create a new, empty region.        |
 |      [DisposeRegion()](libraries/30-regions-creating-and-deleting-regions.md)  Graphics  Dispose of an existing region and  |
 |                                 its rectangles.                    |
 |--------------------------------------------------------------------|
 |      [AndRectRegion()](libraries/30-changing-a-region-rectangles-and-regions.md)  Graphics  And a rectangle into a region.     |
 |       [OrRectRegion()](libraries/30-changing-a-region-rectangles-and-regions.md)  Graphics  Or a rectangle into a region.      |
 |      [XorRectRegion()](libraries/30-changing-a-region-rectangles-and-regions.md)  Graphics  Exclusive-or a rectangle into a    |
 |                                 region.                            |
 |    [ClearRectRegion()](libraries/30-changing-a-region-rectangles-and-regions.md)  Graphics  Clear a rectangular portion of a   |
 |                                 region.                            |
 |    [AndRegionRegion()](libraries/30-changing-a-region-regions-and-regions.md)  Graphics  And two regions together.          |
 |     [OrRegionRegion()](libraries/30-changing-a-region-regions-and-regions.md)  Graphics  Or two regions together.           |
 |    [XorRegionRegion()](libraries/30-changing-a-region-regions-and-regions.md)  Graphics  Exclusive-or two regions together. |
 |--------------------------------------------------------------------|
 |        [ClearRegion()](libraries/30-changing-a-region-regions-and-regions.md)  Graphics  Clear a region.                    |
 |____________________________________________________________________|


With these functions, the application can selectively update a
custom-shaped part of a layer without disturbing any of the other layers
that might be present.


```c
    Never Modify the DamageList of a Layer Directly.
    ------------------------------------------------
    Use the routine [InstallClipRegion()](libraries/30-regions-installing-regions.md) to add clipping to the layer.
    The regions installed by InstallClipRegion() are independent of
    the layer's [DamageList](libraries/30-layers-the-layer-structure.md) and use of user clipping regions will not
    interfere with optimized window refreshing.

    Do Not Modify A Region After It Has Been Added.
    -----------------------------------------------
    After a region has been added with [InstallClipRegion()](libraries/30-regions-installing-regions.md), the
    program may not modify it until the region has been removed with
    another call to InstallClipRegion().
```
 [Creating and Deleting Regions](libraries/30-regions-creating-and-deleting-regions.md)    [Changing a Region](libraries/30-regions-changing-a-region.md) 
 [Installing Regions](libraries/30-regions-installing-regions.md)               [Regions Example](libraries/lib-examples-clipping-c.md) 

---

## See Also

- [AndRectRegion — graphics.library](../autodocs/graphics.library.md#andrectregion)
- [AndRegionRegion — graphics.library](../autodocs/graphics.library.md#andregionregion)
- [ClearRectRegion — graphics.library](../autodocs/graphics.library.md#clearrectregion)
- [ClearRegion — graphics.library](../autodocs/graphics.library.md#clearregion)
- [DisposeRegion — graphics.library](../autodocs/graphics.library.md#disposeregion)
- [InstallClipRegion — layers.library](../autodocs/layers.library.md#installclipregion)
- [NewRegion — graphics.library](../autodocs/graphics.library.md#newregion)
- [OrRectRegion — graphics.library](../autodocs/graphics.library.md#orrectregion)
- [OrRegionRegion — graphics.library](../autodocs/graphics.library.md#orregionregion)
- [XorRectRegion — graphics.library](../autodocs/graphics.library.md#xorrectregion)
- [XorRegionRegion — graphics.library](../autodocs/graphics.library.md#xorregionregion)
