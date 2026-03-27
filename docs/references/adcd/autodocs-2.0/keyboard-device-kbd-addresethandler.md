---
title: keyboard.device/KBD_ADDRESETHANDLER
manual: autodocs-2.0
chapter: autodocs-2.0
section: keyboard-device-kbd-addresethandler
functions: []
libraries: []
---

# keyboard.device/KBD_ADDRESETHANDLER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    KBD_ADDRESETHANDLER -- Add a keyboard reset handler.
FUNCTION

```c
    Add a function to the list of functions called to clean up
    before a hard reset generated at the keyboard.  The reset
    handler is called as:
        ResetHandler(handlerData)
                     a1
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set
    io_Device       preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      KBD_ADDRESETHANDLER
    io_Data         a pointer to an interrupt structure.
        is_Data     the handlerData pointer described above
        is_Code     the Handler function address
```
NOTES

```c
    Few of the Amiga keyboard models generate the communication codes
    used to implement this reset processing.  Specifically, only the
    Euro a1000 (rare), and the B2000 keyboard generate them.

    The interrupt structure is kept by the keyboard device until a
    RemResetHandler command is satisfied for it, but the
    KBD_ADDRESETHANDLER command itself is replied immediately.
```
