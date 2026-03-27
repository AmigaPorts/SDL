---
title: clipboard.device/CBD_CURRENTWRITEID
manual: autodocs-2.0
chapter: autodocs-2.0
section: clipboard-device-cbd-currentwriteid
functions: []
libraries: []
---

# clipboard.device/CBD_CURRENTWRITEID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CBD_CURRENTWRITEID -- Determine the current write identifier.
FUNCTION

    CBD_CURRENTWRITEID fills the io_ClipID with a clip identifier that
    can be compared with that of a post command: if greater than
    the post identifier then the post is obsolete and need never
    be satisfied.
IO REQUEST

```c
    io_Message      mn_ReplyPort set up
    io_Device       preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CBD_CURRENTWRITEID
```
RESULTS

    io_ClipID       the ClipID of the current write is set
