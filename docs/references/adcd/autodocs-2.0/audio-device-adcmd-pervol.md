---
title: audio.device/ADCMD_PERVOL
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-adcmd-pervol
functions: []
libraries: []
---

# audio.device/ADCMD_PERVOL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ADCMD_PERVOL -- change the period and volume for writes in progress to
                    audio channels
FUNCTION

```c
    ADCMD_PERVOL is a command for multiple audio channels.  For each
    selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
    correct and there is a write (CMD_WRITE) in progress, ADCMD_PERVOL
    loads a new volume and period immediately or at the end of the current
    cycle depending on the sync flag (ADIOF_SYNCCYCLE).  If the allocation
    key in incorrect, ADCMD_PERVOL returns an error
    (ADIOERR_NOALLOCATION).  ADCMD_PERVOL is synchronous and only replies
    (mn_ReplyPort) if the quick flag (IOF_QUICK) is clear.  Do not use
    ADCMD_PERVOL in interrupt code at interrupt level 5 or higher.
```
INPUTS

```c
    mn_ReplyPort- pointer to message port that receives I/O request
                  if the quick flag (IOF_QUICK) is clear
    io_Device   - pointer to device node, must be set by (or copied from
                  I/O block set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function
    io_Unit     - bit map of channels to load period and volume (bits 0
                  thru 3 correspond to channels 0 thru 3)
    io_Command  - command number for ADCMD_PERVOL
    io_Flags    - flags, must be cleared if not used:
                  IOF_QUICK      - (CLEAR) reply I/O request
                  ADIOF_SYNCCYCLE- (CLEAR) load period and volume
                                           immediately
                                   (SET) load period and volume at the end
                                         of the current cycle
    ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                  set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function or [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) command
    ioa_Period  - new sample period in 279.365 ns increments (124 thru
                  65536, anti-aliasing filter works below 300 to 500
                  depending on waveform)
    ioa_Volume  - new volume (0 thru 64, linear)
```
OUTPUTS

```c
    io_Unit     - bit map of channels that successfully loaded period and
                  volume (bits 0 thru 3 correspond to channels 0 thru 3)
    io_Error    - error number:
                  0                    - no error
                  ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                         does not match key for channel
```
