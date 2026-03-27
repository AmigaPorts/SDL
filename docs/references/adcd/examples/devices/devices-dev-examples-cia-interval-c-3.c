/* Source: ADCD 2.1
 * Section: devices-dev-examples-cia-interval-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-cia-interval-c.md
 */

    {
    /* Prepare freetimer structure : set-up interrupt */

    ft.timerint.is_Node.ln_Type = NT_INTERRUPT;
    ft.timerint.is_Node.ln_Pri  = 0;
    ft.timerint.is_Node.ln_Name = "cia_example";

    ft.timerint.is_Data         = (APTR)&ed;
    ft.timerint.is_Code         = (APTR)ExampleInterrupt;

    /* Call function to find a free CIA interval timer
     * with flag indicating that we prefer a CIA-A timer.
     */

    printf("Attempting to allocate a free timer\n");

    if (FindFreeTimer(&ft,TRUE))
        {
        if (ft.cia == ciaa)
            {
            printf("CIA-A timer ");
            }
        else
            {
            printf("CIA-B timer ");
            }

        if (ft.timerbit == CIAICRB_TA)
            {
            printf("A allocated\n");
            }
        else
            {
            printf("B allocated\n");
            }


        /* We found a free interval timer.  Let's start it running. */

        StartTimer(&ft,&ed);

        /* Wait for a signal */

        printf("Waiting for signal bit %ld\n",ed.signal);

        Wait(1L<<ed.signal);

        printf("We woke up!\n");

        /* Release the interval timer */

        RemICRVector(ft.ciabase,ft.timerbit,&ft.timerint);

        }
    else
        {
        printf("No CIA interval timer available\n");
        }

    FreeSignal(ed.signal);
    }
