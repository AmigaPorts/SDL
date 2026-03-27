---
title: audio.device/CMD_CLEAR
manual: autodocs-3.5
chapter: autodocs-3.5
section: audio-device-cmd-clear-2
functions: []
libraries: []
---

# audio.device/CMD_CLEAR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CMD_CLEAR -- throw away internal caches
   FUNCTION

```c
       CMD_CLEAR is a standard command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, CMD_CLEAR does nothing; otherwise, CMD_CLEAR returns an error
       (ADIOERR_NOALLOCATION).  CMD_CLEAR is synchronous and only replies
       (mn_ReplyPort) if the quick flag (IOF_QUICK) is clear.
```
   INPUTS

```c
       mn_ReplyPort- pointer to message port that receives I/O request after
                     if the quick flag (IOF_QUICK) is clear
       io_Device   - pointer to device node, must be set by (or copied from
                     I/O block set by) [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function
       io_Unit     - bit map of channels to clear (bits 0 thru 3 correspond
                     to channels 0 thru 3)
       io_Command  - command number for CMD_CLEAR
       io_Flags    - flags, must be cleared if not used:
                     IOF_QUICK - (CLEAR) reply I/O request
       ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                     set by) [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function or [ADCMD_ALLOCATE](autodocs-3.5/audio-device-adcmd-allocate-2.md) command
```
   OUTPUTS

```c
       io_Unit     - bit map of channels successfully cleared (bits 0 thru 3
                     correspond to channels 0 thru 3)
       io_Error    - error number:
                     0                    - no error
                     ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                            does not match key for channel
```
