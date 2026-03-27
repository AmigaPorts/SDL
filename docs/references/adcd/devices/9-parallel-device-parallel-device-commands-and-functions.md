---
title: 9 Parallel Device / Parallel Device Commands and Functions
manual: devices
chapter: devices
section: 9-parallel-device-parallel-device-commands-and-functions
functions: [AbortIO, CheckIO, CloseDevice, DoIO, OpenDevice, SendIO, WaitIO]
libraries: [exec.library, timer.device]
---

# 9 Parallel Device / Parallel Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Command          Operation
-------          ---------
[CMD_FLUSH](autodocs-2.0/parallel-device-cmd-flush.md)        Purge all queued requests for the parallel device.  Does

                 not affect active requests.
[CMD_READ](devices/9-device-interface-reading-from-the-parallel-device.md)         Read a stream of characters from the parallel port.  The

```c
                 number of characters can be specified or a termination
                 character(s) can be used.
```
[CMD_RESET](autodocs-2.0/parallel-device-cmd-reset.md)        Reset the parallel port to its initialized state.  All

                 active and queued I/O requests will be aborted.
[CMD_START](autodocs-2.0/parallel-device-cmd-start.md)        Restart all paused I/O over the parallel port.

                 Reactivates the handshaking sequence.
[CMD_STOP](autodocs-2.0/parallel-device-cmd-stop.md)         Pause all active I/O over the parallel port.  Deactivates

                 the handshaking sequence.
[CMD_WRITE](devices/9-device-interface-writing-to-the-parallel-device.md)        Write out a stream of characters to the parallel port.

                 The number of characters can be specified or a
                 NULL-terminated string can be sent.
[PDCMD_QUERY](devices/9-parallel-device-querying-the-parallel-device.md)      Return the status of the parallel port lines and

                 registers.
[PDCMD_SETPARAMS](devices/9-parallel-device-setting-parallel-parameters.md)  Set the parameters of the parallel port.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/exec-library-abortio.md)        Abort a command to the parallel device. If the command is

                 in progress, it is stopped immediately.  If it is queued,
                 it is removed from the queue.
[BeginIO()](autodocs-2.0/amiga-lib-beginio.md)        Initiate a command and return immediately (asynchronous

```c
                 request).  This is used to minimize the amount of system
                 overhead.
```
[CheckIO()](autodocs-2.0/exec-library-checkio.md)        Determine the current state of an I/O request.

[CloseDevice()](autodocs-2.0/exec-library-closedevice.md)    Relinquish use of the parallel device.  All requests must

                 be complete.
[DoIO()](autodocs-2.0/exec-library-doio.md)           Initiate a command and wait for completion (synchronous

```c
                 request).
```
[OpenDevice()](autodocs-2.0/parallel-device-opendevice.md)     Obtain use of the parallel device.

[SendIO()](autodocs-2.0/exec-library-sendio.md)         Initiate a command and return immediately (asynchronous

```c
                 request).
```
[WaitIO()](autodocs-2.0/exec-library-waitio.md)         Wait for the completion of an asynchronous request.  When


                 the request is complete the message will be removed from
                 your reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)    Create an extended I/O request structure of type

                 IOExtPar.  This structure will be used to communicate
                 commands to the parallel device.
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)     Create a signal message port for reply messages from the

                 parallel device.  Exec will signal a task when a message
                 arrives at the port.
[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)    Delete an extended I/O request structure created by

```c
                 CreateExtIO().
```
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)     Delete the message port created by CreatePort().

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
