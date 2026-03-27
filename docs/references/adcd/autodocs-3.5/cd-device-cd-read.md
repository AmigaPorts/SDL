---
title: cd.device/CD_READ
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-read
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_READ

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_READ -- read data from disk.
   FUNCTION

```c
       Reads data from the CD into memory.  Data may be accessed on WORD
       boundaries (you are not restricted to sector boundaries as with
       normal disk devices).  Data lengths can also be described in WORD
       amounts.
```
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_READ
       io_Data         pointer to the buffer where the data should be put
       io_Length       number of bytes to read, must be a WORD multiple.
       io_Offset       byte offset from the start of the disk describing
                       where to read data from, must be a WORD multiple.
```
   IO REQUEST RESULT

```c
       io_Error  - 0 for success, or an error code as defined in
                   [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
       io_Actual - if io_Error is 0, number of bytes actually transferred
```
   NOTES

       If an error occurs when attempting a CD_READ, the software will
       retry up to 10 times before giving up on the request.  If the
       drive is in double-speed and an error occurs, the software will
       retry once more in double-speed, and if this fails, will retry
       the next 9 times in single-speed.
   SEE ALSO

```c
       [CD_READXL](autodocs-3.5/cd-device-cd-readxl.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
