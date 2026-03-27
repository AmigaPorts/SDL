---
title: F / Control Registers / Bitmap Of Register CRB
manual: hardware
chapter: hardware
section: f-control-registers-bitmap-of-register-crb
functions: []
libraries: []
---

# F / Control Registers / Bitmap Of Register CRB

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

REG# NAME ALARM    INMODE     LOAD      RUNMODE  OUTMODE  PBON    START
---- ---- -----    ------     ----      -------  -------  ----    -----
 F   CRB  0=TOD    00=02      1=force   0=cont.  0=pulse  0=PB7OFF 0=stop

```c
          1=Alarm  01=CNT       load    1=one-   1=toggle 1=PB7ON  1=start
                   10=Timer A  (strobe)   shot
                   11=CNT+
                     Timer A

                   |<---------------  [Timer B](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  Variables ------------>|
```
All unused register bits are unaffected by a write and forced to 0 on a
read.

