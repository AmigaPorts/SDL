/* Source: ADCD 2.1
 * Section: includes-devices-hardblocks-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-devices-hardblocks-i.md
 */

    ULONG   pb_ID		; 4 character identifier
    ULONG   pb_SummedLongs	; size of this checksummed structure
    LONG    pb_ChkSum		; block checksum (longword sum to zero)
    ULONG   pb_HostID		; SCSI Target ID of host
    ULONG   pb_Next		; block number of the next PartitionBlock
    ULONG   pb_Flags		; see below for defines
    STRUCT  pb_Reserved1,2*4
    ULONG   pb_DevFlags		; preferred flags for OpenDevice
    STRUCT  pb_DriveName,32	; preferred DOS device name: BSTR form
