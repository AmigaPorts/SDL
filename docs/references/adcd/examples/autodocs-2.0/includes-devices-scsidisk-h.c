/* Source: ADCD 2.1
 * Section: includes-devices-scsidisk-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-devices-scsidisk-h.md
 */

    ULONG   scsi_Actual;	/* actual Data used */
    UBYTE  *scsi_Command;	/* SCSI Command (same options as scsi_Data) */
    UWORD   scsi_CmdLength;	/* length of Command */
    UWORD   scsi_CmdActual;	/* actual Command used */
    UBYTE   scsi_Flags;		/* includes intended data direction */
    UBYTE   scsi_Status;	/* SCSI status of command */
    UBYTE  *scsi_SenseData;	/* sense data: filled if SCSIF_[OLD]AUTOSENSE */
