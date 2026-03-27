---
title: A Register Summary / HBSTOP, HBSTRT, HCENTER, HSSTOP, HSSTRT, HTOTAL
manual: hardware
chapter: hardware
section: a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt
functions: []
libraries: []
---

# A Register Summary / HBSTOP, HBSTRT, HCENTER, HSSTOP, HSSTRT, HTOTAL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
HBSTOP     1C6      W      A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) ) Horizontal line position for HBLANK stop
HBSTRT     1C4      W      A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) ) Horizontal line position for HBLANK start
HCENTER    1E2      W      A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) ) Horizontal position for Vsync on interlace
HSSTOP     1C2      W      A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) ) Horizontal line position for HSYNC stop
HSSTRT     1DE      W      A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) ) Horizontal sync start (VARHSY)
HTOTAL     1C0      W      A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) ) Highest number count, horiz. line

```c
                                     (VARBEAMEN=1)
```
