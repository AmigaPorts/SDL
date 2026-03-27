---
title: 30 / / Changing a Region / Regions and Regions
manual: libraries
chapter: libraries
section: 30-changing-a-region-regions-and-regions
functions: [AndRegionRegion, ClearRegion, NewRegion, OrRegionRegion, XorRegionRegion]
libraries: [graphics.library]
---

# 30 / / Changing a Region / Regions and Regions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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
[AndRegionRegion()](autodocs-2.0/graphics-library-andregionregion.md) performs a logical and operation on the two regions,
leaving the result in the second region.  The operation leaves drawable
areas wherever the regions drawable areas overlap.  That is, where there
are drawable areas in both region 1 and region 2, there will be drawable
areas left in the result region.

[OrRegionRegion()](autodocs-2.0/graphics-library-orregionregion.md) performs a logical or operation on the two regions,
leaving the result in the second region. The operation leaves drawable
areas wherever there are drawable areas in either region. That is, where
there are drawable areas in either region 1 or region 2, there will be
drawable areas left in the result region.

[XorRegionRegion()](autodocs-2.0/graphics-library-xorregionregion.md) performs a logical exclusive-or operation on the two
regions, leaving the result in the second region.  The operation leaves
drawable areas wherever there are drawable areas in either region but not
both.  That is, where there are drawable areas in either region 1 or
region 2, there will be drawable areas left in the result region.  But
where there are drawable areas in both region 1 and region 2, there will
not be drawable areas left in the result region.

[ClearRegion()](autodocs-2.0/graphics-library-clearregion.md) puts the region back to the same state it was in when the
region was created with [NewRegion()](libraries/30-layers-library-regions.md), that is, no areas are drawable.

---

## See Also

- [AndRegionRegion — graphics.library](../autodocs/graphics.library.md#andregionregion)
- [ClearRegion — graphics.library](../autodocs/graphics.library.md#clearregion)
- [NewRegion — graphics.library](../autodocs/graphics.library.md#newregion)
- [OrRegionRegion — graphics.library](../autodocs/graphics.library.md#orregionregion)
- [XorRegionRegion — graphics.library](../autodocs/graphics.library.md#xorregionregion)
