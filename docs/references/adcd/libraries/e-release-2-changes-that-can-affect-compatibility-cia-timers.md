---
title: E / Release 2 Changes That Can Affect Compatibility / CIA Timers
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-cia-timers
functions: []
libraries: []
---

# E / Release 2 Changes That Can Affect Compatibility / CIA Timers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * System use of CIA timers has changed.  Don't assume how they're used.

  * Don't depend on initial values of CIA registers.

  * Don't mess with [CIABase](autodocs-2.0/includes-resources-ciabase-h.md). Use cia.resource.

  * If your code requires hardware level CIA timers, allocate the timers

```c
    using cia.resource [AddICRVector()](autodocs-2.0/cia-resource-addicrvector.md)!  This is very important. Operating
    system usage of the CIA timers has changed.  The new 2.0 timer.device
    ("Jumpy the Magic Timer Device") will try to jump to different CIAs
    so programs that properly allocate timers will have a better chance
    of getting what they want.  If possible, be flexible and design your
    code to work with whatever timer you can successfully allocate.
```
  * OS usage of INT6 is increasing.  Do not totally take over INT6, and

    do not terminate the server chain if an interrupt is not for you.
