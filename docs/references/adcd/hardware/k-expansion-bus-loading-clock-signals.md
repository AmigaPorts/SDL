---
title: K / / Expansion Bus Loading / Clock Signals
manual: hardware
chapter: hardware
section: k-expansion-bus-loading-clock-signals
functions: []
libraries: []
---

# K / / Expansion Bus Loading / Clock Signals

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All clock signals on the bus are in this group.  Many designs are very
sensitive to clock delay, skew, and rise/fall times, so loading on the
clock lines must be kept to a minimum.  These are bussed signals, actively
driven by the backplane, and source terminated with a low value series
resistor. PICs can apply one standard load to each of these signals when
necessary. Zorro II cards have the same clock rules, so there should never
be clocking problems when using either card type in a backplane.


```c
        [/C3](hardware/k-signal-description-clock-signals-2.md)       [CDAC](hardware/k-signal-description-clock-signals-2.md)        [/C1](hardware/k-signal-description-clock-signals-2.md)         [7M](hardware/k-signal-description-clock-signals-2.md) 
        [E Clock](hardware/k-signal-description-clock-signals-2.md) 
```
