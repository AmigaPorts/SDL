/* Source: ADCD 2.1
 * Section: 11-device-interface-opening-the-scsi-device
 * Library: devices
 * ADCD reference: devices/11-device-interface-opening-the-scsi-device.md
 */

    struct MsgPort *SCSIMP;      /* Message port pointer */
    struct IOStdReq *SCSIIO;     /* IORequest pointer */

        /* Create message port */
    if (!(SCSIMP = CreatePort(NULL,NULL)))
        cleanexit("Can't create message port\n",RETURN_FAIL);

        /* Create IORequest */
    if (!(SCSIIO = CreateExtIO(SCSIMP,sizeof(struct IOStdReq))))
        cleanexit("Can't create IORequest\n",RETURN_FAIL);

        /* Open the SCSI device */
    if (error = OpenDevice("scsi.device",6L,SCSIIO,0L))
        cleanexit("Can't open scsi.device\n",RETURN_FAIL);
