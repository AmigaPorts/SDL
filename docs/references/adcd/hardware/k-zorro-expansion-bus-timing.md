---
title: K Zorro Expansion Bus / Timing
manual: hardware
chapter: hardware
section: k-zorro-expansion-bus-timing
functions: []
libraries: []
---

# K Zorro Expansion Bus / Timing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Some of this information is considered preliminary.  Nothing is expected
to get any more speed critical, but as mentioned previously, the testing
of Zorro III designs has just started at the time of this writing, final
bus controllers are not yet available, and only a few PIC designs have
even been conceived.

This section covers the various timing specifications in detail for
different Zorro III operations.  It's important to realize that this
timing information is a specification.  Actual Zorro III systems may offer
much more relaxed timings.  Today.  The whole point of the specification
is that as long as all Zorro III PICs and all Zorro III backplanes base
things on the timings given here, they'll always work together nicely.
Any design based on the actual characteristics of any particular backplane
will very likely wind up working only on that particular backplane.

The philosophy of timing on the Zorro III bus is to keep things as simple
as possible without compromising the performance goals of the bus.  Zorro
III PICs are expected to be based on F-Series or ACT-series TTL logic,
fast PALs, and possibly full custom chip designs.  It's very unlikely the
designer will meet any of these specifications with the LS parts left over
from old Zorro II card designs.

 [Standard Read Cycle Timing](hardware/k-timing-standard-read-cycle-timing.md)       [Multiple Transfer Cycle Timing](hardware/k-timing-multiple-transfer-cycle-timing.md) 
 [Standard Write Cycle Timing](hardware/k-timing-standard-write-cycle-timing.md)      [Quick Interrupt Cycle Timing](hardware/k-timing-quick-interrupt-cycle-timing.md) 

