---
title: parallel.device/CMD_START
manual: autodocs-2.0
chapter: autodocs-2.0
section: parallel-device-cmd-start
functions: []
libraries: []
---

# parallel.device/CMD_START

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Start -- restart paused I/O over the parallel port
FUNCTION

    This command restarts the current I/O activity on the parallel
    port by reactivating the handshaking sequence.
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Unit         set by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Command      CMD_START (07)
```
SEE ALSO

```c
    [parallel.device/CMD_STOP](autodocs-2.0/parallel-device-cmd-stop.md)
```
