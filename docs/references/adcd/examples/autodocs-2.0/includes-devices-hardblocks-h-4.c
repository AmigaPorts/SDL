/* Source: ADCD 2.1
 * Section: includes-devices-hardblocks-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-devices-hardblocks-h.md
 */

    ULONG   fhb_ID;		/* 4 character identifier */
    ULONG   fhb_SummedLongs;	/* size of this checksummed structure */
    LONG    fhb_ChkSum;		/* block checksum (longword sum to zero) */
    ULONG   fhb_HostID;		/* SCSI Target ID of host */
    ULONG   fhb_Next;		/* block number of next FileSysHeaderBlock */
    ULONG   fhb_Flags;		/* see below for defines */
    ULONG   fhb_Reserved1[2];
    ULONG   fhb_DosType;	/* file system description: match this with */
