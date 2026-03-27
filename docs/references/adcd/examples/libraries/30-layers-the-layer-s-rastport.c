/* Source: ADCD 2.1
 * Section: 30-layers-the-layer-s-rastport
 * Library: libraries
 * ADCD reference: libraries/30-layers-the-layer-s-rastport.md
 */

    struct RastPort *myRPort;
        /* allocate a RastPort pointer for each layer */

    myRPort = layer->rp;

    /* The layer's RastPort may be used with any of the graphics library
    ** calls that require this structure.  For instance, to fill layer
    ** with color:
    */
    SetRast(layer->rp, color);

    /* set up for writing text into layer */
    SetDrMd(layer->rp,JAM1);
    SetAPen(layer->rp,0);
    Move(layer->rp, 5, 7);

    /* write into layer */
    Text(layer->rp, string, strlen(string));
