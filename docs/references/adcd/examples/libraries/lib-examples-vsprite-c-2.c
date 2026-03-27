/* Source: ADCD 2.1
 * Section: lib-examples-vsprite-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-vsprite-c.md
 */

    {
    Wait(1L << win->UserPort->mp_SigBit);
    while (NULL != (msg = (struct IntuiMessage *)GetMsg(win->UserPort)))
        {
        /* Only CLOSEWINDOW and INTUITICKS are active */
        if (msg->Class == CLOSEWINDOW)
            {
            ReplyMsg((struct Message *)msg);
            return;
            }
        /* Must be an INTUITICKS:  change x and y values on the fly.  Note offset by
        ** window left and top edge--sprite relative to the screen, not window.  Divide
        ** the MouseY in half to adjust for Lores movement increments on a Hires screen.
        */
        myVSprite->X = win->LeftEdge + msg->MouseX + myVSprite->VUserExt;
        myVSprite->Y = win->TopEdge  + msg->MouseY/2 + 1;
        ReplyMsg((struct Message *)msg);
        }
    /* Got a message, change image data on the fly */
    myVSprite->ImageData = (myVSprite->ImageData == vsprite_data1) ? vsprite_data2 : vsprite_data1;
    SortGList(myRPort);
    DoCollision(myRPort);
    vspriteDrawGList(win, myRPort);
    }
