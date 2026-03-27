---
title: trackdisk.device/CMD_READ
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-cmd-read
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/CMD_READ

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_READ/ETD_READ -- read sectors of data from a disk.
FUNCTION

    These commands transfer data from the track buffer to a supplied
    buffer. If the desired sector is already in the track buffer, no disk
    activity is initiated. If the desired sector is not in the buffer, the
    track containing that sector is automatically read in. If the data in
    the current track buffer has been modified, it is written out to the
    disk before a new track is read. ETD_READ will read the sector label
    area if the iotd_SecLabel is non-NULL.
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CMD_READ or ETD_READ
    io_Flags        0 or IOF_QUICK
    io_Data         pointer to the buffer where the data should be put
    io_Length       number of bytes to read, must be a multiple of
                    TD_SECTOR.
    io_Offset       byte offset from the start of the disk describing
                    where to read data from, must be a multiple of
                    TD_SECTOR.
    iotd_Count      (ETD_READ only) maximum allowable change counter
                    value.
    iotd_SecLabel   (ETD_READ only) NULL or sector label buffer pointer.
                    If provided, the buffer must be a multiple of
                    TD_LABELSIZE.
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
    [CMD_WRITE](autodocs-2.0/trackdisk-device-cmd-write.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
