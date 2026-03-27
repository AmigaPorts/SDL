/* Source: ADCD 2.1
 * Section: 11-scsi-device-rigiddiskblock-fields-and-implementation
 * Library: devices
 * ADCD reference: devices/11-scsi-device-rigiddiskblock-fields-and-implementation.md
 */

    ULONG   fhb_ID;          /* 4 character identifier */
    ULONG   fhb_SummedLongs; /* size of this checksummed structure */
    LONG    fhb_ChkSum;      /* block checksum (longword sum to zero) */
    ULONG   fhb_HostID;      /* SCSI Target ID of host */
    ULONG   fhb_Next;        /* block number of next FileSysHeaderBlock */
    ULONG   fhb_Flags;       /* see below for defines */
    ULONG   fhb_Reserved1[2];
    ULONG   fhb_DosType;     /* file system description: match this with */
                             /* partition environment's DE_DOSTYPE entry */
    ULONG   fhb_Version;     /* release version of this code */
    ULONG   fhb_PatchFlags;  /* bits set for those of the following that */
                             /*  need to be substituted into a standard */
                             /*  device node for this file system: e.g. */
                             /*  0x180 to substitute SegList & GlobalVec */
    ULONG   fhb_Type;        /* device node type: zero */
    ULONG   fhb_Task;        /* standard dos "task" field: zero */
    ULONG   fhb_Lock;        /* not used for devices: zero */
    ULONG   fhb_Handler;     /* filename to loadseg: zero placeholder */
    ULONG   fhb_StackSize;   /* stacksize to use when starting task */
    LONG    fhb_Priority;    /* task priority when starting task */
    LONG    fhb_Startup;     /* startup msg: zero placeholder */
    LONG    fhb_SegListBlocks; /* first of linked list of LoadSegBlocks: */
                             /*   note that this entry requires some */
                             /*   processing before substitution */
    LONG    fhb_GlobalVec;   /* BCPL global vector when starting task */
    ULONG   fhb_Reserved2[23];/* (those reserved by PatchFlags) */
    ULONG   fhb_Reserved3[21];
