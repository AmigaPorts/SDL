---
title: 2 / Hardware Control Commands / ADCMD_FINISH
manual: devices
chapter: devices
section: 2-hardware-control-commands-adcmd-finish
functions: [AbortIO]
libraries: [timer.device]
---

# 2 / Hardware Control Commands / ADCMD_FINISH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [ADCMD_FINISH](autodocs-2.0/audio-device-adcmd-finish.md) command aborts (calls [AbortIO()](autodocs-2.0/audio-device-abortio.md) ) the current write
request on a channel or channels. This is useful if you have something
playing, such as a long buffer or some repetitions of a buffer, and you
want to stop it.

[ADCMD_FINISH](autodocs-2.0/audio-device-adcmd-finish.md) has a flag you can set (ADIOF_SYNCCYCLE) that allows the
waveform to finish the current cycle before aborting it. This is useful
for splicing together sounds at zero crossings or some other place in the
waveform where the amplitude at the end of one waveform matches the
amplitude at the beginning of the next. Zero crossings are positions
within the waveform at which the amplitude is zero. Splicing at zero
crossings gives you fewer clicks and pops when the audio channel is turned
off or the volume is changed.

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
