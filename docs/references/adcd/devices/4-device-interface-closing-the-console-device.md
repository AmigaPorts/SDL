---
title: 4 / Device Interface / Closing The Console Device
manual: devices
chapter: devices
section: 4-device-interface-closing-the-console-device
functions: [AbortIO, CloseDevice, OpenDevice]
libraries: [exec.library, timer.device]
---

# 4 / Device Interface / Closing The Console Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each [OpenDevice()](autodocs-2.0/console-device-opendevice.md) must eventually be matched by a call to [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).

All I/O requests must be complete before [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).  If any requests
are still pending, abort them with [AbortIO()](autodocs-2.0/exec-library-abortio.md).


```c
    if (!(CheckIO(ConsIO)))
        AbortIO(ConsIO);    /* Ask device to abort any pending requests */

    WaitIO(ConsIO);         /* Wait for abort, then clean up */
    CloseDevice(ConsIO);    /* Close console device */
```

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
