/* Source: ADCD 2.1
 * Section: audio-device-adcmd-free-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/audio-device-adcmd-free-2.md
 */

       ADCMD_FREE is a command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, ADCMD_FREE does the following:
         . restores the channel to a known state (CMD_RESET),
         . changes the channels allocation key, and
         . makes the channel available for re-allocation.
         . If the channel is locked (ADCMD_LOCK) ADCMD_FREE unlocks it and
           clears the bit for the channel (io_Unit) in the lock I/O request.
           If the lock I/O request has no channel bits set ADCMD_FREE replies
           the lock I/O request, and
         . checks if there are allocation requests (ADCMD_ALLOCATE) waiting
           for the channel.

       Otherwise, ADCMD_FREE returns an error (ADIOERR_NOALLOCATION).
       ADCMD_FREE is synchronous and only replies (mn_ReplyPort) if the quick
       flag (IOF_QUICK) is clear.  Do not use ADCMD_FREE in interrupt code.
