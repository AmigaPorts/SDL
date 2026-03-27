---
title: printer.device/CMD_FLUSH
manual: autodocs-2.0
chapter: autodocs-2.0
section: printer-device-cmd-flush
functions: []
libraries: []
---

# printer.device/CMD_FLUSH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CMD_FLUSH -- abort all I/O requests (immediate)
```
FUNCTION

    CMD_FLUSH aborts all stopped I/O at the unit.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CMD_FLUSH
    io_Flags        IOB_QUICK set if quick I/O is possible
```
