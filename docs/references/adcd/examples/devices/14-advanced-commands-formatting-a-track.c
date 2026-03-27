/* Source: ADCD 2.1
 * Section: 14-advanced-commands-formatting-a-track
 * Library: devices
 * ADCD reference: devices/14-advanced-commands-formatting-a-track.md
 */

    #define TRACK_SIZE ((LONG) (NUMSECS * TD_SECTOR))
    UBYTE *Writebuffer;

    if (WriteBuffer = AllocMem(TRACK_SIZE,MEMF_CLEAR|MEMF_CHIP))
        {
        DiskIO->iotd_Req.io_Length=TRACK_SIZE;
        DiskIO->iotd_Req.io_Data=(APTR)Writebuffer;
        DiskIO->iotd_Req.io_Offset=(ULONG)(TRACK_SIZE * track);
        DiskIO->iotd_Req.io_Command = TD_FORMAT;
        DoIO((struct IORequest *)DiskIO);
        }
