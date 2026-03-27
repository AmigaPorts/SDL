---
title: 12 / Device Interface / Closing The Serial Device
manual: devices
chapter: devices
section: 12-device-interface-closing-the-serial-device
functions: [AbortIO, CloseDevice, OpenDevice]
libraries: [exec.library, timer.device]
---

# 12 / Device Interface / Closing The Serial Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each [OpenDevice()](autodocs-2.0/serial-device-opendevice.md) must eventually be matched by a call to [CloseDevice()](autodocs-2.0/serial-device-closedevice.md).
When the last close is performed, the device will deallocate all resources
and buffers.

All IORequests must be complete before [CloseDevice()](autodocs-2.0/serial-device-closedevice.md).  Abort any pending
requests with [AbortIO()](autodocs-2.0/serial-device-abortio.md).

   if (!(CheckIO(SerialIO)))
```c
       {
       AbortIO((struct IORequest *)SerialIO); /* Ask device to abort */
       }			              /*   request, if pending */
```
   WaitIO((struct IORequest *)SerialIO);      /* Wait for abort, then */
   CloseDevice((struct IORequest *)SerialIO); /*  clean up */

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
