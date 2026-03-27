/* Source: ADCD 2.1
 * Section: text-autodocs-audio-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-audio-doc.md
 */

       CMD_STOP is a standard command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, CMD_STOP immediately stops any writes (CMD_WRITE) in
       progress; otherwise, CMD_STOP returns an error (ADIOERR_NOALLOCATION).
       CMD_WRITE queues up writes to a stopped channel until CMD_START starts
       the channel or CMD_RESET resets the channel. CMD_STOP is synchronous
       and only replies (mn_ReplyPort) if the quick flag (IOF_QUICK) is
       clear.  Do not use CMD_STOP in interrupt code at interrupt level 5 or
       higher.
