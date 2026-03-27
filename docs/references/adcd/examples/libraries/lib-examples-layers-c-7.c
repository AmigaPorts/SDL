/* Source: ADCD 2.1
 * Section: lib-examples-layers-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-layers-c.md
 */

    {
    if (layer_array[ktr] != NULL)
        {
        if (!DeleteLayer(DUMMY, layer_array[ktr]))
            error(msgLayer, "Error deleting layer");
        }
    }
