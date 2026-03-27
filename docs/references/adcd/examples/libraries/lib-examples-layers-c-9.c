/* Source: ADCD 2.1
 * Section: lib-examples-layers-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-layers-c.md
 */

    {
    for (ktr = 0; ktr < depth; ktr++)
        {
        if (NULL != bitmap->Planes[ktr])
            FreeRaster(bitmap->Planes[ktr], width, height);
        }

    FreeMem(bitmap, sizeof(*bitmap));
    }
