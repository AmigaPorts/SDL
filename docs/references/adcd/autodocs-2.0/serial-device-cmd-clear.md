---
title: serial.device/CMD_CLEAR
manual: autodocs-2.0
chapter: autodocs-2.0
section: serial-device-cmd-clear
functions: []
libraries: []
---

# serial.device/CMD_CLEAR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Clear -- clear the serial port buffers
FUNCTION

    This command resets the serial port's read buffer pointers.
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](autodocs-2.0/serial-device-opendevice.md)
    io_Unit         set by [OpenDevice](autodocs-2.0/serial-device-opendevice.md)
    io_Command      CMD_CLEAR
```
RESULTS

    Error -- If the Clear succeded, then io_Error will be null.
             If the Clear failed, then the io_Error will be non-zero.
