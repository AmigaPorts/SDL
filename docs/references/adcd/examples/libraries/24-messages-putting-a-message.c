/* Source: ADCD 2.1
 * Section: 24-messages-putting-a-message
 * Library: libraries
 * ADCD reference: libraries/24-messages-putting-a-message.md
 */

    struct MsgPort *xyport, *xyreplyport;
    struct XYMessage *xymsg, *msg;
    BOOL   foundport;

    /* Allocate memory for the message we're going to send. */
    if (xymsg = (struct XYMessage *) AllocMem(sizeof(struct XYMessage),
                                             MEMF_PUBLIC | MEMF_CLEAR))
    {

        /* The replyport we'll use to get response */
        if (xyreplyport = CreateMsgPort()) {
                                         /* or use CreatePort(0,0) */

            xymsg->xy_Msg.mn_Node.ln_Type = NT_MESSAGE;
                                         /* Compose the message    */
            xymsg->xy_Msg.mn_Length = sizeof(struct XYMessage);
            xymsg->xy_Msg.mn_ReplyPort = xyreplyport;
            xymsg->xy_X = 10;
            xymsg->xy_Y = 20;

            /* Now try to send that message to a public port named
             *  "xyport". If foundport eq 0, the port isn't out there.
             */
            if (foundport = SafePutToPort((struct Message *)xymsg,
                                           "xyport"))
            {

            . . .   /* Now let's wait till the someone responds... */

            }
            else printf("Couldn't find 'xyport'\n");

            DeleteMsgPort(xyreplyport);  /* Use DeletePort() if    */
                                         /* the port was created   */
        }                                /* with CreatePort().     */
        else printf("Couldn't create message port\n");
        FreeMem(xymsg, sizeof(struct XYMessage));
    }
    else printf("Couldn't get memory for xymessage\n");
