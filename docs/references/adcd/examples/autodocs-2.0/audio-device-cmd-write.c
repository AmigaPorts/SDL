/* Source: ADCD 2.1
 * Section: audio-device-cmd-write
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/audio-device-cmd-write.md
 */

    CMD_WRITE is a standard command for a single audio channel (io_Unit).
    If the allocation key (ioa_AllocKey) is correct, CMD_WRITE plays a
    sound using the selected channel; otherwise, it returns an error
    (ADIOERR_NOALLOCATION).  CMD_WRITE queues up requests if there is
    another write in progress or if the channel is stopped (CMD_STOP).
    When the write actually starts; if the ADIOF_PERVOL flag is set,
    CMD_WRITE loads volume (ioa_Volume) and period (ioa_Period), and if
    the ADIOF_WRITEMESSAGE flag is set, CMD_WRITE replies the write
    message (ioa_WriteMsg).  CMD_WRITE returns an error (IOERR_ABORTED) if
    it is canceled (AbortIO) or the channel is stolen (ADCMD_ALLOCATE).
    CMD_WRITE is only asynchronous if there is no error, in which case it
    clears the quick flag (IOF_QUICK) and replies the I/O request
    (mn_ReplyPort) after it finishes writting; otherwise, it is synchronou
