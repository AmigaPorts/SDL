/* Source: ADCD 2.1
 * Section: lib-examples-rgbboxes-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rgbboxes-c.md
 */

    {
    for(width=0 ; width < boxWidth; width++)
        *displaymem++ = value;

    displaymem += (bitMap.BytesPerRow - boxWidth);
    }
