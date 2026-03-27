---
title: E / Release 2 Changes That Can Affect Compatibility / Strap
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-strap
functions: [OpenDevice]
libraries: [exec.library]
---

# E / Release 2 Changes That Can Affect Compatibility / Strap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * Romboot.library is gone.

  * Audio.device cannot be [OpenDevice()](libraries/19-accessing-a-device-opening-a-device.md)ed by a boot block program.  See

```c
    "[Audio Device](libraries/e-release-2-changes-that-can-affect-compatibility-audio.md)" below.
```
  * Boot from other floppies (+5,-10,-20,-30) is possible.

  * Undocumented system stack and register usage at Diag and Boot time

    have changed.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
