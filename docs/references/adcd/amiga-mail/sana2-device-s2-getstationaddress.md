---
title: sana2.device/S2_GETSTATIONADDRESS
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-getstationaddress
functions: []
libraries: []
---

# sana2.device/S2_GETSTATIONADDRESS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GetStationAddress -- Get default and interface address.
FUNCTION

```c
    This command causes the device driver to copy the current interface
    address into ios2_SrcAddr, and to copy the factory default station
    address (if any) into ios2_DstAddr.
```
IO REQUEST

    ios2_Command    - S2_GETSTATIONADDRESS.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
    ios2_SrcAddr    - Current interface address.
    ios2_DstAddr    - Default interface address (if any).
```
NOTES

SEE ALSO

    S2_CONFIGINTERFACE
BUGS

