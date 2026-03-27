---
title: serial.device/CMD_FLUSH
manual: autodocs-2.0
chapter: autodocs-2.0
section: serial-device-cmd-flush
functions: []
libraries: []
---

# serial.device/CMD_FLUSH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Flush -- clear all queued I/O requests for the serial port
FUNCTION

    This command purges the read and write request queues for the
    serial device. Flush will not affect active requests.
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](autodocs-2.0/serial-device-opendevice.md)
    io_Unit         set by [OpenDevice](autodocs-2.0/serial-device-opendevice.md)
    io_Command      CMD_FLUSH
```
RESULTS

    Error -- if the Flush succeded, then io_Error will be null.
             If the Flush failed, then the io_Error will be non-zero.
