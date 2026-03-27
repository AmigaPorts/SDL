/* Source: ADCD 2.1
 * Section: lib-examples-port2-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-port2-c.md
 */

    struct MsgPort *xyreplyport;
    struct XYMessage *xymsg, *reply;
                                                           /* Using CreatePort() with no name       */
    if (xyreplyport = CreatePort(0,0))                     /* because this port need not be public. */
    {
        if (xymsg = (struct XYMessage *) AllocMem(sizeof(struct XYMessage), MEMF_PUBLIC | MEMF_CLEAR))
        {
            xymsg->xy_Msg.mn_Node.ln_Type = NT_MESSAGE;                /* make up a message,        */
            xymsg->xy_Msg.mn_Length = sizeof(struct XYMessage);        /* including the reply port. */
            xymsg->xy_Msg.mn_ReplyPort = xyreplyport;
            xymsg->xy_X = 10;                                   /* our special message information. */
            xymsg->xy_Y = 20;

            printf("Sending to port1: x = %d y = %d\n", xymsg->xy_X, xymsg->xy_Y);
                                                                   /* port2 will simply try to put  */

            if (SafePutToPort((struct Message *)xymsg, "xyport"))  /* one message to port1 wait for */
            {                                                      /*  the reply, and then exit     */
                WaitPort(xyreplyport);
                if (reply = (struct XYMessage *)GetMsg(xyreplyport))
                    printf("Reply contains: x = %d y = %d\n",         /* We don't ReplyMsg since   */
                            xymsg->xy_X, xymsg->xy_Y);                /* WE initiated the message. */

                      /* Since we only use this private port for receiving replies, and we sent     */
                      /* only one and got one reply there is no need to cleanup. For a public port, */
                      /* or if you pass a pointer to the port to another process, it is a very good */
                      /* habit to always handle all messages at the port before you delete it.      */
            }
            else printf("Can't find 'xyport'; start port1 in a separate shell\n");
            FreeMem(xymsg, sizeof(struct XYMessage));
        }
        else printf("Couldn't get memory\n");
        DeletePort(xyreplyport);
    }
    else printf("Couldn't create xyreplyport\n");
