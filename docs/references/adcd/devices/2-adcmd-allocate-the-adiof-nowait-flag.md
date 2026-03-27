---
title: 2 / ADCMD_ALLOCATE / The ADIOF_NOWAIT Flag
manual: devices
chapter: devices
section: 2-adcmd-allocate-the-adiof-nowait-flag
functions: [AbortIO]
libraries: [timer.device]
---

# 2 / ADCMD_ALLOCATE / The ADIOF_NOWAIT Flag

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you need to produce a sound right now and otherwise don't want to
allocate, set the ADIOF_NOWAIT flag to 1. This will cause the command to
return an IOERR_ALLOCFAILED error if it cannot allocate any of the
channels. If you are producing a non-urgent sound and you can wait, set
the ADIOF_NOWAIT flag to 0. Then, the [IOAudio](devices/2-audio-device-device-interface.md) block returns only when you
get the allocation. If ADIOF_NOWAIT is set to 0, the audio device will
continue to retry the allocation request whenever channels are freed until
it is successful. If the program decides to cancel the request,
[AbortIO()](autodocs-2.0/audio-device-abortio.md) can be used.

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
