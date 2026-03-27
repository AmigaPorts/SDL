/* Source: ADCD 2.1
 * Section: lib-examples-layers-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-layers-c.md
 */

    {
    for(ktr_2 = 0; ktr_2 < 3; ktr_2++)
        {
        if (!SizeLayer(DUMMY, layer_array[ktr_2], 1, 1))
            error(msgLayer, "SizeLayer() failed.");
        }
    }
