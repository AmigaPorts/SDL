# 30 / / Changing a Region / Regions and Regions


As with rectangles and regions, there are four layers library functions
for combining regions with regions:


```c
    BOOL AndRegionRegion( struct Region *srcRegion,
                          struct Region *destRegion );
    BOOL OrRegionRegion ( struct Region *srcRegion,
                          struct Region *destRegion );
    BOOL XorRegionRegion( struct Region *srcRegion,
                          struct Region *destRegion );
    void ClearRegion    ( struct Region *region );
```
[AndRegionRegion()](../Includes_and_Autodocs_2._guide/node0414.html) performs a logical and operation on the two regions,
leaving the result in the second region.  The operation leaves drawable
areas wherever the regions drawable areas overlap.  That is, where there
are drawable areas in both region 1 and region 2, there will be drawable
areas left in the result region.

[OrRegionRegion()](../Includes_and_Autodocs_2._guide/node0465.html) performs a logical or operation on the two regions,
leaving the result in the second region. The operation leaves drawable
areas wherever there are drawable areas in either region. That is, where
there are drawable areas in either region 1 or region 2, there will be
drawable areas left in the result region.

[XorRegionRegion()](../Includes_and_Autodocs_2._guide/node0491.html) performs a logical exclusive-or operation on the two
regions, leaving the result in the second region.  The operation leaves
drawable areas wherever there are drawable areas in either region but not
both.  That is, where there are drawable areas in either region 1 or
region 2, there will be drawable areas left in the result region.  But
where there are drawable areas in both region 1 and region 2, there will
not be drawable areas left in the result region.

[ClearRegion()](../Includes_and_Autodocs_2._guide/node042B.html) puts the region back to the same state it was in when the
region was created with [NewRegion()](../Libraries_Manual_guide/node03F8.html#line23), that is, no areas are drawable.

