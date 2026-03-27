/* Source: ADCD 2.1
 * Section: includes-devices-clipboard-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-devices-clipboard-i.md
 */

    STRUCT  io_Message,MN_SIZE
    APTR    io_Device		; device node pointer
    APTR    io_Unit		; unit node pointer (ClipboardUnitPartial)
    UWORD   io_Command		; device command
    UBYTE   io_Flags		; including QUICK and SATISFY
    BYTE    io_Error		; error or warning num
    ULONG   io_Actual		; number of bytes transferred
    ULONG   io_Length		; number of bytes requested
    APTR    io_Data		; either clip stream or post port
    ULONG   io_Offset		; offset in clip stream
    LONG    io_ClipID		; ordinal clip identifier
    LABEL   iocr_SIZEOF
