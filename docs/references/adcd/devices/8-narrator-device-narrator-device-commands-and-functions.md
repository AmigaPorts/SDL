---
title: 8 Narrator Device / Narrator Device Commands and Functions
manual: devices
chapter: devices
section: 8-narrator-device-narrator-device-commands-and-functions
functions: [AbortIO, CheckIO, CloseDevice, CloseLibrary, DoIO, OpenDevice, OpenLibrary, SendIO, WaitIO]
libraries: [exec.library, timer.device]
---

# 8 Narrator Device / Narrator Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Command         Operation
-------         ---------
[CMD_FLUSH](autodocs-2.0/narrator-device-cmd-flush.md)       Purge all active and queued requests for the narrator

                device.
[CMD_READ](devices/8-narrator-device-reading-from-the-narrator-device.md)        Read mouth shapes associated with an active write from the

                narrator device.
[CMD_RESET](autodocs-2.0/narrator-device-cmd-reset.md)       Reset the narrator port to its initialized state. All

                active and queued I/O requests will be aborted.  Restarts
                the device if it has been stopped.
[CMD_START](autodocs-2.0/narrator-device-cmd-start.md)       Restart the currently active speech (if any) and resume

                queued I/O requests.
[CMD_STOP](autodocs-2.0/narrator-device-cmd-stop.md)        Stop any currently active speech and prevent queued I/O

                requests from starting.
[CMD_WRITE](devices/8-narrator-device-writing-to-the-narrator-device.md)       Write a stream of characters to the narrator device and


                generate mouth movement data for reads.
Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/narrator-device-abortio.md)       Abort a command to the narrator device. If the command is

                in progress, it is stopped immediately.  If it is queued,
                it is removed from the queue.
[BeginIO()](autodocs-2.0/amiga-lib-beginio.md)       Initiate a command and return immediately (asynchronous

```c
                request).  This is used to minimize the amount of system
                overhead.
```
[CloseDevice()](autodocs-2.0/narrator-device-closedevice.md)   Relinquish use of the narrator device.  All requests must

                be complete.
[CheckIO()](autodocs-2.0/exec-library-checkio.md)       Return the status of an I/O request.

[CloseLibrary()](autodocs-2.0/exec-library-closelibrary.md)  Relinquish use of a previously opened library.

[DoIO()](autodocs-2.0/exec-library-doio.md)          Initiate a command and wait for completion (synchronous

```c
                request). Should be used with care because it will not
                return control if the request does not complete.
```
[OpenDevice()](autodocs-2.0/narrator-device-opendevice.md)    Obtain use of the narrator device.

[OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md)   Obtain use of a library.

[SendIO()](autodocs-2.0/exec-library-sendio.md)        Initiate a command and return immediately (asynchronous

```c
                request).
```
[WaitIO()](autodocs-2.0/exec-library-waitio.md)        Wait for the completion of an asynchronous request. When


                the request is complete the message will be removed from
                reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)   Create an extended I/O request structure of type

                narrator_rb.  This structure will be used to communicate
                commands to the narrator device.
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)    Create a signal message port for reply messages from the

                narrator device.  Exec will signal a task when a message
                arrives at the port.
[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)   Delete an extended I/O request structure created by

```c
                [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).
```
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)    Delete the message port created by [CreatePort()](autodocs-2.0/amiga-lib-createport.md).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [CloseLibrary — exec.library](../autodocs/exec.library.md#closelibrary)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
