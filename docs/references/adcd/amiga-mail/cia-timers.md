---
title: CIA Timers
manual: amiga-mail
chapter: amiga-mail
section: cia-timers
functions: []
libraries: []
---

# CIA Timers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* System use of CIA timers has changed.  Don't peek timers you think the
  system is using in a particular manner.

* Don't depend on initial values of CIA registers.

* Don't mess with CIABase.  Use cia.resource.

* If your code requires hardware level CIA timers, allocate the timers
  using cia.resource AddICRVector()! Very important!  Operating system
  usage of the CIA timers has changed.  The new 2.0 timer.device (``Jumpy
  the Magic Timer Device'') will try to jump to different CIA's so
  programs that properly allocate timers will have a better chance of
  getting what they want.  If possible, be flexible and design your code
  to work with whatever timer you can successfully allocate.

* OS usage of INT6 is increasing.  Do not totally take over INT6, and do
  not terminate the server chain if an interrupt is not for you.

