/* Source: ADCD 2.1
 * Section: 30-creating-and-using-new-layers-creating-the-layers
 * Library: libraries
 * ADCD reference: libraries/30-creating-and-using-new-layers-creating-the-layers.md
 */

    struct Layer_Info *theLayerInfo;

    if (NULL != (theLayerInfo = NewLayerInfo()))
        {
        /* use Layer_Info */

        DisposeLayerInfo(theLayerInfo);
        }
