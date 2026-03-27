---
title: FD/battclock_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-battclock-lib-fd
functions: []
libraries: []
---

# FD/battclock_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "battclock.resource"
##base _BattClockBase
##bias 6
##public
ResetBattClock()()
ReadBattClock()()
WriteBattClock(time)(d0)
##private
battclockPrivate1()()
battclockPrivate2()()
##end

