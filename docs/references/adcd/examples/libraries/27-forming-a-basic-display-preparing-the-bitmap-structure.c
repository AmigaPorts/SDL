/* Source: ADCD 2.1
 * Section: 27-forming-a-basic-display-preparing-the-bitmap-structure
 * Library: libraries
 * ADCD reference: libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md
 */

    /*  Init BitMap for RasInfo.  */
    InitBitMap(&bitMap, DEPTH, WIDTH, HEIGHT);

    /* Set the plane pointers to NULL so the cleanup routine will know */
    /* if they were used. */
    for(depth=0; depth<DEPTH; depth++)
        bitMap.Planes[depth] = NULL;

    /*  Allocate space for BitMap.  */
    for(depth=0; depth<DEPTH; depth++)
        {
        bitMap.Planes[depth] = (PLANEPTR)AllocRaster(WIDTH, HEIGHT);
        if (bitMap.Planes[depth] == NULL)
            cleanExit(RETURN_WARN);
        }
