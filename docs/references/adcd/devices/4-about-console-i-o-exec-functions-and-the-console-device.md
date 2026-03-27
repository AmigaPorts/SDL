---
title: 4 / About Console I/O / Exec Functions And The Console Device
manual: devices
chapter: devices
section: 4-about-console-i-o-exec-functions-and-the-console-device
functions: [AbortIO, CheckIO, DoIO, SendIO]
libraries: [exec.library, timer.device]
---

# 4 / About Console I/O / Exec Functions And The Console Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The various Exec functions such as [DoIO()](autodocs-2.0/exec-library-doio.md), [SendIO()](autodocs-2.0/exec-library-sendio.md), [AbortIO()](autodocs-2.0/exec-library-abortio.md) and
[CheckIO()](autodocs-2.0/exec-library-checkio.md) operate normally. The only caveats are that [CMD_WRITE](devices/4-console-device-writing-to-the-console-device.md) may cause
your application to wait internally, even with SendIO(), and a task using
[CMD_READ](devices/4-console-device-reading-from-the-console-device.md) to wait on a response from a console is at the user's mercy.  If
the user never reselects that window, and the console response provides
the only wake-up call, that task will sleep forever.

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
