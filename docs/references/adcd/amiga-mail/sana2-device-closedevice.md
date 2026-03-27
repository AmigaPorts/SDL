---
title: sana2.device/CloseDevice
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-closedevice
functions: [AbortIO, CloseDevice, OpenDevice, WaitIO]
libraries: [exec.library, timer.device]
---

# sana2.device/CloseDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CloseDevice -- Close the device.
SYNOPSIS

```c
    CloseDevice(Sana2Req)
                A1

    void CloseDevice(struct IOSana2Req *);
```
FUNCTION

```c
    This function is called by exec.library CloseDevice().

    This function performs whatever cleanup is required at device closes.

    Note that all IORequests MUST be complete before closing. If any are
    pending, your program must AbortIO() then WaitIO() each outstanding
    IORequest to complete them.
```
INPUTS

```c
    Sana2Req        - Pointer to IOSana2Req initialized by OpenDevice().
```
NOTES

SEE ALSO

```c
    exec.library/CloseDevice(), exec.library/OpenDevice()
```
BUGS

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
