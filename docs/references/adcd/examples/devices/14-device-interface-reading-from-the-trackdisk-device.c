/* Source: ADCD 2.1
 * Section: 14-device-interface-reading-from-the-trackdisk-device
 * Library: devices
 * ADCD reference: devices/14-device-interface-reading-from-the-trackdisk-device.md
 */

    #define TRACK_SIZE ((LONG) (NUMSECS * TD_SECTOR))
    UBYTE *Readbuffer;
    SHORT tracknum;

    if (Readbuffer = AllocMem(TRACK_SIZE,MEMF_CLEAR|MEMF_CHIP))
        {
        DiskIO->iotd_Req.io_Length = TRACK_SIZE;
        DiskIO->iotd_Req.io_Data = (APTR)Readbuffer;
        DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * track);
        DiskIO->iotd_Req.io_Command = CMD_READ;
        DoIO((struct IORequest *)DiskIO);
        }
