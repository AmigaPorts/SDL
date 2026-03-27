---
title: audio.device/ADCMD_ALLOCATE
manual: autodocs-3.5
chapter: autodocs-3.5
section: audio-device-adcmd-allocate-2
functions: []
libraries: []
---

# audio.device/ADCMD_ALLOCATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

       ADCMD_ALLOCATE -- allocate a set of audio channels
   FUNCTION

```c
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
       to allocate again whenever [ADCMD_FREE](autodocs-3.5/audio-device-adcmd-free-2.md) frees channels or [ADCMD_SETPREC](autodocs-3.5/audio-device-adcmd-setprec-2.md)
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
```
   INPUTS

```c
       ln_Pri      - allocation precedence (-128 thru 127)
       mn_ReplyPort- pointer to message port that receives I/O request after
                     the allocation completes is asynchronous or quick flag
                     (ADIOF_QUICK) is set
       io_Device   - pointer to device node, must be set by (or copied from
                     I/O block set by) [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function
       io_Command  - command number for ADCMD_ALLOCATE
       io_Flags    - flags, must be cleared if not used:
                     IOF_QUICK   - (CLEAR) reply I/O request
                                   (SET) only reply I/O request only if
                                         asynchronous (see above text)
                     ADIOF_NOWAIT- (CLEAR) if allocation fails, wait till is
                                           succeeds
                                   (SET) if allocation fails, return error
                                         (ADIOERR_ALLOCFAILED)
       ioa_AllocKey- allocation key, zero to generate new key; otherwise,
                     it must be set by (or copied from I/O block set by)
                     [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function or previous ADCMD_ALLOCATE command
       ioa_Data    - pointer to channel combination options (byte array, bits
                     0 thru 3 correspond to channels 0 thru 3)
       ioa_Length  - length of the channel combination option array
                     (0 thru 16, 0 always succeeds)
```
   OUTPUTS

```c
       io_Unit     - bit map of successfully allocated channels (bits 0 thru
                     3 correspond to channels 0 thru 3)
       io_Flags    - IOF_QUICK flag cleared if asynchronous (see above text)
       io_Error    - error number:
                     0                   - no error
                     ADIOERR_ALLOCFAILED - allocation failed
       ioa_AllocKey- allocation key, set to a unique number if passed a zero
                     and command succeeds
```
