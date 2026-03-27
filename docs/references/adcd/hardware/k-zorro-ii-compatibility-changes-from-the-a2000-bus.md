---
title: K / Zorro II Compatibility / Changes from the A2000 Bus
manual: hardware
chapter: hardware
section: k-zorro-ii-compatibility-changes-from-the-a2000-bus
functions: []
libraries: []
---

# K / Zorro II Compatibility / Changes from the A2000 Bus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

While much effort has been made to assure that the Zorro II mode of the
A3000 bus is as compatible as possible with the A2000 bus, there are a
few points to consider here.  Primarily, the A3000's Zorro II modes are
driven with a state machine that emulates the  [68000 bus](hardware/k-zorro-ii-compatibility-zorro-ii-bus-architecture.md)  protocol.
This emulation must be based on the published Motorola specifications
detailing 68000 bus behavior. While this has the interesting effect of
changing the Zorro II bus from CPU dependent to CPU independent,
there's some margin for trouble.  Zorro II PICs also designed to these
specifications should have no trouble in the A3000 bus in most cases.
However, anything designed based on observed 68000 behavior rather than
documented 68000 operation is at serious risk of failing in an A3000
bus, as one might expect. There are also actual documented differences,
which are listed below.

 [6800 Bus Interface](hardware/k-changes-from-the-a2000-bus-6800-bus-interface.md)                          [Intelligent Cycle Spacing](hardware/k-changes-from-the-a2000-bus-intelligent-cycle-spacing.md) 
 [Bus Memory Mapping and Cache Support](hardware/k-changes-from-a2000-bus-bus-memory-mapping-and-cache.md)        [Bus Drive and Termination](hardware/k-changes-from-the-a2000-bus-bus-drive-and-termination.md) 
 [Bus Synchronization Delays](hardware/k-changes-from-the-a2000-bus-bus-synchronization-delays.md)                  [DMA Latency and Overlap](hardware/k-changes-from-the-a2000-bus-dma-latency-and-overlap.md) 
 [Zorro II Master Access to Local Slaves](hardware/k-changes-from-a2000-bus-zorro-ii-master-access-to-local.md)      [Power Supply Differences](hardware/k-changes-from-the-a2000-bus-power-supply-differences.md) 
 [Bus Arbitration and Fairness](hardware/k-changes-from-the-a2000-bus-bus-arbitration-and-fairness.md) 

