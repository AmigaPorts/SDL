/* Source: ADCD 2.1
 * Section: 27-the-rastport-structure-initializing-a-rastport-structure
 * Library: libraries
 * ADCD reference: libraries/27-the-rastport-structure-initializing-a-rastport-structure.md
 */

    struct BitMap bitMap = {0};
    struct RastPort rastPort = {0};

    /* Initialize the RastPort and link the BitMap to it. */
    InitRastPort(&rastPort);
    rastPort.BitMap = &bitMap;


    Initialize, Then Link.
    ----------------------
    You cannot link the bitmap in until after the [RastPort](../Libraries_Manual_guide/node034A.html) has been
    initialized.
