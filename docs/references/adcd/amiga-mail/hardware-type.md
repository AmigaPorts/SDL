---
title: Hardware Type
manual: amiga-mail
chapter: amiga-mail
section: hardware-type
functions: []
libraries: []
---

# Hardware Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The HardwareType returned by the device's S2_DEVICEQUERY function is
necessary for those protocols whose standards require different behavior
on different hardware. It is also useful for determining appropriate
packet type numbers to use with the device. The HardwareType values
already issued for standard network hardware are the same as those in RFC
1060 (assigned numbers). Hardware developers implementing networks without
a SANA-II hardware number must contact CATS to have a new hardware type
number assigned. Driver users should all have reasonable defaults which
can be used for hardware with which they are not familiar. 

