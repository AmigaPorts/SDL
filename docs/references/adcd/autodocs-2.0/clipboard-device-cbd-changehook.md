---
title: clipboard.device/CBD_CHANGEHOOK
manual: autodocs-2.0
chapter: autodocs-2.0
section: clipboard-device-cbd-changehook
functions: []
libraries: []
---

# clipboard.device/CBD_CHANGEHOOK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CBD_CHANGEHOOK -- Add or remove a clip change hook
FUNCTION

    CBD_CHANGEHOOK allows specification of a hook to be called
    when the data on the clipboard has changed.
IO REQUEST

```c
    io_Message      mn_ReplyPort set up
    io_Device       preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CBD_CHANGEHOOK
    io_Length -     0 to remove, 1 to install this hook
    io_Data -       struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) *, the clip change hook
```
HOOK ENVIRONMENT
   hook message - a [ClipHookMsg](autodocs-2.0/includes-devices-clipboard-h.md), as defined in [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md)
       chm_Type - 0, indicating that the message has the
           following fields:
       chm_ClipID - the clip ID of the clip triggering the change
   hook object - io_Unit

