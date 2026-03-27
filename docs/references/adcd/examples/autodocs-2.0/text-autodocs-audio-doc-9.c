/* Source: ADCD 2.1
 * Section: text-autodocs-audio-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-audio-doc.md
 */

       CMD_CLEAR is a standard command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, CMD_CLEAR does nothing; otherwise, CMD_CLEAR returns an error
       (ADIOERR_NOALLOCATION).  CMD_CLEAR is synchronous and only replies
       (mn_ReplyPort) if the quick flag (IOF_QUICK) is clear.
