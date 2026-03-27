---
title: A Register Summary / VSSTOP, VSSTRT, VTOTAL
manual: hardware
chapter: hardware
section: a-register-summary-vsstop-vsstrt-vtotal
functions: []
libraries: []
---

# A Register Summary / VSSTOP, VSSTRT, VTOTAL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
VSSTOP     1CA      W      A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) ) Vertical line position for VSYNC stop
VSSTRT     1E0      W      A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) ) Vertical sync start   (VARVSY)
VTOTAL     1C8      W      A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) ) Highest numbered vertical line

```c
                                      (VARBEAMEN=1)
```
