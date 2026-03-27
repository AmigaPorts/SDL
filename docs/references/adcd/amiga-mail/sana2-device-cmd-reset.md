---
title: sana2.device/CMD_RESET
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-cmd-reset
functions: []
libraries: []
---

# sana2.device/CMD_RESET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Reset -- Reset the network interface to initialized state.
FUNCTION

```c
    Currently, SANA-II devices can only be configured once (with
    CMD_CONFIGINTERFACE) and cannot be re-configured, hence,
    CMD_RESET does not apply to this class of device.
```
IO REQUEST

    ios2_Command    - CMD_RESET.
RESULTS

    ios2_Error      - IOERR_NOCMD.
NOTES

SEE ALSO

BUGS

