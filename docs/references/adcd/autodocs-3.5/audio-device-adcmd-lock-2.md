---
title: audio.device/ADCMD_LOCK
manual: autodocs-3.5
chapter: autodocs-3.5
section: audio-device-adcmd-lock-2
functions: []
libraries: []
---

# audio.device/ADCMD_LOCK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       ADCMD_LOCK -- prevent audio channels from being stolen
   FUNCTION

```c
       ADCMD_LOCK is a command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, ADCMD_LOCK locks the channel, preventing subsequent
       allocations (ADCMD_ALLOCATE or OpenDevice) from stealing the channel.
       Otherwise, ADCMD_LOCK returns an error (ADIOERR_NOALLOCATION) and will
       not lock any channels.

       Unlike setting the precedence (ADCMD_SETPREC, [ADCMD_ALLOCATE](autodocs-3.5/audio-device-adcmd-allocate-2.md) or
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
```
   INPUTS

```c
       mn_ReplyPort- pointer to message port that receives I/O request
                     if the quick flag (IOF_QUICK) is clear
       io_Device   - pointer to device node, must be set by (or copied from
                     I/O block set by) [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function
       io_Unit     - bit map of channels to lock (bits 0 thru 3 correspond to
                     channels 0 thru 3)
       io_Command  - command number for ADCMD_LOCK
       io_Flags    - flags, must be cleared
       ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                     set by) [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function or [ADCMD_ALLOCATE](autodocs-3.5/audio-device-adcmd-allocate-2.md) command
```
   OUTPUTS

```c
       io_Unit     - bit map of successfully locked channels (bits 0 thru 3
                     correspond to channels 0 thru 3) not freed (ADCMD_FREE)
       io_Flags    - IOF_QUICK flag cleared if the allocation key is correct
                     (no ADIOERR_NOALLOCATION error)
       io_Error    - error number:
                     0                    - no error
                     ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                            does not match key for channel
                     ADIOERR_CHANNELSTOLEN- allocation attempting to steal
                                            locked channel
```
