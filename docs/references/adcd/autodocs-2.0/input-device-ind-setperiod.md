---
title: input.device/IND_SETPERIOD
manual: autodocs-2.0
chapter: autodocs-2.0
section: input-device-ind-setperiod
functions: []
libraries: []
---

# input.device/IND_SETPERIOD

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IND_SETPERIOD -- Set the key repeat period
FUNCTION

    This command sets the period at which a repeating key repeats.

    This command always executes immediately.
IO REQUEST - a [timerequest](autodocs-2.0/includes-devices-timer-h.md)

```c
    tr_node.io_Message      mn_ReplyPort set if quick I/O is not possible
    tr_node.io_Device       preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    tr_node.io_Unit         preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    tr_node.io_Command      IND_SETPERIOD
    tr_node.io_Flags        IOB_QUICK set if quick I/O is possible
    tr_time.tv_secs         the repeat period seconds
    tr_time.tv_micro        the repeat period microseconds
```
