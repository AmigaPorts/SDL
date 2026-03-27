---
title: cd.device/CD_CHANGESTATE
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-changestate
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_CHANGESTATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_CHANGESTATE -- check if a "valid" disk is currently in a drive.
   FUNCTION

       This command checks to see if there is a "valid" disk in a drive.
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_CHANGESTATE
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
       io_Actual - 0 means there is a disk while anything else indicates
                   there is no disk.
```
   NOTES

       A "valid" disk is a disk with a readable table of contents.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
