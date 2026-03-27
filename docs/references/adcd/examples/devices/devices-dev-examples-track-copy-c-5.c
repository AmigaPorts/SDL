/* Source: ADCD 2.1
 * Section: devices-dev-examples-track-copy-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-track-copy-c.md
 */

    drive1[2] = unit[0]+ '0';  /* Set drive number for source */

    if (!OpenDevice(TD_NAME,unit[0],(struct IORequest *)diskreq0,0L))
    {
          disk_busy(drive1,TRUE);
          drive2[2] = unit[1]+ '0';  /* Set drive number for destination */

        if (!OpenDevice(TD_NAME,unit[1],(struct IORequest *)diskreq1,0L))
        {
            disk_busy(drive2,TRUE);

            Insert_Disks(drive1,drive2);
            Do_Copy(diskreq0,diskreq1);
            Remove_Disks();

            disk_busy(drive2,FALSE);
            CloseDevice((struct IORequest *)diskreq1);
        }
        else printf("Could not open %s\n",drive2);

        disk_busy(drive1,FALSE);
        CloseDevice((struct IORequest *)diskreq0);
    }
    else printf("Could not open %s\n",drive1);
