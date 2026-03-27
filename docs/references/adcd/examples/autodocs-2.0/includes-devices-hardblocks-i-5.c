/* Source: ADCD 2.1
 * Section: includes-devices-hardblocks-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-devices-hardblocks-i.md
 */

    ULONG   lsb_ID		; 4 character identifier
    ULONG   lsb_SummedLongs	; size of this checksummed structure
    LONG    lsb_ChkSum		; block checksum (longword sum to zero)
    ULONG   lsb_HostID		; SCSI Target ID of host
    ULONG   lsb_Next		; block number of the next FileSysBlock
    STRUCT  lsb_LoadData,123*4	; data for "loadseg"
    ; note 123 assumes 512 byte blocks
    ; there is no LoadSegBlock_SIZEOF: try rdb_BlockBytes
