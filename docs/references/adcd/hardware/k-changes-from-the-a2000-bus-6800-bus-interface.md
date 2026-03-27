---
title: K / / Changes from the A2000 Bus / 6800 Bus Interface
manual: hardware
chapter: hardware
section: k-changes-from-the-a2000-bus-6800-bus-interface
functions: []
libraries: []
---

# K / / Changes from the A2000 Bus / 6800 Bus Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A major difference between the A3000 expansion bus in Zorro II mode and
the A2000 bus is the absence of the signals /VPA and /VMA, which comprise
the 6800/6502 peripheral support mechanism that's part of the 68000 bus
interface.  This mechanism was never a supported part of the Zorro II
specification, however, and it should not be used by any PIC.  Any Zorro
II PIC that depends on /VPA or /VMA will not work in the A3000 bus.  It
was, in fact, impossible to legally use this on the A2000 bus.  The
 [E clock](hardware/k-signal-description-clock-signals-2.md)  is, however, supported on the Zorro III bus, though its duty
cycle may vary in some situations.

