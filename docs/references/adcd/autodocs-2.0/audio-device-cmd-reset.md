---
title: audio.device/CMD_RESET
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-cmd-reset
functions: []
libraries: []
---

# audio.device/CMD_RESET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_RESET -- restore device to a known state
FUNCTION

```c
    CMD_RESET is a standard command for multiple audio channels.  For each
    selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
    correct, CMD_RESET:
      . clears the hardware audio registers and attach bits,
      . sets the audio interrupt vector,
      . cancels all pending I/O (CMD_FLUSH), and
      . un-stops the channel if it is stopped (CMD_STOP),

    Otherwise, CMD_RESET returns an error (ADIOERR_NOALLOCATION).
    CMD_RESET is synchronous and only replies (mn_ReplyPort) if the quick
    flag (IOF_QUICK) is clear.  Do not use CMD_RESET in interrupt code at
    interrupt level 5 or higher.
```
INPUTS

```c
    mn_ReplyPort- pointer to message port that receives I/O request
                  if the quick flag (IOF_QUICK) is clear
    io_Device   - pointer to device node, must be set by (or copied from
                  I/O block set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function
    io_Unit     - bit map of channels to reset (bits 0 thru 3 correspond
                  to channels 0 thru 3)
    io_Command  - command number for CMD_RESET
    io_Flags    - flags, must be cleared if not used:
                  IOF_QUICK - (CLEAR) reply I/O request
    ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                  set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function or [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) command
```
OUTPUTS

```c
    io_Unit     - bit map of channels to successfully reset (bits 0 thru 3
                  correspond to channels 0 thru 3)
    io_Error    - error number:
                  0                    - no error
                  ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                         does not match key for channel
```
