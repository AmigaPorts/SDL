---
title: sana2.device/S2_TRACKTYPE
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-tracktype
functions: []
libraries: []
---

# sana2.device/S2_TRACKTYPE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TrackType -- Accumulate statistics about a packet type.
FUNCTION

    This command causes the device driver to accumulate statistics about
    a particular packet type. Packet type statistics, for the particular
    packet type, are zeroed by this command.
IO REQUEST

    ios2_Command    - S2_TRACKTYPE.
    ios2_PacketType - Packet type of interest.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
```
NOTES

SEE ALSO

    S2_UNTRACKTYPE, S2_GETTYPESTATS
BUGS

