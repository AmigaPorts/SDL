/* Source: ADCD 2.1
 * Section: audio-device-cmd-clear-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/audio-device-cmd-clear-2.md
 */

       CMD_CLEAR is a standard command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, CMD_CLEAR does nothing; otherwise, CMD_CLEAR returns an error
       (ADIOERR_NOALLOCATION).  CMD_CLEAR is synchronous and only replies
       (mn_ReplyPort) if the quick flag (IOF_QUICK) is clear.
