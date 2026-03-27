---
title: clipboard.device/CMD_WRITE
manual: autodocs-2.0
chapter: autodocs-2.0
section: clipboard-device-cmd-write
functions: []
libraries: []
---

# clipboard.device/CMD_WRITE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_WRITE -- Write to a clip on the clipboard.
FUNCTION

```c
    This command writes data to the clipboard.  This data can be
    provided sequentially by clearing io_Offset for the initial
    write, and using the incremented value unaltered for
    subsequent writes.  If io_Offset is ever beyond the current
    clip size, the clip is padded with zeros.

    If this write is in response to a [SatisfyMsg](autodocs-2.0/includes-devices-clipboard-h.md) for a pending
    post, then the io_ClipID returned by the [CBD_POST](autodocs-2.0/clipboard-device-cbd-post.md) command must
    be used.  Otherwise, a new ID is obtained by clearing the
    io_ClipID for the first write.  Subsequent writes must not
    alter the io_ClipID.
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set up
    io_Device       preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CMD_WRITE
    io_Length       number of bytes from io_Data to write
    io_Data         pointer to block of data to write
    io_Offset       usually zero if this is the initial write
    io_ClipID       zero if this is the initial write, ClipID of
                    the Post if this is to satisfy a post
```
RESULTS

    io_Error        non-zero if an error occurred
    io_Actual       filled with the actual number of bytes written
    io_Offset       updated to next write position
    io_ClipID       the clip ID assigned to this write: do not
                    alter for subsequent writes
