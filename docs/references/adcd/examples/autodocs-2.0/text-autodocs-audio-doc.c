/* Source: ADCD 2.1
 * Section: text-autodocs-audio-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-audio-doc.md
 */

       ADCMD_ALLOCATE is a command that allocates multiple audio channels.
       ADCMD_ALLOCATE takes an array of possible channel combinations
       (ioa_Data) and an allocation precedence (ln_Pri) and tries to allocate
       one of the combinations of channels.

       If the channel combination array is zero length (ioa_Length), the
       allocation succeeds; otherwise, ADCMD_ALLOCATE checks each
       combination, one at a time, in the specified order, to find one
       combination that does not require ADCMD_ALLOCATE to steal allocated
       channels.

       If it must steal allocated channels, it uses the channel combination
       that steals the lowest precedence channels.

       ADCMD_ALLOCATE cannot steal a channel of equal or greater precedence
       than the allocation precedence (ln_Pri).

       If it fails to allocate any channel combination and the no-wait flag
       (ADIOF_NOWAIT) is set ADCMD_ALLOCATE returns a zero in the unit field
       of the I/O request (io_Unit) and an error (IOERR_ALLOCFAILED).  If the
       no-wait flag is clear, it places the I/O request in a list that tries
       to allocate again whenever ADCMD_FREE frees channels or ADCMD_SETPREC
       lowers the channels' precedences.

       If the allocation is successful, ADCMD_ALLOCATE checks if any channels
       are locked (ADCMD_LOCK) and if so, replies (ReplyMsg) the lock I/O
       request with an error (ADIOERR_CHANNELSTOLEN). Then it places the
       allocation I/O request in a list waiting for the locked channels to be
       freed.  When all the allocated channels are un-locked, ADCMD_ALLOCATE:
         . resets (CMD_RESET) the allocated channels,
         . generates a new allocation key (ioa_AllocKey), if it is zero,
         . copies the allocation key into each of the allocated channels
         . copies the allocation precedence into each of the allocated
           channels, and
         . copies the channel bit map into the unit field of the I/O request.

       If channels are allocated with a non-zero allocation key,
       ADCMD_ALLOCATE allocates with that same key; otherwise, it generates a
       new and unique key.

       ADCMD_ALLOCATE is synchronous:
         . if the allocation succeeds and there are no locked channels to be
           stolen, or
         . if the allocation fails and the no-wait flag is set.

       In either case, ADCMD_ALLOCATE only replies (mn_ReplyPort) if the
       quick flag (IOF_QUICK) is clear; otherwise, the allocation is
       asynchronous, so it clears the quick flag and replies the I/O request
       after the allocation is finished.  If channels are stolen, all audio
       device commands return an error (IOERR_NOALLOCATION) when the former
       user tries to use them again.  Do not use ADCMD_ALLOCATE in interrupt
       code.

       If you decide to store directly to the audio hardware registers, you
       must either lock the channels you've allocated, or set the precedence
       to maximum (ADALLOC_MAXPREC) to prevent the channels from being
       stolen.

       Under all circumstances, unless channels are stolen, you must free
       (ADCMD_FREE) all allocated channels when you are finished using them.
