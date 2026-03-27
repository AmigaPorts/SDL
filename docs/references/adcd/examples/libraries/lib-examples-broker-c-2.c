/* Source: ADCD 2.1
 * Section: lib-examples-broker-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-broker-c.md
 */

    CxMsg *msg;

    ULONG sigrcvd, msgid, msgtype;
    LONG returnvalue = 1L;

    while (returnvalue)
    {
        /* wait for something to happen */
        sigrcvd = Wait(SIGBREAKF_CTRL_C | cxsigflag);

        /* process any messages */
        while(msg = (CxMsg *)GetMsg(broker_mp))
        {
            /* Extract necessary information from the CxMessage and return it */
            msgid = CxMsgID(msg);
            msgtype = CxMsgType(msg);
            ReplyMsg((struct Message *)msg);

            switch(msgtype)
            {
                case CXM_IEVENT:
                    /* Shouldn't get any of these in this example */
                    break;
                case CXM_COMMAND:
                    /* Commodities has sent a command */
                    printf("A command: ");
                    switch(msgid)
                    {
                        case CXCMD_DISABLE:
                            printf("CXCMD_DISABLE\n");
                            /* The user clicked Commodities Exchange disable
                             * gadget better disable
                             */
                            ActivateCxObj(broker, 0L);
                            break;
                        case CXCMD_ENABLE:
                            /* user clicked enable gadget */
                            printf("CXCMD_ENABLE\n");
                            ActivateCxObj(broker, 1L);
                            break;
                        case CXCMD_KILL:
                            /* user clicked kill gadget, better quit */
                            printf("CXCMD_KILL\n");
                            returnvalue = 0L;
                            break;
                    }
                    break;
                default:
                    printf("Unknown msgtype\n");
                    break;
            }
        }
        /* Test to see if user tried to break */
        if (sigrcvd & SIGBREAKF_CTRL_C)
        {
            returnvalue = 0L;
            printf("CTRL C signal break\n");
        }
    }
