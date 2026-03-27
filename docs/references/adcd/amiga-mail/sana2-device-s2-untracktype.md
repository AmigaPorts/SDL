---
title: sana2.device/S2_UNTRACKTYPE
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-untracktype
functions: []
libraries: []
---

# sana2.device/S2_UNTRACKTYPE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    UntrackType -- End statistics about a packet type.
FUNCTION

    This command causes the device driver to stop accumulating
    statistics about a particular packet type.
IO REQUEST

    ios2_Command    - S2_UNTRACKTYPE.
    ios2_PacketType - Packet type of interest.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
```
NOTES

SEE ALSO

    S2_TRACKTYPE, S2_GETTYPESTATS
BUGS

