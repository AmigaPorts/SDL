---
title: audio.device/CMD_START
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-cmd-start
functions: []
libraries: []
---

# audio.device/CMD_START

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CMD_START -- start device processing (like ^Q)
```
FUNCTION
```c
    CMD_START is a standard command for multiple audio channels.  For each
    selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
    correct and the channel was previously stopped (CMD_STOP), CMP_START
    immediately starts all writes (CMD_WRITE) to the channel.  If the
    allocation key is incorrect, CMD_START returns an error
    (ADIOERR_NOALLOCATION).  CMD_START starts multiple channels
    simultaneously to minimize distortion if the channels are playing the
    same waveform and their outputs are mixed. CMD_START is synchronous an
```
d
```c
    only replies (mn_ReplyPort) if the quick flag (IOF_QUICK) is clear.  D
```
o

    not use CMD_START in interrupt code at interrupt level 5 or higher.
INPUTS

```c
    mn_ReplyPort- pointer to message port that receives I/O request after
                  if the quick flag (IOF_QUICK) is clear
    io_Device   - pointer to device node, must be set by (or copied from
                  I/O block set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function
    io_Unit     - bit map of channels to start (bits 0 thru 3 correspond
                  to channels 0 thru 3)
    io_Command  - command number for CMD_START
    io_Flags    - flags, must be cleared if not used:
                  IOF_QUICK - (CLEAR) reply I/O request
    ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                  set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function or [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) command
```
OUTPUTS

```c
    io_Unit     - bit map of channels successfully started (bits 0 thru 3
                  correspond to channels 0 thru 3)
    io_Error    - error number:
                  0                    - no error
                  ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                         does not match key for channel
```
