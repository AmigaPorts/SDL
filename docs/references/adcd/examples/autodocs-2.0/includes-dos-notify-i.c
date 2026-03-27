/* Source: ADCD 2.1
 * Section: includes-dos-notify-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-dos-notify-i.md
 */

    UBYTE  nr_SignalNum			; for SEND_SIGNAL
    STRUCT nr_pad,3

    ;-- Reserved fields:
    STRUCT nr_Reserved,4*4

    ;-- internal for use by handlers/dos:
    ULONG  nr_MsgCount			; # of outstanding msgs
    APTR   nr_Handler			; handler sent to (for EndNotify)
    LABEL  NotifyRequest_SIZEOF
