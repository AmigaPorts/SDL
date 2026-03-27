/* Source: ADCD 2.1
 * Section: include-devices-hardblocks-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-devices-hardblocks-h.md
 */

    ULONG   bbb_ID;		/* 4 character identifier */
    ULONG   bbb_SummedLongs;	/* size of this checksummed structure */
    LONG    bbb_ChkSum;		/* block checksum (longword sum to zero) */
    ULONG   bbb_HostID;		/* SCSI Target ID of host */
    ULONG   bbb_Next;		/* block number of the next BadBlockBlock */
    ULONG   bbb_Reserved;
    struct BadBlockEntry bbb_BlockPairs[61]; /* bad block entry pairs */
    /* note [61] assumes 512 byte blocks */
