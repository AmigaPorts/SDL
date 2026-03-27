---
title: A Register Summary / DIWHIGH, DIWSTOP, DIWSTRT
manual: hardware
chapter: hardware
section: a-register-summary-diwhigh-diwstop-diwstrt
functions: []
libraries: []
---

# A Register Summary / DIWHIGH, DIWSTOP, DIWSTRT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
DIWHIGH    1E4      W     A,D( [E](hardware/c-ecs-hardware-and-graphics-library-display-window.md) ) Display window -  upper bits for

                                       start, stop
DIWSTOP    090      W       A      Display window stop (lower right
```c
                                       vertical-horizontal position)
```
DIWSTRT    08E      W       A      Display window start (upper left

```c
                                       vertical-horizontal position)

                 These registers control display window size and position
                 by locating the upper left and lower right corners.

                 BIT# 15,14,13,12,11,10,09,08,07,06,05,04,03,02,01,00
                      -----------------------------------------------
                 USE  V7 V6 V5 V4 V3 V2 V1 V0 H7 H6 H5 H4 H3 H2 H1 H0

                 DIWSTRT is vertically restricted to the upper 2/3
                 of the display (V8=0) and horizontally restricted to
                 the left 3/4 of the display (H8=0).

                 DIWSTOP is vertically restricted to the lower 1/2
                 of the display (V8=/=V7) and horizontally restricted
                 to the right 1/4 of the display (H8=1).
```
