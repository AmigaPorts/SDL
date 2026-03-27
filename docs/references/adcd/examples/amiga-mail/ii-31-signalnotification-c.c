/* Source: ADCD 2.1
 * Section: ii-31-signalnotification-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-31-signalnotification-c.md
 */

    struct RDArgs  *readargs;
    LONG            rargs[2];
    struct NotifyRequest *notifyrequest;
    UBYTE          *filename;
    ULONG           signr, signal;

    /* To appease amiga.lib */
    SysBase = (*((struct Library **) 4));

    /* Fail silently if < 37 */
    if (DOSBase = OpenLibrary("dos.library", 37))
    {
        /* See the DOS Autodocs for more information about ReadArgs() */
        if (readargs = ReadArgs("Filename/A", rargs, NULL))
        {
            filename = (UBYTE *) (rargs[0]);

            /* Allocate a NotifyRequest structure */
            if (notifyrequest = AllocMem(sizeof(struct NotifyRequest), MEMF_CLEAR))
            {
                /* And allocate a signalbit */
                if ((signr = AllocSignal(-1L)) != -1)
                {

                    /* Initialize notifcation request */
                    notifyrequest->nr_Name = filename;
                    notifyrequest->nr_Flags = NRF_SEND_SIGNAL | NRF_NOTIFY_INITIAL;
                    /* Signal this task */
                    notifyrequest->nr_stuff.nr_Signal.nr_Task =
                            (struct Task *) FindTask(NULL);
                    /* with this signal bit */
                    notifyrequest->nr_stuff.nr_Signal.nr_SignalNum = signr;

                    if ((StartNotify(notifyrequest)) == DOSTRUE)
                    {
                        /* Loop until Ctrl-C to exit */
                        for (;;)
                        {
                            signal = Wait(1L << signr | SIGBREAKF_CTRL_C);
                            if (signal & (1L << signr))
                                VFPrintf(Output(), "Notification signal!\n", NULL);
                            if (signal & SIGBREAKF_CTRL_C)
                            {
                                EndNotify(notifyrequest);
                                PrintFault(ERROR_BREAK, NULL);
                                break;
                            }
                        }
                    }
                    else
                        PrintFault(ERROR_NOT_IMPLEMENTED, NULL);    /* most logical */

                    FreeSignal(signr);
                }
                else
                    VFPrintf(Output(), "No signal available\n", NULL);
                FreeMem(notifyrequest, sizeof(struct NotifyRequest));
            }
            else
                PrintFault(ERROR_NO_FREE_STORE, NULL);

            FreeArgs(readargs);
        }
        else
            PrintFault(IoErr(), NULL);
        CloseLibrary(DOSBase);
    }
