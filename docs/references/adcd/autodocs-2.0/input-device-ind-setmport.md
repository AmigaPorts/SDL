---
title: input.device/IND_SETMPORT
manual: autodocs-2.0
chapter: autodocs-2.0
section: input-device-ind-setmport
functions: []
libraries: []
---

# input.device/IND_SETMPORT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IND_SETMPORT -- Set the current mouse port
FUNCTION

    This command sets the gameport port at which the mouse is
    connected.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      IND_SETMPORT
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       1
    io_Data         a pointer to a byte that is either 0 or 1,
                    indicating that mouse input should be obtained
                    from either the left or right controller port,
                    respectively.
```
