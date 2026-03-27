---
title: 6 / Device Interface / Closing The Input Device
manual: devices
chapter: devices
section: 6-device-interface-closing-the-input-device
functions: [AbortIO, CloseDevice, OpenDevice]
libraries: [exec.library, timer.device]
---

# 6 / Device Interface / Closing The Input Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) must eventually be matched by a call to [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).
All I/O requests must be complete before CloseDevice().  If any requests
are still pending, abort them with [AbortIO()](autodocs-2.0/exec-library-abortio.md):

   if (!(CheckIO(InputIO)))
```c
       {
       AbortIO(InputIO);  /* Ask device to abort request, if pending */
       }
```
   WaitIO(InputIO);       /* Wait for abort, then clean up */
   CloseDevice((struct IORequest *)InputIO);

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
