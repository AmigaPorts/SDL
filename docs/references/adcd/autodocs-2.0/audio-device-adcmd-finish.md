---
title: audio.device/ADCMD_FINISH
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-adcmd-finish
functions: []
libraries: []
---

# audio.device/ADCMD_FINISH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ADCMD_FINISH -- abort writes in progress to audio channels
FUNCTION

```c
    ADCMD_FINISH is a command for multiple audio channels.  For each
    selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
    correct and there is a write (CMD_WRITE)in progress, ADCMD_FINISH
    aborts the current write immediately or at the end of the current
    cycle depending on the sync flag (ADIOF_SYNCCYCLE).  If the allocation
    key is incorrect ADCMD_FINISH returns an error (ADIOERR_NOALLOCATION).
    ADCMD_FINISH is synchronous and only replies (mn_ReplyPort) if the
    quick flag (IOF_QUICK) is clear.  Do not use ADCMD_FINISH in interrupt
    code at interrupt level 5 or higher.
```
INPUTS

```c
    mn_ReplyPort- pointer to message port that receives I/O request
                  if the quick flag (IOF_QUICK) is clear
    io_Device   - pointer to device node, must be set by (or copied from
                  I/O block set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function
    io_Unit     - bit map of channels to finish (bits 0 thru 3 correspond
                  to channels 0 thru 3)
    io_Command  - command number for ADCMD_FINISH
    io_Flags    - flags, must be cleared if not used:
                  IOF_QUICK      - (CLEAR) reply I/O request
                  ADIOF_SYNCCYCLE- (CLEAR) finish immediately
                                   (SET) finish at the end of current
                                         cycle

    ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                  set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function or [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) command
```
OUTPUTS

```c
    io_Unit     - bit map of channels successfully finished (bits 0 thru 3
                  correspond to channels 0 thru 3)
    io_Error    - error number:
                  0                    - no error
                  ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                         does not match key for channel
```
