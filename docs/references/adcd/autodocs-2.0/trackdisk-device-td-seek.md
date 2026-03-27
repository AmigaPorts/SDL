---
title: trackdisk.device/TD_SEEK
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-seek
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_SEEK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TD_SEEK/ETD_SEEK -- control positioning of the drive heads.
FUNCTION

```c
    These commands are currently provided for internal diagnostics,
    disk repair, and head cleaning only.

    TD_SEEK and ETD_SEEK move the drive heads to the track specified. The
    io_Offset field should be set to the (byte) offset to which the seek is
    to occur. TD_SEEK and ETD_SEEK do not verify their position until the
    next read. That is, they only move the heads; they do not actually read
    any data.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_SEEK or ETD_SEEK
    io_Flags        0 or IOF_QUICK
    io_Offset       byte offset from the start of the disk describing
                    where to move the head to.
    iotd_Count      (ETD_SEEK only) maximum allowable change counter
                    value.
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
