---
title: 3 / Device Interface / Clipboard Messages
manual: devices
chapter: devices
section: 3-device-interface-clipboard-messages
functions: []
libraries: []
---

# 3 / Device Interface / Clipboard Messages

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When an application performs a post, it must specify a message port for
the clipboard to send a message to if it needs the application to satisfy
the post with a write called the SatisfyMsg.


```c
    struct SatisfyMsg
    {
    struct  Message sm_Message; /* the length will be 6 */
    UWORD   sm_Unit;            /* 0 for the primary clip unit */
    LONG    sm_ClipID;          /* the clip identifier of the post */
    }
```
This structure is defined in the include file devices/[clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md).

If the application wishes to determine if a post it has recently performed
is still the current clip, it should compare the io_ClipID found in the
post request upon return with that returned by the [CBD_CURRENTREADID](autodocs-2.0/clipboard-device-cbd-currentreadid.md)
command.

If an application has a pending post and wishes to determine if it should
satisfy it (for example, before it exits), it should compare the io_ClipID
of the post I/O request with that of the [CBD_CURRENTWRITEID](autodocs-2.0/clipboard-device-cbd-currentwriteid.md) command. If
the application receives a satisfy message from the clipboard device
(format described below), it must immediately perform the write with the
io_ClipID of the post. The satisfy message from the clipboard may be
removed from the application message port by the clipboard device at any
time (because it is re-used by the clipboard device). It is not dangerous
to spuriously satisfy a post, however, because it is identified by the
io_ClipID.

The cut data is provided to the clipboard device via either a write or a
post of the cut data. The write command accepts the data immediately and
copies it onto the clipboard. The post command allows an application to
inform the clipboard of a cut, but defers the write until the data is
actually required for a paste.

In the preceding discussion, references to the read and write commands of
the clipboard device actually refer to a sequence of read or write
commands, where the clip data is acquired and provided in pieces instead
of all at once.

The clipboard has an end-of-clip concept that is analogous to end-of-file
for both read and write. The read end-of-file must be triggered by the
user of the clipboard in order for the clipboard to move on to service
another application's requests, and consists of reading data past the end
of file. The write end-of-file is indicated by use of the update command,
which indicates to the clipboard that the previous write commands are
completed.

