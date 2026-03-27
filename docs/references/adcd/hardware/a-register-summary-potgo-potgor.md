---
title: A Register Summary / POTGO, POTGOR
manual: hardware
chapter: hardware
section: a-register-summary-potgo-potgor
functions: []
libraries: []
---

# A Register Summary / POTGO, POTGOR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
POTGO      034      W       P     Pot port data write and start.

POTGOR     016      R       P     Pot port data read

```c
                                      (formerly called POTINP).

                 This register controls a 4-bit bi-directional I/O port
                 that shares the same four pins as the four pot counters
                 above.

                 BIT#  FUNCT   DESCRIPTION
                 ----  ---------------------------------------
                 15    OUTRY   Output enable for Paula pin 36
                 14    DATRY   I/O data Paula pin 36
                 13    OUTRX   Output enable for Paula pin 35
                 12    DATRX   I/O data Paula pin 35
                 11    OUTLY   Output enable for Paula pin 33
                 10    DATLY   I/O data Paula pin 33
                 09    OUTLX   Output enable for Paula pin 32
                 08    DATLX   I/O data Paula pin 32
                 07-01   0     Reserved for chip ID code (presently 0)
                 00    START   Start pots (dump capacitors, start
                                 counters)
```
