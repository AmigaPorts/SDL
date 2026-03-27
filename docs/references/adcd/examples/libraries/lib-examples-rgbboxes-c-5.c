/* Source: ADCD 2.1
 * Section: lib-examples-rgbboxes-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rgbboxes-c.md
 */

    {
    for (depth=0; depth<DEPTH; depth++)        /*  Two planes.   */
        {
        displaymem = bitMap.Planes[depth] + boxoffsets[box-1];
        drawFilledBox(box, depth);
        }
    }
