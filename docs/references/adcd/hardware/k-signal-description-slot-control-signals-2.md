---
title: K / Signal Description / Slot Control Signals
manual: hardware
chapter: hardware
section: k-signal-description-slot-control-signals-2
functions: []
libraries: []
---

# K / Signal Description / Slot Control Signals

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This group of signals is responsible for the control of operations between
expansion slots.

Slave (/SLAVEn)
   Each slot has its own /SLAVEn output, driven actively, all of which
   go into the collision detect circuitry.  The "n" refers to the
   expansion slot number of the particular /SLAVE signal. Whenever a
   Zorro III PIC is responding to an address on the bus, it must assert
   its /SLAVEn output very quickly.  If more than one /SLAVEn output
   occurs for the same address, or if a PIC asserts its /SLAVEn output
   for an address reserved by the local bus, a collision is registered
   and the bus controller asserts  [/BERR](hardware/k-signal-description-system-control-signals-2.md) .  The bus controller will assert
   /SLAVEn back to the interrupting device selected during a
```c
    [Quick Interrupt cycle](hardware/k-timing-quick-interrupt-cycle-timing.md) , so any device supporting  [Quick Interrupts](hardware/k-zorro-iii-bus-architecture-quick-interrupts.md) 
```
   must be capable of tri-stating its /SLAVEn; all others can drive
   SLAVEn with a normal active output.

Configuration Chain (/CFGINn, /CFGOUTn)
   The slot configuration mechanism uses the bus signals /CFGOUTn and
   /CFGINn, where "n" refers to the slot number.  Each slot has its own
   version of both signals, which make up the configuration chain
   between slots.  Each subsequent /CFGINn is a result of all previous
   /CFGOUTs, going from slot 0 to the last slot on the expansion bus.
   During the  [autoconfiguration](hardware/k-autoconfig-tm-the-autoconfig-mechanism.md)  process, an unconfigured Zorro III PIC
   responds to the 64K address space starting at either $00E80000 or
   $FF000000 if its /CFGINN signal is asserted.  All unconfigured PICs
   start up with /CFGOUTn negated. When configured, or told to "shut up"
   a PIC will assert its /CFGOUTn, which results in the /CFGINn of the
   next slot being asserted. Backplane logic automatically passes on the
   state of the previous /CFGOUTn to the next /CFGINn for any slot not
   occupied by a PIC, so there's no need to sequentially populate the
   expansion bus slots.

Backplane Type Sense (SenseZ3)
   This line can be used by the PIC to determine the backplane type.  It
   is grounded on a Zorro II backplane, but floating on a Zorro III
   backplane.  The Zorro III PIC connects this signal to a 1K pullup
   resistor to generate a real logic level for this line.  It's
   possible, though more complicated, to build a Zorro III PIC that can
   actually run in Zorro II mode when in a Zorro II backplane.  It's
   hardly necessary or required to support this backward compatibility
   mechanism, and in many cases it will be impractical.  The Zorro III
   specification does require that this signal be used, at least, to
   shut the card down and pass /CFGIN to /CFGOUT when in a Zorro II
   backplane.

