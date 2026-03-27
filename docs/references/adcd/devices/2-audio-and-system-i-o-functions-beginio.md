---
title: 2 / Audio And System I/O Functions / BeginIO()
manual: devices
chapter: devices
section: 2-audio-and-system-i-o-functions-beginio
functions: [DoIO, SendIO]
libraries: [exec.library]
---

# 2 / Audio And System I/O Functions / BeginIO()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All the commands that you can give to the audio device should be sent by
calling the [BeginIO()](autodocs-2.0/audio-device-beginio.md) function.  This differs from other Amiga devices
which generally use [SendIO()](autodocs-2.0/exec-library-sendio.md) or [DoIO()](autodocs-2.0/exec-library-doio.md).  You should not use SendIO() or
DoIO() with the audio device because these functions clear some special
flags used by the audio device; this might cause audio to work incorrectly
under certain circumstances.  To be safe, you should always use BeginIO()
with the audio device.

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
