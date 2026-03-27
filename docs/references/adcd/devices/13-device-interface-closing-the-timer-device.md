---
title: 13 / Device Interface / Closing The Timer Device
manual: devices
chapter: devices
section: 13-device-interface-closing-the-timer-device
functions: [AbortIO, CloseDevice, OpenDevice]
libraries: [exec.library, timer.device]
---

# 13 / Device Interface / Closing The Timer Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) must eventually be matched by a call to [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).

All I/O requests must be complete before [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).  If any requests
are still pending, abort them with [AbortIO()](autodocs-2.0/exec-library-abortio.md).

   if (!(CheckIO(TimerIO)))
```c
       {
       AbortIO(TimerIO);    /* Ask device to abort any pending requests */
       }
```
   WaitIO(TimerIO);         /* Clean up */
   CloseDevice((struct IORequest *)TimerIO);  /* Close Timer device */

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
