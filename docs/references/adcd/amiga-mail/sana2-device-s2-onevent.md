---
title: sana2.device/S2_ONEVENT
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-onevent
functions: []
libraries: []
---

# sana2.device/S2_ONEVENT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    OnEvent -- Return when specified event occures.
FUNCTION

    This command returns when a particular event condition has occured
    on the network or this network interface.
IO REQUEST

```c
    ios2_Command    - S2_ONEVENT.
    ios2_Flags      - Supported flags are:
                            SANA2IOB_QUICK
    ios2_WireError  - Mask of event(s) to wait for
                      (from <devices/sana2.h>).
```
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - Mask of events that occured.
```
NOTES

```c
    If this device driver does not understand the specified event
    condition(s) then the command returns immediately with
    ios2_Req.io_Error set to S2_ERR_NOT_SUPPORTED and ios2_WireError
    S2WERR_BAD_EVENT.  A successful return will have ios2_Error set to
    zero ios2_WireError set to the event number.

    All pending requests for a particular event will be returned when
    that event occurs.

    All event types that cover a particular condition are returned when
    that condition occures. For instance, if an error is returned by
    a buffer management function during receive processing, events of
    types S2EVENT_ERROR, S2EVENT_RX and S2EVENT_BUFF would be returned if
    pending.

    Types ONLINE and OFFLINE return immediately if the device is
    already in the state to be waited for.
```
SEE ALSO

BUGS

