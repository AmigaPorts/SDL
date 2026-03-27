/* Source: ADCD 2.1
 * Section: devices-dev-examples-track-copy-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-track-copy-c.md
 */

    if (ParseArgs(argc, argv, unit))       /* Check inputs */
    {
        if (diskPort=CreatePort(NULL,NULL))
        {
            if (diskreq0=(struct IOExtTD *)CreateExtIO(diskPort,
                                                 sizeof(struct IOExtTD)))
            {
                if (diskreq1=(struct IOExtTD *)CreateExtIO(diskPort,
                                                 sizeof(struct IOExtTD)))
                {
                    Do_OpenDevice(diskreq0,diskreq1, unit);
                    DeleteExtIO((struct IORequest *)diskreq1);
                }
                else printf("Out of memory\n");
                DeleteExtIO((struct IORequest *)diskreq0);
            }
            else printf("Out of memory\n");
            DeletePort(diskPort);
        }
        else printf("Could not create diskReq port\n");
    }
