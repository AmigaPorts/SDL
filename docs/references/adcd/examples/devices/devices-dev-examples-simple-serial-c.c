/* Source: ADCD 2.1
 * Section: devices-dev-examples-simple-serial-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-simple-serial-c.md
 */

    {
    /* Create the IORequest */
    if (SerialIO = (struct IOExtSer *)
                    CreateExtIO(SerialMP,sizeof(struct IOExtSer)))
        {
        /* Open the serial device */
        if (OpenDevice(SERIALNAME,0,(struct IORequest *)SerialIO,0L))

            /* Inform user that it could not be opened */
            printf("Error: %s did not open\n",SERIALNAME);
        else
            {
            /* device opened, write NULL-terminated string */
            SerialIO->IOSer.io_Length   = -1;
            SerialIO->IOSer.io_Data     = (APTR)"Amiga ";
            SerialIO->IOSer.io_Command  = CMD_WRITE;
            if (DoIO((struct IORequest *)SerialIO))     /* execute write */
                printf("Write failed.  Error - %ld\n",SerialIO->IOSer.io_Error);

            /* Close the serial device */
            CloseDevice((struct IORequest *)SerialIO);
            }
        /* Delete the IORequest */
        DeleteExtIO(SerialIO);
        }
    else
        /* Inform user that the IORequest could be created */
        printf("Error: Could create IORequest\n");

    /* Delete the message port */
    DeleteMsgPort(SerialMP);
    }
