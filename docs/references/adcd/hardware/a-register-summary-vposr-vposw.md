---
title: A Register Summary / VPOSR, VPOSW
manual: hardware
chapter: hardware
section: a-register-summary-vposr-vposw
functions: []
libraries: []
---

# A Register Summary / VPOSR, VPOSW

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
VPOSR      004      R      A( [E](hardware/c-ecs-hardware-and-the-graphics-library-determining-chip.md) ) Read vertical most significant bit
```c
                                      (and frame flop)
```
VPOSW      02A      W       A     Write vertical most significant bit

```c
                                      (and frame flop)

                 BIT# 15,14,13,12,11,10,09,08,07,06,05,04,03,02,01,00
                      -----------------------------------------------
                 USE  LOF-- -- -- -- -- -- --,-- -- -- -- -- -- -- V8

                 LOF=Long frame (auto toggle control bit in  [BPLCON0](hardware/a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3.md) )
```
