---
title: serial.device/CMD_RESET
manual: autodocs-3.5
chapter: autodocs-3.5
section: serial-device-cmd-reset-2
functions: []
libraries: []
---

# serial.device/CMD_RESET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       Reset -- reinitializes the serial port
   FUNCTION

       This command resets the serial port to its freshly initialized
       condition. It aborts all I/O requests both queued and current,
       relinquishes the current buffer, obtains a new default sized
       buffer, and sets the port's flags and parameters to their
       boot-up time default values. The functions places the reset
       parameter values in the ioRequest block.
   IO REQUEST

```c
       io_Message      mn_ReplyPort initialized
       io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Command      CMD_RESET
```
   RESULTS

       Error -- if the Reset succeded, then Error will be null.
           If the Reset failed, then the Error will be non-zero.
