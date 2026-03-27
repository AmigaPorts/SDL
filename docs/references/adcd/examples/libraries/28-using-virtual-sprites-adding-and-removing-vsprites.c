/* Source: ADCD 2.1
 * Section: 28-using-virtual-sprites-adding-and-removing-vsprites
 * Library: libraries
 * ADCD reference: libraries/28-using-virtual-sprites-adding-and-removing-vsprites.md
 */

    struct VSprite  myVSprite = {0};
    struct RastPort myRastPort = {0};

    AddVSprite(&myVSprite, &myRastPort);

    /* Manipulate the VSprite as needed here */

    RemVSprite(&myVSprite);
