/* Source: ADCD 2.1
 * Section: devices-dev-examples-parallel-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-parallel-c.md
 */

    {
    if (ParallelIO=(struct IOExtPar *)
        CreateExtIO(ParallelMP,sizeof(struct IOExtPar)) )
        {
        if (OpenDevice(PARALLELNAME,0L,(struct IORequest *)ParallelIO,0) )
            printf("%s did not open\n",PARALLELNAME);
        else
            {
            /* Precalculate a wait mask for the CTRL-C,CTRL-F and message
             * port signals.  When one or more signals are received, Wait()
             *  will return.  Press CTRL-C to exit the example.  Press
             * CTRL-F to wake up the example without doing anything.
             * NOTE: A signal may show up without an associated message!
             */
            WaitMask = SIGBREAKF_CTRL_C | SIGBREAKF_CTRL_F |
                       1L << ParallelMP->mp_SigBit;

            ParallelIO->IOPar.io_Command  = CMD_WRITE;
            ParallelIO->IOPar.io_Length   = -1;
            ParallelIO->IOPar.io_Data     = (APTR)"Hey, Jude!\\r\n";
            SendIO(ParallelIO);             /* execute write */

            printf("Sleeping until CTRL-C, CTRL-F, or write finish\n");
            while(1)
                {
                Temp = Wait(WaitMask);
                printf("Just woke up (YAWN!)\n");

                if (SIGBREAKF_CTRL_C & Temp)
                    break;

                if (CheckIO(ParallelIO) ) /* If request is complete... */
                    {
                    WaitIO(ParallelIO);   /* clean up and remove reply */
                    printf("%ld bytes sent\n",ParallelIO->IOPar.io_Actual);
                    break;
                    }
                }

            AbortIO(ParallelIO);/* Ask dev. to abort request if pending */
            WaitIO(ParallelIO); /* Wait for abort, then clean up */

            CloseDevice((struct IORequest *)ParallelIO);
            }
        DeleteExtIO(ParallelIO);
        }
    DeletePort(ParallelMP);
    }
