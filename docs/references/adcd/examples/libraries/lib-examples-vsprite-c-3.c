/* Source: ADCD 2.1
 * Section: lib-examples-vsprite-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-vsprite-c.md
 */

    {
    if (NULL == (myVSprite = makeVSprite(&myNewVSprite)))
        return_code = RETURN_WARN;
    else
        {
        AddVSprite(myVSprite, myRPort);
        vspriteDrawGList(win, myRPort);
        myVSprite->VUserExt = 20;
        SetCollision(BORDERHIT, borderCheck, myRPort->GelsInfo);
        process_window(win, myRPort, myVSprite);
        RemVSprite(myVSprite);
        freeVSprite(myVSprite);
        }
    vspriteDrawGList(win, myRPort);
    cleanupGelSys(my_ginfo, myRPort);
    }
