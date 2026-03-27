/* Source: ADCD 2.1
 * Section: devices-dev-examples-set-prefs-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-set-prefs-c.md
 */

    {
    if (pio = (union printerIO *)CreateExtIO(PrintMP,sizeof(union printerIO)))
        {
        if (!(OpenDevice("printer.device",0L,(struct IORequest *)pio,0L)))
            {
            DoTest();
            CloseDevice((struct IORequest *)pio);
            }
        DeleteExtIO((struct IORequest *)pio);
        }
    DeletePort(PrintMP);
    }
