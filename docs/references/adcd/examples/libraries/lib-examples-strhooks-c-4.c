/* Source: ADCD 2.1
 * Section: lib-examples-strhooks-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-strhooks-c.md
 */

    {
    Wait(1L << vars->sgg_Window->UserPort->mp_SigBit);
    while (msg =
            (struct IntuiMessage *)GetMsg(vars->sgg_Window->UserPort))
        {
        /* Stash message contents and reply, important when message
        ** triggers some lengthy processing
        */
        class = msg->Class;
        code  = msg->Code;
        ReplyMsg((struct Message *)msg);

        switch (class)
            {
            case IDCMP_GADGETUP:
                /* if a code is set in the hook after an SGH_KEY
                ** command, where SGA_END is set on return from
                ** the hook, the code will be returned in the Code
                ** field of the IDCMP_GADGETUP message.
                */
                break;
            case IDCMP_CLOSEWINDOW:
                return;
                break;
            }
        }
    }
