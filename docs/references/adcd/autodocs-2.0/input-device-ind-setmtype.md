---
title: input.device/IND_SETMTYPE
manual: autodocs-2.0
chapter: autodocs-2.0
section: input-device-ind-setmtype
functions: []
libraries: []
---

# input.device/IND_SETMTYPE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IND_SETMTYPE -- Set the current mouse port controller type
FUNCTION

    This command sets the type of device at the mouse port, so
    the signals at the port may be properly interpreted.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      IND_SETMTYPE
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       1
    io_Data         the address of the byte variable describing
                    the controller type, as per the equates in
                    the gameport include file
```
