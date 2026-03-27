---
title: cd.device/CD_GETGEOMETRY
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-getgeometry
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_GETGEOMETRY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_GETGEOMETRY -- return the geometry of the drive.
   FUNCTION

```c
       This command returns a full set of information about the
       layout of the drive. The information is returned in the
       [DriveGeometry](autodocs-3.5/include-devices-trackdisk-h.md) structure pointed to by io_Data.
```
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_GETGEOMETRY
       io_Data         pointer to a [DriveGeometry](autodocs-3.5/include-devices-trackdisk-h.md) structure
       io_Length       sizeof(struct DriveGeometry)
```
   IO REQUEST RESULT

```c
       io_Error  - 0 for success, or an error code as defined in
                   [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
       io_Actual - length of data transferred.
```
   SEE ALSO

```c
       CD_GETNUMTRACKS, [<devices/trackdisk.h>](autodocs-3.5/include-devices-trackdisk-h.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
