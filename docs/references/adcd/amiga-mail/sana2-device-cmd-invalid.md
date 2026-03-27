---
title: sana2.device/CMD_INVALID
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-cmd-invalid
functions: []
libraries: []
---

# sana2.device/CMD_INVALID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Invalid -- Return with error IOERR_NOCMD.
FUNCTION

    This command causes device driver to reply with an error IOERR_NOCMD
    as defined in <exec/errors.h> indicating the command is not supported.
IO REQUEST

    ios2_Command    - CMD_INVALID.
RESULTS

    ios2_Error      - IOERR_NOCMD.
NOTES

SEE ALSO

BUGS

    Not known to be useful.
