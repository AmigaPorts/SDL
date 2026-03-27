/* Source: ADCD 2.1
 * Section: devices-dev-examples-terminate-parallel-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-terminate-parallel-c.md
 */

    {
    if (ParallelIO=(struct IOExtPar *)
                    CreateExtIO(ParallelMP,sizeof(struct IOExtPar)) )
        {
        if (OpenDevice(PARALLELNAME,0L,(struct IORequest *)ParallelIO,0) )
            printf("%s did not open\n",PARALLELNAME);
        else
           {
            /* Tell user what we are doing */
            printf("\fLooking for Q, E, A or % in output\n");

            /* Set EOF mode flag
             * Set the termination array
             * Send PDCMD_SETPARAMS to the parallel device
             */
            ParallelIO->io_ParFlags |= PARF_EOFMODE;
            ParallelIO->io_PTermArray = Terminators;
            ParallelIO->IOPar.io_Command  = PDCMD_SETPARAMS;
            if (DoIO((struct IORequest *)ParallelIO))
              printf("Set Params failed ");   /* Inform user of error */
            else
             {
             /* Send buffer */
             ParallelIO->IOPar.io_Length   = -1;
             ParallelIO->IOPar.io_Data     = WriteBuffer;
             ParallelIO->IOPar.io_Command  = CMD_WRITE;
             if (DoIO((struct IORequest *)ParallelIO))
              printf("Error: Write failed\n");
             else
             {
               /* Display all characters sent */
               printf("\nThese characters were sent:\n\t\t\tASCII\tHEX\n");
               for (ctr=0;ctr<ParallelIO->IOPar.io_Actual;ctr++)
                    printf("\t\t\t%c\t%x\n",*WriteBuffer,*WriteBuffer++);
               printf("\nThe actual number of characters sent: %d\n",
                         ParallelIO->IOPar.io_Actual);
             }
           }
           CloseDevice((struct IORequest *)ParallelIO);
            }

        DeleteExtIO((struct IORequest *)ParallelIO);
        }
    else
        printf("Error: Could not create I/O request\n");

    DeletePort(ParallelMP);
    }
