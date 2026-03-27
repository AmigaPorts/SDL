---
title: 10 / Device Interface / Closing The Printer Device
manual: devices
chapter: devices
section: 10-device-interface-closing-the-printer-device
functions: [AbortIO, CloseDevice, OpenDevice, WaitIO]
libraries: [exec.library, timer.device]
---

# 10 / Device Interface / Closing The Printer Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) must eventually be matched by a call to [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).

All I/O requests must be complete before [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).  If any requests
are still pending, abort them with [AbortIO()](autodocs-2.0/exec-library-abortio.md).

   AbortIO(PrintIO);  /* Ask device to abort request, if pending */
   WaitIO(PrintIO);   /* Wait for abort, then clean up */

   CloseDevice((struct IORequest *)PrintIO);

   Use [AbortIO()](autodocs-2.0/exec-library-abortio.md) / [WaitIO()](autodocs-2.0/exec-library-waitio.md) Intelligently.
   -------------------------------------
   Only call AbortIO()/WaitIO() for requests which have already been
   sent to the printer device.  Using the AbortIO()/WaitIO() sequence on
   requests which have not been sent results in a hung condition.

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
