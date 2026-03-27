/* Source: ADCD 2.1
 * Section: text-autodocs-audio-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-audio-doc.md
 */

       CMD_FLUSH is a standard command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, CMD_FLUSH aborts all writes (CMD_WRITE) in progress or queued
       and any I/O requests waiting to synchronize with the end of the cycle
       (ADCMD_WAITCYCLE); otherwise, CMD_FLUSH returns an error
       (ADIOERR_NOALLOCATION).  CMD_FLUSH is synchronous and only replies
       (mn_ReplyPort) if the quick flag (IOF_QUICK) is clear.  Do not use
       CMD_FLUSH in interrupt code at interrupt level 5 or higher.
