/* Source: ADCD 2.1
 * Section: 30-changing-a-region-rectangles-and-regions
 * Library: libraries
 * ADCD reference: libraries/30-changing-a-region-rectangles-and-regions.md
 */

    BOOL OrRectRegion   ( struct Region *region,
                          struct Rectangle *rectangle );
    void AndRectRegion  ( struct Region *region,
                          struct Rectangle *rectangle );
    BOOL XorRectRegion  ( struct Region *region,
                          struct Rectangle *rectangle );
    BOOL ClearRectRegion( struct Region *region,
                          struct Rectangle *rectangle );
