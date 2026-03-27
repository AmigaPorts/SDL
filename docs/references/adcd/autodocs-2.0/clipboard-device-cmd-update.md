---
title: clipboard.device/CMD_UPDATE
manual: autodocs-2.0
chapter: autodocs-2.0
section: clipboard-device-cmd-update
functions: []
libraries: []
---

# clipboard.device/CMD_UPDATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_UPDATE -- Terminate the writing of a clip to the clipboard.
FUNCTION

```c
    Indicate to the clipboard that the previous write commands are
    complete and can be used for any pending pastes (reads).  This
    command cannot be issued while any of the write commands are
    pending.
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set up
    io_Device       preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CMD_UPDATE
    io_ClipID       the ClipID of the write
```
RESULTS

    io_Error        non-zero if an error occurred
