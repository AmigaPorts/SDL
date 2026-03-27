---
title: K / Signal Description / DMA Control Signals
manual: hardware
chapter: hardware
section: k-signal-description-dma-control-signals-2
functions: []
libraries: []
---

# K / Signal Description / DMA Control Signals

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are various signals on the expansion bus that coordinate the
arbitration of bus masters.  Zorro II bus masters use some of the same
logical signals, but their arbitration protocol is considerably different.

PIC is DMA Owner (/OWN)
   This is asserted by the bus controller when a master is about to go
   on the bus and indicates that some master owns the bus. Zorro II bus
   masters drive this, and some Zorro III slaves may find a need to
   monitor it, or /BGACK, to determine who's the bus master. This is
   ordinarily not important to Zorro III PICs, and they may not drive
   this line.

Slot Specific Bus Arbitration (/BRn, /BGn)
   These are the slot-specific /BRn and /BGn signals, where "n" refers
   to the expansion slot number. The bus request from each board is
   taken in by the bus controller and ultimately used to take over the
   system from the primary bus master, which is always the local master.
   Zorro III PICs toggle /BRn to register or unregister as a master with
   the bus controller.  /BGn is asserted to one registered PIC at a
   time, on a cycle by cycle basis, to indicate to the PIC that it gets
   the bus for one full cycle.

Bus Grant Acknowledge (/BGACK)
   Asserted by the bus controller when a master is about to go on the
   bus.  As with /OWN, most Zorro III PICs ignore this signal, and none
   may drive it.

Bus Want/Clear (/BCLR)
   This signal is asserted by the bus controller to indicate that a PIC
   wants to master the bus; Zorro III cards can use this to determine if
   any Zorro II bus requests are pending; Zorro III bus requests don't
   affect /BCLR.

