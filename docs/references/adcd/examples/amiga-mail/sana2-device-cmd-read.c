/* Source: ADCD 2.1
 * Section: sana2-device-cmd-read
 * Library: amiga-mail
 * ADCD reference: amiga-mail/sana2-device-cmd-read.md
 */

    Get the next packet available of the requested packet type. The data
    copied (via a call to the requestor-provided CopyToBuffer function)
    into ios2_Data is normally the Data Link Layer packet data only. If
    bit SANA2IOB_RAW is set in ios2_Flags, then the entire physical frame
    will be returned.

    Unlike most Exec devices, SANA-II device drivers do not have internal
    buffers.  If you wish to read data from a SANA-II device you should
    have multiple CMD_READ requests pending at any given time.  The
    functions provided by you the requestor will be used for any incoming
    packets of the type you've requested.  If no read requests are
    outstanding for a type which comes in and no read_orphan requests are
    outstanding, the packet will be lost.
