/* Source: ADCD 2.1
 * Section: lib-examples-visiblewindow-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-visiblewindow-c.md
 */

    {
    /* we only have one signal bit, so we do not have to check which
    ** bit(s) broke the Wait() (i.e. the return value of Wait)
    */
    Wait(1L << win->UserPort->mp_SigBit);

    while ( (! done) &&
            (msg = (struct IntuiMessage *)GetMsg(win->UserPort)))
        {
        /* use a switch statement if looking for multiple event types */
        if (msg->Class == IDCMP_CLOSEWINDOW)
            done = TRUE;

        ReplyMsg((struct Message *)msg);
        }
    }
