---
title: parallel.device/CMD_FLUSH
manual: autodocs-2.0
chapter: autodocs-2.0
section: parallel-device-cmd-flush
functions: []
libraries: []
---

# parallel.device/CMD_FLUSH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Flush -- clear all queued I/O requests for the parallel port
FUNCTION

    This command purges the read and write request queues for the
    parallel device. The currently active request is not purged.
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Unit         set by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Command      CMD_FLUSH (08)
```
