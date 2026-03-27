---
title: 5 Gameport Device / Gameport Device Commands and Functions
manual: devices
chapter: devices
section: 5-gameport-device-gameport-device-commands-and-functions
functions: [AbortIO, CheckIO, CloseDevice, DoIO, OpenDevice, SendIO, WaitIO]
libraries: [exec.library, timer.device]
---

# 5 Gameport Device / Gameport Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Command         Operation
-------         ---------
CMD_CLEAR       Clear the gameport input buffer.

[GPD_ASKCTYPE](devices/5-setting-and-reading-controller-type-determining-the.md)    Return the type of gameport controller being used.

[GPD_ASKTRIGGER](devices/5-gameport-events-determining-the-trigger-conditions.md)  Return the conditions that have been preset for triggering.

[GPD_READEVENT](devices/5-gameport-events-reading-gameport-events.md)   Read one or more gameport events.

[GPD_SETCTYPE](devices/5-setting-and-reading-the-controller-type-setting-the.md)    Set the type of the controller to be used.

[GPD_SETTRIGGER](devices/5-gameport-events-setting-gameport-event-trigger-conditions.md)  Preset the conditions that will trigger a gameport event.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/exec-library-abortio.md)       Abort a command to the gameport device.

[CheckIO()](autodocs-2.0/exec-library-checkio.md)       Return the status of an I/O request.

[CloseDevice()](autodocs-2.0/exec-library-closedevice.md)   Relinquish use of the gameport device.  All requests must

                be complete before closing.
[DoIO()](autodocs-2.0/exec-library-doio.md)          Initiate a command and wait for completion (synchronous

```c
                request).
```
[OpenDevice()](autodocs-2.0/exec-library-opendevice.md)    Obtain shared use of one unit of the gameport device. The

                unit number specified is placed in the I/O request
                structure for use by gameport commands.
[SendIO()](autodocs-2.0/exec-library-sendio.md)        Initiate a command and return immediately (asynchronous

```c
                request).
```
[WaitIO()](autodocs-2.0/exec-library-waitio.md)        Wait for the completion of an asynchronous request.  When


                the request is complete the message will be removed from
                reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)   Create an extended I/O request structure of type [IOStdReq](devices/5-gameport-device-device-interface.md).

                This structure will be used to communicate commands to the
                gameport device.
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)    Create a signal message port for reply messages from the

                gameport device.  Exec will signal a task when a message
                arrives at the port.
[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)   Delete an I/O request structure created by [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).

[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)    Delete the message port created by [CreatePort()](autodocs-2.0/amiga-lib-createport.md).

   Who Runs The Mouse?
   -------------------
   When the input device or Intution is operating, unit 0 is usually
   dedicated to gathering mouse events.  The input device uses the
   gameport device to read the mouse events.  (For applications that
   take over the machine without starting up the input device or
   Intuition, unit 0 can perform the same functions as unit 1.)  See the
   "[Input Device](devices/6-input-device.md)" chapter for more information on the input device.

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
