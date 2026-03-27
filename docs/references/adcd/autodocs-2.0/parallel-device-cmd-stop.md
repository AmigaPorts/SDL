---
title: parallel.device/CMD_STOP
manual: autodocs-2.0
chapter: autodocs-2.0
section: parallel-device-cmd-stop
functions: []
libraries: []
---

# parallel.device/CMD_STOP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Stop -- pause current activity on the parallel device
FUNCTION

    This command halts the current I/O activity on the parallel
    device by discontinuing the handshaking sequence. The stop and
    start commands may not be nested.
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Unit         set by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Command      CMD_STOP (06)
```
SEE ALSO

```c
    [parallel.device/CMD_START](autodocs-2.0/parallel-device-cmd-start.md)
```
