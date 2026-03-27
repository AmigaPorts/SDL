---
title: K / Zorro II Compatibility / Zorro II Bus Architecture
manual: hardware
chapter: hardware
section: k-zorro-ii-compatibility-zorro-ii-bus-architecture
functions: []
libraries: []
---

# K / Zorro II Compatibility / Zorro II Bus Architecture

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Zorro II bus is a simple extension of the 68000 processor bus.  Those
without a working knowledge of the 68000 local bus will find The 68000
User's Manual from Motorola an excellent reference for many Zorro II
issues.  The A500/A2000 Technical Reference Manual from Commodore-Amiga is
also required reading for any Zorro II design issues, as it includes a
complete description of all the Amiga details that aren't part
of the 68000 specification.

The basic Zorro II bus is a buffered version of the 68000 processor bus,
physically provided on a  [100-pin](hardware/k-zorro-expansion-bus-physical-and-logical-signal-names.md)  one-piece connector. The bus is 16 bits
wide, and provides 24 bits of addressing information.  A bus cycle looks
exactly like a 68000 bus cycle.  The cycle is defined by an address
strobe, terminated by a data transfer strobe, and qualified by a
read/write strobe, some memory space qualifiers, and one or two byte
selection strobes.  The basic bus cycle runs for a total of four cycles of
a 7.16MHz clock, though it can be extended to add wait states when
required.

The Zorro II bus adds a number of features to the basic 68000 CPU bus.  It
supplies some Amiga system signals that are useful for expansion card
designs, such as many of the Amiga system clocks.  The bus provides a
default data transfer signal, which expansion cards can easily use and
modify rather than go to the trouble of creating their own.  It provides a
number of discrete interrupt lines which are mixed to provide the 68000
with its standard encoded interrupts.  The 68000 bus arbitration protocol
is used to allow multiple bus masters; arbitration of the bus requests
are managed by the Zorro II bus controller to avoid contention between
multiple masters. And, of course, the bus supplies a number of supply
voltages for  [powering](hardware/k-signal-description-power-connections.md)  cards.

A powerful aspect of the Zorro II bus is its convention for automatically
configuring expansion cards, AUTOCONFIG(TM)  On system powerup, the system
software interrogates each board to determine what kind of board is
installed and how much memory space it needs on the bus.  The software
then tells each board where to reside in memory.  The bus provides
hardware lines to allow the boards to be configured in a daisy chained
fashion regardless of which slots they occupy and to prevent damage to
boards if accidently configured to reside at the same memory location.
Firmware standards also permit software to autoboot or autoinitialize any
board, to match soft-loaded device drivers with individual boards, and to
link memory boards into the appropriate system memory lists.

