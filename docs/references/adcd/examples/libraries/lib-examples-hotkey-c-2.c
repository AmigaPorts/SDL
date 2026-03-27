/* Source: ADCD 2.1
 * Section: lib-examples-hotkey-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-hotkey-c.md
 */

    extern struct MsgPort *broker_mp;
    extern CxObj *broker;
    extern ULONG cxsigflag;
    CxMsg *msg;
    ULONG sigrcvd, msgid, msgtype;
    LONG returnvalue = 1L;

    while(returnvalue)
    {
        sigrcvd = Wait(SIGBREAKF_CTRL_C | cxsigflag);

        while(msg = (CxMsg *)GetMsg(broker_mp))
        {
            msgid = CxMsgID(msg);
            msgtype = CxMsgType(msg);
            ReplyMsg((struct Message *)msg);

            switch(msgtype)
            {
                case CXM_IEVENT:
                    printf("A CXM_EVENT, ");
                    switch(msgid)
                    {
                        case EVT_HOTKEY: /* We got the message from the sender CxObject */
                            printf("You hit the HotKey.\n");
                            break;
                        default:
                            printf("unknown.\n");
                            break;
                    }
                    break;
                case CXM_COMMAND:
                    printf("A command: ");
                    switch(msgid)
                    {
                        case CXCMD_DISABLE:
                            printf("CXCMD_DISABLE\n");
                            ActivateCxObj(broker, 0L);
                            break;
                        case CXCMD_ENABLE:
                            printf("CXCMD_ENABLE\n");
                            ActivateCxObj(broker, 1L);
                            break;
                        case CXCMD_KILL:
                            printf("CXCMD_KILL\n");
                            returnvalue = 0L;
                            break;
                        case CXCMD_UNIQUE:
                        /* Commodities Exchange can be told not only to refuse to launch a
                         * commodity with a name already in use but also can notify the
                         * already running commodity that it happened. It does this by
                         * sending a CXM_COMMAND with the ID set to CXMCMD_UNIQUE.  If the
                         * user tries to run a windowless commodity that is already running,
                         * the user wants the commodity to shut down. */
                            printf("CXCMD_UNIQUE\n");
                            returnvalue = 0L;
                            break;
                        default:
                            printf("Unknown msgid\n");
                            break;
                    }
                    break;
                default:
                    printf("Unknown msgtype\n");
                    break;
            }
        }
        if (sigrcvd & SIGBREAKF_CTRL_C)
        {
            returnvalue = 0L;
            printf("CTRL C signal break\n");
        }
    }
