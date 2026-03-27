/* Source: ADCD 2.1
 * Section: devices-dev-examples-terminate-serial-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-terminate-serial-c.md
 */

    {
    if (SerialIO=(struct IOExtSer *) CreateExtIO(SerialMP,sizeof(struct IOExtSer)))
        {
        if (OpenDevice(SERIALNAME,0L,(struct IORequest *)SerialIO,0) )
            printf("%s did not open\n",SERIALNAME);
        else
            {
             /* Tell user what we are doing */
             printf("\fLooking for Q, E, EOT or ETX\n");

             /* Set EOF mode flag
              * Set the termination array
              * Send SDCMD_SETPARAMS to the serial device
              */
             SerialIO->io_SerFlags |= SERF_EOFMODE;
             SerialIO->io_TermArray = Terminators;
             SerialIO->IOSer.io_Command  = SDCMD_SETPARAMS;
             if (DoIO((struct IORequest *)SerialIO))
                 printf("Set Params failed ");   /* Inform user of error */
             else
                 {
                 SerialIO->IOSer.io_Length   = READ_BUFFER_SIZE;
                 SerialIO->IOSer.io_Data     = (APTR)&ReadBuff[0];
                 SerialIO->IOSer.io_Command  = CMD_READ;
                 if (DoIO((struct IORequest *)SerialIO))     /* Execute Read */
                     printf("Error: Read failed\n");
                 else
                     {
                      /* Display all characters received */
                      printf("\nThese characters were read:\n\t\t\tASCII\tHEX\n");
                      for (ctr=0;ctr<SerialIO->IOSer.io_Actual;ctr++)
                           printf("\t\t\t  %c\t%x\n",ReadBuff[ctr],ReadBuff[ctr]);
                      printf("\nThe actual number of characters read: %d\n",
                                  SerialIO->IOSer.io_Actual);
                      }
                 }
            CloseDevice((struct IORequest *)SerialIO);
            }

        DeleteExtIO((struct IORequest *)SerialIO);
        }
    else
        printf("Error: Could not create IORequest\n");

    DeletePort(SerialMP);
    }
