---
title: 13 Timer Device / Timer Device Commands and Functions
manual: devices
chapter: devices
section: 13-timer-device-timer-device-commands-and-functions
functions: [AbortIO, AddTime, CheckIO, CloseDevice, CmpTime, DoIO, GetSysTime, OpenDevice, ReadEClock, SendIO, SubTime]
libraries: [exec.library, timer.device]
---

# 13 Timer Device / Timer Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Command        Operation
-------        ---------
[TR_ADDREQUEST](devices/13-timer-device-adding-a-time-request.md)  Request that the timer device wait a specified period of

               time before replying to the request.
[TR_GETSYSTIME](devices/13-timer-device-system-time.md)  Get system time and place in a [timeval](devices/13-timer-device-device-interface.md) structure.

[TR_SETSYSTIME](devices/13-timer-device-system-time.md)  Set the system time from the value in a  [timeval](devices/13-timer-device-device-interface.md) structure.


Device Functions
----------------
[AddTime()](autodocs-2.0/timer-device-addtime.md)      Add one  [timeval](devices/13-timer-device-device-interface.md) structure to another.  The result is placed

               in the first timeval structure.
[CmpTime()](autodocs-2.0/timer-device-cmptime.md)      Compare one  [timeval](devices/13-timer-device-device-interface.md) structure to another.  The result is

               returned as a longword.
[GetSysTime()](autodocs-2.0/timer-device-getsystime.md)   Get system time and place in a  [timeval](devices/13-timer-device-device-interface.md) structure.

[ReadEClock()](autodocs-2.0/timer-device-readeclock.md)   Read the current 64 bit value of the E-Clock into an

```c
               [EClockVal](devices/13-timer-device-device-interface.md) structure.  The count rate of the E-Clock is also
               returned. (V36)
```
[SubTime()](autodocs-2.0/timer-device-subtime.md)      Subtract one [timerequest](devices/13-timer-device-device-interface.md) structure from another. The result


```c
               is placed in the first [timerequest](devices/13-timer-device-device-interface.md) structure.
```
Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/exec-library-abortio.md)      Abort a command to the timer device.

[CheckIO()](autodocs-2.0/exec-library-checkio.md)      Return the status of an I/O request.

[CloseDevice()](autodocs-2.0/exec-library-closedevice.md)  Relinquish use of the timer device. All requests must be

               complete before closing.
[DoIO()](autodocs-2.0/exec-library-doio.md)         Initiate a command and wait for completion (synchronous

```c
               request).
```
[OpenDevice()](autodocs-2.0/exec-library-opendevice.md)   Obtain use of the timer device.  The timer device may be

               opened multiple times.
[SendIO()](autodocs-2.0/exec-library-sendio.md)       Initiate a command and return immediately (asynchronous


```c
               request).
```
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)  Create an extended I/O request structure of type

```c
               [timerequest](devices/13-timer-device-device-interface.md).  This structure will be used to communicate
               commands to the timer device.
```
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)   Create a signal message port for reply messages from the

               timer device.  Exec will signal a task when a message
               arrives at the reply port.
[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)  Delete the [timerequest](devices/13-timer-device-device-interface.md) extended I/O request structure

```c
               created by [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).
```
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)   Delete the message port created by [CreatePort()](autodocs-2.0/amiga-lib-createport.md).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [AddTime — timer.device](../autodocs/timer.device.md#addtime)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [CmpTime — timer.device](../autodocs/timer.device.md#cmptime)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [GetSysTime — timer.device](../autodocs/timer.device.md#getsystime)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [ReadEClock — timer.device](../autodocs/timer.device.md#readeclock)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [SubTime — timer.device](../autodocs/timer.device.md#subtime)
