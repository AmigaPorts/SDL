/* Source: ADCD 2.1
 * Section: lib-examples-divert-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-divert-c.md
 */

    UBYTE **ttypes;
    CxMsg *msg;

    if (CxBase = OpenLibrary("commodities.library", 37L))
    {
        /* open the icon.library for support library functions, ArgArrayInit() and ArgArrayDone() */
        if (IconBase = OpenLibrary("icon.library", 36L))
        {
            if (broker_mp = CreateMsgPort())
            {
                newbroker.nb_Port = broker_mp;
                cxsigflag = 1L << broker_mp->mp_SigBit;

                /* ArgArrayInit() is a support library function (in the 2.0 version of amiga.lib) */
                /* that makes it easy to read arguments from either a CLI or from Workbench's     */
                /* ToolTypes. Because it uses icon.library, the library has to be open before     */
                /* before calling this function.  ArgArrayDone() cleans up after this function.   */
                ttypes = ArgArrayInit(argc, argv);

                /* ArgInt() (in amiga.lib) searches through the array set up by ArgArrayInit()    */
                /* for a specific ToolType.  If it finds one, it returns the numeric value of the */
                /* number that followed the ToolType (i.e., CX_PRIORITY=7).  If it  doesn't find  */
                /* the ToolType, it returns the default value (the third argument)                */
                newbroker.nb_Pri = (BYTE)ArgInt(ttypes, "CX_PRIORITY", 0);

                if (broker = CxBroker(&newbroker, NULL))
                {
                    /* CxCustom() takes two arguments, a pointer to the custom function           */
                    /* and an ID. Commodities Exchange will assign that ID to any CxMsg           */
                    /* passed to the custom  function.                                            */
                    if (cocustom = CxCustom(CxFunction, 0L))
                    {
                        AttachCxObj(broker, cocustom);

                        /* Allocate a signal bit for the signal CxObj */
                        if ( (signal = (ULONG)AllocSignal(-1L)) != -1)
                        {
                            /* set up the signal mask */
                            cxobjsignal = 1L << signal;
                            cxsigflag |= cxobjsignal;

                            /* CxSignal takes two arguments, a pointer to the task to signal      */
                            /* (normally the commodity) and the number of the signal bit the      */
                            /* commodity acquired to signal with.                                 */
                            task = FindTask(NULL);
                            if (cosignal = CxSignal(task, signal))
                            {
                                AttachCxObj(cocustom, cosignal);
                                ActivateCxObj(broker, 1L);
                                ProcessMsg();
                            }
                            FreeSignal(signal);
                        }
                    }
                    /* DeleteCxObjAll() is a commodities.library function that not only deletes   */
                    /* the CxObject pointed to in its argument, but it deletes all of the         */
                    /* CxObjects that are attached to it.                                         */
                    DeleteCxObjAll(broker);

                    /* Empty the port of all CxMsgs */
                    while(msg = (CxMsg *)GetMsg(broker_mp))
                        ReplyMsg((struct Message *)msg);
                }
                DeletePort(broker_mp);
            }
            ArgArrayDone();   /* this amiga.lib function cleans up after ArgArrayInit()           */
            CloseLibrary(IconBase);
        }
        CloseLibrary(CxBase);
    }
