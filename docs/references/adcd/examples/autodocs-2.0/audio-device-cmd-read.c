/* Source: ADCD 2.1
 * Section: audio-device-cmd-read
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/audio-device-cmd-read.md
 */

    CMD_READ is a standard command for a single audio channel (io_Unit).
    If the allocation key (ioa_AllocKey) is correct, CMD_READ returns a
    pointer (io_Data) to the I/O block currently writing (CMD_WRITE) on
    the selected channel; otherwise, CMD_READ returns an error
    (ADIOERR_NOALLOCATION).  If there is no write in progress, CMD_READ
    returns zero.  CMD_READ is synchronous and only replies (mn_ReplyPort)
    if the quick bit (IOF_QUICK) is clear.
