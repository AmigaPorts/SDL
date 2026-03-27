---
title: serial.device/CMD_STOP
manual: autodocs-3.5
chapter: autodocs-3.5
section: serial-device-cmd-stop-2
functions: []
libraries: []
---

# serial.device/CMD_STOP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       Stop -- pause all current I/O over the serial port
   FUNCTION

       This command halts all current I/O on the serial port by
       sending an xOFF to the "other side", and submitting a "logical
       xOFF" to "our side", if/when appropriate to current activity.
   IO REQUEST

```c
       io_Message      mn_ReplyPort initialized
       io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Command      CMD_STOP
```
   RESULTS

   SEE ALSO

```c
       [serial.device/CMD_START](autodocs-3.5/serial-device-cmd-start-2.md)
```
