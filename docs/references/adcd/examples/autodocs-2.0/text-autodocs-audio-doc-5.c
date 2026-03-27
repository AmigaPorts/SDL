/* Source: ADCD 2.1
 * Section: text-autodocs-audio-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-audio-doc.md
 */

       ADCMD_LOCK is a command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, ADCMD_LOCK locks the channel, preventing subsequent
       allocations (ADCMD_ALLOCATE or OpenDevice) from stealing the channel.
       Otherwise, ADCMD_LOCK returns an error (ADIOERR_NOALLOCATION) and will
       not lock any channels.

       Unlike setting the precedence (ADCMD_SETPREC, ADCMD_ALLOCATE or
       OpenDevice) to maximum (ADALLOC_MAXPREC) which would cause all
       subsequent allocations to fail, ADCMD_LOCK causes all higher
       precedence allocations, even no-wait (ADIOF_NOWAIT) allocations, to
       wait until the channels are un-locked.

       Locked channels can only be unlocked by freeing them (ADCMD_FREE),
       which clears the channel select bits (io_Unit).  ADCMD_LOCK does not
       reply the I/O request (mn_ReplyPort) until all the channels it locks
       are freed, unless a higher precedence allocation attempts to steal one
       the locked channels. If a steal occurs, ADCMD_LOCK replies and returns
       an error (ADIOERR_CHANNELSTOLEN).  If the lock is replied
       (mn_ReplyPort) with this error, the channels should be freed as soon
       as possible.  To avoid a possible deadlock, never make the freeing of
       stolen channels dependent on another allocations completion.

       ADCMD_LOCK is only asynchronous if the allocation key is correct, in
       which case it clears the quick flag (IOF_QUICK); otherwise, it is
       synchronous and only replies if the quick flag (IOF_QUICK) is clear.
       Do not use ADCMD_LOCK in interrupt code.
