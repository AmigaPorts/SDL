---
title: 9 / Device Interface / Closing The Parallel Device
manual: devices
chapter: devices
section: 9-device-interface-closing-the-parallel-device
functions: [AbortIO, CloseDevice, OpenDevice]
libraries: [exec.library, timer.device]
---

# 9 / Device Interface / Closing The Parallel Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) must eventually be matched by a call to [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).
When the last close is performed, the device will deallocate all resources
and buffers.  The latest parameter settings will be saved for the next
open.

All I/O requests must be complete before [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).  If any requests
are still pending, abort them with AbortIO():

   if (!(CheckIO(ParallelIO)))
```c
       {
       AbortIO(ParallelIO);  /* Ask device to abort request, if pending */
       }
```
   WaitIO(ParallelIO);       /* Wait for abort, then clean up */
   CloseDevice((struct IORequest *)ParallelIO);

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
