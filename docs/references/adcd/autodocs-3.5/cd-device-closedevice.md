---
title: cd.device/CloseDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-closedevice
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CloseDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CloseDevice - terminate access to the CD
   SYNOPSIS

```c
       CloseDevice(IORequest);
                   A1
```
   FUNCTION

```c
       This function will terminate access to the unit openned with
       [OpenDevice()](autodocs-3.5/cd-device-opendevice.md).
```
   INPUTS

```c
       iORequest - pointer to a struct(IOStdReq)
```
   RESULTS

   NOTES

   SEE ALSO

```c
       [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
