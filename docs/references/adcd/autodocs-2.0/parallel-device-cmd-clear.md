---
title: parallel.device/CMD_CLEAR
manual: autodocs-2.0
chapter: autodocs-2.0
section: parallel-device-cmd-clear
functions: []
libraries: []
---

# parallel.device/CMD_CLEAR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Clear -- clear the parallel port buffer
FUNCTION

```c
    This command just RTS's (no buffer to clear)
```
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Unit         set by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Command      CMD_CLEAR (05)
```
