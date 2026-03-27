---
title: gameport.device/GPD_READEVENT
manual: autodocs-2.0
chapter: autodocs-2.0
section: gameport-device-gpd-readevent
functions: []
libraries: []
---

# gameport.device/GPD_READEVENT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GPD_READEVENT -- Return the next game port event.
FUNCTION

    Read game port events from the game port and put them in the
    data area of the iORequest.  If there are no pending game port
    events, this command will not be satisfied, but if there are
    some events, but not as many as can fill IO_LENGTH, the
    request will be satisfied with those currently available.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      GPD_READEVENT
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       the size of the io_Data area in bytes: there
                    are sizeof(inputEvent) bytes per input event.
    io_Data         a buffer area to fill with input events.  The
                    fields of the input event are:
        ie_NextEvent
                    links the events returned
        ie_Class
                    is IECLASS_RAWMOUSE
        ie_SubClass
                    is 0 for the left, 1 for the right game port
        ie_Code
                    contains any gameport button reports.  No
                    report is indicated by the value 0xff.
        ie_Qualifier
                    only the relative and button bits are set
        ie_X, ie_Y
                    the x and y values for this report, in either
                    relative or absolute device dependent units.
        ie_TimeStamp
                    the delta time since the last report, given
                    not as a standard timestamp, but as the frame
                    count in the TV_SECS field.
```
RESULTS

```c
    This function sets the error field in the iORequest, and fills
    the iORequest with the next game port events (but not partial
    events).
```
SEE ALSO

    gameport.device/SetCType, gameport.device/SetTrigger
