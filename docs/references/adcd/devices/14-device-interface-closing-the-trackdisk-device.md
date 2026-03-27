---
title: 14 / Device Interface / Closing The Trackdisk Device
manual: devices
chapter: devices
section: 14-device-interface-closing-the-trackdisk-device
functions: [CloseDevice]
libraries: [exec.library]
---

# 14 / Device Interface / Closing The Trackdisk Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As with all devices, you must close the trackdisk device when you have
finished using it. To release the device, a [CloseDevice()](autodocs-2.0/exec-library-closedevice.md) call is executed
with the same [IOExtTD](devices/14-trackdisk-device-device-interface.md) used when the device was opened. This only closes
the device and makes it available to the rest of the system. It does not
deallocate the [IOExtTD](devices/14-trackdisk-device-device-interface.md) structure.


```c
    CloseDevice((struct IORequest *)DiskIO);
```

---

## See Also

- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
