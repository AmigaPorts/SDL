/* Source: ADCD 2.1
 * Section: 28-using-bobs-adding-a-bob
 * Library: libraries
 * ADCD reference: libraries/28-using-bobs-adding-a-bob.md
 */

    struct GelsInfo myGelsInfo = {0};
    struct VSprite dummySpriteA = {0}, dummySpriteB = {0};
    struct Bob myBob = {0};
    struct RastPort rastport = {0};

    /* Done ONCE, for this GelsInfo.  See setupGelSys() at the end of this
    ** chapter for a more complete initialization of the Gel system
    */
    InitGels(&dummySpriteA, &dummySpriteB, &myGelsInfo);

    /* Initialize the Bob members here, then AddBob() */
    AddBob(&myBob, &rastport);
