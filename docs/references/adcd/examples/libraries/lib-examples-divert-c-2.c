/* Source: ADCD 2.1
 * Section: lib-examples-divert-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-divert-c.md
 */

    extern struct MsgPort *broker_mp;
    extern CxObj *broker;
    extern ULONG cxsigflag;
    CxMsg *msg;
    ULONG sigrcvd, msgid;
    LONG returnvalue = 1L;

    while (returnvalue)
    {
        sigrcvd = Wait(SIGBREAKF_CTRL_C | cxsigflag);

        while(msg = (CxMsg *)GetMsg(broker_mp))
        {
            msgid = CxMsgID(msg);
            ReplyMsg((struct Message *)msg);

            switch(msgid)
            {
                case CXCMD_DISABLE:
                    ActivateCxObj(broker, 0L);
                    break;
                case CXCMD_ENABLE:
                    ActivateCxObj(broker, 1L);
                    break;
                case CXCMD_KILL:
                    returnvalue = 0L;
                    break;
                case CXCMD_UNIQUE:
                    returnvalue = 0L;
                    break;
            }
        }

        if (sigrcvd & SIGBREAKF_CTRL_C) returnvalue = 0L;

        /* Check to see if the signal CxObj signalled us. */
        if (sigrcvd & cxobjsignal) printf("Got Signal\n");
    }
