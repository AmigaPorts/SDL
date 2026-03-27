/* Source: ADCD 2.1
 * Section: lib-examples-layers-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-layers-c.md
 */

     (ktr < 3) && (create_layer_ok);
     ktr++)
    {
    pMessage(msgLayer, "Create BehindLayer");
    if (ktr == 0)
        {
        if ((layer_array[ktr] = CreateBehindLayer(theLayerInfo, theBitMap,
                  W_L+(ktr*30), W_T+(ktr*30), W_R+(ktr*30), W_B+(ktr*30),
                  theLayerFlags[ktr], super_bitmap)) == NULL)
            create_layer_ok = FALSE;
        }
     else
        {
        if ((layer_array[ktr] = CreateBehindLayer(theLayerInfo, theBitMap,
                  W_L+(ktr*30), W_T+(ktr*30), W_R+(ktr*30), W_B+(ktr*30),
                  theLayerFlags[ktr], NULL)) == NULL)
            create_layer_ok = FALSE;
        }

    if (create_layer_ok)
        {
        pMessage(msgLayer, "Fill the RastPort");
        SetRast(layer_array[ktr]->rp, ktr + 1);
        }
    }
