---
title: 30 / / Changing a Region / Rectangles and Regions
manual: libraries
chapter: libraries
section: 30-changing-a-region-rectangles-and-regions
functions: [AndRectRegion, ClearRectRegion, OrRectRegion, XorRectRegion]
libraries: [graphics.library]
---

# 30 / / Changing a Region / Rectangles and Regions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are four functions for changing a region through logical operations
with a rectangle.


```c
    BOOL OrRectRegion   ( struct Region *region,
                          struct Rectangle *rectangle );
    void AndRectRegion  ( struct Region *region,
                          struct Rectangle *rectangle );
    BOOL XorRectRegion  ( struct Region *region,
                          struct Rectangle *rectangle );
    BOOL ClearRectRegion( struct Region *region,
                          struct Rectangle *rectangle );
```
[OrRectRegion()](autodocs-2.0/graphics-library-orrectregion.md) modifies a region structure by or'ing a clipping rectangle
into the region.  When the application draws through this region (assuming
that the region was originally empty), only the pixels within the clipping
rectangle will be affected. If the region already has drawable areas, they
will still exist, this rectangle is added to the drawable area.

[AndRectRegion()](autodocs-2.0/graphics-library-andrectregion.md) modifies the region structure by and'ing a clipping
rectangle into the region.  Only those pixels that were already drawable
and within the rectangle will remain drawable, any that are outside of it
will be clipped in future.

[XorRectRegion()](autodocs-2.0/graphics-library-xorrectregion.md) applies the rectangle to the region in an exclusive-or
mode.  Within the given rectangle, any areas that were drawable become
clipped, any areas that were clipped become drawable.  Areas outside of
the rectangle are not affected.

[ClearRectRegion()](autodocs-2.0/graphics-library-clearrectregion.md) clears the rectangle from the region.  Within the given
rectangle, any areas that were drawable become clipped.  Areas outside of
the rectangle are not affected.

---

## See Also

- [AndRectRegion — graphics.library](../autodocs/graphics.library.md#andrectregion)
- [ClearRectRegion — graphics.library](../autodocs/graphics.library.md#clearrectregion)
- [OrRectRegion — graphics.library](../autodocs/graphics.library.md#orrectregion)
- [XorRectRegion — graphics.library](../autodocs/graphics.library.md#xorrectregion)
