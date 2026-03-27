/* Source: ADCD 2.1
 * Section: devices-dev-examples-get-systime-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-get-systime-c.md
 */

    {
    if (TimerIO = (struct timerequest *)
                   CreateExtIO(TimerMP,sizeof(struct timerequest)) )
        {
            /* Open with UNIT_VBLANK, but any unit can be used */
        if (!(error=OpenDevice(TIMERNAME,UNIT_VBLANK,(struct IORequest *)TimerIO,0L)))
            {
            /* Issue the command and wait for it to finish, then get the reply */
            TimerIO->tr_node.io_Command = TR_GETSYSTIME;
            DoIO((struct IORequest *) TimerIO);

            /* Get the results and close the timer device */
            mics=TimerIO->tr_time.tv_micro;
            secs=TimerIO->tr_time.tv_secs;

            /* Compute days, hours, etc. */
            mins=secs/60;
            hrs=mins/60;
            days=hrs/24;
            secs=secs%60;
            mins=mins%60;
            hrs=hrs%24;

            /* Display the time */
            printf("\nSystem Time (measured from Jan.1,1978)\n");
            printf("  Days   Hours  Minutes Seconds Microseconds\n");
            printf("%6ld %6ld %6ld %6ld %10ld\n",days,hrs,mins,secs,mics);

            /* Close the timer device */
            CloseDevice((struct IORequest *) TimerIO);
            }
        else
            printf("\nError: Could not open timer device\n");

        /* Delete the IORequest structure */
        DeleteExtIO(TimerIO);
        }
    else
        printf("\nError: Could not create I/O structure\n");

    /* Delete the port */
    DeletePort(TimerMP);
    }
