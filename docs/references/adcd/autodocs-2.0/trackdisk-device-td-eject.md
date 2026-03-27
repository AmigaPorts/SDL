---
title: trackdisk.device/TD_EJECT
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-eject
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_EJECT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME
   TD_EJECT -- eject the disk in the drive, if possible.

FUNCTION

    This command causes the drive to attempt to eject the disk in
    it, if any.  Note that the current trackdisk.device does not
    implement this command, but it might in the future, and other
    trackdisk-compatible drivers may implement this command.
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_EJECT
    io_Flags        0 or IOF_QUICK
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
