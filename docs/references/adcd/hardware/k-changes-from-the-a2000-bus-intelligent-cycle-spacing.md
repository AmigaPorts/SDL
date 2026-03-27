---
title: K / / Changes from the A2000 Bus / Intelligent Cycle Spacing
manual: hardware
chapter: hardware
section: k-changes-from-the-a2000-bus-intelligent-cycle-spacing
functions: []
libraries: []
---

# K / / Changes from the A2000 Bus / Intelligent Cycle Spacing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In order to permit a free intermix of Zorro II and Zorro III cycles, the
bus control logic is capable of making intelligent decisions when spacing
bus cycles.  In somc cases, a Zorro II cycle has some component that would
naturally extend into a following cycle.  The cycle spacing logic detects
such a condition, and refuses to start a new cycle until the current one
is complete, even if this extends beyond the defined bounds of a Zorro II
cycle.

For Zorro II PICs that really follow the Zorro II specifications, this
should have no effect.  However, any Zorro II PIC that holds signals much
beyond the end of a cycle, especially critical signals like  [/SLAVE](hardware/k-signal-description-slot-control-signals.md)  and
 [/DTACK](hardware/k-signal-description-addressing-and-control-signals.md) , will likely incur additional wait states on the Zorro III bus.
This is not intended as a license for making sloppy expansion card
designs, just an acknowledgement that some Zorro II devices may cause a
conflict with the faster Zorro III bus  [timings](hardware/k-changes-from-the-a2000-bus-bus-drive-and-termination.md) . The best approach is to
make them work, even with a possible performance penalty.

