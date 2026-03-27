---
title: sana2.device/S2_GETGLOBALSTATS
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-getglobalstats
functions: []
libraries: []
---

# sana2.device/S2_GETGLOBALSTATS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GetGlobalStats -- Get interface accumulated statistics.
FUNCTION

```c
    This command causes the device driver to retrieve various global
    runtime statistics for this network interface. The format of the
    data returned is as follows:

        struct Sana2DeviceStats
        {
            ULONG PacketsReceived;
            ULONG PacketsSent;
            ULONG BadData;
            ULONG Overruns;
            ULONG UnknownTypesReceived;
            ULONG Reconfigurations;
            timeval LastStart;
        };
```
IO REQUEST

    ios2_Command    - S2_GETGLOBALSTATS.
    ios2_StatData   - Pointer to Sana2DeviceStats structure to fill.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
```
NOTES

SEE ALSO

    S2_GETSPECIALSTATS
BUGS

