---
title: audio.device/ADCMD_SETPREC
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-adcmd-setprec
functions: []
libraries: []
---

# audio.device/ADCMD_SETPREC

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ADCMD_SETPREC -- set the allocation precedence for audio channels
FUNCTION

```c
    ADCMD_SETPREC is a command for multiple audio channels.  For each
    selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
    correct, ADCMD_SETPREC sets the allocation precedence to a new value
    (ln_Pri) and checks if there are allocation requests (ADCMD_ALLOCATE)
    waiting for the channel which now have higher precedence; otherwise,
    ADCMD_SETPREC returns an error (ADIOERR_NOALLOCATION).  ADCMD_SETPREC
    is synchronous and only replies (mn_ReplyPort) if the quick flag
    (IOF_QUICK) is clear.  Do not use ADCMD_SETPREC in interrupt code.
```
INPUTS

```c
    ln_Pri      - new allocation precedence (-128 thru 127)
    mn_ReplyPort- pointer to message port that receives I/O request
                  if the quick flag (IOF_QUICK) is clear
    io_Device   - pointer to device node, must be set by (or copied from
                  I/O block set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function
    io_Unit     - bit map of channels to set precedence (bits 0 thru 3
                  correspond to channels 0 thru 3)
    io_Command  - command number for ADCMD_SETPREC
    io_Flags    - flags, must be cleared if not used:
                  IOF_QUICK - (CLEAR) reply I/O request
    ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                  set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function or [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) command
```
OUTPUTS

```c
    io_Unit     - bit map of channels that successfully set precedence
                  (bits 0 thru 3 correspond to channels 0 thru 3)
    io_Error    - error number:
                  0                    - no error
                  ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                         does not match key for channel
```
