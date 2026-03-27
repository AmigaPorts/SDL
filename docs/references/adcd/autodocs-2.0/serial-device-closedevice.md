---
title: serial.device/CloseDevice
manual: autodocs-2.0
chapter: autodocs-2.0
section: serial-device-closedevice
functions: [AbortIO, WaitIO]
libraries: [exec.library, timer.device]
---

# serial.device/CloseDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CloseDevice -- close the serial port
SYNOPSIS
```c
    CloseDevice(deviceNode)
                 A1
```
FUNCTION

```c
    This is an exec call that terminates communication with the
    serial device.  Upon closing, the device's input buffer is freed.

    Note that all IORequests MUST be complete before closing.
     If any are pending, your program must [AbortIO()](autodocs-2.0/serial-device-abortio.md) then [WaitIO()](autodocs-2.0/exec-library-waitio.md)
    to complete them.
```
INPUTS

    deviceNode - pointer to the device node, set by Open
SEE ALSO

```c
    [serial.device/OpenDevice](autodocs-2.0/serial-device-opendevice.md)
```

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
