/* Source: ADCD 2.1
 * Section: dos-library-replypkt
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-replypkt.md
 */

    This returns a packet to the process which sent it to you.  In
    addition, puts your pr_MsgPort address in dp_Port, so using ReplyPkt()
    again will send the message to you.  (This is used in "ping-ponging"
    packets between two processes).  It uses result 1 & 2 to set the
    dp_Res1 and dp_Res2 fields of the packet.
