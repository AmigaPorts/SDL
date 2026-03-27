---
title: 3 / Device Interface / Closing The Clipboard Device
manual: devices
chapter: devices
section: 3-device-interface-closing-the-clipboard-device
functions: [CloseDevice, OpenDevice]
libraries: [exec.library]
---

# 3 / Device Interface / Closing The Clipboard Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) must eventually be matched by a call to
[CloseDevice()](autodocs-2.0/exec-library-closedevice.md).


```c
    CloseDevice(ClipIO);
```
When the last task closes a clipboard unit with CloseDevice(), the
contents of the unit may be copied to a disk file in CLIPS: so that the
clipboard device can be expunged.

---

## See Also

- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
