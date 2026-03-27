---
title: 2 / Device Interface / Closing The Audio Device
manual: devices
chapter: devices
section: 2-device-interface-closing-the-audio-device
functions: [AbortIO, CloseDevice, OpenDevice]
libraries: [exec.library, timer.device]
---

# 2 / Device Interface / Closing The Audio Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An [OpenDevice()](autodocs-2.0/audio-device-opendevice.md) must eventually be matched by a call to [CloseDevice()](autodocs-2.0/audio-device-closedevice.md).

All I/O requests must be complete before CloseDevice().  If any requests
are still pending, abort them with [AbortIO()](autodocs-2.0/audio-device-abortio.md) :

  AbortIO((struct IORequest *)AudioIO);  /* Abort any pending requests */
  WaitPort(AudioMP);                     /* Wait for abort message */
  GetMsg(AudioMP);                       /* Get abort message */
  CloseDevice((struct IORequest *)AudioIO);

CloseDevice() performs an [ADCMD_FREE](devices/2-allocation-and-arbitration-commands-adcmd-free.md) command on any channels selected by
the ioa_Request.io_Unit field of the [IOAudio](devices/2-audio-device-device-interface.md) request.  This means that if
you close the device with the same IOAudio block that you used to allocate
your channels (or a copy of it), the channels will be automatically freed.

If you allocated channels with multiple allocation commands, you cannot
use this function to close all of them at once. Instead, you will have to
issue one [ADCMD_FREE](devices/2-allocation-and-arbitration-commands-adcmd-free.md) command for each allocation that you made. After
issuing the ADCMD_FREE commands for each of the allocations, you can call
CloseDevice().

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
