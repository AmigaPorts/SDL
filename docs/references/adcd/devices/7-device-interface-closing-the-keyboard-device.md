---
title: 7 / Device Interface / Closing The Keyboard Device
manual: devices
chapter: devices
section: 7-device-interface-closing-the-keyboard-device
functions: [AbortIO, CloseDevice, OpenDevice, WaitIO]
libraries: [exec.library, timer.device]
---

# 7 / Device Interface / Closing The Keyboard Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) must eventually be matched by a call to [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).

All I/O requests must be complete before CloseDevice().  If any requests
are still pending, abort them with [AbortIO()](autodocs-2.0/exec-library-abortio.md) and remove them with [WaitIO()](autodocs-2.0/exec-library-waitio.md).

   if (!(CheckIO(KeyIO)))
```c
       {
       AbortIO(KeyIO);  /* Ask device to abort request, if pending */
       }
       WaitIO(KeyIO);   /* Wait for abort, then clean up */
```
   CloseDevice(KeyIO);

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
