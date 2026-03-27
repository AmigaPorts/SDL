---
title: cd.device/OpenDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-opendevice
functions: [CloseDevice]
libraries: [exec.library]
---

# cd.device/OpenDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       OpenDevice - [Open](autodocs-3.5/dos-library-open-2.md) a CD unit for access
```
   SYNOPSIS

```c
       error = OpenDevice("cd.device", UnitNumber, [IORequest](autodocs-3.5/include-exec-io-h.md), flags);
       D0                 A0           D0          A1         D1
```
   FUNCTION

```c
       Opens the cd.device and creates an [IORequest](autodocs-3.5/include-exec-io-h.md) for use in accessing
       the CD.
```
   INPUTS

```c
       UnitNumber - Normally zero; however, this is described as:
                    Ones digit      = [Unit](autodocs-3.5/include-exec-devices-h.md) (SCSI unit number)
                    Tens digit      = LUN (disk within disk changer)
                    Hundreds digit  = Card number (SCSI card)
                    Thousands digit = Reserved (must be zero)
       [IORequest](autodocs-3.5/include-exec-io-h.md)  - Pointer to a struct(IOStdReq)
       flags      - Should be zero.
```
   RESULTS

```c
       error        0 = success, otherwise this is an error.
```
   NOTES

   SEE ALSO

```c
       [CloseDevice()](autodocs-3.5/cd-device-closedevice.md)
```

---

## See Also

- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
