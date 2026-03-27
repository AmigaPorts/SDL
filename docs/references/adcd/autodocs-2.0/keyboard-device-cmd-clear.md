---
title: keyboard.device/CMD_CLEAR
manual: autodocs-2.0
chapter: autodocs-2.0
section: keyboard-device-cmd-clear
functions: []
libraries: []
---

# keyboard.device/CMD_CLEAR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_CLEAR -- Clear the keyboard input buffer.
FUNCTION

    Remove from the input buffer any keys transitions waiting to
    satisfy read requests.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CMD_CLEAR
    io_Flags        IOB_QUICK set if quick I/O is possible
```
