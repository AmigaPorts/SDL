/* Source: ADCD 2.1
 * Section: devices-dev-examples-track-copy-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-track-copy-c.md
 */

    disk->iotd_Req.io_Length=TRACK_SIZE;
    disk->iotd_Req.io_Data=(APTR)buffer;
    disk->iotd_Req.io_Command=TD_FORMAT;
    disk->iotd_Req.io_Offset=(ULONG)(TRACK_SIZE * track);
    DoIO((struct IORequest *)disk);
    if (disk->iotd_Req.io_Error)
    {
        All_OK=FALSE;
        printf("Error %d when writing track %d",disk->iotd_Req.io_Error,track);
    }
    return(All_OK);
