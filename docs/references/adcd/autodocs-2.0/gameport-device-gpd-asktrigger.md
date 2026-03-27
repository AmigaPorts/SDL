---
title: gameport.device/GPD_ASKTRIGGER
manual: autodocs-2.0
chapter: autodocs-2.0
section: gameport-device-gpd-asktrigger
functions: []
libraries: []
---

# gameport.device/GPD_ASKTRIGGER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GPD_ASKTRIGGER -- Inquire the conditions for a game port report
FUNCTION

    This command inquires what conditions must be met by a game
    port unit before a pending Read request will be satisfied.
    These conditions, called triggers, are independent -- that
    any one occurs is sufficient to queue a game port report to
    the Read queue.  These conditions are set by SetTrigger.

    This command always executes immediately.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      GPD_ASKTRIGGER
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       sizeof(gamePortTrigger)
    io_Data         a structure of type [GamePortTrigger](autodocs-2.0/includes-devices-gameport-h.md), which
                    has the following elements
        gpt_Keys -
                GPTB_DOWNKEYS set if button down transitions
                trigger a report, and GPTB_UPKEYS set if button up
                transitions trigger a report
        gpt_Timeout -
                a time which, if exceeded, triggers a report;
                measured in vertical blank units (60/sec)
        gpt_XDelta  -
                a distance in x which, if exceeded, triggers a
                report
        gpt_YDelta  -
                a distance in x which, if exceeded, triggers a
                report
```
