---
title: trackdisk.device/TD_GETNUMTRACKS
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-getnumtracks
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_GETNUMTRACKS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TD_GETNUMTRACKS -- return the number of tracks for the type of disk
                       drive for the unit that was opened.
FUNCTION

    This command returns the number of tracks that are available
    on the disk unit.
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_GETNUMTRACKS
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
    [TD_GETDRIVETYPE](autodocs-2.0/trackdisk-device-td-getdrivetype.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
