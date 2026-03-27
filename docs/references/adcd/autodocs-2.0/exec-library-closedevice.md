---
title: exec.library/CloseDevice
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-closedevice
functions: [CloseDevice]
libraries: [exec.library]
---

# exec.library/CloseDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CloseDevice -- conclude access to a device
SYNOPSIS

```c
    CloseDevice(iORequest)
                A1

    void CloseDevice(struct [IORequest](autodocs-2.0/includes-exec-io-h.md) *);
```
FUNCTION

```c
    This function informs the device that access to a device/unit
    previously opened has been concluded.  The device may perform
    certain house-cleaning operations.

    The user must ensure that all outstanding IORequests have been
    returned before closing the device.  The [AbortIO](autodocs-2.0/timer-device-abortio.md) function can kill
    any stragglers.

    After a close, the I/O request structure is free to be reused.
    Starting with V36 exec it is safe to CloseDevice() with an
    [IORequest](autodocs-2.0/includes-exec-io-h.md) that is either cleared to zeros, or failed to
    open.
```
INPUTS

    iORequest - pointer to an I/O request structure
SEE ALSO

```c
    [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
```

---

## See Also

- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
