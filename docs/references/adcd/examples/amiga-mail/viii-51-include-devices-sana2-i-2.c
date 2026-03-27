/* Source: ADCD 2.1
 * Section: viii-51-include-devices-sana2-i
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-51-include-devices-sana2-i.md
 */

        ; Standard information
        ULONG   S2DQ_SIZEAVAILABLE      ; bytes available
        ULONG   S2DQ_SIZESUPPLIED       ; bytes supplied
        ULONG    S2DQ_FORMAT             ; this is type 0
        ULONG    S2DQ_DEVICELEVEL        ; this document is level 0

        ; Common information
        UWORD   S2DQ_ADDRFIELDSIZE           ; address size in bits
        ULONG   S2DQ_MTU                ; maximum packet data size
        ULONG    S2DQ_BPS                ; line rate (bits/sec)
        ULONG    S2DQ_HARDWARETYPE       ; what the wire is

        ; Format specific information
        LABEL   S2DQ_SIZE
