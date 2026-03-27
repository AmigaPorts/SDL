/* Source: ADCD 2.1
 * Section: devices-dev-examples-pre-v36-device-use-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-pre-v36-device-use-c.md
 */

    {
        /* Create the I/O request */
    if (SerialIO = (struct IOExtSer *)CreateExtIO(SerialMP,sizeof(struct IOExtSer)))
        {
            /* Open the serial device */
        if (OpenDevice(SERIALNAME,0,(struct IORequest *)SerialIO,0L))

            /* Inform user that it could not be opened */
            printf("Error: %s did not open\n",SERIALNAME);
        else
            {
            /* device opened, send query command to it */
            SerialIO->IOSer.io_Command  = SDCMD_QUERY;
            if (DoIO((struct IORequest *)SerialIO))

                /* Inform user that query failed */
                printf("Query  failed. Error - %d\n",SerialIO->IOSer.io_Error);
            else
                /* Print serial device status - see include file for meaning */
                printf("\n\tSerial device status: %x\n\n",SerialIO->io_Status);

            /* Close the serial device */
            CloseDevice((struct IORequest *)SerialIO);
            }
        /* Delete the I/O request */
        DeleteExtIO(SerialIO);
        }
    else
        /* Inform user that the I/O request could be created */
        printf("Error: Could create I/O request\n");

    /* Delete the message port */
    DeletePort(SerialMP);
    }
