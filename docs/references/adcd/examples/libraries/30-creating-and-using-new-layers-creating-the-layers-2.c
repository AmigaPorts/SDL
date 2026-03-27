/* Source: ADCD 2.1
 * Section: 30-creating-and-using-new-layers-creating-the-layers
 * Library: libraries
 * ADCD reference: libraries/30-creating-and-using-new-layers-creating-the-layers.md
 */

    struct Layer      *layer;
    struct Layer_Info *theLayerInfo;
    struct BitMap     *theBitMap;

    /* requests construction of a smart refresh layer. */
    if (NULL == (layer = CreateUpfrontLayer(theLayerInfo, theBitMap,
              20, 20, 100, 80, LAYERSMART, NULL)))
        error("CreateUpfrontLayer() failed.");
    else
        {
        ; /* layer successfully created here. */
        }
