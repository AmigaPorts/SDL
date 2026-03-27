---
title: audio.device/CMD_STOP
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-cmd-stop
functions: []
libraries: []
---

# audio.device/CMD_STOP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CMD_STOP -- stop device processing (like ^S)
```
FUNCTION

```c
    CMD_STOP is a standard command for multiple audio channels.  For each
    selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
    correct, CMD_STOP immediately stops any writes (CMD_WRITE) in
    progress; otherwise, CMD_STOP returns an error (ADIOERR_NOALLOCATION).
    [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md) queues up writes to a stopped channel until [CMD_START](autodocs-2.0/audio-device-cmd-start.md) starts
    the channel or [CMD_RESET](autodocs-2.0/audio-device-cmd-reset.md) resets the channel. CMD_STOP is synchronous
    and only replies (mn_ReplyPort) if the quick flag (IOF_QUICK) is
    clear.  Do not use CMD_STOP in interrupt code at interrupt level 5 or
    higher.
```
INPUTS

```c
    mn_ReplyPort- pointer to message port that receives I/O request after
                  if the quick flag (IOF_QUICK) is clear
    io_Device   - pointer to device node, must be set by (or copied from
                  I/O block set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function
    io_Unit     - bit map of channels to stop (bits 0 thru 3 correspond to
                  channels 0 thru 3)
    io_Command  - command number for CMD_STOP
    io_Flags    - flags, must be cleared if not used:
                  IOF_QUICK - (CLEAR) reply I/O request
    ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                  set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function or [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) command
```
OUTPUTS

```c
    io_Unit     - bit map of channels successfully stopped (bits 0 thru 3
                  correspond to channels 0 thru 3)
    io_Error    - error number:
                  0                    - no error
                  ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                         does not match key for channel
```
