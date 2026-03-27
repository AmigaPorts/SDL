---
title: 11 / Device Interface / Closing The SCSI Device
manual: devices
chapter: devices
section: 11-device-interface-closing-the-scsi-device
functions: [AbortIO, CloseDevice, OpenDevice]
libraries: [exec.library, timer.device]
---

# 11 / Device Interface / Closing The SCSI Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) must eventually be matched by a call to [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).
All I/O requests must be complete before calling [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).  If any
requests are still pending, abort them with [AbortIO()](autodocs-2.0/exec-library-abortio.md).


```c
    if (!(CheckIO(SCSIIO)))
        {
        AbortIO(SCSIIO);   /* Ask device to abort any pending requests */
        WaitIO(SCSIIO);    /* Wait for abort, then clean up */
        }
    CloseDevice(SCSIIO);   /* Close SCSI device */
```

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
