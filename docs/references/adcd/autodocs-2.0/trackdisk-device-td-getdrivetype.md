---
title: trackdisk.device/TD_GETDRIVETYPE
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-getdrivetype
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_GETDRIVETYPE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TD_GETDRIVETYPE -- return the type of disk drive for the unit that was
                       opened.
FUNCTION

```c
    This command returns the type of the disk drive to the user.
    This number will be a small integer and will come from the set of
    DRIVEXXX constants defined in [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md).

    The only way you can actually use this command is if the trackdisk
    device understands the drive type of the hardware that is plugged in.
    This is because the [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) call will fail if the trackdisk device
    does not understand the drive type. To find raw drive identifiers see
    the disk.resource's DR_GETUNITID entry point.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_GETDRIVETYPE
    io_Flags        0 or IOF_QUICK
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
    io_Actual - if io_Error is 0 this contains the drive type connected to
                this unit.
```
SEE ALSO

```c
    [TD_GETNUMTRACKS](autodocs-2.0/trackdisk-device-td-getnumtracks.md), [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
