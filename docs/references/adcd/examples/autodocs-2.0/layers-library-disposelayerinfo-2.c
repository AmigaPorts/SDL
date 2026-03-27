/* Source: ADCD 2.1
 * Section: layers-library-disposelayerinfo
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/layers-library-disposelayerinfo.md
 */

    --delete the layers associated this [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure--

    DeleteLayer(li,simple_layer);
    DeleteLayer(li,smart_layer);

    --see documentation on [DeleteLayer](../Includes_and_Autodocs_2._guide/node0394.html) about deleting SuperBitMap layers--
    my_super_bitmap_ptr = super_layer->SuperBitMap;
    DeleteLayer(li,super_layer);

    --now dispose of the [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure itself--
    DisposeLayerInfo(li);
