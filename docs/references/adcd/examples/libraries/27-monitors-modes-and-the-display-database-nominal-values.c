/* Source: ADCD 2.1
 * Section: 27-monitors-modes-and-the-display-database-nominal-values
 * Library: libraries
 * ADCD reference: libraries/27-monitors-modes-and-the-display-database-nominal-values.md
 */

    struct DimensionInfo query;

    /* fill the buffer with Mode dimension information */

    if(GetDisplayInfoData(handle, (UBYTE *)&query,sizeof(query),
       DTAG_DIMS,NULL)))
    {
        /* display Nominal dimensions of this Mode */

        printf("nominal width  = %ld",
                query.Nominal.MaxX - query.Nominal.MinX + 1);

        printf("nominal height = %ld",
                query.Nominal.MaxY - query.Nominal.MinY + 1);
    }
