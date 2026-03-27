---
title: 7 Keyboard Device / Keyboard Device Commands and Functions
manual: devices
chapter: devices
section: 7-keyboard-device-keyboard-device-commands-and-functions
functions: [AbortIO, AllocMem, CheckIO, CloseDevice, DoIO, FreeMem, OpenDevice, SendIO, WaitIO]
libraries: [exec.library, timer.device]
---

# 7 Keyboard Device / Keyboard Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Command               Operation
-------               ---------
[CMD_CLEAR](autodocs-2.0/keyboard-device-cmd-clear.md)             Clear the keyboard input buffer.  Removes any key

                      transitions from the input buffer.
[KBD_ADDRESETHANDLER](devices/7-amiga-reset-handling-adding-a-reset-handler-kbd.md)   Add a reset handler function to the list of

                      functions called  by the keyboard device to clean up
                      before a hard reset.
[KBD_REMRESETHANDLER](devices/7-amiga-reset-handling-removing-a-reset-handler-kbd.md)   Remove a previously added reset handler from the

                      list of functions called by the keyboard device to
                      clean up before a hard reset.
[KBD_RESETHANDLERDONE](devices/7-amiga-reset-handling-ending-a-reset-task-kbd.md)  Indicate that a handler has completed its job and

                      reset could possibly occur now.
[KBD_READMATRIX](devices/7-keyboard-device-reading-the-keyboard-matrix.md)        Read the state of every key in the keyboard.  Tells

                      the up/down state of every key.
[KBD_READEVENT](autodocs-2.0/keyboard-device-kbd-readevent.md)         Read one (or more) raw key event from the keyboard


                      device.
Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/exec-library-abortio.md)             Abort a command to the keyboard device.

[AllocMem()](autodocs-2.0/exec-library-allocmem.md)            Allocate a block of memory.

[CheckIO()](autodocs-2.0/exec-library-checkio.md)             Return the status of an I/O request.

[CloseDevice()](autodocs-2.0/exec-library-closedevice.md)         Relinquish use of the keyboard device.

[DoIO()](autodocs-2.0/exec-library-doio.md)                Initiate a command and wait for it to complete

```c
                      (synchronous request).
```
[FreeMem()](autodocs-2.0/exec-library-freemem.md)             Free a block of previously allocated memory.

[OpenDevice()](autodocs-2.0/exec-library-opendevice.md)          Obtain use of the keyboard device.

[SendIO()](autodocs-2.0/exec-library-sendio.md)              Initiate a command and return immediately

```c
                      (asynchronous request).
```
[WaitIO()](autodocs-2.0/exec-library-waitio.md)              Wait for the completion of an asynchronous request.


                      When the request is complete the message will be
                      removed from reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)         Create an extended I/O request structure.  This

                      structure will be used to communicate commands to
                      the keyboard device.
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)          Create a signal message port for reply messages from

                      the keyboard device.  Exec will signal a task when a
                      message arrives at the port.
[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)         Delete an extended I/O request structure created by

```c
                      [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).
```
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)          Delete the message port created by [CreatePort()](autodocs-2.0/amiga-lib-createport.md).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
