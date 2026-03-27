/* Source: ADCD 2.1
 * Section: 27-viewport-size-specifications-viewport-width
 * Library: libraries
 * ADCD reference: libraries/27-viewport-size-specifications-viewport-width.md
 */

    struct DimensionInfo querydims;
    struct Rectangle *oscan;
    struct ViewPort viewport;

    /* Use PAL_MONITOR_ID instead of NTSC_MONITOR_ID to get PAL   */
    /* dimensions                                                 */
    if (GetDisplayInfoData( NULL,(UBYTE *)&querydims, sizeof(querydims),
        DTAG_DIMS, NTSC_MONITOR_ID|HIRES_KEY ))
    {
            /* Use StdOScan instead of MaxOScan to get standard   */
            /* overscan dimensions as set by the user in Overscan */
            /* Preferences                                        */
            oscan = &querydims.MaxOScan;
            viewPort->DWidth = oscan->MaxX - oscan->MinX + 1;
    }
