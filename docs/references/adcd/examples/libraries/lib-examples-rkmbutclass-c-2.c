/* Source: ADCD 2.1
 * Section: lib-examples-rkmbutclass-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rkmbutclass-c.md
 */

    ULONG done = FALSE;

    SetGadgetAttrs(but, w, NULL, attr, value, TAG_DONE);

    while (done == FALSE)
    {
        WaitPort((struct MsgPort *)w->UserPort);
        while (msg = (struct IntuiMessage *)
           GetMsg((struct MsgPort *)w->UserPort))
        {
            if (msg->Class == IDCMP_CLOSEWINDOW)
            {
                done = TRUE;
            }
            ReplyMsg(msg);
        }
    }
