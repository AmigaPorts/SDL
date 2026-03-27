---
title: FD/timer_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-timer-lib-fd
functions: []
libraries: []
---

# FD/timer_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "Timer.Device"
##base _TimerBase
##bias 42
##public
AddTime(dest,src)(a0/a1)
SubTime(dest,src)(a0/a1)
CmpTime(dest,src)(a0/a1)
ReadEClock(dest)(a0)
GetSysTime(dest)(a0)
##end

