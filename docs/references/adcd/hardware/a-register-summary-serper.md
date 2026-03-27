---
title: A Register Summary / SERPER
manual: hardware
chapter: hardware
section: a-register-summary-serper
functions: []
libraries: []
---

# A Register Summary / SERPER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
SERPER     032      W       P      Serial port period and control


```c
                 This register contains the control bit LONG referred to
                 above, and a 15-bit number defining the serial port
                 baud rate. If this number is N, then the baud rate is
                 1 bit every (N+1)*.2794  microseconds.

                 BIT#   SYM     FUNCTION
                 -----  ----    ---------------
                 15     LONG    Defines serial receive as 9-bit word.
                 14-00  RATE    Defines baud rate=1/((N+1)*.2794 microsec.)
```
