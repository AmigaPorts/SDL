---
title: 8 / Device Interface / Closing The Narrator Device
manual: devices
chapter: devices
section: 8-device-interface-closing-the-narrator-device
functions: [CloseDevice, OpenDevice]
libraries: [exec.library]
---

# 8 / Device Interface / Closing The Narrator Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each [OpenDevice()](autodocs-2.0/narrator-device-opendevice.md) must be eventually matched by a call to [CloseDevice()](autodocs-2.0/exec-library-closedevice.md).
This is necessary to allow the system to expunge the device in low memory
conditions.  As long as any task has the device open, or has forgotten to
close it before terminating, the narrator device will not be expunged.

All I/O requests must have completed before the task can close the device.
If any requests are still pending, the user must abort them before closing
the device.


```c
    if (!(CheckIO(VoiceIO)
        {
        AbortIO(VoiceIO);  /* Abort queued or in progress request */
        }
    WaitIO((struct IORequest *)VoiceIO); /* Wait for abort to do its job */
    CloseDevice(VoiceIO);                /* Close the device */
```

---

## See Also

- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
