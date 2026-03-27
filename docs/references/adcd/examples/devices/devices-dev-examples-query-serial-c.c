/* Source: ADCD 2.1
 * Section: devices-dev-examples-query-serial-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-query-serial-c.md
 */

    {
    if (SerialIO=(struct IOExtSer *)CreateExtIO(SerialMP,sizeof(struct IOExtSer)) )
        {
        if (OpenDevice(SERIALNAME,0L,(struct IORequest *)SerialIO,0))
            {
            printf("\n%s did not open",SERIALNAME);

            MiscBase= (struct Library *)OpenResource(MISCNAME);

            /* Find out who has the serial device */
            if ((user = AllocMiscResource(MR_SERIALPORT,"Us")) == NULL)
                {
                printf("\n");
                FreeMiscResource(MR_SERIALPORT);
                }
            else
                printf(" because %s owns it \n\n",user);
            }
        else
            {
            SerialIO->IOSer.io_Command  = SDCMD_QUERY;
            DoIO((struct IORequest *)SerialIO);             /* execute query */

            status = SerialIO->io_Status;                    /* store returned status */

            printf("\tThe serial port status is %x\n",status);

            CloseDevice((struct IORequest *)SerialIO);
            }

        DeleteExtIO(SerialIO);
        }
    else
        printf("Can't create I/O request\n");

    DeletePort(SerialMP);
    }
