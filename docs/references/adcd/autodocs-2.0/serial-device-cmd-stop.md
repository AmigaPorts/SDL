---
title: serial.device/CMD_STOP
manual: autodocs-2.0
chapter: autodocs-2.0
section: serial-device-cmd-stop
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
    io_Device       set by [OpenDevice](autodocs-2.0/serial-device-opendevice.md)
    io_Unit         set by [OpenDevice](autodocs-2.0/serial-device-opendevice.md)
    io_Command      CMD_STOP
```
RESULTS

SEE ALSO

```c
    [serial.device/CMD_START](autodocs-2.0/serial-device-cmd-start.md)
```
