/* Source: ADCD 2.1
 * Section: lib-examples-rgbboxes-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rgbboxes-c.md
 */

    {
    /* Get ready to attach the ColorMap, Release 2-style */
    vcTags[0].ti_Data = (ULONG) &viewPort;

    /* Attach the color map and Release 2 extended structures */
    if( VideoControl(cm,vcTags) )
        fail("Could not attach extended structures\n");
    }
