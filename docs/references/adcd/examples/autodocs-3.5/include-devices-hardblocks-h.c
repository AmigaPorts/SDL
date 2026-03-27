/* Source: ADCD 2.1
 * Section: include-devices-hardblocks-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-devices-hardblocks-h.md
 */

    ULONG   rdb_ID;		/* 4 character identifier */
    ULONG   rdb_SummedLongs;	/* size of this checksummed structure */
    LONG    rdb_ChkSum;		/* block checksum (longword sum to zero) */
    ULONG   rdb_HostID;		/* SCSI Target ID of host */
    ULONG   rdb_BlockBytes;	/* size of disk blocks */
    ULONG   rdb_Flags;		/* see below for defines */
    /* block list heads */
    ULONG   rdb_BadBlockList;	/* optional bad block list */
    ULONG   rdb_PartitionList;	/* optional first partition block */
    ULONG   rdb_FileSysHeaderList; /* optional file system header block */
    ULONG   rdb_DriveInit;	/* optional drive-specific init code */
