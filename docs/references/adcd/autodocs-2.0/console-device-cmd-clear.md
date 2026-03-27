---
title: console.device/CMD_CLEAR
manual: autodocs-2.0
chapter: autodocs-2.0
section: console-device-cmd-clear
functions: []
libraries: []
---

# console.device/CMD_CLEAR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_CLEAR -- Clear console input buffer.
FUNCTION

    Remove from the console input buffer any reports waiting to
    satisfy read requests.
IO REQUEST INPUT

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/console-device-opendevice.md)
    io_Unit         preset by the call to [OpenDevice](autodocs-2.0/console-device-opendevice.md)
    io_Command      CMD_CLEAR
    io_Flags        IOB_QUICK set if quick I/O is possible, else 0
```
SEE ALSO

```c
    [exec/io.h](autodocs-2.0/includes-exec-io-h.md), [devices/console.h](autodocs-2.0/includes-devices-console-h.md)
```
