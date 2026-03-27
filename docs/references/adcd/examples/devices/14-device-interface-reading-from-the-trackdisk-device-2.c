/* Source: ADCD 2.1
 * Section: 14-device-interface-reading-from-the-trackdisk-device
 * Library: devices
 * ADCD reference: devices/14-device-interface-reading-from-the-trackdisk-device.md
 */

    DiskIO->iotd_Req.io_Length = TRACK_SIZE;
    DiskIO->iotd_Req.io_Data = (APTR)Readbuffer;
    DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * track);
    DiskIO->iotd_Count = change_count;
    DiskIO->iotd_Req.io_Command = ETD_READ;
    DoIO((struct IORequest *)DiskIO);
