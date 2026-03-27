/* Source: ADCD 2.1
 * Section: layers-library-disposelayerinfo
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/layers-library-disposelayerinfo.md
 */

    return LayerInfo and any other memory attached to this LayerInfo
    to memory allocator.

    Note: if you wish to delete the layers associated with this [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33)
        structure, remember to call [DeleteLayer()](../Includes_and_Autodocs_2._guide/node0394.html) for each of the layers
        before calling DisposeLayerInfo().
