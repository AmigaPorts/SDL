/* Source: ADCD 2.1
 * Section: includes-exec-io-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-exec-io-i.md
 */

    APTR    IO_DEVICE			; device node pointer
    APTR    IO_UNIT			; unit (driver private)
    UWORD   IO_COMMAND			; device command
    UBYTE   IO_FLAGS			; special flags
    BYTE    IO_ERROR			; error or warning code
    LABEL   IO_SIZE
