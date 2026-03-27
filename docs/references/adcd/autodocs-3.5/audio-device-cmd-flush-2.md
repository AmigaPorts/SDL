---
title: audio.device/CMD_FLUSH
manual: autodocs-3.5
chapter: autodocs-3.5
section: audio-device-cmd-flush-2
functions: []
libraries: []
---

# audio.device/CMD_FLUSH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CMD_FLUSH -- cancel all pending I/O
   FUNCTION

```c
       CMD_FLUSH is a standard command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, CMD_FLUSH aborts all writes (CMD_WRITE) in progress or queued
       and any I/O requests waiting to synchronize with the end of the cycle
       (ADCMD_WAITCYCLE); otherwise, CMD_FLUSH returns an error
       (ADIOERR_NOALLOCATION).  CMD_FLUSH is synchronous and only replies
       (mn_ReplyPort) if the quick flag (IOF_QUICK) is clear.  Do not use
       CMD_FLUSH in interrupt code at interrupt level 5 or higher.
```
   INPUTS

```c
       mn_ReplyPort- pointer to message port that receives I/O request
                     if the quick flag (IOF_QUICK) is clear
       io_Device   - pointer to device node, must be set by (or copied from
                     I/O block set by) [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function
       io_Unit     - bit map of channels to flush (bits 0 thru 3 correspond
                     to channels 0 thru 3)
       io_Command  - command number for CMD_FLUSH
       io_Flags    - flags, must be cleared if not used:
                     IOF_QUICK - (CLEAR) reply I/O request
       ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                     set by) [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function or [ADCMD_ALLOCATE](autodocs-3.5/audio-device-adcmd-allocate-2.md) command
```
   OUTPUTS

```c
       io_Unit     - bit map of channels successfully flushed (bits 0 thru 3
                     correspond to channels 0 thru 3)
       io_Error    - error number:
                     0                    - no error
                     ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                            does not match key for channel
```
