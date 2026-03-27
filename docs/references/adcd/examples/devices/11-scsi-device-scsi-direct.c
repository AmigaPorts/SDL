/* Source: ADCD 2.1
 * Section: 11-scsi-device-scsi-direct
 * Library: devices
 * ADCD reference: devices/11-scsi-device-scsi-direct.md
 */

    UWORD *scsi_Data;      /* word aligned data for SCSI Data Phase */
                           /* (optional) data need not be byte aligned */
                           /* (optional) data need not be bus accessible */
    ULONG  scsi_Length;    /* even length of Data area */
                           /* (optional) data can have odd length */
                           /* (optional) data length can be > 2**24 */
    ULONG  scsi_Actual;    /* actual Data used */
    UBYTE *scsi_Command;   /* SCSI Command (same options as scsi_Data) */
    UWORD  scsi_CmdLength; /* length of Command */
    UWORD  scsi_CmdActual; /* actual Command used */
    UBYTE  scsi_Flags;     /* includes intended data direction */
    UBYTE  scsi_Status;    /* SCSI status of command */
    UBYTE *scsi_SenseData; /* sense data: filled if SCSIF_[OLD]AUTOSENSE */
                           /* is set and scsi_Status has CHECK CONDITION */
                           /* (bit 1) set */
    UWORD  scsi_SenseLength;/* size of scsi_SenseData, also bytes to */
                           /* request w/ SCSIF_AUTOSENSE, must be 4..255 */
    UWORD  scsi_SenseActual;/* amount actually fetched (0 = no sense) */
