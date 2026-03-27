---
title: F / Control Registers / Bitmap of Register CRA
manual: hardware
chapter: hardware
section: f-control-registers-bitmap-of-register-cra
functions: []
libraries: []
---

# F / Control Registers / Bitmap of Register CRA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

REG# NAME UNUSED  SPMODE  INMODE  LOAD   RUNMODE  OUTMODE   PBON    START
---- ---- ------  ------  ------  ----   -------  -------   ----    -----
 E   CRA  unused  0=input  0=02  1=force  0=cont. 0=pulse  0=PB6OFF 0=stop

```c
          unused  1=output 1=CNT   load   1=one-  1=toggle 1=PB6ON  1=start
                                 (strobe)   shot

                           |<--------  [Timer](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  A Variables --------------->|
```
All unused register bits are unaffected by a write and forced to 0 on a
read.

