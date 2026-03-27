---
title: input.device/IND_SETTHRESH
manual: autodocs-2.0
chapter: autodocs-2.0
section: input-device-ind-setthresh
functions: []
libraries: []
---

# input.device/IND_SETTHRESH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IND_SETTHRESH -- Set the key repeat threshold
FUNCTION

```c
    This command sets the time that a key must be held down before
    it can repeat.  The repeatability of a key may be restricted
    (as, for example, are the shift keys).

    This command always executes immediately.
```
IO REQUEST - a [timerequest](autodocs-2.0/includes-devices-timer-h.md)

```c
    tr_node.io_Message      mn_ReplyPort set if quick I/O is not possible
    tr_node.io_Device       preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    tr_node.io_Unit         preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    tr_node.io_Command      IND_SETTHRESH
    tr_node.io_Flags        IOB_QUICK set if quick I/O is possible
    tr_time.tv_secs         the threshold seconds
    tr_time.tv_micro        the threshold microseconds
```
