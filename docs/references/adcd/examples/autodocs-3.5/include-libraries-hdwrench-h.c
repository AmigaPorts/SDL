/* Source: ADCD 2.1
 * Section: include-libraries-hdwrench-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-libraries-hdwrench-h.md
 */

    struct MinNode   bb_Node;
    LONG             allocsize;
    LONG             bb_BlockNum;
    WORD             bb_Changed;
    LONG             unit;              /* Unit number for THIS set of RDBs. */
    char             DeviceName [32];   /* Device name */
    struct rw_return bb_RWErrors;
    BOOL             wflag;             /* Written out flag. */
    BYTE             spares[4-sizeof(BOOL)];/* Fill out short word */

    union
    {
        struct       RigidDiskBlock bd_RDB;
        struct       PartitionBlock bd_PB;
        struct       FileSysHeaderBlock bd_FHB;
        struct       LoadSegBlock bd_LSB;
        struct       BadBlockBlock bd_BB;
        UBYTE        bd_Bytes[512];     /* NB: This is the MINIMUM size we */
        UWORD        bd_Words[256];     /* can have here. It MAY be extended */
        ULONG        bd_Longs[128];     /* if actual block size is larger. */
    } bb_Data;
