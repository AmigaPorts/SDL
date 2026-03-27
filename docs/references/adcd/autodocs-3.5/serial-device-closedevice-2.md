---
title: serial.device/CloseDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: serial-device-closedevice-2
functions: [AbortIO, OpenDevice, WaitIO]
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
       This is an exec call that terminates communication with the
       serial device.  Upon closing, the device's input buffer is freed.

       Note that all IORequests MUST be complete before closing.
	If any are pending, your program must [AbortIO()](autodocs-3.5/serial-device-abortio-2.md) then [WaitIO()](autodocs-3.5/exec-library-waitio-2.md)

       to complete them.
   INPUTS

```c
       deviceNode - pointer to the device node, set by [Open](autodocs-3.5/dos-library-open-2.md)
```
   SEE ALSO

```c
       [serial.device/OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
```

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
