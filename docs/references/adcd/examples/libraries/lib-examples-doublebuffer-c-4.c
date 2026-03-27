/* Source: ADCD 2.1
 * Section: lib-examples-doublebuffer-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-doublebuffer-c.md
 */

    {
    bitMap->Planes[plane_num] = (PLANEPTR)AllocRaster(width, height);
    if (bitMap->Planes[plane_num] != NULL )
        BltClear(bitMap->Planes[plane_num], (width / 8) * height, 1);
    else
        {
        freePlanes(bitMap, depth, width, height);
        return(NULL);
        }
    }
