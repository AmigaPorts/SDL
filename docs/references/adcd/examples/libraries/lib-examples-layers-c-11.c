/* Source: ADCD 2.1
 * Section: lib-examples-layers-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-layers-c.md
 */

                     M_L, M_T, M_R, M_B, LAYERSMART, NULL)))
    {
    pMessage(msgLayer, "Setting up Layers");

    if (NULL != (theSuperBitMap = allocBitMap(SCREEN_D, SUPER_W, SUPER_H)))
        {
        if (allocLayers(msgLayer, theLayers, theSuperBitMap, theLayerInfo, theBitMap))
            {
            doLayers(msgLayer, theLayers);

            disposeLayers(msgLayer, theLayers);
            }
        disposeBitMap(theSuperBitMap, SCREEN_D, SUPER_W, SUPER_H);
        }
    if (!DeleteLayer(DUMMY, msgLayer))
        error(msgLayer, "Error deleting layer");
    }
