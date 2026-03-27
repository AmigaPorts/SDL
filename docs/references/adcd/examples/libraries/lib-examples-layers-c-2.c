/* Source: ADCD 2.1
 * Section: lib-examples-layers-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-layers-c.md
 */

    {
    if (!MoveLayer(DUMMY, layer_array[1], 0, 1))
        error(msgLayer, "MoveLayer() failed.");
    if (!MoveLayer(DUMMY, layer_array[2], 0, 2))
        error(msgLayer, "MoveLayer() failed.");
    }
