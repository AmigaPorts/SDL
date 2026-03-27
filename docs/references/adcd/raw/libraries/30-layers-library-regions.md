# 30 Layers Library / Regions


Regions allow the application to install clipping rectangles into layers.
A clipping rectangle is a rectangular area into which the graphics
routines will draw.  All drawing that would fall outside of that
rectangular area is clipped (not rendered).

User clipping regions are linked lists of clipping rectangles created by
an application program through the graphics library routines described
below.  By combining together various clipping rectangles, any arbitrary
clipping shape can be created.  Once the region is set up, you use the
layers library call [InstallClipRegion()](../Libraries_Manual_guide/node03FA.html) to make the clipping region active
in a layer.

Regions are safe to use with layers created by Intuition (i.e., windows).
The following table describes the routines available for the creation,
manipulation and use of regions.


                Table 30-4: Functions Used with Regions
  ____________________________________________________________________
 |                                                                    |
 |          Routine      Library         Description                  |
 |====================================================================|
 |  [InstallClipRegion()](../Libraries_Manual_guide/node03FA.html)  Layers    Add a clipping region to a layer.  |
 |--------------------------------------------------------------------|
 |          [NewRegion()](../Libraries_Manual_guide/node03F9.html)  Graphics  Create a new, empty region.        |
 |      [DisposeRegion()](../Libraries_Manual_guide/node03F9.html#line9)  Graphics  Dispose of an existing region and  |
 |                                 its rectangles.                    |
 |--------------------------------------------------------------------|
 |      [AndRectRegion()](../Libraries_Manual_guide/node03FC.html)  Graphics  And a rectangle into a region.     |
 |       [OrRectRegion()](../Libraries_Manual_guide/node03FC.html)  Graphics  Or a rectangle into a region.      |
 |      [XorRectRegion()](../Libraries_Manual_guide/node03FC.html)  Graphics  Exclusive-or a rectangle into a    |
 |                                 region.                            |
 |    [ClearRectRegion()](../Libraries_Manual_guide/node03FC.html)  Graphics  Clear a rectangular portion of a   |
 |                                 region.                            |
 |    [AndRegionRegion()](../Libraries_Manual_guide/node03FD.html)  Graphics  And two regions together.          |
 |     [OrRegionRegion()](../Libraries_Manual_guide/node03FD.html)  Graphics  Or two regions together.           |
 |    [XorRegionRegion()](../Libraries_Manual_guide/node03FD.html)  Graphics  Exclusive-or two regions together. |
 |--------------------------------------------------------------------|
 |        [ClearRegion()](../Libraries_Manual_guide/node03FD.html)  Graphics  Clear a region.                    |
 |____________________________________________________________________|


With these functions, the application can selectively update a
custom-shaped part of a layer without disturbing any of the other layers
that might be present.


```c
    Never Modify the DamageList of a Layer Directly.
    ------------------------------------------------
    Use the routine [InstallClipRegion()](../Libraries_Manual_guide/node03FA.html) to add clipping to the layer.
    The regions installed by InstallClipRegion() are independent of
    the layer's [DamageList](../Libraries_Manual_guide/node03E4.html#line21) and use of user clipping regions will not
    interfere with optimized window refreshing.

    Do Not Modify A Region After It Has Been Added.
    -----------------------------------------------
    After a region has been added with [InstallClipRegion()](../Libraries_Manual_guide/node03FA.html), the
    program may not modify it until the region has been removed with
    another call to InstallClipRegion().
```
 [Creating and Deleting Regions](../Libraries_Manual_guide/node03F9.html)    [Changing a Region](../Libraries_Manual_guide/node03FB.html) 
 [Installing Regions](../Libraries_Manual_guide/node03FA.html)               [Regions Example](../Libraries_Manual_guide/node05C6.html) 

