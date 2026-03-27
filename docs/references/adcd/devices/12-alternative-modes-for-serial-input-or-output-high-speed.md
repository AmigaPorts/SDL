---
title: 12 / Alternative Modes for Serial Input or Output / High Speed Operation
manual: devices
chapter: devices
section: 12-alternative-modes-for-serial-input-or-output-high-speed
functions: [AbortIO, DoIO, SendIO]
libraries: [exec.library, timer.device]
---

# 12 / Alternative Modes for Serial Input or Output / High Speed Operation

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The more characters that are processed in each I/O request, the higher the
total throughput of the device.  The following technique will minimize
device overhead for reads:

   *  Use the [SDCMD_QUERY](autodocs-2.0/serial-device-sdcmd-query.md) command to get the number of characters currently

```c
      in the buffer (see the devices/[serial.h](autodocs-2.0/includes-devices-serial-h.md) Autodocs for information on
      SDCMD_QUERY).
```
   *  Use [DoIO()](autodocs-2.0/exec-library-doio.md) to read all available characters (or the maximum size of

```c
      your buffer).  In this case, [DoIO()](autodocs-2.0/exec-library-doio.md) is guaranteed to return without
      waiting.
```
   *  If zero characters are in the buffer, post an asynchronous request

```c
      ([SendIO()](autodocs-2.0/exec-library-sendio.md)) for 1 character.  When at least one is ready, the device
      will return it.  Now go back to the first step.
```
   *  If the user decides to quit the program, [AbortIO()](autodocs-2.0/serial-device-abortio.md) any pending

      requests.

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
