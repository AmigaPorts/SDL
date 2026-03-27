/* Source: ADCD 2.1
 * Section: 11-scsi-device-scsi-direct
 * Library: devices
 * ADCD reference: devices/11-scsi-device-scsi-direct.md
 */

    struct IOStdReq *SCSIreq = NULL;
    struct SCSICmd Cmd;           /* where the actual SCSI command goes */

    SCSIreq->io_Length  = sizeof(struct SCSICmd);
    SCSIreq->io_Data    = (APTR)&Cmd;
    SCSIreq->io_Command = HD_SCSICMD;
    DoIO(SCSIreq);
