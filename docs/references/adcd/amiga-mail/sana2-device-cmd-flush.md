---
title: sana2.device/CMD_FLUSH
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-cmd-flush
functions: []
libraries: []
---

# sana2.device/CMD_FLUSH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Flush -- Clear all queued I/O requests for the SANA-II device.
FUNCTION

```c
    This command aborts all I/O requests in both the read and write
    request queues of the device.  All pending I/O requests are
    returned with an error message (IOERR_ABORTED).  CMD_FLUSH does not
    affect active requests.
```
IO REQUEST

    ios2_Command    - CMD_FLUSH.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
```
NOTES

SEE ALSO

BUGS

