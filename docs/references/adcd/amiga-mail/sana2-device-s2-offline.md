---
title: sana2.device/S2_OFFLINE
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-offline
functions: []
libraries: []
---

# sana2.device/S2_OFFLINE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Offline -- Remove interface from service.
FUNCTION

    This command removes a network interface from service.
IO REQUEST

    ios2_Command    - S2_OFFLINE.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
```
NOTES

    Aborts all pending reads and writes with ios2_Error set to
    S2ERR_OUTOFSERVICE.

    While the interface is offline, all read, writes and any other
    command that touches interface hardware will be rejected with
    ios2_Error set to S2ERR_OUTOFSERVICE.

    This command is intended to permit a network interface to be
    tested on an otherwise live system.
SEE ALSO

    S2_ONLINE
BUGS

