/* Source: ADCD 2.1
 * Section: lib-examples-layers-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-layers-c.md
 */

    {
    InitBitMap(bitmap,depth,width,height);

    for (ktr = 0; ktr < depth; ktr++)
        {
        if (NULL == (bitmap->Planes[ktr] = (PLANEPTR)AllocRaster(width,height)))
            bit_map_failed = TRUE;
        else
            BltClear(bitmap->Planes[ktr], RASSIZE(width,height), 1);
        }
    if (bit_map_failed)
        {
        disposeBitMap(bitmap,depth,width,height);
        bitmap = NULL;
        }
    }
