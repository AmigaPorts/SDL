/* Source: ADCD 2.1
 * Section: lib-examples-popshell-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-popshell-c.md
 */

    UBYTE *hotkey, **ttypes;
    CxMsg *msg;

    if (CxBase = OpenLibrary("commodities.library", 37L))
    {
        if (IconBase = OpenLibrary("icon.library", 36L))
        {
            if (broker_mp = CreateMsgPort())
            {
                newbroker.nb_Port = broker_mp;
                cxsigflag = 1L << broker_mp->mp_SigBit;
                ttypes = ArgArrayInit(argc, argv);
                newbroker.nb_Pri = (BYTE)ArgInt(ttypes, "CX_PRIORITY", 0);
                hotkey = ArgString(ttypes, "HOTKEY", "rawkey control esc");

                if (broker = CxBroker(&newbroker, NULL))
                {
                    /* HotKey() is an amiga.lib function that creates a filter, sender */
                    /* and translate CxObject and connects them to report a hot key    */
                    /* press and delete its input event. */
                    if (filter = HotKey(hotkey, broker_mp, EVT_HOTKEY))
                    {
                        AttachCxObj(broker, filter); /* Add a CxObject to another's personal list */

                        if (! CxObjError(filter))
                        {
                            /* InvertString() is an amiga.lib function that creates a linked */
                            /* list of input events which would translate into the string    */
                            /* passed to it.  Note that it puts the input events in the      */
                            /* opposite order in which the corresponding letters appear in   */
                            /* the string.  A translate CxObject expects them backwards.     */
                            if (ie = InvertString(newshell, NULL))
                            {
                                ActivateCxObj(broker, 1L);
                                ProcessMsg();
                                /* we have to release the memory allocated by InvertString.       */
                                FreeIEvents(ie);
                            }
                        }
                    }
                    /* DeleteCxObjAll() is a commodities.library function that not only      */
                    /* deletes the CxObject pointed to in its argument, but deletes all of   */
                    /* the CxObjects attached to it.                                         */
                    DeleteCxObjAll(broker);

                    /* Empty the port of all CxMsgs */
                    while(msg = (CxMsg *)GetMsg(broker_mp))
                        ReplyMsg((struct Message *)msg);
                }
                DeletePort(broker_mp);
            }
            ArgArrayDone();  /* this amiga.lib function cleans up after ArgArrayInit() */
            CloseLibrary(IconBase);
        }
        CloseLibrary(CxBase);
    }
