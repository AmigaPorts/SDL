---
title: 12 Serial Device / Serial Device Commands and Functions
manual: devices
chapter: devices
section: 12-serial-device-serial-device-commands-and-functions
functions: [AbortIO, CheckIO, CloseDevice, DoIO, OpenDevice, SendIO, WaitIO]
libraries: [exec.library, timer.device]
---

# 12 Serial Device / Serial Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Device Command   Operation
--------------   ---------
[CMD_CLEAR](autodocs-2.0/serial-device-cmd-clear.md)        Reset the serial port's read buffer pointers.

[CMD_FLUSH](autodocs-2.0/serial-device-cmd-flush.md)        Purge all queued requests for the serial device (does not

```c
                 affect active requests).
```
[CMD_READ](devices/12-device-interface-reading-from-the-serial-device.md)         Read a stream of characters from the serial port buffer.

```c
                 The number of characters can be specified or a
                 termination character(s) used.
```
[CMD_RESET](autodocs-2.0/serial-device-cmd-reset.md)        Reset the serial port to its initialized state.  All

                 active and queued I/O requests will be aborted and the
                 current buffer will be released.
[CMD_START](autodocs-2.0/serial-device-cmd-start.md)        Restart all paused I/O over the serial port.  Also sends

                 an "xON".
[CMD_STOP](autodocs-2.0/serial-device-cmd-stop.md)         Pause all active I/O over the serial port.  Also sends an

                 "xOFF".
[CMD_WRITE](devices/12-device-interface-writing-to-the-serial-device.md)        Write out a stream of characters to the serial port.  The

                 number of characters can be specified or a
                 NULL-terminated string can be sent.
[SDCMD_BREAK](devices/12-serial-device-sending-the-break-command.md)      Send a break signal out the serial port.  May be done

```c
                 immediately or queued. Duration of the break (in
                 microseconds) can be set by the application.
```
[SDCMD_QUERY](devices/12-serial-device-querying-the-serial-device.md)      Return the status of the serial port lines and registers,

                 and the number of bytes in the serial port's read buffer.
[SDCMD_SETPARAMS](devices/12-serial-device-setting-serial-parameters-sdcmd-setparams.md)  Set the parameters of the serial port.  This ranges from


                 baud rate to number of microseconds a break will last.
Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/serial-device-abortio.md)        Abort a command to the serial device. If the command is

                 in progress, it is stopped immediately.  If it is queued,
                 it is removed from the queue.
[BeginIO()](autodocs-2.0/serial-device-beginio.md)         Initiate a command and return immediately (asynchronous

```c
                 request).  This is used to minimize the amount of system
                 overhead.
```
[CheckIO()](autodocs-2.0/exec-library-checkio.md)        Determine the current state of an I/O request.

[CloseDevice()](autodocs-2.0/serial-device-closedevice.md)    Relinquish use of the serial device.  All requests must

                 be complete.
[DoIO()](autodocs-2.0/exec-library-doio.md)           Initiate a command and wait for completion (synchronous

```c
                 request).
```
[OpenDevice()](autodocs-2.0/serial-device-opendevice.md)     Obtain use of the serial device.

[SendIO()](autodocs-2.0/exec-library-sendio.md)         Initiate a command and return immediately (asynchronous

```c
                 request).
```
[WaitIO()](autodocs-2.0/exec-library-waitio.md)         Wait for the completion of an asynchronous request. When


                 the request is complete the message will be removed from
                 your reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)    Create an extended I/O request structure of type

```c
                 [IOExtSer](devices/12-serial-device-device-interface.md).  This structure will be used to communicate
                 commands to the serial device.
```
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)     Create a signal message port for reply messages from the

                 serial device.  Exec will signal a task when a message
                 arrives at the port.
[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)    Delete an extended I/O request structure created by

```c
                 [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).
```
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)     Delete the message port created by [CreatePort()](autodocs-2.0/amiga-lib-createport.md).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
