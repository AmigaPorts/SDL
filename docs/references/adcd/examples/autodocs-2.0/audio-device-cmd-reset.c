/* Source: ADCD 2.1
 * Section: audio-device-cmd-reset
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/audio-device-cmd-reset.md
 */

    CMD_RESET is a standard command for multiple audio channels.  For each
    selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
    correct, CMD_RESET:
      . clears the hardware audio registers and attach bits,
      . sets the audio interrupt vector,
      . cancels all pending I/O (CMD_FLUSH), and
      . un-stops the channel if it is stopped (CMD_STOP),

    Otherwise, CMD_RESET returns an error (ADIOERR_NOALLOCATION).
    CMD_RESET is synchronous and only replies (mn_ReplyPort) if the quick
    flag (IOF_QUICK) is clear.  Do not use CMD_RESET in interrupt code at
    interrupt level 5 or higher.
