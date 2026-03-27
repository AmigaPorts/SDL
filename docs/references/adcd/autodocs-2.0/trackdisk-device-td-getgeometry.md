---
title: trackdisk.device/TD_GETGEOMETRY
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-getgeometry
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_GETGEOMETRY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME
   TD_GETGEOMETRY -- return the geometry of the drive.

FUNCTION

```c
    This command returns a full set of information about the
    layout of the drive. The information is returned in the
    [DriveGeometry](autodocs-2.0/includes-devices-trackdisk-h.md) structure pointed to by io_Data.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_GETGEOMETRY
    io_Flags        0 or IOF_QUICK
    io_Data         Pointer to a [DriveGeometry](autodocs-2.0/includes-devices-trackdisk-h.md) structure
    io_Length       sizeof(struct DriveGeometry)
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
```
NOTE

    This information may change when a disk in inserted when
    certain hardware is present.
SEE ALSO

```c
    [TD_GETDRIVETYPE](autodocs-2.0/trackdisk-device-td-getdrivetype.md), [TD_GETNUMTRACKS](autodocs-2.0/trackdisk-device-td-getnumtracks.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
