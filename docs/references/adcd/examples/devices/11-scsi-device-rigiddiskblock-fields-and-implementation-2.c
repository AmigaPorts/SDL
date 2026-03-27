/* Source: ADCD 2.1
 * Section: 11-scsi-device-rigiddiskblock-fields-and-implementation
 * Library: devices
 * ADCD reference: devices/11-scsi-device-rigiddiskblock-fields-and-implementation.md
 */

    ULONG   pb_ID;            /* 4 character identifier */
    ULONG   pb_SummedLongs;   /* size of this checksummed structure */
    LONG    pb_ChkSum;        /* block checksum (longword sum to zero) */
    ULONG   pb_HostID;        /* SCSI Target ID of host */
    ULONG   pb_Next;          /* block number of the next PartitionBlock */
    ULONG   pb_Flags;         /* see below for defines */
    ULONG   pb_Reserved1[2];
    ULONG   pb_DevFlags;      /* preferred flags for OpenDevice */
    UBYTE   pb_DriveName[32]; /* preferred DOS device name: BSTR form */
                              /* (not used if this name is in use) */
    ULONG   pb_Reserved2[15]; /* filler to 32 longwords */
    ULONG   pb_Environment[17]; /* environment vector for this partition */
    ULONG   pb_EReserved[15]; /* reserved for future environment vector */
