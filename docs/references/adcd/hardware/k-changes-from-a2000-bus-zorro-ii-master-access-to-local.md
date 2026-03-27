---
title: K / / Changes from A2000 Bus / Zorro II Master Access to Local Slaves
manual: hardware
chapter: hardware
section: k-changes-from-a2000-bus-zorro-ii-master-access-to-local
functions: []
libraries: []
---

# K / / Changes from A2000 Bus / Zorro II Master Access to Local Slaves

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The only supported local bus resource that's guaranteed accessible to a
Zorro II expansion bus master as a slave device is chip bus memory.  All
I/O devices are implementation dependent and not supportable via DMA.  Any
attempted access to unsupported local bus resources as expansion slaves
will result in an  [error](hardware/k-signal-description-system-control-signals.md)  condition being signaled on both the local and
the expansion buses.  Most other local bus resources, such as local bus
fast memory, are located outside of Zorro II space on most systems and
obviously not available to Zorro II masters.

