---
title: trackdisk.device/TD_RAWWRITE
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-rawwrite
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_RAWWRITE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TD_RAWWRITE/ETD_RAWWRITE -- write raw data to the disk.
FUNCTION

```c
    This command writes a track of raw data from the provided buffer to
    the specified track on disk. The data is copied straight to the disk
    with no processing done on it. It will appear exactly on the disk as
    it is in the memory buffer, hopefully in a legal MFM format.

    This interface is intended for sophisticated programmers only.
    Commodore-Amiga reserves the right to make enhancements to the disk
    format in the future. We will provide compatibility via the
    [CMD_WRITE](autodocs-2.0/trackdisk-device-cmd-write.md) and ETD_WRITE commands, anyone using TD_RAWWRITE is
    bypassing this upwards compatibility, and may thus stop working.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_RAWWRITE or ETD_RAWWRITE.
    io_Flags        if the IOTDB_INDEXSYNC bit is set then the driver
                    will make a best effort attempt to start writing
                    from the index mark.  Note that there will be at
                    least some delay, and perhaps a great deal of delay
                    (for example if interrupts have been disabled).
    io_Length       Length of buffer in bytes, with a maximum of 32768
                    bytes.
    io_Data         Pointer to CHIP memory buffer where raw track data is
                    to be taken.
    io_Offset       The number of the track to write to.
    iotd_Count      (ETD_RAWWRITE only) maximum allowable change counter
                    value.
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
```
NOTES

```c
    The track buffer provided MUST be in CHIP memory

    There is a delay between the index pulse and the start of bits
    going out to the driver (e.g. write gate enabled). This delay
    is in the range of 135-200 microseconds. This delay breaks
    down as follows: 55 microsecs is software interrupt overhead
    (this is the time from interrupt to the write of the DSKLEN
    register). 66 microsecs is one horizontal line delay (remember
    that disk IO is synchronized with agnus' display fetches).
    The last variable (0-65 microsecs) is an additional scan line
    since DSKLEN is poked anywhere in the horizontal line. This leaves
    15 microsecs unaccounted for...  Sigh.

    In short, You will almost never get bits within the first 135
    microseconds of the index pulse, and may not get it until 200
    microseconds. At 4 microsecs/bit, this works out to be between
    4 and 7 bytes of user data of delay.
```
BUGS

    This command does not work reliably under versions of Kickstart
    earlier than V36, especially on systems with 1 floppy drive.
SEE ALSO

```c
    [TD_RAWREAD](autodocs-2.0/trackdisk-device-td-rawread.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
