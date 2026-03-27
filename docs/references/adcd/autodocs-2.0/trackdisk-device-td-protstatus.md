---
title: trackdisk.device/TD_PROTSTATUS
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-protstatus
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_PROTSTATUS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TD_PROTSTATUS -- return whether the current disk is write-protected.
FUNCTION

    This command is used to determine whether the current disk is
    write-protected.
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_PROTSTATUS
    io_Flags        0 or IOF_QUICK
```
IO REQUEST RESULT

```c
    io_Error  - 0 for success, or an error code as defined in
                [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
    io_Actual - if io_Error is 0, this tells you whether the disk in the
                drive is write-protected. 0 means the disk is NOT write-
                protected, while any other value indicates it is.
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
