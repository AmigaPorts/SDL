---
title: sana2.device/S2_GETTYPESTATS
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-gettypestats
functions: []
libraries: []
---

# sana2.device/S2_GETTYPESTATS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GetTypeStats -- Get accumulated type specific statistics.
FUNCTION

```c
    This command causes the device driver to retrieve various packet type
    specific runtime statistics for this network interface. The format of
    the data returned is as follows:

        struct Sana2TypeStatData
        {
            LONG PacketsSent;
            LONG PacketsReceived;
            LONG BytesSent;
            LONG BytesReceived;
            LONG PacketsDropped;
        };
```
IO REQUEST

    ios2_Command    - S2_GETTYPESTATS.
    ios2_PacketType - Packet type of interest.
    ios2_StatData   - Pointer to TypeStatData structure to fill in.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
```
NOTES

    Statistics for a particular packet type are only available while that
    packet type is being ``tracked''.
SEE ALSO

    S2_TRACKTYPE, S2_UNTRACKTYPE
BUGS

