---
title: sana2.device/CMD_UPDATE
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-cmd-update
functions: []
libraries: []
---

# sana2.device/CMD_UPDATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Update -- Force packets out to device.
FUNCTION

    Since there are no device internal buffers, CMD_UPDATE does not
    apply to this class of device.
IO REQUEST

    ios2_Command    - CMD_UPDATE.
RESULTS

    ios2_Error      - IOERR_NOCMD.
NOTES

SEE ALSO

BUGS

