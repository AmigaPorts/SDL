---
title: K / / Expansion Bus Loading / Non-bussed Signals
manual: hardware
chapter: hardware
section: k-expansion-bus-loading-non-bussed-signals
functions: []
libraries: []
---

# K / / Expansion Bus Loading / Non-bussed Signals

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The non-bussed, or slot specific, signals are involved with only one slot
on the bus (e.g., each slot has its own copy).  As a result, the drive
requirements are much less for these signals.  The backplane provides
pullups or pulldowns, as required by the specific signal.


```c
        [/CFGINn](hardware/k-signal-description-slot-control-signals-2.md)   [/CFGOUTn](hardware/k-signal-description-slot-control-signals-2.md)   [/BRn](hardware/k-signal-description-dma-control-signals-2.md)        [/BGn](hardware/k-signal-description-dma-control-signals-2.md) 
        [SenseZ3](hardware/k-signal-description-slot-control-signals-2.md)   [/SLAVEn](hardware/k-signal-description-slot-control-signals-2.md) 
```
