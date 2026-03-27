/* Source: ADCD 2.1
 * Section: include-dos-filehandler-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-dos-filehandler-h.md
 */

    ULONG de_TableSize;	     /* Size of Environment vector */
    ULONG de_SizeBlock;	     /* in longwords: Physical disk block size */
    ULONG de_SecOrg;	     /* not used; must be 0 */
    ULONG de_Surfaces;	     /* # of heads (surfaces). drive specific */
    ULONG de_SectorPerBlock; /* N de_SizeBlock sectors per logical block */
    ULONG de_BlocksPerTrack; /* blocks per track. drive specific */
    ULONG de_Reserved;	     /* DOS reserved blocks at start of partition. */
    ULONG de_PreAlloc;	     /* DOS reserved blocks at end of partition */
    ULONG de_Interleave;     /* usually 0 */
    ULONG de_LowCyl;	     /* starting cylinder. typically 0 */
    ULONG de_HighCyl;	     /* max cylinder. drive specific */
    ULONG de_NumBuffers;     /* Initial # DOS of buffers.  */
    ULONG de_BufMemType;     /* type of mem to allocate for buffers */
    ULONG de_MaxTransfer;    /* Max number of bytes to transfer at a time */
    ULONG de_Mask;	     /* Address Mask to block out certain memory */
    LONG  de_BootPri;	     /* Boot priority for autoboot */
    ULONG de_DosType;	     /* ASCII (HEX) string showing filesystem type;
