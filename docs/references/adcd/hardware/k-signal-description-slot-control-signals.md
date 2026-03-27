---
title: K / / Signal Description / Slot Control Signals
manual: hardware
chapter: hardware
section: k-signal-description-slot-control-signals
functions: []
libraries: []
---

# K / / Signal Description / Slot Control Signals

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This group of signals is responsible for the control of operations between
expansion slots.

Slave (/SLAVEn)
   Each slot has its own /SLAVE output, driven actively, all of which go
   into the collision detect circuitry.  The "n" refers to the expansion
   slot number of the particular /SLAVE signal. Whenever a Zorro II PIC
   is responding to an address on the bus, it must assert its /SLAVE
   output within 35ns of  [/AS](hardware/k-signal-description-addressing-and-control-signals.md)  asserted. The /SLAVE output must be negated
   at the end of a cycle within 50ns of  [/AS](hardware/k-signal-description-addressing-and-control-signals.md)  negated.  Late /SLAVE
   assertion on a Zorro II bus can result in loss of data setup times
   and other problems.  A late /SLAVE negation for Zorro II cards can
   cause a collision to be detected on the following cycle.  While the
   Zorro III sloppy cycle logic eliminates this fatal condition, late
   /SLAVE negation can nonetheless slow system performance
   unnecessarily.  If more than one /SLAVE output occurs for the same
   address, or if a PIC asserts its /SLAVE output for an address
   reserved by the local bus, a collision is registered and results in

```c
    [/BERR](hardware/k-signal-description-system-control-signals.md)  being asserted.
```
Configuration Chain (/CFGINn, /CFGOUTn)
   The slot configuration mechanism uses the bus signals /CFGOUTn and
   /CFGINn, where "n" refers to the expansion slot number. Each slot has
   its own version of each, which make up the configuration chain
   between slots.  Each subsequent /CFGIN is a result of all previous
   /CFGOUTs, going from slot 0 to the last slot on the expansion bus.
   During the  [AUTOCONFIG](hardware/k-autoconfig-tm-the-autoconfig-mechanism.md)  process, an unconfigured Zorro PIC responds to
   the 64K address space starting at $00E80000 if its /CFGIN signal is
   asserted.  All unconfigured PICs start up with /CFGOUT negated.  When
   configured, or told to "shut up," a PIC will assert its /CFGOUT,
   which results in the /CFGIN of the next slot being asserted.  The
   backplane passes on the state of the previous /CFGOUT to the next
   /CFGIN for any slot not occupied by a PIC, so there's no need to
   sequentially populate the expansion bus slots.

Data Output Enable (DOE)
   This signal is used by an expansion card to enable the buffers on the
   data bus. The main Zorro II use of this line is to keep PICs from
   driving data on the bus until any other device is completely off the
   bus and the bus buffers are pointing in the correct direction.  This
   prevents any contention on the data bus.

