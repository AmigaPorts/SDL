---
title: clipboard.device/CMD_READ
manual: autodocs-2.0
chapter: autodocs-2.0
section: clipboard-device-cmd-read
functions: []
libraries: []
---

# clipboard.device/CMD_READ

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_READ -- Read from a clip on the clipboard.
FUNCTION

    The read function serves two purposes.

    When io_Offset is within the clip, this acts as a normal read
    request, and io_Data is filled with data from the clipboard.
    The first read request should have a zero io_ClipID, which
    will be filled with the ID assigned for this read.  Normal
    sequential access from the beginning of the clip is achieved
    by setting io_Offset to zero for the first read, then leaving
    it untouched for subsequent reads.  If io_Data is null, then
    io_Offset is incremented by io_Actual as if io_Length bytes
    had been read: this is useful to skip to the end of file
    by using a huge io_Length.

    When io_Offset is beyond the end of the clip, this acts as a
    signal to the clipboard device that the application is
    through reading this clip.  Realize that while an application
    is in the middle of reading a clip, any attempts to write new
    data to the clipboard are held off.  This read past the end
    of file indicates that those operations may now be initiated.
IO REQUEST

```c
    io_Message      mn_ReplyPort set up
    io_Device       preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CMD_READ
    io_Length       number of bytes to put in data buffer
    io_Data         pointer to buffer of data to fill, or null to
                    skip over data
    io_Offset       byte offset of data to read
    io_ClipID       zero if this is the initial read
```
RESULTS

```c
    io_Error        non-zero if an error occurred
    io_Actual       filled with the actual number of bytes read
    io_Data         (the buffer now has io_Actual bytes of data)
    io_Offset       updated to next read position, which is
                    beyond EOF if io_Actual != io_Length
    io_ClipID       the clip ID assigned to this read: do not
                    alter for subsequent reads
```
