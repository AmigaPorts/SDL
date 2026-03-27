/* Source: ADCD 2.1
 * Section: audio-device-cmd-update-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/audio-device-cmd-update-2.md
 */

       CMD_UPDATE is a standard command for multiple audio channels.  For
       each selected channel (io_Unit), if the allocation key (ioa_AllocKey)
       is correct, CMD_UPDATE does nothing; otherwise, CMD_UPDATE returns an
       error (ADIOERR_NOALLOCATION).  CMD_UPDATE is synchronous and only
       replies (mn_ReplyPort) if the quick flag (IOF_QUICK) is clear.
