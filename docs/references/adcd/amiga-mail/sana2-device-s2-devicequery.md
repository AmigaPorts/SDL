---
title: sana2.device/S2_DEVICEQUERY
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-devicequery
functions: []
libraries: []
---

# sana2.device/S2_DEVICEQUERY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    DeviceQuery -- Return parameters for this network interface.
FUNCTION

```c
    This command causes the device driver to report information about the
    device. Up to SizeAvailable bytes of the information is copied
    into a buffer pointed to by ios2_StatData. The format of the data is
    as follows:

        struct Sana2DeviceQuery
        {
        /*
        ** Standard information
        */
            ULONG SizeAvailble; /* bytes available */
            ULONG SizeSupplied; /* bytes supplied */
            LONG  DevQueryFormat;   /* this is type 0 */
            LONG  DeviceLevel;      /* this document is level 0 */

        /*
        ** Common information
        */
            UWORD AddrFieldSize;    /* address size in bits */
            ULONG MTU;              /* maximum packet data size */
            LONG  bps;              /* line rate (bits/sec) */
            LONG  HardwareType;     /* what the wire is */

        /*
        ** Format specific information
        */
        };

    The SizeAvailable specifies the number of bytes that the caller
    is prepared to accomodate, including the standard information fields.

    SizeSupplied is the number of bytes actually supplied,
    including the standard information fields, which will not exceed
    SizeAvailable.

    <devices/sana2.h> includes constants for these values.  If your
    hardware does not have a number assigned to it, you must contact
    CATS to get a hardware number.
```
IO REQUEST

    ios2_Command    - S2_DEVICEQUERY.
    ios2_StatData   - Pointer to Sana2DeviceQuery structure to fill in.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
```
NOTES

SEE ALSO

BUGS

