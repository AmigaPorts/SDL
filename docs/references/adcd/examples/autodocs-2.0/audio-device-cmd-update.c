/* Source: ADCD 2.1
 * Section: audio-device-cmd-update
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/audio-device-cmd-update.md
 */

    CMD_UPDATE is a standard command for multiple audio channels.  For
    each selected channel (io_Unit), if the allocation key (ioa_AllocKey)
    is correct, CMD_UPDATE does nothing; otherwise, CMD_UPDATE returns an
    error (ADIOERR_NOALLOCATION).  CMD_UPDATE is synchronous and only
    replies (mn_ReplyPort) if the quick flag (IOF_QUICK) is clear.
