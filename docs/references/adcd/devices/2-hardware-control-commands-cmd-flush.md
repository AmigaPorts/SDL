---
title: 2 / Hardware Control Commands / CMD_FLUSH
manual: devices
chapter: devices
section: 2-hardware-control-commands-cmd-flush
functions: [AbortIO]
libraries: [timer.device]
---

# 2 / Hardware Control Commands / CMD_FLUSH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[CMD_FLUSH](autodocs-2.0/audio-device-cmd-flush.md) aborts (calls [AbortIO()](autodocs-2.0/audio-device-abortio.md) ) all [CMD_WRITE](devices/2-hardware-control-commands-cmd-write.md) and all [ADCMD_WAITCYCLE](devices/2-hardware-control-commands-adcmd-waitcycle.md)s
that are queued up for the channel or channels. It does not abort
[ADCMD_LOCK](devices/2-allocation-and-arbitration-commands-adcmd-lock.md)s (only [ADCMD_FREE](devices/2-allocation-and-arbitration-commands-adcmd-free.md) clears locks).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
