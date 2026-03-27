---
title: A Register Summary / VHPOSR, VHPOSW
manual: hardware
chapter: hardware
section: a-register-summary-vhposr-vhposw
functions: []
libraries: []
---

# A Register Summary / VHPOSR, VHPOSW

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
VHPOSR     006      R       A     Read vertical and horizontal position of
                                      beam or lightpen
VHPOSW     02C      W       A     Write vertical and horizontal position

```c
                                      of beam or lightpen

                 BIT# 15,14,13,12,11,10,09,08,07,06,05,04,03,02,01,00
                      -----------------------------------------------
                 USE  V7 V6 V5 V4 V3 V2 V1 V0,H8 H7 H6 H5 H4 H3 H2 H1

                 RESOLUTION = 1/160 of screen width (280 ns)
```
