---
title: narrator.device/CMD_FLUSH
manual: autodocs-2.0
chapter: autodocs-2.0
section: narrator-device-cmd-flush
functions: []
libraries: []
---

# narrator.device/CMD_FLUSH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_FLUSH - Aborts all inprogress and queued requests
SYNOPSIS

    Standard device command.
FUNCTION

    Aborts all inprogress and queued speech requests.
INPUTS

```c
    Valid [IORequest](autodocs-2.0/includes-exec-io-h.md) block with the io_Command field set to CMD_FLUSH.
    A valid [IORequest](autodocs-2.0/includes-exec-io-h.md) block is one with its io_Message structure, and
    io_Device and io_Unit fields properly initialized.  The easiest
    way to insure proper initialization is to make a copy of the
    [IORequest](autodocs-2.0/includes-exec-io-h.md) block after a successful [OpenDevice](autodocs-2.0/narrator-device-opendevice.md) call.
```
RESULTS

```c
    io_Error in [IORequest](autodocs-2.0/includes-exec-io-h.md) block set to 0
```
SEE ALSO

    Exec input/output documentation.
