---
title: sana2.device/CMD_START
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-cmd-start
functions: []
libraries: []
---

# sana2.device/CMD_START

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Start -- Restart device operation.
FUNCTION

    There is no way for the driver to keep queuing requests without
    servicing them, so CMD_STOP does not apply to this class of device.
    S2_OFFLINE and S2_ONLINE do perform a similar function to CMD_STOP
    and CMD_START
IO REQUEST

    ios2_Command    - CMD_START.
RESULTS

    ios2_Error      - IOERR_NOCMD.
NOTES

SEE ALSO

    S2_ONLINE, S2_OFFLINE
BUGS

