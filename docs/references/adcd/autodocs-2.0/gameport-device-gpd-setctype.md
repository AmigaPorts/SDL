---
title: gameport.device/GPD_SETCTYPE
manual: autodocs-2.0
chapter: autodocs-2.0
section: gameport-device-gpd-setctype
functions: []
libraries: []
---

# gameport.device/GPD_SETCTYPE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GPD_SETCTYPE -- Set the current game port controller type
FUNCTION

    This command sets the type of device at the game port, so that
    the signals at the port may be properly interpreted.  The port
    can also be turned off, so that no reports are generated.

    This command always executes immediately.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      GPD_SETCTYPE
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       1
    io_Data         the address of the byte variable describing
                    the controller type, as per the equates in
                    the gameport include file
```
