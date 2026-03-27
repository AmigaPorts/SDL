/* Source: ADCD 2.1
 * Section: viii-51-include-devices-sana2-i
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-51-include-devices-sana2-i.md
 */

        STRUCT  IOS2_REQ,IO_SIZE
        ULONG   IOS2_WIREERROR          ; wire type specific error
        ULONG   IOS2_PACKETTYPE         ; packet type
        STRUCT  IOS2_SRCADDR,SANA2_MAX_ADDR_BYTES       ; source address
        STRUCT  IOS2_DSTADDR,SANA2_MAX_ADDR_BYTES       ; dest address
        ULONG   IOS2_DATALENGTH         ; length of packet data
        APTR    IOS2_DATA               ; packet data (not touched by driver!)
        APTR    IOS2_STATDATA           ; statistics data pointer
        APTR    IOS2_BUFFERMANAGEMENT   ; see SANA-II OpenDevice adoc

        LABEL   IOS2_SIZE
