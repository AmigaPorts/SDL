---
title: trackdisk.device/TD_CHANGESTATE
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-changestate
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_CHANGESTATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TD_CHANGESTATE -- check if a disk is currently in a drive.
FUNCTION

    This command checks to see if there is currently a disk in a drive.
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_CHANGESTATE
    io_Flags        0 or IOF_QUICK
```
IO REQUEST RESULT

```c
    io_Error  - 0 for success, or an error code as defined in
                [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
    io_Actual - if io_Error is 0, this tells you whether a disk is in
                the drive. 0 means there is a disk, while anything else
                indicates there is no disk.
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
