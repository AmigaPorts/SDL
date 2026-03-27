/* Source: ADCD 2.1
 * Section: lib-examples-rgbboxes-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rgbboxes-c.md
 */

    {
    bitMap.Planes[depth] = (PLANEPTR)AllocRaster(WIDTH, HEIGHT);
    if (bitMap.Planes[depth] == NULL)
        fail("Could not get BitPlanes\n");
    }
