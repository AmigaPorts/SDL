/* Source: ADCD 2.1
 * Section: includes-devices-hardblocks-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-devices-hardblocks-i.md
 */

    ULONG   bbb_ID		; 4 character identifier
    ULONG   bbb_SummedLongs	; size of this checksummed structure
    LONG    bbb_ChkSum		; block checksum (longword sum to zero)
    ULONG   bbb_HostID		; SCSI Target ID of host
    ULONG   bbb_Next		; block number of the next BadBlockBlock
    ULONG   bbb_Reserved
    STRUCT  bbb_BlockPairs,61*BadBlockEntry_SIZEOF ; bad block entry pairs
    ; note 61 assumes 512 byte blocks
    ; there is no BadBlockBlock_SIZEOF: try rdb_BlockBytes
