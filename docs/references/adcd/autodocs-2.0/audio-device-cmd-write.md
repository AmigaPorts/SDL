---
title: audio.device/CMD_WRITE
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-cmd-write
functions: []
libraries: []
---

# audio.device/CMD_WRITE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_WRITE -- normal I/O entry point
FUNCTION
```c
    CMD_WRITE is a standard command for a single audio channel (io_Unit).
    If the allocation key (ioa_AllocKey) is correct, CMD_WRITE plays a
    sound using the selected channel; otherwise, it returns an error
    (ADIOERR_NOALLOCATION).  CMD_WRITE queues up requests if there is
    another write in progress or if the channel is stopped (CMD_STOP).
    When the write actually starts; if the ADIOF_PERVOL flag is set,
    CMD_WRITE loads volume (ioa_Volume) and period (ioa_Period), and if
    the ADIOF_WRITEMESSAGE flag is set, CMD_WRITE replies the write
    message (ioa_WriteMsg).  CMD_WRITE returns an error (IOERR_ABORTED) if
    it is canceled (AbortIO) or the channel is stolen (ADCMD_ALLOCATE).
    CMD_WRITE is only asynchronous if there is no error, in which case it
    clears the quick flag (IOF_QUICK) and replies the I/O request
    (mn_ReplyPort) after it finishes writting; otherwise, it is synchronou
```
s

```c
    and only replies if the quick flag (IOF_QUICK) is clear.  Do not use
    CMD_WRITE in interrupt code at interrupt level 5 or higher.
```
INPUTS

```c
    mn_ReplyPort- pointer to message port that receives I/O request after
                  the write completes
    io_Device   - pointer to device node, must be set by (or copied from
                  I/O block set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function
    io_Unit     - bit map of channel to write (bit 0 thru 3 corresponds to
                  channel 0 thru 3), if more then one bit is set lowest
                  bit number channel is written
    io_Command  - command number for CMD_WRITE
    io_Flags    - flags, must be cleared if not used:
                  ADIOF_PERVOL       - (SET) load volume and period
                  ADIOF_WRITEMESSAGE - (SET) reply message at write start
    ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                  set by) [OpenDevice](autodocs-2.0/audio-device-opendevice.md) function or [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) command
    ioa_Data    - pointer to waveform array (signed bytes (-128 thru 127)
                  in custom chip addressable ram and word aligned)
    ioa_Length  - length of the wave array in bytes (2 thru 131072, must
                  be even number)
    ioa_Period  - sample period in 279.365 ns increments (124 thru 65536,
                  anti-aliasing filter works below 300 to 500 depending on
                  waveform), if enabled by ADIOF_PERVOL
    ioa_Volume  - volume (0 thru 64, linear), if enabled by ADIOF_PERVOL
    ioa_Cycles  - number of times to repeat array (0 thru 65535, 0 for
                  infinite)
    ioa_WriteMsg- message replied at start of write,  if enabled by
                  ADIOF_WRITEMESSAGE
```
OUTPUTS

```c
    io_Unit     - bit map of channel successfully written (bit 0 thru 3
                  corresponds to channel 0 thru 3)
    io_Flags    - IOF_QUICK flag cleared if there is no error
    io_Error    - error number:
                  0                    - no error
                  IOERR_ABORTED        - canceled (AbortIO) or channel
                                         stolen
                  ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                         does not match key for channel
```
BUGS

```c
    If CMD_WRITE starts the write immediately after stopping a previous
    write, you must set the ADIOF_PERVOL flag or else the new data pointer
    (ioa_Data) and length (ioa_Length) may not be loaded.
```
