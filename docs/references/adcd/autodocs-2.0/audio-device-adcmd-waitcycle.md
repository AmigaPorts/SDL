---
title: audio.device/ADCMD_WAITCYCLE
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-adcmd-waitcycle
functions: []
libraries: []
---

# audio.device/ADCMD_WAITCYCLE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ADCMD_WAITCYCLE -- wait for an audio channel to complete the current
                       cycle of a write
FUNCTION

```c
    ADCMD_WAITCYCLE is a command for a single audio channel (io_Unit).
    If the allocation key (ioa_AllocKey) is correct and there is a write
    (CMD_WRITE) in progress on selected channel, ADCMD_WAITCYCLE does not
    reply (mn_ReplyPort) until the end of the current cycle.  If there is
    no write is progress, ADCMD_WAITCYCLE replies immediately.  If the
    allocation key is incorrect, ADCMD_WAITCYCLE returns an error
    (ADIOERR_NOALLOCATION).  ADCMD_WAITCYCLE returns an error
    (IOERR_ABORTED) if it is canceled (AbortIO) or the channel is stolen
    (ADCMD_ALLOCATE).  ADCMD_WAITCYCLE is only asynchronous if it is
    waiting for a cycle to complete, in which case it clears the quick
    flag (IOF_QUICK); otherwise, it is synchronous and only replies if the
    quick flag (IOF_QUICK) is clear.  Do not use ADCMD_WAITCYCLE in
    interrupt code at interrupt level 5 or higher.
```
INPUTS

```c
    mn_ReplyPort- pointer to message port that receives I/O request, if
                  the quick flag (IOF_QUICK) is clear, or if a write is in
                  progress on the selected channel and a cycle has
                  completed
    io_Device   - pointer to device node, must be set by (or copied from
                  I/O block set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function
    io_Unit     - bit map of channel to wait for cycle (bits 0 thru 3
                  correspond to channels 0 thru 3), if more then one bit
                  is set lowest bit number channel is used
    io_Command  - command number for CMD_WAITCYCLE
    io_Flags    - flags, must be cleared if not used:
                  IOF_QUICK - (CLEAR) reply I/O request
                              (SET) only reply I/O request if a write is
                                    in progress on the selected channel
                                    and a cycle has completed
    ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                  set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function or [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) command
```
OUTPUTS

```c
    io_Unit     - bit map of channel that successfully waited for cycle
                  (bits 0 thru 3 correspond to channels 0 thru 3)
    io_Flags    - IOF_QUICK flag cleared if a write is in progress on the
                  selected channel
    io_Error    - error number:
                  0                    - no error
                  IOERR_ABORTED        - canceled (AbortIO) or channel
                                         stolen
                  ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                         does not match key for channel
```
