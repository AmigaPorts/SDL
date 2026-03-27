---
title: trackdisk.device/TD_FORMAT
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-format
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_FORMAT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TD_FORMAT/ETD_FORMAT -- format a track on a disk.
FUNCTION

```c
    These commands are used to write data to a track that either
    has not yet been formatted or has had a hard error on a standard write
    command. TD_FORMAT completely ignores all data currently on a track and
    does not check for disk change before performing the command. The
    io_Data field must point to at least one track worth of data. The
    io_Offset field must be track aligned, and the io_Length field must be
    in units of track length (that is, NUMSEC*TD_SECTOR).

    The device will format the requested tracks, filling each sector with
    the contents of the buffer pointed to by io_Data. You
    should do a read pass to verify the data.

    If you have a hard write error during a normal write, you may find it
    possible to use the TD_FORMAT command to reformat the track as part of
    your error recovery process. ETD_FORMAT will write the sector label
    area if iotd_SecLabel is non-NULL.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_FORMAT or ETD_FORMAT
    io_Flags        0 or IOF_QUICK
    io_Data         points to a buffer containing the data to write to the
                    track, must be at least as large as io_Length.
    io_Length       number of bytes to format, must be a multiple of
                    (TD_SECTORS * NUMSEC).
    io_Offset       byte offset from the start of the disk for the track to
                    format, must be a multiple of (TD_SECTORS * NUMSEC).
    iotd_Count      (ETD_FORMAT only) maximum allowable change counter
                    value.
    iotd_SecLabel   (ETD_FORMAT only) NULL or sector label buffer pointer.
                    If provided, the buffer must be a multiple of
                    (TD_LABELSIZE * NUMSEC).
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
```
NOTES

    Under versions of Kickstart earlier than V36, the io_Data had to
    point to a buffer in chip memory. This restriction is no longer
    present as of Kickstart V36 and beyond.
SEE ALSO

```c
    [CMD_WRITE](autodocs-2.0/trackdisk-device-cmd-write.md), [TD_RAWWRITE](autodocs-2.0/trackdisk-device-td-rawwrite.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
