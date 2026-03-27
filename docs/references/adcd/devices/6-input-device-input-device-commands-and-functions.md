---
title: 6 Input Device / Input Device Commands and Functions
manual: devices
chapter: devices
section: 6-input-device-input-device-commands-and-functions
functions: [AbortIO, CheckIO, CloseDevice, DoIO, OpenDevice, PeekQualifier, SendIO]
libraries: [exec.library, input.device, timer.device]
---

# 6 Input Device / Input Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Command          Operation
-------          ---------
CMD_FLUSH        Purge all active and queued requests for the input device.

CMD_RESET        Reset the input port to its initialized state.  All

                 active and queued I/O requests will be aborted.  Restarts
                 the device if it has been stopped.
CMD_START        Restart the currently active input (if any) and resume

                 queued I/O requests.
CMD_STOP         Stop any currently active input and prevent queued I/O

                 requests from starting.
[IND_ADDHANDLER](devices/6-input-device-adding-an-input-handler.md)   Add an input-stream handler into the handler chain.

[IND_REMHANDLER](devices/6-adding-an-input-handler-removing-an-input-handler.md)   Remove an input-stream handler from the handler chain.

[IND_SETMPORT](devices/6-input-device-using-the-mouse-port-with-the-input-device.md)     Set the controller port to which the mouse is connected.

[IND_SETMTRIG](devices/6-setting-the-conditions-for-a-mouse-port-report.md)     Set conditions that must be met by a mouse before a

                 pending read request will be satisfied.
[IND_SETMTYPE](autodocs-2.0/input-device-ind-setmtype.md)     Set the type of device at the mouse port.

[IND_SETPERIOD](devices/6-input-device-setting-the-key-repeat-interval.md)    Set the period at which a repeating key repeats.

[IND_SETTHRESH](devices/6-input-device-setting-the-key-repeat-threshold.md)    Set the repeating key hold-down time before repeat starts.

[IND_WRITEEVENT](devices/6-writing-events-to-input-device-stream-setting-position-of.md)   Propagate an input event stream to all devices.


Input Device Function
---------------------
[PeekQualifier()](autodocs-2.0/input-device-peekqualifier.md)  Return the input device's current qualifiers. (V36)


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/exec-library-abortio.md)        Abort a command to the input device.

[CheckIO()](autodocs-2.0/exec-library-checkio.md)        Return the status of an I/O request.

[CloseDevice()](autodocs-2.0/exec-library-closedevice.md)    Relinquish use of the input device.

[DoIO()](autodocs-2.0/exec-library-doio.md)           Initiate a command and wait for completion (synchronous

```c
                 request).
```
[OpenDevice()](autodocs-2.0/exec-library-opendevice.md)     Obtain shared use of the input device.

[SendIO()](autodocs-2.0/exec-library-sendio.md)         Initiate a command and return immediately (asynchronous

```c
                 request).
```
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)    Create an extended I/O request structure of type

```c
                 [IOStdReq](devices/6-input-device-device-interface.md).  This structure will be used to communicate
                 commands to the input device.
```
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)     Create a signal message port for reply messages from the

                 input device.  Exec will signal a task when a message
                 arrives at the reply port.
[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)    Delete an I/O request structure created by [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).

[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)     Delete the message port created by [CreatePort()](autodocs-2.0/amiga-lib-createport.md).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [PeekQualifier — input.device](../autodocs/input.device.md#peekqualifier)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
