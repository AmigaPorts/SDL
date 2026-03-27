---
title: sana2.device/OpenDevice
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-opendevice
functions: [CloseDevice, OpenDevice]
libraries: [exec.library]
---

# sana2.device/OpenDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Open -- Request an opening of the network device.
SYNOPSIS

```c
    error = OpenDevice(unit, IOSana2Req, flags)
    D0                 D0    A1          D1

    BYTE OpenDevice(ULONG, struct IOSana2Req *, ULONG);
```
FUNCTION

```c
    This function is called by exec.library OpenDevice().

    This function performs whatever initialization is required per
    device open and initializes the Sana2Req for use by the
    device.
```
INPUTS

    unit            - Device unit to open.
    Sana2Req        - Pointer to IOSana2Req structure to be initialized by
                      the sana2.device.
    flags           - Supported flags are:
                            SANA2OPB_MINE
                            SANA2OPB_PROM
    ios2_BufferManagement   - A pointer to a tag list containing
                              pointers to buffer management functions.
RESULTS

```c
    error           - same as io_Error
    io_Error        - Zero if successful; non-zero otherwise.
    io_Device       - A pointer to whatever device will handle the calls
                      for this unit.  This pointer may be different
                      depending on what unit is requested.
    ios2_BufferManagement   - A pointer to device internal information
                              used to call buffer management functions.
```
NOTES

SEE ALSO

```c
    exec.library/OpenDevice(), exec.library/CloseDevice()
```
BUGS

---

## See Also

- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
