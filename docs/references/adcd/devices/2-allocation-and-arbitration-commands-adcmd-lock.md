---
title: 2 / Allocation and Arbitration Commands / ADCMD_LOCK
manual: devices
chapter: devices
section: 2-allocation-and-arbitration-commands-adcmd-lock
functions: [AbortIO]
libraries: [timer.device]
---

# 2 / Allocation and Arbitration Commands / ADCMD_LOCK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [ADCMD_LOCK](autodocs-2.0/audio-device-adcmd-lock.md) command performs the "steal verify" function. When
another application is attempting to steal a channel or channels,
ADCMD_LOCK gives you a chance to clean up before the channel is stolen.
You perform a ADCMD_LOCK command right after the [ADCMD_ALLOCATE](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md) command.
ADCMD_LOCK does not return until a higher-priority user attempts to steal
the channel(s) or you perform an [ADCMD_FREE](devices/2-allocation-and-arbitration-commands-adcmd-free.md) command. If someone is
attempting to steal, you must finish up and ADCMD_FREE the channel as
quickly as possible.

You must use [ADCMD_LOCK](autodocs-2.0/audio-device-adcmd-lock.md) if you want to write directly to the hardware
registers instead of using the device commands. If your channel is stolen,
you are not notified unless the ADCMD_LOCK command is present. This could
cause problems for the task that has stolen the channel and is now using
it at the same time as your task. ADCMD_LOCK sets a switch that is not
cleared until you perform an ADCMD_FREE command on the channel. Canceling
an ADCMD_LOCK request with [AbortIO()](autodocs-2.0/audio-device-abortio.md) will not free the channel.

The following outline describes how [ADCMD_LOCK](autodocs-2.0/audio-device-adcmd-lock.md) works when a channel is
stolen and when it is not stolen.

   1. User A allocates a channel.
   2. User A locks the channel.

If User B allocates the channel with a higher precedence:

   3. User B's [ADCMD_ALLOCATE](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md) command is suspended (regardless of the
```c
      setting of the ADIOF_NOWAIT flag).
```
   4. User A's lock command is replied to with an error
```c
      (ADIOERR_CHANNELSTOLEN).
```
   5. User A does whatever is needed to finish up when a channel is stolen.
   6. User A frees the channel with [ADCMD_FREE](devices/2-allocation-and-arbitration-commands-adcmd-free.md).
   7. User B's [ADCMD_ALLOCATE](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md) command is replied to. Now user B has the

      channel.
Otherwise, if the channel is not allocated by another user:

   3. User A finishes the sound.
   4. User A performs the [ADCMD_FREE](devices/2-allocation-and-arbitration-commands-adcmd-free.md) command.
   5. User A's [ADCMD_LOCK](autodocs-2.0/audio-device-adcmd-lock.md) command is replied to.

Never make the freeing of a channel (if the channel is stolen) dependent
on allocating another channel. This may cause a deadlock. If you want
channels back after they have been stolen, you must reallocate them with
the same allocation key. To keep a channel and never let it be stolen, set
precedence to maximum (127). Do not use a lock for this purpose.

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
