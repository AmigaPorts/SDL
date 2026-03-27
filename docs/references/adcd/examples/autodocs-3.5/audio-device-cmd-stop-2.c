/* Source: ADCD 2.1
 * Section: audio-device-cmd-stop-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/audio-device-cmd-stop-2.md
 */

       CMD_STOP is a standard command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, CMD_STOP immediately stops any writes (CMD_WRITE) in
       progress; otherwise, CMD_STOP returns an error (ADIOERR_NOALLOCATION).
       [CMD_WRITE](../Includes_and_Autodocs_3._guide/node0071.html) queues up writes to a stopped channel until [CMD_START](../Includes_and_Autodocs_3._guide/node006E.html) starts
       the channel or [CMD_RESET](../Includes_and_Autodocs_3._guide/node006D.html) resets the channel. CMD_STOP is synchronous
       and only replies (mn_ReplyPort) if the quick flag (IOF_QUICK) is
       clear.  Do not use CMD_STOP in interrupt code at interrupt level 5 or
       higher.
