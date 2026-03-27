---
title: cd.device/CD_PROTSTATUS
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-protstatus
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_PROTSTATUS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_PROTSTATUS -- return whether the current disk is write-protected.
   FUNCTION

       This command is used to determine whether the current disk is
       write-protected.  Currently, this function always returns write-
       protected status.  If write-once CDs are made available at some point,
       this may change.
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_PROTSTATUS
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
       io_Actual - 0 means the disk is NOT write-protected, while any other
                   value indicates it is.
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
