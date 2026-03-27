# 30 / / Changing a Region / Rectangles and Regions


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
[OrRectRegion()](../Includes_and_Autodocs_2._guide/node0464.html) modifies a region structure by or'ing a clipping rectangle
into the region.  When the application draws through this region (assuming
that the region was originally empty), only the pixels within the clipping
rectangle will be affected. If the region already has drawable areas, they
will still exist, this rectangle is added to the drawable area.

[AndRectRegion()](../Includes_and_Autodocs_2._guide/node0413.html) modifies the region structure by and'ing a clipping
rectangle into the region.  Only those pixels that were already drawable
and within the rectangle will remain drawable, any that are outside of it
will be clipped in future.

[XorRectRegion()](../Includes_and_Autodocs_2._guide/node0490.html) applies the rectangle to the region in an exclusive-or
mode.  Within the given rectangle, any areas that were drawable become
clipped, any areas that were clipped become drawable.  Areas outside of
the rectangle are not affected.

[ClearRectRegion()](../Includes_and_Autodocs_2._guide/node042A.html) clears the rectangle from the region.  Within the given
rectangle, any areas that were drawable become clipped.  Areas outside of
the rectangle are not affected.

