/* Source: ADCD 2.1
 * Section: lib-examples-clipping-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-clipping-c.md
 */

    {
    if (FALSE == OrRectRegion(new_region, &my_rectangle))
        {
        DisposeRegion(new_region);
        new_region = NULL;
        }
    }
