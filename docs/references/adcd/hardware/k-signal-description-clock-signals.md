---
title: K / / Signal Description / Clock Signals
manual: hardware
chapter: hardware
section: k-signal-description-clock-signals
functions: []
libraries: []
---

# K / / Signal Description / Clock Signals

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Zorro III expansion bus provides  [clock signals](hardware/k-signal-description-clock-signals-2.md)  for expansion boards.
These clocks are for  [synchronous](hardware/k-basic-zorro-iii-bus-cycles-design-goals.md)  Zorro II designs and for other
synchronous activity such as bus arbitration.  While originally based on
Amiga local bus clocks, these have no guaranteed relationship to any local
bus activity in newer Amiga computers, but are maintained in Amiga
computers as part of the expansion bus specification.  The relationship
between these clocks is illustrated in Figure K-3.

/C1 Clock
   This is a 3.58 MHz clock (3.55 MHz on PAL systems) that's synched to
   the falling edge of the 7M system clock.

/C3 Clock
   This is a 3.58 MHz clock (3.55 MHz on PAL systems) that's synched to
   the rising edge of the 7M system clock.

CDAC Clock
   This is a 7.16 MHz system clock (7.09 MHz on PAL systems) which
   trails the 7M clock by 90 degrees (approximately 35ns).

E Clock
   This is the 68000 generated "E" clock, used for 6800 family
   peripherals driven by "E" and 6502 peripherals driven by phi(2).
   This clock is four 7M clocks high, six clocks low, as per the 68000
   spec.  Note that the bus does not support the rest of the 68000's
   6800/6502 compatible interface; there may be better ways to clock
   such devices.

E7M Clock
   This is the 7.16 MHz system clock (7.09 MHz on PAL systems).  This
   clock forms the basis for all  [Zorro II/68000](hardware/k-basic-zorro-iii-bus-cycles-design-goals.md)  compatible activity, and
   for various other system functions, such as bus arbitration.


           140ns
         |<----->|
      ___     ___     ___     ___     ___     ___     ___     ___     _
 C7M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     |   |___|   |___|   |___|   |___|   |___|   |___|   |___|   |___|

         |   | 75|   |
         | ->| ns|<- |
         | | |   |   |
     35->| |<-   |   |
     ns ___  |  ___  |  ___     ___     ___     ___     ___     ___
CDAC   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     __|   |___|   |___|   |___|   |___|   |___|   |___|   |___|   |___
         |       |
         |   |   |   |
     ____    |    _______         _______         _______         _____
 /C1     |       |       |       |       |       |       |       |
         |_______|       |_______|       |_______|       |_______|

         |   |   |   |
      _______    |    _______         _______         _______         _
 /C3 |       |       |       |       |       |       |       |       |
     |       |_______|       |_______|       |_______|       |_______|
         |
         |   |   |   |
     ____    |   |   |                                    _____________
   E     |                                               |

         |_______________________________________________|


                     Figure K-3: Expansion Bus Clocks
