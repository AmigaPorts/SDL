---
title: sana2.device/S2_GETSPECIALSTATS
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-getspecialstats
functions: []
libraries: []
---

# sana2.device/S2_GETSPECIALSTATS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GetSpecialStats -- Get network type specific statistics.
FUNCTION

```c
    This function returns statistics which are specific to the type of
    network medium this driver controls. For example, this command could
    return statistics common to all Ethernets which are not common to all
    network mediums in general.

    The supplied Sana2SpecialStatData structure is given below:

        struct Sana2SpecialStatData
        {
            ULONG RecordCountMax;
            ULONG RecordCountSupplied;
            struct Sana2StatRecord[RecordCountMax];
        };

    The format of the data returned is:

        struct Sana2StatRecord
        {
            ULONG Type;     /* commodore registered */
            LONG Count;     /* the stat itself */
            char *String;   /* null terminated */
        };

    The RecordCountMax field specifies the number of records that the
    caller is prepared to accomodate.

    RecordCountSupplied is the number of record actually supplied which
    will not exceed RecordCountMax.
```
IO REQUEST

    ios2_Command    - S2_GETSPECIALSTATS.
    ios2_StatData   - Pointer to a Sana2SpecialStatData structure to fill.
                      RecordCountMax must be initialized.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
```
NOTES

    Commodore will maintain registered statistic Types.
SEE ALSO

    S2_GETGLOBALSTATS, <devices/sana2specialstats.h>
BUGS

