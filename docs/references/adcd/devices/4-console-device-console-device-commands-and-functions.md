---
title: 4 Console Device / Console Device Commands and Functions
manual: devices
chapter: devices
section: 4-console-device-console-device-commands-and-functions
functions: [AbortIO, CDInputHandler, CheckIO, CloseDevice, DoIO, GetMsg, OpenDevice, OpenLibrary, OpenWindow, RawKeyConvert, SendIO, Wait, WaitIO, WaitPort]
libraries: [console.device, exec.library, intuition.library, timer.device]
---

# 4 Console Device / Console Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Command              Operation
-------              ---------
[CD_ASKDEFAULTKEYMAP](devices/4-console-device-using-the-console-device-without-a-window.md)  Get the current default keymap.

[CD_ASKKEYMAP](autodocs-2.0/console-device-cd-askkeymap.md)         Get the current key map structure for this console.

[CD_SETDEFAULTKEYMAP](devices/4-console-device-using-the-console-device-without-a-window.md)  Set the current default keymap.

[CD_SETKEYMAP](autodocs-2.0/console-device-cd-setkeymap.md)         Set the current key map structure for this console.

[CMD_CLEAR](autodocs-2.0/console-device-cmd-clear.md)            Remove any reports waiting to satisfy read requests

                     from the console input buffer.
[CMD_READ](devices/4-console-device-reading-from-the-console-device.md)             Read the next input, generally from the keyboard.

                     The form of this input is as an ANSI byte stream.
[CMD_WRITE](devices/4-console-device-writing-to-the-console-device.md)            Write a text record to the display interpreting


                     any ANSI control characters in the record.
Console Device Function
-----------------------
[CDInputHandler()](autodocs-2.0/console-device-cdinputhandler.md)     Handle an input event for the console device.

[RawKeyConvert()](autodocs-2.0/console-device-rawkeyconvert.md)      Decode raw input classes and convert input events of


                     type IECLASS_RAWKEY to ANSI bytes based on the keymap
                     in use.
Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/exec-library-abortio.md)            Abort an I/O request to the console device.

[CheckIO()](autodocs-2.0/exec-library-checkio.md)            Return the status of an I/O request.

[CloseDevice()](autodocs-2.0/exec-library-closedevice.md)        Relinquish use of the console device.  All requests

                     must be complete before closing.
[DoIO()](autodocs-2.0/exec-library-doio.md)               Initiate a command and wait for completion

```c
                     (synchronous request).
```
[GetMsg()](autodocs-2.0/exec-library-getmsg.md)             Get the next message from the reply port.

[OpenDevice()](autodocs-2.0/console-device-opendevice.md)         Obtain use of the console device.  You specify the

```c
                     type of unit and its characteristics in the call to
                     OpenDevice().
```
[OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md)        Gain access to a library.

[OpenWindow()](autodocs-2.0/intuition-library-openwindow.md)         Open an intuition window.

[SendIO()](autodocs-2.0/exec-library-sendio.md)             Initiate a command and return immediately

```c
                     (asynchronous request).
```
[Wait()](autodocs-2.0/exec-library-wait.md)               Wait for one or more signals.

[WaitIO()](autodocs-2.0/exec-library-waitio.md)             Wait for completion of an I/O request and remove it

                     from the reply port.
[WaitPort()](autodocs-2.0/exec-library-waitport.md)           Wait for the reply port to be non-empty. Does not


                     remove the message from port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)        Create an extended I/O request structure for use in

                     communicating with the console device.
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)         Create a message port for reply messages from the

                     console device.  Exec will signal a task when a
                     message arrives at the port.
[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)        Delete the extended I/O request structure created by

```c
                     [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).
```
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)         Delete the message port created by [CreatePort()](autodocs-2.0/amiga-lib-createport.md).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CDInputHandler — console.device](../autodocs/console.device.md#cdinputhandler)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [RawKeyConvert — console.device](../autodocs/console.device.md#rawkeyconvert)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
