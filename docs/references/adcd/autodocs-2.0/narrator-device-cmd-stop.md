---
title: narrator.device/CMD_STOP
manual: autodocs-2.0
chapter: autodocs-2.0
section: narrator-device-cmd-stop
functions: []
libraries: []
---

# narrator.device/CMD_STOP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_STOP  - Stops the device.
SYNOPSIS

    Standard device command.
FUNCTION

```c
    CMD_STOP halts the currently active speech (if any) and prevents
    any queued requests from starting.
```
INPUTS

```c
    Valid [IORequest](autodocs-2.0/includes-exec-io-h.md) block with the io_Command field set to CMD_STOP.
    A valid [IORequest](autodocs-2.0/includes-exec-io-h.md) block is one with its io_Message structure, and
    io_Device and io_Unit fields properly initialized.  The easiest
    way to insure proper initialization is to make a copy of the
    [IORequest](autodocs-2.0/includes-exec-io-h.md) block after a successful [OpenDevice](autodocs-2.0/narrator-device-opendevice.md) call.
```
RESULTS

    io_Error set to 0.
SEE ALSO

    Exec input/output documentation.
