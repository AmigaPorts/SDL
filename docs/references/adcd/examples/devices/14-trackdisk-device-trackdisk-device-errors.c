/* Source: ADCD 2.1
 * Section: 14-trackdisk-device-trackdisk-device-errors
 * Library: devices
 * ADCD reference: devices/14-trackdisk-device-trackdisk-device-errors.md
 */

    DiskIO->iotd_Req.io_Length = TRACK_SIZE;
    DiskIO->iotd_Req.io_Data = (APTR)Writebuffer;
    DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * tracknum);
    DiskIO->iotd_Count = change_count;
    DiskIO->iotd_Req.io_Command = ETD_WRITE;
    if (DoIO((struct IORequest *)DiskIO))
        printf("ETD_WRITE failed.  Error: %ld\n",DiskIO-iotd.io_Error);
