---
title: K / General / Amiga Bus History
manual: hardware
chapter: hardware
section: k-general-amiga-bus-history
functions: []
libraries: []
---

# K / General / Amiga Bus History

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The original Amiga computer, the Amiga 1000, was introduced in 1985. While
it had no built-in standard for expandability, the capability for some
form of expansion was considered extremely important; personal computer
history up to that date had shown several times that an open hardware
expansion capability was often critical to a personal computer's success
and to its capability to adapt to new or unusual applications. The A1000
was designed with a connector giving access to the internal 68000 bus and
a few other system signals. Shortly after introduction, the formal
expansion specification for a card chassis that would connect to the A1000
was published.   This bus became commonly known as the Zorro bus*.  While
the backplane specification was very easy to implement with 1985 PAL
technology based on the existing 68000 signals, the specification did
incorporate a number of advanced features.   Far more sophisticated than
the IBM-XT/AT and Apple II buses in common use at the time, the Zorro bus
allowed any slot to master the bus, and it linked expansion cards with the
system software. Addressing jumpers were eliminated, the card's address
instead being assigned by software, and cards could easily be identified
by software and linked with appropriate driver programs, all with a
minimum of user intervention.

With the introduction of the Amiga 2000 system, the Zorro bus was changed
slightly.  Additional discrete interrupt lines were added, replacing the
encoded lines that couldn't easily be used by any bus resident device.  As
it turns out, these additional encoded lines weren't any more useful, as
they couldn't be disabled by software, and as such, they're no longer
considered an official part of the Zorro II bus specification (they are
supported as part of Zorro III).  Finally, the form factor was changed to
match that of the IBM PC-AT card, acting as both a cost reduction and
allowing the Zorro II bus to offer the PC-AT bus as one optional secondary
bus extension.  This modified specification became commonly known as the
Zorro II bus, and it's the Amiga bus standard that's been in use for most
of the Amiga's life.  And it's a bus standard that will continue to be
important.

 * The original "Zorro" name comes from the code name of one of the A1000
   prototype boards.  The "Zorro" board was the one that followed the
   "Lorraine," and was the board in the works when much of the expansion
   specifications were worked up.  Since everyone uses the "Zorro" name,
   and no one's suggested a better name, we've stuck with it.

