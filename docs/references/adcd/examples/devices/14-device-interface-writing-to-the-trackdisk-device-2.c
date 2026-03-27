/* Source: ADCD 2.1
 * Section: 14-device-interface-writing-to-the-trackdisk-device
 * Library: devices
 * ADCD reference: devices/14-device-interface-writing-to-the-trackdisk-device.md
 */

    DiskIO->iotd_Req.io_Length = TRACK_SIZE;
    DiskIO->iotd_Req.io_Data = (APTR)Writebuffer;
    DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * tracknum);
    DiskIO->iotd_Count = change_count;
    DiskIO->iotd_Req.io_Command = ETD_WRITE;
    DoIO((struct IORequest *)DiskIO);
