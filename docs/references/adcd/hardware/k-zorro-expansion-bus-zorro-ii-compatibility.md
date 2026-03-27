---
title: K Zorro Expansion Bus / Zorro II Compatibility
manual: hardware
chapter: hardware
section: k-zorro-expansion-bus-zorro-ii-compatibility
functions: []
libraries: []
---

# K Zorro Expansion Bus / Zorro II Compatibility

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The A3000 bus is a rather extensive superset of the A2000 bus design.  The
compatibility is based on distinct bus modes, rather than a simple
extension to the existing bus mechanisms. Through the use of an integrated
bus controller (the  [Fat Buster chip](hardware/k-zorro-expansion-bus-zorro-iii-implementations.md) ), the expansion bus configures itself
differently for the 16-bit A2000-compatible Zorro II modes than the 32-bit
Zorro III modes.  As a result, while there are still only  [100 pins](hardware/k-zorro-expansion-bus-physical-and-logical-signal-names.md)  on the
expansion bus, some pins change function considerably depending on the bus
activity that's currently in progress.  While the Zorro II modes of the
Zorro III bus are as compatible as possible with the Zorro II bus
specification (especially the A2000 implementation of this specification),
there are some small differences between the two expansion buses.

Aside from these differences, in general, it's important to understand the
Zorro II bus in order to understand the Zorro III bus.  The general
features of the A3000 bus, like  [autoconfiguration](hardware/k-zorro-ii-compatibility-zorro-ii-bus-architecture.md) , the master-slave bus
architecture, and the physical attributes come from the Zorro II expansion
bus.  Other features of the Zorro III bus address shortcomings of the
Zorro II architecture, but Zorro II has a hand in how some of these
shortcomings are solved under Zorro III.  Those with a full understanding
of the Zorro II bus will mainly be concerned with the possible bus
incompatibilities listed here.

 [Changes from the A2000 Bus](hardware/k-zorro-ii-compatibility-changes-from-the-a2000-bus.md)      [Signal Description](hardware/k-zorro-ii-compatibility-signal-description.md) 
 [Zorro II Bus Architecture](hardware/k-zorro-ii-compatibility-zorro-ii-bus-architecture.md) 

