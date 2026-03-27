/* Source: ADCD 2.1
 * Section: 27-monitors-modes-and-the-display-database-preference-items
 * Library: libraries
 * ADCD reference: libraries/27-monitors-modes-and-the-display-database-preference-items.md
 */

    struct DimensionInfo query;

    /* fill the buffer with Mode dimension information */

    if(GetDisplayInfoData(handle, (UBYTE *)&query,sizeof(query),
       DTAG_DIMS,NULL)))
    {
        /* display standard overscan dimensions of this Mode */

        printf("overscan width  = %ld",
                query.StdOScan.MaxX - query.StdOScan.MinX + 1);

        printf("overscan height = %ld",
                query.StdOScan.MaxY - query.StdOScan.MinY + 1);
    }
