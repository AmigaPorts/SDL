---
title: 2 / Audio And System I/O Functions / AbortIO()
manual: devices
chapter: devices
section: 2-audio-and-system-i-o-functions-abortio
functions: [AbortIO]
libraries: [timer.device]
---

# 2 / Audio And System I/O Functions / AbortIO()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This function can be used to cancel requests for [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md),
[ADCMD_LOCK](autodocs-2.0/audio-device-adcmd-lock.md), [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md), or [ADCMD_WAITCYCLE](autodocs-2.0/audio-device-adcmd-waitcycle.md). When used with the audio
device, [AbortIO()](autodocs-2.0/audio-device-abortio.md) always succeeds.

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
