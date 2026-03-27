---
title: narrator.device/CMD_RESET
manual: autodocs-2.0
chapter: autodocs-2.0
section: narrator-device-cmd-reset
functions: []
libraries: []
---

# narrator.device/CMD_RESET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_RESET - Reset the device to a known state
SYNOPSIS

    Standard device command.
FUNCTION

    Resets the device as though it has just be initialized.
    Aborts all read/write requests whether active of enqueued.
    Restarts device if it has been stopped.
INPUTS

```c
    Valid [IORequest](autodocs-2.0/includes-exec-io-h.md) block with the io_Command field set to CMD_RESET.
    A valid [IORequest](autodocs-2.0/includes-exec-io-h.md) block is one with its io_Message structure, and
    io_Device and io_Unit fields properly initialized.  The easiest
    way to insure proper initialization is to make a copy of the
    [IORequest](autodocs-2.0/includes-exec-io-h.md) block after a successful [OpenDevice](autodocs-2.0/narrator-device-opendevice.md) call.
```
RESULTS

SEE ALSO

    Exec input/output documentation.
