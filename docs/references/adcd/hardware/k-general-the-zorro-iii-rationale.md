---
title: K / General / The Zorro III Rationale
manual: hardware
chapter: hardware
section: k-general-the-zorro-iii-rationale
functions: []
libraries: []
---

# K / General / The Zorro III Rationale

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

With the creation of the Amiga 3000, it became clear that the Zorro II bus
would not be adequate to support all of that system's needs. The Zorro II
bus would continue to be quite useful, as the current Amiga expansion
standard, and so it would have to be supported.   A few unused pins on the
Zorro II bus and the option of a bus controller custom LSI, gave rise to
the Zorro III design, which supports the following features:

   *   [Compatibility](hardware/k-zorro-expansion-bus-zorro-ii-compatibility.md)  with all Zorro II devices.
   *  Full  [32-bit address](hardware/k-zorro-iii-bus-architecture-basic-zorro-iii-bus-cycles.md)  path for new devices.
   *  Full  [32-bit data](hardware/k-zorro-iii-bus-architecture-basic-zorro-iii-bus-cycles.md)  path for new devices.
   *   [Bus speed independent](hardware/k-zorro-ii-compatibility-changes-from-the-a2000-bus.md)  of host system CPU speed.
   *   [High speed](hardware/k-zorro-iii-bus-architecture-multiple-transfer-cycles.md)  bus block transfer mode.
   *   [Bus locking](hardware/k-advanced-mode-support-logic-bus-locking.md)  for multiprocessor support.
   *   [Cache disable](hardware/k-advanced-mode-support-logic-cache-support.md)  for simple cache support.
   *   [Fair arbitration](hardware/k-changes-from-the-a2000-bus-bus-arbitration-and-fairness.md)  for all bus masters.
   *   [Cycle-by-cycle](hardware/k-zorro-iii-bus-architecture-quick-bus-arbitration.md)  bus arbitration mode.
   *   [High speed interrupt](hardware/k-zorro-iii-bus-architecture-quick-interrupts.md)  mode.

Some of the advanced features, such as  [burst modes](hardware/k-signal-description-data-and-related-control-signals.md) , are designed in such
a way as to make them optional; both master and slave arbitrate for them.
In addition, it is possible with a bit of extra cleverness, to design a
card that automatically configures itself for either Zorro II or Zorro III
operation, depending on the status of a sensing pin on the bus.

The Zorro III bus is physically based on the same  [100-pin](hardware/k-zorro-expansion-bus-physical-and-logical-signal-names.md)  single piece
connector as the Zorro II bus.  While some bus signals remain unchanged
throughout bus operation, other signals change based on the specific bus
mode in effect at any time.  The bus is geographically mapped into three
main sections: Zorro II Memory Space, Zorro II I/O Space, and Zorro III
Space. The  [memory map](hardware/d-system-memory-maps-a3000-memory-map.md) , in Figure K-1 shows how these three spaces are
mapped in the A3000 system.  The Zorro II space is limited to a 16
megabyte region, and since it has DMA access by convention to chip memory,
it is in the original 68000 memory map for any bus implementation.  The
Zorro III space can physically be anywhere in 32-bit memory.




      $80000000  ____________       _ _ _ ____________  $01000000
                |            |           |            |
                |            |     |     | Motherboard|
                |            |           |     ROM    |
                |            |     |     |------------| $00F00000
                |            |           |Zorro II I/O|
                | Zorro III  |     |     |------------| $00E80000
                | expansion  |           |    A2000   |
                |   space    |     |     | motherboard|
                |            |           |  register  |
                |            |     |     |    space   |
                |            |           |------------| $00B80000
                |            |     |     |  Zorro II  |
                |            |           |  expansion |
                |            |     |     |    space   |
      $10000000 |------------|           |------------| $00A00000
                |   32-bit   |     |     |            |
                |   memory   |           |  Zorro II  |
                | expansion  |     |     |   memory   |
                |   space    |           |  expansion |
      $08000000 |------------|    /      |    space   |
                |   A3000    |           |            |
                | motherboard|  /        |------------| $00200000
                |   space    |           | Amiga Chip |
      $01000000 |____________|/          |   memory   |
      $00000000 |____________|_ _ _ _ _ _|____________| $00000000


                   Figure K-1: Expansion Memory Map
The Zorro III bus functions in one of two different major modes, depending
on the memory address on the bus.  All bus cycles start with a 32-bit
address, since the full 32-bit address is required for proper cycle
typing.  If the address is determined to be in Zorro II space, a Zorro II
compatible cycle is initiated, and all responding slave devices are
expected to be Zorro II compatible 16-bit PICs.  Should a Zorro III
address be detected, the cycle completes when a Zorro III slave responds
or the bus times out, as driven by the motherboard logic.  It is very
important that no Zorro III device respond in Zorro III mode to a Zorro II
bus access; the two types of cycles make very different use of many of the
expansion bus lines, and serious buffer contention can result if the cycle
types are somehow mixed up.   The Zorro III bus of course started with the
Zorro II bus as its necessary base, but the Zorro III bus mechanisms were
designed as much as possible to solve specific needs for high end Amiga
systems, rather than extend any particular Zorro II philosophy when that
philosophy no longer made any sense.  There are actually several
variations of the basic Zorro III cycle, though they all work on the same
principles. The variations are for optimization of cycle times and for
service of interrupt vectors.  But all of this in due time.

