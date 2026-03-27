---
title: cd.device/CD_SEEK
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-seek
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_SEEK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_SEEK -- position laser at specified location.
   FUNCTION

       CD_SEEK moves the laser to the approximate position specified.  The
       io_Offset field should be set to the offset to which the head is
       to be positioned.
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_SEEK
       io_Offset       position where head is to be moved (always LSN format)
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
