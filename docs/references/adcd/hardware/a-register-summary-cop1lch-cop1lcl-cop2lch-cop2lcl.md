---
title: A Register Summary / COP1LCH, COP1LCL, COP2LCH, COP2LCL
manual: hardware
chapter: hardware
section: a-register-summary-cop1lch-cop1lcl-cop2lch-cop2lcl
functions: []
libraries: []
---

# A Register Summary / COP1LCH, COP1LCL, COP2LCH, COP2LCL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
COP1LCH    080      W      A( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) ) Copper first location register
```c
                                      (high 3 bits, high 5 bits if ECS)
```
COP1LCL    082      W       A     Copper first location register
```c
                                      (low 15 bits)
```
COP2LCH    084      W      A( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) ) Copper second location register
```c
                                      (high 3 bits, high 5 bits if ECS)
```
COP2LCL    086      W       A     Copper second location register

```c
                                      (low 15 bits)

                 These registers contain the jump addresses
                 described above.
```
