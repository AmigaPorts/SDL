/* Source: ADCD 2.1
 * Section: audio-device-adcmd-waitcycle-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/audio-device-adcmd-waitcycle-2.md
 */

       ADCMD_WAITCYCLE is a command for a single audio channel (io_Unit).
       If the allocation key (ioa_AllocKey) is correct and there is a write
       (CMD_WRITE) in progress on selected channel, ADCMD_WAITCYCLE does not
       reply (mn_ReplyPort) until the end of the current cycle.  If there is
       no write is progress, ADCMD_WAITCYCLE replies immediately.  If the
       allocation key is incorrect, ADCMD_WAITCYCLE returns an error
       (ADIOERR_NOALLOCATION).  ADCMD_WAITCYCLE returns an error
       (IOERR_ABORTED) if it is canceled (AbortIO) or the channel is stolen
       (ADCMD_ALLOCATE).  ADCMD_WAITCYCLE is only asynchronous if it is
       waiting for a cycle to complete, in which case it clears the quick
       flag (IOF_QUICK); otherwise, it is synchronous and only replies if the
       quick flag (IOF_QUICK) is clear.  Do not use ADCMD_WAITCYCLE in
       interrupt code at interrupt level 5 or higher.
