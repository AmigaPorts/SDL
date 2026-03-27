/* Source: ADCD 2.1
 * Section: lib-examples-signals-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-signals-c.md
 */

    {
    mainsig = 1L << mainsignum;    /* subtask can access this global */
    maintask = FindTask(NULL);     /* subtask can access this global */

    printf("We alloc a signal, create a task, wait for signals\n");
    subtask = CreateTask(subtaskname, 0L, subtaskcode, 2000);
    if(!subtask)
        printf("Can't create subtask\n");
    else
        {
        printf("After subtask signals, press CTRL-C or CTRL-D to exit\n");

        while((!Done)||(WaitingForSubtask))
            {
            /* Wait on the combined mask for all of the signals we are
             * interested in.  All processes have the CTRL_C thru CTRL_F
             * signals.  We're also Waiting on the mainsig we allocated
             * for our subtask to signal us with.  We could also Wait on
             * the signals of any ports/windows our main task created ... */

            wakeupsigs = Wait(mainsig | SIGBREAKF_CTRL_C | SIGBREAKF_CTRL_D);

            /* Deal with all signals that woke us up - may be more than one */
            if(wakeupsigs & mainsig)
                {
                printf("Signalled by subtask\n");
                WaitingForSubtask = FALSE;   /* OK to kill subtask now */
                }
            if(wakeupsigs & SIGBREAKF_CTRL_C)
                {
                printf("Got CTRL-C signal\n");
                Done = TRUE;
                }
            if(wakeupsigs & SIGBREAKF_CTRL_D)
                {
                printf("Got CTRL-D signal\n");
                Done = TRUE;
                }
            }
        Forbid();
        DeleteTask(subtask);
        Permit();
        }
    FreeSignal(mainsignum);
    }
