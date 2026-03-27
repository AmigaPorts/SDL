/* Source: ADCD 2.1
 * Section: lib-examples-updatestrgad-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-updatestrgad-c.md
 */

    {
    Wait(1L << win->UserPort->mp_SigBit);
    while (msg = (struct IntuiMessage *)GetMsg(win->UserPort))
        {
        /* Stash message contents and reply, important when message
        ** triggers some lengthy processing
        */
        class = msg->Class;
