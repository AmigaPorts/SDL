/* Source: ADCD 2.1
 * Section: audio-device-cmd-stop
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/audio-device-cmd-stop.md
 */

    CMD_STOP is a standard command for multiple audio channels.  For each
    selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
    correct, CMD_STOP immediately stops any writes (CMD_WRITE) in
    progress; otherwise, CMD_STOP returns an error (ADIOERR_NOALLOCATION).
    [CMD_WRITE](../Includes_and_Autodocs_2._guide/node04B6.html) queues up writes to a stopped channel until [CMD_START](../Includes_and_Autodocs_2._guide/node04B3.html) starts
    the channel or [CMD_RESET](../Includes_and_Autodocs_2._guide/node04B2.html) resets the channel. CMD_STOP is synchronous
    and only replies (mn_ReplyPort) if the quick flag (IOF_QUICK) is
    clear.  Do not use CMD_STOP in interrupt code at interrupt level 5 or
    higher.
