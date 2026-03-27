---
title: input.device/IND_REMHANDLER
manual: autodocs-2.0
chapter: autodocs-2.0
section: input-device-ind-remhandler
functions: []
libraries: []
---

# input.device/IND_REMHANDLER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IND_REMHANDLER -- Remove an input handler from the device
FUNCTION

    Remove a function previously added to the list of handler
    functions.
IO REQUEST

```c
    io_Message      mn_ReplyPort set
    io_Device       preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      IND_REMHANDLER
    io_Data         a pointer to the interrupt structure.
```
NOTES

    This command is not immediate
