---
title: sana2.device/S2_DELMULTICASTADDRESS
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-delmulticastaddress
functions: []
libraries: []
---

# sana2.device/S2_DELMULTICASTADDRESS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    DelMultiCastAddress -- Disable an interface multicast address.
FUNCTION

    This command causes device driver to disable multicast packet
    reception for the requested address.

    It is an error to disable a multicast address that is not enabled.
IO REQUEST

    ios2_Command    - S2_DELMULTICASTADDRESS
    ios2_SrcAddr    - Multicast address to disable.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
```
NOTES

    Multicast addresses are added globally -- anyone using the device
    may receive packets as a result of any multicast address which has
    been added for the device.

    Since multicast addresses are not "bound" to a particular packet type,
    each enabled multicast address has an "enabled" count associated with
    it so that if two protocols add the same multicast address and later
    one removes it, it is still enabled until the second removes it.
SEE ALSO

    S2_ADDMULTICASTADDRESS
BUGS

