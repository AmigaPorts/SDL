---
title: 3 Clipboard Device / Clipboard Device Commands and Functions
manual: devices
chapter: devices
section: 3-clipboard-device-clipboard-device-commands-and-functions
functions: [CloseDevice, DoIO, GetMsg, OpenDevice, SendIO]
libraries: [exec.library]
---

# 3 Clipboard Device / Clipboard Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Command             Command Operation
-------             -----------------
[CBD_CHANGEHOOK](devices/3-clipboard-device-monitoring-clipboard-changes.md)      Specify a hook to be called when the data on the

```c
                    clipboard has changed (V36).
```
[CBD_CURRENTREADID](devices/3-device-interface-clipboard-messages.md)   Return the Clip ID of the current clip to read.  This

                    is used to determine if a clip posting is still the
                    latest cut.
[CBD_CURRENTWRITEID](devices/3-device-interface-clipboard-messages.md)  Return the Clip ID of the latest clip written.  This

                    is used to determine if the clip posting data is
                    obsolete.
[CBD_POST](autodocs-2.0/clipboard-device-cbd-post.md)            Post the availability of clip data.

[CMD_READ](devices/3-device-interface-reading-from-the-clipboard-device.md)            Read data from the clipboard for a paste.  Data can be

                    read from anywhere in the clipboard by specifying an
                    offset >0 in the I/O request.
[CMD_UPDATE](devices/3-device-interface-updating-the-clipboard-device.md)          Indicate that the data provided with a write command

                    is complete and available for subsequent read/pastes.
[CMD_WRITE](devices/3-device-interface-writing-to-the-clipboard-device.md)           Write data to the clipboard as a cut.


Exec Functions as Used in This Chapter
--------------------------------------
[CloseDevice()](autodocs-2.0/exec-library-closedevice.md)       Relinquish use of the clipboard device.  All requests

                    must be complete before closing.
[DoIO()](autodocs-2.0/exec-library-doio.md)              Initiate a command and wait for completion

```c
                    (synchronous request).
```
[GetMsg()](autodocs-2.0/exec-library-getmsg.md)            Get next message from a message port.

[OpenDevice()](autodocs-2.0/exec-library-opendevice.md)        Obtain use of the clipboard device.

[SendIO()](autodocs-2.0/exec-library-sendio.md)            Initiate a command and return immediately


```c
                    (asynchronous request).
```
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)       Create an I/O request structure of type IOClipReq.

                    This structure will be used to communicate commands to
                    the clipboard device.
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)        Create a signal message port for reply messages from

                    the clipboard device.  Exec will signal a task when a
                    message arrives at the port.
[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)       Delete an I/O request structure created by

```c
                    CreateExtIO().
```
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)        Delete the message port created by CreatePort().

---

## See Also

- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
