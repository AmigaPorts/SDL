---
title: audio.device/CMD_UPDATE
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-cmd-update
functions: []
libraries: []
---

# audio.device/CMD_UPDATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_UPDATE -- force dirty buffers out
FUNCTION

```c
    CMD_UPDATE is a standard command for multiple audio channels.  For
    each selected channel (io_Unit), if the allocation key (ioa_AllocKey)
    is correct, CMD_UPDATE does nothing; otherwise, CMD_UPDATE returns an
    error (ADIOERR_NOALLOCATION).  CMD_UPDATE is synchronous and only
    replies (mn_ReplyPort) if the quick flag (IOF_QUICK) is clear.
```
INPUTS

```c
    mn_ReplyPort- pointer to message port that receives I/O request after
                  if the quick flag (IOF_QUICK) is clear
    io_Device   - pointer to device node, must be set by (or copied from
                  I/O block set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function
    io_Unit     - bit map of channels to update (bits 0 thru 3 correspond
                  to channels 0 thru 3)
    io_Command  - command number for CMD_UPDATE
    io_Flags    - flags, must be cleared if not used:
                  IOF_QUICK - (CLEAR) reply I/O request
    ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                  set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function or [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) command
```
OUTPUTS

```c
    io_Unit     - bit map of channels successfully updated (bits 0 thru 3
                  correspond to channels 0 thru 3)
    io_Error    - error number:
                  0                    - no error
                  ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                         does not match key for channel
```
