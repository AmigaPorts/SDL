/* Source: ADCD 2.1
 * Section: 11-device-interface-closing-the-scsi-device
 * Library: devices
 * ADCD reference: devices/11-device-interface-closing-the-scsi-device.md
 */

    if (!(CheckIO(SCSIIO)))
        {
        AbortIO(SCSIIO);   /* Ask device to abort any pending requests */
        WaitIO(SCSIIO);    /* Wait for abort, then clean up */
        }
    CloseDevice(SCSIIO);   /* Close SCSI device */
