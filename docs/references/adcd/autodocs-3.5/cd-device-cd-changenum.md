---
title: cd.device/CD_CHANGENUM
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-changenum
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_CHANGENUM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_CHANGENUM -- return the current value of the disk-change counter.
   FUNCTION

       This command returns the current value of the disk-change counter
       The disk change counter is incremented each time a disk is inserted
       or removed from the cd unit.
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_CHANGENUM
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
       io_Actual - if io_Error is 0, this contains the current value of the
                   disk-change counter.
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
