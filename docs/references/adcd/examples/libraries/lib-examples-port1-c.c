/* Source: ADCD 2.1
 * Section: lib-examples-port1-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-port1-c.md
 */

    struct MsgPort *xyport;
    struct XYMessage *xymsg;
    ULONG portsig, usersig, signal;
    BOOL ABORT = FALSE;

    if (xyport = CreatePort("xyport", 0))
    {
        portsig = 1 << xyport->mp_SigBit;       /* Give user a `break' signal. */
        usersig = SIGBREAKF_CTRL_C;

        printf("Start port2 in another shell.  CTRL-C here when done.\n");
        do
        {                                                 /* port1 will wait forever and reply   */
            signal = Wait(portsig | usersig);             /* to messages, until the user breaks. */

                                   /* Since we only have one port that might get messages we     */
            if (signal & portsig)  /* have to reply to, it is not really necessary to test for   */
            {                      /* the portsignal. If there is not message at the port, xymsg */

                while(xymsg = (struct XYMessage *)GetMsg(xyport))        /* simply will be NULL. */
                {
                    printf("port1 received: x = %d y = %d\n", xymsg->xy_X, xymsg->xy_Y);

                    xymsg->xy_X += 50;       /* Since we have not replied yet to the owner of    */
                    xymsg->xy_Y += 50;       /* xymsg, we can change the data contents of xymsg. */

                    printf("port1 replying with: x = %d y = %d\n", xymsg->xy_X, xymsg->xy_Y);
                    ReplyMsg((struct Message *)xymsg);
                }
            }

            if (signal & usersig)                                    /* The user wants to abort. */
            {
                while(xymsg = (struct XYMessage *)GetMsg(xyport))    /* Make sure port is empty. */
                    ReplyMsg((struct Message *)xymsg);
                ABORT = TRUE;
            }
        }
        while (ABORT == FALSE);
            DeletePort(xyport);
        }
    else printf("Couldn't create 'xyport'\n");
