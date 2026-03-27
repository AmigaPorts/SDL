/* Source: ADCD 2.1
 * Section: include-devices-hardblocks-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-devices-hardblocks-h.md
 */

    ULONG   lsb_ID;		/* 4 character identifier */
    ULONG   lsb_SummedLongs;	/* size of this checksummed structure */
    LONG    lsb_ChkSum;		/* block checksum (longword sum to zero) */
    ULONG   lsb_HostID;		/* SCSI Target ID of host */
    ULONG   lsb_Next;		/* block number of the next LoadSegBlock */
    ULONG   lsb_LoadData[123];	/* data for "loadseg" */
    /* note [123] assumes 512 byte blocks */
