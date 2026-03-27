---
title: serial.device/CMD_START
manual: autodocs-3.5
chapter: autodocs-3.5
section: serial-device-cmd-start-2
functions: []
libraries: []
---

# serial.device/CMD_START

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       Start -- restart paused I/O over the serial port
   FUNCTION

       This function restarts all current I/O on the serial port by
       sending an xON to the "other side", and submitting a "logical
       xON" to "our side", if/when appropriate to current activity.
   IO REQUEST

```c
       io_Message      mn_ReplyPort initialized
       io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Command      CMD_START
```
   RESULTS

   SEE ALSO

```c
       [serial.device/CMD_STOP](autodocs-3.5/serial-device-cmd-stop-2.md)
```
