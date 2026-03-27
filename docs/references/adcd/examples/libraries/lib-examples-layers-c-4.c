/* Source: ADCD 2.1
 * Section: lib-examples-layers-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-layers-c.md
 */

    {
    if (!SizeLayer(DUMMY,layer_array[ktr],
                SCREEN_W-(layer_array[ktr]->bounds.MaxX)-1,0))
        error(msgLayer, "SizeLayer() failed.");
    }
