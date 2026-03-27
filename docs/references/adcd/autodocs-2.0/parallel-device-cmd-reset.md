---
title: parallel.device/CMD_RESET
manual: autodocs-2.0
chapter: autodocs-2.0
section: parallel-device-cmd-reset
functions: []
libraries: []
---

# parallel.device/CMD_RESET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Reset -- reinitializes the parallel device
FUNCTION

    This command resets the parallel device to its freshly initialized
    condition. It aborts all I/O requests both queued and current and
    sets the devices's flags and parameters to their boot-up time
    default values. At boot-up time the PTermArray is random, and it
    will be so also here.
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Unit         set by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Command      CMD_RESET (01)
```
RESULTS

    Error -- if the Reset succeded, then io_Error will be null.
             if the Reset failed, then the io_Error will be non-zero.
