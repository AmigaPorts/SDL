/* Source: ADCD 2.1
 * Section: 14-disk-status-commands-determining-the-current-diskchange
 * Library: devices
 * ADCD reference: devices/14-disk-status-commands-determining-the-current-diskchange.md
 */

    ULONG change_count;

    DiskIO->iotd_Req.io_Flags = IOF_QUICK;
    DiskIO->iotd_Req.io_Command = TD_CHANGENUM;
    BeginIO((struct IORequest *)DiskIO);
    /* store current diskchange value */
    change_count = DiskIO->iotd_Req.io_Actual;

    DiskIO->iotd_Req.io_Length = 1;     /* Turn on the drive motor */
    DiskIO->iotd_Count = change_count;
    DiskIO->iotd_Req.io_Command = ETD_MOTOR;
    DoIO((struct IORequest *)DiskIO);
