/* Source: ADCD 2.1
 * Section: 14-device-interface-writing-to-the-trackdisk-device
 * Library: devices
 * ADCD reference: devices/14-device-interface-writing-to-the-trackdisk-device.md
 */

    #define TRACK_SIZE ((LONG) (NUMSECS * TD_SECTOR))
    UBYTE *Writebuffer;

    if (Writebuffer = AllocMem(TRACK_SIZE,MEMF_CLEAR|MEMF_PUBLIC))
        {
        DiskIO->iotd_Req.io_Length = TRACK_SIZE;
        DiskIO->iotd_Req.io_Data = (APTR)Writebuffer;
        DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * tracknum);
        DiskIO->iotd_Req.io_Command = CMD_WRITE;
        DoIO((struct IORequest *)DiskIO);
        }
