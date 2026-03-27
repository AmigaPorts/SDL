---
title: trackdisk.device/TD_CHANGENUM
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-changenum
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_CHANGENUM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TD_CHANGENUM -- return the current value of the disk-change counter.
FUNCTION

```c
    This command returns the current value of the disk-change counter (as
    used by the enhanced commands). The disk change counter is incremented
    each time a disk is inserted or removed from the trackdisk unit.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_CHANGENUM
    io_Flags        0 or IOF_QUICK
```
IO REQUEST RESULT

```c
    io_Error  - 0 for success, or an error code as defined in
                [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
    io_Actual - if io_Error is 0, this contains the current value of the
                disk-change counter.
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
