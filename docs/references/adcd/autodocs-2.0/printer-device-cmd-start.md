---
title: printer.device/CMD_START
manual: autodocs-2.0
chapter: autodocs-2.0
section: printer-device-cmd-start
functions: []
libraries: []
---

# printer.device/CMD_START

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CMD_START -- restart after stop (immediate)
```
FUNCTION

    CMD_START restarts the unit after a stop command.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CMD_START
    io_Flags        IOB_QUICK set if quick I/O is possible
```
