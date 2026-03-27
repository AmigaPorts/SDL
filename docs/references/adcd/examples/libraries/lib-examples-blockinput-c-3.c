/* Source: ADCD 2.1
 * Section: lib-examples-blockinput-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-blockinput-c.md
 */

    {
    Wait(1L << win->UserPort->mp_SigBit);

    while (NULL != (msg = (struct IntuiMessage *)GetMsg(win->UserPort)))
        {
        class = msg->Class;
        ReplyMsg((struct Message *)msg);

        switch (class)
            {
            case IDCMP_CLOSEWINDOW:
                done = TRUE;
                break;

            case IDCMP_INTUITICKS:
                if (tick_count > 0)
                    {
                    if (--tick_count == 0)  endWait(win,&myreq);
                    }
                break;
            }
        }
    }
