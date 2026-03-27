/* Source: ADCD 2.1
 * Section: lib-examples-prefnotify-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-prefnotify-c.md
 */

    {
    /* Allocate a NotifyRequest structure */
    if (notifyrequest = AllocMem(sizeof(struct NotifyRequest), MEMF_CLEAR))
        {
        /* And allocate a signalsbit */
        if ((signum = AllocSignal(-1L)) != -1)
            {
            /* Initialize notification request */
            filename = PREFSFILENAME;
            notifyrequest->nr_Name = filename;
            notifyrequest->nr_Flags = NRF_SEND_SIGNAL;
            /* Signal this task */
            notifyrequest->nr_stuff.nr_Signal.nr_Task = (struct Task *) FindTask(NULL);
            /* with this signals bit */
            notifyrequest->nr_stuff.nr_Signal.nr_SignalNum = signum;

            if ((StartNotify(notifyrequest)) == DOSTRUE)
                {
                printf("Select Serial Prefs SAVE or USE to notify this program\n");
                printf("CTRL-C to exit\n\n");
                /* Loop until Ctrl-C to exit */
                while(!done)
                    {
                    signals = Wait(  (1L << signum) | SIGBREAKF_CTRL_C  );
                    if (signals & (1L << signum))
                        printf("Notification signal received.\n");
                    if (signals & SIGBREAKF_CTRL_C)
                        {
                        EndNotify(notifyrequest);
                        done=TRUE;
                        }
                    }
                }
            else printf("Can't start notification\n");
            FreeSignal(signum);
            }
        else printf("No signals available\n");
        FreeMem(notifyrequest, sizeof(struct NotifyRequest));
        }
    else printf("Not enough memory for NotifyRequest.\n");
    }
