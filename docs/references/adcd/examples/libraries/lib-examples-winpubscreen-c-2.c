/* Source: ADCD 2.1
 * Section: lib-examples-winpubscreen-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-winpubscreen-c.md
 */

    {
    /* We have no other ports of signals to wait on,
    ** so we'll just use WaitPort() instead of Wait()
    */
    WaitPort(win->UserPort);

    while ( (! done) &&
            (msg = (struct IntuiMessage *)GetMsg(win->UserPort)))
        {
        /* use a switch statement if looking for multiple event types */
        if (msg->Class == IDCMP_CLOSEWINDOW)
            done = TRUE;

        ReplyMsg((struct Message *)msg);
        }
    }
