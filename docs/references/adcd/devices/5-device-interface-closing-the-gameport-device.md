---
title: 5 / Device Interface / Closing The Gameport Device
manual: devices
chapter: devices
section: 5-device-interface-closing-the-gameport-device
functions: [AbortIO, CloseDevice, OpenDevice, WaitIO]
libraries: [exec.library, timer.device]
---

# 5 / Device Interface / Closing The Gameport Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) must eventually be matched by a call to [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).

All I/O requests must be complete before [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).  If any requests
are still pending, abort them with [AbortIO()](autodocs-2.0/exec-library-abortio.md) and remove them with [WaitIO()](autodocs-2.0/exec-library-waitio.md).


```c
    if (!(CheckIO(GameIO)))
        {
        AbortIO(GameIO);  /* Ask device to abort request, if pending */
        }
    WaitIO((GameIO);   /* Wait for abort, then clean up */
    CloseDevice(GameIO);
```

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
