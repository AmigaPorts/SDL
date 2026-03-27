---
title: audio.device/ADCMD_FREE
manual: autodocs-3.5
chapter: autodocs-3.5
section: audio-device-adcmd-free-2
functions: []
libraries: []
---

# audio.device/ADCMD_FREE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       ADCMD_FREE -- free audio channels for allocation
   FUNCTION

```c
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
```
   INPUTS

```c
       mn_ReplyPort- pointer to message port that receives I/O request
                     if the quick flag (IOF_QUICK) is clear
       io_Device   - pointer to device node, must be set by (or copied from
                     I/O block set by) [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function
       io_Unit     - bit map of channels to free (bits 0 thru 3 correspond to
                     channels 0 thru 3)
       io_Command  - command number for ADCMD_FREE
       io_Flags    - flags, must be cleared if not used:
                     IOF_QUICK - (CLEAR) reply I/O request
       ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                     set by) [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function or [ADCMD_ALLOCATE](autodocs-3.5/audio-device-adcmd-allocate-2.md) command
```
   OUTPUTS

```c
       io_Unit     - bit map of channels successfully freed (bits 0 thru 3
                     correspond to channels 0 thru 3)
       io_Error    - error number:
                     0                    - no error
                     ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                            does not match key for channel
```
