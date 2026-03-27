/* Source: ADCD 2.1
 * Section: lib-examples-dualplayfield-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-dualplayfield-c.md
 */

    {
    signals = Wait(1L << win->UserPort->mp_SigBit);
    if (signals & (1L << win->UserPort->mp_SigBit))
        {
        while ((!done) &&
               (message = (struct IntuiMessage *)GetMsg(win->UserPort)))
            {
            class = message->Class;
            ReplyMsg((struct Message *)message);

            switch (class)
                {
                case IDCMP_CLOSEWINDOW:
                    done = TRUE;
                    break;
                }
            }
        }
    }
