---
title: audio.device/CMD_READ
manual: autodocs-3.5
chapter: autodocs-3.5
section: audio-device-cmd-read-2
functions: []
libraries: []
---

# audio.device/CMD_READ

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CMD_READ -- normal I/O entry point
   FUNCTION

```c
       CMD_READ is a standard command for a single audio channel (io_Unit).
       If the allocation key (ioa_AllocKey) is correct, CMD_READ returns a
       pointer (io_Data) to the I/O block currently writing (CMD_WRITE) on
       the selected channel; otherwise, CMD_READ returns an error
       (ADIOERR_NOALLOCATION).  If there is no write in progress, CMD_READ
       returns zero.  CMD_READ is synchronous and only replies (mn_ReplyPort)
       if the quick bit (IOF_QUICK) is clear.
```
   INPUTS

```c
       mn_ReplyPort- pointer to message port that receives I/O request after
                     if the quick flag (IOF_QUICK) is clear
       io_Device   - pointer to device node, must be set by (or copied from
                     I/O block set by) [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function
       io_Unit     - bit map of channel to read (bit 0 thru 3 corresponds to
                     channel 0 thru 3), if more then one bit is set lowest
                     bit number channel read
       io_Command  - command number for CMD_READ
       io_Flags    - flags, must be cleared if not used:
                     IOF_QUICK - (CLEAR) reply I/O request
       ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                     set by) [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) function or [ADCMD_ALLOCATE](autodocs-3.5/audio-device-adcmd-allocate-2.md) command
```
   OUTPUTS

```c
       io_Unit     - bit map of channel successfully read (bit 0 thru 3
                     corresponds to channel 0 thru 3)
       io_Error    - error number:
                     0                    - no error
                     ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                            does not match key for channel
       ioa_Data    - pointer to I/O block for current write, zero if none is
                     progress
```
