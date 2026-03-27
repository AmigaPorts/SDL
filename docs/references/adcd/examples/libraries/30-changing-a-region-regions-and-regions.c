/* Source: ADCD 2.1
 * Section: 30-changing-a-region-regions-and-regions
 * Library: libraries
 * ADCD reference: libraries/30-changing-a-region-regions-and-regions.md
 */

    BOOL AndRegionRegion( struct Region *srcRegion,
                          struct Region *destRegion );
    BOOL OrRegionRegion ( struct Region *srcRegion,
                          struct Region *destRegion );
    BOOL XorRegionRegion( struct Region *srcRegion,
                          struct Region *destRegion );
    void ClearRegion    ( struct Region *region );
