---
title: keyboard.device/KBD_REMRESETHANDLER
manual: autodocs-2.0
chapter: autodocs-2.0
section: keyboard-device-kbd-remresethandler
functions: []
libraries: []
---

# keyboard.device/KBD_REMRESETHANDLER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    KBD_REMRESETHANDLER -- Remove a keyboard reset handler.
FUNCTION

```c
    Remove a function previously added to the list of reset
    handler functions with [KBD_ADDRESETHANDLER](autodocs-2.0/keyboard-device-kbd-addresethandler.md).
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set
    io_Device       preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      KBD_REMRESETHANDLER
    io_Data         a pointer to the handler interrupt structure.
```
