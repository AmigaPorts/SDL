/* Source: ADCD 2.1
 * Section: 27-viewport-size-specifications-viewport-height
 * Library: libraries
 * ADCD reference: libraries/27-viewport-size-specifications-viewport-height.md
 */

    struct DimensionInfo querydims;
    struct Rectangle *oscan;
    struct ViewPort viewport;

    if (GetDisplayInfoData( NULL,(UBYTE *)&querydims,
                            sizeof(struct DimensionInfo),
                            DTAG_DIMS, modeID ))
    {
            /* Use StdOScan instead of MaxOScan to get standard   */
            /* overscan dimensions as set by the user in Overscan */
            /* Preferences                                        */
            oscan = &querydims.MaxOScan;
            viewPort->DHeight = oscan->MaxY - oscan->MinY + 1;
    }
