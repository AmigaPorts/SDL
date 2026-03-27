/* Source: ADCD 2.1
 * Section: 30-regions-changing-a-region
 * Library: libraries
 * ADCD reference: libraries/30-regions-changing-a-region.md
 */

    extern struct Region *RowRegion;  /* created elsewhere */

    WORD ktr;
    struct Rectangle rect;

    for (ktr = 1; ktr < 6; ktr++)
        {
        rect.MinX = 50;
        rect.MaxX = 315;
        rect.MinY = (ktr * 10) - 5;
        rect.MaxY = (ktr * 10);

        if (!OrRectRegion(RowRegion, &rect))
            clean_exit(RETURN_WARN);
        }
