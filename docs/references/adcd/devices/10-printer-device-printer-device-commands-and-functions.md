---
title: 10 Printer Device / Printer Device Commands and Functions
manual: devices
chapter: devices
section: 10-printer-device-printer-device-commands-and-functions
functions: [AbortIO, CloseDevice, DoIO, OpenDevice, SendIO, WaitIO]
libraries: [exec.library, timer.device]
---

# 10 Printer Device / Printer Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Command         Operation
-------         ----------
[CMD_FLUSH](autodocs-2.0/printer-device-cmd-flush.md)       Remove all queued requests for the printer device.  Does

                not affect active requests.
[CMD_RESET](autodocs-2.0/printer-device-cmd-reset.md)       Reset the printer device to its initialized state.  All

                active and queued I/O requests will be aborted.
[CMD_START](autodocs-2.0/printer-device-cmd-start.md)       Restart all paused I/O requests

[CMD_STOP](autodocs-2.0/printer-device-cmd-stop.md)        Pause all active and queued I/O requests.

[CMD_WRITE](devices/10-device-interface-writing-text-to-the-printer-device.md)       Write out a stream of characters to the printer device.

                The number of characters can be specified or a
                NULL-terminated string can be sent.
[PRD_DUMPRPORT](devices/10-printer-device-dumping-a-rastport-to-a-printer.md)   Dump the specified RastPort to a graphics printer.

[PRD_PRTCOMMAND](autodocs-2.0/printer-device-prd-prtcommand.md)  Send a command to the printer.

[PRD_QUERY](devices/10-printer-device-querying-the-printer-device.md)       Return the status of the printer port's lines and

                registers.
[PRD_RAWWRITE](autodocs-2.0/printer-device-prd-rawwrite.md)    Send unprocessed output to the the printer.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/exec-library-abortio.md)       Abort a command to the printer device.

[CloseDevice()](autodocs-2.0/exec-library-closedevice.md)   Relinquish use of the printer device.  All requests must

                be complete before closing.
[DoIO()](autodocs-2.0/exec-library-doio.md)          Start a command and wait for completion (synchronous

```c
                request).
```
[OpenDevice()](autodocs-2.0/exec-library-opendevice.md)    Obtain use of the printer device.

[SendIO()](autodocs-2.0/exec-library-sendio.md)        Start a command and return immediately (asynchronous

```c
                request).
```
[WaitIO()](autodocs-2.0/exec-library-waitio.md)        Wait for the completion of an asynchronous request.  When


                the request is complete, the message will be removed from
                the printer message port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)    Create a signal message port for reply messages from the

                audio device.  Exec will signal a task when a message
                arrives at the reply port.
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)   Create an I/O request structure of type printerIO.  This

                structure will be used to send commands to the printer
                device.
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)    Delete the message port created by [CreatePort()](autodocs-2.0/amiga-lib-createport.md).

[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)   Delete an I/O request structure created by [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
