---
title: input.device/IND_WRITEEVENT
manual: autodocs-2.0
chapter: autodocs-2.0
section: input-device-ind-writeevent
functions: []
libraries: []
---

# input.device/IND_WRITEEVENT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IND_WRITEEVENT -- Propagate an input event to all handlers
FUNCTION

IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      IND_WRITEEVENT
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       should be sizeof(struct InputEvent)
    io_Data         a pointer to the struct InputEvent:
        ie_NextEvent
                    will be ignored.
        ie_Class
        ie_SubClass
        ie_Code
        ie_Qualifier
        ie_X, ie_Y
                    as desired
        ie_TimeStamp
                    will be set by this call (V36)
```
NOTES

    The contents of the input event are destroyed.

    This function was documented in V34 and earlier to allow
    chaining of events via ie_NextEvent.  The implementation
    never allowed that.  The documentation now reflects this.

    ie_TimeStamp is set only in V36 and later.  Software written
    to run on earlier versions should set this field to the
    current time.
