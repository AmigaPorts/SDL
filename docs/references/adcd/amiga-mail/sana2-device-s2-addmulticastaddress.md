---
title: sana2.device/S2_ADDMULTICASTADDRESS
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-addmulticastaddress
functions: []
libraries: []
---

# sana2.device/S2_ADDMULTICASTADDRESS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddMulticastAddress -- Enable an interface multicast address.
FUNCTION

    This command causes the device driver to enable multicast packet
    reception for the requested address.
IO REQUEST

    ios2_Command    - S2_ADDMULTICASTADDRESS.
    ios2_SrcAddr    - Multicast address to enable.
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

    S2_MULTICAST, S2_DELMULTICASTADDRESS
BUGS

