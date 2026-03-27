---
title: 2 Audio Device / Audio Device Commands and Functions
manual: devices
chapter: devices
section: 2-audio-device-audio-device-commands-and-functions
functions: [AbortIO, AllocMem, CheckIO, CloseDevice, FreeMem, OpenDevice, Wait, WaitPort]
libraries: [exec.library, timer.device]
---

# 2 Audio Device / Audio Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Command          Operation
-------          ---------
 [ADCMD_ALLOCATE](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md)    Allocate one or more of the four audio channels.

 [ADCMD_FINISH](devices/2-hardware-control-commands-adcmd-finish.md)      Abort the current write request on one or more of the

                   channels.  Can be done immediately or at the end of the
                   current cycle.
 [ADCMD_FREE](devices/2-allocation-and-arbitration-commands-adcmd-free.md)        Free one or more audio channels.

 [ADCMD_LOCK](devices/2-allocation-and-arbitration-commands-adcmd-lock.md)        Lock one or more audio channels.

 [ADCMD_PERVOL](devices/2-hardware-control-commands-adcmd-pervol.md)      Change the period and volume for writes in progress. Can

                   be done immediately or at the end of the cycle.
 [ADCMD_SETPREC](devices/2-allocation-and-arbitration-commands-adcmd-setprec.md)     Set the allocation precedence of one or more channels.

 [ADCMD_WAITCYCLE](devices/2-hardware-control-commands-adcmd-waitcycle.md)   Wait for the current write cycle to complete on a single

                   channel.  Returns at the end of the cycle or immediately
                   if no cycle is active on the channel.
 [CMD_FLUSH](devices/2-hardware-control-commands-cmd-flush.md)         Purge all write cycles and waitcycles (in-progress and

```c
                   queued) for one or more channels.
```
 [CMD_READ](devices/2-hardware-control-commands-cmd-read.md)          Return a pointer to the I/O block currently writing on a

                   single channel.
 [CMD_RESET](devices/2-hardware-control-commands-cmd-reset.md)         Reset one or more channels their initialized state.  All

                   active and queued requests will be aborted.
 [CMD_START](devices/2-hardware-control-commands-cmd-start.md)         Resume writes to one or more channels that were stopped.

 [CMD_STOP](devices/2-hardware-control-commands-cmd-stop.md)          Stop any write cycle in progress on one or more

                                   channels.
 [CMD_WRITE](devices/2-hardware-control-commands-cmd-write.md)         Start a write cycle on a single channel.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/audio-device-abortio.md)        Abort a command to the audio device. If in progress, it

                 is stopped immediately, otherwise it is removed from the
                 queue.
[BeginIO()](autodocs-2.0/audio-device-beginio.md)        Initiate a command and return immediately (asynchronous

```c
                 request).
```
[CheckIO()](autodocs-2.0/exec-library-checkio.md)        Determine the current state of an I/O request.

[CloseDevice()](autodocs-2.0/audio-device-closedevice.md)    Relinquish use of the audio device.

[OpenDevice()](autodocs-2.0/audio-device-opendevice.md)     Obtain use of the audio device.

[Wait()](autodocs-2.0/exec-library-wait.md)           Wait for a signal from the audio device.

[WaitPort()](autodocs-2.0/exec-library-waitport.md)       Wait for the audio message port to receive a message.


Exec Support Functions as Used in This Chapter
----------------------------------------------
[AllocMem()](autodocs-2.0/exec-library-allocmem.md)       Allocate a block of memory.

[CreatePort()](autodocs-2.0/amiga-lib-createport.md)     Create a signal message port for reply messages from the

                 audio device.  Exec will signal a task when a message
                 arrives at the reply port.
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)     Delete the message port created by CreatePort().

[FreeMem()](autodocs-2.0/exec-library-freemem.md)        Free a block of previously allocated memory.

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
