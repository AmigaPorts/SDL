/* Source: ADCD 2.1
 * Section: 32-expansion-board-drivers-expansion-drivers-and-dos
 * Library: libraries
 * ADCD reference: libraries/32-expansion-board-drivers-expansion-drivers-and-dos.md
 */

    ULONG de_TableSize       ; Size of Environment vector
    ULONG de_SizeBlock       ; in longwords: standard value is 128
    ULONG de_SecOrg          ; not used; must be 0
    ULONG de_Surfaces        ; # of heads (surfaces). drive specific
    ULONG de_SectorPerBlock  ; not used; must be 1
    ULONG de_BlocksPerTrack  ; blocks per track. drive specific
    ULONG de_Reserved        ; DOS reserved blocks at start of partition.
    ULONG de_PreAlloc        ; DOS reserved blocks at end of partition
    ULONG de_Interleave      ; usually 0
    ULONG de_LowCyl          ; starting cylinder. typically 0
    ULONG de_HighCyl         ; max cylinder. drive specific
    ULONG de_NumBuffers      ; Initial # DOS of buffers.
    ULONG de_BufMemType      ; type of mem to allocate for buffers
    ULONG de_MaxTransfer     ; Max number of bytes to transfer at a time
    ULONG de_Mask            ; Address Mask to block out certain memory
    LONG  de_BootPri         ; Boot priority for autoboot
    ULONG de_DosType         ; ASCII (HEX) string showing filesystem type;
                             ; 0X444F5300 is old filesystem,
                             ; 0X444F5301 is fast file system
    ULONG de_Baud            ; Baud rate for serial handler
    ULONG de_Control         ; Control word for handler/filesystem
                             ; (used as filesystem/handler desires)
    ULONG de_BootBlocks      ; Number of blocks containing boot code
                             ; (for non-AmigaDOS filesystems)
    LABEL DosEnvec_SIZEOF
